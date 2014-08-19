/*
 * Simulink to MAVLink Interface for Windows serial ports
 * Developed and maintained by Aerospace Division of Nanyang Technological University, Sinpapore
 * 
 *      Authors:    Zhao Weihua  & Chiew Soon Hooi
 *
Copyright (C) 2012 NTU

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

//Simulink definitions
#define S_FUNCTION_NAME  MAVLink_Interface_MultUAV
#define S_FUNCTION_LEVEL 2

//For Windows serial ports
#include <windows.h>

//For Simulink structures
#include "simstruc.h"

//For MAVLink definitions
#include "mavlink/include/common/mavlink.h" //added by weihua
#include "mavlink/include/mavlink_types.h" //path modified by weihua
#include "mavlink/include/common/common.h"//path modified by weihua

//Simulink block parameter definitions
//Com Port
#define COM_PORT_IDX 0
#define COM_PORT(S) ssGetSFcnParam(S,COM_PORT_IDX)
//Baud Rate
#define COM_BUAD_IDX 1
#define COM_BAUD(S) ssGetSFcnParam(S,COM_BUAD_IDX)
//Input messages
#define MSG_IN_IDX  2
#define MSG_IN(S) ssGetSFcnParam(S,MSG_IN_IDX)
//Output messages
#define MSG_OUT_IDX  3
#define MSG_OUT(S) ssGetSFcnParam(S,MSG_OUT_IDX)
//Total number of parameters
#define NPARAMS   4

//Simulink housekeeping
#if !defined(MATLAB_MEX_FILE)
/*
 * This file cannot be used directly with the Real-Time Workshop. 
 */
# error This_file_can_be_used_only_during_simulation_inside_Simulink
#endif

//boolean governing thread loops
bool looping = true;

//serial read and write threads
DWORD WINAPI mavThreadRead(LPVOID lpParam);
DWORD WINAPI mavThreadWrite(LPVOID lpParam);

//Simulink helper functions
int_T mavlink_msg_decode(SimStruct* S, mavlink_message_t msg);
BOOL WriteBuffer(uint8_T* lpBuf, DWORD dwToWrite, SimStruct* S);

//Initialise sizes of Simulink structures based on parameters
static void mdlInitializeSizes(SimStruct *S) {
    /* Custom Data Types */
    HANDLE handle = NULL;
    DTypeId SS_HANDLE = ssRegisterDataType(S, "SS_HANDLE");
    if(SS_HANDLE == INVALID_DTYPE_ID) return;
    if( !ssSetDataTypeSize(S, SS_HANDLE, sizeof(handle)) ) return;
    ssSetDataTypeZero(S, SS_HANDLE, &handle);
    
    int_T nInputPorts  = 0;  /* number of input ports  */
    int_T nOutputPorts = 0;  /* number of output ports */
    
    uint8_T *ptrMsg_id_in;
    uint8_T *ptrMsg_id_out;

    
    ssSetNumSFcnParams(S, NPARAMS);  /* Number of expected parameters */
#if defined(MATLAB_MEX_FILE)
    if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {
     //   mdlCheckParameters(S); // Weihua: commented out
        if (ssGetErrorStatus(S) != NULL) {
            return;
        }
    } else {
        return; /* Parameter mismatch will be reported by Simulink */
    }
#endif

    ssSetSFcnParamTunable(S,COM_PORT_IDX,false);
    ssSetSFcnParamTunable(S,COM_BUAD_IDX,false);
    ssSetSFcnParamTunable(S,MSG_IN_IDX,false);
    ssSetSFcnParamTunable(S,MSG_OUT_IDX,false);
    
    
    ptrMsg_id_in = (uint8_T*) mxGetData(MSG_IN(S));
    ptrMsg_id_out =  (uint8_T*) mxGetData(MSG_OUT(S)); /* pointer to MSG_OUT_IDs */
    nInputPorts = (int_T) mxGetNumberOfElements(MSG_IN(S)); /* set Num of input port according to the MAVlink MSG */
    nOutputPorts = (int_T) mxGetNumberOfElements(MSG_OUT(S)); /* set Num of output port according to the MAVlink MSG */


    /* Register the number and type of states the S-Function uses */

    ssSetNumContStates(    S, 0);   /* number of continuous states           */
    ssSetNumDiscStates(    S, 0);   /* number of discrete states             */


    /*
     * Configure the input ports.  
     */
    if (!ssSetNumInputPorts(S, nInputPorts)) return;    
    
    for (int ii = 0; ii < nInputPorts; ii++) {        
        switch ( *(ptrMsg_id_in + ii) ){
            case MAVLINK_MSG_ID_SET_MODE:{  // #define MAVLINK_MSG_ID_SET_MODE 11
                ssSetInputPortWidth(S, ii, 1); /* Mode_ID*/
//                 ssSetInputPortRequiredContiguous(S,ii,1);
                break;
            }
//DO NOT USE this message, seems pretty unstable over short term LOC
//            case MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE:{
//                ssSetInputPortWidth(S, ii, 8); /* RC Input channels 1-8 */
//                 ssSetInputPortRequiredContiguous(S,ii,1);
//                break;
//            }
            case 59:{ //#define MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST 56
                ssSetInputPortWidth(S, ii, 4); /* Roll, Pitch, Yaw, Thrust*/
                break;
            }
            case MAVLINK_MSG_ID_REQUEST_DATA_STREAM:{   //#define MAVLINK_MSG_ID_REQUEST_DATA_STREAM 66
                ssSetInputPortWidth(S, ii, 3); /* Stream_ID, freq, start_stop */
//                 ssSetInputPortRequiredContiguous(S,ii,1);
                break;
            }
//            case MAVLINK_MSG_ID_ACTION:{
//                ssSetInputPortWidth(S, ii, 1);
////                 ssSetInputPortRequiredContiguous(S,ii,1);
//                break;
//            }
            case MAVLINK_MSG_ID_ATTITUDE:{      //#define MAVLINK_MSG_ID_ATTITUDE 30
                ssSetInputPortWidth(S, ii, 7); /* usec, roll, pitch, yaw, roll rate, pitch rate, yaw rate */
                break;
            }
//            case MAVLINK_MSG_ID_GPS_RAW:{
//                ssSetInputPortWidth(S, ii, 6); /* usec, (fix_type), lat, lon, alt, (eph), (epv), v, hdg */
//                break;
//            }
            case MAVLINK_MSG_ID_VFR_HUD:{ //#define MAVLINK_MSG_ID_VFR_HUD 74
                ssSetInputPortWidth(S, ii, 1); /* airspeed */
                break;
            }
// Weihua, Vicon message begin
            case MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE:{ //#define MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE 104
                ssSetInputPortWidth(S, ii, 7); /* usec, X, Y, Z, Roll, Pitch, Yaw */
                break;
            }
            
            case MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE:{ //#define MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE 103
                ssSetInputPortWidth(S, ii, 4); /* usec, X_Rate, Y_Rate, Z_Rate */
                break;
            }
            
            case MAVLINK_MSG_ID_SET_LOCAL_POSITION_SETPOINT:{ //#define MAVLINK_MSG_ID_SET_LOCAL_POSITION_SETPOINT 50
                ssSetInputPortWidth(S, ii, 6); /* Desired X, Y, Z, Yaw, target_system, target_component, coordinate_frame */
                break;
            }
            
// Weihua, Vicon message end
            
// weihua, for Multiple UAV, 28April2013
            case MAVLINK_MSG_ID_VICON_Q1:{ //#define MAVLINK_MSG_ID_VICON_Q1 196
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q2:{ //#define MAVLINK_MSG_ID_VICON_Q2 197
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q3:{ //#define MAVLINK_MSG_ID_VICON_Q3 198
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q4:{ //#define MAVLINK_MSG_ID_VICON_Q1 196
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q5:{ //#define MAVLINK_MSG_ID_VICON_Q2 197
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q6:{ //#define MAVLINK_MSG_ID_VICON_Q3 198
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            case MAVLINK_MSG_ID_VICON_Q7:{ //#define MAVLINK_MSG_ID_VICON_Q1 196
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q8:{ //#define MAVLINK_MSG_ID_VICON_Q2 197
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q9:{ //#define MAVLINK_MSG_ID_VICON_Q3 198
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }     
            case MAVLINK_MSG_ID_VICON_Q10:{ //#define MAVLINK_MSG_ID_VICON_Q3 198
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            case MAVLINK_MSG_ID_VICON_Q11:{ //#define MAVLINK_MSG_ID_VICON_Q1 196
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q12:{ //#define MAVLINK_MSG_ID_VICON_Q2 197
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q13:{ //#define MAVLINK_MSG_ID_VICON_Q3 198
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q14:{ //#define MAVLINK_MSG_ID_VICON_Q1 196
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q15:{ //#define MAVLINK_MSG_ID_VICON_Q2 197
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q16:{ //#define MAVLINK_MSG_ID_VICON_Q3 198
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            case MAVLINK_MSG_ID_VICON_Q17:{ //#define MAVLINK_MSG_ID_VICON_Q1 196
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q18:{ //#define MAVLINK_MSG_ID_VICON_Q2 197
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q19:{ //#define MAVLINK_MSG_ID_VICON_Q3 198
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }     
            case MAVLINK_MSG_ID_VICON_Q20:{ //#define MAVLINK_MSG_ID_VICON_Q3 198
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            case MAVLINK_MSG_ID_VICON_Q21:{ //#define MAVLINK_MSG_ID_VICON_Q1 196
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q22:{ //#define MAVLINK_MSG_ID_VICON_Q2 197
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q23:{ //#define MAVLINK_MSG_ID_VICON_Q3 198
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q24:{ //#define MAVLINK_MSG_ID_VICON_Q1 196
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q25:{ //#define MAVLINK_MSG_ID_VICON_Q2 197
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q26:{ //#define MAVLINK_MSG_ID_VICON_Q3 198
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            case MAVLINK_MSG_ID_VICON_Q27:{ //#define MAVLINK_MSG_ID_VICON_Q1 196
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q28:{ //#define MAVLINK_MSG_ID_VICON_Q2 197
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q29:{ //#define MAVLINK_MSG_ID_VICON_Q3 198
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }     
            case MAVLINK_MSG_ID_VICON_Q30:{ //#define MAVLINK_MSG_ID_VICON_Q3 198
                ssSetInputPortWidth(S, ii, 6); /* thrust, roll, pitch, yaw, pwm, Quad ID*/
                break;
            }
// weihua, for Multiple UAV, 28April2013
            default:
                ssSetInputPortWidth(S, ii, 1);
                break;
        } /* switch end*/        
     } 
    
    

    /*
     * Configure the output ports. 
     */
    if (!ssSetNumOutputPorts(S, nOutputPorts)) return;

    for (int ii = 0; ii < nOutputPorts; ii++) {        
        switch ( *(ptrMsg_id_out + ii) ){
            case MAVLINK_MSG_ID_HEARTBEAT:{
                ssSetOutputPortWidth(S, ii, 1); /* heart beat */
                break;
            }
            case MAVLINK_MSG_ID_ATTITUDE:{
                ssSetOutputPortWidth(S, ii, 6); /* roll pitch yaw */
                break;
            }
            case MAVLINK_MSG_ID_RAW_IMU:{
                ssSetOutputPortWidth(S, ii, 9); /* acc(xyz) gyro(xyz) mag(xyz) */
                break;
            }
            case MAVLINK_MSG_ID_VFR_HUD:{
                ssSetOutputPortWidth(S, ii, 4);
                break;
            }
            case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:{
                ssSetOutputPortWidth(S, ii, 6);
                break;
            }
            case MAVLINK_MSG_ID_RC_CHANNELS_SCALED:{
                ssSetOutputPortWidth(S, ii, 8); /* roll_output, pitch_output, throttle_output, rudder_output */
                break;
            }
            case MAVLINK_MSG_ID_SERVO_OUTPUT_RAW:{
                ssSetOutputPortWidth(S, ii, 4); /* servo raw 1-4 */
                break;
            }
            
//            Weihua, Vicon outputs begin
            case MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE:{
                ssSetOutputPortWidth(S, ii, 6); /* Vicon: X, Y, Z, Roll, Pitch, Yaw */
                break;
            }            
                        
//            Weihua, Vicon outputs begin
            
            
            default:
                ssSetOutputPortWidth(S, ii, 1);
                break;
        } /* switch end*/        
     } 
    
    
    
    /* setup Dwork Vectors */
    
    ssSetNumDWork(S, nInputPorts+1);
    
    for (int ii = 0; ii < nInputPorts; ii++){
        ssSetDWorkWidth(S, ii, 1024); // Buffer for each input MSG
        ssSetDWorkDataType(S, ii, SS_UINT8);
    }
    ssSetDWorkWidth(S, nInputPorts, 3); // Dwork for hSerial, hThreadRead, hThreadWrite
    ssSetDWorkDataType(S, nInputPorts, SS_HANDLE);
    
    ssSetNumRWork(S, nInputPorts); // length of each input buffer
    
    
    
    
//     ssSetNumIWork(S, nOutputPorts);
    ssSetNumPWork(S, nOutputPorts);
    
    /* setup bool work vector*/
    

    ssSetNumSampleTimes(   S, 1);   /* number of sample times   */
    ssSetSimStateCompliance(S, USE_DEFAULT_SIM_STATE);

} /* end mdlInitializeSizes */


static void mdlInitializeSampleTimes(SimStruct *S)
{
    /* Register one pair for each sample time */
    ssSetSampleTime(S, 0, 0.02);//ssSetSampleTime(S, 0, CONTINUOUS_SAMPLE_TIME); WEIHUA: 50HZ
    ssSetOffsetTime(S, 0, 0.0);

} /* end mdlInitializeSampleTimes */



#define MDL_START  /* Change to #undef to remove function */
#if defined(MDL_START)
  /* Function: mdlStart =======================================================
   * Abstract:
   *    This function is called once at start of model execution. If you
   *    have states that should be initialized once, this is the place
   *    to do it.
   */
static void mdlStart(SimStruct *S)
{
    uint8_T* ptrMsg_id_in = (uint8_T*) mxGetData(MSG_IN(S)); /* pointer to MSG_IDs */;
    int_T nInputPorts = (int_T)mxGetNumberOfElements(MSG_IN(S));
    
    uint8_T* ptrMsg_id_out = (uint8_T*) mxGetData(MSG_OUT(S)); /* pointer to MSG_IDs */;
    int_T nOutputPorts = (int_T)mxGetNumberOfElements(MSG_OUT(S)); /* set Num of output port according to the MAVlink MSG */
    
    
    real_T** ppPwork_data = (real_T**) ssGetPWork(S); 
    HANDLE* ptrHandle = (HANDLE*) ssGetDWork(S,nInputPorts);
    
    HANDLE hSerial, hThreadRead, hThreadWrite;
    

    /*Allocate memory for Output data*/
    for (int ii = 0; ii < nOutputPorts; ii++) {
        /* msg_id =  *(pMsg_id + ii); */
        ppPwork_data[ii] = (real_T*) calloc(ssGetOutputPortWidth(S,ii), sizeof(real_T));
    } 

    
    /* Setup Serial port */
    char_T strCOM[sizeof("COM10")]; //Weihua, previous:  char_T strCOM[sizeof("COM0")]
    mxGetString(COM_PORT(S),strCOM,sizeof(strCOM));
    real_T baud = *(real_T*) mxGetData(COM_BAUD(S));
    
    hSerial = CreateFile(strCOM,
                GENERIC_READ | GENERIC_WRITE,
                0,
                0,
                OPEN_EXISTING,
                FILE_FLAG_OVERLAPPED,
                0);
	if(hSerial==INVALID_HANDLE_VALUE){
		if(GetLastError()==ERROR_FILE_NOT_FOUND){
			printf("Error 1: No Such Com port!\n");
		}
		printf("Error 2: No Such Com port!\n");
	}

	DCB dcbSerialParams = {0};
	DCB dcbSerial = {0};
	dcbSerial.DCBlength=sizeof(dcbSerialParams);
	if (!GetCommState(hSerial, &dcbSerialParams)) {
		printf("Error 3:Cann't open Com Port!\n");
	}
	dcbSerialParams.BaudRate=(int_T) baud;
	dcbSerialParams.ByteSize=8;
	dcbSerialParams.StopBits=ONESTOPBIT;
	dcbSerialParams.Parity=NOPARITY;
	if(!SetCommState(hSerial, &dcbSerialParams)){
		printf("Error 4: Set Com port: Baud, StopBits... \n");
	}
    
    COMMTIMEOUTS timeouts={0};
    timeouts.ReadIntervalTimeout=1;
    timeouts.ReadTotalTimeoutConstant=0;
    timeouts.ReadTotalTimeoutMultiplier=1;
    timeouts.WriteTotalTimeoutConstant=0;
    timeouts.WriteTotalTimeoutMultiplier=5;
    if(!SetCommTimeouts(hSerial, &timeouts)){
        printf("Error 5: Time out!\n");
    }
    ptrHandle[0] = hSerial;
    
    
    looping = true;
    
    
    hThreadRead = CreateThread( NULL, 0, 
           mavThreadRead, S, 0, NULL);
    ptrHandle[1] = hThreadRead;
    
    hThreadWrite = CreateThread( NULL, 0, 
           mavThreadWrite, S, 0, NULL);
    ptrHandle[2] = hThreadWrite;
    
}
#endif /*  MDL_START */


/* Function: mdlOutputs =======================================================
 * Abstract:
 *    In this function, you compute the outputs of your S-function
 *    block. Generally outputs are placed in the output vector(s),
 *    ssGetOutputPortSignal.
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
    int_T nOutputPorts = (int_T)mxGetNumberOfElements(MSG_OUT(S));
    int_T nOutputWidth; 
    real_T** ppPwork_data = (real_T**) ssGetPWork(S);
    
    real_T** outputArray;
    
    outputArray = (real_T**)calloc(nOutputPorts,sizeof(real_T*));
    
    for (int ii = 0; ii < nOutputPorts; ii++){
        *(outputArray+ii) = ssGetOutputPortRealSignal(S,ii);
        nOutputWidth = ssGetOutputPortWidth(S,ii);
        for (int jj = 0; jj < nOutputWidth; jj++){
            *(*(outputArray+ii) + jj) = ppPwork_data[ii][jj]; /* assign output values*/
        }        
    }
    free(outputArray);
   
//     looping = true;
} /* end mdlOutputs */


#define MDL_UPDATE  /* Change to #undef to remove function */
#if defined(MDL_UPDATE)
  /* Function: mdlUpdate ======================================================
   * Abstract:
   *    This function is called once for every major integration time step.
   *    Discrete states are typically updated here, but this function is useful
   *    for performing any tasks that should only take place once per
   *    integration step.
   */
static void mdlUpdate(SimStruct *S, int_T tid)
{
    int_T nInputPorts = ssGetNumInputPorts(S);
    int_T nInputPortWidth;
    uint8_T* ptrMsg_id_in = (uint8_T*) mxGetData(MSG_IN(S));
    InputRealPtrsType pInput;// = ssGetInputPortRealSignalPtrs(S,port);
    mavlink_message_t msg;
    uint16_T msg_len, buf_len, chksum;
    uint8_T* ptrBuf;
    real_T* ptrLen = (real_T*) ssGetRWork(S);
    
    for (int_T index = 0; index < nInputPorts; index++){             
        switch (*(ptrMsg_id_in+index)) {
            case MAVLINK_MSG_ID_SET_MODE: {
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                uint8_T mode = (uint8_T) (*pInput[0]);
                msg_len = mavlink_msg_set_mode_pack(255, 0, &msg, 1, mode, 1); //added last "1" by Weihua
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                
                chksum = crc_calculate(ptrBuf+3,msg_len-4);       /* checksum of the msg in the sending buffer */               
                buf_len = mavlink_msg_to_send_buffer(ptrBuf, &msg); 
                if (chksum == crc_calculate(ptrBuf+3,msg_len-4)){ /*check if the content has been changed */
                    if (ptrLen[index] == -1){ /*check if this msg has been sent*/
                        ptrLen[index] = 0; /* to prevent sending msg continuously */
                    } 
                } else {
                    ptrLen[index] = (real_T) buf_len;
                }
                
                break;
            }
            case MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST: {
                const real_T *rollIn = ssGetInputPortRealSignal(S,0);
                const real_T *pitchIn = ssGetInputPortRealSignal(S,1);
                const real_T *yawIn = ssGetInputPortRealSignal(S,2);
                const real_T *thrustIn = ssGetInputPortRealSignal(S,3);
                float rollVal = (float)rollIn[0];
                float pitchVal = (float)pitchIn[0];
                float yawVal = (float)yawIn[0];
                float thrustVal = (float)thrustIn[0];
                
                msg_len = mavlink_msg_set_roll_pitch_yaw_thrust_pack(255, 0, &msg, 1, 1, rollVal, pitchVal, yawVal, thrustVal);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                
                break;
                
            }
            case MAVLINK_MSG_ID_REQUEST_DATA_STREAM: {                
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                uint8_T stream_id = (uint8_T) (*pInput[0]);
                uint16_T msg_rate = (uint16_T) (*pInput[1]);
                uint8_T start_stop = (uint8_T) (*pInput[2]); 
                msg_len = mavlink_msg_request_data_stream_pack(255, 0, &msg, 1, 0, stream_id, msg_rate, start_stop);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                
                chksum = crc_calculate(ptrBuf+3,msg_len-4);       /* checksum just for the msg in the sending buffer */ 
                buf_len = mavlink_msg_to_send_buffer(ptrBuf, &msg);   
                if (chksum == crc_calculate(ptrBuf+3,msg_len-4)){ /*check if the content has been changed */
                    if (ptrLen[index] == -1){
                        ptrLen[index] = 0;
                    } 
                } else {
                    ptrLen[index] = (real_T) buf_len;
                }
                
                break;
            }
//            case MAVLINK_MSG_ID_ACTION:{
//                break;
//            }
            case MAVLINK_MSG_ID_ATTITUDE:{
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                uint64_T usec = (uint64_T) ((*pInput[0]) * 1000000);
                float roll = (float) (*pInput[1]);
                float pitch = (float) (*pInput[2]);
                float yaw = (float) (*pInput[3]);
                float p = (float) (*pInput[4]);
                float q = (float) (*pInput[5]);
                float r = (float) (*pInput[6]);
                msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
//            case MAVLINK_MSG_ID_GPS_RAW:{
//                pInput = ssGetInputPortRealSignalPtrs(S,index);
//                uint64_T usec = (uint64_T) ((*pInput[0]) * 1000000);
//                float lat = (float) (*pInput[1]);
//                float lon = (float) (*pInput[2]);
//                float alt = (float) (*pInput[3]);
//                float vel = (float) (*pInput[4]);
//                float hdg = (float) (*pInput[5]);
//                msg_len = mavlink_msg_gps_raw_pack(255, 0, &msg, usec, 0, lat, lon, alt, 0.0, 0.0, vel, hdg);
//                ptrBuf = (uint8_T*) ssGetDWork(S,index);
//                
//                chksum = crc_calculate(ptrBuf+3,msg_len-4);       /* checksum just for the msg in the sending buffer */ 
//                buf_len = mavlink_msg_to_send_buffer(ptrBuf, &msg);   
//                if (chksum == crc_calculate(ptrBuf+3,msg_len-4)){ /*check if the content has been changed */
//                    if (ptrLen[index] == -1){
//                        ptrLen[index] = 0;
//                    } 
//                } else {
//                    ptrLen[index] = (real_T) buf_len;
//                }
//                break;
//            }
            case MAVLINK_MSG_ID_VFR_HUD:{
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                float airspeed = (float) (*pInput[1]);
                msg_len = mavlink_msg_vfr_hud_pack(255, 0, &msg, airspeed, 0.0, 0, 0, 0.0, 0.0);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            
//          Weihua, Vicon message begin   
            case MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE:{  //send vicon position and euler angles
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                uint64_T usec = (uint64_T) ((*pInput[0]) * 1000000);
                float X = (float) (*pInput[1]);
                float Y = (float) (*pInput[2]);
                float Z = (float) (*pInput[3]);
                float Roll = (float) (*pInput[4]);
                float Pitch = (float) (*pInput[5]);
                float Yaw = (float) (*pInput[6]);
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_position_estimate_pack(255, 0, &msg,
						       usec, X, Y, Z, Roll, Pitch, Yaw);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
                        
            case MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE:{  //send vicon speed
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                uint64_T usec = (uint64_T) ((*pInput[0]) * 1000000);
                float X_Rate = (float) (*pInput[1]);
                float Y_Rate = (float) (*pInput[2]);
                float Z_Rate = (float) (*pInput[3]);
                mavlink_msg_vision_speed_estimate_pack(255, 0, &msg,
						       usec, X_Rate, Y_Rate, Z_Rate);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            case MAVLINK_MSG_ID_SET_LOCAL_POSITION_SETPOINT:{  //send Desired X, Y, Z, Yaw, target_system, target_component, coordinate_frame */
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                float X_Des = (float) (*pInput[0]);
                float Y_Des = (float) (*pInput[1]);
                float Z_Des = (float) (*pInput[2]);
                float Yaw_Des = (float) (*pInput[3]);
                uint8_T target_system = (uint8_T) (*pInput[4]);
                uint8_T target_component = (uint8_T) (*pInput[5]);
//                 mavlink_msg_vision_speed_estimate_pack(255, 0, &msg,
// 						       usec, X_Rate, Y_Rate, Z_Rate);
                mavlink_msg_set_local_position_setpoint_pack(255, 0, &msg,
						       target_system, target_component, MAV_FRAME_LOCAL_NED, X_Des, Y_Des, Z_Des, Yaw_Des);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
  //          Weihua, Vicon message end
            
// weihua, for Multiple UAV, 28April2013    
                      
             case MAVLINK_MSG_ID_VICON_Q1:{  //send quad 1 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
             
            case MAVLINK_MSG_ID_VICON_Q2:{  //send quad 2 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q3:{  //send quad 3 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[5]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            
            case MAVLINK_MSG_ID_VICON_Q4:{  //send quad 4 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
             
            case MAVLINK_MSG_ID_VICON_Q5:{  //send quad 5 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q6:{  //send quad 6 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[5]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            
            case MAVLINK_MSG_ID_VICON_Q7:{  //send quad 7 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
             
            case MAVLINK_MSG_ID_VICON_Q8:{  //send quad 8 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q9:{  //send quad 9 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[5]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            
            case MAVLINK_MSG_ID_VICON_Q10:{  //send quad 10 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            
            case MAVLINK_MSG_ID_VICON_Q11:{  //send quad 11 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[5]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
             
            case MAVLINK_MSG_ID_VICON_Q12:{  //send quad 12 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q13:{  //send quad 13 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[5]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            
            case MAVLINK_MSG_ID_VICON_Q14:{  //send quad 14 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
             
            case MAVLINK_MSG_ID_VICON_Q15:{  //send quad 15 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q16:{  //send quad 16 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[5]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            
            case MAVLINK_MSG_ID_VICON_Q17:{  //send quad 17 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
             
            case MAVLINK_MSG_ID_VICON_Q18:{  //send quad 18 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q19:{  //send quad 19 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[5]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            
            case MAVLINK_MSG_ID_VICON_Q20:{  //send quad 20 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
             
            case MAVLINK_MSG_ID_VICON_Q21:{  //send quad 21 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q22:{  //send quad 22 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[5]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            
            case MAVLINK_MSG_ID_VICON_Q23:{  //send quad 23 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
             
            case MAVLINK_MSG_ID_VICON_Q24:{  //send quad 24 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q25:{  //send quad 25 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[5]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            
            case MAVLINK_MSG_ID_VICON_Q26:{  //send quad 26 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
             
            case MAVLINK_MSG_ID_VICON_Q27:{  //send quad 27 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            case MAVLINK_MSG_ID_VICON_Q28:{  //send quad 28 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[5]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
            
            
            case MAVLINK_MSG_ID_VICON_Q29:{  //send quad 29 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
             
            case MAVLINK_MSG_ID_VICON_Q30:{  //send quad 30 commands
                pInput = ssGetInputPortRealSignalPtrs(S,index);
                int16_T thrust = (int16_T) ((*pInput[0])*10000); // Thrust X 10000
                int16_T roll = (int16_T) ((*pInput[1])*100); // Roll X 100
                int16_T pitch = (int16_T) ((*pInput[2])*100); // Pitch X 100
                int16_T yaw = (int16_T) ((*pInput[3])*100); // Yaw X 100
                int16_T pwm = (int16_T) (*pInput[4]); // PWM X 1
                uint8_T quad_id = (uint8_T) (*pInput[5]); 
          //      msg_len = mavlink_msg_attitude_pack(255, 0, &msg, usec, roll, pitch, yaw, p, q, r);
                mavlink_msg_vicon_q1_pack(255, 0, &msg,
						       quad_id, thrust, roll, pitch, yaw, pwm);
                ptrBuf = (uint8_T*) ssGetDWork(S,index);
                ptrLen[index] = (real_T) mavlink_msg_to_send_buffer(ptrBuf, &msg);
                break;
            }
              
            
            
            
// weihua, for Multiple UAV, 28April2013
                      
            
           
            default:
                break;
        }
    }
    

    
}
#endif /* MDL_UPDATE */

static void mdlTerminate(SimStruct *S)
{
    int_T nInputPorts = ssGetNumInputPorts(S);
    int_T nOutputPorts = (int_T)mxGetNumberOfElements(MSG_OUT(S));
    real_T** ppPwork_data = (real_T**) ssGetPWork(S);
    
    HANDLE* ptrHandle = (HANDLE*) ssGetDWork(S,nInputPorts);
    
    HANDLE hSerial = ptrHandle[0];
    HANDLE hThreadRead = ptrHandle[1];
    HANDLE hThreadWrite = ptrHandle[2];
    
    for(int ii = 0; ii < nOutputPorts; ii++){
        if(ppPwork_data[ii]!=NULL){
            free(ppPwork_data[ii]);        
        }     
    }    
    looping = false;
    Sleep(1000);
    CloseHandle(hThreadRead);
    CloseHandle(hThreadWrite);
    CloseHandle(hSerial);
}


DWORD WINAPI mavThreadRead(LPVOID lpParam) {
    SimStruct* S = (SimStruct*) lpParam;
    int_T nInputPorts = ssGetNumInputPorts(S);
    int_T nOutputPorts = (int_T)mxGetNumberOfElements(MSG_OUT(S));
    real_T** ppPwork_data = (real_T**) ssGetPWork(S);
    
    HANDLE* ptrHandle = (HANDLE*) ssGetDWork(S,nInputPorts);    
    HANDLE hSerial = ptrHandle[0];
    HANDLE hThreadRead = ptrHandle[1];
    HANDLE hThreadWrite = ptrHandle[2];
    
    int_T index;
    
	char szBuff[2] = {0};
	DWORD dwBytesRead = 0;
    DWORD dwRes;
    BOOL fWaitingOnRead = FALSE;
    OVERLAPPED osReader = {0};
    // Create the overlapped event. Must be closed before exiting
    // to avoid a handle leak.
    osReader.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
   
    
	mavlink_message_t msg;
	mavlink_status_t status;
   
    
    while (looping){
        if (!fWaitingOnRead) {
            // Issue read operation.
            if (!ReadFile(hSerial, szBuff, 1, &dwBytesRead, &osReader)) {
                if (GetLastError() != ERROR_IO_PENDING)     // read not delayed?
                    printf("Serial port Reading error!\n");
                else{
                    fWaitingOnRead = TRUE;
                    // printf("Serial port is waiting for data!\n");
                }                   
            }
            else {  
                // read completed immediately
                // HandleASuccessfulRead(lpBuf, dwRead);
                if(mavlink_parse_char(MAVLINK_COMM_0, szBuff[0], &msg, &status)){
                    mavlink_msg_decode(S, msg);
                }
            }
        } 
        else{
            dwRes = WaitForSingleObject(osReader.hEvent, INFINITE);
            switch(dwRes)
            {
                // Read completed.
                case WAIT_OBJECT_0:
                    if (!GetOverlappedResult(hSerial, &osReader, &dwBytesRead, FALSE))
                        // Error in communications; report it.
                        printf("Serial port Reading error after Overlapped!\n ");
                    else{
                        // Read completed successfully (may because reading timeout).
                        // HandleASuccessfulRead(lpBuf, dwRead);
                        if (dwBytesRead>0){
                            if(mavlink_parse_char(MAVLINK_COMM_0, szBuff[0], &msg, &status)){
                                mavlink_msg_decode(S, msg);
                            }
                        }
                        //  Reset flag so that another opertion can be issued.
                        fWaitingOnRead = FALSE;
                        // printf("%d Byte Data received after Overlapped!\n", (int)dwBytesRead);
                    }
                    break;
                case WAIT_TIMEOUT:
                        // Operation isn't complete yet. fWaitingOnRead flag isn't
                        // changed since I'll loop back around, and I don't want
                        // to issue another read until the first one finishes.
                        //
                        // This is a good time to do some background work.
                    printf("STILL Serial port is waiting for data!\n ");
                    break;                       

                default:
                        // Error in the WaitForSingleObject; abort.
                        // This indicates a problem with the OVERLAPPED structure's
                        // event handle.
                    break;
            }           
        }    
    }
    
    return 0;
}

DWORD WINAPI mavThreadWrite(LPVOID lpParam) {
    SimStruct* S = (SimStruct*) lpParam;
    int_T nInputPorts = ssGetNumInputPorts(S);
    uint8_T* ptrMsg_id_in = (uint8_T*) mxGetData(MSG_IN(S));    
  
    uint8_T* ptrBuf;
    real_T* ptrLen = (real_T*) ssGetRWork(S);
    
    printf("Serial write thread started\n");
    
    while ( looping ) {
        if ( ssGetT(S)>3){ //weihua, previous:10
         //   Sleep(20);      //weihua, previou: 20
            for (int ii = 0; ii < nInputPorts; ii++){
                if (ptrLen[ii] > 0){
                    ptrBuf = (uint8_T*) ssGetDWork(S,ii);
                    if ( WriteBuffer(ptrBuf, (DWORD)ptrLen[ii], S) ){
                        ptrLen[ii] = -1; /*buffer has been sent*/
    //                     memset(ptrBuf, 0, sizeof(ptrBuf));
//                         printf("Write OK!\n");
                    } else{
                        printf("Write error\n");
                    }
                }

            }
        }
	}
    printf("Serial write thread stopped\n");
    return 0;
}


int_T mavlink_msg_decode(SimStruct* S, mavlink_message_t msg)
{   
    int_T nOutputPorts = (int_T)mxGetNumberOfElements(MSG_OUT(S));
    real_T** ppPwork_data = (real_T**) ssGetPWork(S);
    
    uint8_T* ptrMsg_id_out = (uint8_T*) mxGetData(MSG_OUT(S));
    int8_T index;


    for (index = 0; index < nOutputPorts; index++){
        if (msg.msgid == *(ptrMsg_id_out + index))
            break;
    }
    if (index == nOutputPorts){
        index = -1;
        return -1;
        // printf("MSG ID does not match the required outputs!\n");
    }
    else{                
        switch (msg.msgid) {
            case MAVLINK_MSG_ID_HEARTBEAT:{
                ppPwork_data[index][0] = ppPwork_data[index][0]+1;
                break;
            }
            case MAVLINK_MSG_ID_ATTITUDE: {
                ppPwork_data[index][0] = (real_T) mavlink_msg_attitude_get_roll(&msg);
                ppPwork_data[index][1] = (real_T) mavlink_msg_attitude_get_pitch(&msg);
                ppPwork_data[index][2] = (real_T) mavlink_msg_attitude_get_yaw(&msg);
                ppPwork_data[index][3] = (real_T) mavlink_msg_attitude_get_rollspeed(&msg); //weihua, get ViconPose.X
                ppPwork_data[index][4] = (real_T) mavlink_msg_attitude_get_pitchspeed(&msg); //weihua, get ViconPose.Y
                ppPwork_data[index][5] = (real_T) mavlink_msg_attitude_get_yawspeed(&msg); //weihua, get ViconPose.Yaw
                break;
            }
            case MAVLINK_MSG_ID_RAW_IMU: {
                ppPwork_data[index][0] = (real_T) mavlink_msg_raw_imu_get_xacc(&msg);
                ppPwork_data[index][1] = (real_T) mavlink_msg_raw_imu_get_yacc(&msg);
                ppPwork_data[index][2] = (real_T) mavlink_msg_raw_imu_get_zacc(&msg);
                ppPwork_data[index][3] = (real_T) mavlink_msg_raw_imu_get_xgyro(&msg);
                ppPwork_data[index][4] = (real_T) mavlink_msg_raw_imu_get_ygyro(&msg);
                ppPwork_data[index][5] = (real_T) mavlink_msg_raw_imu_get_zgyro(&msg);
                ppPwork_data[index][6] = (real_T) mavlink_msg_raw_imu_get_xmag(&msg);
                ppPwork_data[index][7] = (real_T) mavlink_msg_raw_imu_get_ymag(&msg);
                ppPwork_data[index][8] = (real_T) mavlink_msg_raw_imu_get_zmag(&msg);
                break;
            }                
            case MAVLINK_MSG_ID_VFR_HUD: {
                ppPwork_data[index][0] = (real_T) mavlink_msg_vfr_hud_get_airspeed(&msg);
                ppPwork_data[index][1] = (real_T) mavlink_msg_vfr_hud_get_groundspeed(&msg);
                ppPwork_data[index][2] = (real_T) mavlink_msg_vfr_hud_get_heading(&msg);
                ppPwork_data[index][3] = (real_T) mavlink_msg_vfr_hud_get_alt(&msg);
                break;
            }
            case MAVLINK_MSG_ID_GLOBAL_POSITION_INT: {
                ppPwork_data[index][0] = ((real_T)mavlink_msg_global_position_int_get_lat(&msg))/10000000.0;
                ppPwork_data[index][1] = ((real_T)mavlink_msg_global_position_int_get_lon(&msg))/10000000.0;
                ppPwork_data[index][2] = ((real_T)mavlink_msg_global_position_int_get_alt(&msg))/1000.0;
                ppPwork_data[index][3] = ((real_T)mavlink_msg_global_position_int_get_vx(&msg))/100.0;
                ppPwork_data[index][4] = ((real_T)mavlink_msg_global_position_int_get_vy(&msg))/100.0;
                ppPwork_data[index][5] = ((real_T)mavlink_msg_global_position_int_get_vz(&msg))/100.0;
                break;
            }
            case MAVLINK_MSG_ID_RC_CHANNELS_SCALED:{
                ppPwork_data[index][0] = ((real_T) mavlink_msg_rc_channels_scaled_get_chan1_scaled(&msg)) / 1000;
                ppPwork_data[index][1] = ((real_T) mavlink_msg_rc_channels_scaled_get_chan2_scaled(&msg)) / 1000;
                ppPwork_data[index][2] = ((real_T) mavlink_msg_rc_channels_scaled_get_chan3_scaled(&msg)) / 1000;
                ppPwork_data[index][3] = ((real_T) mavlink_msg_rc_channels_scaled_get_chan4_scaled(&msg)) / 1000;
                ppPwork_data[index][4] = ((real_T) mavlink_msg_rc_channels_scaled_get_chan5_scaled(&msg)) / 1000;
                ppPwork_data[index][5] = ((real_T) mavlink_msg_rc_channels_scaled_get_chan6_scaled(&msg)) / 1000;
                ppPwork_data[index][6] = ((real_T) mavlink_msg_rc_channels_scaled_get_chan7_scaled(&msg)) / 1000;
                ppPwork_data[index][7] = ((real_T) mavlink_msg_rc_channels_scaled_get_chan8_scaled(&msg)) / 1000;
                break;
            }
            case MAVLINK_MSG_ID_SERVO_OUTPUT_RAW: {
                ppPwork_data[index][0] = (real_T) mavlink_msg_servo_output_raw_get_servo1_raw(&msg);
                ppPwork_data[index][1] = (real_T) mavlink_msg_servo_output_raw_get_servo2_raw(&msg);
                ppPwork_data[index][2] = (real_T) mavlink_msg_servo_output_raw_get_servo3_raw(&msg);
                ppPwork_data[index][3] = (real_T) mavlink_msg_servo_output_raw_get_servo4_raw(&msg);
                break;
            }
//             Weihua, Vicon data begin
            case MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE: {
                ppPwork_data[index][0] = (real_T) mavlink_msg_vicon_position_estimate_get_x(&msg);
                ppPwork_data[index][1] = (real_T) mavlink_msg_vicon_position_estimate_get_y(&msg);
                ppPwork_data[index][2] = (real_T) mavlink_msg_vicon_position_estimate_get_z(&msg);
                ppPwork_data[index][3] = (real_T) mavlink_msg_vicon_position_estimate_get_roll(&msg);
                ppPwork_data[index][4] = (real_T) mavlink_msg_vicon_position_estimate_get_pitch(&msg);
                ppPwork_data[index][5] = (real_T) mavlink_msg_vicon_position_estimate_get_yaw(&msg);
                break;
            }
//             Weihua, Vicon data end
            
            default:
                break;
        }
    }
    
    return (int_T)msg.msgid;
}

BOOL WriteBuffer(uint8_T* lpBuf, DWORD dwToWrite, SimStruct* S)
{
    int_T nInputPorts = ssGetNumInputPorts(S);
    HANDLE* ptrHandle = (HANDLE*) ssGetDWork(S,nInputPorts);    
    HANDLE hSerial = ptrHandle[0];
    HANDLE hThreadRead = ptrHandle[1];
    HANDLE hThreadWrite = ptrHandle[2];
    OVERLAPPED osWrite = {0};
    DWORD dwWritten;
    DWORD dwRes;
    BOOL fRes;

   // Create this write operation's OVERLAPPED structure's hEvent.
   osWrite.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
   if (osWrite.hEvent == NULL)
      // error creating overlapped event handle
      return FALSE;

   // Issue write.
   if (!WriteFile(hSerial, lpBuf, dwToWrite, &dwWritten, &osWrite)) {
      if (GetLastError() != ERROR_IO_PENDING) { 
         // WriteFile failed, but isn't delayed. Report error and abort.
         fRes = FALSE;
         printf("Serial port Writing error!\n");
      }
      else
         // Write is pending.
         dwRes = WaitForSingleObject(osWrite.hEvent, INFINITE);
         switch(dwRes)
         {
            // OVERLAPPED structure's event has been signaled. 
            case WAIT_OBJECT_0:
                 if (!GetOverlappedResult(hSerial, &osWrite, &dwWritten, FALSE))
                       fRes = FALSE;
                 else
                     if (dwToWrite > dwWritten)
                         printf("Serial port Writing timeout!\n");
                     // Write operation completed successfully.
                     fRes = TRUE;
                 
                 break;
            
            default:
                 // An error has occurred in WaitForSingleObject.
                 // This usually indicates a problem with the
                // OVERLAPPED structure's event handle.
                 fRes = FALSE;
                 break;
         }
      } else{
        // WriteFile completed immediately.
        fRes = TRUE;
      }

   CloseHandle(osWrite.hEvent);
   return fRes;
}

/*=============================*
 * Required S-function trailer *
 *=============================*/

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif

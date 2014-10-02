#ifndef __c7_four_quad_formation_040714_h__
#define __c7_four_quad_formation_040714_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc7_four_quad_formation_040714InstanceStruct
#define typedef_SFc7_four_quad_formation_040714InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c7_sfEvent;
  uint8_T c7_tp_Airborne;
  uint8_T c7_tp_Takeoff;
  uint8_T c7_tp_Landing;
  uint8_T c7_tp_Decsending;
  uint8_T c7_tp_CutThrottle;
  uint8_T c7_tp_firstpoint;
  uint8_T c7_tp_fourpoint;
  uint8_T c7_tp_secondpoint;
  uint8_T c7_tp_thirdpoint;
  boolean_T c7_isStable;
  uint8_T c7_is_active_c7_four_quad_formation_040714;
  uint8_T c7_is_c7_four_quad_formation_040714;
  uint8_T c7_is_Airborne;
  uint8_T c7_is_Landing;
  real_T c7_DeltaT;
  real_T c7_H0;
  real_T c7_Kl;
  real_T c7_Increm;
  real_T c7_omega_circle;
  real_T c7_PI;
  real_T c7_omega_h;
  real_T c7_Circle_R;
  real_T c7_MAX_Height;
  uint8_T c7_temporalCounter_i1;
  uint32_T c7_presentTicks;
  uint32_T c7_elapsedTicks;
  uint32_T c7_previousTicks;
  uint8_T c7_doSetSimStateSideEffects;
  const mxArray *c7_setSimStateSideEffectsInfo;
} SFc7_four_quad_formation_040714InstanceStruct;

#endif                                 /*typedef_SFc7_four_quad_formation_040714InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c7_four_quad_formation_040714_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c7_four_quad_formation_040714_get_check_sum(mxArray *plhs[]);
extern void c7_four_quad_formation_040714_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif

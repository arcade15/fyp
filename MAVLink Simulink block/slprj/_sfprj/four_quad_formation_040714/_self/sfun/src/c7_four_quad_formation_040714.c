/* Include files */

#include "blascompat32.h"
#include "four_quad_formation_040714_sfun.h"
#include "c7_four_quad_formation_040714.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "four_quad_formation_040714_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c7_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c7_IN_Airborne                 ((uint8_T)1U)
#define c7_IN_Landing                  ((uint8_T)2U)
#define c7_IN_Takeoff                  ((uint8_T)1U)
#define c7_IN_firstpoint               ((uint8_T)2U)
#define c7_IN_fourpoint                ((uint8_T)3U)
#define c7_IN_secondpoint              ((uint8_T)4U)
#define c7_IN_thirdpoint               ((uint8_T)5U)
#define c7_IN_CutThrottle              ((uint8_T)1U)
#define c7_IN_Decsending               ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance);
static void initialize_params_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance);
static void enable_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance);
static void disable_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance);
static void set_sim_state_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance, const mxArray
   *c7_st);
static void c7_set_sim_state_side_effects_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance);
static void finalize_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance);
static void sf_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance);
static void initSimStructsc7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance);
static void c7_Airborne(SFc7_four_quad_formation_040714InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static int32_T c7_emlrt_marshallIn(SFc7_four_quad_formation_040714InstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static uint8_T c7_b_emlrt_marshallIn
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance, const mxArray
   *c7_b_tp_Airborne, const char_T *c7_identifier);
static uint8_T c7_c_emlrt_marshallIn
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static real_T c7_d_emlrt_marshallIn
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance, const mxArray
   *c7_HoverThrottle, const char_T *c7_identifier);
static real_T c7_e_emlrt_marshallIn
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_f_emlrt_marshallIn(SFc7_four_quad_formation_040714InstanceStruct *
  chartInstance, const mxArray *c7_PosDes_UAV1, const char_T *c7_identifier,
  real_T c7_y[4]);
static void c7_g_emlrt_marshallIn(SFc7_four_quad_formation_040714InstanceStruct *
  chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_y[4]);
static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static uint32_T c7_h_emlrt_marshallIn
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance, const mxArray
   *c7_b_previousTicks, const char_T *c7_identifier);
static uint32_T c7_i_emlrt_marshallIn
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId);
static const mxArray *c7_j_emlrt_marshallIn
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance, const mxArray
   *c7_b_setSimStateSideEffectsInfo, const char_T *c7_identifier);
static const mxArray *c7_k_emlrt_marshallIn
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId);
static uint8_T c7__u8_u32_(SFc7_four_quad_formation_040714InstanceStruct
  *chartInstance, uint32_T c7_b);
static void init_dsm_address_info(SFc7_four_quad_formation_040714InstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance)
{
  int32_T c7_i0;
  real_T *c7_HoverThrottle;
  real_T *c7_pwm1;
  real_T (*c7_PosDes_UAV1)[4];
  c7_pwm1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_PosDes_UAV1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c7_HoverThrottle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c7_doSetSimStateSideEffects = 0U;
  chartInstance->c7_setSimStateSideEffectsInfo = NULL;
  chartInstance->c7_is_Airborne = c7_IN_NO_ACTIVE_CHILD;
  chartInstance->c7_tp_Airborne = 0U;
  chartInstance->c7_tp_Takeoff = 0U;
  chartInstance->c7_tp_firstpoint = 0U;
  chartInstance->c7_tp_fourpoint = 0U;
  chartInstance->c7_tp_secondpoint = 0U;
  chartInstance->c7_tp_thirdpoint = 0U;
  chartInstance->c7_is_Landing = c7_IN_NO_ACTIVE_CHILD;
  chartInstance->c7_tp_Landing = 0U;
  chartInstance->c7_tp_CutThrottle = 0U;
  chartInstance->c7_tp_Decsending = 0U;
  chartInstance->c7_is_active_c7_four_quad_formation_040714 = 0U;
  chartInstance->c7_is_c7_four_quad_formation_040714 = c7_IN_NO_ACTIVE_CHILD;
  chartInstance->c7_Increm = 0.0;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    *c7_HoverThrottle = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 2) != 0)) {
    for (c7_i0 = 0; c7_i0 < 4; c7_i0++) {
      (*c7_PosDes_UAV1)[c7_i0] = 0.0;
    }
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 3) != 0)) {
    *c7_pwm1 = 0.0;
  }

  chartInstance->c7_presentTicks = 0U;
  chartInstance->c7_elapsedTicks = 0U;
  chartInstance->c7_previousTicks = 0U;
}

static void initialize_params_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance)
{
  real_T c7_d0;
  real_T c7_d1;
  real_T c7_d2;
  real_T c7_d3;
  real_T c7_d4;
  real_T c7_d5;
  real_T c7_d6;
  real_T c7_d7;
  sf_set_error_prefix_string(
    "Error evaluating data 'DeltaT' in the parent workspace.\n");
  sf_mex_import_named("DeltaT", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c7_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_DeltaT = c7_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'H0' in the parent workspace.\n");
  sf_mex_import_named("H0", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c7_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_H0 = c7_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'Kl' in the parent workspace.\n");
  sf_mex_import_named("Kl", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      &c7_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_Kl = c7_d2;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'omega_circle' in the parent workspace.\n");
  sf_mex_import_named("omega_circle", sf_mex_get_sfun_param(chartInstance->S, 6,
    0), &c7_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_omega_circle = c7_d3;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'PI' in the parent workspace.\n");
  sf_mex_import_named("PI", sf_mex_get_sfun_param(chartInstance->S, 5, 0),
                      &c7_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_PI = c7_d4;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'omega_h' in the parent workspace.\n");
  sf_mex_import_named("omega_h", sf_mex_get_sfun_param(chartInstance->S, 7, 0),
                      &c7_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_omega_h = c7_d5;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'Circle_R' in the parent workspace.\n");
  sf_mex_import_named("Circle_R", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c7_d6, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_Circle_R = c7_d6;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'MAX_Height' in the parent workspace.\n");
  sf_mex_import_named("MAX_Height", sf_mex_get_sfun_param(chartInstance->S, 4, 0),
                      &c7_d7, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_MAX_Height = c7_d7;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c7_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.02
    + 0.5);
  chartInstance->c7_previousTicks = chartInstance->c7_presentTicks;
}

static void disable_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c7_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.02
    + 0.5);
  chartInstance->c7_elapsedTicks = chartInstance->c7_presentTicks -
    chartInstance->c7_previousTicks;
  chartInstance->c7_previousTicks = chartInstance->c7_presentTicks;
  if ((uint32_T)chartInstance->c7_temporalCounter_i1 +
      chartInstance->c7_elapsedTicks <= 255U) {
    chartInstance->c7_temporalCounter_i1 = c7__u8_u32_(chartInstance, (uint32_T)
      chartInstance->c7_temporalCounter_i1 + chartInstance->c7_elapsedTicks);
  } else {
    chartInstance->c7_temporalCounter_i1 = MAX_uint8_T;
  }
}

static void c7_update_debugger_state_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance)
{
  uint32_T c7_prevAniVal;
  c7_prevAniVal = sf_debug_get_animation();
  sf_debug_set_animation(0U);
  if (chartInstance->c7_is_active_c7_four_quad_formation_040714 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_four_quad_formation_040714 == c7_IN_Airborne) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_Airborne == c7_IN_Takeoff) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_four_quad_formation_040714 == c7_IN_Landing) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_Landing == c7_IN_Decsending) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_Landing == c7_IN_CutThrottle) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_Airborne == c7_IN_firstpoint) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_Airborne == c7_IN_fourpoint) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_Airborne == c7_IN_secondpoint) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_Airborne == c7_IN_thirdpoint) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c7_sfEvent);
  }

  sf_debug_set_animation(c7_prevAniVal);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  real_T c7_hoistedGlobal;
  real_T c7_u;
  const mxArray *c7_b_y = NULL;
  int32_T c7_i1;
  real_T c7_b_u[4];
  const mxArray *c7_c_y = NULL;
  real_T c7_b_hoistedGlobal;
  real_T c7_c_u;
  const mxArray *c7_d_y = NULL;
  real_T c7_c_hoistedGlobal;
  real_T c7_d_u;
  const mxArray *c7_e_y = NULL;
  uint8_T c7_d_hoistedGlobal;
  uint8_T c7_e_u;
  const mxArray *c7_f_y = NULL;
  uint8_T c7_e_hoistedGlobal;
  uint8_T c7_f_u;
  const mxArray *c7_g_y = NULL;
  uint8_T c7_f_hoistedGlobal;
  uint8_T c7_g_u;
  const mxArray *c7_h_y = NULL;
  uint8_T c7_g_hoistedGlobal;
  uint8_T c7_h_u;
  const mxArray *c7_i_y = NULL;
  uint8_T c7_h_hoistedGlobal;
  uint8_T c7_i_u;
  const mxArray *c7_j_y = NULL;
  uint32_T c7_i_hoistedGlobal;
  uint32_T c7_j_u;
  const mxArray *c7_k_y = NULL;
  real_T *c7_HoverThrottle;
  real_T *c7_pwm1;
  real_T (*c7_PosDes_UAV1)[4];
  c7_pwm1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_PosDes_UAV1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c7_HoverThrottle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellarray(10), FALSE);
  c7_hoistedGlobal = *c7_HoverThrottle;
  c7_u = c7_hoistedGlobal;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  for (c7_i1 = 0; c7_i1 < 4; c7_i1++) {
    c7_b_u[c7_i1] = (*c7_PosDes_UAV1)[c7_i1];
  }

  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", c7_b_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  c7_b_hoistedGlobal = *c7_pwm1;
  c7_c_u = c7_b_hoistedGlobal;
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 2, c7_d_y);
  c7_c_hoistedGlobal = chartInstance->c7_Increm;
  c7_d_u = c7_c_hoistedGlobal;
  c7_e_y = NULL;
  sf_mex_assign(&c7_e_y, sf_mex_create("y", &c7_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 3, c7_e_y);
  c7_d_hoistedGlobal = chartInstance->c7_is_active_c7_four_quad_formation_040714;
  c7_e_u = c7_d_hoistedGlobal;
  c7_f_y = NULL;
  sf_mex_assign(&c7_f_y, sf_mex_create("y", &c7_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 4, c7_f_y);
  c7_e_hoistedGlobal = chartInstance->c7_is_c7_four_quad_formation_040714;
  c7_f_u = c7_e_hoistedGlobal;
  c7_g_y = NULL;
  sf_mex_assign(&c7_g_y, sf_mex_create("y", &c7_f_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 5, c7_g_y);
  c7_f_hoistedGlobal = chartInstance->c7_is_Airborne;
  c7_g_u = c7_f_hoistedGlobal;
  c7_h_y = NULL;
  sf_mex_assign(&c7_h_y, sf_mex_create("y", &c7_g_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 6, c7_h_y);
  c7_g_hoistedGlobal = chartInstance->c7_is_Landing;
  c7_h_u = c7_g_hoistedGlobal;
  c7_i_y = NULL;
  sf_mex_assign(&c7_i_y, sf_mex_create("y", &c7_h_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 7, c7_i_y);
  c7_h_hoistedGlobal = chartInstance->c7_temporalCounter_i1;
  c7_i_u = c7_h_hoistedGlobal;
  c7_j_y = NULL;
  sf_mex_assign(&c7_j_y, sf_mex_create("y", &c7_i_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 8, c7_j_y);
  c7_i_hoistedGlobal = chartInstance->c7_previousTicks;
  c7_j_u = c7_i_hoistedGlobal;
  c7_k_y = NULL;
  sf_mex_assign(&c7_k_y, sf_mex_create("y", &c7_j_u, 7, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 9, c7_k_y);
  sf_mex_assign(&c7_st, c7_y, FALSE);
  return c7_st;
}

static void set_sim_state_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance, const mxArray
   *c7_st)
{
  const mxArray *c7_u;
  real_T c7_dv0[4];
  int32_T c7_i2;
  real_T *c7_HoverThrottle;
  real_T *c7_pwm1;
  real_T (*c7_PosDes_UAV1)[4];
  c7_pwm1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_PosDes_UAV1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c7_HoverThrottle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_u = sf_mex_dup(c7_st);
  *c7_HoverThrottle = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c7_u, 0)), "HoverThrottle");
  c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 1)),
                        "PosDes_UAV1", c7_dv0);
  for (c7_i2 = 0; c7_i2 < 4; c7_i2++) {
    (*c7_PosDes_UAV1)[c7_i2] = c7_dv0[c7_i2];
  }

  *c7_pwm1 = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u,
    2)), "pwm1");
  chartInstance->c7_Increm = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c7_u, 3)), "Increm");
  chartInstance->c7_is_active_c7_four_quad_formation_040714 =
    c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 4)),
    "is_active_c7_four_quad_formation_040714");
  chartInstance->c7_is_c7_four_quad_formation_040714 = c7_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 5)),
     "is_c7_four_quad_formation_040714");
  chartInstance->c7_is_Airborne = c7_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 6)), "is_Airborne");
  chartInstance->c7_is_Landing = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c7_u, 7)), "is_Landing");
  chartInstance->c7_temporalCounter_i1 = c7_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 8)), "temporalCounter_i1");
  chartInstance->c7_previousTicks = c7_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 9)), "previousTicks");
  sf_mex_assign(&chartInstance->c7_setSimStateSideEffectsInfo,
                c7_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 10)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c7_u);
  chartInstance->c7_doSetSimStateSideEffects = 1U;
  c7_update_debugger_state_c7_four_quad_formation_040714(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void c7_set_sim_state_side_effects_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance)
{
  if (chartInstance->c7_doSetSimStateSideEffects != 0) {
    if (chartInstance->c7_is_c7_four_quad_formation_040714 == c7_IN_Airborne) {
      chartInstance->c7_tp_Airborne = 1U;
    } else {
      chartInstance->c7_tp_Airborne = 0U;
    }

    if (chartInstance->c7_is_Airborne == c7_IN_Takeoff) {
      chartInstance->c7_tp_Takeoff = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_Takeoff = 0U;
    }

    if (chartInstance->c7_is_Airborne == c7_IN_firstpoint) {
      chartInstance->c7_tp_firstpoint = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_firstpoint = 0U;
    }

    if (chartInstance->c7_is_Airborne == c7_IN_fourpoint) {
      chartInstance->c7_tp_fourpoint = 1U;
    } else {
      chartInstance->c7_tp_fourpoint = 0U;
    }

    if (chartInstance->c7_is_Airborne == c7_IN_secondpoint) {
      chartInstance->c7_tp_secondpoint = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 6) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_secondpoint = 0U;
    }

    if (chartInstance->c7_is_Airborne == c7_IN_thirdpoint) {
      chartInstance->c7_tp_thirdpoint = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_thirdpoint = 0U;
    }

    if (chartInstance->c7_is_c7_four_quad_formation_040714 == c7_IN_Landing) {
      chartInstance->c7_tp_Landing = 1U;
    } else {
      chartInstance->c7_tp_Landing = 0U;
    }

    if (chartInstance->c7_is_Landing == c7_IN_CutThrottle) {
      chartInstance->c7_tp_CutThrottle = 1U;
    } else {
      chartInstance->c7_tp_CutThrottle = 0U;
    }

    if (chartInstance->c7_is_Landing == c7_IN_Decsending) {
      chartInstance->c7_tp_Decsending = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 10) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_Decsending = 0U;
    }

    chartInstance->c7_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c7_setSimStateSideEffectsInfo);
}

static void sf_c7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance)
{
  int32_T c7_i3;
  int32_T c7_i4;
  int32_T c7_i5;
  real_T c7_d8;
  int32_T c7_i6;
  int32_T c7_i7;
  boolean_T c7_out;
  int32_T c7_i8;
  int32_T c7_i9;
  boolean_T c7_temp;
  boolean_T c7_b_out;
  boolean_T c7_c_out;
  int32_T c7_i10;
  real_T *c7_HoverThrottle;
  real_T *c7_pwm1;
  real_T (*c7_PosDes_UAV1)[4];
  real_T (*c7_RC)[8];
  real_T (*c7_Pos_UAV1)[4];
  boolean_T guard1 = FALSE;
  c7_pwm1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_Pos_UAV1 = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c7_RC = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 0);
  c7_PosDes_UAV1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c7_HoverThrottle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_set_sim_state_side_effects_c7_four_quad_formation_040714(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c7_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.02
    + 0.5);
  chartInstance->c7_elapsedTicks = chartInstance->c7_presentTicks -
    chartInstance->c7_previousTicks;
  chartInstance->c7_previousTicks = chartInstance->c7_presentTicks;
  if ((uint32_T)chartInstance->c7_temporalCounter_i1 +
      chartInstance->c7_elapsedTicks <= 255U) {
    chartInstance->c7_temporalCounter_i1 = c7__u8_u32_(chartInstance, (uint32_T)
      chartInstance->c7_temporalCounter_i1 + chartInstance->c7_elapsedTicks);
  } else {
    chartInstance->c7_temporalCounter_i1 = MAX_uint8_T;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c7_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c7_HoverThrottle, 0U);
  for (c7_i3 = 0; c7_i3 < 4; c7_i3++) {
    _SFD_DATA_RANGE_CHECK((*c7_PosDes_UAV1)[c7_i3], 1U);
  }

  for (c7_i4 = 0; c7_i4 < 8; c7_i4++) {
    _SFD_DATA_RANGE_CHECK((*c7_RC)[c7_i4], 2U);
  }

  for (c7_i5 = 0; c7_i5 < 4; c7_i5++) {
    _SFD_DATA_RANGE_CHECK((*c7_Pos_UAV1)[c7_i5], 3U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c7_DeltaT, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c7_H0, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c7_Kl, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c7_Increm, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c7_omega_circle, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c7_PI, 9U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c7_omega_h, 10U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c7_Circle_R, 11U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c7_MAX_Height, 12U);
  _SFD_DATA_RANGE_CHECK(*c7_pwm1, 13U);
  chartInstance->c7_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c7_sfEvent);
  if (chartInstance->c7_is_active_c7_four_quad_formation_040714 == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c7_sfEvent);
    chartInstance->c7_is_active_c7_four_quad_formation_040714 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c7_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c7_sfEvent);
    *c7_HoverThrottle = 0.0;
    _SFD_DATA_RANGE_CHECK(*c7_HoverThrottle, 0U);
    c7_d8 = *c7_HoverThrottle;
    sf_mex_printf("%s =\\n", "HoverThrottle");
    sf_mex_call_debug("disp", 0U, 1U, 6, c7_d8);
    chartInstance->c7_is_c7_four_quad_formation_040714 = c7_IN_Landing;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_Landing = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c7_sfEvent);
    chartInstance->c7_is_Landing = c7_IN_Decsending;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c7_sfEvent);
    chartInstance->c7_temporalCounter_i1 = 0U;
    chartInstance->c7_tp_Decsending = 1U;
    for (c7_i6 = 0; c7_i6 < 4; c7_i6++) {
      (*c7_PosDes_UAV1)[c7_i6] = (*c7_Pos_UAV1)[c7_i6];
    }

    for (c7_i7 = 0; c7_i7 < 4; c7_i7++) {
      _SFD_DATA_RANGE_CHECK((*c7_PosDes_UAV1)[c7_i7], 1U);
    }
  } else {
    switch (chartInstance->c7_is_c7_four_quad_formation_040714) {
     case c7_IN_Airborne:
      CV_CHART_EVAL(0, 0, 1);
      c7_Airborne(chartInstance);
      break;

     case c7_IN_Landing:
      CV_CHART_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c7_sfEvent);
      c7_out = (CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2U, 0, (*c7_RC)[6]
                  > 0.5 != 0U, chartInstance->c7_sfEvent)) != 0);
      if (c7_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c7_sfEvent);
        switch (chartInstance->c7_is_Landing) {
         case c7_IN_CutThrottle:
          CV_STATE_EVAL(6, 1, 1);
          chartInstance->c7_tp_CutThrottle = 0U;
          chartInstance->c7_is_Landing = c7_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c7_sfEvent);
          break;

         case c7_IN_Decsending:
          CV_STATE_EVAL(6, 1, 2);
          chartInstance->c7_tp_Decsending = 0U;
          chartInstance->c7_is_Landing = c7_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c7_sfEvent);
          break;

         default:
          CV_STATE_EVAL(6, 1, 0);
          chartInstance->c7_is_Landing = c7_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c7_sfEvent);
          break;
        }

        chartInstance->c7_tp_Landing = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c7_sfEvent);
        chartInstance->c7_is_c7_four_quad_formation_040714 = c7_IN_Airborne;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c7_sfEvent);
        chartInstance->c7_tp_Airborne = 1U;
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c7_sfEvent);
        for (c7_i8 = 0; c7_i8 < 4; c7_i8++) {
          (*c7_PosDes_UAV1)[c7_i8] = (*c7_Pos_UAV1)[c7_i8];
        }

        for (c7_i9 = 0; c7_i9 < 4; c7_i9++) {
          _SFD_DATA_RANGE_CHECK((*c7_PosDes_UAV1)[c7_i9], 1U);
        }

        chartInstance->c7_is_Airborne = c7_IN_Takeoff;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c7_sfEvent);
        chartInstance->c7_temporalCounter_i1 = 0U;
        chartInstance->c7_tp_Takeoff = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                     chartInstance->c7_sfEvent);
        switch (chartInstance->c7_is_Landing) {
         case c7_IN_CutThrottle:
          CV_STATE_EVAL(6, 0, 1);
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                       chartInstance->c7_sfEvent);
          *c7_HoverThrottle += (0.0 - *c7_HoverThrottle) * 3.0 *
            chartInstance->c7_DeltaT;
          _SFD_DATA_RANGE_CHECK(*c7_HoverThrottle, 0U);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c7_sfEvent);
          break;

         case c7_IN_Decsending:
          CV_STATE_EVAL(6, 0, 2);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                       chartInstance->c7_sfEvent);
          c7_temp = (_SFD_CCP_CALL(6U, 0, 1 != 0U, chartInstance->c7_sfEvent) !=
                     0);
          if (c7_temp) {
            c7_temp = (_SFD_CCP_CALL(6U, 1, chartInstance->c7_temporalCounter_i1
                        >= 100U != 0U, chartInstance->c7_sfEvent) != 0);
          }

          c7_b_out = (CV_TRANSITION_EVAL(6U, (int32_T)c7_temp) != 0);
          guard1 = FALSE;
          if (c7_b_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c7_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                         chartInstance->c7_sfEvent);
            c7_c_out = (CV_TRANSITION_EVAL(5U, (int32_T)_SFD_CCP_CALL(5U, 0,
              (*c7_Pos_UAV1)[2] > -0.2 != 0U, chartInstance->c7_sfEvent)) != 0);
            if (c7_c_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c7_sfEvent);
              chartInstance->c7_tp_Decsending = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c7_sfEvent);
              chartInstance->c7_is_Landing = c7_IN_CutThrottle;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c7_sfEvent);
              chartInstance->c7_tp_CutThrottle = 1U;
            } else {
              guard1 = TRUE;
            }
          } else {
            guard1 = TRUE;
          }

          if (guard1 == TRUE) {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                         chartInstance->c7_sfEvent);
            (*c7_PosDes_UAV1)[2] += (0.0 - (*c7_PosDes_UAV1)[2]) * 0.2 *
              chartInstance->c7_DeltaT;
            for (c7_i10 = 0; c7_i10 < 4; c7_i10++) {
              _SFD_DATA_RANGE_CHECK((*c7_PosDes_UAV1)[c7_i10], 1U);
            }
          }

          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c7_sfEvent);
          break;

         default:
          CV_STATE_EVAL(6, 0, 0);
          chartInstance->c7_is_Landing = c7_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c7_sfEvent);
          break;
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);
      chartInstance->c7_is_c7_four_quad_formation_040714 = c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c7_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c7_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_four_quad_formation_040714MachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc7_four_quad_formation_040714
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance)
{
}

static void c7_Airborne(SFc7_four_quad_formation_040714InstanceStruct
  *chartInstance)
{
  boolean_T c7_out;
  int32_T c7_i11;
  int32_T c7_i12;
  boolean_T c7_temp;
  boolean_T c7_b_out;
  int32_T c7_i13;
  boolean_T c7_b_temp;
  boolean_T c7_c_out;
  int32_T c7_i14;
  int32_T c7_i15;
  int32_T c7_i16;
  int32_T c7_i17;
  int32_T c7_i18;
  int32_T c7_i19;
  boolean_T c7_c_temp;
  boolean_T c7_d_out;
  int32_T c7_i20;
  int32_T c7_i21;
  int32_T c7_i22;
  boolean_T c7_d_temp;
  boolean_T c7_e_out;
  int32_T c7_i23;
  int32_T c7_i24;
  int32_T c7_i25;
  real_T *c7_HoverThrottle;
  real_T (*c7_PosDes_UAV1)[4];
  real_T (*c7_RC)[8];
  real_T (*c7_Pos_UAV1)[4];
  c7_Pos_UAV1 = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c7_RC = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 0);
  c7_PosDes_UAV1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c7_HoverThrottle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c7_sfEvent);
  c7_out = (CV_TRANSITION_EVAL(3U, (int32_T)_SFD_CCP_CALL(3U, 0, (*c7_RC)[6] <
              -0.5 != 0U, chartInstance->c7_sfEvent)) != 0);
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c7_sfEvent);
    switch (chartInstance->c7_is_Airborne) {
     case c7_IN_Takeoff:
      CV_STATE_EVAL(0, 1, 1);
      chartInstance->c7_tp_Takeoff = 0U;
      chartInstance->c7_is_Airborne = c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c7_sfEvent);
      break;

     case c7_IN_firstpoint:
      CV_STATE_EVAL(0, 1, 2);
      chartInstance->c7_tp_firstpoint = 0U;
      chartInstance->c7_is_Airborne = c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c7_sfEvent);
      break;

     case c7_IN_fourpoint:
      CV_STATE_EVAL(0, 1, 3);
      chartInstance->c7_tp_fourpoint = 0U;
      chartInstance->c7_is_Airborne = c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c7_sfEvent);
      break;

     case c7_IN_secondpoint:
      CV_STATE_EVAL(0, 1, 4);
      chartInstance->c7_tp_secondpoint = 0U;
      chartInstance->c7_is_Airborne = c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c7_sfEvent);
      break;

     case c7_IN_thirdpoint:
      CV_STATE_EVAL(0, 1, 5);
      chartInstance->c7_tp_thirdpoint = 0U;
      chartInstance->c7_is_Airborne = c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c7_sfEvent);
      break;

     default:
      CV_STATE_EVAL(0, 1, 0);
      chartInstance->c7_is_Airborne = c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c7_sfEvent);
      break;
    }

    chartInstance->c7_tp_Airborne = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c7_sfEvent);
    chartInstance->c7_is_c7_four_quad_formation_040714 = c7_IN_Landing;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_Landing = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c7_sfEvent);
    chartInstance->c7_is_Landing = c7_IN_Decsending;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c7_sfEvent);
    chartInstance->c7_temporalCounter_i1 = 0U;
    chartInstance->c7_tp_Decsending = 1U;
    for (c7_i11 = 0; c7_i11 < 4; c7_i11++) {
      (*c7_PosDes_UAV1)[c7_i11] = (*c7_Pos_UAV1)[c7_i11];
    }

    for (c7_i12 = 0; c7_i12 < 4; c7_i12++) {
      _SFD_DATA_RANGE_CHECK((*c7_PosDes_UAV1)[c7_i12], 1U);
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c7_sfEvent);
    switch (chartInstance->c7_is_Airborne) {
     case c7_IN_Takeoff:
      CV_STATE_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                   chartInstance->c7_sfEvent);
      c7_temp = (_SFD_CCP_CALL(10U, 0, 1 != 0U, chartInstance->c7_sfEvent) != 0);
      if (c7_temp) {
        c7_temp = (_SFD_CCP_CALL(10U, 1, chartInstance->c7_temporalCounter_i1 >=
                    250U != 0U, chartInstance->c7_sfEvent) != 0);
      }

      c7_b_out = (CV_TRANSITION_EVAL(10U, (int32_T)c7_temp) != 0);
      if (c7_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c7_sfEvent);
        chartInstance->c7_tp_Takeoff = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c7_sfEvent);
        chartInstance->c7_is_Airborne = c7_IN_firstpoint;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c7_sfEvent);
        chartInstance->c7_temporalCounter_i1 = 0U;
        chartInstance->c7_tp_firstpoint = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c7_sfEvent);
        *c7_HoverThrottle += (chartInstance->c7_H0 - *c7_HoverThrottle) * 2.0 *
          chartInstance->c7_DeltaT;
        _SFD_DATA_RANGE_CHECK(*c7_HoverThrottle, 0U);
        (*c7_PosDes_UAV1)[2] += (-1.2 - (*c7_PosDes_UAV1)[2]) *
          chartInstance->c7_DeltaT;
        for (c7_i13 = 0; c7_i13 < 4; c7_i13++) {
          _SFD_DATA_RANGE_CHECK((*c7_PosDes_UAV1)[c7_i13], 1U);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c7_sfEvent);
      break;

     case c7_IN_firstpoint:
      CV_STATE_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c7_sfEvent);
      c7_b_temp = (_SFD_CCP_CALL(7U, 0, 1 != 0U, chartInstance->c7_sfEvent) != 0);
      if (c7_b_temp) {
        c7_b_temp = (_SFD_CCP_CALL(7U, 1, chartInstance->c7_temporalCounter_i1 >=
          150U != 0U, chartInstance->c7_sfEvent) != 0);
      }

      c7_c_out = (CV_TRANSITION_EVAL(7U, (int32_T)c7_b_temp) != 0);
      if (c7_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c7_sfEvent);
        chartInstance->c7_tp_firstpoint = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c7_sfEvent);
        chartInstance->c7_is_Airborne = c7_IN_secondpoint;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c7_sfEvent);
        chartInstance->c7_temporalCounter_i1 = 0U;
        chartInstance->c7_tp_secondpoint = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c7_sfEvent);
        (*c7_PosDes_UAV1)[2] += (-1.2 - (*c7_PosDes_UAV1)[2]) *
          chartInstance->c7_DeltaT;
        for (c7_i14 = 0; c7_i14 < 4; c7_i14++) {
          _SFD_DATA_RANGE_CHECK((*c7_PosDes_UAV1)[c7_i14], 1U);
        }

        (*c7_PosDes_UAV1)[1] += (0.0 - (*c7_PosDes_UAV1)[1]) *
          chartInstance->c7_DeltaT;
        for (c7_i15 = 0; c7_i15 < 4; c7_i15++) {
          _SFD_DATA_RANGE_CHECK((*c7_PosDes_UAV1)[c7_i15], 1U);
        }

        (*c7_PosDes_UAV1)[0] += (-1.0 - (*c7_PosDes_UAV1)[0]) *
          chartInstance->c7_DeltaT;
        for (c7_i16 = 0; c7_i16 < 4; c7_i16++) {
          _SFD_DATA_RANGE_CHECK((*c7_PosDes_UAV1)[c7_i16], 1U);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c7_sfEvent);
      break;

     case c7_IN_fourpoint:
      CV_STATE_EVAL(0, 0, 3);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c7_sfEvent);
      (*c7_PosDes_UAV1)[2] = -1.2;
      for (c7_i17 = 0; c7_i17 < 4; c7_i17++) {
        _SFD_DATA_RANGE_CHECK((*c7_PosDes_UAV1)[c7_i17], 1U);
      }

      (*c7_PosDes_UAV1)[1] += (0.0 - (*c7_PosDes_UAV1)[1]) *
        chartInstance->c7_DeltaT;
      for (c7_i18 = 0; c7_i18 < 4; c7_i18++) {
        _SFD_DATA_RANGE_CHECK((*c7_PosDes_UAV1)[c7_i18], 1U);
      }

      (*c7_PosDes_UAV1)[0] += (0.0 - (*c7_PosDes_UAV1)[0]) *
        chartInstance->c7_DeltaT;
      for (c7_i19 = 0; c7_i19 < 4; c7_i19++) {
        _SFD_DATA_RANGE_CHECK((*c7_PosDes_UAV1)[c7_i19], 1U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c7_sfEvent);
      break;

     case c7_IN_secondpoint:
      CV_STATE_EVAL(0, 0, 4);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                   chartInstance->c7_sfEvent);
      c7_c_temp = (_SFD_CCP_CALL(8U, 0, 1 != 0U, chartInstance->c7_sfEvent) != 0);
      if (c7_c_temp) {
        c7_c_temp = (_SFD_CCP_CALL(8U, 1, chartInstance->c7_temporalCounter_i1 >=
          150U != 0U, chartInstance->c7_sfEvent) != 0);
      }

      c7_d_out = (CV_TRANSITION_EVAL(8U, (int32_T)c7_c_temp) != 0);
      if (c7_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c7_sfEvent);
        chartInstance->c7_tp_secondpoint = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c7_sfEvent);
        chartInstance->c7_is_Airborne = c7_IN_thirdpoint;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c7_sfEvent);
        chartInstance->c7_temporalCounter_i1 = 0U;
        chartInstance->c7_tp_thirdpoint = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                     chartInstance->c7_sfEvent);
        (*c7_PosDes_UAV1)[2] = -1.2;
        for (c7_i20 = 0; c7_i20 < 4; c7_i20++) {
          _SFD_DATA_RANGE_CHECK((*c7_PosDes_UAV1)[c7_i20], 1U);
        }

        (*c7_PosDes_UAV1)[1] += (-1.0 - (*c7_PosDes_UAV1)[1]) *
          chartInstance->c7_DeltaT;
        for (c7_i21 = 0; c7_i21 < 4; c7_i21++) {
          _SFD_DATA_RANGE_CHECK((*c7_PosDes_UAV1)[c7_i21], 1U);
        }

        (*c7_PosDes_UAV1)[0] += (-1.0 - (*c7_PosDes_UAV1)[0]) *
          chartInstance->c7_DeltaT;
        for (c7_i22 = 0; c7_i22 < 4; c7_i22++) {
          _SFD_DATA_RANGE_CHECK((*c7_PosDes_UAV1)[c7_i22], 1U);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c7_sfEvent);
      break;

     case c7_IN_thirdpoint:
      CV_STATE_EVAL(0, 0, 5);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                   chartInstance->c7_sfEvent);
      c7_d_temp = (_SFD_CCP_CALL(9U, 0, 1 != 0U, chartInstance->c7_sfEvent) != 0);
      if (c7_d_temp) {
        c7_d_temp = (_SFD_CCP_CALL(9U, 1, chartInstance->c7_temporalCounter_i1 >=
          150U != 0U, chartInstance->c7_sfEvent) != 0);
      }

      c7_e_out = (CV_TRANSITION_EVAL(9U, (int32_T)c7_d_temp) != 0);
      if (c7_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c7_sfEvent);
        chartInstance->c7_tp_thirdpoint = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c7_sfEvent);
        chartInstance->c7_is_Airborne = c7_IN_fourpoint;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c7_sfEvent);
        chartInstance->c7_tp_fourpoint = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                     chartInstance->c7_sfEvent);
        (*c7_PosDes_UAV1)[2] = -1.2;
        for (c7_i23 = 0; c7_i23 < 4; c7_i23++) {
          _SFD_DATA_RANGE_CHECK((*c7_PosDes_UAV1)[c7_i23], 1U);
        }

        (*c7_PosDes_UAV1)[1] += (-1.0 - (*c7_PosDes_UAV1)[1]) *
          chartInstance->c7_DeltaT;
        for (c7_i24 = 0; c7_i24 < 4; c7_i24++) {
          _SFD_DATA_RANGE_CHECK((*c7_PosDes_UAV1)[c7_i24], 1U);
        }

        (*c7_PosDes_UAV1)[0] += (0.0 - (*c7_PosDes_UAV1)[0]) *
          chartInstance->c7_DeltaT;
        for (c7_i25 = 0; c7_i25 < 4; c7_i25++) {
          _SFD_DATA_RANGE_CHECK((*c7_PosDes_UAV1)[c7_i25], 1U);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c7_sfEvent);
      break;

     default:
      CV_STATE_EVAL(0, 0, 0);
      chartInstance->c7_is_Airborne = c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c7_sfEvent);
      break;
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c7_sfEvent);
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

const mxArray *sf_c7_four_quad_formation_040714_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c7_nameCaptureInfo;
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_four_quad_formation_040714InstanceStruct *chartInstance;
  chartInstance = (SFc7_four_quad_formation_040714InstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static int32_T c7_emlrt_marshallIn(SFc7_four_quad_formation_040714InstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i26;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i26, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i26;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_four_quad_formation_040714InstanceStruct *chartInstance;
  chartInstance = (SFc7_four_quad_formation_040714InstanceStruct *)
    chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent), &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  uint8_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_four_quad_formation_040714InstanceStruct *chartInstance;
  chartInstance = (SFc7_four_quad_formation_040714InstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(uint8_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static uint8_T c7_b_emlrt_marshallIn
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance, const mxArray
   *c7_b_tp_Airborne, const char_T *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_tp_Airborne),
    &c7_thisId);
  sf_mex_destroy(&c7_b_tp_Airborne);
  return c7_y;
}

static uint8_T c7_c_emlrt_marshallIn
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_tp_Airborne;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  uint8_T c7_y;
  SFc7_four_quad_formation_040714InstanceStruct *chartInstance;
  chartInstance = (SFc7_four_quad_formation_040714InstanceStruct *)
    chartInstanceVoid;
  c7_b_tp_Airborne = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_tp_Airborne),
    &c7_thisId);
  sf_mex_destroy(&c7_b_tp_Airborne);
  *(uint8_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_four_quad_formation_040714InstanceStruct *chartInstance;
  chartInstance = (SFc7_four_quad_formation_040714InstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static real_T c7_d_emlrt_marshallIn
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance, const mxArray
   *c7_HoverThrottle, const char_T *c7_identifier)
{
  real_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_HoverThrottle),
    &c7_thisId);
  sf_mex_destroy(&c7_HoverThrottle);
  return c7_y;
}

static real_T c7_e_emlrt_marshallIn
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d9;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d9, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d9;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_HoverThrottle;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_four_quad_formation_040714InstanceStruct *chartInstance;
  chartInstance = (SFc7_four_quad_formation_040714InstanceStruct *)
    chartInstanceVoid;
  c7_HoverThrottle = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_HoverThrottle),
    &c7_thisId);
  sf_mex_destroy(&c7_HoverThrottle);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i27;
  real_T c7_b_inData[4];
  int32_T c7_i28;
  real_T c7_u[4];
  const mxArray *c7_y = NULL;
  SFc7_four_quad_formation_040714InstanceStruct *chartInstance;
  chartInstance = (SFc7_four_quad_formation_040714InstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i27 = 0; c7_i27 < 4; c7_i27++) {
    c7_b_inData[c7_i27] = (*(real_T (*)[4])c7_inData)[c7_i27];
  }

  for (c7_i28 = 0; c7_i28 < 4; c7_i28++) {
    c7_u[c7_i28] = c7_b_inData[c7_i28];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static void c7_f_emlrt_marshallIn(SFc7_four_quad_formation_040714InstanceStruct *
  chartInstance, const mxArray *c7_PosDes_UAV1, const char_T *c7_identifier,
  real_T c7_y[4])
{
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_PosDes_UAV1), &c7_thisId,
                        c7_y);
  sf_mex_destroy(&c7_PosDes_UAV1);
}

static void c7_g_emlrt_marshallIn(SFc7_four_quad_formation_040714InstanceStruct *
  chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_y[4])
{
  real_T c7_dv1[4];
  int32_T c7_i29;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv1, 1, 0, 0U, 1, 0U, 1, 4);
  for (c7_i29 = 0; c7_i29 < 4; c7_i29++) {
    c7_y[c7_i29] = c7_dv1[c7_i29];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_PosDes_UAV1;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y[4];
  int32_T c7_i30;
  SFc7_four_quad_formation_040714InstanceStruct *chartInstance;
  chartInstance = (SFc7_four_quad_formation_040714InstanceStruct *)
    chartInstanceVoid;
  c7_PosDes_UAV1 = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_PosDes_UAV1), &c7_thisId,
                        c7_y);
  sf_mex_destroy(&c7_PosDes_UAV1);
  for (c7_i30 = 0; c7_i30 < 4; c7_i30++) {
    (*(real_T (*)[4])c7_outData)[c7_i30] = c7_y[c7_i30];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i31;
  real_T c7_b_inData[8];
  int32_T c7_i32;
  real_T c7_u[8];
  const mxArray *c7_y = NULL;
  SFc7_four_quad_formation_040714InstanceStruct *chartInstance;
  chartInstance = (SFc7_four_quad_formation_040714InstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i31 = 0; c7_i31 < 8; c7_i31++) {
    c7_b_inData[c7_i31] = (*(real_T (*)[8])c7_inData)[c7_i31];
  }

  for (c7_i32 = 0; c7_i32 < 8; c7_i32++) {
    c7_u[c7_i32] = c7_b_inData[c7_i32];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 8), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static uint32_T c7_h_emlrt_marshallIn
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance, const mxArray
   *c7_b_previousTicks, const char_T *c7_identifier)
{
  uint32_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_previousTicks),
    &c7_thisId);
  sf_mex_destroy(&c7_b_previousTicks);
  return c7_y;
}

static uint32_T c7_i_emlrt_marshallIn
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint32_T c7_y;
  uint32_T c7_u1;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u1, 1, 7, 0U, 0, 0U, 0);
  c7_y = c7_u1;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static const mxArray *c7_j_emlrt_marshallIn
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance, const mxArray
   *c7_b_setSimStateSideEffectsInfo, const char_T *c7_identifier)
{
  const mxArray *c7_y = NULL;
  emlrtMsgIdentifier c7_thisId;
  c7_y = NULL;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  sf_mex_assign(&c7_y, c7_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_setSimStateSideEffectsInfo), &c7_thisId), FALSE);
  sf_mex_destroy(&c7_b_setSimStateSideEffectsInfo);
  return c7_y;
}

static const mxArray *c7_k_emlrt_marshallIn
  (SFc7_four_quad_formation_040714InstanceStruct *chartInstance, const mxArray
   *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  const mxArray *c7_y = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_duplicatearraysafe(&c7_u), FALSE);
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static uint8_T c7__u8_u32_(SFc7_four_quad_formation_040714InstanceStruct
  *chartInstance, uint32_T c7_b)
{
  uint8_T c7_a;
  c7_a = (uint8_T)c7_b;
  if (c7_a != c7_b) {
    sf_debug_overflow_detection(SFDB_OVERFLOW);
  }

  return c7_a;
}

static void init_dsm_address_info(SFc7_four_quad_formation_040714InstanceStruct *
  chartInstance)
{
}

/* SFunction Glue Code */
void sf_c7_four_quad_formation_040714_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3528393713U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1611048133U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1003706112U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3142944249U);
}

mxArray *sf_c7_four_quad_formation_040714_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("sH1RP2As8nEmjcOR6YtluD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(8);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c7_four_quad_formation_040714(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[29],T\"HoverThrottle\",},{M[1],M[28],T\"PosDes_UAV1\",},{M[1],M[477],T\"pwm1\",},{M[3],M[186],T\"Increm\",},{M[8],M[0],T\"is_active_c7_four_quad_formation_040714\",},{M[9],M[0],T\"is_c7_four_quad_formation_040714\",},{M[9],M[8],T\"is_Airborne\",},{M[9],M[9],T\"is_Landing\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M1x5[75 684 673 683 669],M[1]}}},{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 10, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_four_quad_formation_040714_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_four_quad_formation_040714InstanceStruct *chartInstance;
    chartInstance = (SFc7_four_quad_formation_040714InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_four_quad_formation_040714MachineNumber_,
           7,
           9,
           11,
           14,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_four_quad_formation_040714MachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_four_quad_formation_040714MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_four_quad_formation_040714MachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"HoverThrottle");
          _SFD_SET_DATA_PROPS(1,2,0,1,"PosDes_UAV1");
          _SFD_SET_DATA_PROPS(2,1,1,0,"RC");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Pos_UAV1");
          _SFD_SET_DATA_PROPS(4,10,0,0,"DeltaT");
          _SFD_SET_DATA_PROPS(5,10,0,0,"H0");
          _SFD_SET_DATA_PROPS(6,10,0,0,"Kl");
          _SFD_SET_DATA_PROPS(7,0,0,0,"Increm");
          _SFD_SET_DATA_PROPS(8,10,0,0,"omega_circle");
          _SFD_SET_DATA_PROPS(9,10,0,0,"PI");
          _SFD_SET_DATA_PROPS(10,10,0,0,"omega_h");
          _SFD_SET_DATA_PROPS(11,10,0,0,"Circle_R");
          _SFD_SET_DATA_PROPS(12,10,0,0,"MAX_Height");
          _SFD_SET_DATA_PROPS(13,2,0,1,"pwm1");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,6);
          _SFD_ST_SUBSTATE_COUNT(0,5);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_INDEX(0,2,3);
          _SFD_ST_SUBSTATE_INDEX(0,3,4);
          _SFD_ST_SUBSTATE_INDEX(0,4,5);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,2);
          _SFD_ST_SUBSTATE_INDEX(6,0,7);
          _SFD_ST_SUBSTATE_INDEX(6,1,8);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,5,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 8, 0 };

          static unsigned int sEndGuardMap[] = { 11, 12 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(6,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 19 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(5,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 8, 0 };

          static unsigned int sEndGuardMap[] = { 11, 12 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(9,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 8, 0 };

          static unsigned int sEndGuardMap[] = { 11, 12 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(7,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 8, 0 };

          static unsigned int sEndGuardMap[] = { 11, 12 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(8,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 9, 0 };

          static unsigned int sEndGuardMap[] = { 12, 13 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(10,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(4,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(4,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(6,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 8, 0 };

          static unsigned int sEndGuardMap[] = { 11, 12 };

          _SFD_TRANS_COV_MAPS(6,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(5,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 19 };

          _SFD_TRANS_COV_MAPS(5,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(1,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(3,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(3,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(9,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 8, 0 };

          static unsigned int sEndGuardMap[] = { 11, 12 };

          _SFD_TRANS_COV_MAPS(9,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(7,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 8, 0 };

          static unsigned int sEndGuardMap[] = { 11, 12 };

          _SFD_TRANS_COV_MAPS(7,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(8,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 8, 0 };

          static unsigned int sEndGuardMap[] = { 11, 12 };

          _SFD_TRANS_COV_MAPS(8,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(10,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 9, 0 };

          static unsigned int sEndGuardMap[] = { 12, 13 };

          _SFD_TRANS_COV_MAPS(10,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)c7_c_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_d_sf_marshallOut,(MexInFcnForType)
            c7_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)c7_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)c7_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)c7_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)c7_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)c7_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)c7_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)c7_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)c7_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)c7_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)c7_c_sf_marshallIn);

        {
          real_T *c7_HoverThrottle;
          real_T *c7_pwm1;
          real_T (*c7_PosDes_UAV1)[4];
          real_T (*c7_RC)[8];
          real_T (*c7_Pos_UAV1)[4];
          c7_pwm1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c7_Pos_UAV1 = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
          c7_RC = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 0);
          c7_PosDes_UAV1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S,
            2);
          c7_HoverThrottle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c7_HoverThrottle);
          _SFD_SET_DATA_VALUE_PTR(1U, *c7_PosDes_UAV1);
          _SFD_SET_DATA_VALUE_PTR(2U, *c7_RC);
          _SFD_SET_DATA_VALUE_PTR(3U, *c7_Pos_UAV1);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c7_DeltaT);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c7_H0);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c7_Kl);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c7_Increm);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c7_omega_circle);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c7_PI);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c7_omega_h);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c7_Circle_R);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c7_MAX_Height);
          _SFD_SET_DATA_VALUE_PTR(13U, c7_pwm1);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_four_quad_formation_040714MachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "AiocXE7zRgTKyCgv29YTqG";
}

static void sf_opaque_initialize_c7_four_quad_formation_040714(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_four_quad_formation_040714InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c7_four_quad_formation_040714
    ((SFc7_four_quad_formation_040714InstanceStruct*) chartInstanceVar);
  initialize_c7_four_quad_formation_040714
    ((SFc7_four_quad_formation_040714InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_four_quad_formation_040714(void
  *chartInstanceVar)
{
  enable_c7_four_quad_formation_040714
    ((SFc7_four_quad_formation_040714InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_four_quad_formation_040714(void
  *chartInstanceVar)
{
  disable_c7_four_quad_formation_040714
    ((SFc7_four_quad_formation_040714InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c7_four_quad_formation_040714(void
  *chartInstanceVar)
{
  sf_c7_four_quad_formation_040714
    ((SFc7_four_quad_formation_040714InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c7_four_quad_formation_040714
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_four_quad_formation_040714
    ((SFc7_four_quad_formation_040714InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_four_quad_formation_040714();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c7_four_quad_formation_040714(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_four_quad_formation_040714();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_four_quad_formation_040714
    ((SFc7_four_quad_formation_040714InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c7_four_quad_formation_040714
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c7_four_quad_formation_040714(S);
}

static void sf_opaque_set_sim_state_c7_four_quad_formation_040714(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c7_four_quad_formation_040714(S, st);
}

static void sf_opaque_terminate_c7_four_quad_formation_040714(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_four_quad_formation_040714InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c7_four_quad_formation_040714
      ((SFc7_four_quad_formation_040714InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_four_quad_formation_040714_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_four_quad_formation_040714
    ((SFc7_four_quad_formation_040714InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_four_quad_formation_040714(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_four_quad_formation_040714
      ((SFc7_four_quad_formation_040714InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_four_quad_formation_040714(SimStruct *S)
{
  /* Actual parameters from chart:
     Circle_R DeltaT H0 Kl MAX_Height PI omega_circle omega_h
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3", "p4", "p5", "p6", "p7",
    "p8" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Circle_R*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for DeltaT*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for H0*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for Kl*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);

  /* registration for MAX_Height*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_DOUBLE);

  /* registration for PI*/
  ssRegDlgParamAsRunTimeParam(S, 5, 5, rtParamNames[5], SS_DOUBLE);

  /* registration for omega_circle*/
  ssRegDlgParamAsRunTimeParam(S, 6, 6, rtParamNames[6], SS_DOUBLE);

  /* registration for omega_h*/
  ssRegDlgParamAsRunTimeParam(S, 7, 7, rtParamNames[7], SS_DOUBLE);
  ssSetNeedAbsoluteTime(S,1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_four_quad_formation_040714_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,7,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,3);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1491246466U));
  ssSetChecksum1(S,(603316234U));
  ssSetChecksum2(S,(431236014U));
  ssSetChecksum3(S,(1268024724U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_four_quad_formation_040714(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c7_four_quad_formation_040714(SimStruct *S)
{
  SFc7_four_quad_formation_040714InstanceStruct *chartInstance;
  chartInstance = (SFc7_four_quad_formation_040714InstanceStruct *)malloc(sizeof
    (SFc7_four_quad_formation_040714InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_four_quad_formation_040714InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_four_quad_formation_040714;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_four_quad_formation_040714;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c7_four_quad_formation_040714;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c7_four_quad_formation_040714;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c7_four_quad_formation_040714;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_four_quad_formation_040714;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_four_quad_formation_040714;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_four_quad_formation_040714;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_four_quad_formation_040714;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_four_quad_formation_040714;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_four_quad_formation_040714;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c7_four_quad_formation_040714_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_four_quad_formation_040714(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_four_quad_formation_040714(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_four_quad_formation_040714(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_four_quad_formation_040714_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

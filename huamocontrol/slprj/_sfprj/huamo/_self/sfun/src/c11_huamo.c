/* Include files */

#include <stddef.h>
#include "blas.h"
#include "huamo_sfun.h"
#include "c11_huamo.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "huamo_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c11_debug_family_names[47] = { "U", "Ixx", "Iyy", "Izz",
  "sp", "L", "m", "pitchd", "rolld", "pitch", "roll", "dotpitch", "dotroll",
  "dotyaw", "signal", "lamd", "kp", "kps", "s", "dotrolld", "dotpitchd",
  "lamdaroll", "kproll", "kpsroll", "deltaroll", "lamdapitch", "kppitch",
  "kpspitch", "deltapitch", "intmax", "eroll", "epitch", "e1", "e3", "x1", "x2",
  "sroll", "spitch", "r2", "r3", "nargin", "nargout", "in", "out", "count",
  "x1_1", "x2_1" };

/* Function Declarations */
static void initialize_c11_huamo(SFc11_huamoInstanceStruct *chartInstance);
static void initialize_params_c11_huamo(SFc11_huamoInstanceStruct *chartInstance);
static void enable_c11_huamo(SFc11_huamoInstanceStruct *chartInstance);
static void disable_c11_huamo(SFc11_huamoInstanceStruct *chartInstance);
static void c11_update_debugger_state_c11_huamo(SFc11_huamoInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c11_huamo(SFc11_huamoInstanceStruct
  *chartInstance);
static void set_sim_state_c11_huamo(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_st);
static void finalize_c11_huamo(SFc11_huamoInstanceStruct *chartInstance);
static void sf_gateway_c11_huamo(SFc11_huamoInstanceStruct *chartInstance);
static void c11_chartstep_c11_huamo(SFc11_huamoInstanceStruct *chartInstance);
static void initSimStructsc11_huamo(SFc11_huamoInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_b_x2_1, const char_T *c11_identifier);
static real_T c11_b_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_c_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_b_x1_1, const char_T *c11_identifier);
static real_T c11_d_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_e_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_b_count, const char_T *c11_identifier);
static real_T c11_f_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_g_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_out, const char_T *c11_identifier, real_T c11_y[2]);
static void c11_h_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[2]);
static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_i_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static void c11_info_helper(const mxArray **c11_info);
static const mxArray *c11_emlrt_marshallOut(const char * c11_u);
static const mxArray *c11_b_emlrt_marshallOut(const uint32_T c11_u);
static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_j_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static uint8_T c11_k_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_b_is_active_c11_huamo, const char_T *c11_identifier);
static uint8_T c11_l_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void init_dsm_address_info(SFc11_huamoInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c11_huamo(SFc11_huamoInstanceStruct *chartInstance)
{
  chartInstance->c11_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_count_not_empty = false;
  chartInstance->c11_x1_1_not_empty = false;
  chartInstance->c11_x2_1_not_empty = false;
  chartInstance->c11_is_active_c11_huamo = 0U;
}

static void initialize_params_c11_huamo(SFc11_huamoInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c11_huamo(SFc11_huamoInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c11_huamo(SFc11_huamoInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c11_update_debugger_state_c11_huamo(SFc11_huamoInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c11_huamo(SFc11_huamoInstanceStruct
  *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  int32_T c11_i0;
  real_T c11_u[2];
  const mxArray *c11_b_y = NULL;
  real_T c11_hoistedGlobal;
  real_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  real_T c11_b_hoistedGlobal;
  real_T c11_c_u;
  const mxArray *c11_d_y = NULL;
  real_T c11_c_hoistedGlobal;
  real_T c11_d_u;
  const mxArray *c11_e_y = NULL;
  uint8_T c11_d_hoistedGlobal;
  uint8_T c11_e_u;
  const mxArray *c11_f_y = NULL;
  real_T (*c11_out)[2];
  c11_out = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellmatrix(5, 1), false);
  for (c11_i0 = 0; c11_i0 < 2; c11_i0++) {
    c11_u[c11_i0] = (*c11_out)[c11_i0];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_hoistedGlobal = chartInstance->c11_count;
  c11_b_u = c11_hoistedGlobal;
  c11_c_y = NULL;
  if (!chartInstance->c11_count_not_empty) {
    sf_mex_assign(&c11_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c11_y, 1, c11_c_y);
  c11_b_hoistedGlobal = chartInstance->c11_x1_1;
  c11_c_u = c11_b_hoistedGlobal;
  c11_d_y = NULL;
  if (!chartInstance->c11_x1_1_not_empty) {
    sf_mex_assign(&c11_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_c_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c11_y, 2, c11_d_y);
  c11_c_hoistedGlobal = chartInstance->c11_x2_1;
  c11_d_u = c11_c_hoistedGlobal;
  c11_e_y = NULL;
  if (!chartInstance->c11_x2_1_not_empty) {
    sf_mex_assign(&c11_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c11_e_y, sf_mex_create("y", &c11_d_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c11_y, 3, c11_e_y);
  c11_d_hoistedGlobal = chartInstance->c11_is_active_c11_huamo;
  c11_e_u = c11_d_hoistedGlobal;
  c11_f_y = NULL;
  sf_mex_assign(&c11_f_y, sf_mex_create("y", &c11_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 4, c11_f_y);
  sf_mex_assign(&c11_st, c11_y, false);
  return c11_st;
}

static void set_sim_state_c11_huamo(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_st)
{
  const mxArray *c11_u;
  real_T c11_dv0[2];
  int32_T c11_i1;
  real_T (*c11_out)[2];
  c11_out = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c11_doneDoubleBufferReInit = true;
  c11_u = sf_mex_dup(c11_st);
  c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 0)),
    "out", c11_dv0);
  for (c11_i1 = 0; c11_i1 < 2; c11_i1++) {
    (*c11_out)[c11_i1] = c11_dv0[c11_i1];
  }

  chartInstance->c11_count = c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 1)), "count");
  chartInstance->c11_x1_1 = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 2)), "x1_1");
  chartInstance->c11_x2_1 = c11_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 3)), "x2_1");
  chartInstance->c11_is_active_c11_huamo = c11_k_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 4)), "is_active_c11_huamo");
  sf_mex_destroy(&c11_u);
  c11_update_debugger_state_c11_huamo(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void finalize_c11_huamo(SFc11_huamoInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c11_huamo(SFc11_huamoInstanceStruct *chartInstance)
{
  int32_T c11_i2;
  int32_T c11_i3;
  real_T (*c11_out)[2];
  real_T (*c11_in)[13];
  c11_out = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_in = (real_T (*)[13])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 10U, chartInstance->c11_sfEvent);
  for (c11_i2 = 0; c11_i2 < 13; c11_i2++) {
    _SFD_DATA_RANGE_CHECK((*c11_in)[c11_i2], 0U);
  }

  chartInstance->c11_sfEvent = CALL_EVENT;
  c11_chartstep_c11_huamo(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_huamoMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c11_i3 = 0; c11_i3 < 2; c11_i3++) {
    _SFD_DATA_RANGE_CHECK((*c11_out)[c11_i3], 1U);
  }
}

static void c11_chartstep_c11_huamo(SFc11_huamoInstanceStruct *chartInstance)
{
  int32_T c11_i4;
  real_T c11_in[13];
  uint32_T c11_debug_family_var_map[47];
  real_T c11_U[2];
  real_T c11_Ixx;
  real_T c11_Iyy;
  real_T c11_Izz;
  real_T c11_sp;
  real_T c11_L;
  real_T c11_m;
  real_T c11_pitchd;
  real_T c11_rolld;
  real_T c11_pitch;
  real_T c11_roll;
  real_T c11_dotpitch;
  real_T c11_dotroll;
  real_T c11_dotyaw;
  real_T c11_signal;
  real_T c11_lamd;
  real_T c11_kp;
  real_T c11_kps;
  real_T c11_s;
  real_T c11_dotrolld;
  real_T c11_dotpitchd;
  real_T c11_lamdaroll;
  real_T c11_kproll;
  real_T c11_kpsroll;
  real_T c11_deltaroll;
  real_T c11_lamdapitch;
  real_T c11_kppitch;
  real_T c11_kpspitch;
  real_T c11_deltapitch;
  real_T c11_intmax;
  real_T c11_eroll;
  real_T c11_epitch;
  real_T c11_e1;
  real_T c11_e3;
  real_T c11_x1;
  real_T c11_x2;
  real_T c11_sroll;
  real_T c11_spitch;
  real_T c11_r2;
  real_T c11_r3;
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  real_T c11_out[2];
  int32_T c11_i5;
  int32_T c11_i6;
  int32_T c11_i7;
  real_T (*c11_b_out)[2];
  real_T (*c11_b_in)[13];
  c11_b_out = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_b_in = (real_T (*)[13])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c11_sfEvent);
  for (c11_i4 = 0; c11_i4 < 13; c11_i4++) {
    c11_in[c11_i4] = (*c11_b_in)[c11_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 47U, 47U, c11_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_U, 0U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_Ixx, 1U, c11_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_Iyy, 2U, c11_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_Izz, 3U, c11_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_sp, 4U, c11_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_L, 5U, c11_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_m, 6U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_pitchd, 7U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_rolld, 8U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_pitch, 9U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_roll, 10U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_dotpitch, 11U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_dotroll, 12U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_dotyaw, 13U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_signal, 14U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_lamd, 15U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_kp, 16U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_kps, 17U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_s, 18U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_dotrolld, 19U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_dotpitchd, 20U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_lamdaroll, 21U, c11_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_kproll, 22U, c11_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_kpsroll, 23U, c11_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_deltaroll, 24U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_lamdapitch, 25U, c11_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_kppitch, 26U, c11_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_kpspitch, 27U, c11_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_deltapitch, 28U, c11_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_intmax, 29U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_eroll, 30U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_epitch, 31U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e1, 32U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e3, 33U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_x1, 34U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_x2, 35U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_sroll, 36U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_spitch, 37U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_r2, 38U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_r3, 39U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 40U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 41U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_in, 42U, c11_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_out, 43U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c11_count, 44U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c11_x1_1, 45U,
    c11_b_sf_marshallOut, c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c11_x2_1, 46U,
    c11_sf_marshallOut, c11_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 28);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 29);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c11_count_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 30);
    chartInstance->c11_count = 0.0;
    chartInstance->c11_count_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 32);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 33);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c11_x1_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 34);
    chartInstance->c11_x1_1 = 0.0;
    chartInstance->c11_x1_1_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 36);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 37);
  if (CV_EML_IF(0, 1, 2, !chartInstance->c11_x2_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 38);
    chartInstance->c11_x2_1 = 0.0;
    chartInstance->c11_x2_1_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 40);
  for (c11_i5 = 0; c11_i5 < 2; c11_i5++) {
    c11_U[c11_i5] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 41);
  c11_Ixx = 0.0095012;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 42);
  c11_Iyy = 0.0095012;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 43);
  c11_Izz = 0.020057;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 45);
  c11_sp = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 47);
  c11_L = 0.232;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 50);
  c11_m = 0.85;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 53);
  c11_pitchd = c11_in[0];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 54);
  c11_rolld = c11_in[1];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 55);
  c11_pitch = c11_in[2];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 56);
  c11_roll = c11_in[3];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 57);
  c11_dotpitch = c11_in[4];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 58);
  c11_dotroll = c11_in[5];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 59);
  c11_dotyaw = c11_in[6];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 60);
  c11_signal = c11_in[7];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 61);
  c11_lamd = c11_in[8];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 62);
  c11_kp = c11_in[9];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 63);
  c11_kps = c11_in[10];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 64);
  c11_s = c11_in[11];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 65);
  if (CV_EML_IF(0, 1, 3, c11_signal > 0.2)) {
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 69);
    c11_dotrolld = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 70);
    c11_dotpitchd = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 73);
    c11_lamdaroll = 6.5;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 74);
    c11_kproll = 17.0;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 75);
    c11_kpsroll = 10.0;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 76);
    c11_deltaroll = 0.05;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 78);
    c11_lamdapitch = 6.5;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 79);
    c11_kppitch = 17.0;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 80);
    c11_kpspitch = 10.0;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 81);
    c11_deltapitch = 0.05;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 83);
    c11_intmax = 5.0;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 84);
    c11_eroll = c11_rolld - c11_roll;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 85);
    c11_epitch = c11_pitchd - c11_pitch;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 86);
    c11_e1 = 34.0 * c11_eroll;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 87);
    c11_e3 = 34.0 * c11_epitch;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 89);
    c11_x1 = chartInstance->c11_x1_1 + c11_eroll * 0.01;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 90);
    c11_x2 = chartInstance->c11_x2_1 + c11_epitch * 0.01;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 97);
    if (CV_EML_IF(0, 1, 4, c11_x1 > c11_intmax)) {
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 98);
      c11_x1 = c11_intmax;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 99);
      if (CV_EML_IF(0, 1, 5, c11_x1 < -c11_intmax)) {
        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 100);
        c11_x1 = -c11_intmax;
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 102);
    if (CV_EML_IF(0, 1, 6, c11_x2 > c11_intmax)) {
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 103);
      c11_x2 = c11_intmax;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 104);
      if (CV_EML_IF(0, 1, 7, c11_x2 < -c11_intmax)) {
        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 105);
        c11_x2 = -c11_intmax;
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 109);
    c11_sroll = (-c11_dotroll + 6.5 * c11_eroll) + 17.0 * c11_x1;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 110);
    c11_spitch = (-c11_dotpitch + 6.5 * c11_epitch) + 17.0 * c11_x2;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 112);
    if (CV_EML_IF(0, 1, 8, c11_sroll <= -c11_deltaroll)) {
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 113);
      c11_r2 = -c11_deltaroll;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 114);
      if (CV_EML_IF(0, 1, 9, c11_sroll >= c11_deltaroll)) {
        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 115);
        c11_r2 = c11_deltaroll;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 117);
        c11_r2 = c11_sroll;
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 120);
    if (CV_EML_IF(0, 1, 10, c11_spitch <= -0.05)) {
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 121);
      c11_r3 = -0.05;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 122);
      if (CV_EML_IF(0, 1, 11, c11_spitch >= c11_deltapitch)) {
        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 123);
        c11_r3 = c11_deltapitch;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 125);
        c11_r3 = c11_spitch;
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 130U);
    c11_U[1] = 0.040953448275862066 * ((c11_e1 - 6.5 * c11_dotroll) -
      -1.1109965057045426 * c11_dotpitch * c11_dotyaw) + 0.095012 * c11_r2;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 131U);
    c11_U[0] = 0.040953448275862066 * ((c11_e3 - 6.5 * c11_dotpitch) -
      1.1109965057045426 * c11_dotroll * c11_dotyaw) + 0.095012 * c11_r3;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 133U);
    chartInstance->c11_x1_1 = c11_x1;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 134U);
    chartInstance->c11_x2_1 = c11_x2;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 136U);
    chartInstance->c11_x1_1 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 137U);
    chartInstance->c11_x2_1 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 138U);
    c11_U[0] = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 139U);
    c11_U[1] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 142U);
  for (c11_i6 = 0; c11_i6 < 2; c11_i6++) {
    c11_out[c11_i6] = c11_U[c11_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -142);
  _SFD_SYMBOL_SCOPE_POP();
  for (c11_i7 = 0; c11_i7 < 2; c11_i7++) {
    (*c11_b_out)[c11_i7] = c11_out[c11_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c11_sfEvent);
}

static void initSimStructsc11_huamo(SFc11_huamoInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber)
{
  (void)c11_machineNumber;
  (void)c11_chartNumber;
  (void)c11_instanceNumber;
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_huamoInstanceStruct *chartInstance;
  chartInstance = (SFc11_huamoInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  if (!chartInstance->c11_x2_1_not_empty) {
    sf_mex_assign(&c11_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static real_T c11_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_b_x2_1, const char_T *c11_identifier)
{
  real_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_x2_1),
    &c11_thisId);
  sf_mex_destroy(&c11_b_x2_1);
  return c11_y;
}

static real_T c11_b_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d0;
  if (mxIsEmpty(c11_u)) {
    chartInstance->c11_x2_1_not_empty = false;
  } else {
    chartInstance->c11_x2_1_not_empty = true;
    sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d0, 1, 0, 0U, 0, 0U, 0);
    c11_y = c11_d0;
  }

  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_x2_1;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_huamoInstanceStruct *chartInstance;
  chartInstance = (SFc11_huamoInstanceStruct *)chartInstanceVoid;
  c11_b_x2_1 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_x2_1),
    &c11_thisId);
  sf_mex_destroy(&c11_b_x2_1);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_huamoInstanceStruct *chartInstance;
  chartInstance = (SFc11_huamoInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  if (!chartInstance->c11_x1_1_not_empty) {
    sf_mex_assign(&c11_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static real_T c11_c_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_b_x1_1, const char_T *c11_identifier)
{
  real_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_x1_1),
    &c11_thisId);
  sf_mex_destroy(&c11_b_x1_1);
  return c11_y;
}

static real_T c11_d_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d1;
  if (mxIsEmpty(c11_u)) {
    chartInstance->c11_x1_1_not_empty = false;
  } else {
    chartInstance->c11_x1_1_not_empty = true;
    sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d1, 1, 0, 0U, 0, 0U, 0);
    c11_y = c11_d1;
  }

  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_x1_1;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_huamoInstanceStruct *chartInstance;
  chartInstance = (SFc11_huamoInstanceStruct *)chartInstanceVoid;
  c11_b_x1_1 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_x1_1),
    &c11_thisId);
  sf_mex_destroy(&c11_b_x1_1);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_huamoInstanceStruct *chartInstance;
  chartInstance = (SFc11_huamoInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  if (!chartInstance->c11_count_not_empty) {
    sf_mex_assign(&c11_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static real_T c11_e_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_b_count, const char_T *c11_identifier)
{
  real_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_count),
    &c11_thisId);
  sf_mex_destroy(&c11_b_count);
  return c11_y;
}

static real_T c11_f_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d2;
  if (mxIsEmpty(c11_u)) {
    chartInstance->c11_count_not_empty = false;
  } else {
    chartInstance->c11_count_not_empty = true;
    sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d2, 1, 0, 0U, 0, 0U, 0);
    c11_y = c11_d2;
  }

  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_count;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_huamoInstanceStruct *chartInstance;
  chartInstance = (SFc11_huamoInstanceStruct *)chartInstanceVoid;
  c11_b_count = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_count),
    &c11_thisId);
  sf_mex_destroy(&c11_b_count);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i8;
  real_T c11_b_inData[2];
  int32_T c11_i9;
  real_T c11_u[2];
  const mxArray *c11_y = NULL;
  SFc11_huamoInstanceStruct *chartInstance;
  chartInstance = (SFc11_huamoInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i8 = 0; c11_i8 < 2; c11_i8++) {
    c11_b_inData[c11_i8] = (*(real_T (*)[2])c11_inData)[c11_i8];
  }

  for (c11_i9 = 0; c11_i9 < 2; c11_i9++) {
    c11_u[c11_i9] = c11_b_inData[c11_i9];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_g_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_out, const char_T *c11_identifier, real_T c11_y[2])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_out), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_out);
}

static void c11_h_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[2])
{
  real_T c11_dv1[2];
  int32_T c11_i10;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c11_i10 = 0; c11_i10 < 2; c11_i10++) {
    c11_y[c11_i10] = c11_dv1[c11_i10];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_out;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[2];
  int32_T c11_i11;
  SFc11_huamoInstanceStruct *chartInstance;
  chartInstance = (SFc11_huamoInstanceStruct *)chartInstanceVoid;
  c11_out = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_out), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_out);
  for (c11_i11 = 0; c11_i11 < 2; c11_i11++) {
    (*(real_T (*)[2])c11_outData)[c11_i11] = c11_y[c11_i11];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i12;
  real_T c11_b_inData[13];
  int32_T c11_i13;
  real_T c11_u[13];
  const mxArray *c11_y = NULL;
  SFc11_huamoInstanceStruct *chartInstance;
  chartInstance = (SFc11_huamoInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i12 = 0; c11_i12 < 13; c11_i12++) {
    c11_b_inData[c11_i12] = (*(real_T (*)[13])c11_inData)[c11_i12];
  }

  for (c11_i13 = 0; c11_i13 < 13; c11_i13++) {
    c11_u[c11_i13] = c11_b_inData[c11_i13];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 13), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_huamoInstanceStruct *chartInstance;
  chartInstance = (SFc11_huamoInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static real_T c11_i_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d3;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d3, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d3;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_nargout;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_huamoInstanceStruct *chartInstance;
  chartInstance = (SFc11_huamoInstanceStruct *)chartInstanceVoid;
  c11_nargout = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_nargout),
    &c11_thisId);
  sf_mex_destroy(&c11_nargout);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray *sf_c11_huamo_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c11_info_helper(&c11_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c11_nameCaptureInfo);
  return c11_nameCaptureInfo;
}

static void c11_info_helper(const mxArray **c11_info)
{
  const mxArray *c11_rhs0 = NULL;
  const mxArray *c11_lhs0 = NULL;
  const mxArray *c11_rhs1 = NULL;
  const mxArray *c11_lhs1 = NULL;
  const mxArray *c11_rhs2 = NULL;
  const mxArray *c11_lhs2 = NULL;
  const mxArray *c11_rhs3 = NULL;
  const mxArray *c11_lhs3 = NULL;
  const mxArray *c11_rhs4 = NULL;
  const mxArray *c11_lhs4 = NULL;
  const mxArray *c11_rhs5 = NULL;
  const mxArray *c11_lhs5 = NULL;
  const mxArray *c11_rhs6 = NULL;
  const mxArray *c11_lhs6 = NULL;
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1388463696U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1370017086U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c11_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c11_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363717480U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c11_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c11_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286825996U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c11_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c11_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c11_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs6), "lhs", "lhs",
                  6);
  sf_mex_destroy(&c11_rhs0);
  sf_mex_destroy(&c11_lhs0);
  sf_mex_destroy(&c11_rhs1);
  sf_mex_destroy(&c11_lhs1);
  sf_mex_destroy(&c11_rhs2);
  sf_mex_destroy(&c11_lhs2);
  sf_mex_destroy(&c11_rhs3);
  sf_mex_destroy(&c11_lhs3);
  sf_mex_destroy(&c11_rhs4);
  sf_mex_destroy(&c11_lhs4);
  sf_mex_destroy(&c11_rhs5);
  sf_mex_destroy(&c11_lhs5);
  sf_mex_destroy(&c11_rhs6);
  sf_mex_destroy(&c11_lhs6);
}

static const mxArray *c11_emlrt_marshallOut(const char * c11_u)
{
  const mxArray *c11_y = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c11_u)), false);
  return c11_y;
}

static const mxArray *c11_b_emlrt_marshallOut(const uint32_T c11_u)
{
  const mxArray *c11_y = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 7, 0U, 0U, 0U, 0), false);
  return c11_y;
}

static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_huamoInstanceStruct *chartInstance;
  chartInstance = (SFc11_huamoInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int32_T c11_j_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i14;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i14, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i14;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_huamoInstanceStruct *chartInstance;
  chartInstance = (SFc11_huamoInstanceStruct *)chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static uint8_T c11_k_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_b_is_active_c11_huamo, const char_T *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_is_active_c11_huamo), &c11_thisId);
  sf_mex_destroy(&c11_b_is_active_c11_huamo);
  return c11_y;
}

static uint8_T c11_l_emlrt_marshallIn(SFc11_huamoInstanceStruct *chartInstance,
  const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void init_dsm_address_info(SFc11_huamoInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c11_huamo_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1882212074U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1187545551U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(733327245U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2002547731U);
}

mxArray *sf_c11_huamo_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("8rdrVox8Ia425SDWZjaad");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(13);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c11_huamo_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c11_huamo_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c11_huamo(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"out\",},{M[4],M[0],T\"count\",S'l','i','p'{{M1x2[1423 1428],M[0],}}},{M[4],M[0],T\"x1_1\",S'l','i','p'{{M1x2[1482 1486],M[0],}}},{M[4],M[0],T\"x2_1\",S'l','i','p'{{M1x2[1538 1542],M[0],}}},{M[8],M[0],T\"is_active_c11_huamo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_huamo_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_huamoInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc11_huamoInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _huamoMachineNumber_,
           11,
           1,
           1,
           0,
           2,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_huamoMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_huamoMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _huamoMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"in");
          _SFD_SET_DATA_PROPS(1,2,0,1,"out");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,12,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",1350,-1,3686);
        _SFD_CV_INIT_EML_IF(0,1,0,1432,1449,-1,1470);
        _SFD_CV_INIT_EML_IF(0,1,1,1490,1506,-1,1526);
        _SFD_CV_INIT_EML_IF(0,1,2,1545,1561,-1,1580);
        _SFD_CV_INIT_EML_IF(0,1,3,2166,2179,3610,3666);
        _SFD_CV_INIT_EML_IF(0,1,4,2801,2813,2829,2846);
        _SFD_CV_INIT_EML_IF(0,1,5,2829,2846,-1,2846);
        _SFD_CV_INIT_EML_IF(0,1,6,2867,2879,2895,2912);
        _SFD_CV_INIT_EML_IF(0,1,7,2895,2912,-1,2912);
        _SFD_CV_INIT_EML_IF(0,1,8,3104,3124,3149,3224);
        _SFD_CV_INIT_EML_IF(0,1,9,3149,3174,3198,3224);
        _SFD_CV_INIT_EML_IF(0,1,10,3256,3281,3304,3374);
        _SFD_CV_INIT_EML_IF(0,1,11,3304,3331,3351,3374);

        {
          unsigned int dimVector[1];
          dimVector[0]= 13;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_d_sf_marshallOut,(MexInFcnForType)
            c11_d_sf_marshallIn);
        }

        {
          real_T (*c11_in)[13];
          real_T (*c11_out)[2];
          c11_out = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
          c11_in = (real_T (*)[13])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c11_in);
          _SFD_SET_DATA_VALUE_PTR(1U, *c11_out);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _huamoMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "bO8yQndtcSgYudlpvj7S1";
}

static void sf_opaque_initialize_c11_huamo(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_huamoInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c11_huamo((SFc11_huamoInstanceStruct*) chartInstanceVar);
  initialize_c11_huamo((SFc11_huamoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c11_huamo(void *chartInstanceVar)
{
  enable_c11_huamo((SFc11_huamoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c11_huamo(void *chartInstanceVar)
{
  disable_c11_huamo((SFc11_huamoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c11_huamo(void *chartInstanceVar)
{
  sf_gateway_c11_huamo((SFc11_huamoInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c11_huamo(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_huamo((SFc11_huamoInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_huamo();/* state var info */
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

extern void sf_internal_set_sim_state_c11_huamo(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c11_huamo();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_huamo((SFc11_huamoInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c11_huamo(SimStruct* S)
{
  return sf_internal_get_sim_state_c11_huamo(S);
}

static void sf_opaque_set_sim_state_c11_huamo(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c11_huamo(S, st);
}

static void sf_opaque_terminate_c11_huamo(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_huamoInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_huamo_optimization_info();
    }

    finalize_c11_huamo((SFc11_huamoInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc11_huamo((SFc11_huamoInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_huamo(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c11_huamo((SFc11_huamoInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_huamo(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_huamo_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,11,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,11);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1832315996U));
  ssSetChecksum1(S,(3608787446U));
  ssSetChecksum2(S,(822937429U));
  ssSetChecksum3(S,(1819285293U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_huamo(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c11_huamo(SimStruct *S)
{
  SFc11_huamoInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc11_huamoInstanceStruct *)utMalloc(sizeof
    (SFc11_huamoInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_huamoInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c11_huamo;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c11_huamo;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c11_huamo;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c11_huamo;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c11_huamo;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c11_huamo;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c11_huamo;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c11_huamo;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_huamo;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_huamo;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c11_huamo;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c11_huamo_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_huamo(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_huamo(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_huamo(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_huamo_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

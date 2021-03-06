/*
 * File: Guidance_System.h
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model download.
 *
 * Model version                        : 1.105
 * Real-Time Workshop file version      : 8.6 (R2014a) 27-Dec-2013
 * Real-Time Workshop file generated on : Mon Jun 27 17:19:18 2016
 * TLC version                          : 8.6 (Jan 30 2014)
 * C/C++ source code generated on       : Mon Jun 27 17:19:19 2016
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Guidance_System_h_
#define RTW_HEADER_Guidance_System_h_
#ifndef download_COMMON_INCLUDES_
# define download_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "waijung_hwdrvlib.h"
#endif                                 /* download_COMMON_INCLUDES_ */

#include "download_types.h"

/* Block signals for system '<Root>/Guidance_System' */
typedef struct {
  real32_T Saturation;                 /* '<S52>/Saturation' */
  real32_T Saturation_d;               /* '<S53>/Saturation' */
  real32_T Saturation_a;               /* '<S54>/Saturation' */
  real32_T Saturation_b;               /* '<S55>/Saturation' */
} B_Guidance_System_download_T;

/* Parameters for system: '<Root>/Guidance_System' */
struct P_Guidance_System_download_T_ {
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S52>/Constant'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S52>/Gain'
                                        */
  real32_T Saturation_UpperSat;        /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S52>/Saturation'
                                        */
  real32_T Saturation_LowerSat;        /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S52>/Saturation'
                                        */
  real32_T Constant_Value_o;           /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S53>/Constant'
                                        */
  real32_T Gain_Gain_d;                /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S53>/Gain'
                                        */
  real32_T Saturation_UpperSat_e;      /* Computed Parameter: Saturation_UpperSat_e
                                        * Referenced by: '<S53>/Saturation'
                                        */
  real32_T Saturation_LowerSat_n;      /* Computed Parameter: Saturation_LowerSat_n
                                        * Referenced by: '<S53>/Saturation'
                                        */
  real32_T Constant_Value_c;           /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S54>/Constant'
                                        */
  real32_T Gain_Gain_h;                /* Computed Parameter: Gain_Gain_h
                                        * Referenced by: '<S54>/Gain'
                                        */
  real32_T Saturation_UpperSat_d;      /* Computed Parameter: Saturation_UpperSat_d
                                        * Referenced by: '<S54>/Saturation'
                                        */
  real32_T Saturation_LowerSat_p;      /* Computed Parameter: Saturation_LowerSat_p
                                        * Referenced by: '<S54>/Saturation'
                                        */
  real32_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S55>/Constant'
                                        */
  real32_T Gain_Gain_n;                /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S55>/Gain'
                                        */
  real32_T Saturation_UpperSat_l;      /* Computed Parameter: Saturation_UpperSat_l
                                        * Referenced by: '<S55>/Saturation'
                                        */
  real32_T Saturation_LowerSat_k;      /* Computed Parameter: Saturation_LowerSat_k
                                        * Referenced by: '<S55>/Saturation'
                                        */
};

extern void download_Guidance_System(real32_T rtu_Receiver, real32_T
  rtu_Receiver_e, real32_T rtu_Receiver_p, real32_T rtu_Receiver_b,
  B_Guidance_System_download_T *localB, P_Guidance_System_download_T *localP);

#endif                                 /* RTW_HEADER_Guidance_System_h_ */

/* [EOF] */

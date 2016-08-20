/*
 * File: Guidance_System.c
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

#include "Guidance_System.h"

/* Include model header file for global data */
#include "download.h"
#include "download_private.h"

/* Output and update for atomic system: '<Root>/Guidance_System' */
void download_Guidance_System(real32_T rtu_Receiver, real32_T rtu_Receiver_e,
  real32_T rtu_Receiver_p, real32_T rtu_Receiver_b, B_Guidance_System_download_T
  *localB, P_Guidance_System_download_T *localP)
{
  real32_T u0;

  /* Gain: '<S52>/Gain' incorporates:
   *  Constant: '<S52>/Constant'
   *  Sum: '<S52>/Add'
   */
  u0 = (rtu_Receiver - localP->Constant_Value) * localP->Gain_Gain;

  /* Saturate: '<S52>/Saturation' */
  if (u0 > localP->Saturation_UpperSat) {
    localB->Saturation = localP->Saturation_UpperSat;
  } else if (u0 < localP->Saturation_LowerSat) {
    localB->Saturation = localP->Saturation_LowerSat;
  } else {
    localB->Saturation = u0;
  }

  /* End of Saturate: '<S52>/Saturation' */

  /* Gain: '<S53>/Gain' incorporates:
   *  Constant: '<S53>/Constant'
   *  Sum: '<S53>/Add'
   */
  u0 = (rtu_Receiver_e - localP->Constant_Value_o) * localP->Gain_Gain_d;

  /* Saturate: '<S53>/Saturation' */
  if (u0 > localP->Saturation_UpperSat_e) {
    localB->Saturation_d = localP->Saturation_UpperSat_e;
  } else if (u0 < localP->Saturation_LowerSat_n) {
    localB->Saturation_d = localP->Saturation_LowerSat_n;
  } else {
    localB->Saturation_d = u0;
  }

  /* End of Saturate: '<S53>/Saturation' */

  /* Gain: '<S54>/Gain' incorporates:
   *  Constant: '<S54>/Constant'
   *  Sum: '<S54>/Add'
   */
  u0 = (rtu_Receiver_p - localP->Constant_Value_c) * localP->Gain_Gain_h;

  /* Saturate: '<S54>/Saturation' */
  if (u0 > localP->Saturation_UpperSat_d) {
    localB->Saturation_a = localP->Saturation_UpperSat_d;
  } else if (u0 < localP->Saturation_LowerSat_p) {
    localB->Saturation_a = localP->Saturation_LowerSat_p;
  } else {
    localB->Saturation_a = u0;
  }

  /* End of Saturate: '<S54>/Saturation' */

  /* Gain: '<S55>/Gain' incorporates:
   *  Constant: '<S55>/Constant'
   *  Sum: '<S55>/Add'
   */
  u0 = (rtu_Receiver_b - localP->Constant_Value_a) * localP->Gain_Gain_n;

  /* Saturate: '<S55>/Saturation' */
  if (u0 > localP->Saturation_UpperSat_l) {
    localB->Saturation_b = localP->Saturation_UpperSat_l;
  } else if (u0 < localP->Saturation_LowerSat_k) {
    localB->Saturation_b = localP->Saturation_LowerSat_k;
  } else {
    localB->Saturation_b = u0;
  }

  /* End of Saturate: '<S55>/Saturation' */
}

/* [EOF] */

/*
 * File: download.c
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model download.
 *
 * Model version                        : 1.77
 * Real-Time Workshop file version      : 8.6 (R2014a) 27-Dec-2013
 * Real-Time Workshop file generated on : Mon Jun 06 17:44:10 2016
 * TLC version                          : 8.6 (Jan 30 2014)
 * C/C++ source code generated on       : Mon Jun 06 17:44:13 2016
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "download.h"
#include "download_private.h"

/* Block signals (auto storage) */
B_download_T download_B;

/* Block states (auto storage) */
DW_download_T download_DW;

/* Real-time model */
RT_MODEL_download_T download_M_;
RT_MODEL_download_T *const download_M = &download_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (download_M->Timing.TaskCounters.TID[1])++;
  if ((download_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.005s, 0.0s] */
    download_M->Timing.TaskCounters.TID[1] = 0;
  }

  (download_M->Timing.TaskCounters.TID[2])++;
  if ((download_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.01s, 0.0s] */
    download_M->Timing.TaskCounters.TID[2] = 0;
  }

  (download_M->Timing.TaskCounters.TID[3])++;
  if ((download_M->Timing.TaskCounters.TID[3]) > 399) {/* Sample time: [0.4s, 0.0s] */
    download_M->Timing.TaskCounters.TID[3] = 0;
  }

  (download_M->Timing.TaskCounters.TID[4])++;
  if ((download_M->Timing.TaskCounters.TID[4]) > 499) {/* Sample time: [0.5s, 0.0s] */
    download_M->Timing.TaskCounters.TID[4] = 0;
  }

  (download_M->Timing.TaskCounters.TID[5])++;
  if ((download_M->Timing.TaskCounters.TID[5]) > 999) {/* Sample time: [1.0s, 0.0s] */
    download_M->Timing.TaskCounters.TID[5] = 0;
  }
}

/* Start for enable system: '<S2>/Angle_hold' */
void download_Angle_hold_Start(DW_Angle_hold_download_T *localDW,
  P_Angle_hold_download_T *localP)
{
  /* InitializeConditions for IfAction SubSystem: '<S20>/Subsystem' */
  /* InitializeConditions for UnitDelay: '<S32>/UD' */
  localDW->UD_DSTATE[0] = localP->DiscreteDerivative_ICPrevScaled;
  localDW->UD_DSTATE[1] = localP->DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_DSTATE[0] =
    localP->DiscreteTimeIntegrator1_IC;
  localDW->DiscreteTimeIntegrator1_DSTATE[1] =
    localP->DiscreteTimeIntegrator1_IC;
  localDW->DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for UnitDelay: '<S34>/UD' */
  localDW->UD_DSTATE_b = localP->DiscreteDerivative_ICPrevScal_b;

  /* InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_DSTAT_b =
    localP->DiscreteTimeIntegrator1_IC_m;
  localDW->DiscreteTimeIntegrator1_PrevR_j = 0;

  /* InitializeConditions for MATLAB Function: '<S31>/MATLAB Function' */
  localDW->count = 0.0;

  /* End of InitializeConditions for SubSystem: '<S20>/Subsystem' */
}

/* Outputs for enable system: '<S2>/Angle_hold' */
void download_Angle_hold(real_T rtu_Enable, real32_T rtu_Guidance_in, real32_T
  rtu_Guidance_in_i, real32_T rtu_Guidance_in_l, real32_T rtu_Signal_back,
  real32_T rtu_Signal_back_o, real32_T rtu_Signal_back_l, real32_T
  rtu_Signal_back_ob, real32_T rtu_Signal_back_p, real32_T rtu_Signal_back_c,
  real32_T rtu_Guidance_in_f, const real32_T rtu_alt_back[2],
  B_Angle_hold_download_T *localB, DW_Angle_hold_download_T *localDW,
  P_Angle_hold_download_T *localP)
{
  real_T a;
  static const real_T a_0[16] = { 0.25, 0.25, 0.25, 0.25, 0.0, -0.5, 0.0, 0.5,
    -0.5, 0.0, 0.5, 0.0, 0.25, -0.25, 0.25, -0.25 };

  static const real_T a_1[16] = { 28461.485917256767, 28461.485917256763,
    28461.485917256767, 28461.485917256763, 0.0, -56922.971834513533,
    6.3197193960766211E-12, 56922.971834513526, -56922.971834513533, 0.0,
    56922.971834513533, 0.0, 333333.33333333331, -333333.33333333331,
    333333.33333333331, -333333.33333333331 };

  int32_T rtb_y_o;
  int32_T rtb_y_c;
  real_T rtb_DataTypeConversion_c[4];
  real_T Sum1_c;
  real_T TSamp_e;
  real_T a_2[4];
  int32_T i;
  real32_T rtb_Gain5_l_idx_0;
  real32_T rtb_Gain5_l_idx_1;
  real32_T rtb_Sum_lz_idx_0;
  real32_T rtb_Sum_lz_idx_1;
  real_T Sum1_idx_0;
  real_T Sum1_idx_1;
  real_T U_idx_1;
  real_T TSamp_idx_0;
  real_T TSamp_idx_1;
  real32_T u0;

  /* Outputs for Enabled SubSystem: '<S2>/Angle_hold' incorporates:
   *  EnablePort: '<S20>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* If: '<S20>/If' incorporates:
     *  DataTypeConversion: '<S31>/Data Type Conversion1'
     *  MATLAB Function: '<S25>/MATLAB Function1'
     *  MATLAB Function: '<S31>/MATLAB Function'
     */
    if (rtu_Guidance_in > 0.2F) {
      /* Outputs for IfAction SubSystem: '<S20>/Subsystem' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      /* Gain: '<S25>/Gain5' */
      rtb_Gain5_l_idx_0 = localP->Gain5_Gain * rtu_Signal_back;
      rtb_Gain5_l_idx_1 = localP->Gain5_Gain * rtu_Signal_back_o;

      /* Sum: '<S26>/Sum' incorporates:
       *  Constant: '<S26>/Constant'
       *  Gain: '<S25>/Gain2'
       *  Gain: '<S25>/Gain3'
       *  Product: '<S26>/Product3'
       */
      rtb_Sum_lz_idx_0 = localP->Gain3_Gain * rtu_Guidance_in_i -
        rtb_Gain5_l_idx_1 * localP->Constant_Value_c;
      rtb_Sum_lz_idx_1 = localP->Gain2_Gain * rtu_Guidance_in_l -
        rtb_Gain5_l_idx_0 * localP->Constant_Value_c;

      /* Sum: '<S26>/Sum1' incorporates:
       *  Constant: '<S26>/P'
       *  Gain: '<S25>/Gain6'
       *  Product: '<S26>/Product1'
       */
      Sum1_idx_0 = (real_T)(rtb_Sum_lz_idx_0 * localP->P_Value) -
        localP->Gain6_Gain * rtu_Signal_back_p;
      Sum1_idx_1 = (real_T)(rtb_Sum_lz_idx_1 * localP->P_Value) -
        localP->Gain6_Gain * rtu_Signal_back_ob;

      /* SampleTimeMath: '<S32>/TSamp'
       *
       * About '<S32>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      TSamp_idx_0 = Sum1_idx_0 * localP->TSamp_WtEt;
      TSamp_idx_1 = Sum1_idx_1 * localP->TSamp_WtEt;

      /* MATLAB Function: '<S26>/MATLAB Function' */
      /* MATLAB Function 'Controller/Angle_hold/Subsystem/Controller_roll/MATLAB Function': '<S33>:1' */
      /* '<S33>:1:3' */
      rtb_y_o = 1;

      /* '<S33>:1:4' */
      /* '<S33>:1:5' */
      if ((rtu_Guidance_in > 0.3) && ((real32_T)fabs(rtb_Sum_lz_idx_0) < 0.18) &&
          ((real32_T)fabs(rtb_Sum_lz_idx_1) < 0.18)) {
        /* '<S33>:1:6' */
        /* if thrust>20%,enable integrator */
        /* '<S33>:1:7' */
        rtb_y_o = 0;
      }

      /* End of MATLAB Function: '<S26>/MATLAB Function' */

      /* DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' incorporates:
       *  DataTypeConversion: '<S26>/Data Type Conversion1'
       */
      if ((rtb_y_o != 0) || (localDW->DiscreteTimeIntegrator1_PrevRes != 0)) {
        localDW->DiscreteTimeIntegrator1_DSTATE[0] =
          localP->DiscreteTimeIntegrator1_IC;
        localDW->DiscreteTimeIntegrator1_DSTATE[1] =
          localP->DiscreteTimeIntegrator1_IC;
      }

      if (localDW->DiscreteTimeIntegrator1_DSTATE[0] >=
          localP->DiscreteTimeIntegrator1_UpperSa) {
        localDW->DiscreteTimeIntegrator1_DSTATE[0] =
          localP->DiscreteTimeIntegrator1_UpperSa;
      } else {
        if (localDW->DiscreteTimeIntegrator1_DSTATE[0] <=
            localP->DiscreteTimeIntegrator1_LowerSa) {
          localDW->DiscreteTimeIntegrator1_DSTATE[0] =
            localP->DiscreteTimeIntegrator1_LowerSa;
        }
      }

      if (localDW->DiscreteTimeIntegrator1_DSTATE[1] >=
          localP->DiscreteTimeIntegrator1_UpperSa) {
        localDW->DiscreteTimeIntegrator1_DSTATE[1] =
          localP->DiscreteTimeIntegrator1_UpperSa;
      } else {
        if (localDW->DiscreteTimeIntegrator1_DSTATE[1] <=
            localP->DiscreteTimeIntegrator1_LowerSa) {
          localDW->DiscreteTimeIntegrator1_DSTATE[1] =
            localP->DiscreteTimeIntegrator1_LowerSa;
        }
      }

      /* Product: '<S26>/Product6' incorporates:
       *  Constant: '<S26>/nI'
       *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator1'
       */
      localB->Product6[0] = localDW->DiscreteTimeIntegrator1_DSTATE[0] *
        localP->nI_Value;
      localB->Product6[1] = localDW->DiscreteTimeIntegrator1_DSTATE[1] *
        localP->nI_Value;

      /* Sum: '<S26>/Sum2' incorporates:
       *  Constant: '<S26>/nD'
       *  Constant: '<S26>/nP'
       *  Product: '<S26>/Product4'
       *  Product: '<S26>/Product5'
       *  Sum: '<S32>/Diff'
       *  UnitDelay: '<S32>/UD'
       */
      localB->Sum2[0] = ((TSamp_idx_0 - localDW->UD_DSTATE[0]) *
                         localP->nD_Value + localP->nP_Value * Sum1_idx_0) +
        localB->Product6[0];
      localB->Sum2[1] = ((TSamp_idx_1 - localDW->UD_DSTATE[1]) *
                         localP->nD_Value + localP->nP_Value * Sum1_idx_1) +
        localB->Product6[1];

      /* MATLAB Function: '<S27>/MATLAB Function' */
      /* MATLAB Function 'Controller/Angle_hold/Subsystem/Controller_yaw/MATLAB Function': '<S35>:1' */
      /* '<S35>:1:3' */
      rtb_y_c = 1;
      if (rtu_Guidance_in > 0.3) {
        /* '<S35>:1:4' */
        /* if thrust>20%,enable integrator */
        /* '<S35>:1:5' */
        rtb_y_c = 0;
      } else {
        if (0.0 < 5.0) {
          /* '<S35>:1:6' */
          /* if delta angle<5,enable integrator */
          /* '<S35>:1:7' */
          rtb_y_c = 0;
        }
      }

      /* End of MATLAB Function: '<S27>/MATLAB Function' */

      /* Sum: '<S27>/Sum1' incorporates:
       *  Constant: '<S27>/P'
       *  Constant: '<S27>/status'
       *  Gain: '<S25>/Gain4'
       *  Gain: '<S25>/Gain5'
       *  Gain: '<S25>/Gain6'
       *  Product: '<S27>/Product1'
       *  Product: '<S27>/Product3'
       *  Sum: '<S27>/Sum'
       */
      Sum1_c = (real_T)((localP->Gain4_Gain * rtu_Guidance_in_f -
                         localP->Gain5_Gain * rtu_Signal_back_l *
                         localP->status_Value) * localP->P_Value_n) -
        localP->Gain6_Gain * rtu_Signal_back_c;

      /* SampleTimeMath: '<S34>/TSamp'
       *
       * About '<S34>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      TSamp_e = Sum1_c * localP->TSamp_WtEt_b;

      /* DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' incorporates:
       *  DataTypeConversion: '<S27>/Data Type Conversion'
       */
      if ((rtb_y_c != 0) || (localDW->DiscreteTimeIntegrator1_PrevR_j != 0)) {
        localDW->DiscreteTimeIntegrator1_DSTAT_b =
          localP->DiscreteTimeIntegrator1_IC_m;
      }

      if (localDW->DiscreteTimeIntegrator1_DSTAT_b >=
          localP->DiscreteTimeIntegrator1_Upper_f) {
        localDW->DiscreteTimeIntegrator1_DSTAT_b =
          localP->DiscreteTimeIntegrator1_Upper_f;
      } else {
        if (localDW->DiscreteTimeIntegrator1_DSTAT_b <=
            localP->DiscreteTimeIntegrator1_Lower_k) {
          localDW->DiscreteTimeIntegrator1_DSTAT_b =
            localP->DiscreteTimeIntegrator1_Lower_k;
        }
      }

      /* MATLAB Function: '<S31>/MATLAB Function' incorporates:
       *  DataTypeConversion: '<S31>/Data Type Conversion2'
       *  DataTypeConversion: '<S31>/Data Type Conversion3'
       */
      /* MATLAB Function 'Controller/Angle_hold/Subsystem/alt_control/MATLAB Function': '<S36>:1' */
      if ((rtu_Guidance_in > 0.35) && (rtu_Guidance_in < 0.45) &&
          (localDW->count == 0.0)) {
        /* '<S36>:1:10' */
        /* '<S36>:1:11' */
        a = rtu_alt_back[0];

        /* '<S36>:1:12' */
        localDW->count = 1.0;
      } else if ((rtu_Guidance_in <= 0.35) && (localDW->count == 1.0)) {
        /* '<S36>:1:13' */
        /* '<S36>:1:14' */
        localDW->count = 0.0;

        /* '<S36>:1:15' */
        a = 0.0;
      } else if ((rtu_Guidance_in >= 0.45) && (localDW->count == 1.0)) {
        /* '<S36>:1:16' */
        /* '<S36>:1:17' */
        localDW->count = 0.0;

        /* '<S36>:1:18' */
        a = 0.0;
      } else {
        /* '<S36>:1:20' */
        localDW->count = 0.0;

        /* '<S36>:1:21' */
        a = 0.0;
      }

      /* Outputs for Enabled SubSystem: '<S31>/Subsystem' incorporates:
       *  EnablePort: '<S37>/Enable'
       */
      /* '<S36>:1:23' */
      /* '<S36>:1:24' */
      if ((real32_T)localDW->count > 0.0F) {
        /* Product: '<S37>/Product2' incorporates:
         *  Constant: '<S31>/Constant2'
         */
        u0 = rtu_alt_back[1] * localP->Constant2_Value;

        /* Saturate: '<S37>/Saturation1' */
        if (u0 > localP->Saturation1_UpperSat_c) {
          u0 = localP->Saturation1_UpperSat_c;
        } else {
          if (u0 < localP->Saturation1_LowerSat_e) {
            u0 = localP->Saturation1_LowerSat_e;
          }
        }

        /* Product: '<S37>/Divide' incorporates:
         *  Constant: '<S31>/Constant3'
         *  Constant: '<S37>/Constant'
         *  Constant: '<S37>/Constant1'
         *  DataTypeConversion: '<S31>/Data Type Conversion'
         *  Fcn: '<S37>/Fcn'
         *  Product: '<S37>/Product1'
         *  Product: '<S37>/Product4'
         *  Saturate: '<S37>/Saturation1'
         *  Sum: '<S37>/Sum'
         *  Sum: '<S37>/Sum1'
         *  Sum: '<S37>/Sum2'
         */
        localB->Divide = (real32_T)((((real_T)(((real32_T)a - rtu_alt_back[0]) *
          localP->Constant3_Value) - u0) + localP->Constant_Value) *
          localP->Constant1_Value_e / ((real32_T)cos(rtb_Gain5_l_idx_0) *
          (real32_T)cos(rtb_Gain5_l_idx_1)));
      }

      /* End of Outputs for SubSystem: '<S31>/Subsystem' */

      /* Switch: '<S31>/Switch' incorporates:
       *  Constant: '<S31>/Constant1'
       *  DataTypeConversion: '<S31>/Data Type Conversion1'
       *  Gain: '<S31>/Gain7'
       *  MATLAB Function: '<S31>/MATLAB Function'
       *  Saturate: '<S31>/Saturation1'
       *  Sum: '<S31>/Sum1'
       *  Sum: '<S31>/Sum4'
       */
      if ((real32_T)localDW->count > localP->Switch_Threshold) {
        rtb_Sum_lz_idx_0 = localB->Divide;
      } else {
        /* Product: '<S31>/Product2' incorporates:
         *  Constant: '<S31>/D'
         */
        u0 = rtu_alt_back[1] * localP->D_Value;

        /* Saturate: '<S31>/Saturation1' */
        if (u0 > localP->Saturation1_UpperSat) {
          u0 = localP->Saturation1_UpperSat;
        } else {
          if (u0 < localP->Saturation1_LowerSat) {
            u0 = localP->Saturation1_LowerSat;
          }
        }

        rtb_Sum_lz_idx_0 = (rtu_Guidance_in - localP->Constant1_Value) *
          localP->Gain7_Gain - u0;
      }

      /* End of Switch: '<S31>/Switch' */

      /* Saturate: '<S31>/Saturation' */
      if (rtb_Sum_lz_idx_0 > localP->Saturation_UpperSat_g) {
        rtb_Sum_lz_idx_0 = localP->Saturation_UpperSat_g;
      } else {
        if (rtb_Sum_lz_idx_0 < localP->Saturation_LowerSat_n) {
          rtb_Sum_lz_idx_0 = localP->Saturation_LowerSat_n;
        }
      }

      /* End of Saturate: '<S31>/Saturation' */

      /* DataTypeConversion: '<S26>/Data Type Conversion' incorporates:
       *  Gain: '<S26>/Gain'
       */
      u0 = (real32_T)(localP->Gain_Gain * localB->Sum2[0]);
      rtb_Sum_lz_idx_1 = (real32_T)(localP->Gain_Gain * localB->Sum2[1]);

      /* Saturate: '<S26>/Saturation' */
      if (rtb_Sum_lz_idx_1 > localP->Saturation_UpperSat_m) {
        rtb_Sum_lz_idx_1 = localP->Saturation_UpperSat_m;
      } else {
        if (rtb_Sum_lz_idx_1 < localP->Saturation_LowerSat_i) {
          rtb_Sum_lz_idx_1 = localP->Saturation_LowerSat_i;
        }
      }

      /* Gain: '<S27>/Gain' incorporates:
       *  Constant: '<S27>/nD'
       *  Constant: '<S27>/nI'
       *  Constant: '<S27>/nP'
       *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator1'
       *  Product: '<S27>/Product4'
       *  Product: '<S27>/Product5'
       *  Product: '<S27>/Product6'
       *  Sum: '<S27>/Sum2'
       *  Sum: '<S34>/Diff'
       *  UnitDelay: '<S34>/UD'
       */
      rtb_Gain5_l_idx_0 = (real32_T)((((TSamp_e - localDW->UD_DSTATE_b) *
        localP->nD_Value_h + localP->nP_Value_p * Sum1_c) +
        localDW->DiscreteTimeIntegrator1_DSTAT_b * localP->nI_Value_j) *
        localP->Gain_Gain_i);

      /* Saturate: '<S27>/Saturation' */
      if (rtb_Gain5_l_idx_0 > localP->Saturation_UpperSat_c) {
        /* DataTypeConversion: '<S25>/Data Type Conversion' */
        rtb_DataTypeConversion_c[3] = localP->Saturation_UpperSat_c;
      } else if (rtb_Gain5_l_idx_0 < localP->Saturation_LowerSat_o) {
        /* DataTypeConversion: '<S25>/Data Type Conversion' */
        rtb_DataTypeConversion_c[3] = localP->Saturation_LowerSat_o;
      } else {
        /* DataTypeConversion: '<S25>/Data Type Conversion' */
        rtb_DataTypeConversion_c[3] = rtb_Gain5_l_idx_0;
      }

      /* End of Saturate: '<S27>/Saturation' */

      /* Saturate: '<S26>/Saturation' */
      /* MATLAB Function 'Controller/Angle_hold/Subsystem/MATLAB Function2': '<S30>:1' */
      /*  b= 8.7838E-6;       % [N.s2] thrust factor in hover */
      /*  d= 7.5E-7;         % [Nm.s2] drag factor in hover */
      /* '<S30>:1:6' */
      /* '<S30>:1:7' */
      /* '<S30>:1:8' */
      if (u0 > localP->Saturation_UpperSat_m) {
        /* MATLAB Function: '<S25>/MATLAB Function2' */
        U_idx_1 = localP->Saturation_UpperSat_m;
      } else if (u0 < localP->Saturation_LowerSat_i) {
        /* MATLAB Function: '<S25>/MATLAB Function2' */
        U_idx_1 = localP->Saturation_LowerSat_i;
      } else {
        /* MATLAB Function: '<S25>/MATLAB Function2' */
        U_idx_1 = u0;
      }

      /* MATLAB Function: '<S25>/MATLAB Function' incorporates:
       *  DataTypeConversion: '<S25>/Data Type Conversion'
       *  Saturate: '<S25>/Saturation'
       */
      /* '<S30>:1:9' */
      /* '<S30>:1:10' */
      /*  thrust and drag coefficients matrix (for hover) */
      /*  Omd=sqrt(inv(mapmat)*U');   % desired prop speeds [rad/s] */
      /*  bin=(Omd+shi)/slo;  % setpoint to be sent to motor modules */
      /* '<S30>:1:20' */
      /*  Only for test */
      /* '<S30>:1:22' */
      /*  [dec] */
      /* MATLAB Function 'Controller/Angle_hold/Subsystem/MATLAB Function': '<S28>:1' */
      /*  [N.s2] thrust factor in hover */
      /*  [Nm.s2] drag factor in hover */
      /* '<S28>:1:4' */
      /* '<S28>:1:5' */
      /* '<S28>:1:6' */
      /* '<S28>:1:7' */
      /* '<S28>:1:8' */
      /*  thrust and drag coefficients matrix (for hover) */
      /*  Omd=sqrt(inv(mapmat)*U');   % desired prop speeds [rad/s] */
      /*  bin=(Omd+shi)/slo;  % setpoint to be sent to motor modules */
      /* '<S28>:1:18' */
      /*  Only for test */
      /* '<S28>:1:20' */
      /*  [dec] */
      /* MATLAB Function 'Controller/Angle_hold/Subsystem/MATLAB Function1': '<S29>:1' */
      /* '<S29>:1:2' */
      for (i = 0; i < 4; i++) {
        a = a_1[i + 12] * rtb_DataTypeConversion_c[3] + (a_1[i + 8] * 0.0 +
          (a_1[i + 4] * 0.0 + a_1[i] * rtb_Sum_lz_idx_0));
        a_2[i] = a;
      }

      /* Saturate: '<S25>/Saturation' incorporates:
       *  MATLAB Function: '<S25>/MATLAB Function'
       */
      if (a_2[0] > localP->Saturation_UpperSat) {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[0] = localP->Saturation_UpperSat;
      } else if (a_2[0] < localP->Saturation_LowerSat) {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[0] = localP->Saturation_LowerSat;
      } else {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[0] = a_2[0];
      }

      if (a_2[1] > localP->Saturation_UpperSat) {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[1] = localP->Saturation_UpperSat;
      } else if (a_2[1] < localP->Saturation_LowerSat) {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[1] = localP->Saturation_LowerSat;
      } else {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[1] = a_2[1];
      }

      if (a_2[2] > localP->Saturation_UpperSat) {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[2] = localP->Saturation_UpperSat;
      } else if (a_2[2] < localP->Saturation_LowerSat) {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[2] = localP->Saturation_LowerSat;
      } else {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[2] = a_2[2];
      }

      if (a_2[3] > localP->Saturation_UpperSat) {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[3] = localP->Saturation_UpperSat;
      } else if (a_2[3] < localP->Saturation_LowerSat) {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[3] = localP->Saturation_LowerSat;
      } else {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[3] = a_2[3];
      }

      rtb_DataTypeConversion_c[0] = sqrt(rtb_DataTypeConversion_c[0]);
      rtb_DataTypeConversion_c[1] = sqrt(rtb_DataTypeConversion_c[1]);
      rtb_DataTypeConversion_c[2] = sqrt(rtb_DataTypeConversion_c[2]);
      rtb_DataTypeConversion_c[3] = sqrt(rtb_DataTypeConversion_c[3]);

      /*  Only for test */
      /* '<S29>:1:4' */
      rtb_DataTypeConversion_c[0] /= 897.59999999999991;
      rtb_DataTypeConversion_c[1] /= 897.59999999999991;
      rtb_DataTypeConversion_c[2] /= 897.59999999999991;
      rtb_DataTypeConversion_c[3] /= 897.59999999999991;

      /* DataTypeConversion: '<S25>/Data Type Conversion1' incorporates:
       *  DataTypeConversion: '<S25>/Data Type Conversion'
       *  MATLAB Function: '<S25>/MATLAB Function1'
       *  MATLAB Function: '<S25>/MATLAB Function2'
       *  Saturate: '<S26>/Saturation'
       *  Sum: '<S25>/Sum1'
       */
      for (i = 0; i < 4; i++) {
        localB->DataTypeConversion1_n[i] = (real32_T)((((a_0[i + 4] * U_idx_1 +
          a_0[i] * 0.0) + a_0[i + 8] * rtb_Sum_lz_idx_1) + a_0[i + 12] * 0.0) /
          2.0 + rtb_DataTypeConversion_c[i]);
      }

      /* End of DataTypeConversion: '<S25>/Data Type Conversion1' */

      /* Update for UnitDelay: '<S32>/UD' */
      localDW->UD_DSTATE[0] = TSamp_idx_0;
      localDW->UD_DSTATE[1] = TSamp_idx_1;

      /* Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' incorporates:
       *  DataTypeConversion: '<S26>/Data Type Conversion1'
       */
      if (rtb_y_o == 0) {
        localDW->DiscreteTimeIntegrator1_DSTATE[0] +=
          localP->DiscreteTimeIntegrator1_gainval * Sum1_idx_0;
        localDW->DiscreteTimeIntegrator1_DSTATE[1] +=
          localP->DiscreteTimeIntegrator1_gainval * Sum1_idx_1;
        if (localDW->DiscreteTimeIntegrator1_DSTATE[0] >=
            localP->DiscreteTimeIntegrator1_UpperSa) {
          localDW->DiscreteTimeIntegrator1_DSTATE[0] =
            localP->DiscreteTimeIntegrator1_UpperSa;
        } else {
          if (localDW->DiscreteTimeIntegrator1_DSTATE[0] <=
              localP->DiscreteTimeIntegrator1_LowerSa) {
            localDW->DiscreteTimeIntegrator1_DSTATE[0] =
              localP->DiscreteTimeIntegrator1_LowerSa;
          }
        }

        if (localDW->DiscreteTimeIntegrator1_DSTATE[1] >=
            localP->DiscreteTimeIntegrator1_UpperSa) {
          localDW->DiscreteTimeIntegrator1_DSTATE[1] =
            localP->DiscreteTimeIntegrator1_UpperSa;
        } else {
          if (localDW->DiscreteTimeIntegrator1_DSTATE[1] <=
              localP->DiscreteTimeIntegrator1_LowerSa) {
            localDW->DiscreteTimeIntegrator1_DSTATE[1] =
              localP->DiscreteTimeIntegrator1_LowerSa;
          }
        }
      }

      if (rtb_y_o > 0) {
        localDW->DiscreteTimeIntegrator1_PrevRes = 1;
      } else {
        localDW->DiscreteTimeIntegrator1_PrevRes = 0;
      }

      /* End of Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' */

      /* Update for UnitDelay: '<S34>/UD' */
      localDW->UD_DSTATE_b = TSamp_e;

      /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' incorporates:
       *  DataTypeConversion: '<S27>/Data Type Conversion'
       */
      if (rtb_y_c == 0) {
        localDW->DiscreteTimeIntegrator1_DSTAT_b +=
          localP->DiscreteTimeIntegrator1_gainv_e * Sum1_c;
        if (localDW->DiscreteTimeIntegrator1_DSTAT_b >=
            localP->DiscreteTimeIntegrator1_Upper_f) {
          localDW->DiscreteTimeIntegrator1_DSTAT_b =
            localP->DiscreteTimeIntegrator1_Upper_f;
        } else {
          if (localDW->DiscreteTimeIntegrator1_DSTAT_b <=
              localP->DiscreteTimeIntegrator1_Lower_k) {
            localDW->DiscreteTimeIntegrator1_DSTAT_b =
              localP->DiscreteTimeIntegrator1_Lower_k;
          }
        }
      }

      if (rtb_y_c > 0) {
        localDW->DiscreteTimeIntegrator1_PrevR_j = 1;
      } else {
        localDW->DiscreteTimeIntegrator1_PrevR_j = 0;
      }

      /* End of Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' */
      /* End of Outputs for SubSystem: '<S20>/Subsystem' */
    }

    /* End of If: '<S20>/If' */

    /* Switch: '<S20>/Switch' incorporates:
     *  Gain: '<S20>/Gain'
     */
    if (rtu_Guidance_in > localP->Switch_Threshold_f) {
      rtb_Sum_lz_idx_0 = localB->DataTypeConversion1_n[0];
      rtb_Sum_lz_idx_1 = localB->DataTypeConversion1_n[1];
      rtb_Gain5_l_idx_0 = localB->DataTypeConversion1_n[2];
      rtb_Gain5_l_idx_1 = localB->DataTypeConversion1_n[3];
    } else {
      rtb_Sum_lz_idx_0 = localP->Gain_Gain_j[0] * rtu_Guidance_in;
      rtb_Sum_lz_idx_1 = localP->Gain_Gain_j[1] * rtu_Guidance_in;
      rtb_Gain5_l_idx_0 = localP->Gain_Gain_j[2] * rtu_Guidance_in;
      rtb_Gain5_l_idx_1 = localP->Gain_Gain_j[3] * rtu_Guidance_in;
    }

    /* End of Switch: '<S20>/Switch' */

    /* Sum: '<S20>/Sum' incorporates:
     *  Constant: '<S20>/Constant1'
     */
    localB->Sum[0] = rtb_Sum_lz_idx_0 + localP->Constant1_Value_h[0];
    localB->Sum[1] = rtb_Sum_lz_idx_1 + localP->Constant1_Value_h[1];
    localB->Sum[2] = rtb_Gain5_l_idx_0 + localP->Constant1_Value_h[2];
    localB->Sum[3] = rtb_Gain5_l_idx_1 + localP->Constant1_Value_h[3];
  }

  /* End of Outputs for SubSystem: '<S2>/Angle_hold' */
}

/*
 * Output and update for atomic system:
 *    '<S69>/MATLAB Function2'
 *    '<S69>/MATLAB Function4'
 */
void download_MATLABFunction2(real_T rtu_u, B_MATLABFunction2_download_T *localB)
{
  real_T y;

  /* MATLAB Function 'Receiver/Enabled Subsystem/MATLAB Function2': '<S71>:1' */
  /* 输入范围为0.34~1.7，将其调整到1~2ms */
  /* '<S71>:1:4' */
  y = rtu_u / 1.375;
  if ((y + 0.76 > 0.8) && (y + 0.76 < 2.1)) {
    /* '<S71>:1:5' */
    /* '<S71>:1:6' */
    localB->y = y + 0.76;
  } else {
    /* '<S71>:1:8' */
    localB->y = 1.5;
  }
}

/* Model step function */
void download_step(void)
{
  /* local block i/o variables */
  real_T rtb_Gain1;
  real_T rtb_Gain3;
  real32_T rtb_TmpSignalConversionAtAngle_[2];
  real32_T stageIn;
  real_T rtb_y_a;
  real32_T rtb_DataTypeConversion[4];
  uint16_T rtb_Add3_o;
  real_T rtb_y_d;
  real32_T rtb_TSamp;
  real32_T rtb_DataTypeConversion1;
  int8_T rtPrevAction;
  int8_T rtAction;
  uint16_T rtb_ShiftArithmetic3_h;
  uint16_T rtb_ShiftArithmetic4_f;
  uint16_T rtb_ShiftArithmetic5_b;
  if (download_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Atomic SubSystem: '<Root>/IMU' */
    download_IMU();

    /* End of Outputs for SubSystem: '<Root>/IMU' */

    /* S-Function (stm32f4_digital_output): '<S7>/Blue LED' */

    /* OrangeLED1BlueLED */
    *OrangeLED1BlueLED_C2 = (boolean_T) download_B.angle_o1;

    /* ReceiverUARTRx3: '<S8>/UART Rx3' */
    if (ReceiverUARTRx3_Receive(&UART2_Temp_Buffer[0], 23)) {/* Non-blocking */
      memcpy(&download_B.UARTRx3_o2_j[0], &UART2_Temp_Buffer[0], 23*sizeof
             (uint8_T));               /* D0 [23] */
      download_B.UARTRx3_o1 = 1;       /* READY */
    } else {
      download_B.UARTRx3_o1 = 0;       /* Not READY */
    }

    /* Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S69>/Enable'
     */
    if (download_B.UARTRx3_o1 > 0) {
      /* ArithShift: '<S69>/Shift Arithmetic3' incorporates:
       *  DataTypeConversion: '<S69>/Data Type Conversion5'
       */
      rtb_ShiftArithmetic3_h = (uint16_T)(download_B.UARTRx3_o2_j[2] >> 6);

      /* ArithShift: '<S69>/Shift Arithmetic4' incorporates:
       *  DataTypeConversion: '<S69>/Data Type Conversion6'
       */
      rtb_ShiftArithmetic4_f = (uint16_T)(download_B.UARTRx3_o2_j[3] << 2);

      /* ArithShift: '<S69>/Shift Arithmetic5' incorporates:
       *  S-Function (sfix_bitop): '<S69>/Bitwise Operator7'
       */
      rtb_ShiftArithmetic5_b = (uint16_T)((uint16_T)(download_B.UARTRx3_o2_j[4]
        & download_P.BitwiseOperator7_BitMask) << 10);

      /* Sum: '<S69>/Add3' incorporates:
       *  ArithShift: '<S69>/Shift Arithmetic6'
       *  ArithShift: '<S69>/Shift Arithmetic7'
       *  S-Function (sfix_bitop): '<S69>/Bitwise Operator1'
       *  S-Function (sfix_bitop): '<S69>/Bitwise Operator2'
       */
      rtb_Add3_o = (uint16_T)((uint32_T)((download_B.UARTRx3_o2_j[4] &
        download_P.BitwiseOperator1_BitMask_ac) >> 1) +
        ((download_B.UARTRx3_o2_j[5] & download_P.BitwiseOperator2_BitMask_n) <<
         7));

      /* MATLAB Function: '<S69>/MATLAB Function1' incorporates:
       *  ArithShift: '<S69>/Shift Arithmetic'
       *  DataTypeConversion: '<S69>/Data Type Conversion4'
       *  DataTypeConversion: '<S69>/Data Type Conversion8'
       *  Gain: '<S69>/Gain'
       *  S-Function (sfix_bitop): '<S69>/Bitwise Operator5'
       *  Sum: '<S69>/Add'
       */
      /* MATLAB Function 'Receiver/Enabled Subsystem/MATLAB Function1': '<S70>:1' */
      /* 输入范围为0.34~1.7，将其调整到1~2ms */
      /* '<S70>:1:4' */
      rtb_y_d = (real_T)((uint32_T)((download_B.UARTRx3_o2_j[1] &
        download_P.BitwiseOperator5_BitMask) << 8) + download_B.UARTRx3_o2_j[0])
        * download_P.Gain_Gain / 1.375;
      if ((rtb_y_d + 0.76 > 0.8) && (rtb_y_d + 0.76 < 2.1)) {
        /* '<S70>:1:5' */
        /* '<S70>:1:6' */
        rtb_y_d += 0.76;
      } else {
        /* '<S70>:1:8' */
        rtb_y_d = 1.5;
      }

      /* End of MATLAB Function: '<S69>/MATLAB Function1' */

      /* DataTypeConversion: '<S69>/Data Type Conversion' */
      download_B.CH1 = (real32_T)rtb_y_d;

      /* Gain: '<S69>/Gain1' incorporates:
       *  ArithShift: '<S69>/Shift Arithmetic1'
       *  ArithShift: '<S69>/Shift Arithmetic2'
       *  DataTypeConversion: '<S69>/Data Type Conversion1'
       *  DataTypeConversion: '<S69>/Data Type Conversion9'
       *  S-Function (sfix_bitop): '<S69>/Bitwise Operator6'
       *  Sum: '<S69>/Add1'
       */
      rtb_Gain1 = (real_T)((uint32_T)((download_B.UARTRx3_o2_j[2] &
        download_P.BitwiseOperator6_BitMask) << 5) + (download_B.UARTRx3_o2_j[1]
        >> 3)) * download_P.Gain1_Gain;

      /* MATLAB Function: '<S69>/MATLAB Function2' */
      download_MATLABFunction2(rtb_Gain1, &download_B.sf_MATLABFunction2);

      /* DataTypeConversion: '<S69>/Data Type Conversion11' */
      download_B.CH2 = (real32_T)download_B.sf_MATLABFunction2.y;

      /* MATLAB Function: '<S69>/MATLAB Function3' incorporates:
       *  DataTypeConversion: '<S69>/Data Type Conversion10'
       *  Gain: '<S69>/Gain2'
       *  Sum: '<S69>/Add2'
       */
      /* MATLAB Function 'Receiver/Enabled Subsystem/MATLAB Function3': '<S72>:1' */
      /* 输入范围为0.34~1.7，将其调整到1~2ms */
      /* '<S72>:1:4' */
      rtb_y_d = (real_T)(uint16_T)(((uint32_T)rtb_ShiftArithmetic3_h +
        rtb_ShiftArithmetic4_f) + rtb_ShiftArithmetic5_b) *
        download_P.Gain2_Gain / 1.375;
      if ((rtb_y_d + 0.75 > 1.0) && (rtb_y_d + 0.75 < 2.1)) {
        /* '<S72>:1:5' */
        /* '<S72>:1:6' */
        rtb_y_d += 0.75;
      } else {
        /* '<S72>:1:8' */
        rtb_y_d = 1.0;
      }

      /* End of MATLAB Function: '<S69>/MATLAB Function3' */

      /* DataTypeConversion: '<S69>/Data Type Conversion12' */
      download_B.CH3 = (real32_T)rtb_y_d;

      /* Gain: '<S69>/Gain3' incorporates:
       *  DataTypeConversion: '<S69>/Data Type Conversion15'
       */
      rtb_Gain3 = download_P.Gain3_Gain * (real_T)rtb_Add3_o;

      /* MATLAB Function: '<S69>/MATLAB Function4' */
      download_MATLABFunction2(rtb_Gain3, &download_B.sf_MATLABFunction4);

      /* DataTypeConversion: '<S69>/Data Type Conversion16' */
      download_B.CH4 = (real32_T)download_B.sf_MATLABFunction4.y;
    }

    /* End of Outputs for SubSystem: '<S8>/Enabled Subsystem' */

    /* Outputs for Atomic SubSystem: '<Root>/Guidance_System' */
    download_Guidance_System(download_B.CH3, download_B.CH4, download_B.CH2,
      download_B.CH1, &download_B.Guidance_System, (P_Guidance_System_download_T
      *)&download_P.Guidance_System);

    /* End of Outputs for SubSystem: '<Root>/Guidance_System' */

    /* MATLAB Function: '<S2>/MATLAB Function' */
    /* MATLAB Function 'Controller/MATLAB Function': '<S21>:1' */
    if ((download_B.Guidance_System.Saturation < 0.1) &&
        (download_B.Guidance_System.Saturation_d < -160.0F)) {
      /* '<S21>:1:7' */
      /* '<S21>:1:8' */
      download_DW.status = 1.0;
    } else {
      if ((download_B.Guidance_System.Saturation < 0.1) &&
          (download_B.Guidance_System.Saturation_d > 160.0F)) {
        /* '<S21>:1:9' */
        /* '<S21>:1:10' */
        download_DW.status = 0.0;
      }
    }

    /* '<S21>:1:12' */
    rtb_y_a = download_DW.status;

    /* End of MATLAB Function: '<S2>/MATLAB Function' */

    /* Outputs for Atomic SubSystem: '<S2>/Velocity_Damper2' */
    /* RateTransition: '<S24>/Rate Transition' */
    if (download_M->Timing.TaskCounters.TID[3] == 0) {
      download_B.RateTransition_e = download_B.Gain6;
    }

    /* End of RateTransition: '<S24>/Rate Transition' */
    /* End of Outputs for SubSystem: '<S2>/Velocity_Damper2' */
  }

  /* Outputs for Atomic SubSystem: '<S2>/Velocity_Damper2' */
  if (download_M->Timing.TaskCounters.TID[3] == 0) {
    /* SampleTimeMath: '<S50>/TSamp'
     *
     * About '<S50>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp = download_B.RateTransition_e * download_P.TSamp_WtEt;

    /* S-Function (sdspbiquad): '<S51>/Generated Filter Block' incorporates:
     *  Sum: '<S50>/Diff'
     *  UnitDelay: '<S50>/UD'
     */
    stageIn = ((rtb_TSamp - download_DW.UD_DSTATE) * 0.0138937552F -
               -1.82657754F * download_DW.GeneratedFilterBlock_FILT_STA_f[0]) -
      0.840471447F * download_DW.GeneratedFilterBlock_FILT_STA_f[1];
    download_B.GeneratedFilterBlock_b = (0.315986633F * stageIn + 0.368038207F *
      download_DW.GeneratedFilterBlock_FILT_STA_f[0]) + 0.315986633F *
      download_DW.GeneratedFilterBlock_FILT_STA_f[1];
    download_DW.GeneratedFilterBlock_FILT_STA_f[1] =
      download_DW.GeneratedFilterBlock_FILT_STA_f[0];
    download_DW.GeneratedFilterBlock_FILT_STA_f[0] = stageIn;

    /* Saturate: '<S47>/Saturation' */
    if (download_B.GeneratedFilterBlock_b > download_P.Saturation_UpperSat) {
      download_B.Saturation = download_P.Saturation_UpperSat;
    } else if (download_B.GeneratedFilterBlock_b <
               download_P.Saturation_LowerSat) {
      download_B.Saturation = download_P.Saturation_LowerSat;
    } else {
      download_B.Saturation = download_B.GeneratedFilterBlock_b;
    }

    /* End of Saturate: '<S47>/Saturation' */
  }

  if (download_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLAB Function: '<S24>/MATLAB Function' incorporates:
     *  DataTypeConversion: '<S24>/Data Type Conversion3'
     */
    /* MATLAB Function 'Controller/Velocity_Damper2/MATLAB Function': '<S49>:1' */
    if ((rtb_y_a == 1.0) && (download_DW.count == 0.0)) {
      /* '<S49>:1:10' */
      /* '<S49>:1:11' */
      download_DW.count = 1.0;

      /* '<S49>:1:12' */
      download_DW.altitude_basic = download_B.Gain6;
    } else {
      if ((rtb_y_a == 0.0) && (download_DW.count == 1.0)) {
        /* '<S49>:1:13' */
        /* '<S49>:1:14' */
        download_DW.count = 0.0;
      }
    }

    /* S-Function (sdspbiquad): '<S48>/Generated Filter Block' incorporates:
     *  DataTypeConversion: '<S24>/Data Type Conversion3'
     *  MATLAB Function: '<S24>/MATLAB Function'
     */
    /* '<S49>:1:16' */
    rtb_y_d = ((download_B.Gain6 - download_DW.altitude_basic) *
               0.013893755370815749 - -1.8265775363780477 *
               download_DW.GeneratedFilterBlock_FILT_STATE[0]) -
      0.840471451002894 * download_DW.GeneratedFilterBlock_FILT_STATE[1];
    download_B.GeneratedFilterBlock = (0.31598662750883372 * rtb_y_d +
      0.368038207256305 * download_DW.GeneratedFilterBlock_FILT_STATE[0]) +
      0.31598662750883377 * download_DW.GeneratedFilterBlock_FILT_STATE[1];
    download_DW.GeneratedFilterBlock_FILT_STATE[1] =
      download_DW.GeneratedFilterBlock_FILT_STATE[0];
    download_DW.GeneratedFilterBlock_FILT_STATE[0] = rtb_y_d;

    /* DataTypeConversion: '<S24>/Data Type Conversion1' */
    rtb_DataTypeConversion1 = (real32_T)download_B.GeneratedFilterBlock;
  }

  if (download_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update for UnitDelay: '<S50>/UD' */
    download_DW.UD_DSTATE = rtb_TSamp;
  }

  /* End of Outputs for SubSystem: '<S2>/Velocity_Damper2' */
  if (download_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion: '<S2>/TmpSignal ConversionAtAngle_holdInport6' */
    rtb_TmpSignalConversionAtAngle_[0] = rtb_DataTypeConversion1;
    rtb_TmpSignalConversionAtAngle_[1] = download_B.Saturation;

    /* SignalConversion: '<S2>/HiddenBuf_InsertedFor_Angle_hold_at_inport_6' */
    download_B.HiddenBuf_InsertedFor_Angle_hol = rtb_y_a;

    /* Outputs for Enabled SubSystem: '<S2>/Angle_hold' */
    download_Angle_hold(download_B.HiddenBuf_InsertedFor_Angle_hol,
                        download_B.Guidance_System.Saturation,
                        download_B.Guidance_System.Saturation_a,
                        download_B.Guidance_System.Saturation_b,
                        download_B.Gain2_e, download_B.Gain1, download_B.Gain2,
                        download_B.Gain3_m, download_B.Gain3, download_B.Gain4,
                        download_B.Guidance_System.Saturation_d,
                        rtb_TmpSignalConversionAtAngle_, &download_B.Angle_hold,
                        &download_DW.Angle_hold, (P_Angle_hold_download_T *)
                        &download_P.Angle_hold);

    /* End of Outputs for SubSystem: '<S2>/Angle_hold' */

    /* RateTransition: '<S9>/Rate Transition' */
    if (download_M->Timing.TaskCounters.TID[2] == 0) {
      download_B.RateTransition[0] = download_B.Angle_hold.Sum[0];
      download_B.RateTransition[1] = download_B.Angle_hold.Sum[1];
      download_B.RateTransition[2] = download_B.Angle_hold.Sum[2];
      download_B.RateTransition[3] = download_B.Angle_hold.Sum[3];
    }

    /* End of RateTransition: '<S9>/Rate Transition' */
  }

  if (download_M->Timing.TaskCounters.TID[2] == 0) {
    /* Saturate: '<S9>/Saturation' */
    if (download_B.RateTransition[0] > download_P.Saturation_UpperSat_l) {
      rtb_TSamp = download_P.Saturation_UpperSat_l;
    } else if (download_B.RateTransition[0] < download_P.Saturation_LowerSat_g)
    {
      rtb_TSamp = download_P.Saturation_LowerSat_g;
    } else {
      rtb_TSamp = download_B.RateTransition[0];
    }

    /* Gain: '<S9>/Gain' incorporates:
     *  Saturate: '<S9>/Saturation'
     */
    download_B.Gain[0] = download_P.Gain_Gain_b * rtb_TSamp;

    /* Saturate: '<S9>/Saturation' */
    if (download_B.RateTransition[1] > download_P.Saturation_UpperSat_l) {
      rtb_TSamp = download_P.Saturation_UpperSat_l;
    } else if (download_B.RateTransition[1] < download_P.Saturation_LowerSat_g)
    {
      rtb_TSamp = download_P.Saturation_LowerSat_g;
    } else {
      rtb_TSamp = download_B.RateTransition[1];
    }

    /* Gain: '<S9>/Gain' incorporates:
     *  Saturate: '<S9>/Saturation'
     */
    download_B.Gain[1] = download_P.Gain_Gain_b * rtb_TSamp;

    /* Saturate: '<S9>/Saturation' */
    if (download_B.RateTransition[2] > download_P.Saturation_UpperSat_l) {
      rtb_TSamp = download_P.Saturation_UpperSat_l;
    } else if (download_B.RateTransition[2] < download_P.Saturation_LowerSat_g)
    {
      rtb_TSamp = download_P.Saturation_LowerSat_g;
    } else {
      rtb_TSamp = download_B.RateTransition[2];
    }

    /* Gain: '<S9>/Gain' incorporates:
     *  Saturate: '<S9>/Saturation'
     */
    download_B.Gain[2] = download_P.Gain_Gain_b * rtb_TSamp;

    /* Saturate: '<S9>/Saturation' */
    if (download_B.RateTransition[3] > download_P.Saturation_UpperSat_l) {
      rtb_TSamp = download_P.Saturation_UpperSat_l;
    } else if (download_B.RateTransition[3] < download_P.Saturation_LowerSat_g)
    {
      rtb_TSamp = download_P.Saturation_LowerSat_g;
    } else {
      rtb_TSamp = download_B.RateTransition[3];
    }

    /* Gain: '<S9>/Gain' incorporates:
     *  Saturate: '<S9>/Saturation'
     */
    download_B.Gain[3] = download_P.Gain_Gain_b * rtb_TSamp;
  }

  if (download_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function Block: <S9>/Basic PWM7 (stm32f4_basicpwm) */
    TIM4->CCR1 = (uint32_t) (download_B.Gain[0] * executeBasicPWM7_SF);
    TIM4->CCR2 = (uint32_t) (download_B.Gain[1] * executeBasicPWM7_SF);
    TIM4->CCR3 = (uint32_t) (download_B.Gain[2] * executeBasicPWM7_SF);
    TIM4->CCR4 = (uint32_t) (download_B.Gain[3] * executeBasicPWM7_SF);

    /* RateTransition: '<S11>/Rate Transition' incorporates:
     *  RateTransition: '<S11>/Rate Transition'
     *  RateTransition: '<S11>/Rate Transition2'
     */
    if (download_M->Timing.TaskCounters.TID[3] == 0) {
      download_B.Angle[0] = download_B.Gain2_e;
      download_B.Angle[1] = download_B.Gain1;
      download_B.Angle[2] = download_B.Gain2;
      download_B.Angle_rate[0] = download_B.Gain3_m;
      download_B.Angle_rate[1] = download_B.Gain3;
      download_B.Angle_rate[2] = download_B.Gain4;
      download_B.RateTransition2[0] = rtb_DataTypeConversion1;
      download_B.RateTransition2[1] = download_B.Saturation;
    }

    /* End of RateTransition: '<S11>/Rate Transition' */
  }

  if (download_M->Timing.TaskCounters.TID[4] == 0) {
    /* toshangweijiUARTTx: '<S11>/UART Tx' */
    {
      UART1_FlushTxBuffer();           /* Flush tx, so we can print to DMA buffer directly */
      sprintf((char*)UART1_Tx_Buffer, "back=%f,%f,%f,%f,%f,%f,%f,%f\r\n" ,
              download_B.Angle[0] ,download_B.Angle[1] ,download_B.Angle[2] ,
              download_B.Angle_rate[0] ,download_B.Angle_rate[1] ,
              download_B.Angle_rate[2] ,download_B.RateTransition2[0] ,
              download_B.RateTransition2[1] );
      UART1_TxUpdate(strlen((char*)UART1_Tx_Buffer));
    }
  }

  if (download_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S11>/Data Type Conversion' */
    rtb_DataTypeConversion[0] = (real32_T)download_B.Angle_hold.Sum2[0];
    rtb_DataTypeConversion[1] = (real32_T)download_B.Angle_hold.Sum2[1];
    rtb_DataTypeConversion[2] = (real32_T)download_B.Angle_hold.Product6[0];
    rtb_DataTypeConversion[3] = (real32_T)download_B.Angle_hold.Product6[1];

    /* RateTransition: '<S11>/Rate Transition3' */
    if (download_M->Timing.TaskCounters.TID[3] == 0) {
      download_B.RateTransition3[0] = rtb_DataTypeConversion[0];
      download_B.RateTransition3[1] = rtb_DataTypeConversion[1];
      download_B.RateTransition3[2] = rtb_DataTypeConversion[2];
      download_B.RateTransition3[3] = rtb_DataTypeConversion[3];
    }

    /* End of RateTransition: '<S11>/Rate Transition3' */
  }

  if (download_M->Timing.TaskCounters.TID[3] == 0) {
    /* toshangweijiUARTTx1: '<S11>/UART Tx1' */
    {
      UART1_FlushTxBuffer();           /* Flush tx, so we can print to DMA buffer directly */
      sprintf((char*)UART1_Tx_Buffer, "control=%f,%f,%f,%f\r\n" ,
              download_B.RateTransition3[0] ,download_B.RateTransition3[1] ,
              download_B.RateTransition3[2] ,download_B.RateTransition3[3] );
      UART1_TxUpdate(strlen((char*)UART1_Tx_Buffer));
    }
  }

  if (download_M->Timing.TaskCounters.TID[1] == 0) {
    /* fromshangweijiUARTRx3: '<S1>/UART Rx3' */
    if (fromshangweijiUARTRx3_Receive(&UART1_Temp_Buffer[0], URX1_BUFFER_SIZE))
    {                                  /* Non-Blocking */
      download_B.UARTRx3_o2 = fromshangweijiUARTRx3_data0;/* D0 */
      download_B.UARTRx3_o3 = fromshangweijiUARTRx3_data1;/* D1 */
      download_B.UARTRx3_o4 = fromshangweijiUARTRx3_data2;/* D2 */
      download_B.UARTRx3_o5 = fromshangweijiUARTRx3_data3;/* D3 */
      download_B.UARTRx3_o6 = fromshangweijiUARTRx3_data4;/* D4 */
      download_B.UARTRx3_o1_o = 1;     /* READY */
    } else {
      download_B.UARTRx3_o1_o = 0;     /* Not READY */
    }

    /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem4' incorporates:
     *  EnablePort: '<S15>/Enable'
     */
    if (download_B.UARTRx3_o1_o > 0) {
      if (!download_DW.EnabledSubsystem4_MODE) {
        /* Level2 S-Function Block: '<S15>/UART Tx' (stm32f4_usart) */
        enable_fromshangweijiEnabledSubsystem4UARTTx();
        download_DW.EnabledSubsystem4_MODE = true;
      }

      /* fromshangweijiEnabledSubsystem4UARTTx: '<S15>/UART Tx' */
      {
        UART1_FlushTxBuffer();         /* Flush tx, so we can print to DMA buffer directly */
        sprintf((char*)UART1_Tx_Buffer, "roll_change_OK\r\n" );
        UART1_TxUpdate(strlen((char*)UART1_Tx_Buffer));
      }
    } else {
      if (download_DW.EnabledSubsystem4_MODE) {
        download_DW.EnabledSubsystem4_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem4' */

    /* fromshangweijiUARTRx4: '<S1>/UART Rx4' */
    if (fromshangweijiUARTRx4_Receive(&UART1_Temp_Buffer[0], URX1_BUFFER_SIZE))
    {                                  /* Non-Blocking */
      download_B.UARTRx4_o2 = fromshangweijiUARTRx4_data0;/* D0 */
      download_B.UARTRx4_o3 = fromshangweijiUARTRx4_data1;/* D1 */
      download_B.UARTRx4_o4 = fromshangweijiUARTRx4_data2;/* D2 */
      download_B.UARTRx4_o5 = fromshangweijiUARTRx4_data3;/* D3 */
      download_B.UARTRx4_o6 = fromshangweijiUARTRx4_data4;/* D4 */
      download_B.UARTRx4_o1 = 1;       /* READY */
    } else {
      download_B.UARTRx4_o1 = 0;       /* Not READY */
    }

    /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem5' incorporates:
     *  EnablePort: '<S16>/Enable'
     */
    if (download_B.UARTRx4_o1 > 0) {
      if (!download_DW.EnabledSubsystem5_MODE) {
        /* Level2 S-Function Block: '<S16>/UART Tx' (stm32f4_usart) */
        enable_fromshangweijiEnabledSubsystem5UARTTx();
        download_DW.EnabledSubsystem5_MODE = true;
      }

      /* fromshangweijiEnabledSubsystem5UARTTx: '<S16>/UART Tx' */
      {
        UART1_FlushTxBuffer();         /* Flush tx, so we can print to DMA buffer directly */
        sprintf((char*)UART1_Tx_Buffer, "yaw_change_OK\r\n" );
        UART1_TxUpdate(strlen((char*)UART1_Tx_Buffer));
      }
    } else {
      if (download_DW.EnabledSubsystem5_MODE) {
        download_DW.EnabledSubsystem5_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem5' */

    /* fromshangweijiUARTRx5: '<S1>/UART Rx5' */
    if (fromshangweijiUARTRx5_Receive(&UART1_Temp_Buffer[0], URX1_BUFFER_SIZE))
    {                                  /* Non-Blocking */
      download_B.UARTRx5_o2 = fromshangweijiUARTRx5_data0;/* D0 */
      download_B.UARTRx5_o3 = fromshangweijiUARTRx5_data1;/* D1 */
      download_B.UARTRx5_o4 = fromshangweijiUARTRx5_data2;/* D2 */
      download_B.UARTRx5_o5 = fromshangweijiUARTRx5_data3;/* D3 */
      download_B.UARTRx5_o6 = fromshangweijiUARTRx5_data4;/* D4 */
      download_B.UARTRx5_o1 = 1;       /* READY */
    } else {
      download_B.UARTRx5_o1 = 0;       /* Not READY */
    }

    /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem6' incorporates:
     *  EnablePort: '<S17>/Enable'
     */
    if (download_B.UARTRx5_o1 > 0) {
      if (!download_DW.EnabledSubsystem6_MODE) {
        /* Level2 S-Function Block: '<S17>/UART Tx' (stm32f4_usart) */
        enable_fromshangweijiEnabledSubsystem6UARTTx();
        download_DW.EnabledSubsystem6_MODE = true;
      }

      /* fromshangweijiEnabledSubsystem6UARTTx: '<S17>/UART Tx' */
      {
        UART1_FlushTxBuffer();         /* Flush tx, so we can print to DMA buffer directly */
        sprintf((char*)UART1_Tx_Buffer, "alt_change_OK\r\n" );
        UART1_TxUpdate(strlen((char*)UART1_Tx_Buffer));
      }
    } else {
      if (download_DW.EnabledSubsystem6_MODE) {
        download_DW.EnabledSubsystem6_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem6' */
  }

  if (download_M->Timing.TaskCounters.TID[5] == 0) {
    /* fromshangweijiUARTRx1: '<S1>/UART Rx1' */
    if (fromshangweijiUARTRx1_Receive(&UART1_Temp_Buffer[0], URX1_BUFFER_SIZE))
    {                                  /* Non-Blocking */
      download_B.UARTRx1_o2 = fromshangweijiUARTRx1_data0;/* D0 */
      download_B.UARTRx1_o1 = 1;       /* READY */
    } else {
      download_B.UARTRx1_o1 = 0;       /* Not READY */
    }

    /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem1' incorporates:
     *  EnablePort: '<S12>/Enable'
     */
    if (download_B.UARTRx1_o1 > 0) {
      if (!download_DW.EnabledSubsystem1_MODE) {
        /* Level2 S-Function Block: '<S12>/Digital Output' (stm32f4_digital_output) */
        enable_fromshangweijiEnabledSubsystem1DigitalOutput();
        download_DW.EnabledSubsystem1_MODE = true;
      }

      /* S-Function (stm32f4_digital_output): '<S12>/Digital Output' */

      /* fromshangweijiEnabledSubsystem1DigitalOutput */
      *fromshangweijiEnabledSubsystem1DigitalOutput_C2 = (boolean_T)
        download_B.UARTRx1_o2;

      /* If: '<S12>/If' */
      rtPrevAction = download_DW.If_ActiveSubsystem;
      if (download_B.UARTRx1_o2 > 0U) {
        rtAction = 0;
      } else {
        rtAction = 1;
      }

      download_DW.If_ActiveSubsystem = rtAction;
      if (rtPrevAction != rtAction) {
        switch (rtPrevAction) {
         case 0:
          break;

         case 1:
          break;
        }
      }

      switch (rtAction) {
       case 0:
        if (rtAction != rtPrevAction) {
          /* Enable for IfAction SubSystem: '<S12>/If Action Subsystem' incorporates:
           *  Enable for ActionPort: '<S18>/Action Port'
           */

          /* Level2 S-Function Block: '<S18>/UART Tx' (stm32f4_usart) */
          enable_fromshangweijiEnabledSubsystem1IfActionSubsystemUARTTx();

          /* End of Enable for SubSystem: '<S12>/If Action Subsystem' */
        }

        /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem' incorporates:
         *  ActionPort: '<S18>/Action Port'
         */

        /* fromshangweijiEnabledSubsystem1IfActionSubsystemUARTTx: '<S18>/UART Tx' */
        {
          UART1_FlushTxBuffer();       /* Flush tx, so we can print to DMA buffer directly */
          sprintf((char*)UART1_Tx_Buffer, ">>LED1 OFF\r\n" );
          UART1_TxUpdate(strlen((char*)UART1_Tx_Buffer));
        }

        /* End of Outputs for SubSystem: '<S12>/If Action Subsystem' */
        break;

       case 1:
        if (rtAction != rtPrevAction) {
          /* Enable for IfAction SubSystem: '<S12>/If Action Subsystem1' incorporates:
           *  Enable for ActionPort: '<S19>/Action Port'
           */

          /* Level2 S-Function Block: '<S19>/UART Tx' (stm32f4_usart) */
          enable_fromshangweijiEnabledSubsystem1IfActionSubsystem1UARTTx();

          /* End of Enable for SubSystem: '<S12>/If Action Subsystem1' */
        }

        /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S19>/Action Port'
         */

        /* fromshangweijiEnabledSubsystem1IfActionSubsystem1UARTTx: '<S19>/UART Tx' */
        {
          UART1_FlushTxBuffer();       /* Flush tx, so we can print to DMA buffer directly */
          sprintf((char*)UART1_Tx_Buffer, ">>LED1 ON\r\n" );
          UART1_TxUpdate(strlen((char*)UART1_Tx_Buffer));
        }

        /* End of Outputs for SubSystem: '<S12>/If Action Subsystem1' */
        break;
      }

      /* End of If: '<S12>/If' */
    } else {
      if (download_DW.EnabledSubsystem1_MODE) {
        /* Level2 S-Function Block: '<S12>/Digital Output' (stm32f4_digital_output) */

        /* disable_fromshangweijiEnabledSubsystem1DigitalOutput(); */

        /* Disable for If: '<S12>/If' */
        switch (download_DW.If_ActiveSubsystem) {
         case 0:
          break;

         case 1:
          break;
        }

        download_DW.If_ActiveSubsystem = -1;

        /* End of Disable for If: '<S12>/If' */
        download_DW.EnabledSubsystem1_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem1' */

    /* fromshangweijiUARTRx: '<S1>/UART Rx' */
    if (fromshangweijiUARTRx_Receive(&UART1_Temp_Buffer[0], URX1_BUFFER_SIZE)) {/* Non-Blocking */
      download_B.UARTRx = 1;           /* READY */
    } else {
      download_B.UARTRx = 0;           /* Not READY */
    }

    /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem2' incorporates:
     *  EnablePort: '<S13>/Enable'
     */
    if (download_B.UARTRx > 0) {
      if (!download_DW.EnabledSubsystem2_MODE) {
        /* Level2 S-Function Block: '<S13>/Read Unique ID' (stm32f4_uidread) */
        enable_fromshangweijiEnabledSubsystem2ReadUniqueID();

        /* Level2 S-Function Block: '<S13>/UART Tx' (stm32f4_usart) */
        enable_fromshangweijiEnabledSubsystem2UARTTx();
        download_DW.EnabledSubsystem2_MODE = true;
      }

      /* S-Function Block: <S13>/Read Unique ID (stm32f4_uidread) */
      download_B.ReadUniqueID[0] =
        UID32_fromshangweijiEnabledSubsystem2ReadUniqueID[0];
      download_B.ReadUniqueID[1] =
        UID32_fromshangweijiEnabledSubsystem2ReadUniqueID[1];
      download_B.ReadUniqueID[2] =
        UID32_fromshangweijiEnabledSubsystem2ReadUniqueID[2];

      /* fromshangweijiEnabledSubsystem2UARTTx: '<S13>/UART Tx' */
      {
        UART1_FlushTxBuffer();         /* Flush tx, so we can print to DMA buffer directly */
        sprintf((char*)UART1_Tx_Buffer, "id=%u,%u,%u\r\n" ,
                download_B.ReadUniqueID[0] ,download_B.ReadUniqueID[1] ,
                download_B.ReadUniqueID[2] );
        UART1_TxUpdate(strlen((char*)UART1_Tx_Buffer));

        /* Blocking, wait for DMA buffer */
        UART1_FlushTxBuffer();
      }
    } else {
      if (download_DW.EnabledSubsystem2_MODE) {
        download_DW.EnabledSubsystem2_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem2' */
  }

  /* fromshangweijiUARTRx2: '<S1>/UART Rx2' */
  if (fromshangweijiUARTRx2_Receive(&UART1_Temp_Buffer[0], URX1_BUFFER_SIZE)) {/* Non-Blocking */
    download_B.UARTRx2 = 1;            /* READY */
  } else {
    download_B.UARTRx2 = 0;            /* Not READY */
  }

  /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem3' incorporates:
   *  EnablePort: '<S14>/Enable'
   */
  if (download_B.UARTRx2 > 0) {
    if (!download_DW.EnabledSubsystem3_MODE) {
      /* Level2 S-Function Block: '<S14>/UART Tx' (stm32f4_usart) */
      enable_fromshangweijiEnabledSubsystem3UARTTx();
      download_DW.EnabledSubsystem3_MODE = true;
    }

    /* fromshangweijiEnabledSubsystem3UARTTx: '<S14>/UART Tx' */
    {
      /* Flush tx, so we can put data directly to DMA buffer */
      UART3_FlushTxBuffer();

      /* Put data into buffer */
      UART3_Tx_Buffer[0] = 214;        /* Header 0 */
      UART3_Tx_Buffer[1] = 109;        /* Header 1 */
      UART3_Tx_Buffer[2] = 21;         /* Header 2 */
      UART3_Tx_Buffer[3] = 21;         /* Header 3 */

      /* Write to DMA, 4 bytes */
      UART3_TxUpdate(4);               /* Only update since data is ready on Tx buffer */
      UART3_FlushTxBuffer();           /* Blocking, wait for DMA buffer */
    }
  } else {
    if (download_DW.EnabledSubsystem3_MODE) {
      download_DW.EnabledSubsystem3_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem3' */
  rate_scheduler();
}

/* Model initialize function */
void download_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)download_M, 0,
                sizeof(RT_MODEL_download_T));

  /* block I/O */
  (void) memset(((void *) &download_B), 0,
                sizeof(B_download_T));

  /* states (dwork) */
  (void) memset((void *)&download_DW, 0,
                sizeof(DW_download_T));

  /* Start for Enabled SubSystem: '<S2>/Angle_hold' */
  download_Angle_hold_Start(&download_DW.Angle_hold, (P_Angle_hold_download_T *)
    &download_P.Angle_hold);

  /* End of Start for SubSystem: '<S2>/Angle_hold' */

  /* Start for If: '<S12>/If' */
  download_DW.If_ActiveSubsystem = -1;

  /* End of Start for SubSystem: '<S1>/Enabled Subsystem1' */

  /* InitializeConditions for MATLAB Function: '<S2>/MATLAB Function' */
  download_DW.status = 0.0;

  /* InitializeConditions for Atomic SubSystem: '<S2>/Velocity_Damper2' */
  /* InitializeConditions for UnitDelay: '<S50>/UD' */
  download_DW.UD_DSTATE = download_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for MATLAB Function: '<S24>/MATLAB Function' */
  download_DW.altitude_basic = 0.0;
  download_DW.count = 0.0;

  /* End of InitializeConditions for SubSystem: '<S2>/Velocity_Damper2' */

  /* Enable for Atomic SubSystem: '<Root>/IMU' */
  download_IMU_Enable();

  /* End of Enable for SubSystem: '<Root>/IMU' */

  /* Level2 S-Function Block: '<S7>/Blue LED' (stm32f4_digital_output) */
  enable_OrangeLED1BlueLED();

  /* Level2 S-Function Block: '<S8>/UART Rx3' (stm32f4_usart) */
  enable_ReceiverUARTRx3();

  /* Level2 S-Function Block: '<S9>/Basic PWM7' (stm32f4_basicpwm) */
  enable_executeBasicPWM7();

  /* Level2 S-Function Block: '<S11>/UART Tx' (stm32f4_usart) */
  enable_toshangweijiUARTTx();

  /* Level2 S-Function Block: '<S11>/UART Tx1' (stm32f4_usart) */
  enable_toshangweijiUARTTx1();

  /* Level2 S-Function Block: '<S1>/UART Rx3' (stm32f4_usart) */
  enable_fromshangweijiUARTRx3();

  /* Level2 S-Function Block: '<S1>/UART Rx4' (stm32f4_usart) */
  enable_fromshangweijiUARTRx4();

  /* Level2 S-Function Block: '<S1>/UART Rx5' (stm32f4_usart) */
  enable_fromshangweijiUARTRx5();

  /* Level2 S-Function Block: '<S1>/UART Rx1' (stm32f4_usart) */
  enable_fromshangweijiUARTRx1();

  /* Level2 S-Function Block: '<S1>/UART Rx' (stm32f4_usart) */
  enable_fromshangweijiUARTRx();

  /* Level2 S-Function Block: '<S1>/UART Rx2' (stm32f4_usart) */
  enable_fromshangweijiUARTRx2();

  /* Level2 S-Function Block: '<S10>/UART Setup' (stm32f4_usart) */
  enable_initUARTSetup();

  /* Level2 S-Function Block: '<S10>/UART Setup1' (stm32f4_usart) */
  enable_initUARTSetup1();

  /* Level2 S-Function Block: '<S10>/UART Setup2' (stm32f4_usart) */
  enable_initUARTSetup2();
}

/* Model terminate function */
void download_terminate(void)
{
  /* Terminate for S-Function (stm32f4_digital_output): '<S7>/Blue LED' */

  /* terminate_OrangeLED1BlueLED(); */

  /* Terminate for S-Function (stm32f4_basicpwm): '<S9>/Basic PWM7' */

  /* terminate_executeBasicPWM7(); */

  /* Terminate for Enabled SubSystem: '<S1>/Enabled Subsystem1' */

  /* Terminate for S-Function (stm32f4_digital_output): '<S12>/Digital Output' */

  /* terminate_fromshangweijiEnabledSubsystem1DigitalOutput(); */

  /* End of Terminate for SubSystem: '<S1>/Enabled Subsystem1' */
}

/* [EOF] */

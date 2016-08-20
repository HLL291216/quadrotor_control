/*
 * File: huamo.c
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model huamo.
 *
 * Model version                        : 1.102
 * Real-Time Workshop file version      : 8.6 (R2014a) 27-Dec-2013
 * Real-Time Workshop file generated on : Mon Jun 13 17:43:24 2016
 * TLC version                          : 8.6 (Jan 30 2014)
 * C/C++ source code generated on       : Mon Jun 13 17:43:26 2016
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "huamo.h"
#include "huamo_private.h"

/* Block signals (auto storage) */
B_huamo_T huamo_B;

/* Block states (auto storage) */
DW_huamo_T huamo_DW;

/* Real-time model */
RT_MODEL_huamo_T huamo_M_;
RT_MODEL_huamo_T *const huamo_M = &huamo_M_;
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
  (huamo_M->Timing.TaskCounters.TID[1])++;
  if ((huamo_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.005s, 0.0s] */
    huamo_M->Timing.TaskCounters.TID[1] = 0;
  }

  (huamo_M->Timing.TaskCounters.TID[2])++;
  if ((huamo_M->Timing.TaskCounters.TID[2]) > 79) {/* Sample time: [0.08s, 0.0s] */
    huamo_M->Timing.TaskCounters.TID[2] = 0;
  }

  (huamo_M->Timing.TaskCounters.TID[3])++;
  if ((huamo_M->Timing.TaskCounters.TID[3]) > 999) {/* Sample time: [1.0s, 0.0s] */
    huamo_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/* Start for enable system: '<S2>/Angle_hold' */
void huamo_Angle_hold_Start(DW_Angle_hold_huamo_T *localDW, P_Angle_hold_huamo_T
  *localP)
{
  /* InitializeConditions for IfAction SubSystem: '<S20>/Subsystem' */
  /* InitializeConditions for MATLAB Function: '<S26>/attitude_control' */
  localDW->x1_1 = 0.0;
  localDW->x2_1 = 0.0;

  /* InitializeConditions for UnitDelay: '<S33>/UD' */
  localDW->UD_DSTATE = localP->DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_DSTATE = localP->DiscreteTimeIntegrator1_IC;
  localDW->DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for MATLAB Function: '<S31>/MATLAB Function' */
  localDW->count = 0.0;

  /* End of InitializeConditions for SubSystem: '<S20>/Subsystem' */
}

/* Outputs for enable system: '<S2>/Angle_hold' */
void huamo_Angle_hold(real_T rtu_Enable, real32_T rtu_Guidance_in, real32_T
                      rtu_Guidance_in_i, real32_T rtu_Guidance_in_l, real32_T
                      rtu_Signal_back, real32_T rtu_Signal_back_o, real32_T
                      rtu_Signal_back_l, real32_T rtu_Signal_back_ob, real32_T
                      rtu_Signal_back_p, real32_T rtu_Signal_back_c, const
                      real32_T rtu_parameter_roll[5], real32_T
                      rtu_Guidance_in_io, const real32_T rtu_alt_back[2],
                      B_Angle_hold_huamo_T *localB, DW_Angle_hold_huamo_T
                      *localDW, P_Angle_hold_huamo_T *localP)
{
  /* local block i/o variables */
  real32_T rtb_Gain5_l[3];
  real32_T rtb_Gain6[3];
  real32_T rtb_Saturation_g;
  real32_T rtb_Saturation_k;
  real_T eroll;
  real_T epitch;
  real_T x1;
  real_T x2;
  static const real_T a[16] = { 0.25, 0.25, 0.25, 0.25, 0.0, -0.5, 0.0, 0.5,
    -0.5, 0.0, 0.5, 0.0, 0.25, -0.25, 0.25, -0.25 };

  static const real_T a_0[16] = { 28461.485917256767, 28461.485917256763,
    28461.485917256767, 28461.485917256763, 0.0, -56922.971834513533,
    6.3197193960766211E-12, 56922.971834513526, -56922.971834513533, 0.0,
    56922.971834513533, 0.0, 333333.33333333331, -333333.33333333331,
    333333.33333333331, -333333.33333333331 };

  real_T rtb_DataTypeConversion8[13];
  real_T rtb_DataTypeConversion_c[4];
  int32_T i;
  real_T a_1[4];
  real_T rtb_out_l_idx_0;
  real_T rtb_out_l_idx_1;
  real32_T rtb_Switch_h_idx_0;
  real32_T rtb_Switch_h_idx_1;
  real32_T rtb_Switch_h_idx_2;
  real32_T rtb_Switch_h_idx_3;

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
      /* Gain: '<S25>/Gain3' */
      rtb_Saturation_g = localP->Gain3_Gain * rtu_Guidance_in_i;

      /* Gain: '<S25>/Gain2' */
      rtb_Saturation_k = localP->Gain2_Gain * rtu_Guidance_in_l;

      /* Gain: '<S25>/Gain5' */
      rtb_Gain5_l[0] = localP->Gain5_Gain * rtu_Signal_back;
      rtb_Gain5_l[1] = localP->Gain5_Gain * rtu_Signal_back_o;
      rtb_Gain5_l[2] = localP->Gain5_Gain * rtu_Signal_back_l;

      /* Gain: '<S25>/Gain6' */
      rtb_Gain6[0] = localP->Gain6_Gain * rtu_Signal_back_ob;
      rtb_Gain6[1] = localP->Gain6_Gain * rtu_Signal_back_p;
      rtb_Gain6[2] = localP->Gain6_Gain * rtu_Signal_back_c;

      /* DataTypeConversion: '<S26>/Data Type Conversion8' */
      rtb_DataTypeConversion8[0] = rtb_Saturation_g;
      rtb_DataTypeConversion8[1] = rtb_Saturation_k;
      rtb_DataTypeConversion8[2] = rtb_Gain5_l[1];
      rtb_DataTypeConversion8[3] = rtb_Gain5_l[0];
      rtb_DataTypeConversion8[4] = rtb_Gain6[1];
      rtb_DataTypeConversion8[5] = rtb_Gain6[0];
      rtb_DataTypeConversion8[6] = rtb_Gain6[2];
      rtb_DataTypeConversion8[7] = rtu_Guidance_in;
      for (i = 0; i < 5; i++) {
        rtb_DataTypeConversion8[i + 8] = rtu_parameter_roll[i];
      }

      /* End of DataTypeConversion: '<S26>/Data Type Conversion8' */

      /* MATLAB Function: '<S26>/attitude_control' */
      /* MATLAB Function 'Controller/Angle_hold/Subsystem/Controller_roll/attitude_control': '<S32>:1' */
      /*  BECAUSE THE PROGRAM IS LICENSED FREE OF CHARGE, THERE IS NO WARRANTY */
      /*  FOR THE PROGRAM, TO THE EXTENT PERMITTED BY APPLICABLE LAW.  EXCEPT WHEN */
      /*  OTHERWISE STATED IN WRITING THE COPYRIGHT HOLDERS AND/OR OTHER PARTIES */
      /*  PROVIDE THE PROGRAM "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED */
      /*  OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF */
      /*  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE ENTIRE RISK AS */
      /*  TO THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH YOU.  SHOULD THE */
      /*  PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY SERVICING, */
      /*  REPAIR OR CORRECTION. */
      /*   */
      /*    12. IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING */
      /*  WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MAY MODIFY AND/OR */
      /*  REDISTRIBUTE THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES, */
      /*  INCLUDING ANY GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING */
      /*  OUT OF THE USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED */
      /*  TO LOSS OF DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY */
      /*  YOU OR THIRD PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER */
      /*  PROGRAMS), EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE */
      /*  POSSIBILITY OF SUCH DAMAGES. */
      /*  Rotations control function */
      /*  INPUT: state, (phi,theta,psi)(ref) */
      /*  OUTPUT: desired prop speeds */
      /*  global file for parameters */
      /* '<S32>:1:40' */
      /* // [kg.m2]     */
      /* // [kg.m2] */
      /* ***** Rotor inertia ****$/ */
      /*  [s] sampling period only used to compute YiA term in dinamica.m */
      /* ***** Arm length ****$/ */
      /* // [m] */
      /* ***** Total mass ****$/ */
      /* // [kg] */
      /*  ********* Operational Conditions ********* */
      /* '<S32>:1:53' */
      /*  desired PITCH angle [rad] */
      /* '<S32>:1:54' */
      /*  desired ROLL angle [rad] */
      /* '<S32>:1:55' */
      /* '<S32>:1:56' */
      /*  [rad] */
      /* '<S32>:1:57' */
      /* '<S32>:1:58' */
      /*  [rad/s] */
      /* '<S32>:1:59' */
      /* '<S32>:1:60' */
      if (rtb_DataTypeConversion8[7] > 0.2) {
        /* '<S32>:1:65' */
        /*  ******************************************************** CONTROL ********************************************************  */
        /*  ********* +滑模参数roll************** */
        /* '<S32>:1:76' */
        /*  ********* + 滑模参数pitch ************** */
        /* '<S32>:1:81' */
        /* '<S32>:1:83' */
        /* '<S32>:1:84' */
        eroll = rtb_DataTypeConversion8[1] - rtb_DataTypeConversion8[3];

        /* '<S32>:1:85' */
        epitch = rtb_DataTypeConversion8[0] - rtb_DataTypeConversion8[2];

        /* '<S32>:1:86' */
        /*  roll error */
        /* '<S32>:1:87' */
        /*  pitch error */
        /* '<S32>:1:89' */
        x1 = eroll * 0.01 + localDW->x1_1;

        /*  integrator */
        /* '<S32>:1:90' */
        x2 = epitch * 0.01 + localDW->x2_1;

        /*  integrator */
        /*  if abs(eroll)>0.17 */
        /*      x1=0; */
        /*  end */
        /*  if abs(epitch)>0.17 */
        /*      x2=0; */
        /*  end */
        if (x1 > 5.0) {
          /* '<S32>:1:97' */
          /* '<S32>:1:98' */
          x1 = 5.0;
        } else {
          if (x1 < -5.0) {
            /* '<S32>:1:99' */
            /* '<S32>:1:100' */
            x1 = -5.0;
          }
        }

        if (x2 > 5.0) {
          /* '<S32>:1:102' */
          /* '<S32>:1:103' */
          x2 = 5.0;
        } else {
          if (x2 < -5.0) {
            /* '<S32>:1:104' */
            /* '<S32>:1:105' */
            x2 = -5.0;
          }
        }

        /*  ********* sliding surface ************** */
        /* '<S32>:1:109' */
        rtb_out_l_idx_1 = (6.5 * eroll + -rtb_DataTypeConversion8[5]) + 17.0 *
          x1;

        /* '<S32>:1:110' */
        rtb_out_l_idx_0 = (6.5 * epitch + -rtb_DataTypeConversion8[4]) + 17.0 *
          x2;

        /*  ********* r2  ************** */
        if (rtb_out_l_idx_1 <= -0.05) {
          /* '<S32>:1:112' */
          /* '<S32>:1:113' */
          rtb_out_l_idx_1 = -0.05;
        } else if (rtb_out_l_idx_1 >= 0.05) {
          /* '<S32>:1:114' */
          /* '<S32>:1:115' */
          rtb_out_l_idx_1 = 0.05;
        } else {
          /* '<S32>:1:117' */
        }

        /*  ********* r3  ************** */
        if (rtb_out_l_idx_0 <= -0.05) {
          /* '<S32>:1:120' */
          /* '<S32>:1:121' */
          rtb_out_l_idx_0 = -0.05;
        } else if (rtb_out_l_idx_0 >= 0.05) {
          /* '<S32>:1:122' */
          /* '<S32>:1:123' */
          rtb_out_l_idx_0 = 0.05;
        } else {
          /* '<S32>:1:125' */
        }

        /*  Coconut controller */
        /* '<S32>:1:130' */
        rtb_out_l_idx_1 = ((34.0 * eroll - 6.5 * rtb_DataTypeConversion8[5]) -
                           -1.1109965057045426 * rtb_DataTypeConversion8[4] *
                           rtb_DataTypeConversion8[6]) * 0.040953448275862066 +
          0.095012 * rtb_out_l_idx_1;

        /* '<S32>:1:131' */
        rtb_out_l_idx_0 = ((34.0 * epitch - 6.5 * rtb_DataTypeConversion8[4]) -
                           1.1109965057045426 * rtb_DataTypeConversion8[5] *
                           rtb_DataTypeConversion8[6]) * 0.040953448275862066 +
          0.095012 * rtb_out_l_idx_0;

        /*  update integrator */
        /* '<S32>:1:133' */
        localDW->x1_1 = x1;

        /* '<S32>:1:134' */
        localDW->x2_1 = x2;
      } else {
        /* '<S32>:1:136' */
        localDW->x1_1 = 0.0;

        /* '<S32>:1:137' */
        localDW->x2_1 = 0.0;

        /* '<S32>:1:138' */
        rtb_out_l_idx_0 = 0.0;

        /* '<S32>:1:139' */
        rtb_out_l_idx_1 = 0.0;
      }

      /* End of MATLAB Function: '<S26>/attitude_control' */

      /* MATLAB Function: '<S27>/MATLAB Function' */
      /*  Outputs */
      /* '<S32>:1:142' */
      /* MATLAB Function 'Controller/Angle_hold/Subsystem/Controller_yaw/MATLAB Function': '<S34>:1' */
      /* '<S34>:1:3' */
      eroll = 1.0;
      if (rtu_Guidance_in > 0.3) {
        /* '<S34>:1:4' */
        /* if thrust>20%,enable integrator */
        /* '<S34>:1:5' */
        eroll = 0.0;
      } else {
        if (0.0 < 5.0) {
          /* '<S34>:1:6' */
          /* if delta angle<5,enable integrator */
          /* '<S34>:1:7' */
          eroll = 0.0;
        }
      }

      /* End of MATLAB Function: '<S27>/MATLAB Function' */

      /* Sum: '<S27>/Sum1' incorporates:
       *  Constant: '<S27>/P'
       *  Constant: '<S27>/status'
       *  Gain: '<S25>/Gain4'
       *  Product: '<S27>/Product1'
       *  Product: '<S27>/Product3'
       *  Sum: '<S27>/Sum'
       */
      epitch = (real_T)((localP->Gain4_Gain * rtu_Guidance_in_io - rtb_Gain5_l[2]
                         * localP->status_Value) * localP->P_Value) - rtb_Gain6
        [2];

      /* SampleTimeMath: '<S33>/TSamp'
       *
       * About '<S33>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      x1 = epitch * localP->TSamp_WtEt;

      /* DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' incorporates:
       *  DataTypeConversion: '<S27>/Data Type Conversion'
       */
      if (((real32_T)eroll != 0.0F) || (localDW->DiscreteTimeIntegrator1_PrevRes
           != 0)) {
        localDW->DiscreteTimeIntegrator1_DSTATE =
          localP->DiscreteTimeIntegrator1_IC;
      }

      if (localDW->DiscreteTimeIntegrator1_DSTATE >=
          localP->DiscreteTimeIntegrator1_UpperSa) {
        localDW->DiscreteTimeIntegrator1_DSTATE =
          localP->DiscreteTimeIntegrator1_UpperSa;
      } else {
        if (localDW->DiscreteTimeIntegrator1_DSTATE <=
            localP->DiscreteTimeIntegrator1_LowerSa) {
          localDW->DiscreteTimeIntegrator1_DSTATE =
            localP->DiscreteTimeIntegrator1_LowerSa;
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
       *  Sum: '<S33>/Diff'
       *  UnitDelay: '<S33>/UD'
       */
      rtb_Saturation_k = (real32_T)((((x1 - localDW->UD_DSTATE) *
        localP->nD_Value + localP->nP_Value * epitch) +
        localDW->DiscreteTimeIntegrator1_DSTATE * localP->nI_Value) *
        localP->Gain_Gain);

      /* Saturate: '<S27>/Saturation' */
      if (rtb_Saturation_k > localP->Saturation_UpperSat_c) {
        rtb_Saturation_k = localP->Saturation_UpperSat_c;
      } else {
        if (rtb_Saturation_k < localP->Saturation_LowerSat_o) {
          rtb_Saturation_k = localP->Saturation_LowerSat_o;
        }
      }

      /* End of Saturate: '<S27>/Saturation' */

      /* MATLAB Function: '<S31>/MATLAB Function' incorporates:
       *  DataTypeConversion: '<S31>/Data Type Conversion2'
       *  DataTypeConversion: '<S31>/Data Type Conversion3'
       */
      /* MATLAB Function 'Controller/Angle_hold/Subsystem/alt_control/MATLAB Function': '<S35>:1' */
      if ((rtu_Guidance_in > 0.35) && (rtu_Guidance_in < 0.45) &&
          (localDW->count == 0.0)) {
        /* '<S35>:1:10' */
        /* '<S35>:1:11' */
        x2 = rtu_alt_back[0];

        /* '<S35>:1:12' */
        localDW->count = 1.0;
      } else if ((rtu_Guidance_in <= 0.35) && (localDW->count == 1.0)) {
        /* '<S35>:1:13' */
        /* '<S35>:1:14' */
        localDW->count = 0.0;

        /* '<S35>:1:15' */
        x2 = 0.0;
      } else if ((rtu_Guidance_in >= 0.45) && (localDW->count == 1.0)) {
        /* '<S35>:1:16' */
        /* '<S35>:1:17' */
        localDW->count = 0.0;

        /* '<S35>:1:18' */
        x2 = 0.0;
      } else {
        /* '<S35>:1:20' */
        localDW->count = 0.0;

        /* '<S35>:1:21' */
        x2 = 0.0;
      }

      /* Outputs for Enabled SubSystem: '<S31>/Subsystem' incorporates:
       *  EnablePort: '<S36>/Enable'
       */
      /* '<S35>:1:23' */
      /* '<S35>:1:24' */
      if ((real32_T)localDW->count > 0.0F) {
        /* Product: '<S36>/Product2' incorporates:
         *  Constant: '<S31>/Constant2'
         */
        rtb_Switch_h_idx_0 = rtu_alt_back[1] * localP->Constant2_Value;

        /* Saturate: '<S36>/Saturation1' */
        if (rtb_Switch_h_idx_0 > localP->Saturation1_UpperSat_c) {
          rtb_Switch_h_idx_0 = localP->Saturation1_UpperSat_c;
        } else {
          if (rtb_Switch_h_idx_0 < localP->Saturation1_LowerSat_e) {
            rtb_Switch_h_idx_0 = localP->Saturation1_LowerSat_e;
          }
        }

        /* Product: '<S36>/Divide' incorporates:
         *  Constant: '<S31>/Constant3'
         *  Constant: '<S36>/Constant'
         *  Constant: '<S36>/Constant1'
         *  DataTypeConversion: '<S31>/Data Type Conversion'
         *  Fcn: '<S36>/Fcn'
         *  Product: '<S36>/Product1'
         *  Product: '<S36>/Product4'
         *  Saturate: '<S36>/Saturation1'
         *  Sum: '<S36>/Sum'
         *  Sum: '<S36>/Sum1'
         *  Sum: '<S36>/Sum2'
         */
        localB->Divide = (real32_T)((((real_T)(((real32_T)x2 - rtu_alt_back[0]) *
          localP->Constant3_Value) - rtb_Switch_h_idx_0) +
          localP->Constant_Value) * localP->Constant1_Value_e / ((real32_T)cos
          (rtb_Gain5_l[0]) * (real32_T)cos(rtb_Gain5_l[1])));
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
        rtb_Saturation_g = localB->Divide;
      } else {
        /* Product: '<S31>/Product2' incorporates:
         *  Constant: '<S31>/D'
         */
        rtb_Switch_h_idx_0 = rtu_alt_back[1] * localP->D_Value;

        /* Saturate: '<S31>/Saturation1' */
        if (rtb_Switch_h_idx_0 > localP->Saturation1_UpperSat) {
          rtb_Switch_h_idx_0 = localP->Saturation1_UpperSat;
        } else {
          if (rtb_Switch_h_idx_0 < localP->Saturation1_LowerSat) {
            rtb_Switch_h_idx_0 = localP->Saturation1_LowerSat;
          }
        }

        rtb_Saturation_g = (rtu_Guidance_in - localP->Constant1_Value) *
          localP->Gain7_Gain - rtb_Switch_h_idx_0;
      }

      /* End of Switch: '<S31>/Switch' */

      /* Saturate: '<S31>/Saturation' */
      if (rtb_Saturation_g > localP->Saturation_UpperSat_g) {
        rtb_Saturation_g = localP->Saturation_UpperSat_g;
      } else {
        if (rtb_Saturation_g < localP->Saturation_LowerSat_n) {
          rtb_Saturation_g = localP->Saturation_LowerSat_n;
        }
      }

      /* End of Saturate: '<S31>/Saturation' */

      /* Saturate: '<S26>/Saturation' incorporates:
       *  DataTypeConversion: '<S26>/Data Type Conversion'
       */
      if ((real32_T)rtb_out_l_idx_1 > localP->Saturation_UpperSat_m) {
        rtb_Switch_h_idx_0 = localP->Saturation_UpperSat_m;
      } else if ((real32_T)rtb_out_l_idx_1 < localP->Saturation_LowerSat_i) {
        rtb_Switch_h_idx_0 = localP->Saturation_LowerSat_i;
      } else {
        rtb_Switch_h_idx_0 = (real32_T)rtb_out_l_idx_1;
      }

      /* MATLAB Function 'Controller/Angle_hold/Subsystem/MATLAB Function2': '<S30>:1' */
      /*  b= 8.7838E-6;       % [N.s2] thrust factor in hover */
      /*  d= 7.5E-7;         % [Nm.s2] drag factor in hover */
      /* '<S30>:1:6' */
      /* '<S30>:1:7' */
      /* '<S30>:1:8' */
      if ((real32_T)rtb_out_l_idx_0 > localP->Saturation_UpperSat_m) {
        /* MATLAB Function: '<S25>/MATLAB Function2' */
        rtb_out_l_idx_0 = localP->Saturation_UpperSat_m;
      } else if ((real32_T)rtb_out_l_idx_0 < localP->Saturation_LowerSat_i) {
        /* MATLAB Function: '<S25>/MATLAB Function2' */
        rtb_out_l_idx_0 = localP->Saturation_LowerSat_i;
      } else {
        /* MATLAB Function: '<S25>/MATLAB Function2' */
        rtb_out_l_idx_0 = (real32_T)rtb_out_l_idx_0;
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
        rtb_out_l_idx_1 = a_0[i + 12] * rtb_Saturation_k + (a_0[i + 8] * 0.0 +
          (a_0[i + 4] * 0.0 + a_0[i] * rtb_Saturation_g));
        a_1[i] = rtb_out_l_idx_1;
      }

      /* Saturate: '<S25>/Saturation' incorporates:
       *  MATLAB Function: '<S25>/MATLAB Function'
       */
      if (a_1[0] > localP->Saturation_UpperSat) {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[0] = localP->Saturation_UpperSat;
      } else if (a_1[0] < localP->Saturation_LowerSat) {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[0] = localP->Saturation_LowerSat;
      } else {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[0] = a_1[0];
      }

      if (a_1[1] > localP->Saturation_UpperSat) {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[1] = localP->Saturation_UpperSat;
      } else if (a_1[1] < localP->Saturation_LowerSat) {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[1] = localP->Saturation_LowerSat;
      } else {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[1] = a_1[1];
      }

      if (a_1[2] > localP->Saturation_UpperSat) {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[2] = localP->Saturation_UpperSat;
      } else if (a_1[2] < localP->Saturation_LowerSat) {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[2] = localP->Saturation_LowerSat;
      } else {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[2] = a_1[2];
      }

      if (a_1[3] > localP->Saturation_UpperSat) {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[3] = localP->Saturation_UpperSat;
      } else if (a_1[3] < localP->Saturation_LowerSat) {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[3] = localP->Saturation_LowerSat;
      } else {
        /* MATLAB Function: '<S25>/MATLAB Function1' */
        rtb_DataTypeConversion_c[3] = a_1[3];
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
        localB->DataTypeConversion1[i] = (real32_T)((((a[i + 4] *
          rtb_out_l_idx_0 + a[i] * 0.0) + a[i + 8] * rtb_Switch_h_idx_0) + a[i +
          12] * 0.0) / 2.0 + rtb_DataTypeConversion_c[i]);
      }

      /* End of DataTypeConversion: '<S25>/Data Type Conversion1' */

      /* Update for UnitDelay: '<S33>/UD' */
      localDW->UD_DSTATE = x1;

      /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' incorporates:
       *  DataTypeConversion: '<S27>/Data Type Conversion'
       */
      if ((real32_T)eroll == 0.0F) {
        localDW->DiscreteTimeIntegrator1_DSTATE +=
          localP->DiscreteTimeIntegrator1_gainval * epitch;
        if (localDW->DiscreteTimeIntegrator1_DSTATE >=
            localP->DiscreteTimeIntegrator1_UpperSa) {
          localDW->DiscreteTimeIntegrator1_DSTATE =
            localP->DiscreteTimeIntegrator1_UpperSa;
        } else {
          if (localDW->DiscreteTimeIntegrator1_DSTATE <=
              localP->DiscreteTimeIntegrator1_LowerSa) {
            localDW->DiscreteTimeIntegrator1_DSTATE =
              localP->DiscreteTimeIntegrator1_LowerSa;
          }
        }
      }

      if ((real32_T)eroll > 0.0F) {
        localDW->DiscreteTimeIntegrator1_PrevRes = 1;
      } else {
        localDW->DiscreteTimeIntegrator1_PrevRes = 0;
      }

      /* End of Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' */
      /* End of Outputs for SubSystem: '<S20>/Subsystem' */
    }

    /* End of If: '<S20>/If' */

    /* Switch: '<S20>/Switch' incorporates:
     *  Gain: '<S20>/Gain'
     */
    if (rtu_Guidance_in > localP->Switch_Threshold_f) {
      rtb_Switch_h_idx_0 = localB->DataTypeConversion1[0];
      rtb_Switch_h_idx_1 = localB->DataTypeConversion1[1];
      rtb_Switch_h_idx_2 = localB->DataTypeConversion1[2];
      rtb_Switch_h_idx_3 = localB->DataTypeConversion1[3];
    } else {
      rtb_Switch_h_idx_0 = localP->Gain_Gain_j[0] * rtu_Guidance_in;
      rtb_Switch_h_idx_1 = localP->Gain_Gain_j[1] * rtu_Guidance_in;
      rtb_Switch_h_idx_2 = localP->Gain_Gain_j[2] * rtu_Guidance_in;
      rtb_Switch_h_idx_3 = localP->Gain_Gain_j[3] * rtu_Guidance_in;
    }

    /* End of Switch: '<S20>/Switch' */

    /* Sum: '<S20>/Sum' incorporates:
     *  Constant: '<S20>/Constant1'
     */
    localB->Sum[0] = rtb_Switch_h_idx_0 + localP->Constant1_Value_h[0];
    localB->Sum[1] = rtb_Switch_h_idx_1 + localP->Constant1_Value_h[1];
    localB->Sum[2] = rtb_Switch_h_idx_2 + localP->Constant1_Value_h[2];
    localB->Sum[3] = rtb_Switch_h_idx_3 + localP->Constant1_Value_h[3];
  }

  /* End of Outputs for SubSystem: '<S2>/Angle_hold' */
}

/*
 * Output and update for atomic system:
 *    '<S68>/MATLAB Function2'
 *    '<S68>/MATLAB Function4'
 */
void huamo_MATLABFunction2(real_T rtu_u, B_MATLABFunction2_huamo_T *localB)
{
  real_T y;

  /* MATLAB Function 'Receiver/Enabled Subsystem/MATLAB Function2': '<S70>:1' */
  /* 输入范围为0.34~1.7，将其调整到1~2ms */
  /* '<S70>:1:4' */
  y = rtu_u / 1.375;
  if ((y + 0.76 > 0.8) && (y + 0.76 < 2.1)) {
    /* '<S70>:1:5' */
    /* '<S70>:1:6' */
    localB->y = y + 0.76;
  } else {
    /* '<S70>:1:8' */
    localB->y = 1.5;
  }
}

/* Model step function */
void huamo_step(void)
{
  /* local block i/o variables */
  real_T rtb_Gain1;
  real_T rtb_Gain3;
  real32_T rtb_TmpSignalConversionAtAngle_[5];
  real32_T rtb_TmpSignalConversionAtAngl_p[2];
  real32_T stageIn;
  uint16_T rtb_Add3;
  real_T rtb_y_n;
  real32_T rtb_TSamp;
  int8_T rtPrevAction;
  int8_T rtAction;
  uint16_T rtb_ShiftArithmetic3_h;
  uint16_T rtb_ShiftArithmetic4_f;
  uint16_T rtb_ShiftArithmetic5_b;
  if (huamo_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Atomic SubSystem: '<Root>/IMU' */
    huamo_IMU();

    /* End of Outputs for SubSystem: '<Root>/IMU' */

    /* S-Function (stm32f4_digital_output): '<S7>/Blue LED' */

    /* OrangeLED1BlueLED */
    *OrangeLED1BlueLED_C2 = (boolean_T) huamo_B.angle_o1;

    /* ReceiverUARTRx3: '<S8>/UART Rx3' */
    if (ReceiverUARTRx3_Receive(&UART2_Temp_Buffer[0], 23)) {/* Non-blocking */
      memcpy(&huamo_B.UARTRx3_o2_j[0], &UART2_Temp_Buffer[0], 23*sizeof(uint8_T));/* D0 [23] */
      huamo_B.UARTRx3_o1 = 1;          /* READY */
    } else {
      huamo_B.UARTRx3_o1 = 0;          /* Not READY */
    }

    /* Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S68>/Enable'
     */
    if (huamo_B.UARTRx3_o1 > 0) {
      /* ArithShift: '<S68>/Shift Arithmetic3' incorporates:
       *  DataTypeConversion: '<S68>/Data Type Conversion5'
       */
      rtb_ShiftArithmetic3_h = (uint16_T)(huamo_B.UARTRx3_o2_j[2] >> 6);

      /* ArithShift: '<S68>/Shift Arithmetic4' incorporates:
       *  DataTypeConversion: '<S68>/Data Type Conversion6'
       */
      rtb_ShiftArithmetic4_f = (uint16_T)(huamo_B.UARTRx3_o2_j[3] << 2);

      /* ArithShift: '<S68>/Shift Arithmetic5' incorporates:
       *  S-Function (sfix_bitop): '<S68>/Bitwise Operator7'
       */
      rtb_ShiftArithmetic5_b = (uint16_T)((uint16_T)(huamo_B.UARTRx3_o2_j[4] &
        huamo_P.BitwiseOperator7_BitMask) << 10);

      /* Sum: '<S68>/Add3' incorporates:
       *  ArithShift: '<S68>/Shift Arithmetic6'
       *  ArithShift: '<S68>/Shift Arithmetic7'
       *  S-Function (sfix_bitop): '<S68>/Bitwise Operator1'
       *  S-Function (sfix_bitop): '<S68>/Bitwise Operator2'
       */
      rtb_Add3 = (uint16_T)((uint32_T)((huamo_B.UARTRx3_o2_j[4] &
        huamo_P.BitwiseOperator1_BitMask_a) >> 1) + ((huamo_B.UARTRx3_o2_j[5] &
        huamo_P.BitwiseOperator2_BitMask_n) << 7));

      /* MATLAB Function: '<S68>/MATLAB Function1' incorporates:
       *  ArithShift: '<S68>/Shift Arithmetic'
       *  DataTypeConversion: '<S68>/Data Type Conversion4'
       *  DataTypeConversion: '<S68>/Data Type Conversion8'
       *  Gain: '<S68>/Gain'
       *  S-Function (sfix_bitop): '<S68>/Bitwise Operator5'
       *  Sum: '<S68>/Add'
       */
      /* MATLAB Function 'Receiver/Enabled Subsystem/MATLAB Function1': '<S69>:1' */
      /* 输入范围为0.34~1.7，将其调整到1~2ms */
      /* '<S69>:1:4' */
      rtb_y_n = (real_T)((uint32_T)((huamo_B.UARTRx3_o2_j[1] &
        huamo_P.BitwiseOperator5_BitMask) << 8) + huamo_B.UARTRx3_o2_j[0]) *
        huamo_P.Gain_Gain / 1.375;
      if ((rtb_y_n + 0.76 > 0.8) && (rtb_y_n + 0.76 < 2.1)) {
        /* '<S69>:1:5' */
        /* '<S69>:1:6' */
        rtb_y_n += 0.76;
      } else {
        /* '<S69>:1:8' */
        rtb_y_n = 1.5;
      }

      /* End of MATLAB Function: '<S68>/MATLAB Function1' */

      /* DataTypeConversion: '<S68>/Data Type Conversion' */
      huamo_B.CH1 = (real32_T)rtb_y_n;

      /* Gain: '<S68>/Gain1' incorporates:
       *  ArithShift: '<S68>/Shift Arithmetic1'
       *  ArithShift: '<S68>/Shift Arithmetic2'
       *  DataTypeConversion: '<S68>/Data Type Conversion1'
       *  DataTypeConversion: '<S68>/Data Type Conversion9'
       *  S-Function (sfix_bitop): '<S68>/Bitwise Operator6'
       *  Sum: '<S68>/Add1'
       */
      rtb_Gain1 = (real_T)((uint32_T)((huamo_B.UARTRx3_o2_j[2] &
        huamo_P.BitwiseOperator6_BitMask) << 5) + (huamo_B.UARTRx3_o2_j[1] >> 3))
        * huamo_P.Gain1_Gain;

      /* MATLAB Function: '<S68>/MATLAB Function2' */
      huamo_MATLABFunction2(rtb_Gain1, &huamo_B.sf_MATLABFunction2);

      /* DataTypeConversion: '<S68>/Data Type Conversion11' */
      huamo_B.CH2 = (real32_T)huamo_B.sf_MATLABFunction2.y;

      /* MATLAB Function: '<S68>/MATLAB Function3' incorporates:
       *  DataTypeConversion: '<S68>/Data Type Conversion10'
       *  Gain: '<S68>/Gain2'
       *  Sum: '<S68>/Add2'
       */
      /* MATLAB Function 'Receiver/Enabled Subsystem/MATLAB Function3': '<S71>:1' */
      /* 输入范围为0.34~1.7，将其调整到1~2ms */
      /* '<S71>:1:4' */
      rtb_y_n = (real_T)(uint16_T)(((uint32_T)rtb_ShiftArithmetic3_h +
        rtb_ShiftArithmetic4_f) + rtb_ShiftArithmetic5_b) * huamo_P.Gain2_Gain /
        1.375;
      if ((rtb_y_n + 0.75 > 1.0) && (rtb_y_n + 0.75 < 2.1)) {
        /* '<S71>:1:5' */
        /* '<S71>:1:6' */
        rtb_y_n += 0.75;
      } else {
        /* '<S71>:1:8' */
        rtb_y_n = 1.0;
      }

      /* End of MATLAB Function: '<S68>/MATLAB Function3' */

      /* DataTypeConversion: '<S68>/Data Type Conversion12' */
      huamo_B.CH3 = (real32_T)rtb_y_n;

      /* Gain: '<S68>/Gain3' incorporates:
       *  DataTypeConversion: '<S68>/Data Type Conversion15'
       */
      rtb_Gain3 = huamo_P.Gain3_Gain * (real_T)rtb_Add3;

      /* MATLAB Function: '<S68>/MATLAB Function4' */
      huamo_MATLABFunction2(rtb_Gain3, &huamo_B.sf_MATLABFunction4);

      /* DataTypeConversion: '<S68>/Data Type Conversion16' */
      huamo_B.CH4 = (real32_T)huamo_B.sf_MATLABFunction4.y;
    }

    /* End of Outputs for SubSystem: '<S8>/Enabled Subsystem' */

    /* Outputs for Atomic SubSystem: '<Root>/Guidance_System' */
    huamo_Guidance_System(huamo_B.CH3, huamo_B.CH4, huamo_B.CH2, huamo_B.CH1,
                          &huamo_B.Guidance_System, (P_Guidance_System_huamo_T *)
                          &huamo_P.Guidance_System);

    /* End of Outputs for SubSystem: '<Root>/Guidance_System' */

    /* fromshangweijiUARTRx3: '<S1>/UART Rx3' */
    if (fromshangweijiUARTRx3_Receive(&UART1_Temp_Buffer[0], URX1_BUFFER_SIZE))
    {                                  /* Non-Blocking */
      huamo_B.UARTRx3_o2 = fromshangweijiUARTRx3_data0;/* D0 */
      huamo_B.UARTRx3_o3 = fromshangweijiUARTRx3_data1;/* D1 */
      huamo_B.UARTRx3_o4 = fromshangweijiUARTRx3_data2;/* D2 */
      huamo_B.UARTRx3_o5 = fromshangweijiUARTRx3_data3;/* D3 */
      huamo_B.UARTRx3_o6 = fromshangweijiUARTRx3_data4;/* D4 */
      huamo_B.UARTRx3_o1_o = 1;        /* READY */
    } else {
      huamo_B.UARTRx3_o1_o = 0;        /* Not READY */
    }

    /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem4' incorporates:
     *  EnablePort: '<S15>/Enable'
     */
    if (huamo_B.UARTRx3_o1_o > 0) {
      if (!huamo_DW.EnabledSubsystem4_MODE) {
        /* Level2 S-Function Block: '<S15>/UART Tx' (stm32f4_usart) */
        enable_fromshangweijiEnabledSubsystem4UARTTx();
        huamo_DW.EnabledSubsystem4_MODE = true;
      }

      /* fromshangweijiEnabledSubsystem4UARTTx: '<S15>/UART Tx' */
      {
        UART1_FlushTxBuffer();         /* Flush tx, so we can print to DMA buffer directly */
        sprintf((char*)UART1_Tx_Buffer, "roll_change_OK\r\n" );
        UART1_TxUpdate(strlen((char*)UART1_Tx_Buffer));
      }

      /* Inport: '<S15>/P' */
      huamo_B.P_e = huamo_B.UARTRx3_o2;

      /* Inport: '<S15>/nP' */
      huamo_B.nP_i = huamo_B.UARTRx3_o3;

      /* Inport: '<S15>/nI' */
      huamo_B.nI_e = huamo_B.UARTRx3_o4;

      /* Inport: '<S15>/nD' */
      huamo_B.nD_l = huamo_B.UARTRx3_o5;

      /* Inport: '<S15>/status' */
      huamo_B.status_o = huamo_B.UARTRx3_o6;
    } else {
      if (huamo_DW.EnabledSubsystem4_MODE) {
        huamo_DW.EnabledSubsystem4_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem4' */

    /* SignalConversion: '<S2>/TmpSignal ConversionAtAngle_holdInport3' */
    rtb_TmpSignalConversionAtAngle_[0] = huamo_B.P_e;
    rtb_TmpSignalConversionAtAngle_[1] = huamo_B.nP_i;
    rtb_TmpSignalConversionAtAngle_[2] = huamo_B.nI_e;
    rtb_TmpSignalConversionAtAngle_[3] = huamo_B.nD_l;
    rtb_TmpSignalConversionAtAngle_[4] = huamo_B.status_o;

    /* MATLAB Function: '<S2>/MATLAB Function' */
    /* MATLAB Function 'Controller/MATLAB Function': '<S21>:1' */
    if ((huamo_B.Guidance_System.Saturation < 0.1) &&
        (huamo_B.Guidance_System.Saturation_d < -160.0F)) {
      /* '<S21>:1:7' */
      /* '<S21>:1:8' */
      huamo_DW.status = 1.0;
    } else {
      if ((huamo_B.Guidance_System.Saturation < 0.1) &&
          (huamo_B.Guidance_System.Saturation_d > 160.0F)) {
        /* '<S21>:1:9' */
        /* '<S21>:1:10' */
        huamo_DW.status = 0.0;
      }
    }

    /* Outputs for Atomic SubSystem: '<S2>/Velocity_Damper2' */
    /* SampleTimeMath: '<S49>/TSamp'
     *
     * About '<S49>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    /* '<S21>:1:12' */
    rtb_TSamp = huamo_B.Gain6 * huamo_P.TSamp_WtEt;

    /* S-Function (sdspbiquad): '<S50>/Generated Filter Block' incorporates:
     *  Sum: '<S49>/Diff'
     *  UnitDelay: '<S49>/UD'
     */
    stageIn = ((rtb_TSamp - huamo_DW.UD_DSTATE) * 0.0138937552F - -1.82657754F *
               huamo_DW.GeneratedFilterBlock_FILT_STA_f[0]) - 0.840471447F *
      huamo_DW.GeneratedFilterBlock_FILT_STA_f[1];
    huamo_B.GeneratedFilterBlock_b = (0.315986633F * stageIn + 0.368038207F *
      huamo_DW.GeneratedFilterBlock_FILT_STA_f[0]) + 0.315986633F *
      huamo_DW.GeneratedFilterBlock_FILT_STA_f[1];
    huamo_DW.GeneratedFilterBlock_FILT_STA_f[1] =
      huamo_DW.GeneratedFilterBlock_FILT_STA_f[0];
    huamo_DW.GeneratedFilterBlock_FILT_STA_f[0] = stageIn;

    /* MATLAB Function: '<S24>/MATLAB Function' incorporates:
     *  DataTypeConversion: '<S24>/Data Type Conversion3'
     *  MATLAB Function: '<S2>/MATLAB Function'
     */
    /* MATLAB Function 'Controller/Velocity_Damper2/MATLAB Function': '<S48>:1' */
    if ((huamo_DW.status == 1.0) && (huamo_DW.count == 0.0)) {
      /* '<S48>:1:10' */
      /* '<S48>:1:11' */
      huamo_DW.count = 1.0;

      /* '<S48>:1:12' */
      huamo_DW.altitude_basic = huamo_B.Gain6;
    } else {
      if ((huamo_DW.status == 0.0) && (huamo_DW.count == 1.0)) {
        /* '<S48>:1:13' */
        /* '<S48>:1:14' */
        huamo_DW.count = 0.0;
      }
    }

    /* S-Function (sdspbiquad): '<S47>/Generated Filter Block' incorporates:
     *  DataTypeConversion: '<S24>/Data Type Conversion3'
     *  MATLAB Function: '<S24>/MATLAB Function'
     */
    /* '<S48>:1:16' */
    rtb_y_n = ((huamo_B.Gain6 - huamo_DW.altitude_basic) * 0.013893755370815749
               - -1.8265775363780477 * huamo_DW.GeneratedFilterBlock_FILT_STATE
               [0]) - 0.840471451002894 *
      huamo_DW.GeneratedFilterBlock_FILT_STATE[1];
    huamo_B.GeneratedFilterBlock = (0.31598662750883372 * rtb_y_n +
      0.368038207256305 * huamo_DW.GeneratedFilterBlock_FILT_STATE[0]) +
      0.31598662750883377 * huamo_DW.GeneratedFilterBlock_FILT_STATE[1];
    huamo_DW.GeneratedFilterBlock_FILT_STATE[1] =
      huamo_DW.GeneratedFilterBlock_FILT_STATE[0];
    huamo_DW.GeneratedFilterBlock_FILT_STATE[0] = rtb_y_n;

    /* Update for UnitDelay: '<S49>/UD' */
    huamo_DW.UD_DSTATE = rtb_TSamp;

    /* SignalConversion: '<S2>/TmpSignal ConversionAtAngle_holdInport6' incorporates:
     *  DataTypeConversion: '<S24>/Data Type Conversion1'
     */
    rtb_TmpSignalConversionAtAngl_p[0] = (real32_T)huamo_B.GeneratedFilterBlock;

    /* Saturate: '<S46>/Saturation' */
    if (huamo_B.GeneratedFilterBlock_b > huamo_P.Saturation_UpperSat) {
      /* SignalConversion: '<S2>/TmpSignal ConversionAtAngle_holdInport6' */
      rtb_TmpSignalConversionAtAngl_p[1] = huamo_P.Saturation_UpperSat;
    } else if (huamo_B.GeneratedFilterBlock_b < huamo_P.Saturation_LowerSat) {
      /* SignalConversion: '<S2>/TmpSignal ConversionAtAngle_holdInport6' */
      rtb_TmpSignalConversionAtAngl_p[1] = huamo_P.Saturation_LowerSat;
    } else {
      /* SignalConversion: '<S2>/TmpSignal ConversionAtAngle_holdInport6' */
      rtb_TmpSignalConversionAtAngl_p[1] = huamo_B.GeneratedFilterBlock_b;
    }

    /* End of Saturate: '<S46>/Saturation' */
    /* End of Outputs for SubSystem: '<S2>/Velocity_Damper2' */

    /* SignalConversion: '<S2>/HiddenBuf_InsertedFor_Angle_hold_at_inport_6' incorporates:
     *  MATLAB Function: '<S2>/MATLAB Function'
     */
    huamo_B.HiddenBuf_InsertedFor_Angle_hol = huamo_DW.status;

    /* Outputs for Enabled SubSystem: '<S2>/Angle_hold' */
    huamo_Angle_hold(huamo_B.HiddenBuf_InsertedFor_Angle_hol,
                     huamo_B.Guidance_System.Saturation,
                     huamo_B.Guidance_System.Saturation_a,
                     huamo_B.Guidance_System.Saturation_b, huamo_B.Gain2_e,
                     huamo_B.Gain1, huamo_B.Gain2, huamo_B.Gain3_b,
                     huamo_B.Gain3, huamo_B.Gain4,
                     rtb_TmpSignalConversionAtAngle_,
                     huamo_B.Guidance_System.Saturation_d,
                     rtb_TmpSignalConversionAtAngl_p, &huamo_B.Angle_hold,
                     &huamo_DW.Angle_hold, (P_Angle_hold_huamo_T *)
                     &huamo_P.Angle_hold);

    /* End of Outputs for SubSystem: '<S2>/Angle_hold' */

    /* Saturate: '<S9>/Saturation' */
    if (huamo_B.Angle_hold.Sum[0] > huamo_P.Saturation_UpperSat_b) {
      rtb_TSamp = huamo_P.Saturation_UpperSat_b;
    } else if (huamo_B.Angle_hold.Sum[0] < huamo_P.Saturation_LowerSat_h) {
      rtb_TSamp = huamo_P.Saturation_LowerSat_h;
    } else {
      rtb_TSamp = huamo_B.Angle_hold.Sum[0];
    }

    /* Gain: '<S9>/Gain' incorporates:
     *  Saturate: '<S9>/Saturation'
     */
    huamo_B.Gain[0] = huamo_P.Gain_Gain_a * rtb_TSamp;

    /* Saturate: '<S9>/Saturation' */
    if (huamo_B.Angle_hold.Sum[1] > huamo_P.Saturation_UpperSat_b) {
      rtb_TSamp = huamo_P.Saturation_UpperSat_b;
    } else if (huamo_B.Angle_hold.Sum[1] < huamo_P.Saturation_LowerSat_h) {
      rtb_TSamp = huamo_P.Saturation_LowerSat_h;
    } else {
      rtb_TSamp = huamo_B.Angle_hold.Sum[1];
    }

    /* Gain: '<S9>/Gain' incorporates:
     *  Saturate: '<S9>/Saturation'
     */
    huamo_B.Gain[1] = huamo_P.Gain_Gain_a * rtb_TSamp;

    /* Saturate: '<S9>/Saturation' */
    if (huamo_B.Angle_hold.Sum[2] > huamo_P.Saturation_UpperSat_b) {
      rtb_TSamp = huamo_P.Saturation_UpperSat_b;
    } else if (huamo_B.Angle_hold.Sum[2] < huamo_P.Saturation_LowerSat_h) {
      rtb_TSamp = huamo_P.Saturation_LowerSat_h;
    } else {
      rtb_TSamp = huamo_B.Angle_hold.Sum[2];
    }

    /* Gain: '<S9>/Gain' incorporates:
     *  Saturate: '<S9>/Saturation'
     */
    huamo_B.Gain[2] = huamo_P.Gain_Gain_a * rtb_TSamp;

    /* Saturate: '<S9>/Saturation' */
    if (huamo_B.Angle_hold.Sum[3] > huamo_P.Saturation_UpperSat_b) {
      rtb_TSamp = huamo_P.Saturation_UpperSat_b;
    } else if (huamo_B.Angle_hold.Sum[3] < huamo_P.Saturation_LowerSat_h) {
      rtb_TSamp = huamo_P.Saturation_LowerSat_h;
    } else {
      rtb_TSamp = huamo_B.Angle_hold.Sum[3];
    }

    /* Gain: '<S9>/Gain' incorporates:
     *  Saturate: '<S9>/Saturation'
     */
    huamo_B.Gain[3] = huamo_P.Gain_Gain_a * rtb_TSamp;

    /* S-Function Block: <S9>/Basic PWM7 (stm32f4_basicpwm) */
    TIM4->CCR1 = (uint32_t) (huamo_B.Gain[0] * dianjiBasicPWM7_SF);
    TIM4->CCR2 = (uint32_t) (huamo_B.Gain[1] * dianjiBasicPWM7_SF);
    TIM4->CCR3 = (uint32_t) (huamo_B.Gain[2] * dianjiBasicPWM7_SF);
    TIM4->CCR4 = (uint32_t) (huamo_B.Gain[3] * dianjiBasicPWM7_SF);

    /* RateTransition: '<S11>/Rate Transition4' */
    if (huamo_M->Timing.TaskCounters.TID[2] == 0) {
      huamo_B.RateTransition4[0] = huamo_B.yaw_H;
      huamo_B.RateTransition4[1] = huamo_B.yaw_L;
      huamo_B.RateTransition4[2] = huamo_B.pitch_H;
      huamo_B.RateTransition4[3] = huamo_B.pitch_L;
      huamo_B.RateTransition4[4] = huamo_B.roll_H;
      huamo_B.RateTransition4[5] = huamo_B.roll_L;
      huamo_B.RateTransition4[6] = huamo_B.p_H;
      huamo_B.RateTransition4[7] = huamo_B.p_L;
      huamo_B.RateTransition4[8] = huamo_B.q_H;
      huamo_B.RateTransition4[9] = huamo_B.q_L;
      huamo_B.RateTransition4[10] = huamo_B.r_H;
      huamo_B.RateTransition4[11] = huamo_B.r_L;
      huamo_B.RateTransition4[12] = huamo_B.alt_H;
      huamo_B.RateTransition4[13] = huamo_B.alt_L;
    }

    /* End of RateTransition: '<S11>/Rate Transition4' */
  }

  if (huamo_M->Timing.TaskCounters.TID[2] == 0) {
    /* toshangweijiUARTTx2: '<S11>/UART Tx2' */
    {
      /* Flush tx, so we can put data directly to DMA buffer */
      UART1_FlushTxBuffer();

      /* Put data into buffer */
      UART1_Tx_Buffer[0] = 165;        /* Header 0 */
      UART1_Tx_Buffer[1] = 90;         /* Header 1 */
      UART1_Tx_Buffer[2] = 17;         /* Header 2 */
      UART1_Tx_Buffer[3] = 164;        /* Header 3 */
      memcpy(&UART1_Tx_Buffer[4], &huamo_B.RateTransition4[0], 14*sizeof(uint8_T));/* Data 0 [14]*/
      UART1_Tx_Buffer[18] = 170;       /* Terminator 0 */

      /* Write to DMA, 19 bytes */
      UART1_TxUpdate(19);              /* Only update since data is ready on Tx buffer */
    }
  }

  if (huamo_M->Timing.TaskCounters.TID[1] == 0) {
    /* fromshangweijiUARTRx4: '<S1>/UART Rx4' */
    if (fromshangweijiUARTRx4_Receive(&UART1_Temp_Buffer[0], URX1_BUFFER_SIZE))
    {                                  /* Non-Blocking */
      huamo_B.UARTRx4_o2 = fromshangweijiUARTRx4_data0;/* D0 */
      huamo_B.UARTRx4_o3 = fromshangweijiUARTRx4_data1;/* D1 */
      huamo_B.UARTRx4_o4 = fromshangweijiUARTRx4_data2;/* D2 */
      huamo_B.UARTRx4_o5 = fromshangweijiUARTRx4_data3;/* D3 */
      huamo_B.UARTRx4_o6 = fromshangweijiUARTRx4_data4;/* D4 */
      huamo_B.UARTRx4_o1 = 1;          /* READY */
    } else {
      huamo_B.UARTRx4_o1 = 0;          /* Not READY */
    }

    /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem5' incorporates:
     *  EnablePort: '<S16>/Enable'
     */
    if (huamo_B.UARTRx4_o1 > 0) {
      if (!huamo_DW.EnabledSubsystem5_MODE) {
        /* Level2 S-Function Block: '<S16>/UART Tx' (stm32f4_usart) */
        enable_fromshangweijiEnabledSubsystem5UARTTx();
        huamo_DW.EnabledSubsystem5_MODE = true;
      }

      /* fromshangweijiEnabledSubsystem5UARTTx: '<S16>/UART Tx' */
      {
        UART1_FlushTxBuffer();         /* Flush tx, so we can print to DMA buffer directly */
        sprintf((char*)UART1_Tx_Buffer, "yaw_change_OK\r\n" );
        UART1_TxUpdate(strlen((char*)UART1_Tx_Buffer));
      }
    } else {
      if (huamo_DW.EnabledSubsystem5_MODE) {
        huamo_DW.EnabledSubsystem5_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem5' */

    /* fromshangweijiUARTRx5: '<S1>/UART Rx5' */
    if (fromshangweijiUARTRx5_Receive(&UART1_Temp_Buffer[0], URX1_BUFFER_SIZE))
    {                                  /* Non-Blocking */
      huamo_B.UARTRx5_o2 = fromshangweijiUARTRx5_data0;/* D0 */
      huamo_B.UARTRx5_o3 = fromshangweijiUARTRx5_data1;/* D1 */
      huamo_B.UARTRx5_o4 = fromshangweijiUARTRx5_data2;/* D2 */
      huamo_B.UARTRx5_o5 = fromshangweijiUARTRx5_data3;/* D3 */
      huamo_B.UARTRx5_o6 = fromshangweijiUARTRx5_data4;/* D4 */
      huamo_B.UARTRx5_o1 = 1;          /* READY */
    } else {
      huamo_B.UARTRx5_o1 = 0;          /* Not READY */
    }

    /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem6' incorporates:
     *  EnablePort: '<S17>/Enable'
     */
    if (huamo_B.UARTRx5_o1 > 0) {
      if (!huamo_DW.EnabledSubsystem6_MODE) {
        /* Level2 S-Function Block: '<S17>/UART Tx' (stm32f4_usart) */
        enable_fromshangweijiEnabledSubsystem6UARTTx();
        huamo_DW.EnabledSubsystem6_MODE = true;
      }

      /* fromshangweijiEnabledSubsystem6UARTTx: '<S17>/UART Tx' */
      {
        UART1_FlushTxBuffer();         /* Flush tx, so we can print to DMA buffer directly */
        sprintf((char*)UART1_Tx_Buffer, "alt_change_OK\r\n" );
        UART1_TxUpdate(strlen((char*)UART1_Tx_Buffer));
      }
    } else {
      if (huamo_DW.EnabledSubsystem6_MODE) {
        huamo_DW.EnabledSubsystem6_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem6' */
  }

  if (huamo_M->Timing.TaskCounters.TID[3] == 0) {
    /* fromshangweijiUARTRx1: '<S1>/UART Rx1' */
    if (fromshangweijiUARTRx1_Receive(&UART1_Temp_Buffer[0], URX1_BUFFER_SIZE))
    {                                  /* Non-Blocking */
      huamo_B.UARTRx1_o2 = fromshangweijiUARTRx1_data0;/* D0 */
      huamo_B.UARTRx1_o1 = 1;          /* READY */
    } else {
      huamo_B.UARTRx1_o1 = 0;          /* Not READY */
    }

    /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem1' incorporates:
     *  EnablePort: '<S12>/Enable'
     */
    if (huamo_B.UARTRx1_o1 > 0) {
      if (!huamo_DW.EnabledSubsystem1_MODE) {
        /* Level2 S-Function Block: '<S12>/Digital Output' (stm32f4_digital_output) */
        enable_fromshangweijiEnabledSubsystem1DigitalOutput();
        huamo_DW.EnabledSubsystem1_MODE = true;
      }

      /* S-Function (stm32f4_digital_output): '<S12>/Digital Output' */

      /* fromshangweijiEnabledSubsystem1DigitalOutput */
      *fromshangweijiEnabledSubsystem1DigitalOutput_C2 = (boolean_T)
        huamo_B.UARTRx1_o2;

      /* If: '<S12>/If' */
      rtPrevAction = huamo_DW.If_ActiveSubsystem;
      if (huamo_B.UARTRx1_o2 > 0U) {
        rtAction = 0;
      } else {
        rtAction = 1;
      }

      huamo_DW.If_ActiveSubsystem = rtAction;
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
      if (huamo_DW.EnabledSubsystem1_MODE) {
        /* Level2 S-Function Block: '<S12>/Digital Output' (stm32f4_digital_output) */

        /* disable_fromshangweijiEnabledSubsystem1DigitalOutput(); */

        /* Disable for If: '<S12>/If' */
        switch (huamo_DW.If_ActiveSubsystem) {
         case 0:
          break;

         case 1:
          break;
        }

        huamo_DW.If_ActiveSubsystem = -1;

        /* End of Disable for If: '<S12>/If' */
        huamo_DW.EnabledSubsystem1_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem1' */

    /* fromshangweijiUARTRx: '<S1>/UART Rx' */
    if (fromshangweijiUARTRx_Receive(&UART1_Temp_Buffer[0], URX1_BUFFER_SIZE)) {/* Non-Blocking */
      huamo_B.UARTRx = 1;              /* READY */
    } else {
      huamo_B.UARTRx = 0;              /* Not READY */
    }

    /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem2' incorporates:
     *  EnablePort: '<S13>/Enable'
     */
    if (huamo_B.UARTRx > 0) {
      if (!huamo_DW.EnabledSubsystem2_MODE) {
        /* Level2 S-Function Block: '<S13>/Read Unique ID' (stm32f4_uidread) */
        enable_fromshangweijiEnabledSubsystem2ReadUniqueID();

        /* Level2 S-Function Block: '<S13>/UART Tx' (stm32f4_usart) */
        enable_fromshangweijiEnabledSubsystem2UARTTx();
        huamo_DW.EnabledSubsystem2_MODE = true;
      }

      /* S-Function Block: <S13>/Read Unique ID (stm32f4_uidread) */
      huamo_B.ReadUniqueID[0] =
        UID32_fromshangweijiEnabledSubsystem2ReadUniqueID[0];
      huamo_B.ReadUniqueID[1] =
        UID32_fromshangweijiEnabledSubsystem2ReadUniqueID[1];
      huamo_B.ReadUniqueID[2] =
        UID32_fromshangweijiEnabledSubsystem2ReadUniqueID[2];

      /* fromshangweijiEnabledSubsystem2UARTTx: '<S13>/UART Tx' */
      {
        UART1_FlushTxBuffer();         /* Flush tx, so we can print to DMA buffer directly */
        sprintf((char*)UART1_Tx_Buffer, "id=%u,%u,%u\r\n" ,huamo_B.ReadUniqueID
                [0] ,huamo_B.ReadUniqueID[1] ,huamo_B.ReadUniqueID[2] );
        UART1_TxUpdate(strlen((char*)UART1_Tx_Buffer));

        /* Blocking, wait for DMA buffer */
        UART1_FlushTxBuffer();
      }
    } else {
      if (huamo_DW.EnabledSubsystem2_MODE) {
        huamo_DW.EnabledSubsystem2_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem2' */
  }

  /* fromshangweijiUARTRx2: '<S1>/UART Rx2' */
  if (fromshangweijiUARTRx2_Receive(&UART1_Temp_Buffer[0], URX1_BUFFER_SIZE)) {/* Non-Blocking */
    huamo_B.UARTRx2 = 1;               /* READY */
  } else {
    huamo_B.UARTRx2 = 0;               /* Not READY */
  }

  /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem3' incorporates:
   *  EnablePort: '<S14>/Enable'
   */
  if (huamo_B.UARTRx2 > 0) {
    if (!huamo_DW.EnabledSubsystem3_MODE) {
      /* Level2 S-Function Block: '<S14>/UART Tx' (stm32f4_usart) */
      enable_fromshangweijiEnabledSubsystem3UARTTx();
      huamo_DW.EnabledSubsystem3_MODE = true;
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
    if (huamo_DW.EnabledSubsystem3_MODE) {
      huamo_DW.EnabledSubsystem3_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem3' */
  rate_scheduler();
}

/* Model initialize function */
void huamo_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)huamo_M, 0,
                sizeof(RT_MODEL_huamo_T));

  /* block I/O */
  (void) memset(((void *) &huamo_B), 0,
                sizeof(B_huamo_T));

  /* states (dwork) */
  (void) memset((void *)&huamo_DW, 0,
                sizeof(DW_huamo_T));

  /* Start for Enabled SubSystem: '<S2>/Angle_hold' */
  huamo_Angle_hold_Start(&huamo_DW.Angle_hold, (P_Angle_hold_huamo_T *)
    &huamo_P.Angle_hold);

  /* End of Start for SubSystem: '<S2>/Angle_hold' */

  /* Start for If: '<S12>/If' */
  huamo_DW.If_ActiveSubsystem = -1;

  /* End of Start for SubSystem: '<S1>/Enabled Subsystem1' */

  /* InitializeConditions for MATLAB Function: '<S2>/MATLAB Function' */
  huamo_DW.status = 0.0;

  /* InitializeConditions for Atomic SubSystem: '<S2>/Velocity_Damper2' */
  /* InitializeConditions for UnitDelay: '<S49>/UD' */
  huamo_DW.UD_DSTATE = huamo_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for MATLAB Function: '<S24>/MATLAB Function' */
  huamo_DW.altitude_basic = 0.0;
  huamo_DW.count = 0.0;

  /* End of InitializeConditions for SubSystem: '<S2>/Velocity_Damper2' */

  /* Enable for Atomic SubSystem: '<Root>/IMU' */
  huamo_IMU_Enable();

  /* End of Enable for SubSystem: '<Root>/IMU' */

  /* Level2 S-Function Block: '<S7>/Blue LED' (stm32f4_digital_output) */
  enable_OrangeLED1BlueLED();

  /* Level2 S-Function Block: '<S8>/UART Rx3' (stm32f4_usart) */
  enable_ReceiverUARTRx3();

  /* Level2 S-Function Block: '<S1>/UART Rx3' (stm32f4_usart) */
  enable_fromshangweijiUARTRx3();

  /* Level2 S-Function Block: '<S9>/Basic PWM7' (stm32f4_basicpwm) */
  enable_dianjiBasicPWM7();

  /* Level2 S-Function Block: '<S11>/UART Tx2' (stm32f4_usart) */
  enable_toshangweijiUARTTx2();

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
void huamo_terminate(void)
{
  /* Terminate for S-Function (stm32f4_digital_output): '<S7>/Blue LED' */

  /* terminate_OrangeLED1BlueLED(); */

  /* Terminate for S-Function (stm32f4_basicpwm): '<S9>/Basic PWM7' */

  /* terminate_dianjiBasicPWM7(); */

  /* Terminate for Enabled SubSystem: '<S1>/Enabled Subsystem1' */

  /* Terminate for S-Function (stm32f4_digital_output): '<S12>/Digital Output' */

  /* terminate_fromshangweijiEnabledSubsystem1DigitalOutput(); */

  /* End of Terminate for SubSystem: '<S1>/Enabled Subsystem1' */
}

/* [EOF] */

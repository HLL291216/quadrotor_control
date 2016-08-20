/*
 * File: huamo_data.c
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

/* Block parameters (auto storage) */
P_huamo_T huamo_P = {
  0.0F,                                /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                        * Referenced by: '<S49>/UD'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator1_BitMask
                                        * Referenced by: '<S56>/Bitwise Operator1'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator1_BitMask_j
                                        * Referenced by: '<S57>/Bitwise Operator1'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator1_BitMask_m
                                        * Referenced by: '<S58>/Bitwise Operator1'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator1_BitMask_mi
                                        * Referenced by: '<S59>/Bitwise Operator1'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator1_BitMask_e
                                        * Referenced by: '<S60>/Bitwise Operator1'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator1_BitMask_i
                                        * Referenced by: '<S61>/Bitwise Operator1'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator1_BitMask_il
                                        * Referenced by: '<S62>/Bitwise Operator1'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator2_BitMask
                                        * Referenced by: '<S56>/Bitwise Operator2'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator2_BitMask_e
                                        * Referenced by: '<S57>/Bitwise Operator2'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator2_BitMask_p
                                        * Referenced by: '<S59>/Bitwise Operator2'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator2_BitMask_j
                                        * Referenced by: '<S60>/Bitwise Operator2'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator2_BitMask_ex
                                        * Referenced by: '<S61>/Bitwise Operator2'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator2_BitMask_g
                                        * Referenced by: '<S62>/Bitwise Operator2'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator2_BitMask_ee
                                        * Referenced by: '<S58>/Bitwise Operator2'
                                        */
  7U,                                  /* Mask Parameter: BitwiseOperator5_BitMask
                                        * Referenced by: '<S68>/Bitwise Operator5'
                                        */
  63U,                                 /* Mask Parameter: BitwiseOperator6_BitMask
                                        * Referenced by: '<S68>/Bitwise Operator6'
                                        */
  1U,                                  /* Mask Parameter: BitwiseOperator7_BitMask
                                        * Referenced by: '<S68>/Bitwise Operator7'
                                        */
  254U,                                /* Mask Parameter: BitwiseOperator1_BitMask_a
                                        * Referenced by: '<S68>/Bitwise Operator1'
                                        */
  15U,                                 /* Mask Parameter: BitwiseOperator2_BitMask_n
                                        * Referenced by: '<S68>/Bitwise Operator2'
                                        */
  240U,                                /* Mask Parameter: BitwiseOperator3_BitMask
                                        * Referenced by: '<S68>/Bitwise Operator3'
                                        */
  127U,                                /* Mask Parameter: BitwiseOperator4_BitMask
                                        * Referenced by: '<S68>/Bitwise Operator4'
                                        */
  128U,                                /* Mask Parameter: BitwiseOperator8_BitMask
                                        * Referenced by: '<S68>/Bitwise Operator8'
                                        */
  3U,                                  /* Mask Parameter: BitwiseOperator9_BitMask
                                        * Referenced by: '<S68>/Bitwise Operator9'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S68>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S68>/Constant1'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S68>/Gain'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S68>/Gain1'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S68>/Gain2'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S68>/Gain3'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S68>/Gain4'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S68>/Gain5'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S9>/Gain'
                                        */
  200.0F,                              /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S49>/TSamp'
                                        */
  2.0F,                                /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S46>/Saturation'
                                        */
  -2.0F,                               /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S46>/Saturation'
                                        */
  0.01F,                               /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S55>/Gain'
                                        */
  0.01F,                               /* Computed Parameter: Gain1_Gain_e
                                        * Referenced by: '<S55>/Gain1'
                                        */
  0.01F,                               /* Computed Parameter: Gain2_Gain_d
                                        * Referenced by: '<S55>/Gain2'
                                        */
  0.0609756112F,                       /* Computed Parameter: Gain3_Gain_f
                                        * Referenced by: '<S55>/Gain3'
                                        */
  0.0609756112F,                       /* Computed Parameter: Gain4_Gain_k
                                        * Referenced by: '<S55>/Gain4'
                                        */
  0.0609756112F,                       /* Computed Parameter: Gain5_Gain_m
                                        * Referenced by: '<S55>/Gain5'
                                        */
  0.01F,                               /* Computed Parameter: Gain6_Gain
                                        * Referenced by: '<S55>/Gain6'
                                        */
  -1.0F,                               /* Computed Parameter: Gain1_Gain_o
                                        * Referenced by: '<S4>/Gain1'
                                        */
  -1.0F,                               /* Computed Parameter: Gain2_Gain_b
                                        * Referenced by: '<S4>/Gain2'
                                        */
  -1.0F,                               /* Computed Parameter: Gain3_Gain_g
                                        * Referenced by: '<S4>/Gain3'
                                        */
  -1.0F,                               /* Computed Parameter: Gain4_Gain_p
                                        * Referenced by: '<S4>/Gain4'
                                        */
  1.8F,                                /* Computed Parameter: Saturation_UpperSat_b
                                        * Referenced by: '<S9>/Saturation'
                                        */
  1.0F,                                /* Computed Parameter: Saturation_LowerSat_h
                                        * Referenced by: '<S9>/Saturation'
                                        */
  1,                                   /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S56>/Constant'
                                        */
  1,                                   /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S57>/Constant'
                                        */
  1,                                   /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S58>/Constant'
                                        */
  1,                                   /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S59>/Constant'
                                        */
  1,                                   /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S60>/Constant'
                                        */
  1,                                   /* Computed Parameter: Constant_Value_k0
                                        * Referenced by: '<S61>/Constant'
                                        */
  1,                                   /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S62>/Constant'
                                        */
  0U,                                  /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S56>/Switch'
                                        */
  0U,                                  /* Computed Parameter: Switch_Threshold_l
                                        * Referenced by: '<S57>/Switch'
                                        */
  0U,                                  /* Computed Parameter: Switch_Threshold_o
                                        * Referenced by: '<S59>/Switch'
                                        */
  0U,                                  /* Computed Parameter: Switch_Threshold_a
                                        * Referenced by: '<S60>/Switch'
                                        */
  0U,                                  /* Computed Parameter: Switch_Threshold_e
                                        * Referenced by: '<S61>/Switch'
                                        */
  0U,                                  /* Computed Parameter: Switch_Threshold_k
                                        * Referenced by: '<S62>/Switch'
                                        */
  0U,                                  /* Computed Parameter: Switch_Threshold_d
                                        * Referenced by: '<S58>/Switch'
                                        */

  /* Start of '<Root>/Guidance_System' */
  {
    1.0F,                              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S51>/Constant'
                                        */
    1.0F,                              /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S51>/Gain'
                                        */
    1.0F,                              /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S51>/Saturation'
                                        */
    0.0F,                              /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S51>/Saturation'
                                        */
    1.5F,                              /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S52>/Constant'
                                        */
    -358.0F,                           /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S52>/Gain'
                                        */
    180.0F,                            /* Computed Parameter: Saturation_UpperSat_e
                                        * Referenced by: '<S52>/Saturation'
                                        */
    -180.0F,                           /* Computed Parameter: Saturation_LowerSat_n
                                        * Referenced by: '<S52>/Saturation'
                                        */
    1.5F,                              /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S53>/Constant'
                                        */
    -40.0F,                            /* Computed Parameter: Gain_Gain_h
                                        * Referenced by: '<S53>/Gain'
                                        */
    25.0F,                             /* Computed Parameter: Saturation_UpperSat_d
                                        * Referenced by: '<S53>/Saturation'
                                        */
    -25.0F,                            /* Computed Parameter: Saturation_LowerSat_p
                                        * Referenced by: '<S53>/Saturation'
                                        */
    1.5F,                              /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S54>/Constant'
                                        */
    40.0F,                             /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S54>/Gain'
                                        */
    25.0F,                             /* Computed Parameter: Saturation_UpperSat_l
                                        * Referenced by: '<S54>/Saturation'
                                        */
    -25.0F                             /* Computed Parameter: Saturation_LowerSat_k
                                        * Referenced by: '<S54>/Saturation'
                                        */
  }
  /* End of '<Root>/Guidance_System' */
  ,

  /* Start of '<S2>/Angle_hold' */
  {
    0.01,                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                        * Referenced by: '<S33>/UD'
                                        */
    200.0,                             /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S33>/TSamp'
                                        */
    0.005,                             /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S27>/Discrete-Time Integrator1'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S27>/Discrete-Time Integrator1'
                                        */
    2.0,                               /* Expression: 2
                                        * Referenced by: '<S27>/Discrete-Time Integrator1'
                                        */
    -2.0,                              /* Expression: -2
                                        * Referenced by: '<S27>/Discrete-Time Integrator1'
                                        */
    0.0200576,                         /* Expression: 2.00576E-2
                                        * Referenced by: '<S27>/Gain'
                                        */
    515640.0,                          /* Expression: 5.1564e+05
                                        * Referenced by: '<S25>/Saturation'
                                        */
    8056.9,                            /* Expression: 8.0569e+03
                                        * Referenced by: '<S25>/Saturation'
                                        */

    /*  Computed Parameter: Gain_Gain_j
     * Referenced by: '<S20>/Gain'
     */
    { 1.0F, 1.0F, 1.0F, 1.0F },
    0.129F,                            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S31>/Constant1'
                                        */
    16.0F,                             /* Computed Parameter: Gain7_Gain
                                        * Referenced by: '<S31>/Gain7'
                                        */
    0.6F,                              /* Computed Parameter: D_Value
                                        * Referenced by: '<S31>/D'
                                        */
    1.0F,                              /* Computed Parameter: Saturation1_UpperSat
                                        * Referenced by: '<S31>/Saturation1'
                                        */
    -1.0F,                             /* Computed Parameter: Saturation1_LowerSat
                                        * Referenced by: '<S31>/Saturation1'
                                        */
    10.0F,                             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S36>/Constant'
                                        */
    0.43F,                             /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S36>/Constant1'
                                        */
    1.5F,                              /* Computed Parameter: Saturation1_UpperSat_c
                                        * Referenced by: '<S36>/Saturation1'
                                        */
    -1.5F,                             /* Computed Parameter: Saturation1_LowerSat_e
                                        * Referenced by: '<S36>/Saturation1'
                                        */
    0.0174520072F,                     /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S25>/Gain3'
                                        */
    0.0174520072F,                     /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S25>/Gain2'
                                        */
    0.0174520072F,                     /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<S25>/Gain5'
                                        */
    0.0174520072F,                     /* Computed Parameter: Gain6_Gain
                                        * Referenced by: '<S25>/Gain6'
                                        */
    0.8F,                              /* Computed Parameter: Saturation_UpperSat_m
                                        * Referenced by: '<S26>/Saturation'
                                        */
    -0.8F,                             /* Computed Parameter: Saturation_LowerSat_i
                                        * Referenced by: '<S26>/Saturation'
                                        */
    0.0174520072F,                     /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S25>/Gain4'
                                        */
    1.0F,                              /* Computed Parameter: status_Value
                                        * Referenced by: '<S27>/status'
                                        */
    2.0F,                              /* Computed Parameter: P_Value
                                        * Referenced by: '<S27>/P'
                                        */
    10.0F,                             /* Computed Parameter: nP_Value
                                        * Referenced by: '<S27>/nP'
                                        */
    0.2F,                              /* Computed Parameter: nD_Value
                                        * Referenced by: '<S27>/nD'
                                        */
    0.0F,                              /* Computed Parameter: nI_Value
                                        * Referenced by: '<S27>/nI'
                                        */
    0.2F,                              /* Computed Parameter: Saturation_UpperSat_c
                                        * Referenced by: '<S27>/Saturation'
                                        */
    -0.2F,                             /* Computed Parameter: Saturation_LowerSat_o
                                        * Referenced by: '<S27>/Saturation'
                                        */
    1.2F,                              /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S31>/Constant2'
                                        */
    3.5F,                              /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S31>/Constant3'
                                        */
    0.0F,                              /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S31>/Switch'
                                        */
    10.0F,                             /* Computed Parameter: Saturation_UpperSat_g
                                        * Referenced by: '<S31>/Saturation'
                                        */
    0.272F,                            /* Computed Parameter: Saturation_LowerSat_n
                                        * Referenced by: '<S31>/Saturation'
                                        */

    /*  Computed Parameter: Constant1_Value_h
     * Referenced by: '<S20>/Constant1'
     */
    { 1.0F, 1.0F, 1.0F, 1.0F },
    0.2F                               /* Computed Parameter: Switch_Threshold_f
                                        * Referenced by: '<S20>/Switch'
                                        */
  }
  /* End of '<S2>/Angle_hold' */
};

/* [EOF] */

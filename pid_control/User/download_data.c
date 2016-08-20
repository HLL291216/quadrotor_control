/*
 * File: download_data.c
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
#include "download.h"
#include "download_private.h"

/* Block parameters (auto storage) */
P_download_T download_P = {
  -1.0F,                               /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                        * Referenced by: '<S51>/UD'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator1_BitMask
                                        * Referenced by: '<S57>/Bitwise Operator1'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator1_BitMask_a
                                        * Referenced by: '<S58>/Bitwise Operator1'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator1_BitMask_k
                                        * Referenced by: '<S59>/Bitwise Operator1'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator1_BitMask_i
                                        * Referenced by: '<S60>/Bitwise Operator1'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator1_BitMask_n
                                        * Referenced by: '<S61>/Bitwise Operator1'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator1_BitMask_g
                                        * Referenced by: '<S62>/Bitwise Operator1'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator1_BitMask_m
                                        * Referenced by: '<S63>/Bitwise Operator1'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator2_BitMask
                                        * Referenced by: '<S57>/Bitwise Operator2'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator2_BitMask_i
                                        * Referenced by: '<S58>/Bitwise Operator2'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator2_BitMask_a
                                        * Referenced by: '<S60>/Bitwise Operator2'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator2_BitMask_i0
                                        * Referenced by: '<S61>/Bitwise Operator2'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator2_BitMask_m
                                        * Referenced by: '<S62>/Bitwise Operator2'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator2_BitMask_o
                                        * Referenced by: '<S63>/Bitwise Operator2'
                                        */
  32768U,                              /* Mask Parameter: BitwiseOperator2_BitMask_k
                                        * Referenced by: '<S59>/Bitwise Operator2'
                                        */
  7U,                                  /* Mask Parameter: BitwiseOperator5_BitMask
                                        * Referenced by: '<S69>/Bitwise Operator5'
                                        */
  63U,                                 /* Mask Parameter: BitwiseOperator6_BitMask
                                        * Referenced by: '<S69>/Bitwise Operator6'
                                        */
  1U,                                  /* Mask Parameter: BitwiseOperator7_BitMask
                                        * Referenced by: '<S69>/Bitwise Operator7'
                                        */
  254U,                                /* Mask Parameter: BitwiseOperator1_BitMask_ac
                                        * Referenced by: '<S69>/Bitwise Operator1'
                                        */
  15U,                                 /* Mask Parameter: BitwiseOperator2_BitMask_n
                                        * Referenced by: '<S69>/Bitwise Operator2'
                                        */
  240U,                                /* Mask Parameter: BitwiseOperator3_BitMask
                                        * Referenced by: '<S69>/Bitwise Operator3'
                                        */
  127U,                                /* Mask Parameter: BitwiseOperator4_BitMask
                                        * Referenced by: '<S69>/Bitwise Operator4'
                                        */
  128U,                                /* Mask Parameter: BitwiseOperator8_BitMask
                                        * Referenced by: '<S69>/Bitwise Operator8'
                                        */
  3U,                                  /* Mask Parameter: BitwiseOperator9_BitMask
                                        * Referenced by: '<S69>/Bitwise Operator9'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S69>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S69>/Constant1'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S69>/Gain'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S69>/Gain1'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S69>/Gain2'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S69>/Gain3'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S69>/Gain4'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S69>/Gain5'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S9>/Gain'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S11>/Gain2'
                                        */
  100.0F,                              /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S51>/TSamp'
                                        */
  3.0F,                                /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S49>/Saturation'
                                        */
  -3.0F,                               /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S49>/Saturation'
                                        */
  0.01F,                               /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S56>/Gain'
                                        */
  0.01F,                               /* Computed Parameter: Gain1_Gain_d
                                        * Referenced by: '<S56>/Gain1'
                                        */
  0.01F,                               /* Computed Parameter: Gain2_Gain_o
                                        * Referenced by: '<S56>/Gain2'
                                        */
  0.0609756112F,                       /* Computed Parameter: Gain3_Gain_l
                                        * Referenced by: '<S56>/Gain3'
                                        */
  0.0609756112F,                       /* Computed Parameter: Gain4_Gain_m
                                        * Referenced by: '<S56>/Gain4'
                                        */
  0.0609756112F,                       /* Computed Parameter: Gain5_Gain_h
                                        * Referenced by: '<S56>/Gain5'
                                        */
  0.01F,                               /* Computed Parameter: Gain6_Gain
                                        * Referenced by: '<S56>/Gain6'
                                        */
  -1.0F,                               /* Computed Parameter: Gain1_Gain_i
                                        * Referenced by: '<S4>/Gain1'
                                        */
  -1.0F,                               /* Computed Parameter: Gain2_Gain_p
                                        * Referenced by: '<S4>/Gain2'
                                        */
  -1.0F,                               /* Computed Parameter: Gain3_Gain_c
                                        * Referenced by: '<S4>/Gain3'
                                        */
  -1.0F,                               /* Computed Parameter: Gain4_Gain_f
                                        * Referenced by: '<S4>/Gain4'
                                        */
  2.0F,                                /* Computed Parameter: Saturation_UpperSat_l
                                        * Referenced by: '<S9>/Saturation'
                                        */
  1.0F,                                /* Computed Parameter: Saturation_LowerSat_g
                                        * Referenced by: '<S9>/Saturation'
                                        */
  100.0F,                              /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S11>/Gain'
                                        */
  100.0F,                              /* Computed Parameter: Gain1_Gain_m
                                        * Referenced by: '<S11>/Gain1'
                                        */
  1,                                   /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S57>/Constant'
                                        */
  1,                                   /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S58>/Constant'
                                        */
  1,                                   /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S59>/Constant'
                                        */
  1,                                   /* Computed Parameter: Constant_Value_bo
                                        * Referenced by: '<S60>/Constant'
                                        */
  1,                                   /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S61>/Constant'
                                        */
  1,                                   /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S62>/Constant'
                                        */
  1,                                   /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S63>/Constant'
                                        */
  0U,                                  /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S57>/Switch'
                                        */
  0U,                                  /* Computed Parameter: Switch_Threshold_n
                                        * Referenced by: '<S58>/Switch'
                                        */
  0U,                                  /* Computed Parameter: Switch_Threshold_l
                                        * Referenced by: '<S60>/Switch'
                                        */
  0U,                                  /* Computed Parameter: Switch_Threshold_j
                                        * Referenced by: '<S61>/Switch'
                                        */
  0U,                                  /* Computed Parameter: Switch_Threshold_m
                                        * Referenced by: '<S62>/Switch'
                                        */
  0U,                                  /* Computed Parameter: Switch_Threshold_ln
                                        * Referenced by: '<S63>/Switch'
                                        */
  0U,                                  /* Computed Parameter: Switch_Threshold_jy
                                        * Referenced by: '<S59>/Switch'
                                        */

  /* Start of '<Root>/Guidance_System' */
  {
    1.0F,                              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S52>/Constant'
                                        */
    1.0F,                              /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S52>/Gain'
                                        */
    1.0F,                              /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S52>/Saturation'
                                        */
    0.0F,                              /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S52>/Saturation'
                                        */
    1.5F,                              /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S53>/Constant'
                                        */
    -358.0F,                           /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S53>/Gain'
                                        */
    180.0F,                            /* Computed Parameter: Saturation_UpperSat_e
                                        * Referenced by: '<S53>/Saturation'
                                        */
    -180.0F,                           /* Computed Parameter: Saturation_LowerSat_n
                                        * Referenced by: '<S53>/Saturation'
                                        */
    1.5F,                              /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S54>/Constant'
                                        */
    -40.0F,                            /* Computed Parameter: Gain_Gain_h
                                        * Referenced by: '<S54>/Gain'
                                        */
    25.0F,                             /* Computed Parameter: Saturation_UpperSat_d
                                        * Referenced by: '<S54>/Saturation'
                                        */
    -25.0F,                            /* Computed Parameter: Saturation_LowerSat_p
                                        * Referenced by: '<S54>/Saturation'
                                        */
    1.5F,                              /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S55>/Constant'
                                        */
    40.0F,                             /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S55>/Gain'
                                        */
    25.0F,                             /* Computed Parameter: Saturation_UpperSat_l
                                        * Referenced by: '<S55>/Saturation'
                                        */
    -25.0F                             /* Computed Parameter: Saturation_LowerSat_k
                                        * Referenced by: '<S55>/Saturation'
                                        */
  }
  /* End of '<Root>/Guidance_System' */
  ,

  /* Start of '<S2>/Angle_hold' */
  {
    0.01,                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                        * Referenced by: '<S39>/UD'
                                        */
    -1.0,                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_i
                                        * Referenced by: '<S32>/UD'
                                        */
    -1.0,                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_b
                                        * Referenced by: '<S34>/UD'
                                        */
    0.01,                              /* Mask Parameter: DiscreteDerivative_ICPrevSca_i3
                                        * Referenced by: '<S36>/UD'
                                        */
    100.0,                             /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S39>/TSamp'
                                        */
    0.01,                              /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S38>/Discrete-Time Integrator'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S38>/Discrete-Time Integrator'
                                        */
    1.0,                              /* Expression: 10
                                        * Referenced by: '<S38>/Discrete-Time Integrator'
                                        */
    -1.0,                             /* Expression: -10
                                        * Referenced by: '<S38>/Discrete-Time Integrator'
                                        */
    100.0,                             /* Computed Parameter: TSamp_WtEt_c
                                        * Referenced by: '<S32>/TSamp'
                                        */
    0.01,                              /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S26>/Discrete-Time Integrator1'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S26>/Discrete-Time Integrator1'
                                        */
    0.5,                              /* Expression: 0.5
                                        * Referenced by: '<S26>/Discrete-Time Integrator1'
                                        */
    -0.5,                             /* Expression: -0.5
                                        * Referenced by: '<S26>/Discrete-Time Integrator1'
                                        */
    0.026844827586206894,              /* Expression: 6.228E-3/0.232
                                        * Referenced by: '<S26>/Gain'
                                        */
    100.0,                             /* Computed Parameter: TSamp_WtEt_b
                                        * Referenced by: '<S34>/TSamp'
                                        */
    0.01,                              /* Computed Parameter: DiscreteTimeIntegrator1_gainv_e
                                        * Referenced by: '<S27>/Discrete-Time Integrator1'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S27>/Discrete-Time Integrator1'
                                        */
    1.0,                              /* Expression: 10
                                        * Referenced by: '<S27>/Discrete-Time Integrator1'
                                        */
    -1.0,                             /* Expression: -10
                                        * Referenced by: '<S27>/Discrete-Time Integrator1'
                                        */
    0.0200576,                         /* Expression: 2.00576E-2
                                        * Referenced by: '<S27>/Gain'
                                        */
    100.0,                             /* Computed Parameter: TSamp_WtEt_k
                                        * Referenced by: '<S36>/TSamp'
                                        */
    0.01,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_n
                                        * Referenced by: '<S31>/Discrete-Time Integrator'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S31>/Discrete-Time Integrator'
                                        */
    1.0,                              /* Expression: 10
                                        * Referenced by: '<S31>/Discrete-Time Integrator'
                                        */
    -1.0,                             /* Expression: -10
                                        * Referenced by: '<S31>/Discrete-Time Integrator'
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
    2.0F,                              /* Computed Parameter: Saturation1_UpperSat
                                        * Referenced by: '<S31>/Saturation1'
                                        */
    -2.0F,                             /* Computed Parameter: Saturation1_LowerSat
                                        * Referenced by: '<S31>/Saturation1'
                                        */
    10.0F,                             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S38>/Constant'
                                        */
    0.43F,                             /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S38>/Constant1'
                                        */
    1.0F,                              /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S26>/Constant'
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
    1.5F,                               /* Computed Parameter: Saturation_UpperSat_rp
                                        * Referenced by: '<S26>/Saturation'
                                        */
    -1.5F,                              /* Computed Parameter: Saturation_LowerSat_rp
                                        / * Referenced by: '<S26>/Saturation'	
                                        */																		
    0.0174520072F,                     /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S25>/Gain4'
                                        */
    1.0F,                              /* Computed Parameter: status_Value
                                        * Referenced by: '<S27>/status'
                                        */
    0.2F,                              /* Computed Parameter: Saturation_UpperSat_c
                                        * Referenced by: '<S27>/Saturation'
                                        */
    -0.2F,                             /* Computed Parameter: Saturation_LowerSat_o
                                        * Referenced by: '<S27>/Saturation'
                                        */
    0.0F,                              /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S31>/Constant4'
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

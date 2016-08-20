/*
 * File: download.h
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

#ifndef RTW_HEADER_download_h_
#define RTW_HEADER_download_h_
#include <math.h>
#include <string.h>
#ifndef download_COMMON_INCLUDES_
# define download_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "waijung_hwdrvlib.h"
#endif                                 /* download_COMMON_INCLUDES_ */

#include "download_types.h"

/* Child system includes */
#include "Guidance_System.h"
#include "IMU.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* Block signals for system '<S2>/Angle_hold' */
typedef struct {
  real32_T Sum[4];                     /* '<S20>/Sum' */
  real32_T DataTypeConversion1[4];     /* '<S25>/Data Type Conversion1' */
  real32_T Divide;                     /* '<S38>/Divide' */
} B_Angle_hold_download_T;

/* Block states (auto storage) for system '<S2>/Angle_hold' */
typedef struct {
  real_T UD_DSTATE[2];                 /* '<S32>/UD' */
  real_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S26>/Discrete-Time Integrator1' */
  real_T UD_DSTATE_b;                  /* '<S34>/UD' */
  real_T DiscreteTimeIntegrator1_DSTAT_b;/* '<S27>/Discrete-Time Integrator1' */
  real_T UD_DSTATE_l;                  /* '<S36>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S31>/Discrete-Time Integrator' */
  real_T UD_DSTATE_m;                  /* '<S39>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_d;/* '<S38>/Discrete-Time Integrator' */
  real_T count;                        /* '<S31>/MATLAB Function' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S26>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_j;/* '<S27>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S31>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_k;/* '<S38>/Discrete-Time Integrator' */
} DW_Angle_hold_download_T;

/* Block signals for system '<S69>/MATLAB Function2' */
typedef struct {
  real_T y;                            /* '<S69>/MATLAB Function2' */
} B_MATLABFunction2_download_T;

/* Block signals (auto storage) */
typedef struct {
  real_T Gain[4];                      /* '<S9>/Gain' */
  real_T RateTransition4[4];           /* '<S11>/Rate Transition4' */
  real32_T rollCH1;                    /* '<Root>/Rate Transition1' */
  real32_T pitchCH2;                   /* '<Root>/Rate Transition1' */
  real32_T thrustCH3;                  /* '<Root>/Rate Transition1' */
  real32_T yawCH4;                     /* '<Root>/Rate Transition1' */
  real32_T Angle[3];                   /* '<Root>/Rate Transition' */
  real32_T Angle_rate[3];              /* '<Root>/Rate Transition' */
  real32_T UARTRx3_o2;                 /* '<S1>/UART Rx3' */
  real32_T UARTRx3_o3;                 /* '<S1>/UART Rx3' */
  real32_T UARTRx3_o4;                 /* '<S1>/UART Rx3' */
  real32_T UARTRx3_o5;                 /* '<S1>/UART Rx3' */
  real32_T UARTRx3_o6;                 /* '<S1>/UART Rx3' */
  real32_T UARTRx4_o2;                 /* '<S1>/UART Rx4' */
  real32_T UARTRx4_o3;                 /* '<S1>/UART Rx4' */
  real32_T UARTRx4_o4;                 /* '<S1>/UART Rx4' */
  real32_T UARTRx4_o5;                 /* '<S1>/UART Rx4' */
  real32_T UARTRx4_o6;                 /* '<S1>/UART Rx4' */
  real32_T UARTRx5_o2;                 /* '<S1>/UART Rx5' */
  real32_T UARTRx5_o3;                 /* '<S1>/UART Rx5' */
  real32_T UARTRx5_o4;                 /* '<S1>/UART Rx5' */
  real32_T UARTRx5_o5;                 /* '<S1>/UART Rx5' */
  real32_T UARTRx5_o6;                 /* '<S1>/UART Rx5' */
  real32_T alt;                        /* '<Root>/Rate Transition' */
  real32_T RateTransition2[2];         /* '<S11>/Rate Transition2' */
  real32_T rollCH1_e;                  /* '<S11>/Rate Transition3' */
  real32_T pitchCH2_i;                 /* '<S11>/Rate Transition3' */
  real32_T thrustCH3_o;                /* '<S11>/Rate Transition3' */
  real32_T yawCH4_l;                   /* '<S11>/Rate Transition3' */
  real32_T CH1;                        /* '<S69>/Data Type Conversion' */
  real32_T CH2;                        /* '<S69>/Data Type Conversion11' */
  real32_T CH3;                        /* '<S69>/Data Type Conversion12' */
  real32_T CH4;                        /* '<S69>/Data Type Conversion16' */
  real32_T Gain1;                      /* '<S4>/Gain1' */
  real32_T Gain2;                      /* '<S4>/Gain2' */
  real32_T Gain3;                      /* '<S4>/Gain3' */
  real32_T Gain4;                      /* '<S4>/Gain4' */
  real32_T Gain_n;                     /* '<S56>/Gain' */
  real32_T Gain1_b;                    /* '<S56>/Gain1' */
  real32_T Gain2_e;                    /* '<S56>/Gain2' */
  real32_T Gain3_m;                    /* '<S56>/Gain3' */
  real32_T Gain4_n;                    /* '<S56>/Gain4' */
  real32_T Gain5;                      /* '<S56>/Gain5' */
  real32_T Gain6;                      /* '<S56>/Gain6' */
  real32_T P;                          /* '<S17>/P' */
  real32_T nP;                         /* '<S17>/nP' */
  real32_T nI;                         /* '<S17>/nI' */
  real32_T nD;                         /* '<S17>/nD' */
  real32_T status;                     /* '<S17>/status' */
  real32_T P_g;                        /* '<S16>/P' */
  real32_T nP_m;                       /* '<S16>/nP' */
  real32_T nI_a;                       /* '<S16>/nI' */
  real32_T nD_d;                       /* '<S16>/nD' */
  real32_T status_k;                   /* '<S16>/status' */
  real32_T P_e;                        /* '<S15>/P' */
  real32_T nP_i;                       /* '<S15>/nP' */
  real32_T nI_e;                       /* '<S15>/nI' */
  real32_T nD_l;                       /* '<S15>/nD' */
  real32_T status_o;                   /* '<S15>/status' */
  uint32_T UARTRx1_o2;                 /* '<S1>/UART Rx1' */
  uint32_T ReadUniqueID[3];            /* '<S13>/Read Unique ID' */
  uint8_T UARTRx3_o1;                  /* '<S8>/UART Rx3' */
  uint8_T UARTRx3_o2_j[23];            /* '<S8>/UART Rx3' */
  uint8_T UARTRx3_o1_o;                /* '<S1>/UART Rx3' */
  uint8_T UARTRx4_o1;                  /* '<S1>/UART Rx4' */
  uint8_T UARTRx5_o1;                  /* '<S1>/UART Rx5' */
  uint8_T RateTransition1[14];         /* '<S11>/Rate Transition1' */
  uint8_T DataTypeConversion4;         /* '<S11>/Data Type Conversion4' */
  uint8_T DataTypeConversion1;         /* '<S11>/Data Type Conversion1' */
  uint8_T DataTypeConversion3;         /* '<S11>/Data Type Conversion3' */
  uint8_T DataTypeConversion2;         /* '<S11>/Data Type Conversion2' */
  uint8_T DataTypeConversion8;         /* '<S11>/Data Type Conversion8' */
  uint8_T DataTypeConversion5;         /* '<S11>/Data Type Conversion5' */
  uint8_T DataTypeConversion7;         /* '<S11>/Data Type Conversion7' */
  uint8_T DataTypeConversion6;         /* '<S11>/Data Type Conversion6' */
  uint8_T DataTypeConversion12;        /* '<S11>/Data Type Conversion12' */
  uint8_T DataTypeConversion9;         /* '<S11>/Data Type Conversion9' */
  uint8_T DataTypeConversion11;        /* '<S11>/Data Type Conversion11' */
  uint8_T DataTypeConversion10;        /* '<S11>/Data Type Conversion10' */
  uint8_T DataTypeConversion19;        /* '<S11>/Data Type Conversion19' */
  uint8_T DataTypeConversion16;        /* '<S11>/Data Type Conversion16' */
  uint8_T DataTypeConversion18;        /* '<S11>/Data Type Conversion18' */
  uint8_T DataTypeConversion17;        /* '<S11>/Data Type Conversion17' */
  uint8_T DataTypeConversion15;        /* '<S11>/Data Type Conversion15' */
  uint8_T DataTypeConversion20;        /* '<S11>/Data Type Conversion20' */
  uint8_T DataTypeConversion14;        /* '<S11>/Data Type Conversion14' */
  uint8_T DataTypeConversion13;        /* '<S11>/Data Type Conversion13' */
  uint8_T UARTRx1_o1;                  /* '<S1>/UART Rx1' */
  uint8_T UARTRx;                      /* '<S1>/UART Rx' */
  uint8_T UARTRx2;                     /* '<S1>/UART Rx2' */
  uint8_T angle_o1;                    /* '<S4>/angle' */
  uint8_T angle_o2;                    /* '<S4>/angle' */
  uint8_T angle_o3;                    /* '<S4>/angle' */
  uint8_T angle_o4;                    /* '<S4>/angle' */
  uint8_T angle_o5;                    /* '<S4>/angle' */
  uint8_T angle_o6;                    /* '<S4>/angle' */
  uint8_T angle_o7;                    /* '<S4>/angle' */
  uint8_T angle_o8;                    /* '<S4>/angle' */
  uint8_T angle_o9;                    /* '<S4>/angle' */
  uint8_T angle_o10;                   /* '<S4>/angle' */
  uint8_T angle_o11;                   /* '<S4>/angle' */
  uint8_T angle_o12;                   /* '<S4>/angle' */
  uint8_T angle_o13;                   /* '<S4>/angle' */
  uint8_T angle_o14;                   /* '<S4>/angle' */
  uint8_T angle_o15;                   /* '<S4>/angle' */
  uint8_T yaw_H;                       /* '<S56>/yaw_H' */
  uint8_T yaw_L;                       /* '<S56>/yaw_L' */
  uint8_T pitch_H;                     /* '<S56>/pitch_H' */
  uint8_T pitch_L;                     /* '<S56>/pitch_L' */
  uint8_T roll_H;                      /* '<S56>/roll_H' */
  uint8_T roll_L;                      /* '<S56>/roll_L' */
  uint8_T p_H;                         /* '<S56>/p_H' */
  uint8_T p_L;                         /* '<S56>/p_L' */
  uint8_T q_H;                         /* '<S56>/q_H' */
  uint8_T q_L;                         /* '<S56>/q_L' */
  uint8_T r_H;                         /* '<S56>/r_H' */
  uint8_T r_L;                         /* '<S56>/r_L' */
  uint8_T alt_H;                       /* '<S56>/alt_H' */
  uint8_T alt_L;                       /* '<S56>/alt_L' */
  B_MATLABFunction2_download_T sf_MATLABFunction4;/* '<S69>/MATLAB Function4' */
  B_MATLABFunction2_download_T sf_MATLABFunction2;/* '<S69>/MATLAB Function2' */
  B_Guidance_System_download_T Guidance_System;/* '<Root>/Guidance_System' */
  B_Angle_hold_download_T Angle_hold;  /* '<S2>/Angle_hold' */
} B_download_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T altitude_basic;               /* '<S24>/MATLAB Function' */
  real_T count;                        /* '<S24>/MATLAB Function' */
  real_T status;                       /* '<S2>/MATLAB Function' */
  real32_T UD_DSTATE;                  /* '<S51>/UD' */
  int8_T If_ActiveSubsystem;           /* '<S12>/If' */
  boolean_T EnabledSubsystem4_MODE;    /* '<S1>/Enabled Subsystem4' */
  boolean_T EnabledSubsystem5_MODE;    /* '<S1>/Enabled Subsystem5' */
  boolean_T EnabledSubsystem6_MODE;    /* '<S1>/Enabled Subsystem6' */
  boolean_T EnabledSubsystem1_MODE;    /* '<S1>/Enabled Subsystem1' */
  boolean_T EnabledSubsystem2_MODE;    /* '<S1>/Enabled Subsystem2' */
  boolean_T EnabledSubsystem3_MODE;    /* '<S1>/Enabled Subsystem3' */
  DW_Angle_hold_download_T Angle_hold; /* '<S2>/Angle_hold' */
} DW_download_T;

/* Parameters for system: '<S2>/Angle_hold' */
struct P_Angle_hold_download_T_ {
  real_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                          * Referenced by: '<S39>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_i;/* Mask Parameter: DiscreteDerivative_ICPrevScal_i
                                          * Referenced by: '<S32>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_b;/* Mask Parameter: DiscreteDerivative_ICPrevScal_b
                                          * Referenced by: '<S34>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevSca_i3;/* Mask Parameter: DiscreteDerivative_ICPrevSca_i3
                                          * Referenced by: '<S36>/UD'
                                          */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S39>/TSamp'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S38>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S38>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: 10
                                          * Referenced by: '<S38>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: -10
                                          * Referenced by: '<S38>/Discrete-Time Integrator'
                                          */
  real_T TSamp_WtEt_c;                 /* Computed Parameter: TSamp_WtEt_c
                                        * Referenced by: '<S32>/TSamp'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S26>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S26>/Discrete-Time Integrator1'
                                        */
  real_T DiscreteTimeIntegrator1_UpperSa;/* Expression: 10
                                          * Referenced by: '<S26>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_LowerSa;/* Expression: -10
                                          * Referenced by: '<S26>/Discrete-Time Integrator1'
                                          */
  real_T Gain_Gain;                    /* Expression: 6.228E-3/0.232
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T TSamp_WtEt_b;                 /* Computed Parameter: TSamp_WtEt_b
                                        * Referenced by: '<S34>/TSamp'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_e;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_e
                                          * Referenced by: '<S27>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC_m; /* Expression: 0
                                        * Referenced by: '<S27>/Discrete-Time Integrator1'
                                        */
  real_T DiscreteTimeIntegrator1_Upper_f;/* Expression: 10
                                          * Referenced by: '<S27>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_Lower_k;/* Expression: -10
                                          * Referenced by: '<S27>/Discrete-Time Integrator1'
                                          */
  real_T Gain_Gain_i;                  /* Expression: 2.00576E-2
                                        * Referenced by: '<S27>/Gain'
                                        */
  real_T TSamp_WtEt_k;                 /* Computed Parameter: TSamp_WtEt_k
                                        * Referenced by: '<S36>/TSamp'
                                        */
  real_T DiscreteTimeIntegrator_gainva_n;/* Computed Parameter: DiscreteTimeIntegrator_gainva_n
                                          * Referenced by: '<S31>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_k;  /* Expression: 0
                                        * Referenced by: '<S31>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperS_i;/* Expression: 10
                                          * Referenced by: '<S31>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_l;/* Expression: -10
                                          * Referenced by: '<S31>/Discrete-Time Integrator'
                                          */
  real_T Saturation_UpperSat;          /* Expression: 5.1564e+05
                                        * Referenced by: '<S25>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 8.0569e+03
                                        * Referenced by: '<S25>/Saturation'
                                        */
  real32_T Gain_Gain_j[4];             /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<S20>/Gain'
                                        */
  real32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S31>/Constant1'
                                        */
  real32_T Gain7_Gain;                 /* Computed Parameter: Gain7_Gain
                                        * Referenced by: '<S31>/Gain7'
                                        */
  real32_T Saturation1_UpperSat;       /* Computed Parameter: Saturation1_UpperSat
                                        * Referenced by: '<S31>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat;       /* Computed Parameter: Saturation1_LowerSat
                                        * Referenced by: '<S31>/Saturation1'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S38>/Constant'
                                        */
  real32_T Constant1_Value_e;          /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S38>/Constant1'
                                        */
  real32_T Constant_Value_c;           /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S26>/Constant'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S25>/Gain3'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S25>/Gain2'
                                        */
  real32_T Gain5_Gain;                 /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<S25>/Gain5'
                                        */
  real32_T Gain6_Gain;                 /* Computed Parameter: Gain6_Gain
                                        * Referenced by: '<S25>/Gain6'
                                        */
  real32_T Saturation_UpperSat_m;      /* Computed Parameter: Saturation_UpperSat_m
                                        * Referenced by: '<S26>/Saturation'
                                        */
  real32_T Saturation_LowerSat_i;      /* Computed Parameter: Saturation_LowerSat_i
                                        * Referenced by: '<S26>/Saturation'
                                        */
  real32_T Saturation_UpperSat_rp;      /* Computed Parameter: Saturation_UpperSat_rp
                                        * Referenced by: '<S26>/Saturation'
                                        */
  real32_T Saturation_LowerSat_rp;      /* Computed Parameter: Saturation_LowerSat_rp
                                        / * Referenced by: '<S26>/Saturation'	
                                        */																				
  real32_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S25>/Gain4'
                                        */
  real32_T status_Value;               /* Computed Parameter: status_Value
                                        * Referenced by: '<S27>/status'
                                        */
  real32_T Saturation_UpperSat_c;      /* Computed Parameter: Saturation_UpperSat_c
                                        * Referenced by: '<S27>/Saturation'
                                        */
  real32_T Saturation_LowerSat_o;      /* Computed Parameter: Saturation_LowerSat_o
                                        * Referenced by: '<S27>/Saturation'
                                        */
  real32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S31>/Constant4'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S31>/Switch'
                                        */
  real32_T Saturation_UpperSat_g;      /* Computed Parameter: Saturation_UpperSat_g
                                        * Referenced by: '<S31>/Saturation'
                                        */
  real32_T Saturation_LowerSat_n;      /* Computed Parameter: Saturation_LowerSat_n
                                        * Referenced by: '<S31>/Saturation'
                                        */
  real32_T Constant1_Value_h[4];       /* Computed Parameter: Constant1_Value_h
                                        * Referenced by: '<S20>/Constant1'
                                        */
  real32_T Switch_Threshold_f;         /* Computed Parameter: Switch_Threshold_f
                                        * Referenced by: '<S20>/Switch'
                                        */
};

/* Parameters (auto storage) */
struct P_download_T_ {
  real32_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                            * Referenced by: '<S51>/UD'
                                            */
  uint16_T BitwiseOperator1_BitMask;   /* Mask Parameter: BitwiseOperator1_BitMask
                                        * Referenced by: '<S57>/Bitwise Operator1'
                                        */
  uint16_T BitwiseOperator1_BitMask_a; /* Mask Parameter: BitwiseOperator1_BitMask_a
                                        * Referenced by: '<S58>/Bitwise Operator1'
                                        */
  uint16_T BitwiseOperator1_BitMask_k; /* Mask Parameter: BitwiseOperator1_BitMask_k
                                        * Referenced by: '<S59>/Bitwise Operator1'
                                        */
  uint16_T BitwiseOperator1_BitMask_i; /* Mask Parameter: BitwiseOperator1_BitMask_i
                                        * Referenced by: '<S60>/Bitwise Operator1'
                                        */
  uint16_T BitwiseOperator1_BitMask_n; /* Mask Parameter: BitwiseOperator1_BitMask_n
                                        * Referenced by: '<S61>/Bitwise Operator1'
                                        */
  uint16_T BitwiseOperator1_BitMask_g; /* Mask Parameter: BitwiseOperator1_BitMask_g
                                        * Referenced by: '<S62>/Bitwise Operator1'
                                        */
  uint16_T BitwiseOperator1_BitMask_m; /* Mask Parameter: BitwiseOperator1_BitMask_m
                                        * Referenced by: '<S63>/Bitwise Operator1'
                                        */
  uint16_T BitwiseOperator2_BitMask;   /* Mask Parameter: BitwiseOperator2_BitMask
                                        * Referenced by: '<S57>/Bitwise Operator2'
                                        */
  uint16_T BitwiseOperator2_BitMask_i; /* Mask Parameter: BitwiseOperator2_BitMask_i
                                        * Referenced by: '<S58>/Bitwise Operator2'
                                        */
  uint16_T BitwiseOperator2_BitMask_a; /* Mask Parameter: BitwiseOperator2_BitMask_a
                                        * Referenced by: '<S60>/Bitwise Operator2'
                                        */
  uint16_T BitwiseOperator2_BitMask_i0;/* Mask Parameter: BitwiseOperator2_BitMask_i0
                                        * Referenced by: '<S61>/Bitwise Operator2'
                                        */
  uint16_T BitwiseOperator2_BitMask_m; /* Mask Parameter: BitwiseOperator2_BitMask_m
                                        * Referenced by: '<S62>/Bitwise Operator2'
                                        */
  uint16_T BitwiseOperator2_BitMask_o; /* Mask Parameter: BitwiseOperator2_BitMask_o
                                        * Referenced by: '<S63>/Bitwise Operator2'
                                        */
  uint16_T BitwiseOperator2_BitMask_k; /* Mask Parameter: BitwiseOperator2_BitMask_k
                                        * Referenced by: '<S59>/Bitwise Operator2'
                                        */
  uint8_T BitwiseOperator5_BitMask;    /* Mask Parameter: BitwiseOperator5_BitMask
                                        * Referenced by: '<S69>/Bitwise Operator5'
                                        */
  uint8_T BitwiseOperator6_BitMask;    /* Mask Parameter: BitwiseOperator6_BitMask
                                        * Referenced by: '<S69>/Bitwise Operator6'
                                        */
  uint8_T BitwiseOperator7_BitMask;    /* Mask Parameter: BitwiseOperator7_BitMask
                                        * Referenced by: '<S69>/Bitwise Operator7'
                                        */
  uint8_T BitwiseOperator1_BitMask_ac; /* Mask Parameter: BitwiseOperator1_BitMask_ac
                                        * Referenced by: '<S69>/Bitwise Operator1'
                                        */
  uint8_T BitwiseOperator2_BitMask_n;  /* Mask Parameter: BitwiseOperator2_BitMask_n
                                        * Referenced by: '<S69>/Bitwise Operator2'
                                        */
  uint8_T BitwiseOperator3_BitMask;    /* Mask Parameter: BitwiseOperator3_BitMask
                                        * Referenced by: '<S69>/Bitwise Operator3'
                                        */
  uint8_T BitwiseOperator4_BitMask;    /* Mask Parameter: BitwiseOperator4_BitMask
                                        * Referenced by: '<S69>/Bitwise Operator4'
                                        */
  uint8_T BitwiseOperator8_BitMask;    /* Mask Parameter: BitwiseOperator8_BitMask
                                        * Referenced by: '<S69>/Bitwise Operator8'
                                        */
  uint8_T BitwiseOperator9_BitMask;    /* Mask Parameter: BitwiseOperator9_BitMask
                                        * Referenced by: '<S69>/Bitwise Operator9'
                                        */
  real_T Constant_Value;               /* Expression: 0.5
                                        * Referenced by: '<S69>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0.5
                                        * Referenced by: '<S69>/Constant1'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/1000
                                        * Referenced by: '<S69>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S69>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S69>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S69>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S69>/Gain4'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S69>/Gain5'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 10
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T Gain2_Gain_h;                 /* Expression: 100
                                        * Referenced by: '<S11>/Gain2'
                                        */
  real32_T TSamp_WtEt;                 /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S51>/TSamp'
                                        */
  real32_T Saturation_UpperSat;        /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S49>/Saturation'
                                        */
  real32_T Saturation_LowerSat;        /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S49>/Saturation'
                                        */
  real32_T Gain_Gain_o;                /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S56>/Gain'
                                        */
  real32_T Gain1_Gain_d;               /* Computed Parameter: Gain1_Gain_d
                                        * Referenced by: '<S56>/Gain1'
                                        */
  real32_T Gain2_Gain_o;               /* Computed Parameter: Gain2_Gain_o
                                        * Referenced by: '<S56>/Gain2'
                                        */
  real32_T Gain3_Gain_l;               /* Computed Parameter: Gain3_Gain_l
                                        * Referenced by: '<S56>/Gain3'
                                        */
  real32_T Gain4_Gain_m;               /* Computed Parameter: Gain4_Gain_m
                                        * Referenced by: '<S56>/Gain4'
                                        */
  real32_T Gain5_Gain_h;               /* Computed Parameter: Gain5_Gain_h
                                        * Referenced by: '<S56>/Gain5'
                                        */
  real32_T Gain6_Gain;                 /* Computed Parameter: Gain6_Gain
                                        * Referenced by: '<S56>/Gain6'
                                        */
  real32_T Gain1_Gain_i;               /* Computed Parameter: Gain1_Gain_i
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real32_T Gain2_Gain_p;               /* Computed Parameter: Gain2_Gain_p
                                        * Referenced by: '<S4>/Gain2'
                                        */
  real32_T Gain3_Gain_c;               /* Computed Parameter: Gain3_Gain_c
                                        * Referenced by: '<S4>/Gain3'
                                        */
  real32_T Gain4_Gain_f;               /* Computed Parameter: Gain4_Gain_f
                                        * Referenced by: '<S4>/Gain4'
                                        */
  real32_T Saturation_UpperSat_l;      /* Computed Parameter: Saturation_UpperSat_l
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real32_T Saturation_LowerSat_g;      /* Computed Parameter: Saturation_LowerSat_g
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real32_T Gain_Gain_a;                /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S11>/Gain'
                                        */
  real32_T Gain1_Gain_m;               /* Computed Parameter: Gain1_Gain_m
                                        * Referenced by: '<S11>/Gain1'
                                        */
  int16_T Constant_Value_b;            /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S57>/Constant'
                                        */
  int16_T Constant_Value_h;            /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S58>/Constant'
                                        */
  int16_T Constant_Value_d;            /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S59>/Constant'
                                        */
  int16_T Constant_Value_bo;           /* Computed Parameter: Constant_Value_bo
                                        * Referenced by: '<S60>/Constant'
                                        */
  int16_T Constant_Value_a;            /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S61>/Constant'
                                        */
  int16_T Constant_Value_l;            /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S62>/Constant'
                                        */
  int16_T Constant_Value_i;            /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S63>/Constant'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S57>/Switch'
                                        */
  uint16_T Switch_Threshold_n;         /* Computed Parameter: Switch_Threshold_n
                                        * Referenced by: '<S58>/Switch'
                                        */
  uint16_T Switch_Threshold_l;         /* Computed Parameter: Switch_Threshold_l
                                        * Referenced by: '<S60>/Switch'
                                        */
  uint16_T Switch_Threshold_j;         /* Computed Parameter: Switch_Threshold_j
                                        * Referenced by: '<S61>/Switch'
                                        */
  uint16_T Switch_Threshold_m;         /* Computed Parameter: Switch_Threshold_m
                                        * Referenced by: '<S62>/Switch'
                                        */
  uint16_T Switch_Threshold_ln;        /* Computed Parameter: Switch_Threshold_ln
                                        * Referenced by: '<S63>/Switch'
                                        */
  uint16_T Switch_Threshold_jy;        /* Computed Parameter: Switch_Threshold_jy
                                        * Referenced by: '<S59>/Switch'
                                        */
  P_Guidance_System_download_T Guidance_System;/* '<Root>/Guidance_System' */
  P_Angle_hold_download_T Angle_hold;  /* '<S2>/Angle_hold' */
};

/* Real-time Model Data Structure */
struct tag_RTM_download_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[5];
    } TaskCounters;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_download_T download_P;

/* Block signals (auto storage) */
extern B_download_T download_B;

/* Block states (auto storage) */
extern DW_download_T download_DW;

/* Model entry point functions */
extern void download_initialize(void);
//extern void download_step(void);
extern void download_terminate(void);

/* Real-time Model object */
extern RT_MODEL_download_T *const download_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'download'
 * '<S1>'   : 'download/ from shangweiji'
 * '<S2>'   : 'download/Controller'
 * '<S3>'   : 'download/Guidance_System'
 * '<S4>'   : 'download/IMU'
 * '<S5>'   : 'download/M3C'
 * '<S6>'   : 'download/Orange LED'
 * '<S7>'   : 'download/Orange LED1'
 * '<S8>'   : 'download/Receiver'
 * '<S9>'   : 'download/execute'
 * '<S10>'  : 'download/init'
 * '<S11>'  : 'download/to shangweiji'
 * '<S12>'  : 'download/ from shangweiji/Enabled Subsystem1'
 * '<S13>'  : 'download/ from shangweiji/Enabled Subsystem2'
 * '<S14>'  : 'download/ from shangweiji/Enabled Subsystem3'
 * '<S15>'  : 'download/ from shangweiji/Enabled Subsystem4'
 * '<S16>'  : 'download/ from shangweiji/Enabled Subsystem5'
 * '<S17>'  : 'download/ from shangweiji/Enabled Subsystem6'
 * '<S18>'  : 'download/ from shangweiji/Enabled Subsystem1/If Action Subsystem'
 * '<S19>'  : 'download/ from shangweiji/Enabled Subsystem1/If Action Subsystem1'
 * '<S20>'  : 'download/Controller/Angle_hold'
 * '<S21>'  : 'download/Controller/MATLAB Function'
 * '<S22>'  : 'download/Controller/Parameter'
 * '<S23>'  : 'download/Controller/Velocity_Damper1'
 * '<S24>'  : 'download/Controller/Velocity_Damper2'
 * '<S25>'  : 'download/Controller/Angle_hold/Subsystem'
 * '<S26>'  : 'download/Controller/Angle_hold/Subsystem/Controller_roll'
 * '<S27>'  : 'download/Controller/Angle_hold/Subsystem/Controller_yaw'
 * '<S28>'  : 'download/Controller/Angle_hold/Subsystem/MATLAB Function'
 * '<S29>'  : 'download/Controller/Angle_hold/Subsystem/MATLAB Function1'
 * '<S30>'  : 'download/Controller/Angle_hold/Subsystem/MATLAB Function2'
 * '<S31>'  : 'download/Controller/Angle_hold/Subsystem/alt_control'
 * '<S32>'  : 'download/Controller/Angle_hold/Subsystem/Controller_roll/Discrete Derivative'
 * '<S33>'  : 'download/Controller/Angle_hold/Subsystem/Controller_roll/MATLAB Function'
 * '<S34>'  : 'download/Controller/Angle_hold/Subsystem/Controller_yaw/Discrete Derivative'
 * '<S35>'  : 'download/Controller/Angle_hold/Subsystem/Controller_yaw/MATLAB Function'
 * '<S36>'  : 'download/Controller/Angle_hold/Subsystem/alt_control/Discrete Derivative'
 * '<S37>'  : 'download/Controller/Angle_hold/Subsystem/alt_control/MATLAB Function'
 * '<S38>'  : 'download/Controller/Angle_hold/Subsystem/alt_control/Subsystem'
 * '<S39>'  : 'download/Controller/Angle_hold/Subsystem/alt_control/Subsystem/Discrete Derivative'
 * '<S40>'  : 'download/Controller/Velocity_Damper1/Altitude_calculation'
 * '<S41>'  : 'download/Controller/Velocity_Damper1/Controller'
 * '<S42>'  : 'download/Controller/Velocity_Damper1/Get_initial_altitude'
 * '<S43>'  : 'download/Controller/Velocity_Damper1/Horizontal_velocity'
 * '<S44>'  : 'download/Controller/Velocity_Damper1/If Action Subsystem'
 * '<S45>'  : 'download/Controller/Velocity_Damper1/MATLAB Function'
 * '<S46>'  : 'download/Controller/Velocity_Damper1/accb_to_acce'
 * '<S47>'  : 'download/Controller/Velocity_Damper1/Altitude_calculation/MATLAB Function'
 * '<S48>'  : 'download/Controller/Velocity_Damper1/accb_to_acce/body axis to earth axis'
 * '<S49>'  : 'download/Controller/Velocity_Damper2/Controller'
 * '<S50>'  : 'download/Controller/Velocity_Damper2/MATLAB Function'
 * '<S51>'  : 'download/Controller/Velocity_Damper2/Controller/Discrete Derivative'
 * '<S52>'  : 'download/Guidance_System/Duty to Force'
 * '<S53>'  : 'download/Guidance_System/Duty to angle1'
 * '<S54>'  : 'download/Guidance_System/Duty to angle2'
 * '<S55>'  : 'download/Guidance_System/Duty to angle3'
 * '<S56>'  : 'download/IMU/Cal'
 * '<S57>'  : 'download/IMU/Cal/bu ma'
 * '<S58>'  : 'download/IMU/Cal/bu ma1'
 * '<S59>'  : 'download/IMU/Cal/bu ma2'
 * '<S60>'  : 'download/IMU/Cal/bu ma3'
 * '<S61>'  : 'download/IMU/Cal/bu ma4'
 * '<S62>'  : 'download/IMU/Cal/bu ma5'
 * '<S63>'  : 'download/IMU/Cal/bu ma6'
 * '<S64>'  : 'download/M3C/Cal'
 * '<S65>'  : 'download/M3C/Cal1'
 * '<S66>'  : 'download/M3C/Cal2'
 * '<S67>'  : 'download/M3C/Cal3'
 * '<S68>'  : 'download/M3C/Cal4'
 * '<S69>'  : 'download/Receiver/Enabled Subsystem'
 * '<S70>'  : 'download/Receiver/Enabled Subsystem/MATLAB Function1'
 * '<S71>'  : 'download/Receiver/Enabled Subsystem/MATLAB Function2'
 * '<S72>'  : 'download/Receiver/Enabled Subsystem/MATLAB Function3'
 * '<S73>'  : 'download/Receiver/Enabled Subsystem/MATLAB Function4'
 */
#endif                                 /* RTW_HEADER_download_h_ */

/* [EOF] */

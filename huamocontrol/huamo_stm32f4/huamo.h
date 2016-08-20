/*
 * File: huamo.h
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

#ifndef RTW_HEADER_huamo_h_
#define RTW_HEADER_huamo_h_
#include <math.h>
#include <string.h>
#ifndef huamo_COMMON_INCLUDES_
# define huamo_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "waijung_hwdrvlib.h"
#endif                                 /* huamo_COMMON_INCLUDES_ */

#include "huamo_types.h"

/* Child system includes */
#include "Guidance_System.h"
#include "IMU.h"

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
  real32_T Divide;                     /* '<S36>/Divide' */
} B_Angle_hold_huamo_T;

/* Block states (auto storage) for system '<S2>/Angle_hold' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S33>/UD' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S27>/Discrete-Time Integrator1' */
  real_T count;                        /* '<S31>/MATLAB Function' */
  real_T x1_1;                         /* '<S26>/attitude_control' */
  real_T x2_1;                         /* '<S26>/attitude_control' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S27>/Discrete-Time Integrator1' */
} DW_Angle_hold_huamo_T;

/* Block signals for system '<S68>/MATLAB Function2' */
typedef struct {
  real_T y;                            /* '<S68>/MATLAB Function2' */
} B_MATLABFunction2_huamo_T;

/* Block signals (auto storage) */
typedef struct {
  real_T HiddenBuf_InsertedFor_Angle_hol;/* '<S2>/MATLAB Function' */
  real_T Gain[4];                      /* '<S9>/Gain' */
  real_T GeneratedFilterBlock;         /* '<S47>/Generated Filter Block' */
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
  real32_T CH1;                        /* '<S68>/Data Type Conversion' */
  real32_T CH2;                        /* '<S68>/Data Type Conversion11' */
  real32_T CH3;                        /* '<S68>/Data Type Conversion12' */
  real32_T CH4;                        /* '<S68>/Data Type Conversion16' */
  real32_T Gain1;                      /* '<S4>/Gain1' */
  real32_T Gain2;                      /* '<S4>/Gain2' */
  real32_T Gain3;                      /* '<S4>/Gain3' */
  real32_T Gain4;                      /* '<S4>/Gain4' */
  real32_T Gain_e;                     /* '<S55>/Gain' */
  real32_T Gain1_e;                    /* '<S55>/Gain1' */
  real32_T Gain2_e;                    /* '<S55>/Gain2' */
  real32_T Gain3_b;                    /* '<S55>/Gain3' */
  real32_T Gain4_j;                    /* '<S55>/Gain4' */
  real32_T Gain5;                      /* '<S55>/Gain5' */
  real32_T Gain6;                      /* '<S55>/Gain6' */
  real32_T P_e;                        /* '<S15>/P' */
  real32_T nP_i;                       /* '<S15>/nP' */
  real32_T nI_e;                       /* '<S15>/nI' */
  real32_T nD_l;                       /* '<S15>/nD' */
  real32_T status_o;                   /* '<S15>/status' */
  real32_T GeneratedFilterBlock_b;     /* '<S50>/Generated Filter Block' */
  uint32_T UARTRx1_o2;                 /* '<S1>/UART Rx1' */
  uint32_T ReadUniqueID[3];            /* '<S13>/Read Unique ID' */
  uint8_T UARTRx3_o1;                  /* '<S8>/UART Rx3' */
  uint8_T UARTRx3_o2_j[23];            /* '<S8>/UART Rx3' */
  uint8_T UARTRx3_o1_o;                /* '<S1>/UART Rx3' */
  uint8_T RateTransition4[14];         /* '<S11>/Rate Transition4' */
  uint8_T UARTRx4_o1;                  /* '<S1>/UART Rx4' */
  uint8_T UARTRx5_o1;                  /* '<S1>/UART Rx5' */
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
  uint8_T yaw_H;                       /* '<S55>/yaw_H' */
  uint8_T yaw_L;                       /* '<S55>/yaw_L' */
  uint8_T pitch_H;                     /* '<S55>/pitch_H' */
  uint8_T pitch_L;                     /* '<S55>/pitch_L' */
  uint8_T roll_H;                      /* '<S55>/roll_H' */
  uint8_T roll_L;                      /* '<S55>/roll_L' */
  uint8_T p_H;                         /* '<S55>/p_H' */
  uint8_T p_L;                         /* '<S55>/p_L' */
  uint8_T q_H;                         /* '<S55>/q_H' */
  uint8_T q_L;                         /* '<S55>/q_L' */
  uint8_T r_H;                         /* '<S55>/r_H' */
  uint8_T r_L;                         /* '<S55>/r_L' */
  uint8_T alt_H;                       /* '<S55>/alt_H' */
  uint8_T alt_L;                       /* '<S55>/alt_L' */
  B_MATLABFunction2_huamo_T sf_MATLABFunction4;/* '<S68>/MATLAB Function4' */
  B_MATLABFunction2_huamo_T sf_MATLABFunction2;/* '<S68>/MATLAB Function2' */
  B_Guidance_System_huamo_T Guidance_System;/* '<Root>/Guidance_System' */
  B_Angle_hold_huamo_T Angle_hold;     /* '<S2>/Angle_hold' */
} B_huamo_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T GeneratedFilterBlock_FILT_STATE[2];/* '<S47>/Generated Filter Block' */
  real_T altitude_basic;               /* '<S24>/MATLAB Function' */
  real_T count;                        /* '<S24>/MATLAB Function' */
  real_T status;                       /* '<S2>/MATLAB Function' */
  real32_T UD_DSTATE;                  /* '<S49>/UD' */
  real32_T GeneratedFilterBlock_FILT_STA_f[2];/* '<S50>/Generated Filter Block' */
  int8_T If_ActiveSubsystem;           /* '<S12>/If' */
  boolean_T EnabledSubsystem4_MODE;    /* '<S1>/Enabled Subsystem4' */
  boolean_T EnabledSubsystem5_MODE;    /* '<S1>/Enabled Subsystem5' */
  boolean_T EnabledSubsystem6_MODE;    /* '<S1>/Enabled Subsystem6' */
  boolean_T EnabledSubsystem1_MODE;    /* '<S1>/Enabled Subsystem1' */
  boolean_T EnabledSubsystem2_MODE;    /* '<S1>/Enabled Subsystem2' */
  boolean_T EnabledSubsystem3_MODE;    /* '<S1>/Enabled Subsystem3' */
  DW_Angle_hold_huamo_T Angle_hold;    /* '<S2>/Angle_hold' */
} DW_huamo_T;

/* Parameters for system: '<S2>/Angle_hold' */
struct P_Angle_hold_huamo_T_ {
  real_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                          * Referenced by: '<S33>/UD'
                                          */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S33>/TSamp'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S27>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S27>/Discrete-Time Integrator1'
                                        */
  real_T DiscreteTimeIntegrator1_UpperSa;/* Expression: 2
                                          * Referenced by: '<S27>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_LowerSa;/* Expression: -2
                                          * Referenced by: '<S27>/Discrete-Time Integrator1'
                                          */
  real_T Gain_Gain;                    /* Expression: 2.00576E-2
                                        * Referenced by: '<S27>/Gain'
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
  real32_T D_Value;                    /* Computed Parameter: D_Value
                                        * Referenced by: '<S31>/D'
                                        */
  real32_T Saturation1_UpperSat;       /* Computed Parameter: Saturation1_UpperSat
                                        * Referenced by: '<S31>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat;       /* Computed Parameter: Saturation1_LowerSat
                                        * Referenced by: '<S31>/Saturation1'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S36>/Constant'
                                        */
  real32_T Constant1_Value_e;          /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S36>/Constant1'
                                        */
  real32_T Saturation1_UpperSat_c;     /* Computed Parameter: Saturation1_UpperSat_c
                                        * Referenced by: '<S36>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_e;     /* Computed Parameter: Saturation1_LowerSat_e
                                        * Referenced by: '<S36>/Saturation1'
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
  real32_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S25>/Gain4'
                                        */
  real32_T status_Value;               /* Computed Parameter: status_Value
                                        * Referenced by: '<S27>/status'
                                        */
  real32_T P_Value;                    /* Computed Parameter: P_Value
                                        * Referenced by: '<S27>/P'
                                        */
  real32_T nP_Value;                   /* Computed Parameter: nP_Value
                                        * Referenced by: '<S27>/nP'
                                        */
  real32_T nD_Value;                   /* Computed Parameter: nD_Value
                                        * Referenced by: '<S27>/nD'
                                        */
  real32_T nI_Value;                   /* Computed Parameter: nI_Value
                                        * Referenced by: '<S27>/nI'
                                        */
  real32_T Saturation_UpperSat_c;      /* Computed Parameter: Saturation_UpperSat_c
                                        * Referenced by: '<S27>/Saturation'
                                        */
  real32_T Saturation_LowerSat_o;      /* Computed Parameter: Saturation_LowerSat_o
                                        * Referenced by: '<S27>/Saturation'
                                        */
  real32_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S31>/Constant2'
                                        */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S31>/Constant3'
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
struct P_huamo_T_ {
  real32_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                            * Referenced by: '<S49>/UD'
                                            */
  uint16_T BitwiseOperator1_BitMask;   /* Mask Parameter: BitwiseOperator1_BitMask
                                        * Referenced by: '<S56>/Bitwise Operator1'
                                        */
  uint16_T BitwiseOperator1_BitMask_j; /* Mask Parameter: BitwiseOperator1_BitMask_j
                                        * Referenced by: '<S57>/Bitwise Operator1'
                                        */
  uint16_T BitwiseOperator1_BitMask_m; /* Mask Parameter: BitwiseOperator1_BitMask_m
                                        * Referenced by: '<S58>/Bitwise Operator1'
                                        */
  uint16_T BitwiseOperator1_BitMask_mi;/* Mask Parameter: BitwiseOperator1_BitMask_mi
                                        * Referenced by: '<S59>/Bitwise Operator1'
                                        */
  uint16_T BitwiseOperator1_BitMask_e; /* Mask Parameter: BitwiseOperator1_BitMask_e
                                        * Referenced by: '<S60>/Bitwise Operator1'
                                        */
  uint16_T BitwiseOperator1_BitMask_i; /* Mask Parameter: BitwiseOperator1_BitMask_i
                                        * Referenced by: '<S61>/Bitwise Operator1'
                                        */
  uint16_T BitwiseOperator1_BitMask_il;/* Mask Parameter: BitwiseOperator1_BitMask_il
                                        * Referenced by: '<S62>/Bitwise Operator1'
                                        */
  uint16_T BitwiseOperator2_BitMask;   /* Mask Parameter: BitwiseOperator2_BitMask
                                        * Referenced by: '<S56>/Bitwise Operator2'
                                        */
  uint16_T BitwiseOperator2_BitMask_e; /* Mask Parameter: BitwiseOperator2_BitMask_e
                                        * Referenced by: '<S57>/Bitwise Operator2'
                                        */
  uint16_T BitwiseOperator2_BitMask_p; /* Mask Parameter: BitwiseOperator2_BitMask_p
                                        * Referenced by: '<S59>/Bitwise Operator2'
                                        */
  uint16_T BitwiseOperator2_BitMask_j; /* Mask Parameter: BitwiseOperator2_BitMask_j
                                        * Referenced by: '<S60>/Bitwise Operator2'
                                        */
  uint16_T BitwiseOperator2_BitMask_ex;/* Mask Parameter: BitwiseOperator2_BitMask_ex
                                        * Referenced by: '<S61>/Bitwise Operator2'
                                        */
  uint16_T BitwiseOperator2_BitMask_g; /* Mask Parameter: BitwiseOperator2_BitMask_g
                                        * Referenced by: '<S62>/Bitwise Operator2'
                                        */
  uint16_T BitwiseOperator2_BitMask_ee;/* Mask Parameter: BitwiseOperator2_BitMask_ee
                                        * Referenced by: '<S58>/Bitwise Operator2'
                                        */
  uint8_T BitwiseOperator5_BitMask;    /* Mask Parameter: BitwiseOperator5_BitMask
                                        * Referenced by: '<S68>/Bitwise Operator5'
                                        */
  uint8_T BitwiseOperator6_BitMask;    /* Mask Parameter: BitwiseOperator6_BitMask
                                        * Referenced by: '<S68>/Bitwise Operator6'
                                        */
  uint8_T BitwiseOperator7_BitMask;    /* Mask Parameter: BitwiseOperator7_BitMask
                                        * Referenced by: '<S68>/Bitwise Operator7'
                                        */
  uint8_T BitwiseOperator1_BitMask_a;  /* Mask Parameter: BitwiseOperator1_BitMask_a
                                        * Referenced by: '<S68>/Bitwise Operator1'
                                        */
  uint8_T BitwiseOperator2_BitMask_n;  /* Mask Parameter: BitwiseOperator2_BitMask_n
                                        * Referenced by: '<S68>/Bitwise Operator2'
                                        */
  uint8_T BitwiseOperator3_BitMask;    /* Mask Parameter: BitwiseOperator3_BitMask
                                        * Referenced by: '<S68>/Bitwise Operator3'
                                        */
  uint8_T BitwiseOperator4_BitMask;    /* Mask Parameter: BitwiseOperator4_BitMask
                                        * Referenced by: '<S68>/Bitwise Operator4'
                                        */
  uint8_T BitwiseOperator8_BitMask;    /* Mask Parameter: BitwiseOperator8_BitMask
                                        * Referenced by: '<S68>/Bitwise Operator8'
                                        */
  uint8_T BitwiseOperator9_BitMask;    /* Mask Parameter: BitwiseOperator9_BitMask
                                        * Referenced by: '<S68>/Bitwise Operator9'
                                        */
  real_T Constant_Value;               /* Expression: 0.5
                                        * Referenced by: '<S68>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0.5
                                        * Referenced by: '<S68>/Constant1'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/1000
                                        * Referenced by: '<S68>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S68>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S68>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S68>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S68>/Gain4'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S68>/Gain5'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 10
                                        * Referenced by: '<S9>/Gain'
                                        */
  real32_T TSamp_WtEt;                 /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S49>/TSamp'
                                        */
  real32_T Saturation_UpperSat;        /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S46>/Saturation'
                                        */
  real32_T Saturation_LowerSat;        /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S46>/Saturation'
                                        */
  real32_T Gain_Gain_o;                /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S55>/Gain'
                                        */
  real32_T Gain1_Gain_e;               /* Computed Parameter: Gain1_Gain_e
                                        * Referenced by: '<S55>/Gain1'
                                        */
  real32_T Gain2_Gain_d;               /* Computed Parameter: Gain2_Gain_d
                                        * Referenced by: '<S55>/Gain2'
                                        */
  real32_T Gain3_Gain_f;               /* Computed Parameter: Gain3_Gain_f
                                        * Referenced by: '<S55>/Gain3'
                                        */
  real32_T Gain4_Gain_k;               /* Computed Parameter: Gain4_Gain_k
                                        * Referenced by: '<S55>/Gain4'
                                        */
  real32_T Gain5_Gain_m;               /* Computed Parameter: Gain5_Gain_m
                                        * Referenced by: '<S55>/Gain5'
                                        */
  real32_T Gain6_Gain;                 /* Computed Parameter: Gain6_Gain
                                        * Referenced by: '<S55>/Gain6'
                                        */
  real32_T Gain1_Gain_o;               /* Computed Parameter: Gain1_Gain_o
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real32_T Gain2_Gain_b;               /* Computed Parameter: Gain2_Gain_b
                                        * Referenced by: '<S4>/Gain2'
                                        */
  real32_T Gain3_Gain_g;               /* Computed Parameter: Gain3_Gain_g
                                        * Referenced by: '<S4>/Gain3'
                                        */
  real32_T Gain4_Gain_p;               /* Computed Parameter: Gain4_Gain_p
                                        * Referenced by: '<S4>/Gain4'
                                        */
  real32_T Saturation_UpperSat_b;      /* Computed Parameter: Saturation_UpperSat_b
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real32_T Saturation_LowerSat_h;      /* Computed Parameter: Saturation_LowerSat_h
                                        * Referenced by: '<S9>/Saturation'
                                        */
  int16_T Constant_Value_f;            /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S56>/Constant'
                                        */
  int16_T Constant_Value_e;            /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S57>/Constant'
                                        */
  int16_T Constant_Value_n;            /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S58>/Constant'
                                        */
  int16_T Constant_Value_l;            /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S59>/Constant'
                                        */
  int16_T Constant_Value_k;            /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S60>/Constant'
                                        */
  int16_T Constant_Value_k0;           /* Computed Parameter: Constant_Value_k0
                                        * Referenced by: '<S61>/Constant'
                                        */
  int16_T Constant_Value_j;            /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S62>/Constant'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S56>/Switch'
                                        */
  uint16_T Switch_Threshold_l;         /* Computed Parameter: Switch_Threshold_l
                                        * Referenced by: '<S57>/Switch'
                                        */
  uint16_T Switch_Threshold_o;         /* Computed Parameter: Switch_Threshold_o
                                        * Referenced by: '<S59>/Switch'
                                        */
  uint16_T Switch_Threshold_a;         /* Computed Parameter: Switch_Threshold_a
                                        * Referenced by: '<S60>/Switch'
                                        */
  uint16_T Switch_Threshold_e;         /* Computed Parameter: Switch_Threshold_e
                                        * Referenced by: '<S61>/Switch'
                                        */
  uint16_T Switch_Threshold_k;         /* Computed Parameter: Switch_Threshold_k
                                        * Referenced by: '<S62>/Switch'
                                        */
  uint16_T Switch_Threshold_d;         /* Computed Parameter: Switch_Threshold_d
                                        * Referenced by: '<S58>/Switch'
                                        */
  P_Guidance_System_huamo_T Guidance_System;/* '<Root>/Guidance_System' */
  P_Angle_hold_huamo_T Angle_hold;     /* '<S2>/Angle_hold' */
};

/* Real-time Model Data Structure */
struct tag_RTM_huamo_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[4];
    } TaskCounters;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_huamo_T huamo_P;

/* Block signals (auto storage) */
extern B_huamo_T huamo_B;

/* Block states (auto storage) */
extern DW_huamo_T huamo_DW;

/* Model entry point functions */
extern void huamo_initialize(void);
extern void huamo_step(void);
extern void huamo_terminate(void);

/* Real-time Model object */
extern RT_MODEL_huamo_T *const huamo_M;

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
 * '<Root>' : 'huamo'
 * '<S1>'   : 'huamo/ from shangweiji'
 * '<S2>'   : 'huamo/Controller'
 * '<S3>'   : 'huamo/Guidance_System'
 * '<S4>'   : 'huamo/IMU'
 * '<S5>'   : 'huamo/M3C'
 * '<S6>'   : 'huamo/Orange LED'
 * '<S7>'   : 'huamo/Orange LED1'
 * '<S8>'   : 'huamo/Receiver'
 * '<S9>'   : 'huamo/dianji'
 * '<S10>'  : 'huamo/init'
 * '<S11>'  : 'huamo/to shangweiji'
 * '<S12>'  : 'huamo/ from shangweiji/Enabled Subsystem1'
 * '<S13>'  : 'huamo/ from shangweiji/Enabled Subsystem2'
 * '<S14>'  : 'huamo/ from shangweiji/Enabled Subsystem3'
 * '<S15>'  : 'huamo/ from shangweiji/Enabled Subsystem4'
 * '<S16>'  : 'huamo/ from shangweiji/Enabled Subsystem5'
 * '<S17>'  : 'huamo/ from shangweiji/Enabled Subsystem6'
 * '<S18>'  : 'huamo/ from shangweiji/Enabled Subsystem1/If Action Subsystem'
 * '<S19>'  : 'huamo/ from shangweiji/Enabled Subsystem1/If Action Subsystem1'
 * '<S20>'  : 'huamo/Controller/Angle_hold'
 * '<S21>'  : 'huamo/Controller/MATLAB Function'
 * '<S22>'  : 'huamo/Controller/Parameter'
 * '<S23>'  : 'huamo/Controller/Velocity_Damper1'
 * '<S24>'  : 'huamo/Controller/Velocity_Damper2'
 * '<S25>'  : 'huamo/Controller/Angle_hold/Subsystem'
 * '<S26>'  : 'huamo/Controller/Angle_hold/Subsystem/Controller_roll'
 * '<S27>'  : 'huamo/Controller/Angle_hold/Subsystem/Controller_yaw'
 * '<S28>'  : 'huamo/Controller/Angle_hold/Subsystem/MATLAB Function'
 * '<S29>'  : 'huamo/Controller/Angle_hold/Subsystem/MATLAB Function1'
 * '<S30>'  : 'huamo/Controller/Angle_hold/Subsystem/MATLAB Function2'
 * '<S31>'  : 'huamo/Controller/Angle_hold/Subsystem/alt_control'
 * '<S32>'  : 'huamo/Controller/Angle_hold/Subsystem/Controller_roll/attitude_control'
 * '<S33>'  : 'huamo/Controller/Angle_hold/Subsystem/Controller_yaw/Discrete Derivative'
 * '<S34>'  : 'huamo/Controller/Angle_hold/Subsystem/Controller_yaw/MATLAB Function'
 * '<S35>'  : 'huamo/Controller/Angle_hold/Subsystem/alt_control/MATLAB Function'
 * '<S36>'  : 'huamo/Controller/Angle_hold/Subsystem/alt_control/Subsystem'
 * '<S37>'  : 'huamo/Controller/Velocity_Damper1/Altitude_calculation'
 * '<S38>'  : 'huamo/Controller/Velocity_Damper1/Controller'
 * '<S39>'  : 'huamo/Controller/Velocity_Damper1/Get_initial_altitude'
 * '<S40>'  : 'huamo/Controller/Velocity_Damper1/Horizontal_velocity'
 * '<S41>'  : 'huamo/Controller/Velocity_Damper1/If Action Subsystem'
 * '<S42>'  : 'huamo/Controller/Velocity_Damper1/MATLAB Function'
 * '<S43>'  : 'huamo/Controller/Velocity_Damper1/accb_to_acce'
 * '<S44>'  : 'huamo/Controller/Velocity_Damper1/Altitude_calculation/MATLAB Function'
 * '<S45>'  : 'huamo/Controller/Velocity_Damper1/accb_to_acce/body axis to earth axis'
 * '<S46>'  : 'huamo/Controller/Velocity_Damper2/Controller'
 * '<S47>'  : 'huamo/Controller/Velocity_Damper2/Lowpass Filter'
 * '<S48>'  : 'huamo/Controller/Velocity_Damper2/MATLAB Function'
 * '<S49>'  : 'huamo/Controller/Velocity_Damper2/Controller/Discrete Derivative'
 * '<S50>'  : 'huamo/Controller/Velocity_Damper2/Controller/Lowpass Filter'
 * '<S51>'  : 'huamo/Guidance_System/Duty to Force'
 * '<S52>'  : 'huamo/Guidance_System/Duty to angle1'
 * '<S53>'  : 'huamo/Guidance_System/Duty to angle2'
 * '<S54>'  : 'huamo/Guidance_System/Duty to angle3'
 * '<S55>'  : 'huamo/IMU/Cal'
 * '<S56>'  : 'huamo/IMU/Cal/bu ma'
 * '<S57>'  : 'huamo/IMU/Cal/bu ma1'
 * '<S58>'  : 'huamo/IMU/Cal/bu ma2'
 * '<S59>'  : 'huamo/IMU/Cal/bu ma3'
 * '<S60>'  : 'huamo/IMU/Cal/bu ma4'
 * '<S61>'  : 'huamo/IMU/Cal/bu ma5'
 * '<S62>'  : 'huamo/IMU/Cal/bu ma6'
 * '<S63>'  : 'huamo/M3C/Cal'
 * '<S64>'  : 'huamo/M3C/Cal1'
 * '<S65>'  : 'huamo/M3C/Cal2'
 * '<S66>'  : 'huamo/M3C/Cal3'
 * '<S67>'  : 'huamo/M3C/Cal4'
 * '<S68>'  : 'huamo/Receiver/Enabled Subsystem'
 * '<S69>'  : 'huamo/Receiver/Enabled Subsystem/MATLAB Function1'
 * '<S70>'  : 'huamo/Receiver/Enabled Subsystem/MATLAB Function2'
 * '<S71>'  : 'huamo/Receiver/Enabled Subsystem/MATLAB Function3'
 * '<S72>'  : 'huamo/Receiver/Enabled Subsystem/MATLAB Function4'
 * '<S73>'  : 'huamo/to shangweiji/Subsystem'
 */
#endif                                 /* RTW_HEADER_huamo_h_ */

/* [EOF] */

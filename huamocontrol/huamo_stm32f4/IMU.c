/*
 * File: IMU.c
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

#include "IMU.h"

/* Include model header file for global data */
#include "huamo.h"
#include "huamo_private.h"

/* Enable for atomic system: '<Root>/IMU' */
void huamo_IMU_Enable(void)
{
  /* Level2 S-Function Block: '<S4>/angle' (stm32f4_usart) */
  enable_IMUangle();
}

/* Output and update for atomic system: '<Root>/IMU' */
void huamo_IMU(void)
{
  uint16_T rtb_Add;
  uint16_T rtb_Add1;
  uint16_T rtb_Add2;
  uint16_T rtb_Add3;
  uint16_T rtb_Add4;
  uint16_T rtb_Add5;
  uint16_T rtb_Add6;

  /* IMUangle: '<S4>/angle' */
  if (IMUangle_Receive(&UART3_Temp_Buffer[0], 14)) {/* Non-blocking */
    memcpy(&huamo_B.angle_o2, &UART3_Temp_Buffer[0], 1*sizeof(uint8_T));/* D0 [1] */
    memcpy(&huamo_B.angle_o3, &UART3_Temp_Buffer[1], 1*sizeof(uint8_T));/* D1 [1] */
    memcpy(&huamo_B.angle_o4, &UART3_Temp_Buffer[2], 1*sizeof(uint8_T));/* D2 [1] */
    memcpy(&huamo_B.angle_o5, &UART3_Temp_Buffer[3], 1*sizeof(uint8_T));/* D3 [1] */
    memcpy(&huamo_B.angle_o6, &UART3_Temp_Buffer[4], 1*sizeof(uint8_T));/* D4 [1] */
    memcpy(&huamo_B.angle_o7, &UART3_Temp_Buffer[5], 1*sizeof(uint8_T));/* D5 [1] */
    memcpy(&huamo_B.angle_o8, &UART3_Temp_Buffer[6], 1*sizeof(uint8_T));/* D6 [1] */
    memcpy(&huamo_B.angle_o9, &UART3_Temp_Buffer[7], 1*sizeof(uint8_T));/* D7 [1] */
    memcpy(&huamo_B.angle_o10, &UART3_Temp_Buffer[8], 1*sizeof(uint8_T));/* D8 [1] */
    memcpy(&huamo_B.angle_o11, &UART3_Temp_Buffer[9], 1*sizeof(uint8_T));/* D9 [1] */
    memcpy(&huamo_B.angle_o12, &UART3_Temp_Buffer[10], 1*sizeof(uint8_T));/* D10 [1] */
    memcpy(&huamo_B.angle_o13, &UART3_Temp_Buffer[11], 1*sizeof(uint8_T));/* D11 [1] */
    memcpy(&huamo_B.angle_o14, &UART3_Temp_Buffer[12], 1*sizeof(uint8_T));/* D12 [1] */
    memcpy(&huamo_B.angle_o15, &UART3_Temp_Buffer[13], 1*sizeof(uint8_T));/* D13 [1] */
    huamo_B.angle_o1 = 1;              /* READY */
  } else {
    huamo_B.angle_o1 = 0;              /* Not READY */
  }

  /* Outputs for Enabled SubSystem: '<S4>/Cal' incorporates:
   *  EnablePort: '<S55>/Enable'
   */
  if (huamo_B.angle_o1 > 0) {
    /* Inport: '<S55>/yaw_H' */
    huamo_B.yaw_H = huamo_B.angle_o2;

    /* Inport: '<S55>/yaw_L' */
    huamo_B.yaw_L = huamo_B.angle_o3;

    /* Sum: '<S55>/Add' incorporates:
     *  ArithShift: '<S55>/Shift Arithmetic'
     *  DataTypeConversion: '<S55>/Data Type Conversion3'
     *  DataTypeConversion: '<S55>/Data Type Conversion4'
     */
    rtb_Add = (uint16_T)((uint32_T)(huamo_B.yaw_H << 8) + huamo_B.yaw_L);

    /* Inport: '<S55>/pitch_H' */
    huamo_B.pitch_H = huamo_B.angle_o4;

    /* Inport: '<S55>/pitch_L' */
    huamo_B.pitch_L = huamo_B.angle_o5;

    /* Sum: '<S55>/Add1' incorporates:
     *  ArithShift: '<S55>/Shift Arithmetic1'
     *  DataTypeConversion: '<S55>/Data Type Conversion2'
     *  DataTypeConversion: '<S55>/Data Type Conversion5'
     */
    rtb_Add1 = (uint16_T)((uint32_T)(huamo_B.pitch_H << 8) + huamo_B.pitch_L);

    /* Inport: '<S55>/roll_H' */
    huamo_B.roll_H = huamo_B.angle_o6;

    /* Inport: '<S55>/roll_L' */
    huamo_B.roll_L = huamo_B.angle_o7;

    /* Sum: '<S55>/Add2' incorporates:
     *  ArithShift: '<S55>/Shift Arithmetic2'
     *  DataTypeConversion: '<S55>/Data Type Conversion7'
     *  DataTypeConversion: '<S55>/Data Type Conversion8'
     */
    rtb_Add2 = (uint16_T)((uint32_T)(huamo_B.roll_H << 8) + huamo_B.roll_L);

    /* Inport: '<S55>/p_H' */
    huamo_B.p_H = huamo_B.angle_o8;

    /* Inport: '<S55>/p_L' */
    huamo_B.p_L = huamo_B.angle_o9;

    /* Sum: '<S55>/Add3' incorporates:
     *  ArithShift: '<S55>/Shift Arithmetic3'
     *  DataTypeConversion: '<S55>/Data Type Conversion17'
     *  DataTypeConversion: '<S55>/Data Type Conversion18'
     */
    rtb_Add3 = (uint16_T)((uint32_T)(huamo_B.p_H << 8) + huamo_B.p_L);

    /* Inport: '<S55>/q_H' */
    huamo_B.q_H = huamo_B.angle_o10;

    /* Inport: '<S55>/q_L' */
    huamo_B.q_L = huamo_B.angle_o11;

    /* Sum: '<S55>/Add4' incorporates:
     *  ArithShift: '<S55>/Shift Arithmetic4'
     *  DataTypeConversion: '<S55>/Data Type Conversion16'
     *  DataTypeConversion: '<S55>/Data Type Conversion19'
     */
    rtb_Add4 = (uint16_T)((uint32_T)(huamo_B.q_H << 8) + huamo_B.q_L);

    /* Inport: '<S55>/r_H' */
    huamo_B.r_H = huamo_B.angle_o12;

    /* Inport: '<S55>/r_L' */
    huamo_B.r_L = huamo_B.angle_o13;

    /* Sum: '<S55>/Add5' incorporates:
     *  ArithShift: '<S55>/Shift Arithmetic5'
     *  DataTypeConversion: '<S55>/Data Type Conversion21'
     *  DataTypeConversion: '<S55>/Data Type Conversion22'
     */
    rtb_Add5 = (uint16_T)((uint32_T)(huamo_B.r_H << 8) + huamo_B.r_L);

    /* Inport: '<S55>/alt_H' */
    huamo_B.alt_H = huamo_B.angle_o14;

    /* Inport: '<S55>/alt_L' */
    huamo_B.alt_L = huamo_B.angle_o15;

    /* Sum: '<S55>/Add6' incorporates:
     *  ArithShift: '<S55>/Shift Arithmetic6'
     *  DataTypeConversion: '<S55>/Data Type Conversion26'
     *  DataTypeConversion: '<S55>/Data Type Conversion27'
     */
    rtb_Add6 = (uint16_T)((uint32_T)(huamo_B.alt_H << 8) + huamo_B.alt_L);

    /* Switch: '<S56>/Switch' incorporates:
     *  Constant: '<S56>/Constant'
     *  S-Function (sfix_bitop): '<S56>/Bitwise Operator'
     *  S-Function (sfix_bitop): '<S56>/Bitwise Operator1'
     *  S-Function (sfix_bitop): '<S56>/Bitwise Operator2'
     *  Sum: '<S56>/Sum'
     */
    if ((rtb_Add & huamo_P.BitwiseOperator2_BitMask) > huamo_P.Switch_Threshold)
    {
      rtb_Add = (uint16_T)((uint16_T)(((uint16_T)((uint16_T)~rtb_Add |
        huamo_P.BitwiseOperator1_BitMask) + huamo_P.Constant_Value_f) >> 1) << 1);
    }

    /* End of Switch: '<S56>/Switch' */

    /* Gain: '<S55>/Gain' incorporates:
     *  DataTypeConversion: '<S55>/Data Type Conversion9'
     */
    huamo_B.Gain_e = huamo_P.Gain_Gain_o * (real32_T)(int16_T)rtb_Add;

    /* Switch: '<S57>/Switch' incorporates:
     *  Constant: '<S57>/Constant'
     *  S-Function (sfix_bitop): '<S57>/Bitwise Operator'
     *  S-Function (sfix_bitop): '<S57>/Bitwise Operator1'
     *  S-Function (sfix_bitop): '<S57>/Bitwise Operator2'
     *  Sum: '<S57>/Sum'
     */
    if ((rtb_Add1 & huamo_P.BitwiseOperator2_BitMask_e) >
        huamo_P.Switch_Threshold_l) {
      rtb_Add1 = (uint16_T)((uint16_T)(((uint16_T)((uint16_T)~rtb_Add1 |
        huamo_P.BitwiseOperator1_BitMask_j) + huamo_P.Constant_Value_e) >> 1) <<
                            1);
    }

    /* End of Switch: '<S57>/Switch' */

    /* Gain: '<S55>/Gain1' incorporates:
     *  DataTypeConversion: '<S55>/Data Type Conversion29'
     */
    huamo_B.Gain1_e = huamo_P.Gain1_Gain_e * (real32_T)(int16_T)rtb_Add1;

    /* Switch: '<S58>/Switch' incorporates:
     *  Constant: '<S58>/Constant'
     *  S-Function (sfix_bitop): '<S58>/Bitwise Operator'
     *  S-Function (sfix_bitop): '<S58>/Bitwise Operator1'
     *  S-Function (sfix_bitop): '<S58>/Bitwise Operator2'
     *  Sum: '<S58>/Sum'
     */
    if ((rtb_Add2 & huamo_P.BitwiseOperator2_BitMask_ee) >
        huamo_P.Switch_Threshold_d) {
      rtb_Add2 = (uint16_T)((uint16_T)(((uint16_T)((uint16_T)~rtb_Add2 |
        huamo_P.BitwiseOperator1_BitMask_m) + huamo_P.Constant_Value_n) >> 1) <<
                            1);
    }

    /* End of Switch: '<S58>/Switch' */

    /* Gain: '<S55>/Gain2' incorporates:
     *  DataTypeConversion: '<S55>/Data Type Conversion30'
     *  DataTypeConversion: '<S55>/Data Type Conversion6'
     */
    huamo_B.Gain2_e = huamo_P.Gain2_Gain_d * (real32_T)(int16_T)rtb_Add2;

    /* Switch: '<S59>/Switch' incorporates:
     *  Constant: '<S59>/Constant'
     *  S-Function (sfix_bitop): '<S59>/Bitwise Operator'
     *  S-Function (sfix_bitop): '<S59>/Bitwise Operator1'
     *  S-Function (sfix_bitop): '<S59>/Bitwise Operator2'
     *  Sum: '<S59>/Sum'
     */
    if ((rtb_Add3 & huamo_P.BitwiseOperator2_BitMask_p) >
        huamo_P.Switch_Threshold_o) {
      rtb_Add3 = (uint16_T)((uint16_T)(((uint16_T)((uint16_T)~rtb_Add3 |
        huamo_P.BitwiseOperator1_BitMask_mi) + huamo_P.Constant_Value_l) >> 1) <<
                            1);
    }

    /* End of Switch: '<S59>/Switch' */

    /* Gain: '<S55>/Gain3' incorporates:
     *  DataTypeConversion: '<S55>/Data Type Conversion31'
     */
    huamo_B.Gain3_b = huamo_P.Gain3_Gain_f * (real32_T)(int16_T)rtb_Add3;

    /* Switch: '<S60>/Switch' incorporates:
     *  Constant: '<S60>/Constant'
     *  S-Function (sfix_bitop): '<S60>/Bitwise Operator'
     *  S-Function (sfix_bitop): '<S60>/Bitwise Operator1'
     *  S-Function (sfix_bitop): '<S60>/Bitwise Operator2'
     *  Sum: '<S60>/Sum'
     */
    if ((rtb_Add4 & huamo_P.BitwiseOperator2_BitMask_j) >
        huamo_P.Switch_Threshold_a) {
      rtb_Add4 = (uint16_T)((uint16_T)(((uint16_T)((uint16_T)~rtb_Add4 |
        huamo_P.BitwiseOperator1_BitMask_e) + huamo_P.Constant_Value_k) >> 1) <<
                            1);
    }

    /* End of Switch: '<S60>/Switch' */

    /* Gain: '<S55>/Gain4' incorporates:
     *  DataTypeConversion: '<S55>/Data Type Conversion32'
     */
    huamo_B.Gain4_j = huamo_P.Gain4_Gain_k * (real32_T)(int16_T)rtb_Add4;

    /* Switch: '<S61>/Switch' incorporates:
     *  Constant: '<S61>/Constant'
     *  S-Function (sfix_bitop): '<S61>/Bitwise Operator'
     *  S-Function (sfix_bitop): '<S61>/Bitwise Operator1'
     *  S-Function (sfix_bitop): '<S61>/Bitwise Operator2'
     *  Sum: '<S61>/Sum'
     */
    if ((rtb_Add5 & huamo_P.BitwiseOperator2_BitMask_ex) >
        huamo_P.Switch_Threshold_e) {
      rtb_Add5 = (uint16_T)((uint16_T)(((uint16_T)((uint16_T)~rtb_Add5 |
        huamo_P.BitwiseOperator1_BitMask_i) + huamo_P.Constant_Value_k0) >> 1) <<
                            1);
    }

    /* End of Switch: '<S61>/Switch' */

    /* Gain: '<S55>/Gain5' incorporates:
     *  DataTypeConversion: '<S55>/Data Type Conversion33'
     */
    huamo_B.Gain5 = huamo_P.Gain5_Gain_m * (real32_T)(int16_T)rtb_Add5;

    /* Switch: '<S62>/Switch' incorporates:
     *  Constant: '<S62>/Constant'
     *  S-Function (sfix_bitop): '<S62>/Bitwise Operator'
     *  S-Function (sfix_bitop): '<S62>/Bitwise Operator1'
     *  S-Function (sfix_bitop): '<S62>/Bitwise Operator2'
     *  Sum: '<S62>/Sum'
     */
    if ((rtb_Add6 & huamo_P.BitwiseOperator2_BitMask_g) >
        huamo_P.Switch_Threshold_k) {
      rtb_Add6 = (uint16_T)((uint16_T)(((uint16_T)((uint16_T)~rtb_Add6 |
        huamo_P.BitwiseOperator1_BitMask_il) + huamo_P.Constant_Value_j) >> 1) <<
                            1);
    }

    /* End of Switch: '<S62>/Switch' */

    /* Gain: '<S55>/Gain6' incorporates:
     *  DataTypeConversion: '<S55>/Data Type Conversion34'
     */
    huamo_B.Gain6 = huamo_P.Gain6_Gain * (real32_T)(int16_T)rtb_Add6;
  }

  /* End of Outputs for SubSystem: '<S4>/Cal' */

  /* Gain: '<S4>/Gain1' */
  huamo_B.Gain1 = huamo_P.Gain1_Gain_o * huamo_B.Gain1_e;

  /* Gain: '<S4>/Gain2' */
  huamo_B.Gain2 = huamo_P.Gain2_Gain_b * huamo_B.Gain_e;

  /* Gain: '<S4>/Gain3' */
  huamo_B.Gain3 = huamo_P.Gain3_Gain_g * huamo_B.Gain4_j;

  /* Gain: '<S4>/Gain4' */
  huamo_B.Gain4 = huamo_P.Gain4_Gain_p * huamo_B.Gain5;
}

/* [EOF] */

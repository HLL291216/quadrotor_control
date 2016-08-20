/*
 * File: IMU.c
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

#include "IMU.h"

/* Include model header file for global data */
#include "download.h"
#include "download_private.h"

/* Enable for atomic system: '<Root>/IMU' */
void download_IMU_Enable(void)
{
  /* Level2 S-Function Block: '<S4>/angle' (stm32f4_usart) */
  enable_IMUangle();
}

/* Output and update for atomic system: '<Root>/IMU' */
void download_IMU(void)
{
  uint16_T rtb_Add6;

  /* IMUangle: '<S4>/angle' */
  if (IMUangle_Receive(&UART3_Temp_Buffer[0], 14)) {/* Non-blocking */
    memcpy(&download_B.angle_o2, &UART3_Temp_Buffer[0], 1*sizeof(uint8_T));/* D0 [1] */
    memcpy(&download_B.angle_o3, &UART3_Temp_Buffer[1], 1*sizeof(uint8_T));/* D1 [1] */
    memcpy(&download_B.angle_o4, &UART3_Temp_Buffer[2], 1*sizeof(uint8_T));/* D2 [1] */
    memcpy(&download_B.angle_o5, &UART3_Temp_Buffer[3], 1*sizeof(uint8_T));/* D3 [1] */
    memcpy(&download_B.angle_o6, &UART3_Temp_Buffer[4], 1*sizeof(uint8_T));/* D4 [1] */
    memcpy(&download_B.angle_o7, &UART3_Temp_Buffer[5], 1*sizeof(uint8_T));/* D5 [1] */
    memcpy(&download_B.angle_o8, &UART3_Temp_Buffer[6], 1*sizeof(uint8_T));/* D6 [1] */
    memcpy(&download_B.angle_o9, &UART3_Temp_Buffer[7], 1*sizeof(uint8_T));/* D7 [1] */
    memcpy(&download_B.angle_o10, &UART3_Temp_Buffer[8], 1*sizeof(uint8_T));/* D8 [1] */
    memcpy(&download_B.angle_o11, &UART3_Temp_Buffer[9], 1*sizeof(uint8_T));/* D9 [1] */
    memcpy(&download_B.angle_o12, &UART3_Temp_Buffer[10], 1*sizeof(uint8_T));/* D10 [1] */
    memcpy(&download_B.angle_o13, &UART3_Temp_Buffer[11], 1*sizeof(uint8_T));/* D11 [1] */
    memcpy(&download_B.angle_o14, &UART3_Temp_Buffer[12], 1*sizeof(uint8_T));/* D12 [1] */
    memcpy(&download_B.angle_o15, &UART3_Temp_Buffer[13], 1*sizeof(uint8_T));/* D13 [1] */
    download_B.angle_o1 = 1;           /* READY */
  } else {
    download_B.angle_o1 = 0;           /* Not READY */
  }

  /* Outputs for Enabled SubSystem: '<S4>/Cal' incorporates:
   *  EnablePort: '<S56>/Enable'
   */
  if (download_B.angle_o1 > 0) {
    /* Sum: '<S56>/Add' incorporates:
     *  ArithShift: '<S56>/Shift Arithmetic'
     *  DataTypeConversion: '<S56>/Data Type Conversion3'
     *  DataTypeConversion: '<S56>/Data Type Conversion4'
     */
    rtb_Add6 = (uint16_T)((uint32_T)(download_B.angle_o2 << 8) +
                          download_B.angle_o3);

    /* Switch: '<S57>/Switch' incorporates:
     *  Constant: '<S57>/Constant'
     *  S-Function (sfix_bitop): '<S57>/Bitwise Operator'
     *  S-Function (sfix_bitop): '<S57>/Bitwise Operator1'
     *  S-Function (sfix_bitop): '<S57>/Bitwise Operator2'
     *  Sum: '<S57>/Sum'
     */
    if ((rtb_Add6 & download_P.BitwiseOperator2_BitMask) >
        download_P.Switch_Threshold) {
      rtb_Add6 = (uint16_T)((uint16_T)(((uint16_T)((uint16_T)~rtb_Add6 |
        download_P.BitwiseOperator1_BitMask) + download_P.Constant_Value_b) >> 1)
                            << 1);
    }

    /* End of Switch: '<S57>/Switch' */

    /* Gain: '<S56>/Gain' incorporates:
     *  DataTypeConversion: '<S56>/Data Type Conversion'
     *  DataTypeConversion: '<S56>/Data Type Conversion9'
     */
    download_B.Gain_n = download_P.Gain_Gain_o * (real32_T)(int16_T)rtb_Add6;

    /* Sum: '<S56>/Add1' incorporates:
     *  ArithShift: '<S56>/Shift Arithmetic1'
     *  DataTypeConversion: '<S56>/Data Type Conversion2'
     *  DataTypeConversion: '<S56>/Data Type Conversion5'
     */
    rtb_Add6 = (uint16_T)((uint32_T)(download_B.angle_o4 << 8) +
                          download_B.angle_o5);

    /* Switch: '<S58>/Switch' incorporates:
     *  Constant: '<S58>/Constant'
     *  S-Function (sfix_bitop): '<S58>/Bitwise Operator'
     *  S-Function (sfix_bitop): '<S58>/Bitwise Operator1'
     *  S-Function (sfix_bitop): '<S58>/Bitwise Operator2'
     *  Sum: '<S58>/Sum'
     */
    if ((rtb_Add6 & download_P.BitwiseOperator2_BitMask_i) >
        download_P.Switch_Threshold_n) {
      rtb_Add6 = (uint16_T)((uint16_T)(((uint16_T)((uint16_T)~rtb_Add6 |
        download_P.BitwiseOperator1_BitMask_a) + download_P.Constant_Value_h) >>
        1) << 1);
    }

    /* End of Switch: '<S58>/Switch' */

    /* Gain: '<S56>/Gain1' incorporates:
     *  DataTypeConversion: '<S56>/Data Type Conversion1'
     *  DataTypeConversion: '<S56>/Data Type Conversion29'
     */
    download_B.Gain1_b = download_P.Gain1_Gain_d * (real32_T)(int16_T)rtb_Add6;

    /* Sum: '<S56>/Add2' incorporates:
     *  ArithShift: '<S56>/Shift Arithmetic2'
     *  DataTypeConversion: '<S56>/Data Type Conversion7'
     *  DataTypeConversion: '<S56>/Data Type Conversion8'
     */
    rtb_Add6 = (uint16_T)((uint32_T)(download_B.angle_o6 << 8) +
                          download_B.angle_o7);

    /* Switch: '<S59>/Switch' incorporates:
     *  Constant: '<S59>/Constant'
     *  S-Function (sfix_bitop): '<S59>/Bitwise Operator'
     *  S-Function (sfix_bitop): '<S59>/Bitwise Operator1'
     *  S-Function (sfix_bitop): '<S59>/Bitwise Operator2'
     *  Sum: '<S59>/Sum'
     */
    if ((rtb_Add6 & download_P.BitwiseOperator2_BitMask_k) >
        download_P.Switch_Threshold_j) {
      rtb_Add6 = (uint16_T)((uint16_T)(((uint16_T)((uint16_T)~rtb_Add6 |
        download_P.BitwiseOperator1_BitMask_k) + download_P.Constant_Value_d) >>
        1) << 1);
    }

    /* End of Switch: '<S59>/Switch' */

    /* Gain: '<S56>/Gain2' incorporates:
     *  DataTypeConversion: '<S56>/Data Type Conversion30'
     *  DataTypeConversion: '<S56>/Data Type Conversion6'
     */
    download_B.Gain2_e = download_P.Gain2_Gain_o * (real32_T)(int16_T)rtb_Add6;

    /* Sum: '<S56>/Add3' incorporates:
     *  ArithShift: '<S56>/Shift Arithmetic3'
     *  DataTypeConversion: '<S56>/Data Type Conversion17'
     *  DataTypeConversion: '<S56>/Data Type Conversion18'
     */
    rtb_Add6 = (uint16_T)((uint32_T)(download_B.angle_o8 << 8) +
                          download_B.angle_o9);

    /* Switch: '<S60>/Switch' incorporates:
     *  Constant: '<S60>/Constant'
     *  S-Function (sfix_bitop): '<S60>/Bitwise Operator'
     *  S-Function (sfix_bitop): '<S60>/Bitwise Operator1'
     *  S-Function (sfix_bitop): '<S60>/Bitwise Operator2'
     *  Sum: '<S60>/Sum'
     */
    if ((rtb_Add6 & download_P.BitwiseOperator2_BitMask_a) >
        download_P.Switch_Threshold_l) {
      rtb_Add6 = (uint16_T)((uint16_T)(((uint16_T)((uint16_T)~rtb_Add6 |
        download_P.BitwiseOperator1_BitMask_i) + download_P.Constant_Value_bo) >>
        1) << 1);
    }

    /* End of Switch: '<S60>/Switch' */

    /* Gain: '<S56>/Gain3' incorporates:
     *  DataTypeConversion: '<S56>/Data Type Conversion12'
     *  DataTypeConversion: '<S56>/Data Type Conversion31'
     */
    download_B.Gain3_m = download_P.Gain3_Gain_l * (real32_T)(int16_T)rtb_Add6;

    /* Sum: '<S56>/Add4' incorporates:
     *  ArithShift: '<S56>/Shift Arithmetic4'
     *  DataTypeConversion: '<S56>/Data Type Conversion16'
     *  DataTypeConversion: '<S56>/Data Type Conversion19'
     */
    rtb_Add6 = (uint16_T)((uint32_T)(download_B.angle_o10 << 8) +
                          download_B.angle_o11);

    /* Switch: '<S61>/Switch' incorporates:
     *  Constant: '<S61>/Constant'
     *  S-Function (sfix_bitop): '<S61>/Bitwise Operator'
     *  S-Function (sfix_bitop): '<S61>/Bitwise Operator1'
     *  S-Function (sfix_bitop): '<S61>/Bitwise Operator2'
     *  Sum: '<S61>/Sum'
     */
    if ((rtb_Add6 & download_P.BitwiseOperator2_BitMask_i0) >
        download_P.Switch_Threshold_jw) {
      rtb_Add6 = (uint16_T)((uint16_T)(((uint16_T)((uint16_T)~rtb_Add6 |
        download_P.BitwiseOperator1_BitMask_n) + download_P.Constant_Value_a) >>
        1) << 1);
    }

    /* End of Switch: '<S61>/Switch' */

    /* Gain: '<S56>/Gain4' incorporates:
     *  DataTypeConversion: '<S56>/Data Type Conversion13'
     *  DataTypeConversion: '<S56>/Data Type Conversion32'
     */
    download_B.Gain4_n = download_P.Gain4_Gain_m * (real32_T)(int16_T)rtb_Add6;

    /* Sum: '<S56>/Add5' incorporates:
     *  ArithShift: '<S56>/Shift Arithmetic5'
     *  DataTypeConversion: '<S56>/Data Type Conversion21'
     *  DataTypeConversion: '<S56>/Data Type Conversion22'
     */
    rtb_Add6 = (uint16_T)((uint32_T)(download_B.angle_o12 << 8) +
                          download_B.angle_o13);

    /* Switch: '<S62>/Switch' incorporates:
     *  Constant: '<S62>/Constant'
     *  S-Function (sfix_bitop): '<S62>/Bitwise Operator'
     *  S-Function (sfix_bitop): '<S62>/Bitwise Operator1'
     *  S-Function (sfix_bitop): '<S62>/Bitwise Operator2'
     *  Sum: '<S62>/Sum'
     */
    if ((rtb_Add6 & download_P.BitwiseOperator2_BitMask_m) >
        download_P.Switch_Threshold_m) {
      rtb_Add6 = (uint16_T)((uint16_T)(((uint16_T)((uint16_T)~rtb_Add6 |
        download_P.BitwiseOperator1_BitMask_g) + download_P.Constant_Value_l) >>
        1) << 1);
    }

    /* End of Switch: '<S62>/Switch' */

    /* Gain: '<S56>/Gain5' incorporates:
     *  DataTypeConversion: '<S56>/Data Type Conversion20'
     *  DataTypeConversion: '<S56>/Data Type Conversion33'
     */
    download_B.Gain5 = download_P.Gain5_Gain_h * (real32_T)(int16_T)rtb_Add6;

    /* Sum: '<S56>/Add6' incorporates:
     *  ArithShift: '<S56>/Shift Arithmetic6'
     *  DataTypeConversion: '<S56>/Data Type Conversion26'
     *  DataTypeConversion: '<S56>/Data Type Conversion27'
     */
    rtb_Add6 = (uint16_T)((uint32_T)(download_B.angle_o14 << 8) +
                          download_B.angle_o15);

    /* Switch: '<S63>/Switch' incorporates:
     *  Constant: '<S63>/Constant'
     *  S-Function (sfix_bitop): '<S63>/Bitwise Operator'
     *  S-Function (sfix_bitop): '<S63>/Bitwise Operator1'
     *  S-Function (sfix_bitop): '<S63>/Bitwise Operator2'
     *  Sum: '<S63>/Sum'
     */
    if ((rtb_Add6 & download_P.BitwiseOperator2_BitMask_o) >
        download_P.Switch_Threshold_ln) {
      rtb_Add6 = (uint16_T)((uint16_T)(((uint16_T)((uint16_T)~rtb_Add6 |
        download_P.BitwiseOperator1_BitMask_m) + download_P.Constant_Value_i) >>
        1) << 1);
    }

    /* End of Switch: '<S63>/Switch' */

    /* Gain: '<S56>/Gain6' incorporates:
     *  DataTypeConversion: '<S56>/Data Type Conversion25'
     *  DataTypeConversion: '<S56>/Data Type Conversion34'
     */
    download_B.Gain6 = download_P.Gain6_Gain * (real32_T)(int16_T)rtb_Add6;
  }

  /* End of Outputs for SubSystem: '<S4>/Cal' */

  /* Gain: '<S4>/Gain1' */
  download_B.Gain1 = download_P.Gain1_Gain_i * download_B.Gain1_b;

  /* Gain: '<S4>/Gain2' */
  download_B.Gain2 = download_P.Gain2_Gain_p * download_B.Gain_n;

  /* Gain: '<S4>/Gain3' */
  download_B.Gain3 = download_P.Gain3_Gain_c * download_B.Gain4_n;

  /* Gain: '<S4>/Gain4' */
  download_B.Gain4 = download_P.Gain4_Gain_f * download_B.Gain5;
}

/* [EOF] */

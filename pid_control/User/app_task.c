#include "app_task.h"

void com1(void)
{
	  real32_T rtb_TSamp;
	  real_T tmp;
	  real_T rtb_y_p;
	  int16_T rtb_Gain_k_idx_0;
    int16_T rtb_Gain_k_idx_1;
	  int16_T rtb_Gain1_l_idx_2;
    int16_T rtb_Gain1_l_idx_3;
    real_T rtb_Gain2_b_idx_1;
    real_T rtb_Gain2_b_idx_2;
    real_T rtb_Gain2_b_idx_3;
	  download_B.RateTransition1[0] = download_B.yaw_H;
    download_B.RateTransition1[1] = download_B.yaw_L;
    download_B.RateTransition1[2] = download_B.pitch_H;
    download_B.RateTransition1[3] = download_B.pitch_L;
    download_B.RateTransition1[4] = download_B.roll_H;
    download_B.RateTransition1[5] = download_B.roll_L;
    download_B.RateTransition1[6] = download_B.p_H;
    download_B.RateTransition1[7] = download_B.p_L;
    download_B.RateTransition1[8] = download_B.q_H;
    download_B.RateTransition1[9] = download_B.q_L;
    download_B.RateTransition1[10] = download_B.r_H;
    download_B.RateTransition1[11] = download_B.r_L;
    download_B.RateTransition1[12] = download_B.alt_H;
    download_B.RateTransition1[13] = download_B.alt_L;
    /* Gain: '<S11>/Gain1' incorporates:
     *  SignalConversion: '<S11>/TmpSignal ConversionAtGain1Inport1'
     */
	 /* Gain: '<S11>/Gain' */
    rtb_TSamp = (real32_T)floor(download_P.Gain_Gain_a *
      download_B.RateTransition2[0]);
    if (rtIsNaNF(rtb_TSamp) || rtIsInfF(rtb_TSamp)) {
      rtb_TSamp = 0.0F;
    } else {
      rtb_TSamp = (real32_T)fmod(rtb_TSamp, 65536.0F);
    }

    rtb_Gain_k_idx_0 = (int16_T)(rtb_TSamp < 0.0F ? (int32_T)(int16_T)-(int16_T)
                                 (uint16_T)-rtb_TSamp : (int32_T)(int16_T)
      (uint16_T)rtb_TSamp);
    rtb_TSamp = (real32_T)floor(download_P.Gain_Gain_a *
      download_B.RateTransition2[1]);
    if (rtIsNaNF(rtb_TSamp) || rtIsInfF(rtb_TSamp)) {
      rtb_TSamp = 0.0F;
    } else {
      rtb_TSamp = (real32_T)fmod(rtb_TSamp, 65536.0F);
    }

    rtb_Gain_k_idx_1 = (int16_T)(rtb_TSamp < 0.0F ? (int32_T)(int16_T)-(int16_T)
                                 (uint16_T)-rtb_TSamp : (int32_T)(int16_T)
      (uint16_T)rtb_TSamp);

    /* End of Gain: '<S11>/Gain' */

    /* DataTypeConversion: '<S11>/Data Type Conversion4' incorporates:
     *  ArithShift: '<S11>/Shift Arithmetic'
     */
    download_B.DataTypeConversion4 = (uint8_T)(rtb_Gain_k_idx_0 >> 8);

    /* DataTypeConversion: '<S11>/Data Type Conversion1' */
    download_B.DataTypeConversion1 = (uint8_T)rtb_Gain_k_idx_0;

    /* DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
     *  ArithShift: '<S11>/Shift Arithmetic1'
     */
    download_B.DataTypeConversion3 = (uint8_T)(rtb_Gain_k_idx_1 >> 8);

    /* DataTypeConversion: '<S11>/Data Type Conversion2' */
    download_B.DataTypeConversion2 = (uint8_T)rtb_Gain_k_idx_1;
	  /* RateTransition: '<S11>/Rate Transition3' incorporates:
   *  RateTransition: '<S11>/Rate Transition3'
   */
	  download_B.rollCH1_e = download_B.Guidance_System.Saturation_b;
    download_B.pitchCH2_i = download_B.Guidance_System.Saturation_a;
    download_B.thrustCH3_o = download_B.Guidance_System.Saturation;
    download_B.yawCH4_l = download_B.Guidance_System.Saturation_d;
    rtb_TSamp = (real32_T)floor(download_P.Gain1_Gain_m * download_B.rollCH1_e);
    if (rtIsNaNF(rtb_TSamp) || rtIsInfF(rtb_TSamp)) {
      rtb_TSamp = 0.0F;
    } else {
      rtb_TSamp = (real32_T)fmod(rtb_TSamp, 65536.0F);
    }

    rtb_Gain_k_idx_0 = (int16_T)(rtb_TSamp < 0.0F ? (int32_T)(int16_T)-(int16_T)
                                 (uint16_T)-rtb_TSamp : (int32_T)(int16_T)
      (uint16_T)rtb_TSamp);
    rtb_TSamp = (real32_T)floor(download_P.Gain1_Gain_m * download_B.pitchCH2_i);
    if (rtIsNaNF(rtb_TSamp) || rtIsInfF(rtb_TSamp)) {
      rtb_TSamp = 0.0F;
    } else {
      rtb_TSamp = (real32_T)fmod(rtb_TSamp, 65536.0F);
    }

    rtb_Gain_k_idx_1 = (int16_T)(rtb_TSamp < 0.0F ? (int32_T)(int16_T)-(int16_T)
                                 (uint16_T)-rtb_TSamp : (int32_T)(int16_T)
      (uint16_T)rtb_TSamp);
    rtb_TSamp = (real32_T)floor(download_P.Gain1_Gain_m * download_B.thrustCH3_o);
    if (rtIsNaNF(rtb_TSamp) || rtIsInfF(rtb_TSamp)) {
      rtb_TSamp = 0.0F;
    } else {
      rtb_TSamp = (real32_T)fmod(rtb_TSamp, 65536.0F);
    }

    rtb_Gain1_l_idx_2 = (int16_T)(rtb_TSamp < 0.0F ? (int32_T)(int16_T)-(int16_T)
                                  (uint16_T)-rtb_TSamp : (int32_T)(int16_T)
      (uint16_T)rtb_TSamp);
    rtb_TSamp = (real32_T)floor(download_P.Gain1_Gain_m * download_B.yawCH4_l);
    if (rtIsNaNF(rtb_TSamp) || rtIsInfF(rtb_TSamp)) {
      rtb_TSamp = 0.0F;
    } else {
      rtb_TSamp = (real32_T)fmod(rtb_TSamp, 65536.0F);
    }

    rtb_Gain1_l_idx_3 = (int16_T)(rtb_TSamp < 0.0F ? (int32_T)(int16_T)-(int16_T)
                                  (uint16_T)-rtb_TSamp : (int32_T)(int16_T)
      (uint16_T)rtb_TSamp);

    /* End of Gain: '<S11>/Gain1' */

    /* DataTypeConversion: '<S11>/Data Type Conversion8' incorporates:
     *  ArithShift: '<S11>/Shift Arithmetic2'
     */
    download_B.DataTypeConversion8 = (uint8_T)(rtb_Gain_k_idx_0 >> 8);

    /* DataTypeConversion: '<S11>/Data Type Conversion5' */
    download_B.DataTypeConversion5 = (uint8_T)rtb_Gain_k_idx_0;

    /* DataTypeConversion: '<S11>/Data Type Conversion7' incorporates:
     *  ArithShift: '<S11>/Shift Arithmetic3'
     */
    download_B.DataTypeConversion7 = (uint8_T)(rtb_Gain_k_idx_1 >> 8);

    /* DataTypeConversion: '<S11>/Data Type Conversion6' */
    download_B.DataTypeConversion6 = (uint8_T)rtb_Gain_k_idx_1;

    /* DataTypeConversion: '<S11>/Data Type Conversion12' incorporates:
     *  ArithShift: '<S11>/Shift Arithmetic4'
     */
    download_B.DataTypeConversion12 = (uint8_T)(rtb_Gain1_l_idx_2 >> 8);

    /* DataTypeConversion: '<S11>/Data Type Conversion9' */
    download_B.DataTypeConversion9 = (uint8_T)rtb_Gain1_l_idx_2;

    /* DataTypeConversion: '<S11>/Data Type Conversion11' incorporates:
     *  ArithShift: '<S11>/Shift Arithmetic5'
     */
    download_B.DataTypeConversion11 = (uint8_T)(rtb_Gain1_l_idx_3 >> 8);

    /* DataTypeConversion: '<S11>/Data Type Conversion10' */
    download_B.DataTypeConversion10 = (uint8_T)rtb_Gain1_l_idx_3;

    /* RateTransition: '<S11>/Rate Transition4' */
    download_B.RateTransition4[0] = download_B.Angle_hold.Sum[0];
    download_B.RateTransition4[1] = download_B.Angle_hold.Sum[1];
    download_B.RateTransition4[2] = download_B.Angle_hold.Sum[2];
    download_B.RateTransition4[3] = download_B.Angle_hold.Sum[3];

    /* Gain: '<S11>/Gain2' */
    rtb_y_p = download_P.Gain2_Gain_h * download_B.RateTransition4[0];
    rtb_Gain2_b_idx_1 = download_P.Gain2_Gain_h * download_B.RateTransition4[1];
    rtb_Gain2_b_idx_2 = download_P.Gain2_Gain_h * download_B.RateTransition4[2];
    rtb_Gain2_b_idx_3 = download_P.Gain2_Gain_h * download_B.RateTransition4[3];

    /* DataTypeConversion: '<S11>/Data Type Conversion19' incorporates:
     *  ArithShift: '<S11>/Shift Arithmetic6'
     */
    tmp = floor(ldexp(rtb_y_p, -8));
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 256.0);
    }

    download_B.DataTypeConversion19 = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)
      -(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);

    /* End of DataTypeConversion: '<S11>/Data Type Conversion19' */

    /* DataTypeConversion: '<S11>/Data Type Conversion16' */
    tmp = floor(rtb_y_p);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 256.0);
    }

    download_B.DataTypeConversion16 = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)
      -(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);

    /* End of DataTypeConversion: '<S11>/Data Type Conversion16' */

    /* DataTypeConversion: '<S11>/Data Type Conversion18' incorporates:
     *  ArithShift: '<S11>/Shift Arithmetic7'
     */
    tmp = floor(ldexp(rtb_Gain2_b_idx_1, -8));
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 256.0);
    }

    download_B.DataTypeConversion18 = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)
      -(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);

    /* End of DataTypeConversion: '<S11>/Data Type Conversion18' */

    /* DataTypeConversion: '<S11>/Data Type Conversion17' */
    tmp = floor(rtb_Gain2_b_idx_1);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 256.0);
    }

    download_B.DataTypeConversion17 = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)
      -(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);

    /* End of DataTypeConversion: '<S11>/Data Type Conversion17' */

    /* DataTypeConversion: '<S11>/Data Type Conversion15' incorporates:
     *  ArithShift: '<S11>/Shift Arithmetic8'
     */
    tmp = floor(ldexp(rtb_Gain2_b_idx_2, -8));
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 256.0);
    }

    download_B.DataTypeConversion15 = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)
      -(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);

    /* End of DataTypeConversion: '<S11>/Data Type Conversion15' */

    /* DataTypeConversion: '<S11>/Data Type Conversion20' */
    tmp = floor(rtb_Gain2_b_idx_2);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 256.0);
    }

    download_B.DataTypeConversion20 = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)
      -(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);

    /* End of DataTypeConversion: '<S11>/Data Type Conversion20' */

    /* DataTypeConversion: '<S11>/Data Type Conversion14' incorporates:
     *  ArithShift: '<S11>/Shift Arithmetic9'
     */
    tmp = floor(ldexp(rtb_Gain2_b_idx_3, -8));
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 256.0);
    }

    download_B.DataTypeConversion14 = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)
      -(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);

    /* End of DataTypeConversion: '<S11>/Data Type Conversion14' */

    /* DataTypeConversion: '<S11>/Data Type Conversion13' */
    tmp = floor(rtb_Gain2_b_idx_3);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 256.0);
    }

    download_B.DataTypeConversion13 = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)
      -(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);

    /* End of DataTypeConversion: '<S11>/Data Type Conversion13' */

    /* toshangweijiUARTTx: '<S11>/UART Tx' */
    {
      /* Flush tx, so we can put data directly to DMA buffer */
      UART1_FlushTxBuffer();

      /* Put data into buffer */
      UART1_Tx_Buffer[0] = 165;        /* Header 0 */
      UART1_Tx_Buffer[1] = 90;         /* Header 1 */
      UART1_Tx_Buffer[2] = 37;         /* Header 2 */
      UART1_Tx_Buffer[3] = 166;        /* Header 3 */
      memcpy(&UART1_Tx_Buffer[4], &download_B.RateTransition1[0], 34*sizeof
             (uint8_T));               /* Data 0 [34]*/
      UART1_Tx_Buffer[38] = 170;       /* Terminator 0 */

      /* Write to DMA, 39 bytes */
      UART1_TxUpdate(39);              /* Only update since data is ready on Tx buffer */
    }

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
				OSTimeDlyHMSM(0, 0, 0,50);//周期50ms
        UART1_TxUpdate(strlen((char*)UART1_Tx_Buffer));
      }

      /* Inport: '<S15>/P' */
      download_B.P_e = download_B.UARTRx3_o2;

      /* Inport: '<S15>/nP' */
      download_B.nP_i = download_B.UARTRx3_o3;

      /* Inport: '<S15>/nI' */
      download_B.nI_e = download_B.UARTRx3_o4;

      /* Inport: '<S15>/nD' */
      download_B.nD_l = download_B.UARTRx3_o5;

      /* Inport: '<S15>/status' */
      download_B.status_o = download_B.UARTRx3_o6;
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
				OSTimeDlyHMSM(0, 0, 0,50);//周期50ms
        UART1_TxUpdate(strlen((char*)UART1_Tx_Buffer));
      }

      /* Inport: '<S16>/P' */
      download_B.P_g = download_B.UARTRx4_o2;

      /* Inport: '<S16>/nP' */
      download_B.nP_m = download_B.UARTRx4_o3;

      /* Inport: '<S16>/nI' */
      download_B.nI_a = download_B.UARTRx4_o4;

      /* Inport: '<S16>/nD' */
      download_B.nD_d = download_B.UARTRx4_o5;

      /* Inport: '<S16>/status' */
      download_B.status_k = download_B.UARTRx4_o6;
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
				OSTimeDlyHMSM(0, 0, 0,50);//周期50ms
        UART1_TxUpdate(strlen((char*)UART1_Tx_Buffer));
      }

      /* Inport: '<S17>/P' */
      download_B.P = download_B.UARTRx5_o2;

      /* Inport: '<S17>/nP' */
      download_B.nP = download_B.UARTRx5_o3;

      /* Inport: '<S17>/nI' */
      download_B.nI = download_B.UARTRx5_o4;

      /* Inport: '<S17>/nD' */
      download_B.nD = download_B.UARTRx5_o5;

      /* Inport: '<S17>/status' */
      download_B.status = download_B.UARTRx5_o6;
    } else {
      if (download_DW.EnabledSubsystem6_MODE) {
        download_DW.EnabledSubsystem6_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem6' */
}
void control(void)
{
	real_T rtb_Gain1;
  real_T rtb_Gain3;
	real_T rtb_HiddenBuf_InsertedFor_Angle;
  real32_T rtb_TmpSignalConversionAtAngle_[5];
  real32_T rtb_TmpSignalConversionAtAngl_c[5];
  real32_T rtb_TmpSignalConversionAtAngl_g[5];
  real32_T rtb_TmpSignalConversionAtAngl_p[2];
	static float rtb_Saturation0=0,alt=0,last_alt=0,count=0;
  real32_T stageIn; 
	real32_T rtb_Saturation;
	real32_T rtb_DataTypeConversion1_n;
	real_T rtb_y_o;
  real32_T rtb_TSamp;
	int32_T memIdx;
  int32_T numIdx;
  int32_T denIdx;
  real32_T numAccum;
  real_T numAccum_0;
  int32_T j;
	
	download_B.rollCH1 = download_B.Guidance_System.Saturation_b;
  download_B.pitchCH2 = download_B.Guidance_System.Saturation_a;
  download_B.thrustCH3 = download_B.Guidance_System.Saturation;
  download_B.yawCH4 = download_B.Guidance_System.Saturation_d;
  download_B.Angle[0] = download_B.Gain2_e;
  download_B.Angle[1] = download_B.Gain1;
  download_B.Angle[2] = download_B.Gain2;
  download_B.Angle_rate[0] = download_B.Gain3_m;
  download_B.Angle_rate[1] = download_B.Gain3;
  download_B.Angle_rate[2] = download_B.Gain4;
	if(count==0)
	{
	last_alt=download_B.Gain6;
	count=1;
	}
	if(fabs(download_B.Gain6-last_alt)>0.5)
	{
	download_B.alt = last_alt;
	}
	else
	{
	download_B.alt=download_B.Gain6;
	last_alt=download_B.Gain6;
	}
	
	 /* SignalConversion: '<S2>/TmpSignal ConversionAtAngle_holdInport3' */
  rtb_TmpSignalConversionAtAngle_[0] = download_B.P_e;
  rtb_TmpSignalConversionAtAngle_[1] = download_B.nP_i;
  rtb_TmpSignalConversionAtAngle_[2] = download_B.nI_e;
  rtb_TmpSignalConversionAtAngle_[3] = download_B.nD_l;
  rtb_TmpSignalConversionAtAngle_[4] = download_B.status_o;
	  /* SignalConversion: '<S2>/TmpSignal ConversionAtAngle_holdInport4' */
  rtb_TmpSignalConversionAtAngl_c[0] = download_B.P_g;
  rtb_TmpSignalConversionAtAngl_c[1] = download_B.nP_m;
  rtb_TmpSignalConversionAtAngl_c[2] = download_B.nI_a;
  rtb_TmpSignalConversionAtAngl_c[3] = download_B.nD_d;
  rtb_TmpSignalConversionAtAngl_c[4] = download_B.status_k;
	   /* SignalConversion: '<S2>/TmpSignal ConversionAtAngle_holdInport5' */
  rtb_TmpSignalConversionAtAngl_g[0] = download_B.P;
  rtb_TmpSignalConversionAtAngl_g[1] = download_B.nP;
  rtb_TmpSignalConversionAtAngl_g[2] = download_B.nI;
  rtb_TmpSignalConversionAtAngl_g[3] = download_B.nD;
  rtb_TmpSignalConversionAtAngl_g[4] = download_B.status;
    /* MATLAB Function: '<S2>/MATLAB Function' */
    /* MATLAB Function 'Controller/MATLAB Function': '<S21>:1' */
    if ((download_B.thrustCH3 < 0.1) && (download_B.yawCH4 < -160.0F)) {
      /* '<S21>:1:7' */
      /* '<S21>:1:8' */
      download_DW.status = 1.0;
    } else {
      if ((download_B.thrustCH3 < 0.1) && (download_B.yawCH4 > 160.0F)) {
        /* '<S21>:1:9' */
        /* '<S21>:1:10' */
        download_DW.status = 0.0;
      }
    }

    /* Outputs for Atomic SubSystem: '<S2>/Velocity_Damper2' */
    /* SampleTimeMath: '<S51>/TSamp'
     *
     * About '<S51>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    /* '<S21>:1:12' */
		alt=alt*0.9+download_B.alt*0.1;
    rtb_TSamp = alt * download_P.TSamp_WtEt;
    
    /* Sum: '<S51>/Diff' incorporates:
     *  UnitDelay: '<S51>/UD'
     */
    rtb_Saturation = rtb_TSamp - download_DW.UD_DSTATE;
    rtb_Saturation0=rtb_Saturation0*0.9+rtb_Saturation*0.1;
		rtb_Saturation =rtb_Saturation0;
    /* Saturate: '<S49>/Saturation' */
    if (rtb_Saturation > download_P.Saturation_UpperSat) {
      rtb_Saturation = download_P.Saturation_UpperSat;
    } else {
      if (rtb_Saturation < download_P.Saturation_LowerSat) {
        rtb_Saturation = download_P.Saturation_LowerSat;
      }
    }

    /* End of Saturate: '<S49>/Saturation' */

    /* MATLAB Function: '<S24>/MATLAB Function' incorporates:
     *  DataTypeConversion: '<S24>/Data Type Conversion3'
     *  MATLAB Function: '<S2>/MATLAB Function'
     */
    /* MATLAB Function 'Controller/Velocity_Damper2/MATLAB Function': '<S50>:1' */
    if ((download_DW.status == 1.0) && (download_DW.count == 0.0)) {
      /* '<S50>:1:10' */
      /* '<S50>:1:11' */
      download_DW.count = 1.0;

      /* '<S50>:1:12' */
      download_DW.altitude_basic = alt;
    } else {
      if ((download_DW.status == 0.0) && (download_DW.count == 1.0)) {
        /* '<S50>:1:13' */
        /* '<S50>:1:14' */
        download_DW.count = 0.0;
      }
    }

    /* DataTypeConversion: '<S24>/Data Type Conversion1' incorporates:
     *  DataTypeConversion: '<S24>/Data Type Conversion3'
     *  MATLAB Function: '<S24>/MATLAB Function'
     */
    /* '<S50>:1:16' */
    rtb_DataTypeConversion1_n = (real32_T)(alt -
      download_DW.altitude_basic);

    /* Update for UnitDelay: '<S51>/UD' */
    download_DW.UD_DSTATE = rtb_TSamp;

    /* SignalConversion: '<S2>/TmpSignal ConversionAtAngle_holdInport6' incorporates:
     *  DataTypeConversion: '<S24>/Data Type Conversion1'
     *  DataTypeConversion: '<S24>/Data Type Conversion3'
     *  MATLAB Function: '<S24>/MATLAB Function'
     */
    rtb_TmpSignalConversionAtAngl_p[0] = rtb_DataTypeConversion1_n;

    /* End of Outputs for SubSystem: '<S2>/Velocity_Damper2' */
    rtb_TmpSignalConversionAtAngl_p[1] = rtb_Saturation;

    /* SignalConversion: '<S2>/HiddenBuf_InsertedFor_Angle_hold_at_inport_6' incorporates:
     *  MATLAB Function: '<S2>/MATLAB Function'
     */
    rtb_HiddenBuf_InsertedFor_Angle = download_DW.status;

    /* Outputs for Enabled SubSystem: '<S2>/Angle_hold' */
    download_Angle_hold(rtb_HiddenBuf_InsertedFor_Angle, download_B.thrustCH3,
                        download_B.pitchCH2, download_B.rollCH1,
                        download_B.Angle, rtb_TmpSignalConversionAtAngle_,
                        download_B.Angle_rate, download_B.yawCH4,
                        rtb_TmpSignalConversionAtAngl_c,
                        rtb_TmpSignalConversionAtAngl_p,
                        rtb_TmpSignalConversionAtAngl_g, &download_B.Angle_hold,
                        &download_DW.Angle_hold, (P_Angle_hold_download_T *)
                        &download_P.Angle_hold);

    /* End of Outputs for SubSystem: '<S2>/Angle_hold' */

    /* Saturate: '<S9>/Saturation' */
    if (download_B.Angle_hold.Sum[0] > download_P.Saturation_UpperSat_l) {
      rtb_TSamp = download_P.Saturation_UpperSat_l;
    } else if (download_B.Angle_hold.Sum[0] < download_P.Saturation_LowerSat_g)
    {
      rtb_TSamp = download_P.Saturation_LowerSat_g;
    } else {
      rtb_TSamp = download_B.Angle_hold.Sum[0];
    }

    /* Gain: '<S9>/Gain' incorporates:
     *  Saturate: '<S9>/Saturation'
     */
    download_B.Gain[0] = download_P.Gain_Gain_b * rtb_TSamp;

    /* Saturate: '<S9>/Saturation' */
    if (download_B.Angle_hold.Sum[1] > download_P.Saturation_UpperSat_l) {
      rtb_TSamp = download_P.Saturation_UpperSat_l;
    } else if (download_B.Angle_hold.Sum[1] < download_P.Saturation_LowerSat_g)
    {
      rtb_TSamp = download_P.Saturation_LowerSat_g;
    } else {
      rtb_TSamp = download_B.Angle_hold.Sum[1];
    }

    /* Gain: '<S9>/Gain' incorporates:
     *  Saturate: '<S9>/Saturation'
     */
    download_B.Gain[1] = download_P.Gain_Gain_b * rtb_TSamp;

    /* Saturate: '<S9>/Saturation' */
    if (download_B.Angle_hold.Sum[2] > download_P.Saturation_UpperSat_l) {
      rtb_TSamp = download_P.Saturation_UpperSat_l;
    } else if (download_B.Angle_hold.Sum[2] < download_P.Saturation_LowerSat_g)
    {
      rtb_TSamp = download_P.Saturation_LowerSat_g;
    } else {
      rtb_TSamp = download_B.Angle_hold.Sum[2];
    }

    /* Gain: '<S9>/Gain' incorporates:
     *  Saturate: '<S9>/Saturation'
     */
    download_B.Gain[2] = download_P.Gain_Gain_b * rtb_TSamp;

    /* Saturate: '<S9>/Saturation' */
    if (download_B.Angle_hold.Sum[3] > download_P.Saturation_UpperSat_l) {
      rtb_TSamp = download_P.Saturation_UpperSat_l;
    } else if (download_B.Angle_hold.Sum[3] < download_P.Saturation_LowerSat_g)
    {
      rtb_TSamp = download_P.Saturation_LowerSat_g;
    } else {
      rtb_TSamp = download_B.Angle_hold.Sum[3];
    }

    /* Gain: '<S9>/Gain' incorporates:
     *  Saturate: '<S9>/Saturation'
     */
    download_B.Gain[3] = download_P.Gain_Gain_b * rtb_TSamp;

    /* S-Function Block: <S9>/Basic PWM7 (stm32f4_basicpwm) */
    TIM4->CCR1 = (uint32_t) (download_B.Gain[0] * executeBasicPWM7_SF);
    TIM4->CCR2 = (uint32_t) (download_B.Gain[1] * executeBasicPWM7_SF);
    TIM4->CCR3 = (uint32_t) (download_B.Gain[2] * executeBasicPWM7_SF);
    TIM4->CCR4 = (uint32_t) (download_B.Gain[3] * executeBasicPWM7_SF);
		//准备发给上位机的飞行高度和飞行高度方向的速度
		download_B.RateTransition2[0] = rtb_DataTypeConversion1_n;
    download_B.RateTransition2[1] = rtb_Saturation;
}

void IMU(void)
{
       /* Outputs for Atomic SubSystem: '<Root>/IMU' */
       download_IMU();

      /* End of Outputs for SubSystem: '<Root>/IMU' */
		  /* OrangeLED1BlueLED */
      *OrangeLED1BlueLED_C2 = (boolean_T) download_B.angle_o1;
}
void Rec(void)
{
  	uint16_T rtb_Add3;
		real_T rtb_Gain1;
	  real_T rtb_Gain3;
	  uint16_T rtb_ShiftArithmetic5_b;
	  uint16_T rtb_ShiftArithmetic3_h;
	  real_T rtb_y_o;
	  uint16_T rtb_ShiftArithmetic4_f;
 /* ReceiverUARTRx3: '<S8>/UART Rx3' */
    if (ReceiverUARTRx3_Receive(&UART2_Temp_Buffer[0], 23)) {/* Non-blocking */
      memcpy(&download_B.UARTRx3_o2_j[0], &UART2_Temp_Buffer[0], 23*sizeof
             (uint8_T));               /* D0 [23] */
      download_B.UARTRx3_o1 = 1;       /* READY */
    } else {
      download_B.UARTRx3_o1 = 0;       /* Not READY */
    }

    /* Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S70>/Enable'
     */
    if (download_B.UARTRx3_o1 > 0) {
      /* ArithShift: '<S70>/Shift Arithmetic3' incorporates:
       *  DataTypeConversion: '<S70>/Data Type Conversion5'
       */
      rtb_ShiftArithmetic3_h = (uint16_T)(download_B.UARTRx3_o2_j[2] >> 6);

      /* ArithShift: '<S70>/Shift Arithmetic4' incorporates:
       *  DataTypeConversion: '<S70>/Data Type Conversion6'
       */
      rtb_ShiftArithmetic4_f = (uint16_T)(download_B.UARTRx3_o2_j[3] << 2);

      /* ArithShift: '<S70>/Shift Arithmetic5' incorporates:
       *  S-Function (sfix_bitop): '<S70>/Bitwise Operator7'
       */
      rtb_ShiftArithmetic5_b = (uint16_T)((uint16_T)(download_B.UARTRx3_o2_j[4]
        & download_P.BitwiseOperator7_BitMask) << 10);

      /* Sum: '<S70>/Add3' incorporates:
       *  ArithShift: '<S70>/Shift Arithmetic6'
       *  ArithShift: '<S70>/Shift Arithmetic7'
       *  S-Function (sfix_bitop): '<S70>/Bitwise Operator1'
       *  S-Function (sfix_bitop): '<S70>/Bitwise Operator2'
       */
      rtb_Add3 = (uint16_T)((uint32_T)((download_B.UARTRx3_o2_j[4] &
        download_P.BitwiseOperator1_BitMask_ac) >> 1) +
                            ((download_B.UARTRx3_o2_j[5] &
        download_P.BitwiseOperator2_BitMask_n) << 7));

      /* MATLAB Function: '<S70>/MATLAB Function1' incorporates:
       *  ArithShift: '<S70>/Shift Arithmetic'
       *  DataTypeConversion: '<S70>/Data Type Conversion4'
       *  DataTypeConversion: '<S70>/Data Type Conversion8'
       *  Gain: '<S70>/Gain'
       *  S-Function (sfix_bitop): '<S70>/Bitwise Operator5'
       *  Sum: '<S70>/Add'
       */
      /* MATLAB Function 'Receiver/Enabled Subsystem/MATLAB Function1': '<S71>:1' */
      /* 输入范围为0.34~1.7，将其调整到1~2ms */
      /* '<S71>:1:4' */
      rtb_y_o = (real_T)((uint32_T)((download_B.UARTRx3_o2_j[1] &
        download_P.BitwiseOperator5_BitMask) << 8) + download_B.UARTRx3_o2_j[0])
        * download_P.Gain_Gain / 1.375;
      if ((rtb_y_o + 0.76 > 0.8) && (rtb_y_o + 0.76 < 2.1)) {
        /* '<S71>:1:5' */
        /* '<S71>:1:6' */
        rtb_y_o += 0.76;
      } else {
        /* '<S71>:1:8' */
        rtb_y_o = 1.5;
      }

      /* End of MATLAB Function: '<S70>/MATLAB Function1' */

      /* DataTypeConversion: '<S70>/Data Type Conversion' */
      download_B.CH1 = (real32_T)rtb_y_o;

      /* Gain: '<S70>/Gain1' incorporates:
       *  ArithShift: '<S70>/Shift Arithmetic1'
       *  ArithShift: '<S70>/Shift Arithmetic2'
       *  DataTypeConversion: '<S70>/Data Type Conversion1'
       *  DataTypeConversion: '<S70>/Data Type Conversion9'
       *  S-Function (sfix_bitop): '<S70>/Bitwise Operator6'
       *  Sum: '<S70>/Add1'
       */
      rtb_Gain1 = (real_T)((uint32_T)((download_B.UARTRx3_o2_j[2] &
        download_P.BitwiseOperator6_BitMask) << 5) + (download_B.UARTRx3_o2_j[1]
        >> 3)) * download_P.Gain1_Gain;

      /* MATLAB Function: '<S70>/MATLAB Function2' */
      download_MATLABFunction2(rtb_Gain1, &download_B.sf_MATLABFunction2);

      /* DataTypeConversion: '<S70>/Data Type Conversion11' */
      download_B.CH2 = (real32_T)download_B.sf_MATLABFunction2.y;

      /* MATLAB Function: '<S70>/MATLAB Function3' incorporates:
       *  DataTypeConversion: '<S70>/Data Type Conversion10'
       *  Gain: '<S70>/Gain2'
       *  Sum: '<S70>/Add2'
       */
      /* MATLAB Function 'Receiver/Enabled Subsystem/MATLAB Function3': '<S73>:1' */
      /* 输入范围为0.34~1.7，将其调整到1~2ms */
      /* '<S73>:1:4' */
      rtb_y_o = (real_T)(uint16_T)(((uint32_T)rtb_ShiftArithmetic3_h +
        rtb_ShiftArithmetic4_f) + rtb_ShiftArithmetic5_b) *
        download_P.Gain2_Gain / 1.375;
      if ((rtb_y_o + 0.75 > 1.0) && (rtb_y_o + 0.75 < 2.1)) {
        /* '<S73>:1:5' */
        /* '<S73>:1:6' */
        rtb_y_o += 0.75;
      } else {
        /* '<S73>:1:8' */
        rtb_y_o = 1.0;
      }

      /* End of MATLAB Function: '<S70>/MATLAB Function3' */

      /* DataTypeConversion: '<S70>/Data Type Conversion12' */
      download_B.CH3 = (real32_T)rtb_y_o;

      /* Gain: '<S70>/Gain3' incorporates:
       *  DataTypeConversion: '<S70>/Data Type Conversion15'
       */
      rtb_Gain3 = download_P.Gain3_Gain * (real_T)rtb_Add3;

      /* MATLAB Function: '<S70>/MATLAB Function4' */
      download_MATLABFunction2(rtb_Gain3, &download_B.sf_MATLABFunction4);

      /* DataTypeConversion: '<S70>/Data Type Conversion16' */
      download_B.CH4 = (real32_T)download_B.sf_MATLABFunction4.y;
    }

    /* End of Outputs for SubSystem: '<S8>/Enabled Subsystem' */

    /* Outputs for Atomic SubSystem: '<Root>/Guidance_System' */
    download_Guidance_System(download_B.CH3, download_B.CH4, download_B.CH2,
      download_B.CH1, &download_B.Guidance_System, (P_Guidance_System_download_T
      *)&download_P.Guidance_System);

    /* End of Outputs for SubSystem: '<Root>/Guidance_System' */

}

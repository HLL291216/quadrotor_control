/*
 * File: waijung_hwdrvlib.c
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

#include "waijung_hwdrvlib.h"

/* Unique ID data */
uint32_t UID32_fromshangweijiEnabledSubsystem2ReadUniqueID[3];

/* ########################################################################
 * Name: <S18>/UART Tx
 * Id: fromshangweijiEnabledSubsystem1IfActionSubsystemUARTTx
 * ########################################################################
 */

/* Enable UART-DMA module */
void enable_fromshangweijiEnabledSubsystem1IfActionSubsystemUARTTx(void)
{
}

/* ########################################################################
 * Name: <S19>/UART Tx
 * Id: fromshangweijiEnabledSubsystem1IfActionSubsystem1UARTTx
 * ########################################################################
 */

/* Enable UART-DMA module */
void enable_fromshangweijiEnabledSubsystem1IfActionSubsystem1UARTTx(void)
{
}

/* ########################################################################
 * Name: <S12>/Digital Output
 * Id: fromshangweijiEnabledSubsystem1DigitalOutput
 * ########################################################################
 */
uint16_t fromshangweijiEnabledSubsystem1DigitalOutput_portVal;
void enable_fromshangweijiEnabledSubsystem1DigitalOutput(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

  /* Configure PC in output Push Pull mode for fromshangweijiEnabledSubsystem1DigitalOutput Block*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;/* Waijung 14.xx */
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}

/* Eanble Unique ID Read */
void enable_fromshangweijiEnabledSubsystem2ReadUniqueID(void)
{
  UID32_fromshangweijiEnabledSubsystem2ReadUniqueID[0] = * (volatile uint32_t*)
    UID32BaseAddress_fromshangweijiEnabledSubsystem2ReadUniqueID;
  UID32_fromshangweijiEnabledSubsystem2ReadUniqueID[1] = * (volatile uint32_t*)
    (UID32BaseAddress_fromshangweijiEnabledSubsystem2ReadUniqueID + 4);
  UID32_fromshangweijiEnabledSubsystem2ReadUniqueID[2] = * (volatile uint32_t*)
    (UID32BaseAddress_fromshangweijiEnabledSubsystem2ReadUniqueID + 8);
}

/* ########################################################################
 * Name: <S13>/UART Tx
 * Id: fromshangweijiEnabledSubsystem2UARTTx
 * ########################################################################
 */

/* Enable UART-DMA module */
void enable_fromshangweijiEnabledSubsystem2UARTTx(void)
{
}

/* ########################################################################
 * Name: <S14>/UART Tx
 * Id: fromshangweijiEnabledSubsystem3UARTTx
 * ########################################################################
 */

/* Enable UART-DMA module */
void enable_fromshangweijiEnabledSubsystem3UARTTx(void)
{
}

/* ########################################################################
 * Name: <S15>/UART Tx
 * Id: fromshangweijiEnabledSubsystem4UARTTx
 * ########################################################################
 */

/* Enable UART-DMA module */
void enable_fromshangweijiEnabledSubsystem4UARTTx(void)
{
}

/* ########################################################################
 * Name: <S16>/UART Tx
 * Id: fromshangweijiEnabledSubsystem5UARTTx
 * ########################################################################
 */

/* Enable UART-DMA module */
void enable_fromshangweijiEnabledSubsystem5UARTTx(void)
{
}

/* ########################################################################
 * Name: <S17>/UART Tx
 * Id: fromshangweijiEnabledSubsystem6UARTTx
 * ########################################################################
 */

/* Enable UART-DMA module */
void enable_fromshangweijiEnabledSubsystem6UARTTx(void)
{
}

/* ########################################################################
 * Name: <S4>/angle
 * Id: IMUangle
 * ########################################################################
 */

/* Data read structure */
UARTRX_BUFFER_READ_STRUCT IMUangle_read_structure = { 0, 0, (uint8_t *)0 };

uint8_t IMUangle_Receive(uint8_t *buffer, uint16_t size)
{
  const char header[4] = { 165, 90, 17, 164 };/* Header */

  const char terminator[1] = { 170 };  /* Terminator */

  return ( UART3_ReadBinary(&IMUangle_read_structure, header, 4, terminator, 1,
           buffer, size));
}

/* Enable UART-DMA module */
void enable_IMUangle(void)
{
}

/* ########################################################################
 * Name: <S7>/Blue LED
 * Id: OrangeLED1BlueLED
 * ########################################################################
 */
uint16_t OrangeLED1BlueLED_portVal;
void enable_OrangeLED1BlueLED(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

  /* Configure PC in output Push Pull mode for OrangeLED1BlueLED Block*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;/* Waijung 14.xx */
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}

/* ########################################################################
 * Name: <S8>/UART Rx3
 * Id: ReceiverUARTRx3
 * ########################################################################
 */

/* Data read structure */
UARTRX_BUFFER_READ_STRUCT ReceiverUARTRx3_read_structure = { 0, 0, (uint8_t *)0
};

uint8_t ReceiverUARTRx3_Receive(uint8_t *buffer, uint16_t size)
{
  const char header[2] = { 0, 15 };    /* Header */

  const char terminator[1] = { 0 };

  return ( UART2_ReadBinary(&ReceiverUARTRx3_read_structure, header, 2,
           terminator, 0, buffer, size));
}

/* Enable UART-DMA module */
void enable_ReceiverUARTRx3(void)
{
}

void enable_executeBasicPWM7(void)
{
  /* Block: executeBasicPWM7 */
  GPIO_InitTypeDef GPIO_InitStructure;
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
  TIM_OCInitTypeDef TIM_OCInitStructure;

  /* TIM4 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

  /* GPIOB clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

  /* GPIOB configuration */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 |
    GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* Connect TIM4 pins to AF */
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_TIM4);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_TIM4);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_TIM4);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_TIM4);

  /* Time base configuration */
  TIM_TimeBaseStructure.TIM_Period = executeBasicPWM7_TIM4_ARR-1;/* 0.01 sec */
  TIM_TimeBaseStructure.TIM_Prescaler = 13;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseStructure.TIM_RepetitionCounter = 0x0000;
  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

  /* Init OC */
  TIM_OCStructInit(&TIM_OCInitStructure);
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

  /* PWM1 Mode configuration: Channel 1 */
  TIM_OC1Init(TIM4, &TIM_OCInitStructure);
  TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel 2 */
  TIM_OC2Init(TIM4, &TIM_OCInitStructure);
  TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel 3 */
  TIM_OC3Init(TIM4, &TIM_OCInitStructure);
  TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel 4 */
  TIM_OC4Init(TIM4, &TIM_OCInitStructure);
  TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);

  /* TIM4 configure auto reload */
  TIM_ARRPreloadConfig(TIM4, ENABLE);

  /* TIM4 enable counter */
  TIM_Cmd(TIM4, ENABLE);
}

void disable_executeBasicPWM7(void)
{
  TIM_Cmd(TIM4, DISABLE);
}

void terminate_executeBasicPWM7(void)
{
  TIM_Cmd(TIM4, DISABLE);
}

/* ########################################################################
 * Name: <S11>/UART Tx
 * Id: toshangweijiUARTTx
 * ########################################################################
 */

/* Enable UART-DMA module */
void enable_toshangweijiUARTTx(void)
{
}

/* ########################################################################
 * Name: <S11>/UART Tx1
 * Id: toshangweijiUARTTx1
 * ########################################################################
 */

/* Enable UART-DMA module */
void enable_toshangweijiUARTTx1(void)
{
}

/* ########################################################################
 * Name: <S1>/UART Rx3
 * Id: fromshangweijiUARTRx3
 * ########################################################################
 */

/* Data read structure */
UARTRX_BUFFER_READ_STRUCT fromshangweijiUARTRx3_read_structure = { 0, 0,
  (uint8_t *)0 };

/* Data */
float fromshangweijiUARTRx3_data0 = 0;
float fromshangweijiUARTRx3_data1 = 0;
float fromshangweijiUARTRx3_data2 = 0;
float fromshangweijiUARTRx3_data3 = 0;
float fromshangweijiUARTRx3_data4 = 0;

/* Non-Blocking */
uint8_t fromshangweijiUARTRx3_Receive(uint8_t *buffer, uint16_t size)
{
  uint8_T ready = 0;
  const char terminator[2] = { 13, 10 };/* Terminator */

  /* Rx Non-Blocking */
  if (UART1_ReadLine(&fromshangweijiUARTRx3_read_structure, terminator, 2,
                     buffer, size) > 0) {
    ready = (uint8_t)(sscanf((const char*)buffer,"pid_roll=%f,%f,%f,%f,%f\r\n" ,
      &fromshangweijiUARTRx3_data0 ,&fromshangweijiUARTRx3_data1 ,
      &fromshangweijiUARTRx3_data2 ,&fromshangweijiUARTRx3_data3 ,
      &fromshangweijiUARTRx3_data4 ) == 5);
  }

  return ready;
}

/* Enable UART-DMA module */
void enable_fromshangweijiUARTRx3(void)
{
}

/* ########################################################################
 * Name: <S1>/UART Rx4
 * Id: fromshangweijiUARTRx4
 * ########################################################################
 */

/* Data read structure */
UARTRX_BUFFER_READ_STRUCT fromshangweijiUARTRx4_read_structure = { 0, 0,
  (uint8_t *)0 };

/* Data */
float fromshangweijiUARTRx4_data0 = 0;
float fromshangweijiUARTRx4_data1 = 0;
float fromshangweijiUARTRx4_data2 = 0;
float fromshangweijiUARTRx4_data3 = 0;
float fromshangweijiUARTRx4_data4 = 0;

/* Non-Blocking */
uint8_t fromshangweijiUARTRx4_Receive(uint8_t *buffer, uint16_t size)
{
  uint8_T ready = 0;
  const char terminator[2] = { 13, 10 };/* Terminator */

  /* Rx Non-Blocking */
  if (UART1_ReadLine(&fromshangweijiUARTRx4_read_structure, terminator, 2,
                     buffer, size) > 0) {
    ready = (uint8_t)(sscanf((const char*)buffer,"pid_yaw=%f,%f,%f,%f,%f\r\n" ,
      &fromshangweijiUARTRx4_data0 ,&fromshangweijiUARTRx4_data1 ,
      &fromshangweijiUARTRx4_data2 ,&fromshangweijiUARTRx4_data3 ,
      &fromshangweijiUARTRx4_data4 ) == 5);
  }

  return ready;
}

/* Enable UART-DMA module */
void enable_fromshangweijiUARTRx4(void)
{
}

/* ########################################################################
 * Name: <S1>/UART Rx5
 * Id: fromshangweijiUARTRx5
 * ########################################################################
 */

/* Data read structure */
UARTRX_BUFFER_READ_STRUCT fromshangweijiUARTRx5_read_structure = { 0, 0,
  (uint8_t *)0 };

/* Data */
float fromshangweijiUARTRx5_data0 = 0;
float fromshangweijiUARTRx5_data1 = 0;
float fromshangweijiUARTRx5_data2 = 0;
float fromshangweijiUARTRx5_data3 = 0;
float fromshangweijiUARTRx5_data4 = 0;

/* Non-Blocking */
uint8_t fromshangweijiUARTRx5_Receive(uint8_t *buffer, uint16_t size)
{
  uint8_T ready = 0;
  const char terminator[2] = { 13, 10 };/* Terminator */

  /* Rx Non-Blocking */
  if (UART1_ReadLine(&fromshangweijiUARTRx5_read_structure, terminator, 2,
                     buffer, size) > 0) {
    ready = (uint8_t)(sscanf((const char*)buffer,"pid_alt=%f,%f,%f,%f,%f\r\n" ,
      &fromshangweijiUARTRx5_data0 ,&fromshangweijiUARTRx5_data1 ,
      &fromshangweijiUARTRx5_data2 ,&fromshangweijiUARTRx5_data3 ,
      &fromshangweijiUARTRx5_data4 ) == 5);
  }

  return ready;
}

/* Enable UART-DMA module */
void enable_fromshangweijiUARTRx5(void)
{
}

/* ########################################################################
 * Name: <S1>/UART Rx1
 * Id: fromshangweijiUARTRx1
 * ########################################################################
 */

/* Data read structure */
UARTRX_BUFFER_READ_STRUCT fromshangweijiUARTRx1_read_structure = { 0, 0,
  (uint8_t *)0 };

/* Data */
uint32_t fromshangweijiUARTRx1_data0 = 0;

/* Non-Blocking */
uint8_t fromshangweijiUARTRx1_Receive(uint8_t *buffer, uint16_t size)
{
  uint8_T ready = 0;
  const char terminator[2] = { 13, 10 };/* Terminator */

  /* Rx Non-Blocking */
  if (UART1_ReadLine(&fromshangweijiUARTRx1_read_structure, terminator, 2,
                     buffer, size) > 0) {
    ready = (uint8_t)(sscanf((const char*)buffer,"LED1=%u\r\n" ,
      &fromshangweijiUARTRx1_data0 ) == 1);
  }

  return ready;
}

/* Enable UART-DMA module */
void enable_fromshangweijiUARTRx1(void)
{
}

/* ########################################################################
 * Name: <S1>/UART Rx
 * Id: fromshangweijiUARTRx
 * ########################################################################
 */

/* Data read structure */
UARTRX_BUFFER_READ_STRUCT fromshangweijiUARTRx_read_structure = { 0, 0, (uint8_t
  *)0 };

/* Data */

/* Non-Blocking */
uint8_t fromshangweijiUARTRx_Receive(uint8_t *buffer, uint16_t size)
{
  uint8_T ready = 0;
  const char terminator[2] = { 13, 10 };/* Terminator */

  /* Rx Non-Blocking */
  if (UART1_ReadLine(&fromshangweijiUARTRx_read_structure, terminator, 2, buffer,
                     size) > 0) {
    ready = (uint8_t)(strcmp((const char*)buffer,"id\r\n") == 0);
  }

  return ready;
}

/* Enable UART-DMA module */
void enable_fromshangweijiUARTRx(void)
{
}

/* ########################################################################
 * Name: <S1>/UART Rx2
 * Id: fromshangweijiUARTRx2
 * ########################################################################
 */

/* Data read structure */
UARTRX_BUFFER_READ_STRUCT fromshangweijiUARTRx2_read_structure = { 0, 0,
  (uint8_t *)0 };

/* Data */

/* Non-Blocking */
uint8_t fromshangweijiUARTRx2_Receive(uint8_t *buffer, uint16_t size)
{
  uint8_T ready = 0;
  const char terminator[2] = { 13, 10 };/* Terminator */

  /* Rx Non-Blocking */
  if (UART1_ReadLine(&fromshangweijiUARTRx2_read_structure, terminator, 2,
                     buffer, size) > 0) {
    ready = (uint8_t)(strcmp((const char*)buffer,"M3C init\r\n") == 0);
  }

  return ready;
}

/* Enable UART-DMA module */
void enable_fromshangweijiUARTRx2(void)
{
}

/* ########################################################################
 * Name: <S10>/UART Setup
 * Id: initUARTSetup
 * ########################################################################
 */

/* Tx buffer */
uint8_t UART1_Tx_Buffer[UTX1_BUFFER_SIZE];
UART_TX_STATE initUARTSetup_Tx_State;

/* Rx buffer */
uint8_t UART1_Rx_Buffer[URX1_BUFFER_SIZE];
uint8_t UART1_Temp_Buffer[URX1_BUFFER_SIZE];

/* DMA Init struct */
DMA_InitTypeDef initUARTSetup_DMA_Init;

/* Init buffer read */
void UART1_RestoreBytes(UARTRX_BUFFER_READ_STRUCT *read_struct, uint16_t count)
{
  uint16_t roll_count = count;

  /* Remove overflow buffer */
  while (roll_count > URX1_BUFFER_SIZE)
    roll_count -= URX1_BUFFER_SIZE;

  /* Return bytes back into buffer */
  if (roll_count > read_struct->index) {
    read_struct->index = URX1_BUFFER_SIZE - roll_count + read_struct->index;
  } else {
    read_struct->index -= roll_count;
  }
}

/* Read buffer from DMA
 ** Return value: Number of bytes vaiable.
 */
void UART1_Read(UARTRX_BUFFER_READ_STRUCT *read_struct)
{
  __IO uint16_t dma_curr_ndtr;
  __IO uint16_t dma_curr_index;
  uint16_t data_index = 0;
  uint16_t data_count = 0;

  /* Get current NDTR */
  if ((dma_curr_ndtr = DMA2_Stream2->NDTR) == 0) {/* Not initialize or turn-around state*/
    read_struct->count = 0;
    return;
  }

  /* Get current data indexs */
  dma_curr_index = URX1_BUFFER_SIZE - dma_curr_ndtr;
  if (read_struct->index < dma_curr_index) {
    /* Data is available */
    data_index = read_struct->index;
    data_count = dma_curr_index - read_struct->index;
    read_struct->index += data_count;
    read_struct->index &= (URX1_BUFFER_SIZE-1);
  } else if (read_struct->index > dma_curr_index) {
    /* Data is available with overlap */
    data_index = read_struct->index;
    data_count = URX1_BUFFER_SIZE-read_struct->index;
    read_struct->index = 0;
  } else {                             /* No new data */
  }

  /* Return the reading */
  if (data_count > 0) {
    read_struct->buffer = &UART1_Rx_Buffer[data_index];
    read_struct->count = data_count;
  } else {
    read_struct->count = 0;
  }
}

void UART1_ReadEx(UARTRX_BUFFER_READ_STRUCT *read_struct, uint8_t *buffer,
                  uint16_t buffer_size, uint16_t*reading_count)
{
  uint16_t bytes_to_read, data_read_index;
  bytes_to_read = buffer_size;         /* Tracking count of data readings */
  data_read_index = 0;                 /* Increment buffer index */
  do {
    UART1_Read(read_struct);
    if (read_struct->count <= bytes_to_read) {
      memcpy(&buffer[data_read_index], read_struct->buffer, read_struct->count);
      data_read_index += read_struct->count;
      bytes_to_read -= read_struct->count;
    } else {
      /* Return some byte back to buffer */
      //read_struct->index -= (read_struct->count - bytes_to_read);
      UART1_RestoreBytes(read_struct, (read_struct->count - bytes_to_read));/* Fixed: Waijung 14.05a */

      /* Return reading data */
      memcpy(&buffer[data_read_index], read_struct->buffer, bytes_to_read);
      bytes_to_read = 0;
    }
  } while ((bytes_to_read > 0) && (read_struct->count > 0));

  /* Number of reading bytes */
  *reading_count = buffer_size - bytes_to_read;
}

/* Read Ascii packet
 * Return char count, exclude NULL
 * Terminator: "\n", "\r", "\r\n"
 */
uint16_t UART1_ReadLine(UARTRX_BUFFER_READ_STRUCT *read_struct, const char
  *terminator, uint16_t terminator_count, uint8_t *buffer, uint16_t buffer_size)
{
  uint16_t count, packet_len = 0, receive_count = 0;
  uint16_t i;
  uint8_t terminator_found = 0;

  /* Determine maximum number of bytes to read */
  count = buffer_size - 1;
  if (count >= URX1_BUFFER_SIZE)
    count = URX1_BUFFER_SIZE-1;

  /* Ignore terminator is invalid */
  if (terminator_count < 1)
    return 0;

  /* Read packet */
  do {
    UART1_Read(read_struct);           /* Check DMA buffer */
    receive_count += read_struct->count;/* Total number of data received */

    /* Search terminator */
    i = 0;
    while (!terminator_found && (i < read_struct->count)) {
      if (read_struct->buffer[i] == (uint8_t)terminator[terminator_count - 1])
        terminator_found = 1;
      i++;
    }

    packet_len += i;
    if (terminator_found) {
      terminator_found = 0;

      /* Roll-back buffer index */
      if ((packet_len > count) || (packet_len < terminator_count)) {/* Packet count is invalid, drop it */
        UART1_RestoreBytes(read_struct, (receive_count-packet_len));

        /* Reset */
        packet_len = 0;
        receive_count = 0;
      } else {
        UART1_RestoreBytes(read_struct, receive_count);

        /* Load data into buffer */
        UART1_ReadEx(read_struct, buffer, packet_len, &i);
        buffer[packet_len] = '\0';     /* Append NULL */

        /* Validate terminator */
        if (!strncmp((char *)&buffer[packet_len-terminator_count], terminator,
                     terminator_count)) {
          return packet_len;           /* packet reading success, return number of received bytes */
        } else {
          /* Invalid terminator */
          packet_len = 0;
          receive_count = 0;
        }
      }
    }
  } while (read_struct->count > 0);

  /* Could not find the packet terminator, reset reading struct to its original position */
  if (receive_count > 0) {
    UART1_RestoreBytes(read_struct, receive_count);
  }

  /* No byte receive */
  return 0;
}

/* Read Binary packet
 * 0: Not ready, 1: Data is ready
 */
uint8_t UART1_ReadBinary(UARTRX_BUFFER_READ_STRUCT *read_struct, const char
  *header, uint16_t header_count, const char *terminator, uint16_t
  terminator_count, uint8_t *buffer, uint16_t data_count)
{
  uint16_t receive_count = 0, drop_count = 0, binary_state = 0, binary_index = 0;
  uint16_t i;
  do {
    UART1_Read(read_struct);           /* Check DMA buffer */
    receive_count += read_struct->count;/* Total number of data received */

    /* Binary packet processing */
    for (i=0; i<read_struct->count; i++) {
      switch ( binary_state ) {
       case 0:                         /* Search for header */
        if (binary_index < header_count) {
          if (read_struct->buffer[i] == header[binary_index]) {
            binary_index ++;
          } else {
            binary_index = 0;
            drop_count = receive_count - (read_struct->count - i - 1);/* Drop packet */
          }
          break;
        } else {                       /* Change to DATA state */
          binary_index = 0;
          binary_state ++;
        }

       case 1:                         /* Wait for data */
        /* Wait for DATA */
        if (binary_index < data_count) {
          buffer[binary_index] = read_struct->buffer[i];
          binary_index ++;

          /* Check if ready (No terminator) */
          if ((binary_index >= data_count) && (terminator_count == 0)) {
            UART1_RestoreBytes(read_struct, (read_struct->count - i - 1));/* Restore some bytes */
            return 1;                  /* Return success status */
          }
          break;
        } else {                       /* Change to Terminator state */
          binary_index = 0;
          binary_state ++;
        }

       case 2:                         /* Scan for terminator */
        if (binary_index < terminator_count) {
          if (read_struct->buffer[i] == terminator[binary_index]) {
            binary_index ++;
          } else {
            binary_state = 0;
            binary_index = 0;
            drop_count = receive_count - (read_struct->count - i - 1);/* Drop packet */
          }
        }

        if (binary_index >= terminator_count) {/* Success */
          /* Restore some bytes */
          UART1_RestoreBytes(read_struct, (read_struct->count - i - 1));
          return 1;                    /* Return success status */
        }
        break;
      }
    }
  } while (read_struct->count > 0);

  /* Restore bytes */
  UART1_RestoreBytes(read_struct, (receive_count - drop_count));
  return 0;
}

/* Wait for DMA transfer to completion */
UART_TX_STATE UART1_FlushTxBuffer(void)
{
  if (initUARTSetup_Tx_State != txIdle) {
    /* Chehck last DMA transmit */
    while ((DMA_GetFlagStatus(DMA2_Stream7, DMA_FLAG_TCIF7) == RESET)
           || (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)) {
    }

    /* Clear DMA Streams flags */
    DMA_ClearFlag(DMA2_Stream7, DMA_FLAG_HTIF7 | DMA_FLAG_TCIF7);

    /* Disable the DMA Streams */
    DMA_Cmd(DMA2_Stream7, DISABLE);

    /* Disable the USART Tx DMA request */
    USART_DMACmd(USART1, USART_DMAReq_Tx, DISABLE);

    /* Update state */
    initUARTSetup_Tx_State = txIdle;
  }

  return initUARTSetup_Tx_State;
}

/* Write to DMA buffer */
void UART1_Write(uint8_t* data, uint16_t count)
{
  if (count > 0) {
    /* Wait for Tx state to idle */
    UART1_FlushTxBuffer();

    /* Setup */
    memcpy(UART1_Tx_Buffer, data, count);

    /* Update */
    UART1_TxUpdate(count);
  }
}

/* Update transmit buffer */
void UART1_TxUpdate(uint16_t count)
{
  if (count > 0) {
    /* Wait for Tx state to idle */
    UART1_FlushTxBuffer();
    initUARTSetup_DMA_Init.DMA_BufferSize = (uint16_t)count;
    DMA_Init(DMA2_Stream7, &initUARTSetup_DMA_Init);

    /* Enable */
    USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);
    USART_ClearFlag(USART1, USART_FLAG_TC);
    DMA_Cmd(DMA2_Stream7, ENABLE);

    /* Tx is busy */
    initUARTSetup_Tx_State = txBusy;
  }
}

/* Enable UART-DMA module */
void enable_initUARTSetup(void)
{
  USART_InitTypeDef USART_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable GPIO clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

  /* Enable UART clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

  /* Enable the DMA clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);

  /* Connect PXx to USARTx_Tx*/
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);

  /* Connect PXx to USARTx_Rx*/
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);

  /* Configure USART pin as alternate function  */
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;

  /* Configure USART Tx */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* Configure USART Rx */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* USART Configuration */
  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  /* Over sampling x8 */
  USART_OverSampling8Cmd(USART1, ENABLE);

  /* USART configuration */
  USART_Init(USART1, &USART_InitStructure);

  /* Enable USART */
  USART_Cmd(USART1, ENABLE);

  /* DMA init struct configuration */
  initUARTSetup_DMA_Init.DMA_PeripheralBaseAddr = (uint32_t)(&USART1->DR);
  initUARTSetup_DMA_Init.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  initUARTSetup_DMA_Init.DMA_MemoryInc = DMA_MemoryInc_Enable;
  initUARTSetup_DMA_Init.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  initUARTSetup_DMA_Init.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  initUARTSetup_DMA_Init.DMA_FIFOMode = DMA_FIFOMode_Disable;
  initUARTSetup_DMA_Init.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
  initUARTSetup_DMA_Init.DMA_MemoryBurst = DMA_MemoryBurst_Single;
  initUARTSetup_DMA_Init.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;

  /* Configure DMA controller to manage RX DMA request */
  initUARTSetup_DMA_Init.DMA_Channel = DMA_Channel_4;
  initUARTSetup_DMA_Init.DMA_Memory0BaseAddr = (uint32_t)UART1_Rx_Buffer;
  initUARTSetup_DMA_Init.DMA_DIR = DMA_DIR_PeripheralToMemory;
  initUARTSetup_DMA_Init.DMA_BufferSize = (uint16_t)URX1_BUFFER_SIZE;
  initUARTSetup_DMA_Init.DMA_Mode = DMA_Mode_Circular;
  initUARTSetup_DMA_Init.DMA_Priority = DMA_Priority_VeryHigh;
  DMA_Init(DMA2_Stream2, &initUARTSetup_DMA_Init);

  /* Enable the USART Rx DMA requests */
  USART_DMACmd(USART1, USART_DMAReq_Rx , ENABLE);

  /* Enable the DMA Stream */
  DMA_Cmd(DMA2_Stream2, ENABLE);

  /* Configure DMA controller to manage TX DMA request */
  initUARTSetup_DMA_Init.DMA_Channel = DMA_Channel_4;
  initUARTSetup_DMA_Init.DMA_Memory0BaseAddr = (uint32_t)UART1_Tx_Buffer;
  initUARTSetup_DMA_Init.DMA_DIR = DMA_DIR_MemoryToPeripheral;
  initUARTSetup_DMA_Init.DMA_BufferSize = (uint16_t)UTX1_BUFFER_SIZE;
  initUARTSetup_DMA_Init.DMA_Mode = DMA_Mode_Normal;
  initUARTSetup_DMA_Init.DMA_Priority = DMA_Priority_High;

  /* Init Tx state */
  initUARTSetup_Tx_State = txIdle;
}

/* ########################################################################
 * Name: <S10>/UART Setup1
 * Id: initUARTSetup1
 * ########################################################################
 */

/* Tx buffer */
uint8_t UART3_Tx_Buffer[UTX3_BUFFER_SIZE];
UART_TX_STATE initUARTSetup1_Tx_State;

/* Rx buffer */
uint8_t UART3_Rx_Buffer[URX3_BUFFER_SIZE];
uint8_t UART3_Temp_Buffer[URX3_BUFFER_SIZE];

/* DMA Init struct */
DMA_InitTypeDef initUARTSetup1_DMA_Init;

/* Init buffer read */
void UART3_RestoreBytes(UARTRX_BUFFER_READ_STRUCT *read_struct, uint16_t count)
{
  uint16_t roll_count = count;

  /* Remove overflow buffer */
  while (roll_count > URX3_BUFFER_SIZE)
    roll_count -= URX3_BUFFER_SIZE;

  /* Return bytes back into buffer */
  if (roll_count > read_struct->index) {
    read_struct->index = URX3_BUFFER_SIZE - roll_count + read_struct->index;
  } else {
    read_struct->index -= roll_count;
  }
}

/* Read buffer from DMA
 ** Return value: Number of bytes vaiable.
 */
void UART3_Read(UARTRX_BUFFER_READ_STRUCT *read_struct)
{
  __IO uint16_t dma_curr_ndtr;
  __IO uint16_t dma_curr_index;
  uint16_t data_index = 0;
  uint16_t data_count = 0;

  /* Get current NDTR */
  if ((dma_curr_ndtr = DMA1_Stream1->NDTR) == 0) {/* Not initialize or turn-around state*/
    read_struct->count = 0;
    return;
  }

  /* Get current data indexs */
  dma_curr_index = URX3_BUFFER_SIZE - dma_curr_ndtr;
  if (read_struct->index < dma_curr_index) {
    /* Data is available */
    data_index = read_struct->index;
    data_count = dma_curr_index - read_struct->index;
    read_struct->index += data_count;
    read_struct->index &= (URX3_BUFFER_SIZE-1);
  } else if (read_struct->index > dma_curr_index) {
    /* Data is available with overlap */
    data_index = read_struct->index;
    data_count = URX3_BUFFER_SIZE-read_struct->index;
    read_struct->index = 0;
  } else {                             /* No new data */
  }

  /* Return the reading */
  if (data_count > 0) {
    read_struct->buffer = &UART3_Rx_Buffer[data_index];
    read_struct->count = data_count;
  } else {
    read_struct->count = 0;
  }
}

void UART3_ReadEx(UARTRX_BUFFER_READ_STRUCT *read_struct, uint8_t *buffer,
                  uint16_t buffer_size, uint16_t*reading_count)
{
  uint16_t bytes_to_read, data_read_index;
  bytes_to_read = buffer_size;         /* Tracking count of data readings */
  data_read_index = 0;                 /* Increment buffer index */
  do {
    UART3_Read(read_struct);
    if (read_struct->count <= bytes_to_read) {
      memcpy(&buffer[data_read_index], read_struct->buffer, read_struct->count);
      data_read_index += read_struct->count;
      bytes_to_read -= read_struct->count;
    } else {
      /* Return some byte back to buffer */
      //read_struct->index -= (read_struct->count - bytes_to_read);
      UART3_RestoreBytes(read_struct, (read_struct->count - bytes_to_read));/* Fixed: Waijung 14.05a */

      /* Return reading data */
      memcpy(&buffer[data_read_index], read_struct->buffer, bytes_to_read);
      bytes_to_read = 0;
    }
  } while ((bytes_to_read > 0) && (read_struct->count > 0));

  /* Number of reading bytes */
  *reading_count = buffer_size - bytes_to_read;
}

/* Read Ascii packet
 * Return char count, exclude NULL
 * Terminator: "\n", "\r", "\r\n"
 */
uint16_t UART3_ReadLine(UARTRX_BUFFER_READ_STRUCT *read_struct, const char
  *terminator, uint16_t terminator_count, uint8_t *buffer, uint16_t buffer_size)
{
  uint16_t count, packet_len = 0, receive_count = 0;
  uint16_t i;
  uint8_t terminator_found = 0;

  /* Determine maximum number of bytes to read */
  count = buffer_size - 1;
  if (count >= URX3_BUFFER_SIZE)
    count = URX3_BUFFER_SIZE-1;

  /* Ignore terminator is invalid */
  if (terminator_count < 1)
    return 0;

  /* Read packet */
  do {
    UART3_Read(read_struct);           /* Check DMA buffer */
    receive_count += read_struct->count;/* Total number of data received */

    /* Search terminator */
    i = 0;
    while (!terminator_found && (i < read_struct->count)) {
      if (read_struct->buffer[i] == (uint8_t)terminator[terminator_count - 1])
        terminator_found = 1;
      i++;
    }

    packet_len += i;
    if (terminator_found) {
      terminator_found = 0;

      /* Roll-back buffer index */
      if ((packet_len > count) || (packet_len < terminator_count)) {/* Packet count is invalid, drop it */
        UART3_RestoreBytes(read_struct, (receive_count-packet_len));

        /* Reset */
        packet_len = 0;
        receive_count = 0;
      } else {
        UART3_RestoreBytes(read_struct, receive_count);

        /* Load data into buffer */
        UART3_ReadEx(read_struct, buffer, packet_len, &i);
        buffer[packet_len] = '\0';     /* Append NULL */

        /* Validate terminator */
        if (!strncmp((char *)&buffer[packet_len-terminator_count], terminator,
                     terminator_count)) {
          return packet_len;           /* packet reading success, return number of received bytes */
        } else {
          /* Invalid terminator */
          packet_len = 0;
          receive_count = 0;
        }
      }
    }
  } while (read_struct->count > 0);

  /* Could not find the packet terminator, reset reading struct to its original position */
  if (receive_count > 0) {
    UART3_RestoreBytes(read_struct, receive_count);
  }

  /* No byte receive */
  return 0;
}

/* Read Binary packet
 * 0: Not ready, 1: Data is ready
 */
uint8_t UART3_ReadBinary(UARTRX_BUFFER_READ_STRUCT *read_struct, const char
  *header, uint16_t header_count, const char *terminator, uint16_t
  terminator_count, uint8_t *buffer, uint16_t data_count)
{
  uint16_t receive_count = 0, drop_count = 0, binary_state = 0, binary_index = 0;
  uint16_t i;
  do {
    UART3_Read(read_struct);           /* Check DMA buffer */
    receive_count += read_struct->count;/* Total number of data received */

    /* Binary packet processing */
    for (i=0; i<read_struct->count; i++) {
      switch ( binary_state ) {
       case 0:                         /* Search for header */
        if (binary_index < header_count) {
          if (read_struct->buffer[i] == header[binary_index]) {
            binary_index ++;
          } else {
            binary_index = 0;
            drop_count = receive_count - (read_struct->count - i - 1);/* Drop packet */
          }
          break;
        } else {                       /* Change to DATA state */
          binary_index = 0;
          binary_state ++;
        }

       case 1:                         /* Wait for data */
        /* Wait for DATA */
        if (binary_index < data_count) {
          buffer[binary_index] = read_struct->buffer[i];
          binary_index ++;

          /* Check if ready (No terminator) */
          if ((binary_index >= data_count) && (terminator_count == 0)) {
            UART3_RestoreBytes(read_struct, (read_struct->count - i - 1));/* Restore some bytes */
            return 1;                  /* Return success status */
          }
          break;
        } else {                       /* Change to Terminator state */
          binary_index = 0;
          binary_state ++;
        }

       case 2:                         /* Scan for terminator */
        if (binary_index < terminator_count) {
          if (read_struct->buffer[i] == terminator[binary_index]) {
            binary_index ++;
          } else {
            binary_state = 0;
            binary_index = 0;
            drop_count = receive_count - (read_struct->count - i - 1);/* Drop packet */
          }
        }

        if (binary_index >= terminator_count) {/* Success */
          /* Restore some bytes */
          UART3_RestoreBytes(read_struct, (read_struct->count - i - 1));
          return 1;                    /* Return success status */
        }
        break;
      }
    }
  } while (read_struct->count > 0);

  /* Restore bytes */
  UART3_RestoreBytes(read_struct, (receive_count - drop_count));
  return 0;
}

/* Wait for DMA transfer to completion */
UART_TX_STATE UART3_FlushTxBuffer(void)
{
  if (initUARTSetup1_Tx_State != txIdle) {
    /* Chehck last DMA transmit */
    while ((DMA_GetFlagStatus(DMA1_Stream3, DMA_FLAG_TCIF3) == RESET)
           || (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET)) {
    }

    /* Clear DMA Streams flags */
    DMA_ClearFlag(DMA1_Stream3, DMA_FLAG_HTIF3 | DMA_FLAG_TCIF3);

    /* Disable the DMA Streams */
    DMA_Cmd(DMA1_Stream3, DISABLE);

    /* Disable the USART Tx DMA request */
    USART_DMACmd(USART3, USART_DMAReq_Tx, DISABLE);

    /* Update state */
    initUARTSetup1_Tx_State = txIdle;
  }

  return initUARTSetup1_Tx_State;
}

/* Write to DMA buffer */
void UART3_Write(uint8_t* data, uint16_t count)
{
  if (count > 0) {
    /* Wait for Tx state to idle */
    UART3_FlushTxBuffer();

    /* Setup */
    memcpy(UART3_Tx_Buffer, data, count);

    /* Update */
    UART3_TxUpdate(count);
  }
}

/* Update transmit buffer */
void UART3_TxUpdate(uint16_t count)
{
  if (count > 0) {
    /* Wait for Tx state to idle */
    UART3_FlushTxBuffer();
    initUARTSetup1_DMA_Init.DMA_BufferSize = (uint16_t)count;
    DMA_Init(DMA1_Stream3, &initUARTSetup1_DMA_Init);

    /* Enable */
    USART_DMACmd(USART3, USART_DMAReq_Tx, ENABLE);
    USART_ClearFlag(USART3, USART_FLAG_TC);
    DMA_Cmd(DMA1_Stream3, ENABLE);

    /* Tx is busy */
    initUARTSetup1_Tx_State = txBusy;
  }
}

/* Enable UART-DMA module */
void enable_initUARTSetup1(void)
{
  USART_InitTypeDef USART_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable GPIO clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

  /* Enable UART clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

  /* Enable the DMA clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);

  /* Connect PXx to USARTx_Tx*/
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_USART3);

  /* Connect PXx to USARTx_Rx*/
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_USART3);

  /* Configure USART pin as alternate function  */
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;

  /* Configure USART Tx */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* Configure USART Rx */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* USART Configuration */
  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  /* Over sampling x8 */
  USART_OverSampling8Cmd(USART3, ENABLE);

  /* USART configuration */
  USART_Init(USART3, &USART_InitStructure);

  /* Enable USART */
  USART_Cmd(USART3, ENABLE);

  /* DMA init struct configuration */
  initUARTSetup1_DMA_Init.DMA_PeripheralBaseAddr = (uint32_t)(&USART3->DR);
  initUARTSetup1_DMA_Init.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  initUARTSetup1_DMA_Init.DMA_MemoryInc = DMA_MemoryInc_Enable;
  initUARTSetup1_DMA_Init.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  initUARTSetup1_DMA_Init.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  initUARTSetup1_DMA_Init.DMA_FIFOMode = DMA_FIFOMode_Disable;
  initUARTSetup1_DMA_Init.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
  initUARTSetup1_DMA_Init.DMA_MemoryBurst = DMA_MemoryBurst_Single;
  initUARTSetup1_DMA_Init.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;

  /* Configure DMA controller to manage RX DMA request */
  initUARTSetup1_DMA_Init.DMA_Channel = DMA_Channel_4;
  initUARTSetup1_DMA_Init.DMA_Memory0BaseAddr = (uint32_t)UART3_Rx_Buffer;
  initUARTSetup1_DMA_Init.DMA_DIR = DMA_DIR_PeripheralToMemory;
  initUARTSetup1_DMA_Init.DMA_BufferSize = (uint16_t)URX3_BUFFER_SIZE;
  initUARTSetup1_DMA_Init.DMA_Mode = DMA_Mode_Circular;
  initUARTSetup1_DMA_Init.DMA_Priority = DMA_Priority_VeryHigh;
  DMA_Init(DMA1_Stream1, &initUARTSetup1_DMA_Init);

  /* Enable the USART Rx DMA requests */
  USART_DMACmd(USART3, USART_DMAReq_Rx , ENABLE);

  /* Enable the DMA Stream */
  DMA_Cmd(DMA1_Stream1, ENABLE);

  /* Configure DMA controller to manage TX DMA request */
  initUARTSetup1_DMA_Init.DMA_Channel = DMA_Channel_4;
  initUARTSetup1_DMA_Init.DMA_Memory0BaseAddr = (uint32_t)UART3_Tx_Buffer;
  initUARTSetup1_DMA_Init.DMA_DIR = DMA_DIR_MemoryToPeripheral;
  initUARTSetup1_DMA_Init.DMA_BufferSize = (uint16_t)UTX3_BUFFER_SIZE;
  initUARTSetup1_DMA_Init.DMA_Mode = DMA_Mode_Normal;
  initUARTSetup1_DMA_Init.DMA_Priority = DMA_Priority_High;

  /* Init Tx state */
  initUARTSetup1_Tx_State = txIdle;
}

/* ########################################################################
 * Name: <S10>/UART Setup2
 * Id: initUARTSetup2
 * ########################################################################
 */

/* Rx buffer */
uint8_t UART2_Rx_Buffer[URX2_BUFFER_SIZE];
uint8_t UART2_Temp_Buffer[URX2_BUFFER_SIZE];

/* DMA Init struct */
DMA_InitTypeDef initUARTSetup2_DMA_Init;

/* Init buffer read */
void UART2_RestoreBytes(UARTRX_BUFFER_READ_STRUCT *read_struct, uint16_t count)
{
  uint16_t roll_count = count;

  /* Remove overflow buffer */
  while (roll_count > URX2_BUFFER_SIZE)
    roll_count -= URX2_BUFFER_SIZE;

  /* Return bytes back into buffer */
  if (roll_count > read_struct->index) {
    read_struct->index = URX2_BUFFER_SIZE - roll_count + read_struct->index;
  } else {
    read_struct->index -= roll_count;
  }
}

/* Read buffer from DMA
 ** Return value: Number of bytes vaiable.
 */
void UART2_Read(UARTRX_BUFFER_READ_STRUCT *read_struct)
{
  __IO uint16_t dma_curr_ndtr;
  __IO uint16_t dma_curr_index;
  uint16_t data_index = 0;
  uint16_t data_count = 0;

  /* Get current NDTR */
  if ((dma_curr_ndtr = DMA1_Stream5->NDTR) == 0) {/* Not initialize or turn-around state*/
    read_struct->count = 0;
    return;
  }

  /* Get current data indexs */
  dma_curr_index = URX2_BUFFER_SIZE - dma_curr_ndtr;
  if (read_struct->index < dma_curr_index) {
    /* Data is available */
    data_index = read_struct->index;
    data_count = dma_curr_index - read_struct->index;
    read_struct->index += data_count;
    read_struct->index &= (URX2_BUFFER_SIZE-1);
  } else if (read_struct->index > dma_curr_index) {
    /* Data is available with overlap */
    data_index = read_struct->index;
    data_count = URX2_BUFFER_SIZE-read_struct->index;
    read_struct->index = 0;
  } else {                             /* No new data */
  }

  /* Return the reading */
  if (data_count > 0) {
    read_struct->buffer = &UART2_Rx_Buffer[data_index];
    read_struct->count = data_count;
  } else {
    read_struct->count = 0;
  }
}

void UART2_ReadEx(UARTRX_BUFFER_READ_STRUCT *read_struct, uint8_t *buffer,
                  uint16_t buffer_size, uint16_t*reading_count)
{
  uint16_t bytes_to_read, data_read_index;
  bytes_to_read = buffer_size;         /* Tracking count of data readings */
  data_read_index = 0;                 /* Increment buffer index */
  do {
    UART2_Read(read_struct);
    if (read_struct->count <= bytes_to_read) {
      memcpy(&buffer[data_read_index], read_struct->buffer, read_struct->count);
      data_read_index += read_struct->count;
      bytes_to_read -= read_struct->count;
    } else {
      /* Return some byte back to buffer */
      //read_struct->index -= (read_struct->count - bytes_to_read);
      UART2_RestoreBytes(read_struct, (read_struct->count - bytes_to_read));/* Fixed: Waijung 14.05a */

      /* Return reading data */
      memcpy(&buffer[data_read_index], read_struct->buffer, bytes_to_read);
      bytes_to_read = 0;
    }
  } while ((bytes_to_read > 0) && (read_struct->count > 0));

  /* Number of reading bytes */
  *reading_count = buffer_size - bytes_to_read;
}

/* Read Ascii packet
 * Return char count, exclude NULL
 * Terminator: "\n", "\r", "\r\n"
 */
uint16_t UART2_ReadLine(UARTRX_BUFFER_READ_STRUCT *read_struct, const char
  *terminator, uint16_t terminator_count, uint8_t *buffer, uint16_t buffer_size)
{
  uint16_t count, packet_len = 0, receive_count = 0;
  uint16_t i;
  uint8_t terminator_found = 0;

  /* Determine maximum number of bytes to read */
  count = buffer_size - 1;
  if (count >= URX2_BUFFER_SIZE)
    count = URX2_BUFFER_SIZE-1;

  /* Ignore terminator is invalid */
  if (terminator_count < 1)
    return 0;

  /* Read packet */
  do {
    UART2_Read(read_struct);           /* Check DMA buffer */
    receive_count += read_struct->count;/* Total number of data received */

    /* Search terminator */
    i = 0;
    while (!terminator_found && (i < read_struct->count)) {
      if (read_struct->buffer[i] == (uint8_t)terminator[terminator_count - 1])
        terminator_found = 1;
      i++;
    }

    packet_len += i;
    if (terminator_found) {
      terminator_found = 0;

      /* Roll-back buffer index */
      if ((packet_len > count) || (packet_len < terminator_count)) {/* Packet count is invalid, drop it */
        UART2_RestoreBytes(read_struct, (receive_count-packet_len));

        /* Reset */
        packet_len = 0;
        receive_count = 0;
      } else {
        UART2_RestoreBytes(read_struct, receive_count);

        /* Load data into buffer */
        UART2_ReadEx(read_struct, buffer, packet_len, &i);
        buffer[packet_len] = '\0';     /* Append NULL */

        /* Validate terminator */
        if (!strncmp((char *)&buffer[packet_len-terminator_count], terminator,
                     terminator_count)) {
          return packet_len;           /* packet reading success, return number of received bytes */
        } else {
          /* Invalid terminator */
          packet_len = 0;
          receive_count = 0;
        }
      }
    }
  } while (read_struct->count > 0);

  /* Could not find the packet terminator, reset reading struct to its original position */
  if (receive_count > 0) {
    UART2_RestoreBytes(read_struct, receive_count);
  }

  /* No byte receive */
  return 0;
}

/* Read Binary packet
 * 0: Not ready, 1: Data is ready
 */
uint8_t UART2_ReadBinary(UARTRX_BUFFER_READ_STRUCT *read_struct, const char
  *header, uint16_t header_count, const char *terminator, uint16_t
  terminator_count, uint8_t *buffer, uint16_t data_count)
{
  uint16_t receive_count = 0, drop_count = 0, binary_state = 0, binary_index = 0;
  uint16_t i;
  do {
    UART2_Read(read_struct);           /* Check DMA buffer */
    receive_count += read_struct->count;/* Total number of data received */

    /* Binary packet processing */
    for (i=0; i<read_struct->count; i++) {
      switch ( binary_state ) {
       case 0:                         /* Search for header */
        if (binary_index < header_count) {
          if (read_struct->buffer[i] == header[binary_index]) {
            binary_index ++;
          } else {
            binary_index = 0;
            drop_count = receive_count - (read_struct->count - i - 1);/* Drop packet */
          }
          break;
        } else {                       /* Change to DATA state */
          binary_index = 0;
          binary_state ++;
        }

       case 1:                         /* Wait for data */
        /* Wait for DATA */
        if (binary_index < data_count) {
          buffer[binary_index] = read_struct->buffer[i];
          binary_index ++;

          /* Check if ready (No terminator) */
          if ((binary_index >= data_count) && (terminator_count == 0)) {
            UART2_RestoreBytes(read_struct, (read_struct->count - i - 1));/* Restore some bytes */
            return 1;                  /* Return success status */
          }
          break;
        } else {                       /* Change to Terminator state */
          binary_index = 0;
          binary_state ++;
        }

       case 2:                         /* Scan for terminator */
        if (binary_index < terminator_count) {
          if (read_struct->buffer[i] == terminator[binary_index]) {
            binary_index ++;
          } else {
            binary_state = 0;
            binary_index = 0;
            drop_count = receive_count - (read_struct->count - i - 1);/* Drop packet */
          }
        }

        if (binary_index >= terminator_count) {/* Success */
          /* Restore some bytes */
          UART2_RestoreBytes(read_struct, (read_struct->count - i - 1));
          return 1;                    /* Return success status */
        }
        break;
      }
    }
  } while (read_struct->count > 0);

  /* Restore bytes */
  UART2_RestoreBytes(read_struct, (receive_count - drop_count));
  return 0;
}

/* Enable UART-DMA module */
void enable_initUARTSetup2(void)
{
  USART_InitTypeDef USART_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable GPIO clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

  /* Enable UART clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

  /* Enable the DMA clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);

  /* Connect PXx to USARTx_Rx*/
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);

  /* Configure USART pin as alternate function  */
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;

  /* Configure USART Rx */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* USART Configuration */
  USART_InitStructure.USART_BaudRate = 100000;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_2;
  USART_InitStructure.USART_Parity = USART_Parity_Even;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx;

  /* Over sampling x8 */
  USART_OverSampling8Cmd(USART2, ENABLE);

  /* USART configuration */
  USART_Init(USART2, &USART_InitStructure);

  /* Enable USART */
  USART_Cmd(USART2, ENABLE);

  /* DMA init struct configuration */
  initUARTSetup2_DMA_Init.DMA_PeripheralBaseAddr = (uint32_t)(&USART2->DR);
  initUARTSetup2_DMA_Init.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  initUARTSetup2_DMA_Init.DMA_MemoryInc = DMA_MemoryInc_Enable;
  initUARTSetup2_DMA_Init.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  initUARTSetup2_DMA_Init.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  initUARTSetup2_DMA_Init.DMA_FIFOMode = DMA_FIFOMode_Disable;
  initUARTSetup2_DMA_Init.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
  initUARTSetup2_DMA_Init.DMA_MemoryBurst = DMA_MemoryBurst_Single;
  initUARTSetup2_DMA_Init.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;

  /* Configure DMA controller to manage RX DMA request */
  initUARTSetup2_DMA_Init.DMA_Channel = DMA_Channel_4;
  initUARTSetup2_DMA_Init.DMA_Memory0BaseAddr = (uint32_t)UART2_Rx_Buffer;
  initUARTSetup2_DMA_Init.DMA_DIR = DMA_DIR_PeripheralToMemory;
  initUARTSetup2_DMA_Init.DMA_BufferSize = (uint16_t)URX2_BUFFER_SIZE;
  initUARTSetup2_DMA_Init.DMA_Mode = DMA_Mode_Circular;
  initUARTSetup2_DMA_Init.DMA_Priority = DMA_Priority_VeryHigh;
  DMA_Init(DMA1_Stream5, &initUARTSetup2_DMA_Init);

  /* Enable the USART Rx DMA requests */
  USART_DMACmd(USART2, USART_DMAReq_Rx , ENABLE);

  /* Enable the DMA Stream */
  DMA_Cmd(DMA1_Stream5, ENABLE);
}

/* ########################################################################
 * Timer
 * ########################################################################
 */

/* Low precision non-Blocking delay timer.
 ** Relolution of timer is one TICK step interrupt.
 */
void SysTimer_Start(SYS_TIMER_STRUCT* timer, uint32_t ms)
{
  /* Calculate amount of tick count */
  timer->length = (uint32_t)((float)ms/(1000*SYS_TICKSTEP));

  /* Capture current tick */
  timer->start = (uint32_t)systick_count;
}

int SysTimer_IsTimeout(SYS_TIMER_STRUCT* timer)
{
  uint32_t Capture;

  /* Capture current tick */
  Capture = (uint32_t)systick_count;

  /* Check */
  if (Capture >= timer->start) {
    if ((Capture - timer->start) >= timer->length)
      return 1;
  } else {
    if (((0xFFFFFFFF - timer->start)+Capture) >= timer->length)
      return 1;
  }

  return 0;
}

/* Improved precision non-Blocking delay timer.
 ** Relolution of timer is 1uS.
 */
void SysTimer_uS_Start(SYS_TIMER_uS_STRUCT *timer, uint32_t us)
{
  /* Tick */
  timer->tick = SYS_CURRENT_TICK;

  /* Tick overflow count */
  timer->tid = (uint32_t)systick_count;

  /* Target */
  timer->target_us = us*((uint32_t)HCLK/1000000);
}

int SysTimer_uS_IsTimeout(SYS_TIMER_uS_STRUCT* timer)
{
  uint32_t curr_tick;
  uint32_t curr_tid;

  /* Already timeout ? */
  if (timer->target_us == 0) {
    return 1;
  }

  /* Capture current tick */
  curr_tick = SYS_CURRENT_TICK;
  curr_tid = systick_count;

  /* Processing TID*/
  while (timer->tid != curr_tid) {
    if (timer->target_us > timer->tick) {
      timer->target_us -= timer->tick;
      timer->tid ++;
      timer->tick = SYSTICKRELOADVALUE-1;
    } else {
      timer->target_us = 0;
      return 1;                        /* Timeout */
    }
  }

  /* Processing Tick */
  if ((timer->tick > curr_tick) && ((timer->tick - curr_tick) > timer->target_us))
  {
    timer->target_us = 0;
    return 1;                          /* Timeout */
  }

  /* Need wait */
  return 0;
}

/* Blocking delay, uS */
void SysTimer_delay_us(uint32_t us)
{
  SYS_TIMER_uS_STRUCT timer;
  SysTimer_uS_Start(&timer, us);
  while (SysTimer_uS_IsTimeout(&timer) == 0) ;
}

/* Blocking delay, mS */
void SysTimer_delay_ms(uint32_t ms)
{
  SYS_TIMER_STRUCT timer;
  SysTimer_Start(&timer, ms);
  while (SysTimer_IsTimeout(&timer) == 0) ;
}

/* [EOF] */

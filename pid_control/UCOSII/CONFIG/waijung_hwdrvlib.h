/*
 * File: waijung_hwdrvlib.h
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model download.
 *
 * Model version                        : 1.103
 * Real-Time Workshop file version      : 8.6 (R2014a) 27-Dec-2013
 * Real-Time Workshop file generated on : Sun Jun 26 11:20:16 2016
 * TLC version                          : 8.6 (Jan 30 2014)
 * C/C++ source code generated on       : Sun Jun 26 11:20:17 2016
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_waijung_hwdrvlib_h_
#define RTW_HEADER_waijung_hwdrvlib_h_
#include "rtwtypes.h"
#include "stm32f4xx.h"

/* ########################################################################
 * Name: <S12>/Digital Output
 * Id: fromshangweijiEnabledSubsystem1DigitalOutput
 * ########################################################################
 */
#define fromshangweijiEnabledSubsystem1DigitalOutput_C2 Peripheral_BB(GPIOC->ODR, 2) /* Output pin */

/* Unique ID Based Address */
#define UID32BaseAddress_fromshangweijiEnabledSubsystem2ReadUniqueID 0x1FFF7A10

/* ########################################################################
 * Name: <S7>/Blue LED
 * Id: OrangeLED1BlueLED
 * ########################################################################
 */
#define OrangeLED1BlueLED_C2           Peripheral_BB(GPIOC->ODR, 2) /* Output pin */

/*
 * Define PWM Generation Scale Factor
 * From TIMx_CCRx = TIMx_ARR * (Duty Cycle / 100)
 * TIMx_CCRx = (TIMx_ARR/100) * Duty Cycle
 */
#define executeBasicPWM7_TIM4_ARR      60000
#define executeBasicPWM7_SF            (executeBasicPWM7_TIM4_ARR / 100)

/*
 * Bit banding
 *
 * The Cortex memory map includes two bit-band regions.
 * These regions map each word in an alias region of memory to a bit in
 * a bit-band region of memory. Writing to a word in the alias region
 * has the same effect as a read-modify-write operation on the targeted bit
 * in the bit-band region.
 *
 * In the STM32F4xxx both peripheral registers and SRAM are mapped in
 * a bit-band region. This allows single bit-band write and read operations
 * to be performed.
 *
 * A mapping formula shows how to reference each word in the alias region
 * to a corresponding bit in the bit-band region. The mapping formula is:
 * bit_word_addr = bit_band_base + (byte_offset x 32) + (bit_number × 4)
 *
 * BB_base      is the base address of the bit-band region for a register. (PERIPH_BB_BASE at 0x42000000 or SRAM_BB_BASE at 0x22000000)
 * Reg_base     is the base address of a register in the memory region. (PERIPH_BASE at 0x40000000 or SRAM_BASE at 0x20000000)
 * Register     is a register in the memory region that contains the targeted bit.
 * Bit_number   is the targeted bit number (0 - 31).
 *
 * PERIPH_BB_BASE, SRAM_BB_BASE, PERIPH_BASE, and SRAM_BASE are defined in stm32f10x.h
 *
 * Example for determining bit banding bit.
 * Determine DMA Transfer Complete Flag using bit banding.
 * TCIFx is the flag for DMA Channel x
 * This bit is set by hardware. It is cleared by software writing 1 to
 * the corresponding bit in the DMA_IFCR register.
 * TCIFx = 0: No transfer complete (TC) event on channel x
 * TCIFx = 1: A transfer complete (TC) event occurred on channel x
 *
 * DMA Channel:       1 2 3  4  5  6  7
 * Flag bit position: 1 5 9 13 17 21 25 (in DMA_ISR register)
 * (For DMA2 Channel 6 and 7 is irrelevant since it only has 5 channels.)
 *
 * CTCIFx: Channel x transfer complete clear (x = 1 ..7)
 * This bit is set and cleared by software.
 * CTCIFx = 0: No effect
 * CTCIFx = 1: Clear the corresponding TCIF flag in the DMA_ISR register
 *
 */
#define BitBanding(Register, Bit_number, Reg_base, BB_base) ((volatile uint32_t*) ((BB_base) + (((uint32_t) &(Register)) - ((Reg_base))<<5) + ((Bit_number)<<2)))
#define Peripheral_BB(Register, Bit_number) BitBanding(Register, Bit_number, PERIPH_BASE, PERIPH_BB_BASE)
#define SRAM_BB(Register, Bit_number)  BitBanding(Register, Bit_number, SRAM_BASE, SRAM_BB_BASE)

/*
 * Sample usage:
 * USART1->SR can be found from "stm32f4xx.h" and USART_FLAG_TC (6) can be found from "stm32f4xx_usart.h"
 * #define USART1_TC Peripheral_BB(USART1->SR, 6) USART_SR.TC bit
 *
 * Another example:
 * #define GPIOC_8 Peripheral_BB(GPIOC->ODR, 8)
 * *GPIOC_8 = 1;
 */

/*
 * Systick is configured such that the SysTick interrupt every 0.001 sec
 * which is the base sample time of the system.
 */
#define SYSTICKRELOADVALUE             168000

/*
 * HCLK (Hz)
 */
#define HCLK                           168000000

/*
 * Each Systick counter is TIMEPERSYSTICK sec.
 */
#define TIMEPERSYSTICK                 0.001 / 168000

/* Unique ID data */
extern uint32_t UID32_fromshangweijiEnabledSubsystem2ReadUniqueID[3];
extern volatile unsigned int systick_count;

/* ########################################################################
 * UART Utilities for packet processing
 * ########################################################################
 */
/* UART packet process struct */
typedef enum {
  txIdle = 0,
  txBusy
} UART_TX_STATE;

/* Data read structure */
typedef struct {
  uint16_t index;                      /* Index of data in buffer */
  uint16_t count;                      /* Return data count */
  uint8_t *buffer;                     /* Return buffer pointer of valid data */
} UARTRX_BUFFER_READ_STRUCT;

/* ########################################################################
 * Name: <S18>/UART Tx
 * Id: fromshangweijiEnabledSubsystem1IfActionSubsystemUARTTx
 * ########################################################################
 */
void enable_fromshangweijiEnabledSubsystem1IfActionSubsystemUARTTx(void);

/* ########################################################################
 * Name: <S19>/UART Tx
 * Id: fromshangweijiEnabledSubsystem1IfActionSubsystem1UARTTx
 * ########################################################################
 */
void enable_fromshangweijiEnabledSubsystem1IfActionSubsystem1UARTTx(void);

/* fromshangweijiEnabledSubsystem1DigitalOutput */
void enable_fromshangweijiEnabledSubsystem1DigitalOutput(void);

/* Eanble Unique ID Read */
void enable_fromshangweijiEnabledSubsystem2ReadUniqueID(void);

/* ########################################################################
 * Name: <S13>/UART Tx
 * Id: fromshangweijiEnabledSubsystem2UARTTx
 * ########################################################################
 */
void enable_fromshangweijiEnabledSubsystem2UARTTx(void);

/* ########################################################################
 * Name: <S14>/UART Tx
 * Id: fromshangweijiEnabledSubsystem3UARTTx
 * ########################################################################
 */
void enable_fromshangweijiEnabledSubsystem3UARTTx(void);

/* ########################################################################
 * Name: <S15>/UART Tx
 * Id: fromshangweijiEnabledSubsystem4UARTTx
 * ########################################################################
 */
void enable_fromshangweijiEnabledSubsystem4UARTTx(void);

/* ########################################################################
 * Name: <S16>/UART Tx
 * Id: fromshangweijiEnabledSubsystem5UARTTx
 * ########################################################################
 */
void enable_fromshangweijiEnabledSubsystem5UARTTx(void);

/* ########################################################################
 * Name: <S17>/UART Tx
 * Id: fromshangweijiEnabledSubsystem6UARTTx
 * ########################################################################
 */
void enable_fromshangweijiEnabledSubsystem6UARTTx(void);

/* ########################################################################
 * Name: <S4>/angle
 * Id: IMUangle
 * ########################################################################
 */
extern UARTRX_BUFFER_READ_STRUCT IMUangle_read_structure;
uint8_t IMUangle_Receive(uint8_t *buffer, uint16_t size);
void enable_IMUangle(void);

/* OrangeLED1BlueLED */
void enable_OrangeLED1BlueLED(void);

/* ########################################################################
 * Name: <S8>/UART Rx3
 * Id: ReceiverUARTRx3
 * ########################################################################
 */
extern UARTRX_BUFFER_READ_STRUCT ReceiverUARTRx3_read_structure;
uint8_t ReceiverUARTRx3_Receive(uint8_t *buffer, uint16_t size);
void enable_ReceiverUARTRx3(void);

/* ########################################################################
 * Name: <S1>/UART Rx3
 * Id: fromshangweijiUARTRx3
 * ########################################################################
 */
extern UARTRX_BUFFER_READ_STRUCT fromshangweijiUARTRx3_read_structure;
uint8_t fromshangweijiUARTRx3_Receive(uint8_t *buffer, uint16_t size);

/* Data */
extern float fromshangweijiUARTRx3_data0;
extern float fromshangweijiUARTRx3_data1;
extern float fromshangweijiUARTRx3_data2;
extern float fromshangweijiUARTRx3_data3;
extern float fromshangweijiUARTRx3_data4;

#define fromshangweijiUARTRx3_terminator_SIZE 2

extern const char fromshangweijiUARTRx3_terminator[];
void enable_fromshangweijiUARTRx3(void);
void enable_executeBasicPWM7(void);    /* executeBasicPWM7 */

/* ########################################################################
 * Name: <S11>/UART Tx
 * Id: toshangweijiUARTTx
 * ########################################################################
 */
void enable_toshangweijiUARTTx(void);

/* ########################################################################
 * Name: <S1>/UART Rx4
 * Id: fromshangweijiUARTRx4
 * ########################################################################
 */
extern UARTRX_BUFFER_READ_STRUCT fromshangweijiUARTRx4_read_structure;
uint8_t fromshangweijiUARTRx4_Receive(uint8_t *buffer, uint16_t size);

/* Data */
extern float fromshangweijiUARTRx4_data0;
extern float fromshangweijiUARTRx4_data1;
extern float fromshangweijiUARTRx4_data2;
extern float fromshangweijiUARTRx4_data3;
extern float fromshangweijiUARTRx4_data4;

#define fromshangweijiUARTRx4_terminator_SIZE 2

extern const char fromshangweijiUARTRx4_terminator[];
void enable_fromshangweijiUARTRx4(void);

/* ########################################################################
 * Name: <S1>/UART Rx5
 * Id: fromshangweijiUARTRx5
 * ########################################################################
 */
extern UARTRX_BUFFER_READ_STRUCT fromshangweijiUARTRx5_read_structure;
uint8_t fromshangweijiUARTRx5_Receive(uint8_t *buffer, uint16_t size);

/* Data */
extern float fromshangweijiUARTRx5_data0;
extern float fromshangweijiUARTRx5_data1;
extern float fromshangweijiUARTRx5_data2;
extern float fromshangweijiUARTRx5_data3;
extern float fromshangweijiUARTRx5_data4;

#define fromshangweijiUARTRx5_terminator_SIZE 2

extern const char fromshangweijiUARTRx5_terminator[];
void enable_fromshangweijiUARTRx5(void);

/* ########################################################################
 * Name: <S1>/UART Rx1
 * Id: fromshangweijiUARTRx1
 * ########################################################################
 */
extern UARTRX_BUFFER_READ_STRUCT fromshangweijiUARTRx1_read_structure;
uint8_t fromshangweijiUARTRx1_Receive(uint8_t *buffer, uint16_t size);

/* Data */
extern uint32_t fromshangweijiUARTRx1_data0;

#define fromshangweijiUARTRx1_terminator_SIZE 2

extern const char fromshangweijiUARTRx1_terminator[];
void enable_fromshangweijiUARTRx1(void);

/* ########################################################################
 * Name: <S1>/UART Rx
 * Id: fromshangweijiUARTRx
 * ########################################################################
 */
extern UARTRX_BUFFER_READ_STRUCT fromshangweijiUARTRx_read_structure;
uint8_t fromshangweijiUARTRx_Receive(uint8_t *buffer, uint16_t size);

/* Data */
#define fromshangweijiUARTRx_terminator_SIZE 2

extern const char fromshangweijiUARTRx_terminator[];
void enable_fromshangweijiUARTRx(void);

/* ########################################################################
 * Name: <S1>/UART Rx2
 * Id: fromshangweijiUARTRx2
 * ########################################################################
 */
extern UARTRX_BUFFER_READ_STRUCT fromshangweijiUARTRx2_read_structure;
uint8_t fromshangweijiUARTRx2_Receive(uint8_t *buffer, uint16_t size);

/* Data */
#define fromshangweijiUARTRx2_terminator_SIZE 2

extern const char fromshangweijiUARTRx2_terminator[];
void enable_fromshangweijiUARTRx2(void);

/* ########################################################################
 * Name: <S10>/UART Setup
 * Id: initUARTSetup
 * ########################################################################
 */
#define UTX1_BUFFER_SIZE               512

extern uint8_t UART1_Tx_Buffer[];
extern UART_TX_STATE initUARTSetup_Tx_State;
extern void UART1_TxUpdate(uint16_t count);

#define URX1_BUFFER_SIZE               512

extern uint8_t UART1_Rx_Buffer[];
extern uint8_t UART1_Temp_Buffer[];
uint16_t UART1_ReadLine(UARTRX_BUFFER_READ_STRUCT *read_struct, const char
  *terminator, uint16_t terminator_count, uint8_t *buffer, uint16_t buffer_size);
uint8_t UART1_ReadBinary(UARTRX_BUFFER_READ_STRUCT *read_struct, const char
  *header, uint16_t header_count, const char *terminator, uint16_t
  terminator_count, uint8_t *buffer, uint16_t data_count);
void UART1_RestoreBytes(UARTRX_BUFFER_READ_STRUCT *read_struct, uint16_t count);
extern uint16_t UART1_GetInitNDTR(void);
void UART1_Read(UARTRX_BUFFER_READ_STRUCT *read_struct);
void UART1_ReadEx(UARTRX_BUFFER_READ_STRUCT *read_struct, uint8_t *buffer,
                  uint16_t buffer_size, uint16_t*reading_count);
extern void UART1_Write(uint8_t* data, uint16_t count);
extern UART_TX_STATE UART1_FlushTxBuffer(void);
void enable_initUARTSetup(void);

/* ########################################################################
 * Name: <S10>/UART Setup1
 * Id: initUARTSetup1
 * ########################################################################
 */
#define UTX3_BUFFER_SIZE               512

extern uint8_t UART3_Tx_Buffer[];
extern UART_TX_STATE initUARTSetup1_Tx_State;
extern void UART3_TxUpdate(uint16_t count);

#define URX3_BUFFER_SIZE               512

extern uint8_t UART3_Rx_Buffer[];
extern uint8_t UART3_Temp_Buffer[];
uint16_t UART3_ReadLine(UARTRX_BUFFER_READ_STRUCT *read_struct, const char
  *terminator, uint16_t terminator_count, uint8_t *buffer, uint16_t buffer_size);
uint8_t UART3_ReadBinary(UARTRX_BUFFER_READ_STRUCT *read_struct, const char
  *header, uint16_t header_count, const char *terminator, uint16_t
  terminator_count, uint8_t *buffer, uint16_t data_count);
void UART3_RestoreBytes(UARTRX_BUFFER_READ_STRUCT *read_struct, uint16_t count);
extern uint16_t UART3_GetInitNDTR(void);
void UART3_Read(UARTRX_BUFFER_READ_STRUCT *read_struct);
void UART3_ReadEx(UARTRX_BUFFER_READ_STRUCT *read_struct, uint8_t *buffer,
                  uint16_t buffer_size, uint16_t*reading_count);
extern void UART3_Write(uint8_t* data, uint16_t count);
extern UART_TX_STATE UART3_FlushTxBuffer(void);
void enable_initUARTSetup1(void);

/* ########################################################################
 * Name: <S10>/UART Setup2
 * Id: initUARTSetup2
 * ########################################################################
 */
#define URX2_BUFFER_SIZE               512

extern uint8_t UART2_Rx_Buffer[];
extern uint8_t UART2_Temp_Buffer[];
uint16_t UART2_ReadLine(UARTRX_BUFFER_READ_STRUCT *read_struct, const char
  *terminator, uint16_t terminator_count, uint8_t *buffer, uint16_t buffer_size);
uint8_t UART2_ReadBinary(UARTRX_BUFFER_READ_STRUCT *read_struct, const char
  *header, uint16_t header_count, const char *terminator, uint16_t
  terminator_count, uint8_t *buffer, uint16_t data_count);
void UART2_RestoreBytes(UARTRX_BUFFER_READ_STRUCT *read_struct, uint16_t count);
extern uint16_t UART2_GetInitNDTR(void);
void UART2_Read(UARTRX_BUFFER_READ_STRUCT *read_struct);
void UART2_ReadEx(UARTRX_BUFFER_READ_STRUCT *read_struct, uint8_t *buffer,
                  uint16_t buffer_size, uint16_t*reading_count);
extern void UART2_Write(uint8_t* data, uint16_t count);
extern UART_TX_STATE UART2_FlushTxBuffer(void);
void enable_initUARTSetup2(void);

/* ########################################################################
 * Timer
 * ########################################################################
 */
#define SYS_CURRENT_TICK               (SysTick->VAL)
#define SYS_TICKSTEP                   0.001f

typedef struct {
  uint32_t start;
  uint32_t length;
} SYS_TIMER_STRUCT;

#define SYSTIMER_FLAGS_TIMEOUT         0x01

typedef struct {
  uint8_t flags;
  uint32_t tid;                        /* Tick count */
  uint32_t tick;                       /* Capture cuttent tick */
  uint32_t target_us;                  /* Target of systick */
} SYS_TIMER_uS_STRUCT;

extern volatile unsigned int systick_count;
void SysTimer_Start(SYS_TIMER_STRUCT* timer, uint32_t ms);
void SysTimer_uS_Start(SYS_TIMER_uS_STRUCT *timer, uint32_t us);
int SysTimer_IsTimeout(SYS_TIMER_STRUCT* timer);
int SysTimer_uS_IsTimeout(SYS_TIMER_uS_STRUCT* timer);
void SysTimer_delay_us(uint32_t us);

#endif                                 /* RTW_HEADER_waijung_hwdrvlib_h_ */

/* [EOF] */

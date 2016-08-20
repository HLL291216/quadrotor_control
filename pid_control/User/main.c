/*
 * File: main.c
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model download.
 *
 * Model version                        : 1.90
 * Real-Time Workshop file version      : 8.6 (R2014a) 27-Dec-2013
 * Real-Time Workshop file generated on : Wed Jun 15 18:41:32 2016
 * TLC version                          : 8.6 (Jan 30 2014)
 * C/C++ source code generated on       : Wed Jun 15 18:41:34 2016
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "includes.h"
#include "app_cfg.h"
#include "waijung_hwdrvlib.h"
#include "rtwtypes.h"                  /* MathWorks types */
#include "app_task.h"
#include "download.h"
#include "download_private.h"
#include "stm32f4xx_flash.h"
/*
 * rt_Onestep is called from a timer ISR at the base sample time of 0.005 sec.
 * The ISR is void SysTick_Handler(void) and is defined in stm32f4xx_it.c
 */
volatile unsigned int systick_count = 1;
static volatile unsigned int systick_active = 0;
static  OS_STK App_TaskStartStk[APP_TASK_START_STK_SIZE];
static  OS_STK Task_main_controlStk[Task_main_control_STK_SIZE];
static  OS_STK Task_Com1Stk[Task_Com1_STK_SIZE];
static  OS_STK Task_IMUStk[Task_IMU_STK_SIZE];
static  OS_STK Task_RecStk[Task_Rec_STK_SIZE];
static  void App_TaskCreate(void);
static  void Task_main_control(void* p_arg);
static  void Task_dianji(void* p_arg);
static  void Task_Com1(void* p_arg);
static  void Task_IMU(void* p_arg);
static  void Task_Rec(void* p_arg);
static  void App_TaskStart(void* p_arg);
OS_EVENT* IMU_SEM;
OS_EVENT* Rec_SEM;
OS_EVENT* control_SEM;
void rt_OneStep(void);
void SystemClock_Config(void);
void canshu_init(void);
/* Main program */
int_T main(void)
{
   //UCOS ��ʼ��
   OSInit();                                                   /* Initialize "uC/OS-II, The Real-Time Kernel".         */
  /* Initialize model */
	SystemClock_Config();
  download_initialize();

  /* Continue indefinitely */
  if (SysTick_Config(SYSTICKRELOADVALUE)) {
    /* Capture error */
    while (1) ;
  }
  OSTaskCreate((void (*) (void *)) App_TaskStart,	  		  		//ָ����������ָ��
                          (void *) 0,								  		//����ʼִ��ʱ�����ݸ�����Ĳ�����ָ��
               (OS_STK *) &App_TaskStartStk[APP_TASK_START_STK_SIZE - 1],	//���������Ķ�ջ��ջ��ָ��   �Ӷ����µݼ�
               (INT8U) APP_TASK_START_PRIO);								//�������������ȼ�
	OSStart();	
//  while (1) {
//    if (systick_active != systick_count) {
//      systick_active ++;
//      download_step();

//      /* Get model outputs here */

//      /* Profiler update */
//    }
//  }
}
/*
*********************************************************************************************************
*                                          App_TaskStart()
*
* Description : The startup task.  The uC/OS-II ticker should only be initialize once multitasking starts.
*
* Argument : p_arg       Argument passed to 'App_TaskStart()' by 'OSTaskCreate()'.
*
* Return   : none.
*
* Caller   : This is a task.
*
* Note     : none.
*********************************************************************************************************
*/

static  void App_TaskStart(void* p_arg)
{
   

    OS_CPU_SR cpu_sr=0;
   (void) p_arg;

//ʹ��ucos ��ͳ������
#if (OS_TASK_STAT_EN > 0)
   //----ͳ�������ʼ������  
   OSStatInit();                                               /* Determine CPU capacity.                              */
#endif
   //��������������
	 OS_ENTER_CRITICAL();			//�����ٽ���(�޷����жϴ��) 
   App_TaskCreate();
   OSTaskDel(OS_PRIO_SELF);
	 OS_EXIT_CRITICAL();				//�˳��ٽ���(���Ա��жϴ��)
}
//Com1����----------------------------------------
static  void Task_Com1(void* p_arg)
{	
    INT8U err;
	 (void) p_arg;
	  canshu_init();
   	while (1)
 {  OSSemPend(control_SEM,10,&err); 		           //�ȴ�control�ź��� 
    com1();
	  OSTimeDlyHMSM(0, 0, 0,100);//����100ms
 }
}
//��������----------------------------------------
static  void Task_main_control(void* p_arg)
{		
	  INT8U err; 
	 (void) p_arg;
		while (1)
   { 
	    OSSemPend(IMU_SEM,5,&err); 		           //�ȴ�IMU�ź��� 
		  OSSemPend(Rec_SEM,5,&err); 		           //�ȴ�Rec�ź��� 
		  OSSchedLock();//��������
      control();
		  OSSemPost(control_SEM);//���ճɹ��ź���
		  OSSchedUnlock();//�������
      OSTimeDlyHMSM(0, 0, 0,10);//���������10ms
   }
}
	//IMU����----------------------------------------
static  void Task_main_IMU(void* p_arg)
{		
	  INT8U err;
	 (void) p_arg;
		while (1)
   { 	 
      IMU();
		  if(download_B.angle_o1==1)
			{
			OSSemPost(IMU_SEM);//���ճɹ��ź���
			}
      OSTimeDlyHMSM(0, 0, 0,5);//���������3ms
   }
}
//���ջ�����---------------------------------------
static  void Task_main_Rec(void* p_arg)
{		
	  INT8U err;

	
	 (void) p_arg;

		while (1)
   { 	 
      Rec();
		  if(download_B.UARTRx3_o1==1)
			{
			OSSemPost(Rec_SEM);//���ճɹ��ź���
			}
      OSTimeDlyHMSM(0, 0, 0,5);//���������3ms
   }
}

/*
*********************************************************************************************************
*                                            App_TaskCreate()
*
* Description : Create the application tasks.
*
* Argument : none.
*
* Return   : none.
*
* Caller   : App_TaskStart().
*
* Note     : none.
*********************************************************************************************************
*/

static  void App_TaskCreate(void)
{
//	Com3_MBOX=OSMboxCreate((void *) 0);		     //��������1�жϵ���Ϣ����
//	PWM_MBOX=OSMboxCreate((void *) 0);		     //����PWM�жϵ���Ϣ����
 
	IMU_SEM=OSSemCreate(1);	 //����IMU���ź���
	Rec_SEM=OSSemCreate(1);//����Rec�ź���
	control_SEM=OSSemCreate(1);//���������ź���
//	while(SI4432_Sstart());
	
    //Rec����------------------------------------------------------
   OSTaskCreateExt(Task_main_Rec,(void *)0,(OS_STK *)&Task_RecStk[Task_Rec_STK_SIZE-1],Task_Rec_PRIO,Task_Rec_PRIO,(OS_STK *)&Task_RecStk[0],
                    Task_Rec_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CHK|OS_TASK_OPT_STK_CLR);
	    //control����-----------------------------------------------------
   OSTaskCreateExt(Task_main_control,(void *)0,(OS_STK *)&Task_main_controlStk[Task_main_control_STK_SIZE-1],Task_main_control_PRIO,Task_main_control_PRIO,(OS_STK *)&Task_main_controlStk[0],
                    Task_main_control_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CHK|OS_TASK_OPT_STK_CLR);
			//IMU����-----------------------------------------------------
    OSTaskCreateExt(Task_main_IMU,(void *)0,(OS_STK *)&Task_IMUStk[Task_IMU_STK_SIZE-1],Task_IMU_PRIO,Task_IMU_PRIO,(OS_STK *)&Task_IMUStk[0],
                     Task_IMU_STK_SIZE,
                     (void *)0,
                     OS_TASK_OPT_STK_CHK|OS_TASK_OPT_STK_CLR);		
		 //Com1����------------------------------------------------------
   OSTaskCreateExt(Task_Com1,(void *)0,(OS_STK *)&Task_Com1Stk[Task_Com1_STK_SIZE-1],Task_Com1_PRIO,Task_Com1_PRIO,(OS_STK *)&Task_Com1Stk[0],
                    Task_Com1_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CHK|OS_TASK_OPT_STK_CLR);												 
}
/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_DeInit();//����RCCȱʡ����HSI��8MHZ,PLL�رգ�HSE�ر�...
	RCC_HSEConfig(RCC_HSE_OFF);
  RCC_HSICmd(ENABLE);
  while(RCC_GetFlagStatus(RCC_FLAG_HSIRDY)== RESET);//�ȴ�HSI����
	RCC_PLLConfig(RCC_PLLSource_HSI ,8,168,2,7); //SYSCLK=168MHZ;
	RCC_HCLKConfig(RCC_SYSCLK_Div1);//	HCLK = SYSCLK=168MHZ
  RCC_PCLK1Config(RCC_HCLK_Div4); //APB1ʱ��= 42MHZ 
  RCC_PCLK2Config(RCC_HCLK_Div2);//APB2=84MHZ 
	RCC_PLLCmd(ENABLE);//����PLL��Ϊϵͳʱ��
  FLASH_SetLatency(FLASH_Latency_5); //Flash�洢��ʱ5����
  FLASH_PrefetchBufferCmd(ENABLE);//Ԥȡ����ʹ��
  RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK); //ѡ��PLL��Ϊϵͳʱ��
  while(RCC_GetSYSCLKSource()!= 0x08);//����ϵͳʱ���Ƿ�ΪPLL���ʱ��
}

void rt_OneStep(void)
{
  /* Tick counter */
   OS_CPU_SR  cpu_sr;


    OS_ENTER_CRITICAL();  //����ȫ���жϱ�־,�����ж�/* Tell uC/OS-II that we are starting an ISR*/
    OSIntNesting++;	   //OSSemPost(NMEA_MBOX); 
    OS_EXIT_CRITICAL();	  //�ָ�ȫ���жϱ�־

    OSTimeTick();     /* Call uC/OS-II's OSTimeTick(),��os_core.c�ļ��ﶨ��,��Ҫ�ж���ʱ�������Ƿ��ʱ��*/
	
    OSIntExit();  //��os_core.c�ļ��ﶨ��,����и������ȼ������������,��ִ��һ�������л�  
//  systick_count++;
}

/**
 * @brief  This function handles SysTick Handler.
 * @param  None
 * @retval None
 */
void SysTick_Handler(void)
{
  rt_OneStep();
}

void canshu_init(void)
{
	    // roll
//	        /* Inport: '<S15>/P' */
//      download_B.P_e = 9;

//      /* Inport: '<S15>/nP' */
//      download_B.nP_i = 8;

//      /* Inport: '<S15>/nI' */
//      download_B.nI_e = 10;

//      /* Inport: '<S15>/nD' */
//      download_B.nD_l = 1.2;

//      /* Inport: '<S15>/status' */
//      download_B.status_o = 1;
//	
		        /* Inport: '<S15>/P' */
      download_B.P_e = 6;

      /* Inport: '<S15>/nP' */
      download_B.nP_i = 8.5;

      /* Inport: '<S15>/nI' */
      download_B.nI_e = 10;

      /* Inport: '<S15>/nD' */
      download_B.nD_l = 0.8;

      /* Inport: '<S15>/status' */
      download_B.status_o = 1;
	
	      //yaw
	      /* Inport: '<S16>/P' */
      download_B.P_g = 4;

      /* Inport: '<S16>/nP' */
      download_B.nP_m = 10;

      /* Inport: '<S16>/nI' */
      download_B.nI_a = 2;

      /* Inport: '<S16>/nD' */
      download_B.nD_d = 0.8;

      /* Inport: '<S16>/status' */
      download_B.status_k = 1;
			
			//alt
		  /* Inport: '<S17>/P' */
      download_B.P = 4;

      /* Inport: '<S17>/nP' */
      download_B.nP = 2;

      /* Inport: '<S17>/nI' */
      download_B.nI = 1;

      /* Inport: '<S17>/nD' */
      download_B.nD = 0.5;

      /* Inport: '<S17>/status' */
      download_B.status = 1;

}
/* [EOF] */

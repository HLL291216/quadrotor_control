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
   //UCOS 初始化
   OSInit();                                                   /* Initialize "uC/OS-II, The Real-Time Kernel".         */
  /* Initialize model */
	SystemClock_Config();
  download_initialize();

  /* Continue indefinitely */
  if (SysTick_Config(SYSTICKRELOADVALUE)) {
    /* Capture error */
    while (1) ;
  }
  OSTaskCreate((void (*) (void *)) App_TaskStart,	  		  		//指向任务代码的指针
                          (void *) 0,								  		//任务开始执行时，传递给任务的参数的指针
               (OS_STK *) &App_TaskStartStk[APP_TASK_START_STK_SIZE - 1],	//分配给任务的堆栈的栈顶指针   从顶向下递减
               (INT8U) APP_TASK_START_PRIO);								//分配给任务的优先级
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

//使能ucos 的统计任务
#if (OS_TASK_STAT_EN > 0)
   //----统计任务初始化函数  
   OSStatInit();                                               /* Determine CPU capacity.                              */
#endif
   //建立其他的任务
	 OS_ENTER_CRITICAL();			//进入临界区(无法被中断打断) 
   App_TaskCreate();
   OSTaskDel(OS_PRIO_SELF);
	 OS_EXIT_CRITICAL();				//退出临界区(可以被中断打断)
}
//Com1任务----------------------------------------
static  void Task_Com1(void* p_arg)
{	
    INT8U err;
	 (void) p_arg;
	  canshu_init();
   	while (1)
 {  OSSemPend(control_SEM,10,&err); 		           //等待control信号量 
    com1();
	  OSTimeDlyHMSM(0, 0, 0,100);//周期100ms
 }
}
//主控任务----------------------------------------
static  void Task_main_control(void* p_arg)
{		
	  INT8U err; 
	 (void) p_arg;
		while (1)
   { 
	    OSSemPend(IMU_SEM,5,&err); 		           //等待IMU信号量 
		  OSSemPend(Rec_SEM,5,&err); 		           //等待Rec信号量 
		  OSSchedLock();//任务上锁
      control();
		  OSSemPost(control_SEM);//接收成功信号量
		  OSSchedUnlock();//任务解锁
      OSTimeDlyHMSM(0, 0, 0,10);//电调是周期10ms
   }
}
	//IMU任务----------------------------------------
static  void Task_main_IMU(void* p_arg)
{		
	  INT8U err;
	 (void) p_arg;
		while (1)
   { 	 
      IMU();
		  if(download_B.angle_o1==1)
			{
			OSSemPost(IMU_SEM);//接收成功信号量
			}
      OSTimeDlyHMSM(0, 0, 0,5);//电调是周期3ms
   }
}
//接收机任务---------------------------------------
static  void Task_main_Rec(void* p_arg)
{		
	  INT8U err;

	
	 (void) p_arg;

		while (1)
   { 	 
      Rec();
		  if(download_B.UARTRx3_o1==1)
			{
			OSSemPost(Rec_SEM);//接收成功信号量
			}
      OSTimeDlyHMSM(0, 0, 0,5);//电调是周期3ms
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
//	Com3_MBOX=OSMboxCreate((void *) 0);		     //建立串口1中断的消息邮箱
//	PWM_MBOX=OSMboxCreate((void *) 0);		     //建立PWM中断的消息邮箱
 
	IMU_SEM=OSSemCreate(1);	 //建立IMU的信号量
	Rec_SEM=OSSemCreate(1);//建立Rec信号量
	control_SEM=OSSemCreate(1);//建立控制信号量
//	while(SI4432_Sstart());
	
    //Rec任务------------------------------------------------------
   OSTaskCreateExt(Task_main_Rec,(void *)0,(OS_STK *)&Task_RecStk[Task_Rec_STK_SIZE-1],Task_Rec_PRIO,Task_Rec_PRIO,(OS_STK *)&Task_RecStk[0],
                    Task_Rec_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CHK|OS_TASK_OPT_STK_CLR);
	    //control任务-----------------------------------------------------
   OSTaskCreateExt(Task_main_control,(void *)0,(OS_STK *)&Task_main_controlStk[Task_main_control_STK_SIZE-1],Task_main_control_PRIO,Task_main_control_PRIO,(OS_STK *)&Task_main_controlStk[0],
                    Task_main_control_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CHK|OS_TASK_OPT_STK_CLR);
			//IMU任务-----------------------------------------------------
    OSTaskCreateExt(Task_main_IMU,(void *)0,(OS_STK *)&Task_IMUStk[Task_IMU_STK_SIZE-1],Task_IMU_PRIO,Task_IMU_PRIO,(OS_STK *)&Task_IMUStk[0],
                     Task_IMU_STK_SIZE,
                     (void *)0,
                     OS_TASK_OPT_STK_CHK|OS_TASK_OPT_STK_CLR);		
		 //Com1任务------------------------------------------------------
   OSTaskCreateExt(Task_Com1,(void *)0,(OS_STK *)&Task_Com1Stk[Task_Com1_STK_SIZE-1],Task_Com1_PRIO,Task_Com1_PRIO,(OS_STK *)&Task_Com1Stk[0],
                    Task_Com1_STK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CHK|OS_TASK_OPT_STK_CLR);												 
}
/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_DeInit();//设置RCC缺省化，HSI打开8MHZ,PLL关闭，HSE关闭...
	RCC_HSEConfig(RCC_HSE_OFF);
  RCC_HSICmd(ENABLE);
  while(RCC_GetFlagStatus(RCC_FLAG_HSIRDY)== RESET);//等待HSI就绪
	RCC_PLLConfig(RCC_PLLSource_HSI ,8,168,2,7); //SYSCLK=168MHZ;
	RCC_HCLKConfig(RCC_SYSCLK_Div1);//	HCLK = SYSCLK=168MHZ
  RCC_PCLK1Config(RCC_HCLK_Div4); //APB1时钟= 42MHZ 
  RCC_PCLK2Config(RCC_HCLK_Div2);//APB2=84MHZ 
	RCC_PLLCmd(ENABLE);//启用PLL作为系统时钟
  FLASH_SetLatency(FLASH_Latency_5); //Flash存储延时5周期
  FLASH_PrefetchBufferCmd(ENABLE);//预取缓存使能
  RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK); //选择PLL作为系统时钟
  while(RCC_GetSYSCLKSource()!= 0x08);//测试系统时钟是否为PLL输出时钟
}

void rt_OneStep(void)
{
  /* Tick counter */
   OS_CPU_SR  cpu_sr;


    OS_ENTER_CRITICAL();  //保存全局中断标志,关总中断/* Tell uC/OS-II that we are starting an ISR*/
    OSIntNesting++;	   //OSSemPost(NMEA_MBOX); 
    OS_EXIT_CRITICAL();	  //恢复全局中断标志

    OSTimeTick();     /* Call uC/OS-II's OSTimeTick(),在os_core.c文件里定义,主要判断延时的任务是否计时到*/
	
    OSIntExit();  //在os_core.c文件里定义,如果有更高优先级的任务就绪了,则执行一次任务切换  
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

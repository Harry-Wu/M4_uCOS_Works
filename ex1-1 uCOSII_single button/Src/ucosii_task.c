#include "stm32f4xx.h"
#include "includes.h"
#include "led.h"
#include "ucosii_task.h"
#include "MyTypeDef.h"
#include "key.h"


OS_STK START_TASK_STK[START_TASK_STK_LEN];
void start_task(void *pdata)
{
	u8 sta;
	OS_STK_DATA p_stk_data;
	pdata = pdata;
	OSStatInit();    //初始化统计任务，OS_TASK_STAT_EN 必须置为 1，
									//该函数只能在第一个被建立并运行的任务中调用
	
	sta = OSTaskCreate(key_task,NULL,&KEY_TASK_STK[KEY_TASK_STK_LEN-1],KEY_TASK_PRIO);
	if(sta!=OS_ERR_NONE)
	{
		LED6 = 0;
	}
	
	sta=OSTaskCreate(beep_task,NULL,&BEEP_TASK_STK[BEEP_TASK_STK_LEN-1],BEEP_TASK_PRIO);
	if(sta!=OS_ERR_NONE)
	{
		LED6 = 0;
	}
	
	while(1)
	{
		OSTaskStkChk(OS_PRIO_SELF,&p_stk_data);
		LED6 = !LED6;
		OSTimeDly(100);
		//printf("CPU%%=%d%%\r\n", OSCPUUsage);
		//printf("start_stk=%d%%\r\n",p_stk_data.OSUsed*100/(p_stk_data.OSUsed+p_stk_data.OSFree));
	}
	
}

OS_STK KEY_TASK_STK[KEY_TASK_STK_LEN];
void key_task(void *pdata)
{
	u8 key;
	pdata = pdata;
	while(1)
	{
		key = key_scanf();
		if(key != NO_KEY)
		{
			OSTaskResume(BEEP_TASK_PRIO);
		}
		OSTimeDly(1);
	}
}

OS_STK BEEP_TASK_STK[BEEP_TASK_STK_LEN];
void beep_task(void *pdata)
{	
	pdata=pdata;	
	while(1)
	{
		OSTaskSuspend(OS_PRIO_SELF);
		BUZZER1=1;
		OSTimeDly(5);
		BUZZER1=0;
	}	
}

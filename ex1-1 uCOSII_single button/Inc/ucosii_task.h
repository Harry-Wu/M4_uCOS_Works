#ifndef _UCOSII_TASK_H_
#define	_UCOSII_TASK_H_
#include "includes.h"
#include "stm32f4xx.h"

#define START_TASK_PRIO     5  //�������ȼ�
#define START_TASK_STK_LEN  128  //��ջ��С128�ֽ�
extern OS_STK START_TASK_STK[];
void start_task(void *pdata);

#define KEY_TASK_PRIO     10
#define KEY_TASK_STK_LEN  128  
extern OS_STK KEY_TASK_STK[];
void key_task(void *pdata);

#define BEEP_TASK_PRIO     13
#define BEEP_TASK_STK_LEN  128
extern OS_STK BEEP_TASK_STK[];
void beep_task(void *pdata);

#endif

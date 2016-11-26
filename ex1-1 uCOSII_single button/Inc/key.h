#ifndef _KEY_H_
#define _KEY_H_
#include "stm32f4xx.h"
#include "MyTypeDef.h"

#define KEY1 PAin(0)
#define KEY2 PEin(2)
#define KEY3 PEin(3)
#define KEY4 PEin(4)

#define NO_KEY  0xff
#define KEY1_OK  1
#define KEY2_OK  2
#define KEY3_OK  3
#define KEY4_OK  4

extern u8 key;

//void key_init(void);
u8 key_scanf(void);

#endif

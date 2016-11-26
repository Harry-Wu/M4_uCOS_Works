/*****************************************************************************
@File name: MyTypeDef.h 
@Description: 
@Author: Harry Wu
@Version: V1.1
@Date: 2016-11-09
@History: 
        V1.1: Add io_bit.h content
*****************************************************************************/

#ifndef _MYTYPEDEF_H_
#define _MYTYPEDEF_H_

#include "core_cm4.h"             /* Cortex-M4 processor and core peripherals */
#include "system_stm32f4xx.h"
#include <stdint.h>

/** @addtogroup Exported_types
  * @{
  */  
/*!< STM32F10x Standard Peripheral Library old types (maintained for legacy purpose) */
typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef const int32_t sc32;  /*!< Read Only */
typedef const int16_t sc16;  /*!< Read Only */
typedef const int8_t sc8;   /*!< Read Only */

typedef __IO int32_t  vs32;
typedef __IO int16_t  vs16;
typedef __IO int8_t   vs8;

typedef __I int32_t vsc32;  /*!< Read Only */
typedef __I int16_t vsc16;  /*!< Read Only */
typedef __I int8_t vsc8;   /*!< Read Only */

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef const uint32_t uc32;  /*!< Read Only */
typedef const uint16_t uc16;  /*!< Read Only */
typedef const uint8_t uc8;   /*!< Read Only */

typedef __IO uint32_t  vu32;
typedef __IO uint16_t vu16;
typedef __IO uint8_t  vu8;

typedef __I uint32_t vuc32;  /*!< Read Only */
typedef __I uint16_t vuc16;  /*!< Read Only */
typedef __I uint8_t vuc8;   /*!< Read Only */

//typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;

//typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
//#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

//typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;

#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr&0xFFFFF)<<5)+(bitnum<<2))
#define MEM_ADDR(addr) *((volatile unsigned long *)(addr))
#define BIT_ADDR(addr, bitnum) MEM_ADDR(BITBAND(addr, bitnum))
//F4XXIO �ڵ�ַӳ��
#define GPIOA_ODR_Addr (GPIOA_BASE+20) //0x40020014
#define GPIOB_ODR_Addr (GPIOB_BASE+20) //0x40020414
#define GPIOC_ODR_Addr (GPIOC_BASE+20) //0x40020814
#define GPIOD_ODR_Addr (GPIOD_BASE+20) //0x40020C14
#define GPIOE_ODR_Addr (GPIOE_BASE+20) //0x40021014
#define GPIOF_ODR_Addr (GPIOF_BASE+20) //0x40021414
#define GPIOG_ODR_Addr (GPIOG_BASE+20) //0x40021814
#define GPIOH_ODR_Addr (GPIOH_BASE+20) //0x40021C14
#define GPIOI_ODR_Addr (GPIOI_BASE+20) //0x40022014
#define GPIOA_IDR_Addr (GPIOA_BASE+16) //0x40020010
#define GPIOB_IDR_Addr (GPIOB_BASE+16) //0x40020410
#define GPIOC_IDR_Addr (GPIOC_BASE+16) //0x40020810
#define GPIOD_IDR_Addr (GPIOD_BASE+16) //0x40020C10
#define GPIOE_IDR_Addr (GPIOE_BASE+16) //0x40021010
#define GPIOF_IDR_Addr (GPIOF_BASE+16) //0x40021410
#define GPIOG_IDR_Addr (GPIOG_BASE+16) //0x40021810
#define GPIOH_IDR_Addr (GPIOF_BASE+16) //0x40021C10
#define GPIOI_IDR_Addr (GPIOG_BASE+16) //0x40022010
//F4XXIO �ڲ���,ֻ�Ե�һ��IO ��,n ��ֵ��Χ[0-15]
#define PAout(n) 		BIT_ADDR(GPIOA_ODR_Addr,n) //GPIOA ĳһλ���
#define PAin(n) 		BIT_ADDR(GPIOA_IDR_Addr,n) //GPIOA ĳһλ����
#define PBout(n) 		BIT_ADDR(GPIOB_ODR_Addr,n) //GPIOB ĳһλ���
#define	PBin(n) 		BIT_ADDR(GPIOB_IDR_Addr,n) //GPIOB ĳһλ����
#define PCout(n)		BIT_ADDR(GPIOC_ODR_Addr,n) //GPIOC ĳһλ���
#define PCin(n) 		BIT_ADDR(GPIOC_IDR_Addr,n) //GPIOC ĳһλ����
#define PDout(n) 		BIT_ADDR(GPIOD_ODR_Addr,n) //GPIOD ĳһλ���
#define PDin(n) 		BIT_ADDR(GPIOD_IDR_Addr,n) //GPIOD ĳһλ����
#define PEout(n) 		BIT_ADDR(GPIOE_ODR_Addr,n) //GPIOE ĳһλ���
#define PEin(n) 		BIT_ADDR(GPIOE_IDR_Addr,n) //GPIOE ĳһλ����
#define PFout(n) 		BIT_ADDR(GPIOF_ODR_Addr,n) //GPIOF ĳһλ���
#define PFin(n) 		BIT_ADDR(GPIOF_IDR_Addr,n) //GPIOF ĳһλ����
#define PGout(n) 		BIT_ADDR(GPIOG_ODR_Addr,n) //GPIOG ĳһλ���
#define PGin(n) 		BIT_ADDR(GPIOG_IDR_Addr,n) //GPIOG ĳһλ����
#define PHout(n) 		BIT_ADDR(GPIOH_ODR_Addr,n) //GPIOH ĳһλ���
#define PHin(n) 		BIT_ADDR(GPIOH_IDR_Addr,n) //GPIOH ĳһλ����
#define PIout(n) 		BIT_ADDR(GPIOI_ODR_Addr,n) //GPIOI ĳһλ���
#define PIin(n) 		BIT_ADDR(GPIOI_IDR_Addr,n) //GPIOI ĳһλ����




#endif

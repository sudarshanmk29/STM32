/*
 * custom_gpio_hal.h
 *
 *  Created on: May 28, 2025
 *      Author: MQD1COB
 */

#ifndef INC_CUSTOM_GPIO_HAL_H_
#define INC_CUSTOM_GPIO_HAL_H_

#include <stdio.h>
#include <stdint.h>

#define     __IO    volatile             /*!< Defines 'read / write' permissions */

#define RCC_Base 0x40023800
#define GPIOA_Base 0x40020000
#define GPIOB_Base 0x40020400
#define GPIOC_Base 0x40020800
#define GPIOD_Base 0x40020C00

typedef enum GPIO_Port
{
	RCC_GPIOA,
	RCC_GPIOB,
	RCC_GPIOC,
	RCC_GPIOD,
	RCC_GPIOE,
	RCC_GPIOF,
	RCC_GPIOG,
	RCC_GPIOH,
	RCC_GPIOI
}GPIO_Port;

typedef enum GPIO_Pin
{
	GPIO_Pin0,
	GPIO_Pin1,
	GPIO_Pin2,
	GPIO_Pin3,
	GPIO_Pin4,
	GPIO_Pin5,
	GPIO_Pin6,
	GPIO_Pin7,
	GPIO_Pin8,
	GPIO_Pin9,
	GPIO_Pin10,
	GPIO_Pin11,
	GPIO_Pin12,
	GPIO_Pin13,
	GPIO_Pin14,
	GPIO_Pin15
}GPIO_Pin;

typedef struct
{
	__IO uint32_t RCC_CR;
	__IO uint32_t RCC_PLLCFGR;
	__IO uint32_t RCC_CFGR;
	__IO uint32_t RCC_CIR;
	__IO uint32_t RCC_AHB1RSTR;
	__IO uint32_t RCC_AHB2RSTR;
	__IO uint32_t RCC_AHB3RSTR;
	__IO uint32_t Reserved0;
	__IO uint32_t RCC_APB1RSTR;
	__IO uint32_t RCC_APB2RSTR;
	__IO uint32_t Reserved1;
	__IO uint32_t Reserved2;
	__IO uint32_t RCC_AHB1ENR;
	__IO uint32_t RCC_AHB2ENR;
	__IO uint32_t RCC_AHB3ENR;
	__IO uint32_t Reserved3;
	__IO uint32_t RCC_APB1ENR;
	__IO uint32_t RCC_APB2ENR;
	__IO uint32_t Reserved4;
	__IO uint32_t Reserved5;
	__IO uint32_t RCC_AHB1LPENR;
	__IO uint32_t RCC_AHB2LPENR;
	__IO uint32_t RCC_AHB3LPENR;
	__IO uint32_t Reserved6;
	__IO uint32_t RCC_APB1LPENR;
	__IO uint32_t RCC_APB2LPENR;
	__IO uint32_t Reserved7;
	__IO uint32_t Reserved8;
	__IO uint32_t RCC_BDCR;
	__IO uint32_t RCC_CSR;
	__IO uint32_t Reserved9;
	__IO uint32_t Reserved10;
	__IO uint32_t RCC_SSCGR;
	__IO uint32_t RCC_PLLI2SCFGR;
}RCC_offset;

typedef struct
{
	__IO uint32_t GPIO_MODER;
	__IO uint32_t GPIO_OTYPER;
	__IO uint32_t GPIO_OSPEEDR;
	__IO uint32_t GPIO_PUPDR;
	__IO uint32_t GPIO_IDR;
	__IO uint32_t GPIO_ODR;
	__IO uint32_t GPIO_BSRR;
	__IO uint32_t GPIO_LCKR;
	__IO uint32_t GPIO_AFR[2];
}GPIO_offset;

#define RCC 	((RCC_offset *)RCC_Base)
#define GPIOA 	((GPIO_offset *)GPIOA_Base)
#define GPIOB 	((GPIO_offset *)GPIOB_Base)
#define GPIOC 	((GPIO_offset *)GPIOC_Base)
#define GPIOD 	((GPIO_offset *)GPIOD_Base)

#endif /* INC_CUSTOM_GPIO_HAL_H_ */

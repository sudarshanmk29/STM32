/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Sudarshan M K
 * @brief          : Main program body
 ******************************************************************************
 * Program to Turn on all the Internal LED's
 * Port D of the GPIO is internally connected to the on board LED's
 * Port D Pin 12 (PD12)--> Green LED
 * Port D Pin 13 (PD13)--> Orange LED
 * Port D Pin 14 (PD14)--> Red LED
 * Port D Pin 15 (PD15)--> Blue LED
 *
 * Refer the Schematic (19309) for more information
 *
 * 1) In order to turn on the LED's we need to enable the port to which the LED's are connected
 * 2) From the Schematic it is clear that the On board LED's are connected to Port D Pin 12,13,14,15
 * 3) To Enable the Port, we need to Enable the Bus to which the Ports are connected.
 * As per ARM Architecture, all the GPIO's are memory mapped I/O. The ARM processors work
 * in the load-store model. So, in order to move the data, the bus(address and data bus) has to be enabled
 * 4) As per the controller datasheet's Functional Block Diagram, the GPIO Port D is connected to the AHB1 Bus(Advanced High Performance Bus)
 * 5) In order to Enable the AHB Bus, we need to enable the Reset and Control Clock (RCC) AHB1_ENR register for GPIO Port D
 * ** Check the Reference Manual for more details regarding RCC
 *
 * Procedure to work with on-board LED's
 * 1) Enable the RCC AHB1_ENR register for GPIOD
 * 2) Enable the GPIOD_MODER Register for Pins 12, 13, 14, 15
 * 3) Enable the GPIOD_ODR Register for Pins 12, 13, 14, 15
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#include <stdio.h>
#include <stdint.h>

#define RCC_BASE 0x40023800
#define RCC_AHB1ENR_offset 0x30

#define GPIOA_BASE 0x40020000
#define GPIOB_BASE 0x40020400
#define GPIOC_BASE 0x40020800
#define GPIOD_BASE 0x40020C00

#define GPIO_MODER_offset 0x00
#define GPIO_ODR_offset 0x14

int main(void)
{
	//Configure the registers with base address and offset
	volatile uint32_t *RCC_AHB1ENR = (volatile uint32_t *)(RCC_BASE | RCC_AHB1ENR_offset);
	volatile uint32_t *GPIOD_MODER = (volatile uint32_t*)(GPIOD_BASE | GPIO_MODER_offset);
	volatile uint32_t *GPIOD_ODR = (volatile uint32_t*)(GPIOD_BASE | GPIO_ODR_offset);

	//Enable the GPIO Port D
	*RCC_AHB1ENR |=(1<<3);

	//Set the GPIOD_MODER to reset state
	*GPIOD_MODER &= 0x00;

	//Set PD12 to General Purpose Output mode
	*GPIOD_MODER |= (1<<24);
	//Set PD13 to General Purpose Output mode
	*GPIOD_MODER |= (1<<26);
	//Set PD14 to General Purpose Output mode
	*GPIOD_MODER |= (1<<28);
	//Set PD15 to General Purpose Output mode
	*GPIOD_MODER |= (1<<30);

	//Turn ON the Green LED
	*GPIOD_ODR |= (1<<12);
	//Turn ON the Orange LED
	*GPIOD_ODR |= (1<<13);
	//Turn ON the Red LED
	*GPIOD_ODR |= (1<<14);
	//Turn ON the Blue LED
	*GPIOD_ODR |= (1<<15);

	while(1);
}

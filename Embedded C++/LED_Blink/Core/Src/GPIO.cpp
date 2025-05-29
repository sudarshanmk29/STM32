/*
 * GPIO.cpp
 *
 *  Created on: May 29, 2025
 *      Author: MQD1COB
 */

#include "GPIO.h"

GPIO::GPIO():m_GPIO_State(-1) {
	// TODO Auto-generated constructor stub
}

GPIO::~GPIO() {
	// TODO Auto-generated destructor stub
}

void GPIO::GPIO_WritePin(GPIO_offset* GPIO_Port, uint8_t GPIO_PIN, uint8_t state)
{
	if(!GPIO_Port)
		return;
	GPIO_Port->GPIO_ODR &= 0x00;	//Reset the Output data register
	if(state)
		GPIO_Port->GPIO_ODR |= (1 << GPIO_PIN); //Write the Pin to High
	else
		GPIO_Port->GPIO_ODR &= ~(1 << GPIO_PIN); //Write the Pin to Low
}

void GPIO::clock_config(uint8_t pin_no)
{
	RCC->RCC_AHB1ENR = 0x00100000;		//Reset AHB1ENR register
	RCC->RCC_AHB1ENR |= (1 << pin_no);	//Enable the specific port
}

/*Provide the delay in seconds*/
void GPIO::HAL_Delay(uint32_t delay)
{
	uint64_t us_delay = delay * 1000000;
	while(us_delay > 0)
	{
		us_delay--;
	}
}

void GPIO::gpio_config(GPIO_offset* GPIO_Port, uint8_t GPIO_PIN)
{
	GPIO_Port->GPIO_MODER &= 0x00;  //Reset the mode register
	uint8_t gpio_pin = GPIO_PIN * 2;
	GPIO_Port->GPIO_MODER |= (1 << gpio_pin); //Configure the pin as output
}

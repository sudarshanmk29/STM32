/*
 * GPIO.h
 *
 *  Created on: May 29, 2025
 *      Author: MQD1COB
 */

#ifndef SRC_GPIO_H_
#define SRC_GPIO_H_

#include <cstdint>
#ifdef __cplusplus
extern "C" {
#endif
	#include "custom_gpio_hal.h"
#ifdef __cplusplus
}
#endif

#define HAL_MAX_DELAY      0xFFFFFFFFU

class GPIO {
public:
	GPIO();
	virtual ~GPIO();
	void clock_config(uint8_t pin_no);
	void gpio_config(GPIO_offset* GPIO_Port, uint8_t GPIO_PIN);
	void GPIO_WritePin(GPIO_offset* GPIO_Port, uint8_t GPIO_PIN, uint8_t state);
	void HAL_Delay(uint32_t delay);

	typedef enum GPIO_State
	{
		GPIO_RESET = 0,
		GPIO_SET
	}GPIO_State;
private:
	int8_t m_GPIO_State;
};

#endif /* SRC_GPIO_H_ */

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include "GPIO.h"
using namespace std;

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{
	GPIO gpio;
	gpio.clock_config(RCC_GPIOD);
	gpio.gpio_config(GPIOD, GPIO_Pin13);

	while(1)
	{
		gpio.GPIO_WritePin(GPIOD, GPIO_Pin13, gpio.GPIO_SET);
		gpio.HAL_Delay(1);
		gpio.GPIO_WritePin(GPIOD, GPIO_Pin13, gpio.GPIO_RESET);
		gpio.HAL_Delay(1);
	}
	return 0;
}

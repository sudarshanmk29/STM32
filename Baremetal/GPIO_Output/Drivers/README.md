This Drivers package is borrowed from STM32 Website and git repository
STM32 Website: https://www.st.com/en/embedded-software/stm32cubef4.html
STM32 Github repository: https://github.com/STMicroelectronics/STM32CubeF4

Only Fetched the Drivers directory from the repository
For Basic Operations like the GPIO, Timers, UART, USART, ADC, DAC, etc..; only the below folders are required:
			- Drivers\CMSIS\Device\ST\STM32F4xx\Include
			- Drivers\CMSIS\Include

For RTOS projects, we additionally require along with the above folders:
			- Drivers\CMSIS\RTOS2\Include
			- Drivers\CMSIS\RTOS\Template
			
For DSP Projects, we require:
			- Drivers\CMSIS\DSP\Include

for Neural Networks, we require:
			- Drivers\CMSIS\NN\Include

The Board Support Package (BSP) is only required for interfacing with other boards like Adafruit, etc.. They are also included out here for future references only

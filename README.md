# GPIO_LED
An application that controls the hardware of the STM32F411xC in order to control the IOn via the pins of the development board.

The project will consist of the following structure:
- main.c - Mainly responsible for the application's use
- my_stm32f4_gpio_driver.h - Definitions of designations and functions that will be called from the driver itself
- my_stm32f4_gpio_lib.h - Definitions of the hardware we need to communicate with
- my_stm32f4_gpio_lib.c - We apply functionality

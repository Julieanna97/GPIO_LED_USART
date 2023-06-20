#include  "my_stm32f4_gpio_lib.h"
// Includes our custom built library for GPIO at STM32F4x

// Initializes the struct
GPIO_InitTypeDef		myGPIO_InitSruct;

// Main program that starts executing
int main(void){
   // Configures the initialization settings to use pin 5 of GPIOA as an output in Push-Pull mode
   myGPIO_InitSruct.Mode = GPIO_MODE_OUTPUT_PP;
   myGPIO_InitSruct.Pin  = GPIO_PIN_5;
   myGPIO_InitSruct.Pull = GPIO_NOPULL;

   // Enable the clock for PortA
   // We initialize the port with the settings above
   __LIB_RCC_GPIOA_CLK_ENABLE();
	LIB_GPIO_Init(GPIOA, &myGPIO_InitSruct);

	// Forever-loop where we iterate between "high" and "low" state of the pin
	while(1){
	   for(int i = 0; i< 900000; i++){}
		 LIB_GPIO_TogglePin(GPIOA, GPIO_PIN_5);

	}
   
}
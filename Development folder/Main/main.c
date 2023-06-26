// Includes our custom built library for UART at STM32F4x
#include "my_stm32f4_uart_lib.h"


// Main program that starts executing
int main(void)
{

	UART_ComType com = USART_DUPLEX;
	UART_BaudRateType baudRate = UART_BAUDRATE_115200;
	
	/**
	 * @brief We initialize the UART with duplex enabled
	 * and with baud rate 115200
	 */
	__LIB_UART_Init(&com, &baudRate);
	
	// LIB_GPIO_Init(GPIOA, &myGPIO_InitSruct);

	// Write data to UART in a loop
	char data[5] ={'H', 'E', 'L', 'L', 'O'};

	typedef enum
	{
		OFF = 0,
		ON = 1
		
	}UART_StateType;

	UART_StateType state;

	if (state == ON)
	{
		for(state = ON; state != OFF; state++)
		{
			__LIB_UART_Write(data[state]);

			if(data > 'Z')
			{
				break;
			}
		}
	}
	else
	{
		state = OFF;
	}

	return 0;
   
}
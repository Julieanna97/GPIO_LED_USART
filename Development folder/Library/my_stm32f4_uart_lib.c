#include "my_stm32f4_uart_lib.h"

// global variable
/* APB2 peripheral */
USART_RegTypeDef *usart1 = USART1;  // USART1 is used
USART_RegTypeDef *usart6 = USART6;
/* APB1 peripheral */
USART_RegTypeDef *usart2 = USART2;


int __LIB_UART_Write(int ch)
{
    while(!(usart1->SR & (0x0080)));  // Wait until transmit data register is empty
    usart1->DR = (ch & 0xFF);    // write the character to the data register

    return ch;
}


int __LIB_UART_Read(void)
{
    while(!(usart1->SR & (0x0020))); // Wait until read data register is not empty
    return (usart1->DR); // read the next character from the data register

}

// Configure the UART peripheral
void __LIB_UART_Init(UART_ComType *Com, UART_BaudRateType *BaudRate)
{

    // Set the baud rate
    uint32_t baud = (uint32_t)(*BaudRate);
    /* Variable to store the APB clock frequency 
     *(derived from SYSCLCK, e.g., 100 MHz)
     */
    uint32_t apbclock = 0;
    uint32_t usartdiv = 0;

    if (usart1 || usart6)
    {
        // APB2 clock frequency
        apbclock = 100000000;

        // Calculate the USARTDIV value for the desired baud rate
        usartdiv = (apbclock + (baud / 2)) / baud;

    }
    else
    {

        // APB1 clock frequency
        apbclock = 50000000;

        usartdiv = (apbclock + (baud / 2)) / baud;
    }

    usart1->BRR = usartdiv;

    // Enable the UART and other configuration settings
    usart1->CR1 |= 0x2000;  // Enable USART
    usart1->CR1 |= 0x0008;  // Enable transmitter
    usart1->CR1 |= 0x0004;  // Enable receiver


}
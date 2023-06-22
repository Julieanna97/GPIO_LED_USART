#include "my_stm32f4_uart_lib.h"

// global variable
/* APB2 peripheral */
USART_RegTypeDef *usart1 = USART1;  // USART1 is used
USART_RegTypeDef *usart6 = USART6;
/* APB1 peripheral */
USART_RegTypeDef *usart2 = USART2;

#define USART_SR_TXE    0x0080
#define USART_SR_RXNE   0x1U<<5

int __LIB_UART_Write(int ch)
{
    while(!(usart1->SR & USART_SR_TXE));  // Wait until transmit data register is empty
    usart1->DR = (ch & 0xFF);    // write the character to the data register

    return ch;
}

int __LIB_UART_Read(void)
{
    while(!(usart1->SR & USART_SR_RXNE)); // Wait until read data register is not empty
    int ch = usart1->DR; // read the next character from the data register

    return ch;
}

// Configure the USART1 peripheral
void __LIB_UART_Init(UART_ComType *Com, UART_BaudRateType *BaudRate)
{

    // Set the baud rate
    uint32_t baud = (uint32_t)(*BaudRate);
    /* Variable to store the APB clock frequency 
     *(derived from SYSCLCK, e.g., 100 MHz)
     */

    // usart clock frequency
    int apb2clock, apb1clock = 0;

    if (usart1 || usart6)
    {
        apb2clock = 100000000;
        if(baud == UART_BAUDRATE_9600)
        {
            usart1->BRR, usart6->BRR = (apb2clock + (baud / 2)) / baud;
        }
        else if (baud == UART_BAUDRATE_115200)
        {
            usart1->BRR, usart6->BRR = (apb2clock + (baud / 2)) / baud;
        }
    }
    else if (usart2)
    {
        apb1clock = 50000000;
        if(baud == UART_BAUDRATE_9600)
        {
            usart2->BRR = (apb1clock + (baud / 2)) / baud;
        }
        else if (baud == UART_BAUDRATE_115200)
        {
            usart2->BRR = (apb1clock + (baud / 2)) / baud;
        }
    }


    // Enable the UART and other configuration settings
    usart1->CR1 |= 0x2000;  // Enable USART
    usart1->CR1 |= 0x0008;  // Enable transmitter
    usart1->CR1 |= 0x0004;  // Enable receiver


}
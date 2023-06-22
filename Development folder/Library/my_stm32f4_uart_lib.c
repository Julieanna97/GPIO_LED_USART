#include "my_stm32f4_uart_lib.h"

// global variable
/* APB2 peripheral */
USART_RegTypeDef *usart1 = USART1;
USART_RegTypeDef *usart6 = USART6;
/* APB1 peripheral */
USART_RegTypeDef *usart2 = USART2;

#define USART_SR_TXE    0x0080U  // Transmit data register empty
#define USART_SR_RXNE   0x1U<<5  // Read data register not empty
#define USART_EN        0x1U<<13    // Enable UART
#define OVER8           (1U<<15)    // 0 = oversampling by 16

/* UART's flow control modes */
#define IRDA_MODE_EN    0x0002U     // IrDA mode enable
#define SMART_MODE_EN   0x0020U     // Smartcard mode enable
#define RTSE_MODE_EN    0x0100U     // RTS enable
#define CTSE_MODE_EN    0x0200U     // CTS enable
#define USART_STOPBITS  0x00U       // Stop bits reset
#define USART_STOPBITS_2  0x2000U   // 2 stop bits

int __LIB_UART_Write(int ch)
{
    while(!(usart1->SR, usart2->SR, usart6->SR & USART_SR_TXE));  // Wait until transmit data register is empty
    usart1->DR = (ch & 0xFF);    // write the character to the data register

    return ch;
}

int __LIB_UART_Read(void)
{
    while(!(usart1->SR, usart2->SR, usart6->SR & USART_SR_RXNE)); // Wait until read data register is not empty
    int ch = usart1->DR; // read the next character from the data register

    return ch;
}

// Configure the USART1 peripheral
void __LIB_UART_Init(UART_ComType *Com, UART_BaudRateType *BaudRate)
{
    // Enable UART
    usart1->CR1, usart2->CR1, usart6->CR1 |= USART_EN;
    // Enable both transmitter and receiver
    usart1->CR1, usart2->CR1, usart6->CR1 |= USART_MODE_DUPLEX;

    uint32_t baud = (uint32_t)(*BaudRate);
    /* Variable to store the usart clock frequency 
     *(derived from SYSCLCK, e.g., 100 MHz)
     */
    uint32_t apb2clock, apb1clock = 0;
    uint32_t overSampling = 16; // Assuming oversampling of 16 is used
    uint32_t usartdiv = 0;

    // Set baud rate
    if (usart1 || usart6)
    {
        apb2clock = 100000000;
        if(baud == UART_BAUDRATE_9600)
        {
            usartdiv = (apb2clock / (baud * overSampling)) - 1;
            usart1->BRR, usart6->BRR = usartdiv;
        }
        else if (baud == UART_BAUDRATE_115200)
        {
            usartdiv = (apb2clock + (baud / 2)) / baud;
            usart1->BRR, usart6->BRR = usartdiv;
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

    /* Configure flow control */
    usart1->CR3, usart2->CR3, usart6->CR3 |= RTSE_MODE_EN;
    // RTS hardware flow control is used for this example

    /* Configure stop bits */
    // Clear the stop bits field
    usart1->CR2, usart2->CR2, usart6->CR2 &= ~USART_STOPBITS;
    // Set 2 stop bits
    usart1->CR2, usart2->CR2, usart6->CR2 |= USART_STOPBITS_2;


    // Enable/Disable transmitter
    if(*Com == USART_TE || *Com == USART_DUPLEX)
    {
        usart1->CR1, usart2->CR1, usart6->CR1 |= USART_MODE_TX;  // Enable transmitter
    }
    else
    {
        usart1->CR1, usart2->CR1, usart6->CR1 &= ~USART_MODE_TX;  // Disable transmitter
    }

    // Copying value of *Com pointer to a new variable called com
    UART_ComType com = *Com;

    // Enable/Disable receiever
    if(com == USART_RE || com == USART_DUPLEX)
    {
        usart1->CR1, usart2->CR1, usart6->CR1 |= USART_MODE_RX;
    }
    else
    {
        usart1->CR1, usart2->CR1, usart6->CR1 &= ~USART_MODE_RX;
    }


}
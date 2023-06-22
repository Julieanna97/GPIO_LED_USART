#ifndef _MY_STM32F4_UART_LIB_H_
#define _MY_STM32F4_UART_LIB_H_

#include "my_stm32f4_uart_driver.h"

#define USART_MODE_NONE ((uint32_t)0x00U)       // Transmitter and receiver are disabled
#define USART_MODE_TX 0x0008U                    // Transmitter enabled
#define USART_MODE_RX 0x0004U                    // Receiver enabled
#define USART_MODE_DUPLEX (USART_MODE_TX | USART_MODE_RX) // Both transmitter and receiver enabled

typedef enum
{
    USART_NONE = USART_MODE_NONE,
    USART_TE = USART_MODE_TX,
    USART_RE = USART_MODE_RX,
    USART_DUPLEX = USART_MODE_DUPLEX

}UART_ComType;

typedef enum
{
    UART_BAUDRATE_1200 = 1200U,
    UART_BAUDRATE_2400 = 2400U,
    UART_BAUDRATE_4800 = 4800U,
    UART_BAUDRATE_9600 = 9600U,
    UART_BAUDRATE_19200 = 19200U,
    UART_BAUDRATE_38400 = 38400U,
    UART_BAUDRATE_57600 = 57600U,
    UART_BAUDRATE_115200 = 115200U


}UART_BaudRateType;


int __LIB_UART_Write(int ch);
int __LIB_UART_Read(void);
void __LIB_UART_Init(UART_ComType *Com, UART_BaudRateType *BaudRate);


#endif
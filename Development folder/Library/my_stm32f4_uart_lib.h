#ifndef _MY_STM32F4_UART_LIB_H_
#define _MY_STM32F4_UART_LIB_H_

#include "my_stm32f4_uart_driver.h"

/**
 * @brief Defines constants related to UART's
 * corresponding modes and configuration types.
 */

typedef struct
{


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


}UART_BaudrateType;

#endif
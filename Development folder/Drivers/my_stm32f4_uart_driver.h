#ifndef _MY_STM32F4_UART_DRIVER_H_
#define _MY_STM32F4_UART_DRIVER_H_

#include <stdint.h>
#include "my_stm32f4_gpio_driver.h"


#define APB1PERIPH_BASE PERIPH_BASE // Base address for peripheral register APB1
#define APB2PERIPH_BASE 0x40010000U // Base address for peripheral register APB2


#define USART1_BASE (APB2PERIPH_BASE + 0x1000U) // An offset from the APB2 origin leading to USART1
#define USART2_BASE (APB1PERIPH_BASE + 0x4400U) // An offset from the APB1 origin leading to USART2
#define USART6_BASE (APB2PERIPH_BASE + 0x1400U) // An offset from the APB2 origin leading to USART6

#define USART_MODE_NONE ((uint32_t)0x00U)       // Transmitter and receiver are disabled
#define USART_MODE_TX 0x0008U                    // Transmitter enabled
#define USART_MODE_RX 0x0004U                    // Receiver enabled
#define USART_MODE_DUPLEX (USART_MODE_TX | USART_MODE_RX) // Both transmitter and receiver enabled


typedef struct
{
        __IO uint32_t SR;       /* Status register */
        __IO uint32_t DR;       /* Data register */
        __IO uint32_t BRR;      /* Baud rate register */
        __IO uint32_t CR1;      /* Control register */
        __IO uint32_t CR2;
        __IO uint32_t CR3;
        __IO uint32_t GTPR;     /* Guard time and prescaler register */

}USART_RegTypeDef;


#define USART1 ((USART_RegTypeDef *)USART1_BASE);
#define USART2 ((USART_RegTypeDef *)USART2_BASE);
#define USART6 ((USART_RegTypeDef *)USART6_BASE);

#endif
#ifndef _MY_STM32F4_GPIO_LIB_H_
#define _MY_STM32F4_GPIO_LIB_H_

#include "my_stm32f4_gpio_driver.h"

/**
 * @brief Defines constants related to GPIO pins
 * and their corresponding modes and pull configurations.
 */

#define GPIO_PIN_0 ((uint16_t) 0x0001)
#define GPIO_PIN_1 ((uint16_t) 0x0002)
#define GPIO_PIN_2 ((uint16_t) 0x0004)
#define GPIO_PIN_3 ((uint16_t) 0x0008)
#define GPIO_PIN_4 ((uint16_t) 0x0010)
#define GPIO_PIN_5 ((uint16_t) 0x0020)
#define GPIO_PIN_6 ((uint16_t) 0x0040)
#define GPIO_PIN_7 ((uint16_t) 0x0080)
#define GPIO_PIN_8 ((uint16_t) 0x0100)
#define GPIO_PIN_9 ((uint16_t) 0x0200)
#define GPIO_PIN_10 ((uint16_t) 0x0400)
#define GPIO_PIN_11 ((uint16_t) 0x0800)
#define GPIO_PIN_12 ((uint16_t) 0x1000)
#define GPIO_PIN_13 ((uint16_t) 0x2000)
#define GPIO_PIN_14 ((uint16_t) 0x4000)
#define GPIO_PIN_15 ((uint16_t) 0x8000)
#define GPIO_PIN_ALL ((uint16_t) 0xFFFF)


/* Various configuration mode bits to the I/O pins
PP = push-pull
OD = open drain + pull-up/down
AF = alternate function
*/
#define GPIO_MODE_INPUT       0x00U
#define GPIO_MODE_OUTPUT_PP   0x11U
#define GPIO_MODE_OUTPUT_OD   0x01U
#define GPIO_MODE_AF_PP       0x02U
#define GPIO_MODE_AF_OD       0x12U

#define GPIO_NOPULL           0x00U
#define GPIO_PULLUP           0x01U
#define GPIO_PULLDOWN         0x02U

/**
 * @brief Configuration parameters for initializing
 * GPIO pin.
 */
typedef struct
{
    uint32_t Pin;
    uint32_t Mode;
    uint32_t Pull;
    uint32_t Speed;
    uint32_t Alternate;

}GPIO_InitTypeDef;

/**
 * @brief States of the GPIO pin.
 * 
 */
typedef enum
{
    GPIO_PIN_RESET = 0,
    GPIO_PIN_SET = 1

}GPIO_PinState;

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


/* Initalization of GPIO modules*/
void LIB_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init);
GPIO_PinState LIB_GPIO_ReadPinState(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void LIB_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void LIB_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

/**
 * @brief Enable clock signals for the corresponding
 * GPIO ports: A, B, C, D, E, H
 */
void __LIB_RCC_GPIOA_CLK_ENABLE(void);
void __LIB_RCC_GPIOB_CLK_ENABLE(void);
void __LIB_RCC_GPIOC_CLK_ENABLE(void);
void __LIB_RCC_GPIOD_CLK_ENABLE(void);
void __LIB_RCC_GPIOE_CLK_ENABLE(void);
void __LIB_RCC_GPIOH_CLK_ENABLE(void);

#endif
#ifndef _MY_STM32F4_GPIO_DRIVER_H_
#define _MY_STM32F4_GPIO_DRIVER_H_

#include <stdint.h>

#define PERIPH_BASE 0x40000000U // Base address for peripheral work
#define AHB1PERIPH_BASE (PERIPH_BASE + 0x10U) // An offset from the origin leading to the peripheral register AHB1
#define RCC_BASE (PERIPH_BASE + 0x30U) // An offset from the origin leading to the clock-register for the GPIO

#define _IO volatile

typedef struct
{
    _IO uint32_t MODER;
    _IO uint32_t OTYPER;
    _IO uint32_t OSPEEDR;

}GPIO_Typedef;


#endif
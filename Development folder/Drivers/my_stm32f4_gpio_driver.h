#ifndef _MY_STM32F4_GPIO_DRIVER_H_
#define _MY_STM32F4_GPIO_DRIVER_H_

#include <stdint.h>

/**
 * @brief The original state of our piece of communication
 * with the development card 
 */
#define PERIPH_BASE 0x40000000U // Base address for peripheral work
#define AHB1PERIPH_BASE 0x40020000U // Base address for peripheral register AHB1
#define APB1PERIPH_BASE PERIPH_BASE // Base address for peripheral register APB1
#define APB2PERIPH_BASE 0x40010000U // Base address for peripheral register APB2


#define RCC_BASE (AHB1PERIPH_BASE + 0x3800U) // An offset from the origin leading to the clock-register for the GPIO
#define USART1_BASE (APB2PERIPH_BASE + 0x1000U) // An offset from the APB2 origin leading to USART1
#define USART2_BASE (APB1PERIPH_BASE + 0x4400U) // An offset from the APB1 origin leading to USART2
#define USART6_BASE (APB2PERIPH_BASE + 0x1400U) // An offset from the APB2 origin leading to USART6

/**
 * @brief Defines memory addresses for different
 * GPIO ports on the communication bus
 */
#define GPIOA_BASE (AHB1PERIPH_BASE + 0x00U)
#define GPIOB_BASE (AHB1PERIPH_BASE + 0x0400U)
#define GPIOC_BASE (AHB1PERIPH_BASE + 0x0800U)
#define GPIOD_BASE (AHB1PERIPH_BASE + 0x0C00U)
#define GPIOE_BASE (AHB1PERIPH_BASE + 0x1000U)
#define GPIOH_BASE (AHB1PERIPH_BASE + 0x1C00U)

#define __IO volatile  // value may change between different accesses even if it's not modified

/**
 * @brief Structure to the GPIOs.
 * What they consist of and their usage.
 */
typedef struct
{
        /* General purpose I/O reference registers */
        __IO uint32_t MODER;    /* Mode register */
        __IO uint32_t OTYPER;   /* Output type register */
        __IO uint32_t OSPEEDR;  /* Output speed register */
        __IO uint32_t PUPDR;    /* Pull-up/pull-down register */
        __IO uint32_t IDR;      /* Input data register */
        __IO uint32_t ODR;      /* Output data register */
        __IO uint32_t BSRR;     /* Bit set/reset register */
        __IO uint32_t LCKR;     /* Configuration lock register */
        __IO uint32_t AFR[2];   /* Alternate function low/high register */

}GPIO_TypeDef;

typedef struct
{
        /* Reset and clock control reference registers */
        __IO uint32_t CR;           /* Clock control register */
        __IO uint32_t PLLCFGR;      /* PPL configuration register */
        __IO uint32_t CFGR;         /* Clock configuration register */
        __IO uint32_t CIR;          /* Clock interrupt register */
        __IO uint32_t AHB1RSTR;     /* AHB1 peripheral reset register */
        __IO uint32_t AHB2RSTR;   
                uint32_t DUMMY1;    /* fill in variable for configuration bits */
                uint32_t DUMMY2;
        __IO uint32_t APB1RSTR;     /* APB1 peripheral reset register */
        __IO uint32_t APB2RSTR;     
                uint32_t DUMMY3[2];
        __IO uint32_t AHB1ENR;      /* AHB1 peripheral clock enable register */
        __IO uint32_t AHB2ENR;      
                uint32_t DUMMY4[2];
        __IO uint32_t APB1ENR;
        __IO uint32_t APB2ENR;
                uint32_t DUMMY5[2];
        __IO uint32_t AHB1LPENR;    /* AHB1 peripheral clock enable in low power mode register */
        __IO uint32_t AHB2LPENR;
                uint32_t DUMMY6[2];
        __IO uint32_t APB1LPENR;
        __IO uint32_t APB2LPENR;
                uint32_t DUMMY7[2];
        __IO uint32_t BDCR;         /* Backup domain control register */
        __IO uint32_t CSR;          /* Clock control & status register */
                uint32_t DUMMY8[2];
        __IO uint32_t SSCGR;        /* Spread spectrum clock generation register */
        __IO uint32_t PLLI2SCFGR;   /* PLLI2S configuration register */
                uint32_t DUMMY9;
        __IO uint32_t DCKCFGR;      /* Dedicated clocks configuration register */


}RCC_TypeDef;

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


#define RCC ((RCC_TypeDef *)RCC_BASE)

#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE ((GPIO_TypeDef *)GPIOE_BASE)
#define GPIOH ((GPIO_TypeDef *)GPIOH_BASE)

#define GPIOA_EN 1<<0
#define GPIOB_EN 1<<1
#define GPIOC_EN 1<<2
#define GPIOD_EN 1<<3
#define GPIOE_EN 1<<4
#define GPIOH_EN 1<<7

#define MODER_5_OUT 1<<10
#define LED_PIN 1<<5

#define USART1 ((USART_RegTypeDef *)USART1_BASE);
#define USART2 ((USART_RegTypeDef *)USART2_BASE);
#define USART6 ((USART_RegTypeDef *)USART6_BASE);


#endif
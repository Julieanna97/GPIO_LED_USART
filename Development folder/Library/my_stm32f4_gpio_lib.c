// Includes custom library for GPIO control / Driver for GPIO
#include  "my_stm32f4_gpio_lib.h"

// Various configuration bits in the form of constants for the program's functions
#define GPIO_NUMBER							16U
#define	GPIO_MODER_MODE0					0x3U<<0
#define	GPIO_MODE							0x03U
#define	GPIO_PUPDR_PUPDR0					0x3U<<0
#define	GPIO_OSPEEDER_OSPEEDR0				0x3U<<0
#define	GPIO_OTYPER_OT0						0x1U<<0
#define GPIO_OUTPUT_TYPE					0x00010U

// Initializes our GPIO pin based on the specified settings
void LIB_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init){
	
	// The variables that store our temporary values for the initialization
    uint32_t position;
    uint32_t temp =  0x0U;
    uint32_t ioposition = 0x00U;
    uint32_t iocurrent =  0x00U;

	// For-loop that iterates over all our pins, in this case our 16 pins
	for(position = 0U; position < GPIO_NUMBER; position++){
		
		// Calculates the current position and compares whether you are on the pin to be activated/initiated
		ioposition = 0x01U << position;
		iocurrent =  (uint32_t)(GPIO_Init->Pin)&ioposition;
		
		// Check if the pin should be activated
		if(iocurrent == ioposition){
			
			// Checks which function the pin should be activated with
			// if selected pin mode is push-pull or open drain
			if((GPIO_Init->Mode == GPIO_MODE_AF_PP) || (GPIO_Init->Mode == GPIO_MODE_AF_OD)){
				
				/* Updates the register with our variables to
				 * configure the bits in the AFR register
				 */
				temp = GPIOx->AFR[position >>3U];
				// First deactivate afr
		 		temp &= ~(0xFU <<((uint32_t)(position & 0x07U) * 4U));
		 		// Secondly enable AFR
				temp |= ((uint32_t)(GPIO_Init->Alternate) << (((uint32_t)position & 0x07U)*4U)); 
		 		GPIOx->AFR[position >>3U] =  temp;
		
		}

		// Configuring the MODE register for our pin
		temp = GPIOx->MODER;
		temp &= ~(GPIO_MODER_MODE0 <<(position * 2U));
		temp |= (GPIO_Init->Mode & GPIO_MODE) <<(position *2U);
		GPIOx->MODER = temp;
			
		// Configure the register for output type
		if((GPIO_Init->Mode == GPIO_MODE_OUTPUT_PP) || (GPIO_Init->Mode== GPIO_MODE_OUTPUT_OD) ||
		(GPIO_Init->Mode == GPIO_MODE_AF_PP) || (GPIO_Init->Mode== GPIO_MODE_AF_OD)){
			
			// We configure the speed using the OSPEED register
			temp = GPIOx->OSPEEDR;
			temp &= ~(GPIO_OSPEEDER_OSPEEDR0 << (position * 2U));
			temp |= (GPIO_Init->Speed <<(position *2U));
			GPIOx->OSPEEDR =temp;
					
			temp =  GPIOx->OTYPER;
			temp &= ~(GPIO_OTYPER_OT0 << (position * 2U));
			temp |= (((GPIO_Init->Mode & GPIO_OUTPUT_TYPE)>> 4U) <<(position * 2U));
			GPIOx->OTYPER =  temp;
		}

		// Configure the PU/PD mode
		temp = GPIOx->PUPDR;
		temp &= ~(GPIO_PUPDR_PUPDR0 <<(position * 2U));
		temp |= ((GPIO_Init->Pull) << (position *2U));
		GPIOx->PUPDR = temp;
			
			
		
		}
	 

	}
	
}

// Read the return for a given pin and render it
GPIO_PinState LIB_GPIO_ReadPinState(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	GPIO_PinState bitstatus;
	if((GPIOx->IDR & GPIO_Pin) != (uint32_t)GPIO_PIN_RESET){
		
		bitstatus = GPIO_PIN_SET;
	}
	else{
		bitstatus = GPIO_PIN_RESET;
	}
	
	return bitstatus;
}

// Write a new status to the specified pin
void LIB_GPIO_WritePin(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin,GPIO_PinState PinState)
{
	if(PinState != GPIO_PIN_RESET){
	  GPIOx->BSRR = GPIO_Pin;
	}
	
	else{
	   GPIOx->BSRR = (uint32_t)GPIO_Pin <<16;
	}
}

// We toggle the status of the selected pin
void LIB_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){

	 GPIOx->ODR ^= GPIO_Pin;
}

// Enables the clock for all ports
void __LIB_RCC_GPIOA_CLK_ENABLE(void){  RCC->AHB1ENR |= GPIOA_EN;}
void __LIB_RCC_GPIOB_CLK_ENABLE(void){  RCC->AHB1ENR |= GPIOB_EN;}
void __LIB_RCC_GPIOC_CLK_ENABLE(void){  RCC->AHB1ENR |= GPIOC_EN;}
void __LIB_RCC_GPIOD_CLK_ENABLE(void){  RCC->AHB1ENR |= GPIOD_EN;}
void __LIB_RCC_GPIOE_CLK_ENABLE(void){  RCC->AHB1ENR |= GPIOE_EN;}
void __LIB_RCC_GPIOH_CLK_ENABLE(void){  RCC->AHB1ENR |= GPIOH_EN;}

#include "stm32f4_gpio.h"

// Khoi tao xung clock va ngoai vi GPIO
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EN_or_DIS) // Cau hinh xung clock cho ngoai vi
{
	if(EN_or_DIS == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}else if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_EN();
		}
	}else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DIS();
		}else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DIS();
		}else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DIS();
		}else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DIS();
		}else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DIS();
		}else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_DIS();
		}else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_DIS();
		}else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DIS();
		}else if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_DIS();
		}
	}
}

void GPIO_Init(GPIO_Handle_t *pGPIO_Handle)
{
	// enable the peripheral clock
	GPIO_PeriClockControl(pGPIO_Handle->pGPIOx, ENABLE);
	
	uint32_t temp = 0;
	
	// 1. configure the mode of gpio pin
	if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		temp = ( pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode << (2*pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber) );
		pGPIO_Handle->pGPIOx->MODER &= ~(0x3 << (2*pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber) );  // reset
		pGPIO_Handle->pGPIOx->MODER |= temp; // set
	}else
	{
		// interrupt mode
		
	}
	
	// 2. configure the speed
	temp = ( pGPIO_Handle->GPIO_PinConfig.GPIO_PinSpeed << (2*pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber) );
	pGPIO_Handle->pGPIOx->OSPEEDR &= ~(0x3 << (2*pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber) );  // reset
	pGPIO_Handle->pGPIOx->OSPEEDR |= temp; // set
	
	// 3. configure the pupd settings
	temp = ( pGPIO_Handle->GPIO_PinConfig.GPIO_PinPuPdControl << (2*pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber) );
	pGPIO_Handle->pGPIOx->PUPDR &= ~(0x3 << (2*pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber) );  // reset
	pGPIO_Handle->pGPIOx->PUPDR |= temp; // set
	
	// 4. configure the otype
	temp = ( pGPIO_Handle->GPIO_PinConfig.GPIO_PinOType << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber );
	pGPIO_Handle->pGPIOx->OTYPER &= ~(0x1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);  // reset
	pGPIO_Handle->pGPIOx->OTYPER |= temp; // set
	
	
	// 5. configure the alt functionality
	if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFUNC)
	{
		uint8_t temp1, temp2;
		temp1 = pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber / 8; // Thanh ghi AFR cao / thap
		temp2 = pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber % 8; // PinNumber tren moi thanh ghi AFR
		
		pGPIO_Handle->pGPIOx->AFR[temp1] &= ~(0xF << (4*temp2));
		pGPIO_Handle->pGPIOx->AFR[temp1] |= (pGPIO_Handle->GPIO_PinConfig.GPIO_PinAltFuncMode << (4*temp2));
	}
	
}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	}else if(pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	}else if(pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();
	}else if(pGPIOx == GPIOD)
	{
		GPIOD_REG_RESET();
	}else if(pGPIOx == GPIOE)
	{
		GPIOE_REG_RESET();
	}else if(pGPIOx == GPIOF)
	{
		GPIOF_REG_RESET();
	}else if(pGPIOx == GPIOG)
	{
		GPIOG_REG_RESET();
	}else if(pGPIOx == GPIOH)
	{
		GPIOH_REG_RESET();
	}else if(pGPIOx == GPIOI)
	{
		GPIOI_REG_RESET();
	}
}

// Cac chuc nang GPIO
uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001); // (pGPIOx->IDR & (0x01 << PinNumber)) >> PinNumber
	return value;
}

uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)(pGPIOx->IDR);
	return value;
}
void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= (0x1 << PinNumber);
	}else if(Value == GPIO_PIN_RESET)
	{
		pGPIOx->ODR &= ~(0x1 << PinNumber);
	}
}
void GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (0x1 << PinNumber);
}

// Chuc nang ngat ngoai EXTI GPIO
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EN_or_DIS);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);

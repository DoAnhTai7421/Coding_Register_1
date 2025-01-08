#ifndef INC_STM32F4_GPIO_H_
#define INC_STM32F4_GPIO_H_

#include "stm32f4.h"

#define GPIO_PIN_NO_0  0
#define GPIO_PIN_NO_1  1
#define GPIO_PIN_NO_2  2
#define GPIO_PIN_NO_3  3
#define GPIO_PIN_NO_4  4
#define GPIO_PIN_NO_5  5
#define GPIO_PIN_NO_6  6
#define GPIO_PIN_NO_7  7
#define GPIO_PIN_NO_8  8
#define GPIO_PIN_NO_9  9
#define GPIO_PIN_NO_10 10
#define GPIO_PIN_NO_11 11
#define GPIO_PIN_NO_12 12
#define GPIO_PIN_NO_13 13
#define GPIO_PIN_NO_14 14
#define GPIO_PIN_NO_15 15

// Define Mode
#define GPIO_MODE_INPUT 	0
#define GPIO_MODE_OUTPUT 	1
#define GPIO_MODE_ALTFUNC 2
#define GPIO_MODE_ANALOG 	3

/*
 * Chua hieu ro tai sap gia tri MODE_IT la 4-5-6
 */
#define GPIO_MODE_IT_FALLING 4  // Falling
#define GPIO_MODE_IT_RISING  5  // Rising
#define GPIO_MODE_IT_ALL 		 6  // Falling + Rising

// Define Output Type
#define GPIO_OUTPUT_TYPE_PP 0 // Push-Pull
#define GPIO_OUTPUT_TYPE_OD 1 // Open-Drain

// Define Speed
#define GPIO_SPEED_LOW 		0
#define GPIO_SPEED_MEDIUM 1
#define GPIO_SPEED_FAST 	2
#define GPIO_SPEED_HIGH 	3

// Define Pull-up Pull-down
#define GPIO_NO_PUPD  0  // No
#define GPIO_PIN_PU 	1  // Pull-up
#define GPIO_PIN_PD 	2  // Pull-down


typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOType;
	uint8_t GPIO_PinAltFuncMode;
}GPIO_PinConfig_t;

typedef struct
{
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;

// Khoi tao xung clock va ngoai vi GPIO
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EN_or_DIS); // Cau hinh xung clock cho ngoai vi
void GPIO_Init(GPIO_Handle_t *pGPIO_Handle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

// Cac chuc nang GPIO
uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

// Chuc nang ngat ngoai EXTI GPIO
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EN_or_DIS);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);


#endif  /* INC_STM32F4_GPIO_H_ */

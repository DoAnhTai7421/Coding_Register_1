#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h> /* hoac co the dung #include "stm32f4xx.h" */

// Buoc 1: Dinh nghia bo nho base
#define FLASH_BASEADDR 0x08000000U
#define SRAM1_BASEADDR 0x20000000U
#define SRAM2_BASEADDR 0x2001C000U
#define ROM_BASEADDR 0x1FFF0000U
#define SRAM SRAM1_BASEADDR

// Buoc 2: Dinh nghia ngoai vi base
#define PERIPH_BASEADDR 0x40000000U
#define APB1PERIPH_BASEADDR PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR 0x40010000U
#define AHB1PERIPH_BASEADDR 0x40020000U
#define AHB2PERIPH_BASEADDR 0x50000000U

// Buoc 3: Dinh nghia Port GPIO + RCC (AHB1)
#define GPIOA_BASEADDR (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR (AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR (AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR (AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR (AHB1PERIPH_BASEADDR + 0x2000)
// #define GPIOJ_BASEADDR (AHB1PERIPH_BASEADDR + 0x2400)
// #define GPIOK_BASEADDR (AHB1PERIPH_BASEADDR + 0x2800)

#define RCC_BASEADDR (AHB1PERIPH_BASEADDR + 0x3800)

// Buoc 4: Dinh nghia Ngoai vi I2C + SPI + UART/USART (APB1)
#define I2C1_BASEADDR (APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR (APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR (APB1PERIPH_BASEADDR + 0x5C00)

#define SPI2_BASEADDR (APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR (APB1PERIPH_BASEADDR + 0x3C00)

#define USART2_BASEADDR (APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR (APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR (APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR (APB1PERIPH_BASEADDR + 0x5000)

// Buoc 5: Dinh nghia APB2
#define EXTI_BASEADDR (APB2PERIPH_BASEADDR + 0x3C00)
#define SPI1_BASEADDR (APB2PERIPH_BASEADDR + 0x3000)
#define SYSCFG_BASEADDR (APB2PERIPH_BASEADDR + 0x3800)
#define USART1_BASEADDR (APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR (APB2PERIPH_BASEADDR + 0x1400)

// Buoc 6: Dinh nghia struct thanh ghi GPIO
typedef struct
{
	volatile uint32_t MODER;    /* Address offset: 0x00 */
	volatile uint32_t OTYPER;   /* Address offset: 0x04 */
	volatile uint32_t OSPEEDR;  /* Address offset: 0x08 */
	volatile uint32_t PUPDR;    /* Address offset: 0x0C */
	volatile uint32_t IDR;      /* Address offset: 0x10 */
	volatile uint32_t ODR;      /* Address offset: 0x14 */
	volatile uint32_t BSRR;     /* Address offset: 0x18 */
	volatile uint32_t LCKR;     /* Address offset: 0x1C */
	volatile uint32_t AFR[2];   /* Address offset: 0x20, 0x24 */
}GPIO_RegDef_t;

// Buoc 7: Khoi tao thanh ghi GPIO
	/* Xoa cac dinh nghia GPIOx trong cac file khac*/
#undef GPIOA
#undef GPIOB
#undef GPIOC
#undef GPIOD
#undef GPIOE
#undef GPIOF
#undef GPIOG
#undef GPIOH
#undef GPIOI
// #undef GPIOJ
// #undef GPIOK

#define GPIOA ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH ((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI ((GPIO_RegDef_t*)GPIOI_BASEADDR)
// #define GPIOJ ((GPIO_RegDef_t*)GPIOJ_BASEADDR)
// #define GPIOK ((GPIO_RegDef_t*)GPIOK_BASEADDR)

// Buoc 8:  Khoi tao struct thanh ghi RCC + khoi tao
typedef struct
{
	volatile uint32_t RC;          /* Address offset: 0x00 */
	volatile uint32_t PLLCFGR;     /* Address offset: 0x04 */
	volatile uint32_t CFGR;        /* Address offset: 0x08 */
	volatile uint32_t CIR;         /* Address offset: 0x0C */
	volatile uint32_t AHB1RSTR;    /* Address offset: 0x10 */
	volatile uint32_t AHB2RSTR;    /* Address offset: 0x14 */
	volatile uint32_t AHB3RSTR;    /* Address offset: 0x18 */
	uint32_t Reserved_0;               /* Reserved: 0x1C */
	volatile uint32_t APB1RSTR;    /* Address offset: 0x20 */
	volatile uint32_t APB2RSTR;    /* Address offset: 0x24 */
	uint32_t Reserved_1[2];            /* Reserved: 0x28, 0x2C */
	volatile uint32_t AHB1ENR;     /* Address offset: 0x30 */
	volatile uint32_t AHB2ENR;     /* Address offset: 0x34 */
	volatile uint32_t AHB3ENR;     /* Address offset: 0x38 */
	uint32_t Reserved_2;               /* Reserved: 0x3C */
	volatile uint32_t APB1ENR;     /* Address offset: 0x40 */
	volatile uint32_t APB2ENR;     /* Address offset: 0x44 */
	uint32_t Reserved_3[2];            /* Reserved: 0x48, 0x4C */
	volatile uint32_t AHB1LPENR;   /* Address offset: 0x50 */
	volatile uint32_t AHB2LPENR;   /* Address offset: 0x54 */
	volatile uint32_t AHB3LPENR;   /* Address offset: 0x58 */
	uint32_t Reserved_4;               /* Reserved: 0x5C */
	volatile uint32_t APB1LPENR;   /* Address offset: 0x60 */
	volatile uint32_t APB2LPENR;   /* Address offset: 0x64 */
	uint32_t Reserved_5[2];            /* Reserved: 0x68, 0x6C */
	volatile uint32_t BDCR;        /* Address offset: 0x70 */
	volatile uint32_t CSR;         /* Address offset: 0x74 */
	uint32_t Reserved_6[2];            /* Reserved: 0x78, 0x7C */
	volatile uint32_t SSCGR;       /* Address offset: 0x80 */
	volatile uint32_t PLLI2SCFGR;  /* Address offset: 0x84 */
}RCC_RegDef_t;

#undef RCC
#define RCC ((RCC_RegDef_t *)RCC_BASEADDR)

// Buoc 9: Dinh nghia struct va khoi tao thanh ghi Ngat ngoai EXTI
typedef struct
{
	volatile uint32_t IMR;    /* Address offset: 0x00 */
	volatile uint32_t EMR;    /* Address offset: 0x04 */
	volatile uint32_t RTSR;   /* Address offset: 0x08 */
	volatile uint32_t FTSR;   /* Address offset: 0x0C */
	volatile uint32_t SWIER;  /* Address offset: 0x10 */
	volatile uint32_t PR;     /* Address offset: 0x14 */
}EXTI_RegDef_t;

#undef EXTI
#define EXTI ((EXTI_RegDef_t*)EXTI_BASEADDR)

// Buoc 10: Dinh nghia struct va khoi tao thanh ghi SPI
typedef struct
{
	volatile uint32_t CR1;       /* Address offset: 0x00 */
	volatile uint32_t CR2;       /* Address offset: 0x04 */
	volatile uint32_t SR;        /* Address offset: 0x08 */
	volatile uint32_t DR;        /* Address offset: 0x0C */
	volatile uint32_t CRCPR;     /* Address offset: 0x10 */
	volatile uint32_t RXCRCR;    /* Address offset: 0x14 */
	volatile uint32_t TXCRCR;    /* Address offset: 0x18 */
	volatile uint32_t I2SCFGR;   /* Address offset: 0x1C */
	volatile uint32_t I2SPR;     /* Address offset: 0x20 */
}SPI_RegDef_t;

#undef SPI1
#undef SPI2
#undef SPI3

#define SPI1 ((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2 ((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3 ((SPI_RegDef_t*)SPI3_BASEADDR)

// Buoc 11: Dinh nghia struct va khoi tao thanh ghi SYSCFG
typedef struct
{
	volatile uint32_t MEMRMP;       /* Address offset: 0x00 */
	volatile uint32_t PMC;       		/* Address offset: 0x04 */
	volatile uint32_t EXTICR1;      /* Address offset: 0x08 */
	volatile uint32_t EXTICR2;      /* Address offset: 0x0C */
	volatile uint32_t EXTICR3;      /* Address offset: 0x10 */
	volatile uint32_t EXTICR4;    	/* Address offset: 0x14 */
	uint32_t Reserved[2];						    /* Reserved: 0x18, 0x1C */
	volatile uint32_t CMPCR;    		/* Address offset: 0x20 */
}SYSCFG_RegDef_t;

#undef SYSCFG
#define SYSCFG ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

// Buoc 12: Dinh nghia struct va khoi tao thanh ghi I2C
typedef struct
{
	volatile uint32_t CR1;       /* Address offset: 0x00 */
	volatile uint32_t CR2;       /* Address offset: 0x04 */
	volatile uint32_t OAR1;      /* Address offset: 0x08 */
	volatile uint32_t OAR2;      /* Address offset: 0x0C */
	volatile uint32_t DR;        /* Address offset: 0x10 */
	volatile uint32_t SR1;    	 /* Address offset: 0x14 */
	volatile uint32_t SR2;       /* Address offset: 0x18 */
	volatile uint32_t CCR;   		 /* Address offset: 0x1C */
	volatile uint32_t TRISE;     /* Address offset: 0x20 */
	volatile uint32_t FLTR;      /* Address offset: 0x24 */
}I2C_RegDef_t;

#undef I2C1
#undef I2C2
#undef I2C3

#define I2C1 ((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2 ((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3 ((I2C_RegDef_t*)I2C3_BASEADDR)

// Buoc 13: Dinh nghia struct va khoi tao thanh ghi UART, USART
typedef struct
{
	volatile uint32_t SR;       /* Address offset: 0x00 */
	volatile uint32_t DR;       /* Address offset: 0x04 */
	volatile uint32_t BRR;        /* Address offset: 0x08 */
	volatile uint32_t CR1;        /* Address offset: 0x0C */
	volatile uint32_t CR2;     /* Address offset: 0x10 */
	volatile uint32_t CR3;    /* Address offset: 0x14 */
	volatile uint32_t GTPR;    /* Address offset: 0x18 */
}USART_RegDef_t;

#undef USART1
#undef USART2
#undef USART3
#undef UART4
#undef UART5
#undef USART6

#define USART1 ((I2C_RegDef_t*)USART1_BASEADDR)
#define USART2 ((I2C_RegDef_t*)USART2_BASEADDR)
#define USART3 ((I2C_RegDef_t*)USART3_BASEADDR)
#define UART4 ((I2C_RegDef_t*)UART4_BASEADDR)
#define UART5 ((I2C_RegDef_t*)UART5_BASEADDR)
#define USART6 ((I2C_RegDef_t*)USART6_BASEADDR)

// Buoc 14: Kich hoat (Enable) cac thanh ghi RCC cho cac ngoai vi
/*
 * Clock Enable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_EN() (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN() (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN() (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN() (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN() (RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN() (RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN() (RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN() (RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN() (RCC->AHB1ENR |= (1 << 8))

/*
 * Clock Enable Macros for I2Cx peripherals
 */
#define I2C1_PCLK_EN() (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN() (RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN() (RCC->APB1ENR |= (1 << 23))

/*
 * Clock Enable Macros for SPIx peripherals
 */
#define SPI1_PCLK_EN() (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN() (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN() (RCC->APB1ENR |= (1 << 15))

/*
 * Clock Enable Macros for USARTx, UARTx peripherals
 */
#define USART1_PCLK_EN() (RCC->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN() (RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN() (RCC->APB1ENR |= (1 << 18))
#define UART4_PCLK_EN() (RCC->APB1ENR |= (1 << 19))
#define UART5_PCLK_EN() (RCC->APB1ENR |= (1 << 20))
#define USART6_PCLK_EN() (RCC->APB2ENR |= (1 << 5))

/*
 * Clock Enable Macros for SYSCFG peripherals
 */
#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1 << 14))

// Buoc 15: Vo hieu hoa (Disable) cac thanh ghi RCC cho cac ngoai vi
/*
 * Clock Disable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_PCLK_DIS() (RCC->AHB1ENR &= ~(1 << 8))

/*
 * Clock Disable Macros for I2Cx peripherals
 */
#define I2C1_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 23))

/*
 * Clock Disable Macros for SPIx peripherals
 */
#define SPI1_PCLK_DIS() (RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 15))

/*
 * Clock Disable Macros for USARTx, UARTx peripherals
 */
#define USART1_PCLK_DIS() (RCC->APB2ENR &= ~(1 << 4))
#define USART2_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 17))
#define USART3_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 18))
#define UART4_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 19))
#define UART5_PCLK_DIS() (RCC->APB1ENR &= ~(1 << 20))
#define USART6_PCLK_DIS() (RCC->APB2ENR &= ~(1 << 5))

/*
 * Clock Disable Macros for SYSCFG peripherals
 */
#define SYSCFG_PCLK_DIS() (RCC->APB2ENR &= ~(1 << 14))

// Buoc 16: Reset thanh ghi GPIO
#define GPIOA_REG_RESET() do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); } while(0)
#define GPIOB_REG_RESET() do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); } while(0)
#define GPIOC_REG_RESET() do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); } while(0)
#define GPIOD_REG_RESET() do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); } while(0)
#define GPIOE_REG_RESET() do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); } while(0)
#define GPIOF_REG_RESET() do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); } while(0)
#define GPIOG_REG_RESET() do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); } while(0)
#define GPIOH_REG_RESET() do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); } while(0)
#define GPIOI_REG_RESET() do{ (RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8)); } while(0)
#define GPIOJ_REG_RESET() do{ (RCC->AHB1RSTR |= (1 << 9)); (RCC->AHB1RSTR &= ~(1 << 9)); } while(0)
#define GPIOK_REG_RESET() do{ (RCC->AHB1RSTR |= (1 << 10)); (RCC->AHB1RSTR &= ~(1 << 10)); } while(0)

#define ENABLE 1
#define DISABLE 0
#define SET ENABLE
#define RESET DISABLE
#define GPIO_PIN_SET SET
#define GPIO_PIN_RESET RESET
#define FLAG_SET SET
#define FLAG_RESET RESET



#endif /* INC_STM32F407XX_H_ */

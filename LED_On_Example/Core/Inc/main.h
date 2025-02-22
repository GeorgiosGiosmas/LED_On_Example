/*
 * main.h
 *
 *  Created on: Sep 12, 2024
 *      Author: gegio
 */

#ifndef INC_MAIN_H_
#define INC_MAIN_H_

#include "stm32f4xx_hal.h"

/* ====== Program flow =======
 *
 * Στο main.c γίνεται high level initialization του περιφερειακου δηλαδή
 * καλειται η custom UART_Init(), SPI_Init() και λοιπά.
 *
 * Στο msp.c έχουμε low level initialization πχ setting IRQ number, τιμες στους registers
 * και καθορισμός των pins που θα χρησιμοποιηθούν. Πχ Uart_Msp_Init(), SPI_Msp_Init()
 * και λοιπά.
 */

/* ============ Header Files ==============
 *
 *   #include "stm32f4xx.h ==> This is for MCU family
 *
 *   #include "stm32f407xx.h ==> This is for the MCU. It describes the microcontroller, its IRQ
 *   							 definitions, memory map, register details, peripheral clock
 *   							 management macros and others.
 *
 *	 #include "stm32f4xx_hal.h ==> This is for Cube HAL. For the SDK.
 *	 							( WE INCLUDE ONLY THIS FILE )
 */

/*
 *	@brief	This is a custom enumeration for the return status
 */

// If no PLL clock available set this to 1.
#define NO_PLL	( 1 )

typedef enum
{
	Execution_Succesfull 	= 0,
	Execution_Failed 		= 1
} ReturnStatus;

/*
 * @brief This is the enumeration type for the supported clocks.
 */
typedef enum
{
	HSI_16	=	0,
	HSI_8	=	1,
	HSE_4	=	2,
	HSE_2	=	3,
	PLL_84	=	4,
	PLL_42	=	5,
} Clock_Source_t;

/*
 * @brief This function sets the appropriate clock source for our circuit.
 */
uint8_t SystemClock_Config(Clock_Source_t clk);

/*
 * @brief This function configures the appriopriate GPIO pins as LED outputs.
 */
uint8_t GPIO_Set(GPIO_TypeDef *gpio);

/*
 * @brief This function configures the basic Timer which is used for blinking the LEDS.
 */
uint8_t Timer_Configuration(void);

/*
 * @brief This function configures the USART3 peripheral.
 */
uint8_t USART3_Configuration(void);

/*
 * @brief This function chooses the blinking pattern .
 */
void Choose_Pattern(void);

/*
 * @brief This a custom IRQ handler for TIMER's 6 IRQ handler  @ref TIM6_DAC_IRQHandler.
 */
void TIMER6_IRQ_Handler(void);

/*
 * @brief This function sets up the button.
 */
uint8_t Button_Configuration(void);

#endif /* INC_MAIN_H_ */

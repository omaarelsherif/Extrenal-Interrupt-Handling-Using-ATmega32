/*
*    EXTI_Program.c
*    Name : Omar Elsherif
*    Version: 1.0
*    Date: 12-9-2023
*    Desc: Code file contains the code for External interrupt driver 
*/

// Include header files
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "DIO_Interface.h"
#include "EXTI_Register.h"
#include "EXTI_Config.h"

// Function to initialize the external interrupt
void EXTI_VoidInit()
{
	// Clear interrupts flags
	//GICR |= (1 << INTF0) | (1 << INTF1) | (1 << INTF2);

	// INT0
	if(INT_NUM == INT0_NUM && INT0_EN == ENABLE)
	{
		// Switch over ISC mode
		switch(ISC_MODE)
		{
			// Low level
			case LOW_LEVEL:
				CLR_BIT(MCUCR, ISC00);
				CLR_BIT(MCUCR, ISC01);
				break;
			// Any logical change
			case OCH:
				SET_BIT(MCUCR, ISC00);
				CLR_BIT(MCUCR, ISC01);
				break;
			// Falling edge
			case FALLING:
				CLR_BIT(MCUCR, ISC00);
				SET_BIT(MCUCR, ISC01);
				break;
			// Raising edge
			case RAISING:
				SET_BIT(MCUCR, ISC00);
				SET_BIT(MCUCR, ISC01);
				break;
		}

		// Enable the interrupt
		SET_BIT(GICR, INT0);
	}

	// INT1
	if(INT_NUM == INT1_NUM && INT1_EN == ENABLE)
	{
		// Switch over ISC mode
		switch(ISC_MODE)
		{
			// Low level
			case LOW_LEVEL:
				CLR_BIT(MCUCR, ISC10);
				CLR_BIT(MCUCR, ISC11);
				break;
			// Any logical change
			case OCH:
				SET_BIT(MCUCR, ISC10);
				CLR_BIT(MCUCR, ISC11);
				break;
			// Falling edge
			case FALLING:
				CLR_BIT(MCUCR, ISC10);
				SET_BIT(MCUCR, ISC11);
				break;
			// Raising edge
			case RAISING:
				SET_BIT(MCUCR, ISC10);
				SET_BIT(MCUCR, ISC11);
				break;
		}

		// Enable the interrupt
		SET_BIT(GICR, INT1);
	}

	// INT2
	if(INT_NUM == INT2_NUM && INT2_EN == ENABLE)
	{
		// Switch over ISC mode
		switch(ISC_MODE)
		{
			// Falling edge
			case FALLING:
				CLR_BIT(MCUCSR, ISC2);
				break;
			// Raising edge
			case RAISING:
				SET_BIT(MCUCSR, ISC2);
				break;
		}

		// Enable the interrupt
		SET_BIT(GICR, INT2);
	}
}

// Function to enable General Interrupt Enable (GIE)
void EXTI_VoidEnableGIE(void)
{
	// Enable GIE
	SET_BIT(SREG, PIN7);
}

// Function to disable General Interrupt Enable (GIE)
void EXTI_VoidDisableGIE(void)
{
	// Disable GIE
	CLR_BIT(SREG, PIN7);
}

// INT0 ISR
void __vector_1(void)
{
    // INT Body
    DIO_VoidSetPinValue(PORT_C, PIN0, HIGH);
}

// INT1 ISR
void __vector_2(void)
{
    // INT Body
    DIO_VoidSetPinValue(PORT_C, PIN0, HIGH);
}

// INT2 ISR
void __vector_3(void)
{
    // INT Body
    DIO_VoidSetPinValue(PORT_C, PIN0, HIGH);
}

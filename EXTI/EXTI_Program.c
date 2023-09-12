/*
*    EXTI_Program.c
*    Name : Omar Elsherif
*    Version: 1.0
*    Date: 12-9-2023
*    Desc: Code file contains the code for External interrupt driver 
*/

// Include header files
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_Register.h"
#include "EXTI_Config.h"
#include "DIO_Interface.h"

// Function to initialize the external interrupt
void EXTI_VoidInit(void)
{
	switch(ISC_MODE)
	{
		case LOW_LEVEL:
			CLR_BIT(MCUCR, ISC00);
			CLR_BIT(MCUCR, ISC01);
			break;
		case OCH:
			SET_BIT(MCUCR, ISC00);
			CLR_BIT(MCUCR, ISC01);
			break;
		case FALLING:
			CLR_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			break;
		case RAISING:
			SET_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			break;
	}
    
    // Enable INT0
	#if INT0_EN == ENABLE
		SET_BIT(GICR, 6);
	#elif INT0_EN == DISABLE
		CLR_BIT(GICR, 6);
	#endif
}

// Function to enable General Interrupt Enable (GIE)
void EXTI_VoidEnableGIE(void)
{
	// Enable GIE
	SET_BIT(SREG, 7);
}

// Function to disable General Interrupt Enable (GIE)
void EXTI_VoidDisableGIE(void)
{
	// Enable GIE
	CLR_BIT(SREG, 7);
}

// INT0 ISR
void __vector_1(void)
{
    // INT Body
    DIO_VoidSetPinValue(2, 0, 1);
}



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
	CLR_BIT(SREG, PIN7);
}

// INT0 ISR
void __vector_1(void)
{
    // INT Body
    DIO_VoidSetPinValue(PORT_C, PIN0, HIGH);
}



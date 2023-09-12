/*
 * EXTI
 * Author: OmarElsherif
 */

// Include drivers
#include "DIO_Interface.h"
#include "EXTI_Interface.h"

// Main function
void main(void)
{
	// Enable GIE (Globale Interrupt Enable)
	EXTI_VoidEnableGIE();

	// Initialize external enterrupt (EXTI)
	EXTI_VoidInit();

	// Set INT0 pin as input and activate internal pull up resistance for INT0 at portd pin2
	DIO_VoidSetPinDirection(3, 2, 0);
	DIO_VoidSetPinValue(3, 2, 1);

	// Set DDR fro pin0 of portc as output to target a led
	DIO_VoidSetPinDirection(2, 0, 1);

	// Program loop
	while(1)
	{

	}
}

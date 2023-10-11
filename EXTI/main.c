/*
 * EXTI
 * Author: OmarElsherif
 */

// Include drivers
#include "MCAL/DIO_Config.h"
#include "MCAL/DIO_Interface.h"
#include "MCAL/EXTI_Config.h"
#include "MCAL/EXTI_Interface.h"

// Main function
void main(void)
{
	// Enable GIE (Globale Interrupt Enable)
	EXTI_VoidEnableGIE();

	// Initialize external enterrupt (EXTI)
	EXTI_VoidInit();

	// Set INT0 pin as input and activate internal pull up resistance
	DIO_VoidSetPinDirection(PORT_D, PIN2, INPUT);
	DIO_VoidSetPinValue(PORT_D, PIN2, HIGH);

	// Set direction for portc pin0 as output to target a led
	DIO_VoidSetPinDirection(PORT_C, PIN0, OUTPUT);

	// Program loop
	while(1){}
}

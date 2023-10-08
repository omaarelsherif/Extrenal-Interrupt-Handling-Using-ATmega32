/*
*    EXTI_Config.h
*    Name : Omar Elsherif
*    Version: 1.0
*    Date: 12-9-2023
*    Desc: Header file contains configurations for External interrupt driver 
*/

#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

// Include DIO configurations
#include "DIO_Config.h"

// Macros to define ISC modes
#define FALLING		0
#define RAISING		1
#define OCH			2
#define LOW_LEVEL   3
#define ISC_MODE    FALLING
#define INT_NUM     0

// Macros to define ISC bits to set ISC mode for INT0
#define ISC00	0
#define ISC01	1

// Macros to define enable & disable
#define DISABLE  0
#define ENABLE   1
#define INT0_EN  ENABLE
#define INT1_EN  DISABLE
#define INT2_EN  DISABLE

#endif

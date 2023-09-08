/******************************************************/
/******************************************************/
/*****************Author: Baraa Adel*******************/
/**************File: PORT_PRIVATE_H********************/
/******************Date:14th JULY 2023*****************/
/*********************Version: V1**********************/
/******************************************************/
/******************************************************/


#ifndef PORT_PRIVATE_H
#define PORT_PRIVATE_H


#define GPIO_A_BASE_ADDRESS 0x40010800
#define GPIO_B_BASE_ADDRESS 0x40010C00
#define GPIO_C_BASE_ADDRESS 0x40011000
#define GPIO_D_BASE_ADDRESS 0x40011400
#define GPIO_E_BASE_ADDRESS 0x40011800
#define GPIO_F_BASE_ADDRESS 0x40011C00

#define  GPIOX_CRH_RESET	0x44444444
#define  GPIOX_CRL_RESET	0x44444444


/*
0: Input mode (reset state)
1: Output mode, max speed 10 MHz.
2: Output mode, max speed 2 MHz.
3: Output mode, max speed 50 MHz.

*/
/*Mode*/
#define INPUT  			0
#define OUTPUT_10MHz 	1
#define OUTPUT_2MHz 	2
#define OUTPUT_50MHz 	3

/*
In input mode (MODE[1:0]=00):
00: Analog mode
01: Floating input (reset state)
10: Input with pull-up / pull-down
11: Reserved

In output mode (MODE[1:0] > 00):

00: General purpose output push-pull
01: General purpose output Open-drain
10: Alternate function output Push-pull
11: Alternate function output Open-drain
*/
/*Config*/
#define ANALOG		0
#define FLOATING	1
#define	PULL		2

#define GP_OPP		0
#define GP_OOD		1
#define AF_OPP		2
#define AF_OOD		3




typedef struct
{
	u32 CR[2];
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 BRR;
    u32 LCKR;


}GPIO_type;

#define GPIO_A	((GPIO_type *)GPIO_A_BASE_ADDRESS)
#define GPIO_B	((GPIO_type *)GPIO_B_BASE_ADDRESS)
#define GPIO_C	((GPIO_type *)GPIO_C_BASE_ADDRESS)
#define GPIO_D	((GPIO_type *)GPIO_D_BASE_ADDRESS)
#define GPIO_E	((GPIO_type *)GPIO_E_BASE_ADDRESS)
#define GPIO_F	((GPIO_type *)GPIO_F_BASE_ADDRESS)



/* GPIOX X FOR A,B,C,D,E AND F*/
#define GPIOA 0
#define GPIOB 1
#define GPIOC 2
#define GPIOD 3
#define GPIOE 4
#define GPIOF 5



#define PIN_ON	1
#define PIN_OFF	0

#define PORT_ON  0x0000FFFF
#define PORT_OFF 0xFFFF0000

#define 	A0 		0
#define 	A1 		1
#define 	A2 		2
#define 	A3 		3
#define 	A4 		4
#define 	A5 		5
#define 	A6 		6
#define 	A7 		7
#define 	A8 		8
#define 	A9 		9
#define 	A10 	10
#define 	A11 	11
#define 	A12 	12
#define 	A13 	13
#define 	A14 	14
#define 	A15 	15

#define 	B0 		0
#define 	B1 		1
#define 	B2 		2
#define 	B3 		3
#define 	B4 		4
#define 	B5 		5
#define 	B6 		6
#define 	B7 		7
#define 	B8 		8
#define 	B9 		9
#define 	B10 	10
#define 	B11 	11
#define 	B12 	12
#define 	B13 	13
#define 	B14 	14
#define 	B15 	15


#define 	C0 		0
#define 	C1 		1
#define 	C2 		2
#define 	C3 		3
#define 	C4 		4
#define 	C5 		5
#define 	C6 		6
#define 	C7 		7
#define 	C8 		8
#define 	C9 		9
#define 	C10 	10
#define 	C11 	11
#define 	C12 	12
#define 	C13 	13
#define 	C14 	14
#define 	C15 	15

#define 	D0 		0
#define 	D1 		1
#define 	D2 		2
#define 	D3 		3
#define 	D4 		4
#define 	D5 		5
#define 	D6 		6
#define 	D7 		7
#define 	D8 		8
#define 	D9 		9
#define 	D10 	10
#define 	D11 	11
#define 	D12 	12
#define 	D13 	13
#define 	D14 	14
#define 	D15 	15

#define 	E0 		0
#define 	E1 		1
#define 	E2 		2
#define 	E3 		3
#define 	E4 		4
#define 	E5 		5
#define 	E6 		6
#define 	E7 		7
#define 	E8 		8
#define 	E9 		9
#define 	E10 	10
#define 	E11 	11
#define 	E12 	12
#define 	E13 	13
#define 	E14 	14
#define 	E15 	15

#define 	F0 		0
#define 	F1 		1
#define 	F2 		2
#define 	F3 		3
#define 	F4 		4
#define 	F5 		5
#define 	F6 		6
#define 	F7 		7
#define 	F8 		8
#define 	F9 		9
#define 	F10 	10
#define 	F11 	11
#define 	F12 	12
#define 	F13 	13
#define 	F14 	14
#define 	F15 	15


#define 	GPIOA_A0 		000
#define 	GPIOA_A1 		001
#define 	GPIOA_A2 		002
#define 	GPIOA_A3 		003
#define 	GPIOA_A4 		004
#define 	GPIOA_A5 		005
#define 	GPIOA_A6 		006
#define 	GPIOA_A7 		007
#define 	GPIOA_A8 		008
#define 	GPIOA_A9 		009
#define 	GPIOA_A10	 	010
#define 	GPIOA_A11 		011
#define 	GPIOA_A12 		012
#define 	GPIOA_A13 		013
#define 	GPIOA_A14 		014
#define 	GPIOA_A15 		015


#define 	GPIOB_B0 		100
#define 	GPIOB_B1 		101
#define 	GPIOB_B2 		102
#define 	GPIOB_B3 		103
#define 	GPIOB_B4 		104
#define 	GPIOB_B5 		105
#define 	GPIOB_B6 		106
#define 	GPIOB_B7 		107
#define 	GPIOB_B8 		108
#define 	GPIOB_B9 		109
#define 	GPIOB_B10 		110
#define 	GPIOB_B11 		111
#define 	GPIOB_B12 		112
#define 	GPIOB_B13 		113
#define 	GPIOB_B14 		114
#define 	GPIOB_B15 		115


#define 	GPIOC_C0 		200
#define 	GPIOC_C1 		201
#define 	GPIOC_C2 		202
#define 	GPIOC_C3 		203
#define 	GPIOC_C4 		204
#define 	GPIOC_C5 		205
#define 	GPIOC_C6 		206
#define 	GPIOC_C7 		207
#define 	GPIOC_C8 		208
#define 	GPIOC_C9 		209
#define 	GPIOC_C10 		210
#define 	GPIOC_C11 		211
#define 	GPIOC_C12 		212
#define 	GPIOC_C13 		213
#define 	GPIOC_C14 		214
#define 	GPIOC_C15 		215




#endif

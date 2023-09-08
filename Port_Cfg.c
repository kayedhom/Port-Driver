/*****************************************************/
/*****************************************************/
/*****************Author: Baraa Adel******************/
/******************File: PORT_CFG_C*******************/
/******************Date:14th JULY 2023****************/
/*********************Version: V1*********************/
/*****************************************************/
/*****************************************************/

#include "Port.h"


const Port_ConfigType Port_Configuration =
{
    /* Configuration for individual port pins */
	 GPIOC,C13  , GP_OPP  , OUTPUT_2MHz, PIN_ON, TRUE,GPIOC_C13,
     GPIOA,A0   , GP_OPP  , OUTPUT_2MHz, PIN_OFF, TRUE,GPIOA_A0,
     GPIOA,A1   , GP_OPP  , OUTPUT_2MHz, PIN_OFF, TRUE,GPIOA_A1,

    /* Add more configurations if required */
};



    // Port_PinType            port ;
    // Port_PinType            pin;
    // Port_PinConfigType      config;
    // Port_PinModeType        mode;
    // Port_PinLevelType       initialLevel;
    // u8                      isDirectionChangeable;
	// u8                       Port_Pin_Id;

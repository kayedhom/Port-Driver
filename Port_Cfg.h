/*****************************************************/
/*****************************************************/
/*****************Author: Baraa Adel******************/
/********************File: PORT_CFG_H*****************/
/******************Date:14th JULY 2023****************/
/*********************Version: V1*********************/
/*****************************************************/
/*****************************************************/


#ifndef PORT_CFG_H
#define PORT_CFG_H

#include "Std_Types.h"

/* Configuration for PORT_NUMBER_OF_PORT_PINS can be adjusted based on the hardware */
#define PORT_NUMBER_OF_PORT_PINS  (16U)
#define PORT_NUMBER_OF_USED_PORT_PINS  (3U)

/* Symbolic names for port pin indexes */
#define PORT_PIN_INDEX_LED1      (0U)
#define PORT_PIN_INDEX_LED2      (1U)
#define PORT_PIN_INDEX_BUTTON1   (2U)
#define PORT_PIN_INDEX_BUTTON2   (3U)
/* Add more symbolic names for other pins as needed */

/* Symbolic names for port pin direction */
#define PORT_PIN_DIRECTION_INPUT    (0U)
#define PORT_PIN_DIRECTION_OUTPUT   (1U)

/* Symbolic names for port pin mode */
#define PORT_PIN_MODE_GPIO          (0U)
/* Add other possible pin modes here as needed */

/* Symbolic names for port pin level */
#define PORT_PIN_LEVEL_LOW          (0U)
#define PORT_PIN_LEVEL_HIGH         (1U)

/* Configuration for setting the direction API */
#define PORT_SET_PIN_DIRECTION_API  (STD_ON)

/* Configuration for version information API */
#define PORT_VERSION_INFO_API       (STD_ON)

#endif /* PORT_CFG_H */

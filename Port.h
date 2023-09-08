/*****************************************************/
/*****************************************************/
/*****************Author: Baraa Adel******************/
/********************File: PORT_H*********************/
/******************Date:14th JULY 2023****************/
/*********************Version: V1*********************/
/*****************************************************/
/*****************************************************/


#ifndef PORT_H
#define PORT_H

#include "Std_Types.h"
#include "Port_private.h"
#include "Port_Cfg.h"
#define mariam 0
/* AUTOSAR version information for the Port Driver */
/* AUTOSAR Version 4.0.3  */
#define PORT_AR_RELEASE_MAJOR_VERSION    (4U)
#define PORT_AR_RELEASE_MINOR_VERSION    (3U)
#define PORT_AR_RELEASE_REVISION_VERSION (1U)

/* Module version information for the Port Driver */
#define PORT_SW_MAJOR_VERSION    (1U)
#define PORT_SW_MINOR_VERSION    (0U)
#define PORT_SW_PATCH_VERSION    (0U)

/* AUTOSAR Standard API Service ID */
#define PORT_INIT_SID                      (u8)0x00
#define PORT_SET_PIN_DIRECTION_SID         (u8)0x01
#define PORT_REFRESH_PORT_DIRECTION_SID    (u8)0x02
#define PORT_SET_PIN_MODE_SID              (u8)0x03
#define PORT_GET_VERSION_INFO_SID          (u8)0x04

/* Port Module ID from AUTOSAR BSW Document */
#define PORT_MODULE_ID                          (124U)

/*
 * Port Instance ID
 * Note: ID = 0 because there are no other HW
 * For this instance
*/
#define PORT_INSTANCE_ID                        (0U)


/**DET Error Codes
  *Note: You can get them from Ch7 from PORT SWS **/



/* DET Code for Port Pin not configured as changeable            */
#define PORT_E_DIRECTION_UNCHANGEABLE           (u8)0x0B


/*
 * DET Code for Port_Init called with wrong Parameter
 * Note: This error is removed from AUTOSAR 4.3.1
[SWS_Port_00051]
*/

/* Development error codes */
#define PORT_E_PARAM_PIN                  (u8)0x0A
#define PORT_E_DIRECTION_UNCHANGEABLE     (u8)0x0B
#define PORT_E_INIT_FAILED                (u8)0x0C
#define PORT_E_PARAM_INVALID_MODE         (u8)0x0D
#define PORT_E_MODE_UNCHANGEABLE          (u8)0x0E
#define PORT_E_UNINIT                     (u8)0x0F
#define PORT_E_PARAM_POINTER              (u8)0x10


///* Port pin mode */
//#define PORT_PIN_MODE_GPIO                (u8)0x00
/* Add other possible pin modes here as needed */


#define TRUE    1
#define FALSE   0
#define NULL    0

/* Type definition for Port_PinType */
typedef u8 Port_PinType;

//typedef u8 Port_PinDirectionType;

/* Type definition for Port_PinModeType */
typedef u8 Port_PinModeType;

/* Type definition for Port_PinConfigType */
typedef u8 Port_PinConfigType;

/* Type definition for Port_PinLevelType */
typedef u8 Port_PinLevelType;


/* Type definition for Port_PinDirectionType , Port pin direction */

typedef enum
{
    PORT_PIN_IN =0 ,
    PORT_PIN_OUT
} Port_PinDirectionType;

/* Type definition for Std_VersionInfoType  */
typedef struct
{
    u16 vendorID;          // Vendor ID
    u16 moduleID;          // Module ID
    u8 instanceID;         // Instance ID (if applicable)
    u8 sw_major_version;   // Software major version
    u8 sw_minor_version;   // Software minor version
    u8 sw_patch_version;   // Software patch version
} Std_VersionInfoType;

/* Structure to hold the configuration data for a port pin */
typedef struct
{
    Port_PinType            port ;
    Port_PinType            pin;
    Port_PinConfigType   	config;
    Port_PinModeType        mode;
    Port_PinLevelType       initialLevel;
    u8                      isDirectionChangeable;
    u8                      Port_Pin_Id;
} Port_ConfigPin;

/* Structure to hold the configuration data for the Port Driver */
typedef struct
{
    Port_ConfigPin pins[PORT_NUMBER_OF_PORT_PINS];
} Port_ConfigType;


extern const Port_ConfigType Port_Configuration;



/* Function to initialize the Port Driver */
void Port_Init(const Port_ConfigType* ConfigPtr);

/* Function to set the pin direction of a specific port pin */
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);

/* Function to set the mode of a specific port pin */
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);

/* Function to refresh the direction of all configured port pins */
void Port_RefreshPortDirection(void);

/* Function to get the version information of the Port Driver */
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);


#endif /* PORT_H */

/*****************************************************/
/*****************************************************/
/*****************Author: Baraa Adel******************/
/*********************File: PORT_C********************/
/******************Date:14th JULY 2023****************/
/*********************Version: V1*********************/
/*****************************************************/
/*****************************************************/

/*Change here*/

#include "Port.h"

/* Static array to hold the port configurations */
static Port_ConfigType Port_Config;
Std_ReturnType status;
/* Function to initialize the Port Driver */
void Port_Init(const Port_ConfigType* ConfigPtr)
{
    /* Check if the ConfigPtr is not NULL */
    if (ConfigPtr != NULL)
    {
  
        /* Copy the port configurations to the static array */
        for (u8 i = 0; i < PORT_NUMBER_OF_USED_PORT_PINS; i++)
        {
            Port_Config.pins[i].port = ConfigPtr->pins[i].port;
            Port_Config.pins[i].pin = ConfigPtr->pins[i].pin;
            Port_Config.pins[i].config = ConfigPtr->pins[i].config;
            Port_Config.pins[i].mode = ConfigPtr->pins[i].mode;
            Port_Config.pins[i].initialLevel = ConfigPtr->pins[i].initialLevel;
            Port_Config.pins[i].isDirectionChangeable = ConfigPtr->pins[i].isDirectionChangeable;
            Port_Config.pins[i].Port_Pin_Id=ConfigPtr->pins[i].Port_Pin_Id;
        }

        u8 local_pin	=0;
		u8 CR_LorH		=0;
		u8 local_config	=0;
		u8 local_mode	=0;
		u32 Config_Mode	=0;

        for (u8 i = 0; i < PORT_NUMBER_OF_USED_PORT_PINS; i++)
        {
            local_pin 	 =  Port_Config.pins[i].pin;
            CR_LorH 	 = 	0;
            local_config = 	 Port_Config.pins[i].config;
            local_mode   =   Port_Config.pins[i].mode;
            Config_Mode  = 	0; /*Hold mode and config values */
            if((PORT_NUMBER_OF_PORT_PINS>>1) <= local_pin )
            {
            local_pin = local_pin - 8;
            CR_LorH	  = 1;
            }
            Config_Mode = (local_config<<2) + local_mode;
            Config_Mode = Config_Mode << (local_pin<<2);   /*which pin*/

            switch(Port_Config.pins[i].port){

                case GPIOA:
                GPIO_A -> CR[CR_LorH]|=Config_Mode;
                break;
                case GPIOB:
                GPIO_B -> CR[CR_LorH]|=Config_Mode;
                break;
                case GPIOC:
                GPIO_C -> CR[CR_LorH]|=Config_Mode;
                break;
                case GPIOD:
                GPIO_D -> CR[CR_LorH]|=Config_Mode;
                break;
                case GPIOE:
                GPIO_E -> CR[CR_LorH]|=Config_Mode;
                break;
                case GPIOF:
                GPIO_F -> CR[CR_LorH]|=Config_Mode;
                break;
                default:
                break;
	}
    }


    }
    else
    {
        /* Report development error: ConfigPtr is NULL */
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_INIT_FAILED);
    }
}







/* Function to set the pin direction of a specific port pin */
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
    /* Local variable to hold the status */
     status = E_OK;

    /* Check if the port pin is valid */
    for (u8 i = 0; i < PORT_NUMBER_OF_USED_PORT_PINS; i++){
    if(Port_Config.pins[i].Port_Pin_Id==Pin)
    {
        /* Check if the direction is changeable for the pin */
        if (Port_Config.pins[i].isDirectionChangeable == TRUE)
        {
            /* Set the pin direction */
        u8 local_pin	=   Port_Config.pins[i].pin;
		u8 CR_LorH		=   0;
		u8 local_config	=   Port_Config.pins[i].config;
		u8 local_mode	=   Direction;
		u32 Config_Mode	=   0;     /*Hold mode and config values */
        u32 changeValue =   0;     /*Reset mode and config values in REG*/

            if((PORT_NUMBER_OF_PORT_PINS>>1) <= local_pin )
            {
            local_pin = local_pin - 8;
            CR_LorH	  = 1;
            }
            Config_Mode = (local_config<<2) + local_mode;
            Config_Mode = Config_Mode << (local_pin<<2);   /*which pin*/
            changeValue =(~(0x0000000F<<(local_pin<<2)));

            switch(Port_Config.pins[i].port){

                case GPIOA:
                GPIO_A -> CR[CR_LorH]&=changeValue;
                GPIO_A -> CR[CR_LorH]|=Config_Mode;
                break;
                case GPIOB:
                GPIO_B -> CR[CR_LorH]&=changeValue;
                GPIO_B -> CR[CR_LorH]|=Config_Mode;
                break;
                case GPIOC:
                GPIO_C -> CR[CR_LorH]&=changeValue;
                GPIO_C -> CR[CR_LorH]|=Config_Mode;
                break;
                case GPIOD:
                GPIO_D -> CR[CR_LorH]&=changeValue;
                GPIO_D -> CR[CR_LorH]|=Config_Mode;
                break;
                case GPIOE:
                GPIO_E -> CR[CR_LorH]&=changeValue;
                GPIO_E -> CR[CR_LorH]|=Config_Mode;
                break;
                case GPIOF:
                GPIO_F -> CR[CR_LorH]&=changeValue;
                GPIO_F -> CR[CR_LorH]|=Config_Mode;
                break;
                default:
                break;
	}


            /* Update the internal direction variable for the pin */
            Port_Config.pins[i].mode = Direction;
        }
        else
        {
            /* Report development error: direction is unchangeable for the pin */
            /* Mode is unchangeable, report a PORT_E_MODE_UNCHANGEABLE */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_DIRECTION_UNCHANGEABLE);
            status = E_NOT_OK;
        }
            i=PORT_NUMBER_OF_USED_PORT_PINS;
    }
    else
    {
        /* Report development error: invalid pin number */
        status = E_NOT_OK;
    }

    }
}


/* Function to refresh the direction of all configured port pins */
void Port_RefreshPortDirection(void)
{
    /* Loop through all the configured pins */
    for (u8 i = 0; i < PORT_NUMBER_OF_USED_PORT_PINS; i++)
    {
        /* Check if the direction is changeable for the pin */
        if (Port_Configuration.pins[i].isDirectionChangeable == TRUE)
        {
            /* Set the pin direction */
            Port_Config.pins[i].mode=Port_Configuration.pins[i].mode;
            /* Implementation specific code to set the direction of the pin */
        }
    }
}

/* Function to get the version information of the Port Driver */
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
    /* Check if versioninfo is not NULL */
    if (versioninfo != NULL)
    {
        /* Set the version information of the Port Driver */
      //  versioninfo->vendorID = PORT_VENDOR_ID;
      //  versioninfo->moduleID = PORT_MODULE_ID;
        versioninfo->sw_major_version = PORT_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = PORT_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = PORT_SW_PATCH_VERSION;
    }
    else
    {
        /* Report development error: versioninfo is NULL */
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_GET_VERSION_INFO_SID,PORT_E_PARAM_POINTER);
    }
}

/* Function to set the pin mode of a specific port pin */
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{

    /* Local variable to hold the status */
     status = E_OK;

    /* Check if the port pin is valid */
    for (u8 i = 0; i < PORT_NUMBER_OF_USED_PORT_PINS; i++){
    if(Port_Config.pins[i].Port_Pin_Id==Pin)
    {
        /* Check if the direction is changeable for the pin */
        if (Port_Config.pins[i].isDirectionChangeable == TRUE)
        {
            /* Set the pin direction */
        u8 local_pin	=   Port_Config.pins[i].pin;
		u8 CR_LorH		=   0;
		u8 local_config	=   Mode;
		u8 local_mode	=   Port_Config.pins[i].mode;
		u32 Config_Mode	=   0;     /*Hold mode and config values */
        u32 changeValue =   0;     /*Reset mode and config values in REG*/

            if((PORT_NUMBER_OF_PORT_PINS>>1) <= local_pin )
            {
            local_pin = local_pin - 8;
            CR_LorH	  = 1;
            }
            Config_Mode = (local_config<<2) + local_mode;
            Config_Mode = Config_Mode << (local_pin<<2);   /*which pin*/
            changeValue =(~(0x0000000F<<(local_pin<<2)));

            switch(Port_Config.pins[i].port){

                case GPIOA:
                GPIO_A -> CR[CR_LorH]&=changeValue;
                GPIO_A -> CR[CR_LorH]|=Config_Mode;
                break;
                case GPIOB:
                GPIO_B -> CR[CR_LorH]&=changeValue;
                GPIO_B -> CR[CR_LorH]|=Config_Mode;
                break;
                case GPIOC:
                GPIO_C -> CR[CR_LorH]&=changeValue;
                GPIO_C -> CR[CR_LorH]|=Config_Mode;
                break;
                case GPIOD:
                GPIO_D -> CR[CR_LorH]&=changeValue;
                GPIO_D -> CR[CR_LorH]|=Config_Mode;
                break;
                case GPIOE:
                GPIO_E -> CR[CR_LorH]&=changeValue;
                GPIO_E -> CR[CR_LorH]|=Config_Mode;
                break;
                case GPIOF:
                GPIO_F -> CR[CR_LorH]&=changeValue;
                GPIO_F -> CR[CR_LorH]|=Config_Mode;
                break;
                default:
                break;
	}


            /* Update the internal direction variable for the pin */
            Port_Config.pins[i].config =  Mode;
        }
        else
        {
            /* Report development error: direction is unchangeable for the pin */
            /* Mode is unchangeable, report a PORT_E_MODE_UNCHANGEABLE */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
            status = E_NOT_OK;
        }
            i=PORT_NUMBER_OF_USED_PORT_PINS;
    }
    else
    {
        /* Report development error: invalid pin number */
        status = E_NOT_OK;
    }

    }


}


//u32 changeValue =(~(0x0000000F<<(local_pin<<2)));
//                GPIO_A -> CR[CR_LorH]&=changeValue;
//                GPIO_A -> CR[CR_LorH]|=Config_Mode;


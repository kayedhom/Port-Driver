#ifndef PORT_TYPES_H
#define PORT_TYPES_H

#include "Std_Types.h"

/* AUTOSAR version information for the Port Driver */
#define PORT_AR_RELEASE_MAJOR_VERSION    (4U)
#define PORT_AR_RELEASE_MINOR_VERSION    (3U)
#define PORT_AR_RELEASE_REVISION_VERSION (1U)

/* Module version information for the Port Driver */
#define PORT_SW_MAJOR_VERSION    (1U)
#define PORT_SW_MINOR_VERSION    (0U)
#define PORT_SW_PATCH_VERSION    (0U)

/* Type definition for Port_PinType */
typedef uint8 Port_PinType;

/* Type definition for Port_PinDirectionType */
typedef uint8 Port_PinDirectionType;

/* Type definition for Port_PinModeType */
typedef uint8 Port_PinModeType;

/* Type definition for Port_PinLevelType */
typedef uint8 Port_PinLevelType;

/* Structure to hold the configuration data for a port pin */
typedef struct
{
    Port_PinType pin;
    Port_PinDirectionType direction;
    Port_PinModeType mode;
    Port_PinLevelType initialLevel;
    boolean isDirectionChangeable;
} Port_ConfigPin;

/* Structure to hold the configuration data for the Port Driver */
typedef struct
{
    Port_ConfigPin pins[PORT_NUMBER_OF_PORT_PINS];
} Port_ConfigType;

#endif /* PORT_TYPES_H */

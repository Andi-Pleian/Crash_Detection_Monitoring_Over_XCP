#if (!defined STD_TYPES_H)
/* !LINKSTO STD003,1, STD014,1 */
#define STD_TYPES_H

/**
 * \file
 *
 * \brief AUTOSAR Base
 *
 * This file contains the implementation of the AUTOSAR
 * module Base.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


/* !LINKSTO STD004,1 */

/*==================[inclusions]=============================================*/

/* !LINKSTO STD001,1 */
#include <Platform_Types.h> /* Autosar platform specific type declarations */
#include <Compiler.h>       /* Autosar compiler specific declarations */

/*==================[macros]=================================================*/

/* !LINKSTO STD007,1 */
#if (defined STD_HIGH)
#error STD_HIGH already defined
#endif

/** \brief physical state 5V or 3.3V  */
#define STD_HIGH 1U

#if (defined STD_LOW)
#error STD_LOW already defined
#endif

/** \brief physical state 0V */
#define STD_LOW 0U

/* !LINKSTO STD013,1 */
#if (defined STD_ACTIVE)
#error STD_ACTIVE already defined
#endif

/** \brief Autosar logical state 'active' */
#define STD_ACTIVE 1U

#if (defined STD_IDLE)
#error STD_IDLE already defined
#endif

/** \brief Autosar logical state 'idle' */
#define STD_IDLE 0U

/* !LINKSTO STD010,1 */
#if (defined STD_ON)
#error STD_ON already defined
#endif

/** \brief Autosar definition for 'on' */
#define STD_ON 1U

#if (defined STD_OFF)
#error STD_OFF already defined
#endif

/** \brief Autosar definition for 'off' */
#define STD_OFF 0U

#if (!defined STATUSTYPEDEFINED)
/** \brief Guard macro for type definition of StatusType */
#define STATUSTYPEDEFINED
/** \brief Definition StatusType (OSEK compliance) */
typedef unsigned char StatusType;
#endif

/* !LINKSTO STD006,1 */
#if (!defined E_OK)
/** \brief Constant for value OK of StatusType */
/* !LINKSTO STD011,1 */
#define E_OK 0U
#endif

#if (!defined E_NOT_OK)
/** \brief Constant for value NOT_OK of StatusType */
/* !LINKSTO STD011,1 */
#define E_NOT_OK 1U
#endif

/*------------------[AUTOSAR vendor identification]-------------------------*/

#if (defined STD_VENDOR_ID)
#error STD_VENDOR_ID is already defined
#endif
/** \brief AUTOSAR vendor identification: EB Automotive */
#define STD_VENDOR_ID         1U

/*------------------[AUTOSAR module identification]-------------------------*/

#if (defined STD_MODULE_ID)
#error STD_MODULE_ID already defined
#endif
/** \brief AUTOSAR module identification
 *
 * Left empty as this header does not belong to any module
 */
#define STD_MODULE_ID         197U

/*------------------[AUTOSAR release version identification]----------------*/

#if (defined STD_AR_RELEASE_MAJOR_VERSION)
#error STD_AR_RELEASE_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR release major version */
#define STD_AR_RELEASE_MAJOR_VERSION     4U

#if (defined STD_AR_RELEASE_MINOR_VERSION)
#error STD_AR_RELEASE_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR release minor version */
#define STD_AR_RELEASE_MINOR_VERSION     0U

#if (defined STD_AR_RELEASE_REVISION_VERSION)
#error STD_AR_RELEASE_REVISION_VERSION already defined
#endif
/** \brief AUTOSAR release revision version */
#define STD_AR_RELEASE_REVISION_VERSION  3U

/*------------------[AUTOSAR module version identification]------------------*/

#if (defined STD_SW_MAJOR_VERSION)
#error STD_SW_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR module major version */
#define STD_SW_MAJOR_VERSION     1U

#if (defined STD_SW_MINOR_VERSION)
#error STD_SW_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR module minor version */
#define STD_SW_MINOR_VERSION     3U

#if (defined STD_SW_PATCH_VERSION)
#error STD_SW_PATCH_VERSION already defined
#endif
/** \brief AUTOSAR module patch version */
#define STD_SW_PATCH_VERSION     0U

/*------------------[AUTOSAR module vendor API infix]------------------------*/

#if (defined STD_VENDOR_API_INFIX)
#error STD_VENDOR_API_INFIX already defined
#endif
/** \brief Vendor API infix
 *
 * Left empty as this header does not belong to any module
 */
#define STD_VENDOR_API_INFIX

/*==================[type definitions]=======================================*/

/** \brief Autosar standard API return type */
/* !LINKSTO STD005,1 */
typedef uint8 Std_ReturnType;

#if (!defined STD_VERSION_INFO_TYPE_DEFINED)
/** \brief Guard for definition of Std_VersionInfoType */
#define STD_VERSION_INFO_TYPE_DEFINED STD_OFF
#endif

/* !LINKSTO Base.CustomStdVersionInfoType.ConfigMacro,1 */
#if (STD_VERSION_INFO_TYPE_DEFINED != STD_ON)

/** \brief return type for xxx_GetVersionInfo() functions of each BSW module
 *
 * This type is used to request the version of BSW module using the
 * xxx_GetVersionInfo() function.
 */
/* !LINKSTO STD015,1 */
typedef struct
{
   uint16 vendorID;
   uint16 moduleID;
   uint8  sw_major_version;
   uint8  sw_minor_version;
   uint8  sw_patch_version;
} Std_VersionInfoType;

#endif /* #if (STD_VERSION_INFO_TYPE_DEFINED != STD_ON) */

/*==================[end of file]============================================*/
#endif /* if !defined( STD_TYPES_H ) */

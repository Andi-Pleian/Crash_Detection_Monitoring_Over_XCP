/**
 * \file
 *
 * \brief AUTOSAR Xcp
 *
 * This file contains the implementation of the AUTOSAR
 * module Xcp.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]============================================*/

#include <Xcp_Wrapper_Trace.h>
#include <Std_Types.h>        /* AUTOSAR standard types */
//#include <TSAutosar.h>        /* EB specific standard types */


/* include service wrapper header file */
#include <Xcp_Wrapper.h>

/* Xcp header file */
#include <Xcp.h>
#include <Xcp_Cbk.h>

/* include user header file*/

/*==================[macros]================================================*/

/*------------------[AUTOSAR vendor identification check]-------------------*/

#if (!defined XCP_VENDOR_ID) /* configuration check */
#error XCP_VENDOR_ID must be defined
#endif

#if (XCP_VENDOR_ID != 1U) /* vendor check */
#error XCP_VENDOR_ID has wrong vendor id
#endif

/*------------------[AUTOSAR release version identification check]----------*/

#if (!defined XCP_AR_RELEASE_MAJOR_VERSION) /* configuration check */
#error XCP_AR_RELEASE_MAJOR_VERSION must be defined
#endif

/* major version check */
#if (XCP_AR_RELEASE_MAJOR_VERSION != 4U)
#error XCP_AR_RELEASE_MAJOR_VERSION wrong (!= 4U)
#endif

#if (!defined XCP_AR_RELEASE_MINOR_VERSION) /* configuration check */
#error XCP_AR_RELEASE_MINOR_VERSION must be defined
#endif

/* minor version check */
#if (XCP_AR_RELEASE_MINOR_VERSION != 0U )
#error XCP_AR_RELEASE_MINOR_VERSION wrong (!= 0U)
#endif

#if (!defined XCP_AR_RELEASE_REVISION_VERSION) /* configuration check */
#error XCP_AR_RELEASE_REVISION_VERSION must be defined
#endif

/* revision version check */
#if (XCP_AR_RELEASE_REVISION_VERSION != 3U )
#error XCP_AR_RELEASE_REVISION_VERSION wrong (!= 3U)
#endif

/*------------------[AUTOSAR module version identification check]-----------*/

#if (!defined XCP_SW_MAJOR_VERSION) /* configuration check */
#error XCP_SW_MAJOR_VERSION must be defined
#endif

/* major version check */
#if (XCP_SW_MAJOR_VERSION != 2U)
#error XCP_SW_MAJOR_VERSION wrong (!= 2U)
#endif

#if (!defined XCP_SW_MINOR_VERSION) /* configuration check */
#error XCP_SW_MINOR_VERSION must be defined
#endif

/* minor version check */
#if (XCP_SW_MINOR_VERSION < 11U)
#error XCP_SW_MINOR_VERSION wrong (< 11U)
#endif

#if (!defined XCP_SW_PATCH_VERSION) /* configuration check */
#error XCP_SW_PATCH_VERSION must be defined
#endif

/* patch version check */
#if (XCP_SW_PATCH_VERSION < 1U)
#error XCP_SW_PATCH_VERSION wrong (< 1U)
#endif
/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/
#if (defined XCP_MODULE_DISABLED)
#error XCP_MODULE_DISABLED already defined
#endif
/** \brief Constant macrodefinition for checking the state of Xcp module */
#define XCP_MODULE_DISABLED                             0U

/*==================[external constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/

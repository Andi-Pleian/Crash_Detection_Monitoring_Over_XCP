/**
 * \file
 *
 * \brief AUTOSAR Dem
 *
 * This file contains the implementation of the AUTOSAR
 * module Dem.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2015 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if ( !defined DEM_BSW_TYPES_H )
#define DEM_BSW_TYPES_H
/*==================[inclusions]============================================*/

/* Generated configuration data. Defines DEM_INCLUDE_RTE. */
#include <Dem_Cfg.h>

/*==================[type definitions]======================================*/

/* The definition of Dem_EventIdType was moved to Dem_Cfg.h, because it is used
 * by Dem_AdvDisplPassiveEventIdsLine[] */

#ifndef RTE_TYPE_Dem_EventStatusExtendedType
#define RTE_TYPE_Dem_EventStatusExtendedType
/**  \brief Defines the Event Status byte
 **  In this data-type each bit has an individual meaning.
 **  In case the Rte is available this type is defined in Rte_Type.h.
 **/
typedef uint8 Dem_EventStatusExtendedType;
#endif

#ifndef RTE_TYPE_Dem_ASR40_EventIdType
#define RTE_TYPE_Dem_ASR40_EventIdType
/**  \brief Defines the Dem Event ID which is
 **  identification of an event by assigned EventId
 **  In case the Rte is available this type is defined in Rte_Type.h.
 **/
typedef uint16 Dem_ASR40_EventIdType;
#endif

#ifndef RTE_TYPE_Dem_EventStatusExtendedType
#define RTE_TYPE_Dem_EventStatusExtendedType
/**  \brief Defines the Event Status byte
 **  In this data-type each bit has an individual meaning.
 **  In case the Rte is available this type is defined in Rte_Type.h.
 **/
typedef uint8 Dem_EventStatusExtendedType;
#endif

#ifndef RTE_TYPE_Dem_ASR42_EventIdType
#define RTE_TYPE_Dem_ASR42_EventIdType
/**  \brief Defines the Dem Event ID which is
 **  identification of an event by assigned EventId
 **  In case the Rte is available this type is defined in Rte_Type.h.
 **/
/* SWS_Dem_00925 */
typedef uint16 Dem_ASR42_EventIdType;
#endif

#ifndef RTE_TYPE_Dem_ASR42_UdsStatusByteType
#define RTE_TYPE_Dem_ASR42_UdsStatusByteType
/**  \brief Defines the Event Status byte
 **  In this data-type each bit has an individual meaning.
 **  In case the Rte is available this type is defined in Rte_Type.h.
 **/
/* SWS_Dem_00928 */
typedef uint8 Dem_ASR42_UdsStatusByteType;
#endif

/*==================[macros]================================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* if !defined( DEM_BSW_TYPES_H ) */

/*==================[end of file NvM.h]=====================================*/

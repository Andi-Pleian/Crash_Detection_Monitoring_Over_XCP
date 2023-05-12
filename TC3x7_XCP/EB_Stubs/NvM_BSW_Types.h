/**
 * \file
 *
 * \brief AUTOSAR NvM
 *
 * This file contains the implementation of the AUTOSAR
 * module NvM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if ( !defined NVM_BSW_TYPES_H )
#define NVM_BSW_TYPES_H
/*==================[inclusions]============================================*/

/* Generated configuration data. Defines NVM_INCLUDE_RTE. */
#include <NvM_Cfg.h>

/*==================[type definitions]======================================*/

#ifndef RTE_TYPE_NvM_ASR32_BlockIdType
#define RTE_TYPE_NvM_ASR32_BlockIdType
/**  \brief Defines the NvM block ID which is equal to the
 **  number of the block in the configuration table.
 **  In case the Rte is available this type is defined in Rte_Type.h.
 **/
typedef uint16 NvM_ASR32_BlockIdType;
#endif

#ifndef RTE_TYPE_NvM_ASR32_RequestResultType
#define RTE_TYPE_NvM_ASR32_RequestResultType
/**  \brief Defines the NvM error status e.g. NVM_REQ_OK.
 **  In case the Rte is available, this type is defined in Rte_Type.h.
 **/
typedef uint8 NvM_ASR32_RequestResultType;
#endif

#ifndef RTE_TYPE_NvM_ASR40_BlockIdType
#define RTE_TYPE_NvM_ASR40_BlockIdType
/**  \brief Defines the NvM block ID which is equal to the
 **  number of the block in the configuration table.
 **  In case the Rte is available this type is defined in Rte_Type.h.
 **/
/* !LINKSTO NVM471,1 */
typedef uint16 NvM_ASR40_BlockIdType;
#endif

#ifndef RTE_TYPE_NvM_ASR40_RequestResultType
#define RTE_TYPE_NvM_ASR40_RequestResultType
/**  \brief Defines the NvM error status e.g. NVM_REQ_OK.
 **  In case the Rte is available, this type is defined in Rte_Type.h.
 **/
/* !LINKSTO NVM470,1 */
typedef uint8 NvM_ASR40_RequestResultType;
#endif

#ifndef RTE_TYPE_NvM_ASR42_BlockIdType
#define RTE_TYPE_NvM_ASR42_BlockIdType
/**  \brief Defines the NvM block ID which is equal to the
 **  number of the block in the configuration table.
 **  In case the Rte is available this type is defined in Rte_Type.h.
 **/
/* !LINKSTO NVM471,1 */
typedef uint16 NvM_ASR42_BlockIdType;
#endif

#ifndef RTE_TYPE_NvM_ASR42_RequestResultType
#define RTE_TYPE_NvM_ASR42_RequestResultType
/**  \brief Defines the NvM error status e.g. NVM_REQ_OK.
 **  In case the Rte is available, this type is defined in Rte_Type.h.
 **/
/* !LINKSTO NVM470,1 */
typedef uint8 NvM_ASR42_RequestResultType;
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

#endif /* if !defined( NVM_BSW_TYPES_H ) */

/*==================[end of file NvM.h]=====================================*/

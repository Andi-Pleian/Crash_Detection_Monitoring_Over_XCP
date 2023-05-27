/**
 * \file
 *
 * \brief AUTOSAR Det
 *
 * This file contains the implementation of the AUTOSAR
 * module Det.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if !defined(DET_BSW_H)
#define DET_BSW_H

/*==================[inclusions]============================================*/

#include <Det_Cfg.h>                   /* this moule's public configuration */

/* we do not need to include Rte_Types.h here because the Rte does not define
 * any Det specific data types. */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

#define DET_START_SEC_CODE
#include <MemMap.h>

/* Declaration of Det service API must _NOT_ be excluded in case of
 * internal usage because Det.c is decoupled from RTE. */

/* !LINKSTO Det.EB.ASR32.Det103,1 */
/** \brief Report development errors.
 **
 ** This function reports development errors. This function is called from
 ** modules XXX for development errors in case of activated preprocessor
 ** switch XXX_DEV_ERROR_DETECT.  Production relevant errors shall be reported
 ** to the Diagnostics Event Manager (DEM).
 **
 ** \param[in] ModuleId Module ID of calling module.
 ** \param[in] InstanceId Instance ID of calling module.
 ** \param[in] ApiId ID of API service in which error is detected.
 ** \param[in] ErrorId ID of detected development error.
 ** \return allways ::E_OK
 **
 ** \ServiceID{::DET_SID_REPORT_ERROR}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC(Std_ReturnType, DET_CODE) Det_ASR40_ReportError(
   uint16 ModuleId,
   uint8  InstanceId,
   uint8  ApiId,
   uint8  ErrorId);

/* !LINKSTO Det.EB.ASR32.Det102,1 */
#if ((DET_ENABLE_ASR32_SERVICE_API == STD_ON) || (DET_DEFAULT_ASR_SERVICE_API == DET_SERVICE_API_ASR32))
/** \brief Report development errors.
 **
 ** This function is the AUTOSAR 3.2 specific implementation to report development errors.
 ** This function is called from modules XXX for development errors in case of activated
 ** preprocessor switch XXX_DEV_ERROR_DETECT.  Production relevant errors shall be reported
 ** to the Diagnostics Event Manager (DEM).
 **
 ** \param[in] ModuleId Module ID of calling module.
 ** \param[in] InstanceId Instance ID of calling module.
 ** \param[in] ApiId ID of API service in which error is detected.
 ** \param[in] ErrorId ID of detected development error.
 ** \return none
 **
 ** \ServiceID{::DET_SID_REPORT_ERROR}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC(void, DET_CODE) Det_ASR32_ReportError(
   uint16 ModuleId,
   uint8  InstanceId,
   uint8  ApiId,
   uint8  ErrorId);
#endif

#define DET_STOP_SEC_CODE
#include <MemMap.h>

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
#endif /* if !defined(DET_BSW_H) */

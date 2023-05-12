/**
 * \file
 *
 * \brief AUTOSAR Dcm
 *
 * This file contains the implementation of the AUTOSAR
 * module Dcm.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined DCM_TYPES_CFG_H)
#define DCM_TYPES_CFG_H

/*==================[includes]===================================================================*/
/*==================[macros]=====================================================================*/

/* !LINKSTO Dcm.EB.SesCtrlType.RteUsageFalse,1 */
#if (DCM_INCLUDE_RTE == STD_OFF)
/*------------------[definitions of session levels]----------------------------------------------*/
#if (defined DcmConf_DcmDspSession_DEFAULT_SESSION)
#error DcmConf_DcmDspSession_DEFAULT_SESSION already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDspSession_DEFAULT_SESSION 1U

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_DEFAULT_SESSION)
#error Dcm_DEFAULT_SESSION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_DEFAULT_SESSION 1U
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DcmConf_DcmDspSession_EXTENDED_DIAGNOSTIC_SESSION)
#error DcmConf_DcmDspSession_EXTENDED_DIAGNOSTIC_SESSION already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDspSession_EXTENDED_DIAGNOSTIC_SESSION 3U

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_EXTENDED_DIAGNOSTIC_SESSION)
#error Dcm_EXTENDED_DIAGNOSTIC_SESSION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_EXTENDED_DIAGNOSTIC_SESSION 3U
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DcmConf_DcmDspSession_SAFETY_SYSTEM_DIAGNOSTIC_SESSION)
#error DcmConf_DcmDspSession_SAFETY_SYSTEM_DIAGNOSTIC_SESSION already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDspSession_SAFETY_SYSTEM_DIAGNOSTIC_SESSION 4U

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_SAFETY_SYSTEM_DIAGNOSTIC_SESSION)
#error Dcm_SAFETY_SYSTEM_DIAGNOSTIC_SESSION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_SAFETY_SYSTEM_DIAGNOSTIC_SESSION 4U
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DcmConf_DcmDspSession_CODING_SESSION)
#error DcmConf_DcmDspSession_CODING_SESSION already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDspSession_CODING_SESSION 65U

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_CODING_SESSION)
#error Dcm_CODING_SESSION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_CODING_SESSION 65U
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DcmConf_DcmDspSession_DEVELOPMENT_SESSION)
#error DcmConf_DcmDspSession_DEVELOPMENT_SESSION already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDspSession_DEVELOPMENT_SESSION 79U

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_DEVELOPMENT_SESSION)
#error Dcm_DEVELOPMENT_SESSION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_DEVELOPMENT_SESSION 79U
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#endif /* #if (DCM_INCLUDE_RTE == STD_OFF) */

/*==================[type definitions]===========================================================*/
/*==================[external function declarations]=============================================*/
/*==================[internal function declarations]=============================================*/
/*==================[external constants]=========================================================*/
/*==================[internal data]==============================================================*/
/*==================[external function definitions]==============================================*/
/*==================[internal function definitions]==============================================*/

#endif /* if !defined( DCM_TYPES_CFG_H ) */
/*==================[end of file]================================================================*/

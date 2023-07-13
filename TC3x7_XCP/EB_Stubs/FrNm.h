/**
 * \file
 *
 * \brief AUTOSAR FrNm
 *
 * This file contains the implementation of the AUTOSAR
 * module FrNm.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#if (!defined FRNM_H)
#define FRNM_H

/*==================[inclusions]=========================================*/

#if (!defined FRNM_NO_CFG_REQUIRED)
#define FRNM_NO_CFGCLASSMIX_REQUIRED
#include <FrNm_Cfg.h>           /* Module configuration */
#endif /* FRNM_NO_CFG_REQUIRED */

#if (!defined FRNM_NO_LCFG_REQUIRED) && (!defined FRNM_NO_CFG_REQUIRED)
#include <FrNm_Lcfg.h>          /* Link-Time configuration */
#endif /* FRNM_NO_LCFG_REQUIRED */

/* Exclude post-build-time configuration include file if requested to do so */
#if (!defined FRNM_NO_PBCFG_REQUIRED)
#if (FRNM_PBCFGM_SUPPORT_ENABLED == STD_OFF)
#include <FrNm_PBcfg.h>     /* post build configuration of FrNm */
#endif /* FRNM_PBCFGM_SUPPORT_ENABLED == STD_OFF */
#endif /* FRNM_NO_PBCFG_REQUIRED */

#undef FRNM_NO_CFG_REQUIRED
#undef FRNM_NO_LCFG_REQUIRED
#undef FRNM_NO_PBCFG_REQUIRED

#include <FrNm_Api.h>

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* if !defined( FRNM_H ) */
/*==================[end of file]========================================*/

/**
 * \file
 *
 * \brief AUTOSAR CanSM
 *
 * This file contains the implementation of the AUTOSAR
 * module CanSM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined CANSM_INTERNALCFG_H_)
#define CANSM_INTERNALCFG_H_
/*==================[includes]==============================================*/

#include <BswM_CanSM.h>        /* Basic Software Mode Manager */

/*==================[macros]================================================*/

/*------------------[Function-Like macros]-----------*/

#if (defined BSWM_CANSM_CURRENTSTATE)      /* To prevent double declaration */
#error BSWM_CANSM_CURRENTSTATE already defined!
#endif /* #if (defined BSWM_CANSM_CURRENTSTATE) */

/** \brief Indicate state changes to BswM */
#define BSWM_CANSM_CURRENTSTATE(nw, cs) \
  BswM_CanSM_CurrentState(nw, cs)

#endif /* (!defined CANSM_INTERNALCFG_H_) */
/*==================[end of file]===========================================*/

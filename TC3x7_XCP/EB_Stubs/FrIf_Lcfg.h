/**
 * \file
 *
 * \brief AUTOSAR FrIf
 *
 * This file contains the implementation of the AUTOSAR
 * module FrIf.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef FRIF_LCFG_H
#define FRIF_LCFG_H

/*
 * Include Section
 */
#include <FrIf_Api.h>      /* FrIf public API */


/*
 * Global function declarations
 */
/* start code section declaration */
#define FRIF_START_SEC_CODE
#include <MemMap.h>


extern FUNC(void,FRIF_CODE) FrIf_MainFunction_0(void);
extern FUNC(void,FRIF_CODE) FrIf_JobListExec_0(void);


/* stop code section declaration */
#define FRIF_STOP_SEC_CODE
#include <MemMap.h>


#endif /* FRIF_LCFG_H */
/*==================[end of file]============================================*/


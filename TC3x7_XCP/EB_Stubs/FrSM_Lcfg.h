/**
 * \file
 *
 * \brief AUTOSAR FrSM
 *
 * This file contains the implementation of the AUTOSAR
 * module FrSM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef FRSM_LCFG_H
#define FRSM_LCFG_H

/*
 * Include Section
 */

#include <FrSM.h>      /* FrSM interface headerfile */

/*
 * Global Function Declarations
 */

#define FRSM_START_SEC_CODE
#include <MemMap.h>  /* !LINKSTO FrSm.ASR40.FrSm057,1 */


/**
 * \brief FrSM main function for FlexRay cluster with FrIfClstIdx 0
 *
 * \ServiceID{0x80}
 */
extern FUNC(void,FRSM_CODE) FrSM_MainFunction_0(void);


#define FRSM_STOP_SEC_CODE
#include <MemMap.h>  /* !LINKSTO FrSm.ASR40.FrSm057,1 */


#endif /* FRSM_LCFG_H */


/*
 * = eof ======================================================================
 */

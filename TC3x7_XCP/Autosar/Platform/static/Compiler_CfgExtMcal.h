/**
 * \file
 *
 * \brief AUTOSAR Resource
 *
 * This file contains the implementation of the AUTOSAR
 * module Resource.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined COMPILER_CFGEXT_MCAL_H)
#define COMPILER_CFGEXT_MCAL_H


/* EB: Map Mcal functions to Os functions *
 * Tracked in ticket ASCINFINEON-405 */
#ifdef OS_KERNEL_TYPE
#include <Os.h>        /* OS interrupt services */	
#endif

/*EB :define IFX_INTERRUPT to be handle by Os */
#define IFX_INTERRUPT(isr,vectabNum,prio) \
					void OS_ISR_##isr(void)	
    
/* 
  Note: Elektrobit Automotive GmbH modified the original code provided
        by the third party supplier. The modification is provided for
        convenience.
        Please use the modification on your discretion and account, or
        use the unmodified files provided with this distribution. 
  Please see for the reasons in the file ImportantNotes.txt for tag
*/
#endif /* if !defined( COMPILER_CFGEXT_MCAL_H ) */
/*==================[end of file]============================================*/

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

#if (!defined XCP_DEFPROG_CFG_H)
#define XCP_DEFPROG_CFG_H

/*==================[includes]==============================================*/

/*==================[macros]================================================*/




/*------------------[Defensive programming]---------------------------------*/

#if (defined XCP_DEFENSIVE_PROGRAMMING_ENABLED)
#error XCP_DEFENSIVE_PROGRAMMING_ENABLED is already defined
#endif
/** \brief Defensive programming usage
 **
 ** En- or disables the usage of the defensive programming */
#define XCP_DEFENSIVE_PROGRAMMING_ENABLED   STD_OFF

#if (defined XCP_PRECONDITION_ASSERT_ENABLED)
#error XCP_PRECONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Precondition assertion usage
 **
 ** En- or disables the usage of precondition assertion checks */
#define XCP_PRECONDITION_ASSERT_ENABLED     STD_OFF

#if (defined XCP_POSTCONDITION_ASSERT_ENABLED)
#error XCP_POSTCONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Postcondition assertion usage
 **
 ** En- or disables the usage of postcondition assertion checks */
#define XCP_POSTCONDITION_ASSERT_ENABLED    STD_OFF

#if (defined XCP_UNREACHABLE_CODE_ASSERT_ENABLED)
#error XCP_UNREACHABLE_CODE_ASSERT_ENABLED is already defined
#endif
/** \brief Unreachable code assertion usage
 **
 ** En- or disables the usage of unreachable code assertion checks */
#define XCP_UNREACHABLE_CODE_ASSERT_ENABLED STD_OFF

#if (defined XCP_INVARIANT_ASSERT_ENABLED)
#error XCP_INVARIANT_ASSERT_ENABLED is already defined
#endif
/** \brief Invariant assertion usage
 **
 ** En- or disables the usage of invariant assertion checks */
#define XCP_INVARIANT_ASSERT_ENABLED        STD_OFF

#if (defined XCP_STATIC_ASSERT_ENABLED)
#error XCP_STATIC_ASSERT_ENABLED is already defined
#endif
/** \brief Static assertion usage
 **
 ** En- or disables the usage of static assertion checks */
#define XCP_STATIC_ASSERT_ENABLED           STD_OFF



/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

#endif /* if !defined( XCP_DEFPROG_CFG_H ) */
/*==================[end of file]===========================================*/

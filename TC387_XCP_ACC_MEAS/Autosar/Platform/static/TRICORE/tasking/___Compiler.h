#if (!defined COMPILER_H)
#define COMPILER_H
/* COMPILER047 */
 
/**
 * \file
 *
 * \brief AUTOSAR Platforms
 *
 * This file contains the implementation of the AUTOSAR
 * module Platforms.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
 
/*
 * MISRA-C:2004 Deviations:
 *
 * MISRA-1) Deviated Rule: 19.10 (required)
 * In the definition of a function-like macro each instance of a parameter
 * shall be enclosed in parentheses unless it is used as the operand
 * of # or ##.
 *
 * Reason:
 * The AUTOSAR compiler abstraction requires these definitions in this way
 * and the arguments cannot be enclosed in parentheses due to C syntax.
 */

/*==================[macros]=================================================*/

/* EB: We need to specify compiler symbol before including Compiler_Cfg.h *
 * cause mapping of Infineons' compiler depended won't work otherwise. */

/*------------------[compiler symbol]----------------------------------------*/

/* COMPILER010 */

/** \brief compiler symbol for Tasking compiler for TriCore */
#ifndef _TASKING_C_TRICORE_
#define _TASKING_C_TRICORE_ 1U
#endif

/*==================[inclusions]=============================================*/
 
/* COMPILER052 */
#include <Compiler_Cfg.h> /* module specific memory and pointer classes */
#include <Compiler_Common.h> /* common parts of Compiler.h files */
 
/*==================[macros]=================================================*/

/*------------------[storage classes]----------------------------------------*/
 
#if (defined INLINE)
#error INLINE already defined
#endif
 
/* COMPILER057 */
/** \brief definition of an inline keyword
 **
 ** To be used for inlining functions */
/* EB changed adding inline keywors cause for Infineon MCAL at TC29XT it is mandatory *
 * Tracked in ticket: ASCINFINEON-507 */
#define INLINE inline

#if (defined LOCAL_INLINE)
#error LOCAL_INLINE is already defined
#endif
 
/* COMPILER060 */
/** \brief definition of a keyword for 'static inline' functions
 **
 ** To be used for 'static inline' functions. */
#define LOCAL_INLINE static INLINE
 
/*------------------[macros for functions]-----------------------------------*/
 
#if (defined FUNC)
#error FUNC already defined
#endif
 
/* COMPILER001 */
/** \brief abstraction for function declaration and definition
 **
 ** This macro abstracts the declaration and definition of functions
 ** and ensures the correct syntax of function declaration as
 ** required by the specific compiler.
 **
 ** \param[in] rettype return type of the function
 ** \param[in] memclass classification of the function itself */
/* Deviation MISRA-1 */
#define FUNC(rettype, memclass) rettype
 
#if (defined FUNC_P2CONST)
#error FUNC_P2CONST already defined
#endif
 
/* COMPILER061 */
/** \brief abstraction for function declaration and definition
 **
 ** This macro abstracts the declaration and definition of functions
 ** returning a pointer to a constant and ensures the correct syntax
 ** of function declarations as required by a specific compiler.
 **
 ** \param[in] rettype return type of the function
 ** \param[in] ptrclass defines the classification of the pointers distance
 ** \param[in] memclass classification of the function itself */
/* Deviation MISRA-1 */
#define FUNC_P2CONST(rettype, ptrclass, memclass) rettype const *
 
#if (defined FUNC_P2VAR)
#error FUNC_P2VAR already defined
#endif
 
/* COMPILER063 */
/** \brief abstraction for function declaration and definition
 **
 ** This macro abstracts the declaration and definition of functions
 ** returning a pointer to a variable and ensures the correct syntax
 ** of function declarations as required by a specific compiler.
 **
 ** \param[in] rettype return type of the function
 ** \param[in] ptrclass defines the classification of the pointers distance
 ** \param[in] memclass classification of the function itself */
/* Deviation MISRA-1 */
#define FUNC_P2VAR(rettype, ptrclass, memclass) rettype *
 
/*------------------[macros for pointers]------------------------------------*/
 
#if (defined P2VAR)
#error P2VAR already defined
#endif
 
/* COMPILER006 */
/** \brief abstraction for pointers in RAM pointing to RAM
 **
 ** This macro abstracts the declaration and definition of pointers
 ** in RAM pointing to variables in RAM.
 **
 ** The pointer itself is modifiable.
 ** The pointer's target is modifiable.
 **
 ** \param[in] ptrtype type of the referenced variable
 ** \param[in] memclass classification of the pointer's variable itself
 ** \param[in] defines the classification of the pointer's distance */
/* Deviation MISRA-1 */
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *
 
#if (defined P2CONST)
#error P2CONST already defined
#endif
 
/* COMPILER013 */
/** \brief abstraction for pointers in RAM pointing to ROM
 **
 ** This macro abstracts the declaration and definition of pointers
 ** in RAM pointing to constants in ROM.
 **
 ** The pointer itself is modifiable.
 ** The pointer's target is not modifiable (read only).
 **
 ** \param[in] ptrtype type of the referenced constant
 ** \param[in] memclass classification of the pointer's variable itself
 ** \param[in] defines the classification of the pointer's distance */
/* Deviation MISRA-1 */
#define P2CONST(ptrtype, memclass, ptrclass) ptrtype const *
 
#if (defined CONSTP2VAR)
#error CONSTP2VAR already defined
#endif
 
/* COMPILER031 */
/** \brief abstraction for pointers in ROM pointing to RAM
 **
 ** This macro abstracts the declaration and definition of pointers
 ** in ROM pointing to variables in RAM.
 **
 ** The pointer is not modifiable. (read only).
 ** The pointer's target is modifiable.
 **
 ** \param[in] ptrtype type of the referenced variable
 ** \param[in] memclass classification of the pointer's variable itself
 ** \param[in] defines the classification of the pointer's distance */
/* Deviation MISRA-1 */
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const
 
#if (defined CONSTP2CONST)
#error CONSTP2CONST already defined
#endif
 
/* COMPILER032 */
/** \brief abstraction for pointers in ROM pointing to ROM
 **
 ** This macro abstracts the declaration and definition of pointers
 ** in ROM pointing to constants in ROM.
 **
 ** The pointer itself is not modifiable (read only).
 ** The pointer's target is not modifiable (read only).
 **
 ** \param[in] ptrtype type of the referenced constant
 ** \param[in] memclass classification of the pointer's variable itself
 ** \param[in] defines the classification of the pointer's distance */
/* Deviation MISRA-1 */
#define CONSTP2CONST(ptrtype, memclass, ptrclass) ptrtype const * const
 
/* COMPILER039 */
#if (defined P2FUNC)
#error P2FUNC already defined
#endif
 
/** \brief abstraction for declaration and definition of function pointers
 **
 ** This macro abstracts the declaration and definition of pointers
 ** to functions.
 **
 ** \param[in] rettype return type of the function
 ** \param[in] ptrclass defines the classification of the pointer's distance
 ** \param[in] function name respectively name of the defined type
 ** */
/* Deviation MISRA-1 */
#define P2FUNC(rettype, ptrclass, fctname) rettype (* fctname)

/*------------------[keywords for constants]---------------------------------*/

#if (defined CONST)
#error CONST already defined
#endif

/* COMPILER023 */
/** \brief abstraction for declaration and definition of constants
 **
 ** This macro abstracts the declaration and definition of constants.
 **
 ** \param[in] consttype type of the constant
 ** \param[in] memclass classification of the constant itself */
/* Deviation MISRA-1 */
#define CONST(consttype, memclass) consttype const

/* SWS_COMPILER_00065 */
#if (defined CONSTP2FUNC)
#error CONSTP2FUNC already defined
#endif
 
/** \brief abstraction for declaration and definition of constant function pointers
 **
 ** This macro abstracts the declaration and definition of constant pointers
 ** to functions.
 **
 ** \param[in] rettype return type of the function
 ** \param[in] ptrclass defines the classification of the pointer's distance
 ** \param[in] function name respectively name of the defined type
 ** */
/* Deviation MISRA-1 */
#define CONSTP2FUNC(rettype, ptrclass, fctname) rettype (* const fctname)

/*------------------[keywords for variables]---------------------------------*/
 
/* COMPILER026 */
#if (defined VAR)
#error VAR already defined
#endif
 
/** \brief abstraction for the declaration and definition of variables
 **
 ** This macro abstracts the declaration and definition of variables.
 **
 ** \param[in] vartype type of the variable
 ** \param[in] memclass classification of the variable itself */
/* Deviation MISRA-1 */
#define VAR(vartype, memclass) vartype
 
/*==================[type definitions]=======================================*/
 
/*==================[external function declarations]=========================*/
 
/*==================[internal function declarations]=========================*/
 
/*==================[external constants]=====================================*/
 
/*==================[internal constants]=====================================*/
 
/*==================[external data]==========================================*/
 
/*==================[internal data]==========================================*/
 
/*==================[external function definitions]==========================*/
 
/*==================[internal function definitions]==========================*/
 
/*==================[end of file]============================================*/
#endif /* if !defined( COMPILER_H ) */

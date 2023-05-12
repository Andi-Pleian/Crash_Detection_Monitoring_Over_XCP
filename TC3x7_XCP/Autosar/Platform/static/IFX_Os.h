/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : IFX_Os.h                                                   **
**                                                                            **
**  VERSION      : 1.0.0                                                      **
**                                                                            **
**  DATE         : 2016-10-05                                                 **
**                                                                            **
**  VARIANT      : NA                                                         **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION : Stub header file for OS APIs                                **
**                                                                            **
**  SPECIFICATION(S) :  AUTOSAR Release 4.2.2                                 **
**                                                                            **
**  MAY BE CHANGED BY USER : YES                                              **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
*******************************************************************************/
#ifndef IFX_OS_H
#define IFX_OS_H

#include "Mcal_Compiler.h"
/* 
  Note: Elektrobit Automotive GmbH modified the original code provided
        by the third party supplier. The modification is provided for
        convenience.
        Please use the modification on your discretion and account, or
        use the unmodified files provided with this distribution. 
  Please see for the reasons in the file ImportantNotes.txt for tag
*/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/



/*******************************************************************************
**                      Configuration data                                    **
*******************************************************************************/


/*
 Keyword for Interrupt
*/

#ifndef INTERRUPT
#ifdef _TASKING_C_TRICORE_
  #if (_TASKING_C_TRICORE_ == 1U)
   /*IFX_MISRA_RULE_19_04_STATUS=INTERRUPT cannot be expand to a braced
   initialiser*/
   #define INTERRUPT __interrupt
   #endif
#elif defined _GNU_C_TRICORE_
  #if(_GNU_C_TRICORE_ == 1U)
   #define INTERRUPT __interrupt
    #endif
#elif defined _DIABDATA_C_TRICORE_
  #if (_DIABDATA_C_TRICORE_ == 1U)
   #define INTERRUPT __interrupt__
  #endif
#endif
#endif

/*
Inline qualifier, in case of GNU compiler extern is required
for inline function definition , if residing in header file.
Its not required for TASKING compiler.
Its defined to nothing.
*/

#ifndef _INLINEQUALIFIER_
#define _INLINEQUALIFIER_
#endif

#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
/* Tasking Intrinsic: Disable Global Interrupt Flag */
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the Tricore
intrinsic function*/
#define DISABLE() (__disable())
/* Tasking Intrinsic: Enable Global Interrupt Flag */
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the Tricore
intrinsic function*/
#define ENABLE() (__enable())



/*
 * SYSCALL to generate system call trap
 */
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the Tricore
intrinsic function*/
/*IFX_MISRA_RULE_19_04_STATUS=SYSCALL cannot be expand to a braced
 initialiser*/
 // Can be moved to OS.h
#define SYSCALL(tin)   __syscall(tin)

/*
Tasking Intrinsic: Disable Global Interrupt Flag and return it
*/

/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the Tricore
intrinsic function*/
 // Can be moved to OS.h
#define DISABLE_AND_SAVE() (__disable_and_save())


/*
Tasking Intrinsic: Restore Global Interrupt Flag
*/

/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the Tricore
intrinsic function*/
 // Can be moved to OS.h
#define RESTORE(x) (__restore(x))



#endif
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)

/* Intrinsic: Disable Global Interrupt Flag */
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the Tricore
intrinsic function*/
#define DISABLE() _disable()

/* Intrinsic: Enable Global Interrupt Flag */
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the Tricore
intrinsic function*/
#define ENABLE() _enable()

#define SYSCALL(tin)   _syscall(tin)
#endif
#elif defined _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)

/* Intrinsic: Disable Global Interrupt Flag */
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the Tricore
intrinsic function*/
#define DISABLE() _disable()

/* Intrinsic: Enable Global Interrupt Flag */
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the Tricore
intrinsic function*/
#define ENABLE() _enable()

#define SYSCALL(tin)   _syscall(tin)
#endif
#endif





/*******************************************************************************
** Macro Syntax : __GETTIN(tin)                                               **
**                                                                            **
** Parameters (in) :  None                                                    **
** Parameters (out):  None                                                    **
** return value    : tin : trap number                                        **
** Description    : GETTIN is used to read the trap value from register       **
**                                                                            **
*******************************************************************************/
#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)

/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the get the tin
 function*/
/*IFX_MISRA_RULE_19_04_STATUS=__GETTIN cannot be expand to a braced
 initialiser*/
#define __GETTIN(tin) \
{ \
  __asm("mov %0,d15" : "=d"(tin)); \
}
#endif
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the get the tin
 function*/
/*IFX_MISRA_RULE_19_04_STATUS=__GETTIN cannot be expand to a braced
 initialiser*/

#define __GETTIN(tin) \
{ \
  __asm__ ("mov \t%0,%%d15":"=d" (tin)); \
}
#endif
#elif defined _DIABDATA_C_TRICORE_
#if(_DIABDATA_C_TRICORE_ == 1U)
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the get the tin
 function*/
/*IFX_MISRA_RULE_19_04_STATUS=__GETTIN cannot be expand to a braced
 initialiser*/

#define __GETTIN(tin) \
{ \
  __asm (" mov\t %d2,%d15"); \
  tin = get_res();        \
}

#endif 
/*******************************************************************************
** Macro Syntax : __trap_handler(puiAddress)                                  **
**                                                                            **
** Parameters (in) :  puiAddress : Address of trap handler                    **
** Parameters (out):  None                                                    **
** return value    : None                                                     **
** Description    : __trap_handler is used to call the trap handler           **
**                                                                            **
*******************************************************************************/
#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)

/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the trap handler
 function*/
/*IFX_MISRA_RULE_19_04_STATUS=__trap_handler cannot be expand to a braced
 initialiser*/
#define __trap_handler(puiAddress) \
  { __asm ("ji\t %0\n\trfe": :"a" (puiAddress)); }
#endif
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the trap handler
 function*/
/*IFX_MISRA_RULE_19_04_STATUS=__trap_handler cannot be expand to a braced
 initialiser*/

#define __trap_handler(puiAddress) \
  { __asm ("ji\t %0\n\trfe": :"a" (puiAddress)); }
#endif
#elif defined _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the trap handler
 function*/
/*IFX_MISRA_RULE_19_04_STATUS=__trap_handler cannot be expand to a braced
 initialiser*/

#define __trap_handler(puiAddress) \
{ __asm ("#$$bp"); \
  __asm (" movh.a\t %a15,"#puiAddress"@ha"); \
  __asm (" lea\t %a15,[%a15]"#puiAddress"@l"); \
  __asm (" ji %a15"); \
  __asm (" rfe"); \
  __asm ("#$$ep"); \
}
#endif
#endif 

/*******************************************************************************
** Macro Syntax : __set_trapnum(trapnum)                                      **
**                                                                            **
** Parameters (in) :  trapnum : trap number                                   **
** Parameters (out):  None                                                    **
** return value    : None                                                     **
** Description    : __set_trapnum is used to set the trap number              **
**                                                                            **
*******************************************************************************/
#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)

/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to set the  trap number
 function*/
/*IFX_MISRA_RULE_19_04_STATUS=__set_trapnum cannot be expand to a braced
 initialiser*/
/*IFX_MISRA_RULE_19_13_STATUS=# used only to set the trap number.
There is no impact of order of evaluation with the # operator at this function*/
#define __set_trapnum(trapnum) \
    { __asm(" addi\t d4,d15,#"#trapnum""); }
#endif
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to set the  trap number
 function*/
/*IFX_MISRA_RULE_19_04_STATUS=__set_trapnum cannot be expand to a braced
 initialiser*/
/*IFX_MISRA_RULE_19_13_STATUS=# used only to set the trap number.
There is no impact of order of evaluation with the # operator at this function*/

#define __set_trapnum(trapnum) \
    { __asm(" addi\t %d4,%d15,"#trapnum""); }

#endif
#elif defined _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to set the  trap number
 function*/
/*IFX_MISRA_RULE_19_04_STATUS=__set_trapnum cannot be expand to a braced
 initialiser*/
/*IFX_MISRA_RULE_19_13_STATUS=# used only to set the trap number.
There is no impact of order of evaluation with the # operator at this function*/

#define __set_trapnum(trapnum) \
    { __asm(" addi\t %d4,%d15,"#trapnum""); }

#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif
#endif


#endif /* IFX_OS_H  */

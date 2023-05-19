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
**  FILENAME     : Mcal_Compiler.h                                            **
**                                                                            **
**  VERSION      : 2.0.0                                                      **
**                                                                            **
**  DATE         : 2017-01-09                                                 **
**                                                                            **
**  VARIANT      : NA                                                         **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION : This header file exports Mcal compiler specific             **
                   functions and macros                                       **
**                                                                            **
**  SPECIFICATION(S) : Specification of Compiler Abstraction, AUTOSAR         **
**                     Release 4.2.2                                          **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**  TRACEABILITY : 
*******************************************************************************/
#ifndef MCAL_COMPILER_H
#define MCAL_COMPILER_H

#include "Std_Types.h"
#include "Compiler.h"

/*
  Note: Elektrobit Automotive GmbH modified the original code provided
        by the third party supplier. The modification is provided for
        convenience.
        Please use the modification on your discretion and account, or
        use the unmodified files provided with this distribution. 
  Please see for the reasons in the file ImportantNotes.txt for tag
*/
/*EB add support for WindRiver compiler*/
#if (_DIABDATA_C_TRICORE_ == 1U)
#include "asm.h"
#include "stdarg.h"
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#ifdef _GNU_C_TRICORE_
#include "intrinsics.h"
#endif


/*******************************************************************************
**                      Configuration data                                    **
*******************************************************************************/
typedef unsigned int unsigned_int;

/*
 Keyword for IFX_NO_INLINE
*/
#ifdef _TASKING_C_TRICORE_

#ifndef IFX_NO_INLINE
#define IFX_NO_INLINE __noinline

#endif
/* #ifndef IFX_NO_INLINE */
#endif
/*#ifdef(_TASKING_C_TRICORE_)*/

/*EB add support for WindRiver compiler*/
#ifdef _DIABDATA_C_TRICORE_
#ifndef IFX_INLINE
#define IFX_INLINE       inline
#endif
#ifndef IFX_NO_INLINE
#define IFX_NO_INLINE   __noinline
#endif
#endif

#ifdef _GNU_C_TRICORE_
#ifndef IFX_NO_INLINE

#define IFX_NO_INLINE __attribute__ ((noinline))
#endif
/* #ifndef IFX_NO_INLINE */
#endif
/*#ifdef(_GNU_C_TRICORE_)*/


#ifdef _TASKING_C_TRICORE_
/*
Tasking Intrinsic: Insert ISYNC Instruction
*/
/*MISRA2012_RULE_4_9_JUSTIFICATION:Function like macro used to call the Tricore
intrinsic function*/
#define ISYNC() (__isync())

/*MISRA2012_RULE_4_9_JUSTIFICATION:Function like macro used to call the Tricore
intrinsic function*/
#define DSYNC() (__dsync())


/*
Tasking Intrinsic: move contents of the addressed core SFR into a data register
*/
/*MISRA2012_RULE_4_9_JUSTIFICATION:Function like macro used to call the Tricore
intrinsic function*/
#define MFCR(Reg) (__mfcr((sint32)(Reg)))

/*
Tasking Intrinsic:  Move contents of a data register (Data)
to the addressed core SFR (Reg).
For Tasking compiler,ISYNC is part of __mtcr call, hence not added in the macro
definition
*/
/*MISRA2012_RULE_4_9_JUSTIFICATION:Function like macro used to call the Tricore
intrinsic function*/
#define MTCR(Reg, Data)   DSYNC();\
                          __mtcr((sint32)(Reg), (sint32)(Data))


/* Tasking Intrinsic: No operation */
/*MISRA2012_RULE_4_9_JUSTIFICATION:Function like macro used to call the Tricore
intrinsic function*/
#define NOP() (__nop())


/*
Tasking Intrinsic: CRC32 instruction
*/

/*MISRA2012_RULE_4_9_JUSTIFICATION:Function like macro used to call the Tricore
intrinsic function*/
#define CRC32(b, a) (__crc32((unsigned_int)(b),(unsigned_int)(a)))

#endif
#ifdef _GNU_C_TRICORE_

#define CRC32(b, a) (__crc32((unsigned_int)(b),(unsigned_int)(a)))

/* CRC declaration to ensure this function is always inlined */
static INLINE unsigned __crc32( unsigned b, unsigned a ) \
__attribute__ ((always_inline));

/* Calculate the CRC of register D[a] and the inverse of register D[b] and
put the result in D[res].
The CRC polynomial used is the CRC-32 polynomial as defined in the IEEE 802.3
standard. The initial value of D[b] should be zero
*/
static INLINE unsigned __crc32( unsigned b, unsigned a ) {
  unsigned res;
  /* The operands a and b are interchanged because GNU compiler has
   * used V1.0 D9 2010-11 of Tricore instruction manual. In this manual,
   * crc32 instruction uses crc32 D[c], D[a], D[b] instead of
   * crc32 D[c], D[b], D[a]
   */
  __asm__ volatile("crc32 %0, %2, %1" :"=d"(res) : "d"(b), "d"(a): "memory");
    return res;
}

/*
Hitech Intrinsic: Insert ISYNC Instruction
*/
/*MISRA2012_RULE_4_9_JUSTIFICATION:Function like macro used to call the Tricore
intrinsic function*/
#define ISYNC() _isync()

/*MISRA2012_RULE_4_9_JUSTIFICATION:Function like macro used to call the Tricore
intrinsic function*/
#define DSYNC() _dsync()


/* Intrinsic: : move contents of the addressed core SFR into a data register */
/*MISRA2012_RULE_4_9_JUSTIFICATION:Function like macro used to call the Tricore
intrinsic function*/
#define MFCR(Reg) (__mfcr((Reg)))
/*
Intrinsic:  Move contents of a data register (Data)
to the addressed core SFR (Reg)
*/
/*MISRA2012_RULE_4_9_JUSTIFICATION:Function like macro used to call the Tricore
intrinsic function*/
#define MTCR(Reg, Data)   DSYNC();\
                          __mtcr((Reg), (Data));\
                          ISYNC()

/*********************************************************************
 * MTCR
 **********************************************************************/

/* Intrinsic: No operation */
/*MISRA2012_RULE_4_9_JUSTIFICATION:Function like macro used to call the Tricore
intrinsic function*/
#define NOP() (_nop())
#endif

/*EB add support for WindRiver compiler*/
#ifdef _DIABDATA_C_TRICORE_
#define CRC32(b, a) (__crc32((unsigned_int)(b),(unsigned_int)(a)))
#endif

#ifdef _GNU_C_TRICORE_
#ifndef __indirect
#define __indirect
#endif
#endif

/*******************************************************************************
** Macro Syntax : IMASKLDMST(Address, Value, Offset, Bits)                    **
**                                                                            **
** Parameters (in) :  Address: Address of the Variable to be Modified         **
**                    Value  : Value to be written                            **
**                    Offset : Bit Offset from LSB                            **
**                    Bits   : No of Bits Modified                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Description    : IMASKLDMST is used to write atomic instructions in        **
**                  code.The function writes the number of bits of an integer **
**                  value at a certain address location in memory with a ...  **
**                  bitoffset. The number of bits must be a constant value... **
**                  Note that the Address must be Word Aligned.A direct type  **
**                  cast to "int"is needed to avoid Misra Violation           **
*******************************************************************************/

/*
Use of Atomic Write Intrinsic from Tasking.
*/

/*
The default option provided here:
extended imaskldmst, that helps to execute
ldmst irrespective of variable allocation. NEAR / FAR
boundary.

If the user desires to use TASKING LDMST
the following is the convention.
Caveat: the variable should be placed in
NEAR section.
A direct type cast to "int"
is needed to avoid Misra Violation

#define IMASKLDMST(address,val,offset,bits)  \
  __imaskldmst((sint32*)(address),\
                                 (sint32)(val),     \
                                 (sint32)(offset),  \
                                 (sint32)(bits))

*/
#ifdef _TASKING_C_TRICORE_

/*MISRA2012_RULE_4_9_JUSTIFICATION:Function like macro used to call the Tricore
intrinsic function*/
/*MISRA2012_RULE_20_10_JUSTIFICATION: '#' used only to set the number of bits 
 required for IMASK instruction. There is no impact of order of evaluation with 
 the # operator at this intrinsic function */
#define IMASKLDMST(address,val,offset,bits) \
 __asm("imask e2,%0,%1,#" #bits " \n ldmst [%2]0,e2" \
        : : "d" (val), "d" (offset), "a" (address) : "e2")

#endif
#ifdef _GNU_C_TRICORE_
/*MISRA2012_RULE_4_9_JUSTIFICATION:Function like macro used to call the Tricore
intrinsic function*/
#define IMASKLDMST(address,val,offset,bits) \
                        __imaskldmst(address, val, offset, bits)

/*! \brief Atomic load-modify-store. */

#define __imaskldmst(address, value, bitoffset, bits) \
  {long long tmp;\
  __asm__("imask %A0,%1,%2,%3"\
          :"=d"((long long)tmp)\
          :"d"(value),"d"(bitoffset),"i"(bits): "memory");\
  __asm__("ldmst [%0]0,%A1"::"a"(address),"d"(tmp): "memory");}
#endif
/*
Example:
A variable TESTVAR should be set to value 10 from  bit number 3 to 6.
Case 1:

  uint32 TESTVAR;  assume the variable is located at 0xd0001000
  IMASKLDMST(&TESTVAR,10,3,4);

  This will produce assembly instructions like
    imask e0,#10,#3,#4
  ldmst TESTVAR,e0

Case 2:

  Now if the variable is placed at outside 16K boundary
  uint32 TESTVAR __at(0xd0004000);

  Using IMASKLDMST will result in compile time error.
  So the user should use EXT_IMASKLDMST. The resulting
  assembly will be

  mov16 d15,#10
  movh.a  a15,#@his(TESTVAR)
  mov16 d0,#3
  lea a15,[a15]@los(TESTVAR)
  imask e2,d15,d0,#4
  ldmst [a15]0,e2

*/


/*******************************************************************************
** Macro Syntax : EXTRACT(value,pos,width)                                    **
**                                                                            **
** Parameters (in) :                                                          **
**                    Value  : Value to be extracted                          **
**                    pos : Bit Offset from LSB                               **
**                    Width   : No of Bits to be read                         **
** Parameters (out):  None                                                    **
** return value    : integer (extracted value)                                **
** Description    : EXTRACT is used to read value from a required position    **
**                  for the desired number of bits.                           **
**                  Reads the values in a single instruction when compared    **
**                  mask and loading the same                                 **
*******************************************************************************/
#ifdef _TASKING_C_TRICORE_
/*MISRA2012_RULE_4_9_JUSTIFICATION:Function like macro used to call the Tricore
intrinsic function*/
#define EXTRACT(value,pos,width)            (__extru((sint32)(value), \
                                                    (sint32)(pos), \
                                                    (sint32)(width)))

#endif
#ifdef _GNU_C_TRICORE_

/*MISRA2012_RULE_4_9_JUSTIFICATION:Function like macro used to call the Tricore
intrinsic function*/
#define EXTRACT(value,pos,width)            (_extru((unsigned)(value), \
                                                    (unsigned)(pos), \
                                                    (unsigned)(width)))

/* Same as __extr() but return bit-field as unsigned integer */
static INLINE unsigned _extru(unsigned a, unsigned p, unsigned w) {
  unsigned res;
  __asm__ volatile ("mov %%d14,%2  \n\
                     mov %%d15,%3  \n\
                     extr.u %0,%1,%%e14"
                    : "=d" (res) : "d" (a), "d" (p), "d" (w):"d14","d15");
  return res;
}

#endif

/*******************************************************************************
** Macro Syntax : Mcal_CountLeadingZeros(Variable)                            **
**                                                                            **
** Parameters (in) :  Variable: variable whose leading zero needs to          **
**                              counted.                                      **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Description     : Macro to Count Leading Zeros in a  variable. The tasking **
**                   intrinsic __clz is used for this purpose.                **
**                                                                            **
*******************************************************************************/
#ifdef _TASKING_C_TRICORE_
/*MISRA2012_RULE_4_9_JUSTIFICATION:Function like macro used to call the Tricore
intrinsic function*/
#define Mcal_CountLeadingZeros(Variable) ( __clz((sint32)(Variable)))
#endif
#ifdef _GNU_C_TRICORE_
/*MISRA2012_RULE_4_9_JUSTIFICATION:Function like macro used to call the Tricore
intrinsic function*/
#define Mcal_CountLeadingZeros(Variable) ( __CLZ((sint32)(Variable)))

#endif

/*******************************************************************************
** Macro Syntax : cmpswap_w(unsigned int volatile *address,                   **
**                                unsigned int value, unsigned int condition) **
**                                                                            **
** Parameters (in) : address : ResourceStatusPtr address                      **
**                   value: This variable is updated with status of           **
**                           ResourceStatusPtr                                **
** Parameters (out):  None                                                    **
**                                                                            **
** Description     : This function is a implementation of a binary semaphore  **
**                   using compare and swap instruction                       **
*******************************************************************************/
#ifdef _GNU_C_TRICORE_
static INLINE unsigned int cmpswap_w (unsigned int volatile *address,
           unsigned int value, unsigned int condition)
{
  __extension__ unsigned long long reg64
    = value | (unsigned long long) condition << 32;

  __asm__ __volatile__ ("cmpswap.w [%[addr]]0, %A[reg]"
                        : [reg] "+d" (reg64)
                        : [addr] "a" (address)
                        : "memory");
    return reg64;
}

#endif
/*******************************************************************************
** Macro Syntax : Mcal_CmpAndSwap(ResourceStatusPtr,Value,Compare)            **
**                                                                            **
** Parameters (in) : Value: This variable is updated with status of          **
**                           ResourceStatusPtr                                **
**                   ResourceStatusPtr: This variable is set                  **
** Parameters (out):  None                                                    **
**                                                                            **
** Description     : This function is a implementation of a binary semaphore  **
**                   using compare and swap instruction                       **
*******************************************************************************/
#ifdef _TASKING_C_TRICORE_
/*MISRA2012_RULE_4_9_JUSTIFICATION:Function like macro used to call the Tricore
intrinsic function*/
#define  Mcal_CmpAndSwap(ResourceStatusPtr,Value,Compare) \
     __cmpswapw(((unsigned_int*)(void*)(ResourceStatusPtr)), \
     ((unsigned_int)(Value)), ((unsigned_int)(Compare)) )

#endif
#ifdef _GNU_C_TRICORE_
/*MISRA2012_RULE_4_9_JUSTIFICATION:Function like macro used to call the Tricore
intrinsic function*/
#define  Mcal_CmpAndSwap(ResourceStatusPtr,Value,Compare)  \
        cmpswap_w(((unsigned_int*)(void*)ResourceStatusPtr), \
        ((unsigned_int)Value), ((unsigned_int)Compare) )

#endif

/*EB add support for WindRiver compiler*/
#if (_DIABDATA_C_TRICORE_ == 1U)
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the Tricore
intrinsic function*/
/*IFX_MISRA_RULE_19_04_STATUS=IMASKLDMST cannot be expand to a braced
 initialiser*/

#define  IMASKLDMST(address,val,offset,bits) \
{unsigned long long tmp;\
  tmp = _imaskew( val, offset, bits);\
  _ldmst( address, 0,tmp);\
}

#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */

#if (_DIABDATA_C_TRICORE_ == 1U)

/*
Hitech Intrinsic: Insert ISYNC Instruction
*/
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the Tricore
intrinsic function*/
#define ISYNC() __isync()

/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the Tricore
intrinsic function*/
#define DSYNC() __dsync()
/* Intrinsic: Disable Global Interrupt Flag */
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the Tricore
intrinsic function*/

/* Intrinsic: Enable Global Interrupt Flag */
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the Tricore
intrinsic function*/

#define NOP() _nop()

#define __dsync _dsync
#define __isync _isync
#define __mtcr _mtcr
#define __mfcr _mfcr
#define __abs _abs

#define MFCR(Reg) (__mfcr((Reg)))

#define MTCR(Reg, Data)   DSYNC();\
                          __mtcr((Reg), (Data));\
                          ISYNC()

#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */

#if (_DIABDATA_C_TRICORE_ == 1U)
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the Tricore
intrinsic function*/
#define EXTRACT(value,pos,width)            (_extru((unsigned)(value), \
                                                    (unsigned)(pos), \
                                                    (unsigned)(width)))

#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#if (_DIABDATA_C_TRICORE_ == 1U)
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the Tricore
intrinsic function*/
#if 0
asm volatile unsigned int IFX_INLINE Mcal_CmpAndSwap(
   unsigned int *ResourceStatusPtr, unsigned long RetVal, unsigned long CmpVal)
{
%reg RetVal,ResourceStatusPtr,CmpVal;
!"%d2","%d3"
  mov %d2,RetVal
  mov %d3,CmpVal
  cmpswap.w [ResourceStatusPtr]0,%e2
  mov RetVal,%d2
}

/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to call the Tricore
intrinsic function*/
/* function to calcute the crc values based on passed parameters  */
asm volatile unsigned IFX_INLINE __crc32( unsigned  b, unsigned  a)
{
%reg b,a;
!"%d2","%d3"
  mov %d2,b
  mov %d3,a
  crc32 %d2,%d2,%d3
}
#endif

#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif /* MCAL_COMPILER_H  */

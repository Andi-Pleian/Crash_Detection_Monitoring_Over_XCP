///**
// * \file
// *
// * \brief AUTOSAR Platforms
// *
// * This file contains the implementation of the AUTOSAR
// * module Platforms.
// *
// * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
// *
// * Copyright 2005 - 2017 Elektrobit Automotive GmbH
// * All rights exclusively reserved for Elektrobit Automotive GmbH,
// * unless expressly agreed to otherwise.
// */
//
//#if (!defined TSPLATFORMS_H)
//#define TSPLATFORMS_H
//
///*==================[inclusions]=============================================*/
//
//#include <Std_Types.h> /* AUTOSAR standard types */
//
//#ifdef OS_KERNEL_TYPE
//#include <Os.h>        /* OS interrupt services */
//#endif
//
//#ifdef _GNU_C_TRICORE_
//#include <intrinsics.h>
//#endif
//
///*==================[type definitions]=======================================*/
//
///** \brief Type used to store the interrupt status */
//typedef uint32 TS_IntStatusType;
//
///*==================[macros]=================================================*/
//
///*------------------[derivate names]----------------------------------------*/
//
//#define TS_TC10GP     1
//#define TS_TC1775     2
//#define TS_TC1775B    3
//#define TS_TC1766     4
//#define TS_TC1796     5
//#define TS_TC1797     6
//#define TS_TC1767     7
//#define TS_TC1387     8
//#define TS_TC1782     9
//#define TS_TC1798     10
//#define TS_TC1791     11
//#define TS_TC1793     12
//#define TS_TC27XFPGA  13
//#define TS_TC2D5      14
//#define TS_TC277      15
//#define TS_TC275      16
//#define TS_TC1784     17
//#define TS_TC26XD     19
//#define TS_TC23XL     22
//#define TS_TC29XT     23
//#define TS_TC22XL     24
//#define TS_TC39XX     26
//
///*------------------[core architecture]----------------------------------------*/
///* because we cannot assume the presence of the OS, and the AutoCore build environment
// * does not seem to provide it, we need to determine the architecture ourselves from
// * the TS_ARCH_DERIVATE setting.
// */
//#if   /* TC 1.6EP cores (Aurix) */ \
//	(TS_ARCH_DERIVATE)==(TS_TC2D5)     || \
//	(TS_ARCH_DERIVATE)==(TS_TC27XFPGA) || \
//	(TS_ARCH_DERIVATE)==(TS_TC277)     || \
//	(TS_ARCH_DERIVATE)==(TS_TC275)     || \
//	(TS_ARCH_DERIVATE)==(TS_TC26XD)    || \
//    (TS_ARCH_DERIVATE)==(TS_TC29XT)    || \
//    (TS_ARCH_DERIVATE)==(TS_TC23XL)    || \
//    (TS_ARCH_DERIVATE)==(TS_TC22XL)
//
//#define TS_TC_CORE_ARCHITECTURE 161u
//
//#elif /* TC 1.6.2 cores */ \
//(TS_ARCH_DERIVATE)==(TS_TC39XX)
//
//#define TS_TC_CORE_ARCHITECTURE 162u
//
//#elif /* TC 1.6 cores */ \
//	(TS_ARCH_DERIVATE)==(TS_TC1791) || \
//	(TS_ARCH_DERIVATE)==(TS_TC1793) || \
//	(TS_ARCH_DERIVATE)==(TS_TC1798)
//
//#define TS_TC_CORE_ARCHITECTURE 160u
//
//#else /* fallback to TC 1.3 */
//#define TS_TC_CORE_ARCHITECTURE 130u
//
//#endif
//
///* The offset of the Tricore CSFRs that we use here.
//*/
//#define TS_PSW 0xfe04
//#define TS_PSW_MASK_IO    0xc00u  /* bitmask for the PSW.IO bits */
//#define TS_PSW_MASK_IO_U0 0x000u  /* bitmask value for the PSW.IO == User0 mode */
//
//#define TS_ICR 0xfe2c
//#define TS_ICR_CCPN		  0xffu	/* Current CPU priority number. */
//
//#if TS_TC_CORE_ARCHITECTURE >= 161u
//#define TS_ICR_MASK_IE   0x8000u  /* bitmask for the ICR.IE bit */
//#else
//#define TS_ICR_MASK_IE    0x100u  /* bitmask for the ICR.IE bit */
//#endif
//
///* abstraction of compiler intrinsics */
//#ifdef _GNU_C_TRICORE_
//#define TS_TOOL_INLINE        __inline__                     /* accepted in C90 mode */
//#define TS_TOOL_INLINE_ATTR   __attribute__((always_inline)) /* inline even with -O0 */
//
///* cannot use the _mfcr() intrinsic because it uses a block construct that
// * raises compiler warnings in ISO C90 mode
// */
//#define TS_MFCR(sysreg, out) \
//	__asm__ __volatile__ ("mfcr %0, %1" : "=d" (out) : "i" (sysreg) : )
//#define TS_ISYNC()            _isync()
//
//#define TS_DISABLE()          _disable()
//#define TS_ENABLE()           _enable()
//
//#if TS_TC_CORE_ARCHITECTURE >= 160u
//#define TS_DISABLE_AND_SAVE(prevstat) \
//    __asm__ __volatile__ ("disable %0" : "=d" (prevstat) : : "memory")
//#define TS_RESTORE(prevstat) \
//    __asm__ __volatile__ ("restore %0" : : "d" (prevstat) : "memory")
//#endif
//
//#elif defined(_TASKING_C_TRICORE_)
//#define TS_TOOL_INLINE        inline
//#define TS_TOOL_INLINE_ATTR
//#define TS_MFCR(sysreg,out)   ((out) = ((uint32) __mfcr(sysreg)))
//#define TS_ISYNC()            __isync()
//
//#define TS_DISABLE()          __disable()
//#define TS_ENABLE()           __enable()
//
//#if TS_TC_CORE_ARCHITECTURE >= 160u
//#define TS_RESTORE(s)         __restore(s)
//#define TS_DISABLE_AND_SAVE(prevstat) \
//  (prevstat) = (TS_IntStatusType) __disable_and_save()
//#endif
//
//
//#elif defined(_DIABDATA_C_TRICORE_)
//#define TS_TOOL_INLINE        __inline__
//#define TS_TOOL_INLINE_ATTR   __attribute__((always_inline))
//
//#define TS_MFCR(sysreg, out) \
//	do { \
//		(out) = TS_MFCR_ ##sysreg(); \
//	} while (0)
//
//__asm volatile uint32 TS_MFCR_TS_PSW(void)
//{
//! "%d2"
//	mfcr %d2, TS_PSW
//}
//
//__asm volatile uint32 TS_MFCR_TS_ICR(void)
//{
//! "%d2"
//	mfcr %d2, TS_ICR
//}
//
//__asm volatile void TS_ISYNC(void)
//{
//!
//	isync
//}
//
//__asm volatile void TS_DISABLE(void)
//{
//!
//	disable
//}
//
//__asm volatile void TS_ENABLE(void)
//{
//!
//	enable
//}
//
//#if TS_TC_CORE_ARCHITECTURE >= 160u
//__asm volatile void TS_RESTORE(uint32 prevstat)
//{
//%reg prevstat
//!
//	restore prevstat
//}
//
//#define TS_DISABLE_AND_SAVE(prevstat) \
//	do { \
//		(prevstat) = TsDisableAndSave(); \
//	} while (0)
//
//__asm volatile uint32 TsDisableAndSave(void)
//{
//! "%d2"
//	.word 0x03c0020d
//}
//
//
//#endif
//#else
//#error "Unsupported toolchain. Add support for your toolchain to TSPlatforms.h!"
//
//#endif /* abstraction of compiler intrinsics */
//
//#ifndef EB_STATIC_CHECK
//
///*------------------[TS_AtomicSetBit_8]-------------------------------------*/
//
///** \brief Set one bit of a 8 bit variable
// **
// ** This macro sets the bit \p Bit in the variable referenced
// ** by \p Address.
// ** It is an atomic load-and-store operation, in that software cannot
// ** interrupt between the load and the store and make modifications
// ** to the variable which would have be discarded by the store.
// **
// ** \pre \p Address shall be a valid pointer
// ** \pre \p Address shall point to a modifiable location
// ** \pre \p Bit shall have a value between 0 and 7
// **
// ** \param[in]  Bit     the bit to set, range: 0 .. 7
// ** \param[out] Address constant pointer to the variable to change */
//#define TS_AtomicSetBit_8(Address, Bit) \
//  do { \
//    uint32 *addr_word = (uint32*) (((uint32)(Address)) & (~3u)); \
//    uint32 bit_within_word = ((((uint32)(Address)) & 3u)*8u) + (Bit); \
//    TS_AtomicSetBit_32(addr_word, bit_within_word); \
//  } while(0)
//
///*------------------[TS_AtomicSetBit_16]-------------------------------------*/
//
///** \brief Set one bit of a 16 bit variable
// **
// ** This macro sets the bit \p Bit in the variable referenced
// ** by \p Address.
// ** It is an atomic load-and-store operation, in that software cannot
// ** interrupt between the load and the store and make modifications
// ** to the variable which would have be discarded by the store.
// **
// ** \pre \p Address shall be a valid pointer
// ** \pre \p Address shall point to a modifiable location
// ** \pre \p Address shall be 2-byte aligned
// ** \pre \p Bit shall have a value between 0 and 15
// **
// ** \param[in]  Bit     the bit to set, range: 0 .. 15
// ** \param[out] Address constant pointer to the variable to change */
//#define TS_AtomicSetBit_16(Address, Bit) \
//  TS_AtomicSetBit_8((uint8*)(Address), (Bit))
//
///*------------------[TS_AtomicSetBit_32]-------------------------------------*/
//
///** \brief Set one bit of a 32 bit variable
// **
// ** This macro sets the bit \p Bit in the variable referenced
// ** by \p Address.
// ** It is an atomic load-and-store operation, in that software cannot
// ** interrupt between the load and the store and make modifications
// ** to the variable which would have be discarded by the store.
// **
// ** \pre \p Address shall be a valid pointer
// ** \pre \p Address shall point to a modifiable location
// ** \pre \p Address shall be 4-byte aligned
// ** \pre \p Bit shall have a value between 0 and 31
// **
// ** \param[in]  Bit     the bit to set, range: 0 .. 31
// ** \param[out] Address constant pointer to the variable to change */
//
//#ifdef _GNU_C_TRICORE_
//#define TS_AtomicSetBit_32(Address, Bit)                        \
//  TS_AtomicSetBit_32_Asm(Address, Bit)
//
//static TS_TOOL_INLINE void TS_AtomicSetBit_32_Asm(uint32 *addr, uint32 bitidx) TS_TOOL_INLINE_ATTR;
//static TS_TOOL_INLINE void TS_AtomicSetBit_32_Asm(uint32 *addr, uint32 bitidx)
//{
//  __asm__ __volatile__ (
//      "imask  %%e2,    1, %2, 1 \n\t"
//      "ldmst [%0]0, %%e2"
//      : "=a" (addr)              /* output */
//      : "0" (addr), "d" (bitidx) /* input */
//      : "d2", "d3", "memory"     /* clobber */
//  );
//}
//#elif defined(_TASKING_C_TRICORE_)
//#define TS_AtomicSetBit_32(Address, Bit) \
//  __putbit(1u, ((int*)(Address)), (Bit)) /* maps to imask + ldmst */
//
//#elif defined(_DIABDATA_C_TRICORE_)
//
//__asm volatile void TS_ArchAtomicModifyFlagImpl(volatile void *address, uint32 value, uint32 mask)
//{
//%reg address, value, mask;
//! "%d4", "%d5"
//	mov		%d4, value
//	mov		%d5, mask
//	ldmst	[address]0, %e4
//}
//
//#define TS_AtomicSetBit_32(Address, Bit)                        \
//  TS_AtomicSetBit_32_Asm(Address, Bit)
//
//static TS_TOOL_INLINE void TS_AtomicSetBit_32_Asm(volatile uint32 *addr, uint32 bitidx) TS_TOOL_INLINE_ATTR;
//static TS_TOOL_INLINE void TS_AtomicSetBit_32_Asm(volatile uint32 *addr, uint32 bitidx)
//{
//	uint32 bitset = 1u << bitidx;
//	TS_ArchAtomicModifyFlagImpl(addr, bitset, bitset);
//}
//#endif
//
///*------------------[TS_AtomicClearBit_8]-----------------------------------*/
//
///** \brief Clear one bit of a 8 bit variable
// **
// ** This macro clears the bit \p Bit in the variable referenced
// ** by \p Address.
// ** It is an atomic load-and-store operation, in that software cannot
// ** interrupt between the load and the store and make modifications
// ** to the variable which would have be discarded by the store.
// **
// ** \pre \p Address shall be a valid pointer
// ** \pre \p Address shall point to a modifiable location
// ** \pre \p Bit shall have a value between 0 and 7
// **
// ** \param[in]  Bit     the bit to clear, range: 0 .. 7
// ** \param[out] Address constant pointer to the variable to change */
//#define TS_AtomicClearBit_8(Address, Bit) \
//  do { \
//    uint32 *addr_word = (uint32*) (((uint32)(Address)) & (~3u)); \
//    uint32 bit_within_word = ((((uint32)(Address)) & 3u)*8u) + (Bit); \
//    TS_AtomicClearBit_32(addr_word, bit_within_word); \
//  } while(0)
//
///*------------------[TS_AtomicClearBit_16]-----------------------------------*/
//
///** \brief Clear one bit of a 16 bit variable
// **
// ** This macro clears the bit \p Bit in the variable referenced
// ** by \p Address.
// ** It is an atomic load-and-store operation, in that software cannot
// ** interrupt between the load and the store and make modifications
// ** to the variable which would have be discarded by the store.
// **
// ** \pre \p Address shall be a valid pointer
// ** \pre \p Address shall point to a modifiable location
// ** \pre \p Address shall be 2-byte aligned
// ** \pre \p Bit shall have a value between 0 and 15
// **
// ** \param[in]  Bit     the bit to clear, range: 0 .. 15
// ** \param[out] Address constant pointer to the variable to change */
//#define TS_AtomicClearBit_16(Address, Bit) \
//  TS_AtomicClearBit_8((uint8*)(Address), (Bit))
//
///*------------------[TS_AtomicClearBit_32]-----------------------------------*/
//
///** \brief Clear one bit of a 32 bit variable
// **
// ** This macro clears the bit \p Bit in the variable referenced
// ** by \p Address.
// ** It is an atomic load-and-store operation, in that software cannot
// ** interrupt between the load and the store and make modifications
// ** to the variable which would have be discarded by the store.
// **
// ** \pre \p Address shall be a valid pointer
// ** \pre \p Address shall point to a modifiable location
// ** \pre \p Address shall be 4-byte aligned
// ** \pre \p Bit shall have a value between 0 and 31
// **
// ** \param[in]  Bit     the bit to clear, range: 0 .. 31
// ** \param[out] Address constant pointer to the variable to change */
//
//#ifdef _GNU_C_TRICORE_
//
//#define TS_AtomicClearBit_32(Address, Bit) \
//  TS_AtomicClearBit_32_Asm(Address, Bit)
//
//static TS_TOOL_INLINE void TS_AtomicClearBit_32_Asm(uint32 *addr, uint32 bitidx) TS_TOOL_INLINE_ATTR;
//static TS_TOOL_INLINE void TS_AtomicClearBit_32_Asm(uint32 *addr, uint32 bitidx)
//{
//  __asm__ __volatile__ (
//      "imask  %%e2,    0, %2, 1 \n\t"
//      "ldmst [%0]0, %%e2"
//      : "=a" (addr)              /* output */
//      : "0" (addr), "d" (bitidx) /* input */
//      : "d2", "d3", "memory"     /* clobber */
//  );
//}
//#elif defined(_TASKING_C_TRICORE_)
//
//#define TS_AtomicClearBit_32(Address, Bit) \
//  __putbit(0u, ((int*)(Address)), (Bit)) /* maps to imask + ldmst */
//
//
//#elif defined(_DIABDATA_C_TRICORE_)
//
//#define TS_AtomicClearBit_32_Asm(Address, Bit)                        \
//  TS_AtomicClearBit_32_Asm(Address, Bit)
//
//static TS_TOOL_INLINE void TS_AtomicClearBit_32_Asm(volatile uint32 *addr, uint32 bitidx) TS_TOOL_INLINE_ATTR;
//static TS_TOOL_INLINE void TS_AtomicClearBit_32_Asm(volatile uint32 *addr, uint32 bitidx)
//{
//	uint32 bitclear = 1u << bitidx;
//	TS_ArchAtomicModifyFlagImpl(addr, 0, bitclear);
//}
//#endif
//
//#endif /* (defined EB_STATIC_CHECK) */
//
///*------------------[TS_IntDisable]-----------------------------------------*/
//
//#if (defined TS_IntDisable) /* guard to prevent double definition */
//#error "TS_IntDisable already defined"
//#endif /* if (defined TS_IntDisable) */
//
//#if defined (EB_STATIC_CHECK)
///* use a arbitrary value for expanding the macro TS_IntDisable
// * in case it is disabled */
//#define TS_IntDisable()     42
//
//#else /* !defined (EB_STATIC_CHECK) */
//
///** \brief Disables interrupts and returns previous state.
// **
// ** This macro disables all interrupts by clearing the IE flag in the
// ** interrupt control register (ICR), using the DISABLE instruction.
// ** The previous contents of the ICR are returned. */
//
//#define TS_IntDisable() TS_IntDisableInline()
//static TS_TOOL_INLINE TS_IntStatusType TS_IntDisableInline(void) TS_TOOL_INLINE_ATTR;
//
//static TS_TOOL_INLINE TS_IntStatusType TS_IntDisableInline(void)
//{
//  uint32 psw;
//  TS_IntStatusType ret = 0;
//
//  TS_MFCR(TS_PSW, psw);
//
//  if((psw & TS_PSW_MASK_IO) == TS_PSW_MASK_IO_U0)
//  {
//    /* User-0 mode, use OS services */
//#ifdef OS_KERNEL_TYPE
//    SuspendAllInterrupts();
//#else
//    /* We cannot disable the interrupts of a User-0 control flow without OS
//     * support. Add the appropriate call for your OS here
//     */
//    while(1) { }
//#endif
//  }
//  else
//  {
//#if TS_TC_CORE_ARCHITECTURE >= 160u
//    /* User-1 or supervisor, use disable/restore */
//    TS_DISABLE_AND_SAVE(ret);
//#else
//    TS_MFCR(TS_ICR, ret);
//    ret &= TS_ICR_MASK_IE;
//    TS_DISABLE();
//#endif
//
//    TS_ISYNC();
//  }
//
//  return ret;
//}
//
//#endif /* !defined (EB_STATIC_CHECK) */
//
///*------------------[TS_IntRestore]-----------------------------------------*/
//
//#if (defined TS_IntRestore) /* guard to prevent double definition */
//#error "TS_IntRestore already defined"
//#endif /* if (defined TS_IntRestore) */
//
//#if defined (EB_STATIC_CHECK)
//#define TS_IntRestore(s)
//#else /* !defined (EB_STATIC_CHECK) */
//
///** \brief Restores interrupt lock state
// **
// ** This macro restores the interrupt locking status to a state
// ** returned by a previous call to TS_IntDisable().
// **/
//#define TS_IntRestore(s) TS_IntRestoreInline(s)
//static TS_TOOL_INLINE void TS_IntRestoreInline(TS_IntStatusType s) TS_TOOL_INLINE_ATTR;
//static TS_TOOL_INLINE void TS_IntRestoreInline(TS_IntStatusType s)
//{
//  uint32 psw;
//  TS_MFCR(TS_PSW, psw);
//
//  if((psw & TS_PSW_MASK_IO) == TS_PSW_MASK_IO_U0)
//  {
//    /* User-0 mode, use OS services */
//#ifdef OS_KERNEL_TYPE
//    ResumeAllInterrupts();
//#else
//    /* We cannot enable the interrupts of a User-0 control flow without OS
//     * support. Add the appropriate call for your OS here.
//     */
//    while(1) { }
//#endif
//  }
//  else
//  {
//#if TS_TC_CORE_ARCHITECTURE >= 160u
//    /* User-1 or supervisor, use disable/restore */
//    TS_RESTORE(s);
//    TS_ISYNC();
//#else
//    if(s)
//    {
//      TS_ENABLE();
//      TS_ISYNC();
//    }
//#endif
//  }
//}
//
//#endif /* !defined (EB_STATIC_CHECK) */
//
//#endif /* if (!defined TSPLATFORMS_H)*/

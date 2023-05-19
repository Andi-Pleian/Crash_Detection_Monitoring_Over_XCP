#if (!defined TS_AUTOSAR_H)
#define TS_AUTOSAR_H

/**
 * \file
 *
 * \brief AUTOSAR Base
 *
 * This file contains the implementation of the AUTOSAR
 * module Base.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 20.10 (advisory)
 * The # and ## preprocessor operators should not be used.
 *
 * Reason:
 * 1) The operators are used to concatenate the error identifier for TS_STATIC_ASSERT.
 * There is no other way to assemble sensible compiler error messages.
 * 2) The operators are used to add the 'U' or 'UL' suffix to constants
 * which can only be performed using the '##' operator. The ## is required
 * here to prevent premature expansion of the memory class compiler abstraction
 * parameter which results in the call of a macro with an empty argument (in
 * cases where the memory class compiler abstraction is left empty by the
 * integrator).
 *
 */

/*==================[inclusions]=============================================*/

#include <Std_Types.h>     /* Autosar standard data types */
#include <TSAutosar_Cfg.h> /* Non-Autosar platform specific definitions */
/* Common Autosar definitions and common macros are located in TSPlatforms.h,
 * which includes header files with common type definitions
 *
 * Platforms Setting:
 * Non-Autosar platform specific definitions are included by the header file
 * TSPlatforms.h which is located in Platforms. It contains specific macros and functions
 * like TS_IntDisable, TS_IntRestore, TS_AtomicSetBit_8/16/32, TS_AtomicClearBit_8/16/32/64.
 * It is mandatory that the macros TS_IntDisable and TS_IntRestore are provided in Platforms.
 * - TS_IntDisable macro disables all interrupts by setting PRIMASK to 1 and
 *   returns the previous content of PRIMASK.
 * - TS_IntRestore macro restores the interrupt locking status to a state
 *   returned by a previous call to TS_IntDisable().
 * If the macros TS_AtomicSetBit_8/16/32 and TS_AtomicClearBit_8/16/32/64 are not provided
 * in Platforms, then the macros provided in the header file TSAutosar.h will be used.
 * A description of these macros is provided in TSAutosar.h.
 */
//TODO ANDI
#include <TSPlatforms.h>

/*==================[macros]=================================================*/

/*------------------[macros set on the command line]-------------------------*/
//TODO ANDI
#if (!defined TS_ARCH_FAMILY)
//#error TS_ARCH_FAMILY must be defined on the commandline
#endif
//TODO ANDI
#if (!defined TS_ARCH_DERIVATE)
//#error TS_ARCH_DERIVATE must be defined on the commandline
#endif

/*------------------[architecture names]-------------------------------------*/

/** \brief constant for C16X target architecture family */
#define TS_C16X        1U
/** \brief constant for PA target architecture family */
#define TS_PA          2U
/** \brief constant for EXCALIBUR target architecture family */
#define TS_EXCALIBUR   3U
/** \brief constant for F2MC16L target architecture family */
#define TS_F2MC16L     4U
/** \brief constant for MB91 target architecture family */
#define TS_MB91        5U
/** \brief constant for H8 target architecture family */
#define TS_H8          6U
/** \brief constant for HC08 target architecture family */
#define TS_HC08        7U
/** \brief constant for HC12 target architecture family */
#define TS_HC12        8U
/** \brief constant for M32C target architecture family */
#define TS_M32C        9U
/** \brief constant for NEC78K target architecture family */
#define TS_NEC78K     10U
/** \brief constant for S12X target architecture family */
#define TS_S12X       11U
/** \brief constant for SAF7780 target architecture family */
#define TS_SAF7780    12U
/** \brief constant for SH2 target architecture family */
#define TS_SH2        13U
/** \brief constant for ST30 target architecture family */
#define TS_ST30       14U
/** \brief constant for TMS470 target architecture family */
#define TS_TMS470     15U
/** \brief constant for TRICORE target architecture family */
#define TS_TRICORE    16U
/** \brief constant for V850 target architecture family */
#define TS_V850       17U
/** \brief constant for XC16X target architecture family */
#define TS_XC16X      18U
/** \brief constant for WINDOWS target architecture family */
#define TS_WINDOWS    19U
/** \brief constant for XC2000 target architecture family */
#define TS_XC2000     20U
/** \brief constant for R32C target architecture family */
#define TS_R32C       21U
/** \brief constant for MPC551X target architecture family */
#define TS_MPC551X    22U
/** \brief constant for EASYCAN target architecture family */
#define TS_EASYCAN    23U
/** \brief constant for XPC56XX target architecture family */
#define TS_XPC56XX    24U
/** \brief constant for M32R target architecture family */
#define TS_M32R       25U
/** \brief constant for PIC24H target architecture family */
#define TS_PIC24H     26U
/** \brief constant for NIOS2 target architecture family */
#define TS_NIOS2      27U
/** \brief constant for MB96 target architecture family */
#define TS_MB96       28U
/** \brief constant for SH4 target architecture family */
#define TS_SH4        29U
/** \brief constant for EBX1XX target architecture family */
#define TS_EBX1XX     30U
/** \brief constant for ARM target architecture family */
#define TS_ARM        31U
/** \brief constant for FCR4 target architecture family */
#define TS_FCR4       32U
/** \brief constant for PIKEOS target architecture family */
#define TS_PIKEOS     33U
/** \brief constant for S12Z target architecture family */
#define TS_S12Z       34U
/** \brief constant for DSPIC33 target architecture family */
#define TS_DSPIC33    35U
/** \brief constant for LINUX target architecture family */
#define TS_LINUX      36U
/** \brief constant for RH850 target architecture family */
#define TS_RH850      37U
/** \brief constant for RL78 target architecture family */
#define TS_RL78       38U
/** \brief constant for RZ target architecture family */
#define TS_RZ         39U
/** \brief constant for CORTEXM target architecture family */
#define TS_CORTEXM    40U
/** \brief constant for STM8A target architecture family */
#define TS_STM8A      41U
/** \brief constant for TMS320 target architecture family */
#define TS_TMS320     42U
/** \brief constant for ARM64 target architecture family */
#define TS_ARM64      43U

/* Sanity checks for Atomic macros */
#if !( defined(TS_IntDisable) && defined(TS_IntRestore) )
//TODO ANDI
//#error "TSPlatforms.h is not correctly implemented"
#endif

#if (defined TS_PARAM_UNUSED)
#error TS_PARAM_UNUSED already defined
#endif

#if (defined EB_STATIC_CHECK)
/** \brief This macro can be used to avoid compiler warnings
 *
 * It is left empty to not produce a false positive for MISRA 14.2
 */
#define TS_PARAM_UNUSED(x)
#else
/** \brief This macro can be used to avoid compiler warnings */
#define TS_PARAM_UNUSED(x) ((void) (x))
#endif
/*------------------[static assertions]-------------------------------------*/
#if (defined TS_STATIC_ASSERT)
#error TS_STATIC_ASSERT is already defined
#endif
#if (defined TS_STATIC_ASSERT_JOIN)
#error TS_STATIC_ASSERT_JOIN is already defined
#endif
#if (defined TS_STATIC_ASSERT_EVAL)
#error TS_STATIC_ASSERT_EVAL is already defined
#endif

/** \brief internal concatenation helper macro */
/* Deviation MISRAC2012-1 */
#define TS_STATIC_ASSERT_JOIN(msg_id,line) TS_STATIC_ASSERT__##msg_id##__in_line_##line
/** \brief internal parameter evaluation helper macro to serve evaluated tokens to
 *         TS_STATIC_ASSERT_JOIN's ## operators
 */
#define TS_STATIC_ASSERT_EVAL(msg_id,line) TS_STATIC_ASSERT_JOIN(msg_id,line)

/** \brief Report a static assertion (a.k.a. compile-time assert)
 *
 * Use this macro to check a static compile time assertion as
 * part of defensive programming.  With this macro you can check
 * - size of types and size of global variables
 * - alignment of global variables
 * - padding in structures
 *
 * The macro cannot be used for non-static checks involving quantities which
 * cannot be computed at compile time by the compiler.
 *
 * This macro can be used both at global and at local scope, but it should 
 * better be used at function level, right after the local variables, before 
 * the first statement of the scope.
 *
 * Note1: At global scope, there is potential to confuse tools like doxygen,
 * which mistakes it as a function declaration, unless
 * DOXYGEN_EXCLUDE_SYBOLS += TS_STATIC_ASSERT is added to the respective make
 * file. (e.g. asc_MODULE\doc\project\design\Makefile)
 *
 * Note2: You have to use a trailing semicolon after TS_STATIC_ASSERT().
 *
 * Examples:
 *
 * Ensure the correct size of a data type:
 * - typedef uint8 Mod_IdHandleType;
 * - TS_STATIC_ASSERT(sizeof(Mod_IdHandleType) == 1U, Incorrect_allocation_size)
 *
 * Ensure correct alignment of the data type (32-bit in this case):
 * - Mod_IdHandleType Mod_GlobalIdHandle;
 * - TS_STATIC_ASSERT((&Mod_GlobalIdHandle & 3U) == 0U, Incorrect_alignment)
 *
 * Technical background: If the \a expr evaluates to false, the macro defines
 * an array type with negative array size.  This is an invalid construct in
 * ANSI C and leads to a compiler error.  The identifier of the type is typically
 * included in the compiler's error message for the user to see.  It includes
 * the string "TS_STATIC_ASSERT", the supplied \a msg_id and also the line
 * number on which the macro TS_STATIC_ASSERT() is placed.
 * From this information the user can infer which static assert failed.
 *
 * \param[in] expr     The assertion expression
 * \param[in] msg_id   The error message. It is used as part of an identifier
 *                     that is shown in the compiler error message.
 */

#define TS_STATIC_ASSERT(expr, msg_id) \
  typedef uint8 TS_STATIC_ASSERT_EVAL(msg_id,__LINE__) [(expr) ? 1 : -1]

/* if a translation unit includes multiple C-Files, it will set this macro to STD_ON */
#ifndef TS_MERGED_COMPILE

/** \brief All source files are built separately by default */
#define TS_MERGED_COMPILE STD_OFF

#endif /* TS_MERGED_COMPILE */

#if (TS_MERGED_COMPILE == STD_ON)

/** \brief Use internal linkage of function declarations, if merged, fast build is used */
#define TS_MOD_PRIV_DECL static
/** \brief Use internal linkage of function definitions, if merged, fast build is used */
#define TS_MOD_PRIV_DEFN static

#else /* TS_MERGED_COMPILE */

/** \brief Use external linkage of function declarations, if normal build is used */
#define TS_MOD_PRIV_DECL extern
/** \brief Use external linkage of function declarations, if normal build is used */
#define TS_MOD_PRIV_DEFN

#endif /* TS_MERGED_COMPILE */

#if (defined TS_VENDOR_ID_3SOFT)
#error TS_VENDOR_ID_3SOFT already defined
#endif

/** \brief definition of the unique vendor ID
 *
 * This vendor ID is based on the vendor ID published by the HIS.
 * It should be used for each module
 */
#define TS_VENDOR_ID_3SOFT 1U

#if (defined TS_VENDOR_ID_EB)
#error TS_VENDOR_ID_EB already defined
#endif

/** \brief map vendor ID of EB to 3SOFT */
#define TS_VENDOR_ID_EB TS_VENDOR_ID_3SOFT

#if (defined TS_PROD_ERR_REP_TO_DEM)
#error TS_PROD_ERR_REP_TO_DEM already defined
#endif

/** \brief definition of production error reporting defines - report to Dem
 *
 * The production error reporting could be configured to Dem, Det and off.
 * TS_PROD_ERR_REP_TO_DEM is used if the production error is reported
 * towards the Dem.
 */
#define TS_PROD_ERR_REP_TO_DEM 0U

#if (defined TS_PROD_ERR_REP_TO_DET)
#error TS_PROD_ERR_REP_TO_DET already defined
#endif

/** \brief definition of production error reporting defines - report to Det
 *
 * The production error reporting could be configured to Dem, Det and off.
 * TS_PROD_ERR_REP_TO_DET is used if the production error is reported
 * towards the Det.
 */
#define TS_PROD_ERR_REP_TO_DET 1U

#if (defined TS_PROD_ERR_DISABLE)
#error TS_PROD_ERR_DISABLE already defined
#endif

/** \brief definition of production error reporting defines - off
 *
 * The production error reporting could be configured to Dem, Det and off.
 * TS_PROD_ERR_DISABLE is used if the production error reporting is
 * switched off.
 */
#define TS_PROD_ERR_DISABLE 2U

/*------------------[UINTX_C macros]-----------------------------------------*/

#if (!defined UINT8_C)
/* Deviation MISRAC2012-1 <+2> */
/** \brief Macro to define a constant of type uint8 */
#define UINT8_C(x) ((uint8) x ## U)
#endif

#if (!defined UINT16_C)
/* Deviation MISRAC2012-1 <+2> */
/** \brief Macro to define a constant of type uint16 */
#define UINT16_C(x) ((uint16) x ## U)
#endif

#if (!defined UINT32_C)
/* Deviation MISRAC2012-1 <+2> */
/** \brief Macro to define a constant of type uint32 */
#define UINT32_C(x) (x ## UL)
#endif

#if (!defined SINT8_C)
/** \brief Macro to define a constant of type sint8 */
#define SINT8_C(x) ((sint8)(x))
#endif

#if (!defined SINT16_C)
/** \brief Macro to define a constant of type sint16 */
#define SINT16_C(x) ((sint16)(x))
#endif

#if (!defined SINT32_C)
/* Deviation MISRAC2012-1 <+2> */
/** \brief Macro to define a constant of type sint32 */
#define SINT32_C(x) (x ## L)
#endif

#if (defined HAS_64BIT_TYPES)
#if (!defined SINT64_C)
/* Deviation MISRAC2012-1 <+2> */
/** \brief Macro to define a constant of type sint64 */
#define SINT64_C(x) (x ## LL)
#endif

#if (!defined UINT64_C)
/* Deviation MISRAC2012-1 <+2> */
/** \brief Macro to define a constant of type uint64 */
#define UINT64_C(x) (x ## ULL)
#endif
#endif /* if (defined HAS_64BIT_TYPES) */

#if (!defined BOOLEAN_C)
/* Deviation MISRAC2012-1 <+2> */
/** \brief Macro to define a constant of type boolean */
#define BOOLEAN_C(x) ((boolean) x ## U)
#endif

/*------------------[Bit library macros]-------------------------------------*/

/*------------------[TS_IsBitSet]--------------------------------------------*/
#if (!defined TS_IsBitSet)

/** \brief Check if a bit is set in a variable of type \p OpType
 *
 * This functions returns non-zero if the bit number \p Bit from
 * the variable of type \p OpType pointed to by \p Address is set.
 *
 * The parameter \p OpType can either be \p uint8, \p uint16
 * or \p uint32.
 *
 * \pre \p Address shall be a valid pointer
 * \pre \p Address shall point to an object of type \p OpType
 * \pre depending on the value of \p OpType, the parameter \p Bit
 *   shall have the following range:
 *   \p uint8: 0..7, \p uint16: 0..15, \p uint32: 0..31
 * \pre \p OpType shall be one of \p uint8, \p uint16 or \p uint32
 *
 * \param[in]  Address pointer to the variable of type \p OpType
 * \param[in]  Bit     number of the bit to extract
 * \param[in]  OpType  type of this whole operation
 *
 * \remarks The parameters of this macro may be used in any way, especially
 *   they can be used more than once. They shall not contain side effects.
 */
#define TS_IsBitSet(Address,Bit,OpType) \
  ((*(Address) & ((OpType)((OpType)1U<<(Bit)))) != 0U)

#endif

/*------------------[TS_GetBit]----------------------------------------------*/
#if (!defined TS_GetBit)

/** \brief Extracts a bit from a variable of type \p OpType
 *
 * This functions returns the bit number \p Bit from the variable
 * of type \p OpType pointed to by \p Address.
 *
 * The parameter \p OpType can either be \p uint8, \p uint16
 * or \p uint32.
 *
 * \pre \p Address shall be a valid pointer
 * \pre \p Address shall point to an object of type \p OpType
 * \pre depending on the value of \p OpType, the parameter \p Bit
 *   shall have the following range:
 *   \p uint8: 0..7, \p uint16: 0..15, \p uint32: 0..31
 * \pre \p OpType shall be one of \p uint8, \p uint16 or \p uint32
 * \pre \p Result shall be a modifiable variable of type \p OpType.
 *
 * \param[in]  Address pointer to the variable of type \p OpType
 * \param[in]  Bit     number of the bit to extract
 * \param[in]  OpType  type of this whole operation
 * \param[out] Result  variable of type \p OpType to store result
 *
 * \remarks The parameters of this macro may be used in any way, especially
 *   they can be used more than once. They shall not contain side effects.
 */
#define TS_GetBit(Address,Bit,OpType,Result)         \
  ((Result) = (OpType)( ((OpType)( ((OpType)*(Address)) >> (Bit) )) & ((OpType)1u)) )

#endif

/*------------------[TS_GetBitGroup]-----------------------------------------*/
#if (!defined TS_GetBitGroup)
/** \brief Gets the level of a group of bits
 *
 * This macro extracts the level of several consecutive bits indicated
 * by \p Mask and \p Offset from the variable pointed to by \p Address.
 *
 * Preconditions:
 * \pre \p Address shall be a valid pointer
 * \pre \p Address shall point to a variable of type \p OpType
 * \pre \p Mask shall be of type \p OpType
 * \pre Depending on the type of \p OpType, the
 *   parameter \p Offset shall have the following range:
 *   \p uint8: 0..7, \p uint16: 0..15, \p uint32: 0..31
 * \pre \p OpType shall be one of \p uint8, \p uint16 or \p uint32
 * \pre \p Result shall be a modifiable variable of type \p OpType
 *
 * \param[in]  Address pointer to the register to extract the information
 * \param[in]  Mask    describes the consecutive bits, type OpType
 * \param[in]  Offset  describes the bit positions, range: see above
 * \param[in]  OpType  gives the type of the operation
 * \param[out] Result  output parameter holding the result
 *
 * \remarks The parameters of this macro may be used in any way, especially
 *   they can be used more than once. They shall not contain side effects.
 */
#define TS_GetBitGroup(Address,Mask,Offset,OpType,Result) \
  ((Result) = (OpType) (((OpType)(*(Address))) & (OpType)(Mask)) >> (Offset))

#endif

/*------------------[TS_AtomicSetBit_8]-------------------------------------*/
#if (!defined TS_AtomicSetBit_8)

/** \brief Set one bit of a 8 bit variable
 *
 * This macro sets the bit \p Bit in the variable referenced
 * by \p Address.
 * It is an atomic load-and-store operation, in that software cannot
 * interrupt between the load and the store and make modifications
 * to the variable which would have be discarded by the store.
 *
 * CAVEAT : the operation is not atomic where hardware outside the CPU
 * can modify the variable (for example, multicore architecture, DMA,
 * shared bus systems)
 *
 * \pre \p Address shall be a valid pointer
 * \pre \p Address shall point to a modifiable location
 * \pre \p Bit shall have a value between 0 and n-1, where n is the number
 * of bits of the variable referenced by \p Address
 *
 * \param[in]  Bit     the bit to set, range: 0 .. n-1
 * \param[out] Address constant pointer to the variable to change
 */
#define TS_AtomicSetBit_8(Address, Bit)                         \
  do {                                                          \
    TS_IntStatusType TS_AtomicSetBitSave = TS_IntDisable();     \
    *(Address) |= (uint8)(UINT8_C(1) << (Bit));                  \
    TS_IntRestore(TS_AtomicSetBitSave);                         \
  } while (0)

#endif

/*------------------[TS_AtomicSetBit_16]-------------------------------------*/
#if (!defined TS_AtomicSetBit_16)

/** \brief Set one bit of a 16 bit variable
 *
 * This macro sets the bit \p Bit in the variable referenced
 * by \p Address.
 * It is an atomic load-and-store operation, in that software cannot
 * interrupt between the load and the store and make modifications
 * to the variable which would have be discarded by the store.
 *
 * CAVEAT : the operation is not atomic where hardware outside the CPU
 * can modify the variable (for example, multicore architecture, DMA,
 * shared bus systems)
 *
 * \pre \p Address shall be a valid pointer
 * \pre \p Address shall point to a modifiable location
 * \pre \p Bit shall have a value between 0 and n-1, where n is the number
 * of bits of the variable referenced by \p Address
 *
 * \param[in]  Bit     the bit to set, range: 0 .. n-1
 * \param[out] Address constant pointer to the variable to change
 */
#define TS_AtomicSetBit_16(Address, Bit)                        \
  do {                                                          \
    TS_IntStatusType TS_AtomicSetBitSave = TS_IntDisable();     \
    *(Address) |= (uint16)(UINT16_C(1) << (Bit));                \
    TS_IntRestore(TS_AtomicSetBitSave);                         \
  } while (0)

#endif

/*------------------[TS_AtomicSetBit_32]-------------------------------------*/
#if (!defined TS_AtomicSetBit_32)

/** \brief Set one bit of a 32 bit variable
 *
 * This macro sets the bit \p Bit in the variable referenced
 * by \p Address.
 * It is an atomic load-and-store operation, in that software cannot
 * interrupt between the load and the store and make modifications
 * to the variable which would have be discarded by the store.
 *
 * CAVEAT : the operation is not atomic where hardware outside the CPU
 * can modify the variable (for example, multicore architecture, DMA,
 * shared bus systems)
 *
 * \pre \p Address shall be a valid pointer
 * \pre \p Address shall point to a modifiable location
 * \pre \p Bit shall have a value between 0 and n-1, where n is the number
 * of bits of the variable referenced by \p Address
 *
 * \param[in]  Bit     the bit to set, range: 0 .. n-1
 * \param[out] Address constant pointer to the variable to change
 */
#define TS_AtomicSetBit_32(Address, Bit)                        \
  do {                                                          \
    TS_IntStatusType TS_AtomicSetBitSave = TS_IntDisable();     \
    *(Address) |= (uint32)(UINT32_C(1) << (Bit));                \
    TS_IntRestore(TS_AtomicSetBitSave);                         \
  } while (0)

#endif

#if (defined HAS_64BIT_TYPES)
/*------------------[TS_AtomicSetBit_64]-------------------------------------*/
#if (!defined TS_AtomicSetBit_64)

/** \brief Set one bit of a 64 bit variable
 *
 * This macro sets the bit \p Bit in the variable referenced
 * by \p Address.
 * It is an atomic load-and-store operation, in that software cannot
 * interrupt between the load and the store and make modifications
 * to the variable which would have be discarded by the store.
 *
 * CAVEAT : the operation is not atomic where hardware outside the CPU
 * can modify the variable (for example, multicore architecture, DMA,
 * shared bus systems)
 *
 * \pre \p Address shall be a valid pointer
 * \pre \p Address shall point to a modifiable location
 * \pre \p Bit shall have a value between 0 and n-1, where n is the number
 * of bits of the variable referenced by \p Address
 *
 * \param[in]  Bit     the bit to set, range: 0 .. n-1
 * \param[out] Address constant pointer to the variable to change
 */
#define TS_AtomicSetBit_64(Address, Bit)                        \
  do {                                                          \
    TS_IntStatusType TS_AtomicSetBitSave = TS_IntDisable();     \
    *(Address) |= (uint64)(UINT64_C(1) << (Bit));                \
    TS_IntRestore(TS_AtomicSetBitSave);                         \
  } while (0)

#endif /* if (!defined TS_AtomicSetBit_64) */
#endif /* if (defined HAS_64BIT_TYPES) */

/*------------------[TS_AtomicSetBit]----------------------------------------*/
#if (!defined TS_AtomicSetBit)

/** \brief Set one bit of a variable
 *
 * This macro sets the bit \p Bit in the variable referenced
 * by \p Address.
 * It is an atomic load-and-store operation, in that software cannot
 * interrupt between the load and the store and make modifications
 * to the variable which would have be discarded by the store.
 *
 * CAVEAT : the operation is not atomic where hardware outside the CPU
 * can modify the variable (for example, multicore architecture, DMA,
 * shared bus systems)
 *
 * Hint: On some architectures the macro may produce a compiler warning
 * or MISRA violation about unreachable code when used.
 * In order to provide a generic macro handling the
 * clearing/setting of bits in integral data types of different
 * width, the exact width of the data has to be queried and
 * depending on the width the appropriate (possibly optimized)
 * variant of the macro shall be invoked. - Since the data type
 * however is know to the compiler, this results in unreachable
 * code that will be removed by the compiler (which is exactly the
 * desired behavior).
 *
 * \pre \p Address shall be a valid pointer
 * \pre \p Address shall point to a modifiable location
 * \pre \p Bit shall have a value between 0 and n-1, where n is the number
 * of bits of the variable referenced by \p Address
 *
 * \param[in]  Bit     the bit to set, range: 0 .. n-1
 * \param[out] Address constant pointer to the variable to change
 */
#if (defined HAS_64BIT_TYPES)
#define TS_AtomicSetBit(Address, Bit)                                                            \
  do {                                                                                           \
    if (sizeof(*(Address)) == 1U)                                                                \
    {                                                                                            \
      TS_AtomicSetBit_8((volatile P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) (Address), (Bit));    \
    }                                                                                            \
    else if (sizeof(*(Address)) == 2U)                                                           \
    {                                                                                            \
      TS_AtomicSetBit_16((volatile P2VAR(uint16, AUTOMATIC, BASE_APPL_DATA)) (Address), (Bit));  \
    }                                                                                            \
    else if (sizeof(*(Address)) == 4U)                                                           \
    {                                                                                            \
      TS_AtomicSetBit_32((volatile P2VAR(uint32, AUTOMATIC, BASE_APPL_DATA)) (Address), (Bit));  \
    }                                                                                            \
    else                                                                                         \
    {                                                                                            \
      TS_AtomicSetBit_64((volatile P2VAR(uint64, AUTOMATIC, BASE_APPL_DATA)) (Address), (Bit));  \
    }                                                                                            \
  } while (0)
#else
#define TS_AtomicSetBit(Address, Bit)                                                            \
  do {                                                                                           \
    if (sizeof(*(Address)) == 1U)                                                                \
    {                                                                                            \
      TS_AtomicSetBit_8((volatile P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) (Address), (Bit));    \
    }                                                                                            \
    else if (sizeof(*(Address)) == 2U)                                                           \
    {                                                                                            \
      TS_AtomicSetBit_16((volatile P2VAR(uint16, AUTOMATIC, BASE_APPL_DATA)) (Address), (Bit));  \
    }                                                                                            \
    else                                                                                         \
    {                                                                                            \
      TS_AtomicSetBit_32((volatile P2VAR(uint32, AUTOMATIC, BASE_APPL_DATA)) (Address), (Bit));  \
    }                                                                                            \
  } while (0)
#endif /* if (defined HAS_64BIT_TYPES) */
#endif /* if (!defined TS_AtomicSetBit) */

/*------------------[TS_AtomicClearBit_8]------------------------------------*/
#if (!defined TS_AtomicClearBit_8)

/** \brief Clear one bit of a 8 bit variable
 *
 * This macro clears the bit \p Bit in the variable referenced
 * by \p Address.
 * It is an atomic load-and-store operation, in that software cannot
 * interrupt between the load and the store and make modifications
 * to the variable which would have be discarded by the store.
 *
 * CAVEAT: the operation is not atomic where hardware outside the CPU
 * can modify the variable (for example, multicore architecture, DMA,
 * shared bus systems)
 *
 * \pre \p Address shall be a valid pointer
 * \pre \p Address shall point to a modifiable location
 * \pre \p Bit shall have a value between 0 and n-1, where n is the number
 * of bits of the variable referenced by \p Address
 *
 * \param[in]  Bit     the bit to clear, range: 0 .. n-1
 * \param[out] Address constant pointer to the variable to change
 */
#define TS_AtomicClearBit_8(Address, Bit)                       \
  do {                                                          \
    TS_IntStatusType TS_AtomicClearBitSave = TS_IntDisable();   \
    *(Address) &= (uint8) ~((uint8)(UINT8_C(1) << (Bit)));       \
    TS_IntRestore(TS_AtomicClearBitSave);                       \
  } while (0)

#endif

/*------------------[TS_AtomicClearBit_16]-----------------------------------*/
#if (!defined TS_AtomicClearBit_16)

/** \brief Clear one bit of a 16 bit variable
 *
 * This macro clears the bit \p Bit in the variable referenced
 * by \p Address.
 * It is an atomic load-and-store operation, in that software cannot
 * interrupt between the load and the store and make modifications
 * to the variable which would have be discarded by the store.
 *
 * CAVEAT: the operation is not atomic where hardware outside the CPU
 * can modify the variable (for example, multicore architecture, DMA,
 * shared bus systems)
 *
 * \pre \p Address shall be a valid pointer
 * \pre \p Address shall point to a modifiable location
 * \pre \p Bit shall have a value between 0 and n-1, where n is the number
 * of bits of the variable referenced by \p Address
 *
 * \param[in]  Bit     the bit to clear, range: 0 .. n-1
 * \param[out] Address constant pointer to the variable to change
 */
#define TS_AtomicClearBit_16(Address, Bit)                      \
  do {                                                          \
    TS_IntStatusType TS_AtomicClearBitSave = TS_IntDisable();   \
    *(Address) &= (uint16) ~((uint16)(UINT16_C(1) << (Bit)));    \
    TS_IntRestore(TS_AtomicClearBitSave);                       \
  } while (0)

#endif

/*------------------[TS_AtomicClearBit_32]-----------------------------------*/
#if (!defined TS_AtomicClearBit_32)

/** \brief Clear one bit of a 32 bit variable
 *
 * This macro clears the bit \p Bit in the variable referenced
 * by \p Address.
 * It is an atomic load-and-store operation, in that software cannot
 * interrupt between the load and the store and make modifications
 * to the variable which would have be discarded by the store.
 *
 * CAVEAT: the operation is not atomic where hardware outside the CPU
 * can modify the variable (for example, multicore architecture, DMA,
 * shared bus systems)
 *
 * \pre \p Address shall be a valid pointer
 * \pre \p Address shall point to a modifiable location
 * \pre \p Bit shall have a value between 0 and n-1, where n is the number
 * of bits of the variable referenced by \p Address
 *
 * \param[in]  Bit     the bit to clear, range: 0 .. n-1
 * \param[out] Address constant pointer to the variable to change
 */
#define TS_AtomicClearBit_32(Address, Bit)                      \
  do {                                                          \
    TS_IntStatusType TS_AtomicClearBitSave = TS_IntDisable();   \
    *(Address) &= (uint32) ~((uint32)(UINT32_C(1) << (Bit)));    \
    TS_IntRestore(TS_AtomicClearBitSave);                       \
  } while (0)

#endif

#if (defined HAS_64BIT_TYPES)
/*------------------[TS_AtomicClearBit_64]-----------------------------------*/
#if (!defined TS_AtomicClearBit_64)

/** \brief Clear one bit of a 64 bit variable
 *
 * This macro clears the bit \p Bit in the variable referenced
 * by \p Address.
 * It is an atomic load-and-store operation, in that software cannot
 * interrupt between the load and the store and make modifications
 * to the variable which would have be discarded by the store.
 *
 * CAVEAT: the operation is not atomic where hardware outside the CPU
 * can modify the variable (for example, multicore architecture, DMA,
 * shared bus systems)
 *
 * \pre \p Address shall be a valid pointer
 * \pre \p Address shall point to a modifiable location
 * \pre \p Bit shall have a value between 0 and n-1, where n is the number
 * of bits of the variable referenced by \p Address
 *
 * \param[in]  Bit     the bit to clear, range: 0 .. n-1
 * \param[out] Address constant pointer to the variable to change
 */
#define TS_AtomicClearBit_64(Address, Bit)                      \
  do {                                                          \
    TS_IntStatusType TS_AtomicClearBitSave = TS_IntDisable();   \
    *(Address) &= (uint64) ~((uint64)(UINT64_C(1) << (Bit)));    \
    TS_IntRestore(TS_AtomicClearBitSave);                       \
  } while (0)

#endif /* if (!defined TS_AtomicClearBit_64) */
#endif /* if (defined HAS_64BIT_TYPES) */

/*------------------[TS_AtomicClearBit]--------------------------------------*/
#if (!defined TS_AtomicClearBit)

/** \brief Clear one bit of a variable
 *
 * This macro clears the bit \p Bit in the variable referenced
 * by \p Address.
 * It is an atomic load-and-store operation, in that software cannot
 * interrupt between the load and the store and make modifications
 * to the variable which would have be discarded by the store.
 *
 * CAVEAT: the operation is not atomic where hardware outside the CPU
 * can modify the variable (for example, multicore architecture, DMA,
 * shared bus systems)
 *
 * Hint: On some architectures the macro may produce a compiler warning
 * or MISRA violation about unreachable code when used.
 * In order to provide a generic macro handling the
 * clearing/setting of bits in integral data types of different
 * width, the exact width of the data has to be queried and
 * depending on the width the appropriate (possibly optimized)
 * variant of the macro shall be invoked. - Since the data type
 * however is know to the compiler, this results in unreachable
 * code that will be removed by the compiler (which is exactly the
 * desired behavior).
 *
 * \pre \p Address shall be a valid pointer
 * \pre \p Address shall point to a modifiable location
 * \pre \p Bit shall have a value between 0 and n-1, where n is the number
 * of bits of the variable referenced by \p Address
 *
 * \param[in]  Bit     the bit to clear, range: 0 .. n-1
 * \param[out] Address constant pointer to the variable to change
 */
#if (defined HAS_64BIT_TYPES)
#define TS_AtomicClearBit(Address, Bit)                                                            \
  do {                                                                                             \
    if (sizeof(*(Address)) == 1U)                                                                 \
    {                                                                                              \
      TS_AtomicClearBit_8((volatile P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) (Address), (Bit));    \
    }                                                                                              \
    else if (sizeof(*(Address)) == 2U)                                                             \
    {                                                                                              \
      TS_AtomicClearBit_16((volatile P2VAR(uint16, AUTOMATIC, BASE_APPL_DATA)) (Address), (Bit));  \
    }                                                                                              \
    else if (sizeof(*(Address)) == 4U)                                                             \
    {                                                                                              \
      TS_AtomicClearBit_32((volatile P2VAR(uint32, AUTOMATIC, BASE_APPL_DATA)) (Address), (Bit));  \
    }                                                                                              \
    else                                                                                           \
    {                                                                                              \
      TS_AtomicClearBit_64((volatile P2VAR(uint64, AUTOMATIC, BASE_APPL_DATA)) (Address), (Bit));  \
    }                                                                                              \
  } while (0)
#else
#define TS_AtomicClearBit(Address, Bit)                                                            \
  do {                                                                                             \
    if (sizeof(*(Address)) == 1U)                                                                  \
    {                                                                                              \
      TS_AtomicClearBit_8((volatile P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) (Address), (Bit));    \
    }                                                                                              \
    else if (sizeof(*(Address)) == 2U)                                                             \
    {                                                                                              \
      TS_AtomicClearBit_16((volatile P2VAR(uint16, AUTOMATIC, BASE_APPL_DATA)) (Address), (Bit));  \
    }                                                                                              \
    else                                                                                           \
    {                                                                                              \
      TS_AtomicClearBit_32((volatile P2VAR(uint32, AUTOMATIC, BASE_APPL_DATA)) (Address), (Bit));  \
    }                                                                                              \
  } while (0)
#endif /* if (defined HAS_64BIT_TYPES) */
#endif /* if (!defined TS_AtomicClearBit) */

/*------------------[TS_DefMaxAlignedByteArray]------------------------------*/
#if (defined TS_DefMaxAlignedByteArray)
#error TS_DefMaxAlignedByteArray already defined
#endif

/** \brief Define a byte array with maximum alignment
 *
 * This macro defines \p identifier as an array of at least
 * \p numberOfBytes bytes in a way that this array is aligned
 * according to the most stringent alignment requirement of any
 * simple data type available on the respective platform.
 *
 * \pre \p identifier shall be a valid C identifier
 *
 * \param[in]  identifier    C identifier to use for the array definition
 * \param[in] numberOfBytes number of bytes to be provided in the array
 * \param[in] module modules abbreviation in capital letters (e.g., COM, FR_1_EB)
 * \param[in] memclass memory classification (without module abbreviation) for the array
 */
/* Deviation MISRAC2012-1 */
#define TS_DefMaxAlignedByteArray(identifier, module, memclass, numberOfBytes) \
  TS_DefMaxAlignedByteArray_Hlp(identifier, module, _ ## memclass, numberOfBytes)

/** \brief Helper macro for TS_DefMaxAlignedByteArray */
/* Deviation MISRAC2012-1 */
#define TS_DefMaxAlignedByteArray_Hlp(identifier, module, memclass, numberOfBytes) \
  VAR(TS_MaxAlignedType, module ## memclass) \
    identifier[(((numberOfBytes) - 1) + sizeof(TS_MaxAlignedType)) / sizeof(TS_MaxAlignedType)]

#endif /* if (!defined TS_AUTOSAR_H) */

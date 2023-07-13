#if (!defined AUTOSAR_CFG_H)
#define AUTOSAR_CFG_H

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

/*==================[macros]=================================================*/

/*------------------[Macros for Atomic Assignment]---------------------------*/
 
#if (defined TS_AtomicAssign8)
#error TS_AtomicAssign8 already defined
#endif
/** \brief Assigns the 8 bit entity \p from to \p to in an atomic fashion
 *
 * This macro assigns the 8 bit entity \p from to \p to in an atomic fashion
 *
 * The parameters \p from and \p to thus have to be of type \p uint8 or \p sint8.
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].char.AtomicAccess'
 *
 * \param[out] to    8 bit entity which is the destination of the assignment
 * \param[in]  from  8 bit entity which is the source of the assignment
 *
 * \remarks The parameters of this macro may be used in any way, especially
 *   they can be used more than once. They shall not contain side effects.
 */
#define TS_AtomicAssign8(to, from) ((to) = (from))

#if (defined TS_AtomicAssign16)
#error TS_AtomicAssign16 already defined
#endif
/** \brief Assigns the 16 bit entity \p from to \p to in an atomic fashion
 *
 * This macro assigns the 16 bit entity \p from to \p to in an atomic fashion
 *
 * The parameters \p from and \p to thus have to be of type \p uint8 or \p sint8.
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].short.AtomicAccess'
 *
 * \param[out] to    16 bit entity which is the destination of the assignment
 * \param[in]  from  16 bit entity which is the source of the assignment
 *
 * \remarks The parameters of this macro may be used in any way, especially
 *   they can be used more than once. They shall not contain side effects.
 */
#define TS_AtomicAssign16(to, from) ((to) = (from))

#if (defined TS_AtomicAssign32)
#error TS_AtomicAssign32 already defined
#endif
/** \brief Assigns the 32 bit entity \p from to \p to in an atomic fashion
 *
 * This macro assigns the 32 bit entity \p from to \p to in an atomic fashion
 *
 * The parameters \p from and \p to thus have to be of type \p uint8 or \p sint8.
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long.AtomicAccess'
 *
 * \param[out] to    32 bit entity which is the destination of the assignment
 * \param[in]  from  32 bit entity which is the source of the assignment
 *
 * \remarks The parameters of this macro may be used in any way, especially
 *   they can be used more than once. They shall not contain side effects.
 */
#define TS_AtomicAssign32(to, from) ((to) = (from))

/*------------------[Macros for Litte / Big Endian]--------------------------*/

#ifdef TS_IF_BE_LE
  #error already defined: TS_IF_BE_LE
#endif
/** \brief Selector for Big Endian / Little Endian expression variants */
#define TS_IF_BE_LE(BE,LE) LE

/*------------------[Size of Autosar Standard Types]-------------------------*/

#if (defined TS_SIZE_boolean)
#error TS_SIZE_boolean already defined
#endif
/** \brief Size of derived type boolean
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].char.Size'
 */
#define TS_SIZE_boolean  1U

#if (defined TS_SIZE_sint8)
#error TS_SIZE_sint8 already defined
#endif
/** \brief Size of derived type sint8
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].char.Size'
 */
#define TS_SIZE_sint8  1U

#if (defined TS_SIZE_sint16)
#error TS_SIZE_sint16 already defined
#endif
/** \brief Size of derived type sint16
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].short.Size'
 */
#define TS_SIZE_sint16  2U

#if (defined TS_SIZE_sint32)
#error TS_SIZE_sint32 already defined
#endif
/** \brief Size of derived type sint32
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long.Size'
 */
#define TS_SIZE_sint32  4U

#if (defined TS_SIZE_uint8)
#error TS_SIZE_uint8 already defined
#endif
/** \brief Size of derived type uint8
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].char.Size'
 */
#define TS_SIZE_uint8  1U

#if (defined TS_SIZE_uint16)
#error TS_SIZE_uint16 already defined
#endif
/** \brief Size of derived type uint16
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].short.Size'
 */
#define TS_SIZE_uint16  2U

#if (defined TS_SIZE_uint32)
#error TS_SIZE_uint32 already defined
#endif
/** \brief Size of derived type uint32
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long.Size'
 */
#define TS_SIZE_uint32  4U

#if (defined TS_SIZE_sint8_least)
#error TS_SIZE_sint8_least already defined
#endif
/** \brief Size of derived type sint8_least
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long.Size'
 */
#define TS_SIZE_sint8_least  4U

#if (defined TS_SIZE_sint16_least)
#error TS_SIZE_sint16_least already defined
#endif
/** \brief Size of derived type sint16_least
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long.Size'
 */
#define TS_SIZE_sint16_least  4U

#if (defined TS_SIZE_sint32_least)
#error TS_SIZE_sint32_least already defined
#endif
/** \brief Size of derived type sint32_least
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long.Size'
 */
#define TS_SIZE_sint32_least  4U

#if (defined TS_SIZE_uint8_least)
#error TS_SIZE_uint8_least already defined
#endif
/** \brief Size of derived type uint8_least
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long.Size'
 */
#define TS_SIZE_uint8_least  4U

#if (defined TS_SIZE_uint16_least)
#error TS_SIZE_uint16_least already defined
#endif
/** \brief Size of derived type uint16_least
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long.Size'
 */
#define TS_SIZE_uint16_least  4U

#if (defined TS_SIZE_uint32_least)
#error TS_SIZE_uint32_least already defined
#endif
/** \brief Size of derived type uint32_least
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long.Size'
 */
#define TS_SIZE_uint32_least  4U

#if (defined TS_SIZE_float32)
#error TS_SIZE_float32 already defined
#endif
/** \brief Size of derived type float32
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].float.Size'
 */
#define TS_SIZE_float32  4U

#if (defined TS_SIZE_float64)
#error TS_SIZE_float64 already defined
#endif
/** \brief Size of derived type float64
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].float.Size'
 */
#define TS_SIZE_float64  4U

#if (defined TS_SIZE_sint64)
#error TS_SIZE_sint64 already defined
#endif
/** \brief Size of derived type sint64
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long long.Size'
 */
#define TS_SIZE_sint64  8U

#if (defined TS_SIZE_uint64)
#error TS_SIZE_uint64 already defined
#endif
/** \brief Size of derived type uint64
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long long.Size'
 */
#define TS_SIZE_uint64  8U

#if (defined TS_SIZE_TS_MaxAlignedType)
#error TS_SIZE_TS_MaxAlignedType already defined
#endif
/** \brief Size of derived type TS_MaxAlignedType
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].double.Size'
 */
#define TS_SIZE_TS_MaxAlignedType  8U

/*------------------[Alignment Autosar Standard Types]-----------------------*/

#if (defined TS_ALIGNMENT_boolean)
#error TS_ALIGNMENT_boolean already defined
#endif
/** \brief Alignment constraints for derived type boolean
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].char.Alignment'
 */
#define TS_ALIGNMENT_boolean  1U

#if (defined TS_ALIGNMENT_sint8)
#error TS_ALIGNMENT_sint8 already defined
#endif
/** \brief Alignment constraints for derived type sint8
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].char.Alignment'
 */
#define TS_ALIGNMENT_sint8  1U

#if (defined TS_ALIGNMENT_sint16)
#error TS_ALIGNMENT_sint16 already defined
#endif
/** \brief Alignment constraints for derived type sint16
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].short.Alignment'
 */
#define TS_ALIGNMENT_sint16  2U

#if (defined TS_ALIGNMENT_sint32)
#error TS_ALIGNMENT_sint32 already defined
#endif
/** \brief Alignment constraints for derived type sint32
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long.Alignment'
 */
#define TS_ALIGNMENT_sint32  4U

#if (defined TS_ALIGNMENT_uint8)
#error TS_ALIGNMENT_uint8 already defined
#endif
/** \brief Alignment constraints for derived type uint8
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].char.Alignment'
 */
#define TS_ALIGNMENT_uint8  1U

#if (defined TS_ALIGNMENT_uint16)
#error TS_ALIGNMENT_uint16 already defined
#endif
/** \brief Alignment constraints for derived type uint16
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].short.Alignment'
 */
#define TS_ALIGNMENT_uint16  2U

#if (defined TS_ALIGNMENT_uint32)
#error TS_ALIGNMENT_uint32 already defined
#endif
/** \brief Alignment constraints for derived type uint32
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long.Alignment'
 */
#define TS_ALIGNMENT_uint32  4U

#if (defined TS_ALIGNMENT_sint8_least)
#error TS_ALIGNMENT_sint8_least already defined
#endif
/** \brief Alignment constraints for derived type sint8_least
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long.Alignment'
 */
#define TS_ALIGNMENT_sint8_least  4U

#if (defined TS_ALIGNMENT_sint16_least)
#error TS_ALIGNMENT_sint16_least already defined
#endif
/** \brief Alignment constraints for derived type sint16_least
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long.Alignment'
 */
#define TS_ALIGNMENT_sint16_least  4U

#if (defined TS_ALIGNMENT_sint32_least)
#error TS_ALIGNMENT_sint32_least already defined
#endif
/** \brief Alignment constraints for derived type sint32_least
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long.Alignment'
 */
#define TS_ALIGNMENT_sint32_least  4U

#if (defined TS_ALIGNMENT_uint8_least)
#error TS_ALIGNMENT_uint8_least already defined
#endif
/** \brief Alignment constraints for derived type uint8_least
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long.Alignment'
 */
#define TS_ALIGNMENT_uint8_least  4U

#if (defined TS_ALIGNMENT_uint16_least)
#error TS_ALIGNMENT_uint16_least already defined
#endif
/** \brief Alignment constraints for derived type uint16_least
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long.Alignment'
 */
#define TS_ALIGNMENT_uint16_least  4U

#if (defined TS_ALIGNMENT_uint32_least)
#error TS_ALIGNMENT_uint32_least already defined
#endif
/** \brief Alignment constraints for derived type uint32_least
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long.Alignment'
 */
#define TS_ALIGNMENT_uint32_least  4U

#if (defined TS_ALIGNMENT_float32)
#error TS_ALIGNMENT_float32 already defined
#endif
/** \brief Alignment constraints for derived type float32
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].float.Alignment'
 */
#define TS_ALIGNMENT_float32  4U

#if (defined TS_ALIGNMENT_float64)
#error TS_ALIGNMENT_float64 already defined
#endif
/** \brief Alignment constraints for derived type float64
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].float.Alignment'
 */
#define TS_ALIGNMENT_float64  4U

#if (defined TS_ALIGNMENT_sint64)
#error TS_ALIGNMENT_sint64 already defined
#endif
/** \brief Alignment constraints for derived type sint64
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long long.Alignment'
 */
#define TS_ALIGNMENT_sint64  8U

#if (defined TS_ALIGNMENT_uint64)
#error TS_ALIGNMENT_uint64 already defined
#endif
/** \brief Alignment constraints for derived type uint64
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].long long.Alignment'
 */
#define TS_ALIGNMENT_uint64  8U

#if (defined TS_ALIGNMENT_array)
#error TS_ALIGNMENT_array already defined
#endif
/** \brief Default alignment constraint for arrays */
#define TS_ALIGNMENT_array  1U

#if (defined TS_ALIGNMENT_struct)
#error TS_ALIGNMENT_struct already defined
#endif
/** \brief Default alignment constraint for structs */
#define TS_ALIGNMENT_struct  1U

#if (defined TS_ALIGNMENT_TS_MaxAlignedType)
#error TS_ALIGNMENT_TS_MaxAlignedType already defined
#endif
/** \brief Alignment constraints for derived type TS_MaxAlignedType
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].double.Alignment'
 */
#define TS_ALIGNMENT_TS_MaxAlignedType  4U

/*==================[type definitions]======================================*/

/** \brief Type definition of derived type TS_MaxAlignedType
 *
 * Platforms Setting:
 * It is set in Platforms plugin by setting the parameter 'Derivedtypes.TS_MaxAlignedType.Mapping'.
 */
typedef double TS_MaxAlignedType;

#endif /*(!defined AUTOSAR_CFG_H)*/

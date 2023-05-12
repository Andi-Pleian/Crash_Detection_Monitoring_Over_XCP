/* Os_types_TRICORE.h
 *
 * This file defines the basic data types for TRICORE
 *
 * See also: Os_types.h
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_types_TRICORE.h 1.1 2017/12/21 16:35:21CET Postolache, Alexandru (uidu6496) none  $
*/

#ifndef OS_TYPES_TRICORE_H
#define OS_TYPES_TRICORE_H

#if (OS_CPU == OS_TC1791)
#include <TRICORE/TC1791/Os_types_TC1791.h>
#elif (OS_CPU == OS_TC1793)
#include <TRICORE/TC1793/Os_types_TC1793.h>
#elif (OS_CPU == OS_TC1798)
#include <TRICORE/TC1798/Os_types_TC1798.h>
#elif (OS_CPU == OS_TC23XL)
#include <TRICORE/TC23XL/Os_types_TC23XL.h>
#elif (OS_CPU == OS_TC275)
#include <TRICORE/TC275/Os_types_TC275.h>
#elif (OS_CPU == OS_TC22XL)
#include <TRICORE/TC22XL/Os_types_TC22XL.h>
#elif (OS_CPU == OS_TC277)
#include <TRICORE/TC277/Os_types_TC277.h>
#elif (OS_CPU == OS_TC29XT)
#include <TRICORE/TC29XT/Os_types_TC29XT.h>
#elif (OS_CPU == OS_TC26XD)
#include <TRICORE/TC26XD/Os_types_TC26XD.h>
#elif (OS_CPU == OS_TC39XX)
#include <TRICORE/TC39XX/Os_types_TC39XX.h>
#else
#error "Unsupported derivative."
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Architecture data type characteristics
*/
#define OS_ENDIAN		OS_LITTLEENDIAN
#define OS_ARCH_HAS_64BIT	0

/* Sizes for computing struct offsets for assembler
*/
#define OS_SIZEOF_PTR	OS_U(4)
#define OS_SIZEOF_FPTR	OS_SIZEOF_PTR

#ifndef OS_ASM
/* Fixed-length types
*/

typedef unsigned char		os_uint8_t;
typedef signed char			os_int8_t;
typedef unsigned short		os_uint16_t;
typedef signed short		os_int16_t;
typedef unsigned int		os_uint32_t;
typedef signed int			os_int32_t;

/* Types for address/size of memory object
*/
typedef os_uint32_t		os_address_t;
typedef os_int32_t		os_ptrdiff_t;
typedef os_uint32_t		os_size_t;

/* Type for a stack element.
*/
typedef os_uint32_t		os_stackelement_t;

/* Type for a service parameter.
 *
 * An integer type big enough to hold any OS Service parameter.
 * Used for error handling.
*/
typedef os_uint32_t os_paramtype_t;

/*!
 * OS_ARCH_HAS_CHAR_T
 *
 * This architecture has no specific char type. Hence, the common definition is used.
 */
#define OS_ARCH_HAS_CHAR_T 0

#endif /* !OS_ASM */

#define OS_SIZEOF_STACKELEMENT	4

/* os_clzword_t - type of a word for which a CLZ or similar instruction is defined.
*/
#define OS_SIZEOF_CLZWORD	4
#define OS_CLZWORD_NBITS	32
#ifndef OS_ASM
typedef os_uint32_t os_clzword_t;
#endif

/*!
 * os_syncspot_t
 * OS_SYNCSPOT_ALIGNMENT_GRANULE
 *
 * This type defines a 'synchronization spot', which can be used by software
 * for synchronization/locking purposes, e.g. to implement mutual exclusion.
 * The definition of this type accounts for hardware-assisted operation, i.e.
 * alignment and size are appropriate to access instances of which to achieve
 * synchronization/locking.
 */
#define OS_SYNCSPOT_ALIGNMENT_GRANULE 4
#ifndef OS_ASM
typedef volatile os_size_t os_syncspot_t;
#endif

/*!
 * os_sw_syncspot_t
 *
 * This type serves essentially the same purpose as os_syncspot_t,
 * with the exception that hardware-assistance is not a concern.
 * This means, instances of os_sw_syncspot_t just have to guarantee that
 * write accesses are atomic. Concurrent write accesses must be serialized
 * by hardware, whereby the concrete order is undefined.
*/
#ifndef OS_ASM
typedef volatile os_size_t os_sw_syncspot_t;
#endif

#ifdef __cplusplus
}
#endif

#endif /* OS_TYPES_TRICORE_H */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/

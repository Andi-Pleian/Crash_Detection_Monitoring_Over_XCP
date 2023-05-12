/* Os_defs_TRICORE.h - Tricore definitions for derivative selection etc.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_defs_TRICORE.h 1.1 2017/12/21 16:35:19CET Postolache, Alexandru (uidu6496) none  $
*/

#ifndef OS_DEFS_TRICORE_H
#define OS_DEFS_TRICORE_H

/* CPUs. OS_CPU must be one of these.
 *
 * CAVEAT:
 * The existence of a TRICORE derivative in this list does not imply a
 * commitment or intention to support the derivative.
*/
#define OS_TC1798	0x10b
#define OS_TC1791	0x10c
#define OS_TC1793	0x10d

#define OS_TC277	 0x202
#define OS_TC23XL    0x203
#define OS_TC275	 0x204
#define OS_TC29XT	 0x205
#define OS_TC22XL    0x206
#define OS_TC26XD    0x207

#define OS_TC39XX    0x301

/* Architectures of the TriCore family
 * The values used must be suitable for comparing architecture versions
 *
 * Note: architecture versions prior to 1.6E/1.6P are not supported
 */
#define OS_TRICOREARCH_16EP       161  /* Aurix */
#define OS_TRICOREARCH_162        162  /* Aurix 2G */

#endif
/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/

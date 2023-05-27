/* Os_api_TRICORE.h
 *
 * This file is the architecture-dependent public API prototype file for TRICORE
 *
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_api_TRICORE.h 1.1 2017/12/21 16:35:17CET Postolache, Alexandru (uidu6496) none  $
 */
#ifndef OS_API_TRICORE_H
#define OS_API_TRICORE_H

#include <TRICORE/Os_types_TRICORE.h>

/* TRICORE does not support atomic monitor operations
 *
 * !LINKSTO Kernel.Feature.TransactionSupport, 1
*/
#define OS_HAS_TRANSACTION_SUPPORT	0

#ifndef OS_HAS_TB_INTERNAL
#error "OS_HAS_TB_INTERNAL undefined."
#endif

#if OS_HAS_TB_INTERNAL==1
/* STM serves as internal timestamp timer. */
#ifndef OS_ASM
extern void OS_TricoreGetTimestamp(os_timestamp_t *);
#define OS_TB_FUNC	OS_TricoreGetTimestamp
#endif
#endif


#endif /* OS_API_TRICORE_H */


/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
 */

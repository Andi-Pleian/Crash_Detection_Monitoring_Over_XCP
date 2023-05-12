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

#if (!defined BASE_DBG_H )
#define BASE_DBG_H
[!IF "node:exists(as:modconf('Base')[1]/BaseDbg/BaseDbgHeaderFile) = 'true'"!]
/*==================[inclusions]============================================*/

/* !LINKSTO Base.Dbg.Base_Dbg_h,1 */
#include <[!"as:modconf('Base')[1]/BaseDbg/BaseDbgHeaderFile"!]>
[!ENDIF!]
#endif /* (!defined BASE_DBG_H) */
/*==================[end of file]===========================================*/

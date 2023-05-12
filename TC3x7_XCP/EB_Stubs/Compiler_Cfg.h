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
#if !( defined COMPILER_CFG_H )
#define COMPILER_CFG_H

/*==================[inclusions]=============================================*/

/*------------------[Compiler_Cfg extensions]--------------------------------*/

#if ( defined COMPILERCFG_EXTENSION_FILE )
#include <Compiler_CfgExt.h>
#endif /* if ( defined COMPILERCFG_EXTENSION_FILE ) */

#if ( defined COMPILERCFG_EXTENSION_MCAL_FILE )
#include <Compiler_CfgExtMCAL.h>
#endif /* if ( defined COMPILERCFG_EXTENSION_MCAL_FILE ) */

/*==================[macros]=================================================*/

/* mandatory for LinIf test */
#if !( defined LINIF_APPL_CONST )
#define LINIF_APPL_CONST
#endif /* if !( defined LINIF_APPL_CONST ) */

#endif /* if !( defined COMPILER_CFG_H ) */
/*==================[end of file]============================================*/

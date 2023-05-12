#if (!defined ETH_GENERALTYPES_CFG_H)
#define ETH_GENERALTYPES_CFG_H
[!AUTOSPACING!][!//
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

/*==================[inclusions]=============================================*/

#include <Std_Types.h>          /* AUTOSAR standard type definitions */

/*==================[type definitions]=======================================*/

/** \brief Represents the hardware object handles of a ETH hardware buffer.
 *
 * Range:
 *  - uint32 (if configuration parameter 'EthIf/EthIfPublicCfg/EthIfPublicHandleTypeEnum = UINT32')
 *  - uint8  (otherwise)
 */
 /* !LINKSTO Base.Eth.Eth_BufIdxType,1 */
[!IF "node:exists(as:modconf('EthIf')[1]/EthIfGeneral/EthIfPublicHandleTypeEnum) and
      (as:modconf('EthIf')[1]/EthIfGeneral/EthIfPublicHandleTypeEnum = 'UINT32')"!]
typedef uint32 Eth_BufIdxType;
[!ELSE!][!//
#define Eth_BufIdxType uint8
[!ENDIF!][!//

#endif /* if !defined( ETH_GENERALTYPES_CFG_H ) */
/*==================[end of file]============================================*/

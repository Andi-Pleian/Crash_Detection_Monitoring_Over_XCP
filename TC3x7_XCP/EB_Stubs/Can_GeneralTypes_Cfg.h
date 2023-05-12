#if (!defined CAN_GENERALTYPES_CFG_H)
#define CAN_GENERALTYPES_CFG_H
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

/** \brief Represents the hardware object handles of a CAN hardware unit. For CAN
 *         hardware units with more than 255 HW objects use extended range (generated).
 *
 * Range:
 *  - uint16 (if configuration parameter 'CanIf/CanIfPublicCfg/CanIfPublicHandleTypeEnum = UINT16')
 *  - uint8  (otherwise)
 */
/* !LINKSTO CAN429,1 */
typedef uint8 Can_HwHandleType;

/** \brief Represents the Identifier of an L-PDU. For extended IDs the most
 *        significant bit is set (generated).
 *
 * Range:
 *  - uint16 (if configuration parameter 'CanIf/CanIfPublicCfg/CanIfPublicCanIdTypeEnum = UINT16')
 *  - uint32 (otherwise)
 */
/* !LINKSTO CAN416,1 */
typedef uint32 Can_IdType;

#endif /* if !defined( CAN_GENERALTYPES_CFG_H ) */
/*==================[end of file]============================================*/

#if (!defined COMSTACK_CFG_H)
/* !LINKSTO COMTYPE016,1 */
#define COMSTACK_CFG_H

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
/* !LINKSTO COMTYPE003,1, COMTYPE015,1, COMTYPE029,1 */
[!/* PduIdTypeEnum is fixed to UINT16, see deviations of EcuC */!][!//
[!IF "node:exists(as:modconf('EcuC')[1]/EcucPduCollection/PduIdTypeEnum) and
          (as:modconf('EcuC')[1]/EcucPduCollection/PduIdTypeEnum != 'UINT16')"!][!//
[!ERROR  "For PduIdTypeEnum only data type UINT16 is supported"!]
[!ENDIF!][!//
[!/* PduLengthTypeEnum is fixed to UINT16, see deviations of EcuC */!][!//
[!IF "node:exists(as:modconf('EcuC')[1]/EcucPduCollection/PduLengthTypeEnum) and
          (as:modconf('EcuC')[1]/EcucPduCollection/PduLengthTypeEnum != 'UINT16')"!][!//
[!ERROR  "For PduLengthTypeEnum only data type UINT16 is supported"!][!//
[!ENDIF!][!//

/*==================[macros]=================================================*/

/*------------------[Size of Autosar Comstack Types]-------------------------*/

#if (defined TS_SIZE_PduIdType)
#error TS_SIZE_PduIdType already defined
#endif
/** \brief Size of AUTOSAR standard type PduIdType
 *
 * this value is fixed to 2U (see deviations of EcuC)
 */
#define TS_SIZE_PduIdType 2U

#if (defined TS_SIZE_PduLengthType)
#error TS_SIZE_PduLengthType already defined
#endif
/** \brief Size of AUTOSAR standard type PduLengthType
 *
 * this value is fixed to 2U (see deviations of EcuC)
 */
#define TS_SIZE_PduLengthType 2U

/*==================[type definitions]======================================*/

/* !LINKSTO COMTYPE030,1 */
/** \brief Type for a unique identifier for a PDU
 *
 * this type is fixed to uint16 (see deviations of EcuC)
 * - range: 0 .. PduIdmax
 */
typedef uint16 PduIdType;

/* !LINKSTO COMTYPE030,1 */
/** \brief Type for lengths information of a PDU
 *
 * this type is fixed to uint16 (see deviations of EcuC)
 * - range: 0 .. PduLengthmax
 */
typedef uint16 PduLengthType;

#endif /* if !defined( COMSTACK_CFG_H ) */
/*==================[end of file]============================================*/

/**
 * \file
 *
 * \brief AUTOSAR CanIf
 *
 * This file contains the implementation of the AUTOSAR
 * module CanIf.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
[!CODE!]
[!AUTOSPACING!]
#if (!defined CANIF_INT_CFG_H)
#define CANIF_INT_CFG_H


/*==================[includes]===============================================*/
#define CANIF_NO_PBCFG_REQUIRED
#include <TSAutosar.h>          /* EB specific standard types */
#include <ComStack_Types.h>     /* Autosar standard types */
#include <CanIf.h>            /* CanIf interface */

[!SELECT "as:modconf('CanIf')[1]/CanIfDispatchCfg"!]
[!IF "    (CanIfDispatchUserCtrlBusOffUL = 'CAN_SM')
       or (CanIfDispatchUserCtrlModeIndicationUL = 'CAN_SM')
       or (     (node:exists(../CanIfTrcvDrvCfg/*))
            and (    (CanIfDispatchUserTrcvModeIndicationUL = 'CAN_SM')
                  or (     (../CanIfPublicCfg/CanIfPublicPnSupport = 'true')
                       and (    (CanIfDispatchUserConfirmPnAvailabilityUL = 'CAN_SM')
                             or (CanIfDispatchUserClearTrcvWufFlagIndicationUL = 'CAN_SM')
                             or (CanIfDispatchUserCheckTrcvWakeFlagIndicationUL = 'CAN_SM')
                           )
                     )
                )
          )
     "!]
#include <CanSM_Cbk.h>                /* AUTOSAR CanSM callback definitions */
[!ENDIF!]
[!ENDSELECT!]

[!LOOP "CanIfPublicCfg/CanIfPublicCddHeaderFile/*"!][!//
#include <[!"."!]>   /* CDD header file */
[!ENDLOOP!][!//

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* if !defined( CANIF_INT_CFG_H ) */
/*==================[end of file]============================================*/
[!ENDCODE!]

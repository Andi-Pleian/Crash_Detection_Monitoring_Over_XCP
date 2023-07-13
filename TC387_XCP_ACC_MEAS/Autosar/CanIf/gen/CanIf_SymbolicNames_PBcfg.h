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
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


  #if (!defined CANIF_SYMBOLICNAMES_PBCFG_H)
#define CANIF_SYMBOLICNAMES_PBCFG_H

/*==================[includes]===============================================*/
/*==================[macros]=================================================*/

/*------------------[symbolic name values]----------------------------------*/

/** \brief Export symbolic name values for CanIfTxPduIds */


#if (defined CanIfConf_CanIfTxPduCfg_XCP_RESPONSE)
#error CanIfConf_CanIfTxPduCfg_XCP_RESPONSE already defined!
#endif /* #if( defined CanIfConf_CanIfTxPduCfg_XCP_RESPONSE)*/
#define CanIfConf_CanIfTxPduCfg_XCP_RESPONSE 0U

#if (defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <=
AUTOSAR version) */
#if (defined CanIf_XCP_RESPONSE)
#error CanIf_XCP_RESPONSE already defined!
#endif /* #if( defined CanIf_XCP_RESPONSE)*/
#define CanIf_XCP_RESPONSE 0U
#endif /* defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES */


/** \brief Export symbolic name values for CanIfRxPduIds */


#if (defined CanIfConf_CanIfRxPduCfg_XCP_REQUEST)
#error CanIfConf_CanIfRxPduCfg_XCP_REQUEST already defined!
#endif /* #if( defined CanIfConf_CanIfRxPduCfg_XCP_REQUEST)*/
#define CanIfConf_CanIfRxPduCfg_XCP_REQUEST 0U

#if (defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <=
AUTOSAR version) */
#if (defined CanIf_XCP_REQUEST)
#error CanIf_XCP_REQUEST already defined!
#endif /* #if( defined CanIf_XCP_REQUEST)*/
#define CanIf_XCP_REQUEST 0U
#endif /* defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES */


/** \brief Export symbolic name values for CanIfCtrlIds */


#if (defined CanIfConf_CanIfCtrlDrvCfg_contr_ACSM5_PS_CAN)
#error CanIfConf_CanIfCtrlDrvCfg_contr_ACSM5_PS_CAN already defined!
#endif /* #if( defined CanIfConf_CanIfCtrlDrvCfg_contr_ACSM5_PS_CAN)*/
#define CanIfConf_CanIfCtrlDrvCfg_contr_ACSM5_PS_CAN 0U

#if (defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <=
AUTOSAR version) */
#if (defined CanIf_CanIfCtrlDrvCfg_contr_ACSM5_PS_CAN)
#error CanIf_CanIfCtrlDrvCfg_contr_ACSM5_PS_CAN already defined!
#endif /* #if( defined CanIf_CanIfCtrlDrvCfg_contr_ACSM5_PS_CAN)*/
#define CanIf_CanIfCtrlDrvCfg_contr_ACSM5_PS_CAN 0U
#endif /* defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES */


/** \brief Export symbolic name values for CanIfTrcvIds */

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* if !defined( CANIF_SYMBOLICNAMES_PBCFG_H ) */
/*==================[end of file]============================================*/

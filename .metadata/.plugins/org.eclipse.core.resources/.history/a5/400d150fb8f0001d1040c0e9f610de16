[!/*****************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2017)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Can_17_McmCan_PBCfg.c                                         **
**                                                                            **
**  VERSION   : 3.0.1                                                         **
**                                                                            **
**  DATE      : 2017-03-14                                                    **
**                                                                            **
**  BSW MODULE DECRIPTION : Can_17_McmCan.bmd                                 **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY : [cover parentID= ]                                         **
**                                                                            **
**  DESCRIPTION  : Code template source file for Can Driver                   **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) : Specification of Can Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*****************************************************************************/!]
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2017)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Can_17_McmCan_PBCfg.c                                         **
**                                                                            **
**  VERSION   : 3.0.0                                                         **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : Can_17_McmCan.bmd                                 **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Can configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Can Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

[!//
[!/* Include Code Generator Macros */!][!//
[!INCLUDE "Can_17_McmCan.m"!][!//
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include CAN Driver Header File */
#include "Can_17_McmCan.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define CAN_17_MCMCAN_START_SEC_CONFIG_DATA_QM_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"
[!//
[!VAR "ControllerConfigMax" = "num:i(0)"!][!//
[!VAR "Cntrlindx" = "num:i(0)"!][!//
[!VAR "HwObjindx" = "num:i(0)"!][!//
[!VAR "HwObjctMaxTemp" = "num:i(0)"!][!//
[!VAR "StandardIdOnly" = "num:i(0)"!][!//
[!VAR "MixedOnly" = "num:i(0)"!][!//
[!VAR "ExtendedOnly" = "num:i(0)"!][!//
[!VAR "TxObjectCountMax" = "num:i(0)"!][!//
[!VAR "RxObjectCountMax" = "num:i(0)"!][!//
[!VAR "FDNodesPresent" = "num:i(0)"!][!//
[!VAR "TxQueueUsedStatus" = "num:i(0)"!][!//
[!VAR "RXFIFO0UsedStatus" = "num:i(0)"!][!//
[!VAR "RXFIFO1UsedStatus" = "num:i(0)"!][!//
[!VAR "RXFIFOBuffFlag" = "num:i(0)"!][!//
[!VAR "ControllerBRConfigTemp" = "num:i(0)"!][!//
[!VAR "BaudrateIndx" = "num:i(0)"!][!//
[!VAR "PublicIcomSupport" = "num:i(0)"!][!//
[!VAR "NoOfIcomConfig" = "num:i(0)"!][!//
[!VAR "MultiCycleWriteOperCfg" = "num:i(0)"!][!//
[!VAR "MultiCycleReadOperCfg" = "num:i(0)"!][!//
[!VAR "CanDrvWakeupSupport" = "num:i(0)"!][!//
[!VAR "HrhRefNameCheckMax" = "num:i(0)"!][!//
[!VAR "HthRefNameCheckMax" = "num:i(0)"!][!//
[!VAR "MainFuncNameHth" = "''"!][!//
[!VAR "MainFuncNameHrh" = "''"!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Can')[1]/CanConfigSet/./*[1]"!][!//
[!VAR "ConfigPath" = "node:path(.)"!][!//
[!VAR "ConfigShortNamePath" = "substring-after($ConfigPath, 'CanConfigSet/')"!][!//
[!IF "../../CanGeneral/*[1]/CanPublicIcomSupport = 'true'"!][!//
    [!VAR "PublicIcomSupport" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "node:exists(CanIcom/*[1]) = 'true'"!][!//
[!VAR "NoOfIcomConfig" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "$PublicIcomSupport > num:i(0) and $NoOfIcomConfig = num:i(0)"!][!//
[!ERROR!][!//
Atleast one instance CanIcomConfig container should be configured when CanPublicIcomSupport in CanGeneral container is configured as 'true'.
[!ENDERROR!][!//
[!ENDIF!][!//
[!VAR "CanRxCalloutFnExists" = "num:i(0)"!][!//
[!/* Extract Receive L-PDU Callout Function Pointer */!][!//
[!IF "node:exists(../../CanGeneral/*[1]/CanLPduReceiveCalloutFunction) = 'true'"!][!//
[!VAR "RxLPduCallout" = "../../CanGeneral/*[1]/CanLPduReceiveCalloutFunction"!][!//
[!IF "$RxLPduCallout != '""' and $RxLPduCallout != '' and $RxLPduCallout != 'NULL_PTR' and $RxLPduCallout != 'NULL'"!][!//
[!VAR "CanRxCalloutFnExists" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!//
[!IF "$CanRxCalloutFnExists = num:i(1)"!][!//

/* CAN L-PDU Receive Callout Function */
extern boolean [!"$RxLPduCallout"!] (uint8 Hrh,
           Can_IdType CanId, uint8 CanDlc, const uint8 *CanSduPtr);
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "ControllerConfigMaxTemp" = "num:i(count(./CanController/*))"!][!//
[!FOR "Cntrlindx" = "1" TO "$ControllerConfigMaxTemp"!][!//
    [!IF "(CanController/*[position()=$Cntrlindx]/CanWakeupSupport = 'true')"!][!//
    [!VAR "CanDrvWakeupSupport" = "num:i(1)"!][!//
    [!ENDIF!][!//
    [!VAR "ControllerBRConfigTemp" = "num:i(count(CanController/*[position()=$Cntrlindx]/CanControllerBaudrateConfig/*))"!][!//
    [!FOR "BaudrateIndx" = "1" TO "$ControllerBRConfigTemp"!][!//
        [!IF "(node:exists(CanController/*[position()=$Cntrlindx]/CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/*))"!][!//
            [!VAR "FDNodesPresent" = "num:i(1)"!][!//
        [!ENDIF!][!//
    [!ENDFOR!][!//
[!ENDFOR!][!//
[!VAR "HwObjctMaxTemp" = "num:i(count(./CanHardwareObject/*))"!][!//
[!FOR "HwObjindx" = "1" TO "$HwObjctMaxTemp"!][!//
    [!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanObjectType = 'TRANSMIT'"!][!//
        [!VAR "TxObjectCountMax" = "num:i($TxObjectCountMax+1)"!][!//
        [!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanHwObjectCount > 1"!][!//
            [!VAR "TxQueueUsedStatus" = "num:i(1)"!][!//
        [!ENDIF!][!//
        [!IF "node:refexists(./CanHardwareObject/*[position()=$HwObjindx]/CanMainFunctionRWPeriodRef)"!][!//
        [!VAR "TxMode"= "(node:value(./CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef))"!][!//
        [!IF "node:ref($TxMode)/CanTxProcessing = 'POLLING'"!][!//
            [!VAR "MainFuncNameConfig"= "(node:value(./CanHardwareObject/*[position()=$HwObjindx]/CanMainFunctionRWPeriodRef))"!][!//
            [!VAR "HthRefNameCheckMax" = "num:i($HthRefNameCheckMax+1)"!][!//
            [!IF "$HthRefNameCheckMax = num:i(1)"!][!//
                [!VAR "MainFuncNameHth" = "$MainFuncNameConfig"!][!//
            [!ENDIF!][!//
            [!IF "$MainFuncNameHth != $MainFuncNameConfig"!][!//
                [!VAR "MultiCycleWriteOperCfg" = "num:i(1)"!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
    [!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanObjectType = 'RECEIVE'"!][!//
        [!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanHwObjectCount > 1"!][!//
            [!VAR "HwControllerId" = "num:i(node:ref(./CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef)/CanControllerId)"!][!//
            [!IF "$RXFIFOBuffFlag = 1"!][!//
                [!IF "$HwControllerId = $LastCntrlId"!][!//
                    [!VAR "RXFIFO1UsedStatus" = "num:i(1)"!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
            [!IF "$RXFIFOBuffFlag = 0"!][!//
                [!VAR "RXFIFO0UsedStatus" = "num:i(1)"!][!//
                [!VAR "RXFIFOBuffFlag" = "num:i($RXFIFOBuffFlag+1)"!][!//
            [!ENDIF!][!//
            [!VAR "LastCntrlId" = "num:i($HwControllerId)"!][!//
            [!IF "$HwControllerId != $LastCntrlId"!][!//
                    [!VAR "RXFIFOBuffFlag" = "num:i(0)"!][!//
            [!ENDIF!][!//
            [!VAR "LastCntrlId" = "num:i($HwControllerId)"!][!//
        [!ENDIF!][!//
        [!VAR "RxObjectCountMax" = "num:i($RxObjectCountMax+1)"!][!//
        [!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanIdType = 'STANDARD'"!][!//
            [!VAR "StandardIdOnly" = "num:i(1)"!][!//
        [!ENDIF!][!//
        [!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanIdType = 'MIXED'"!][!//
            [!VAR "MixedOnly" = "num:i(1)"!][!//
        [!ENDIF!][!//
        [!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanIdType = 'EXTENDED'"!][!//
            [!VAR "ExtendedOnly" = "num:i(1)"!][!//
        [!ENDIF!][!//
        [!IF "node:refexists(./CanHardwareObject/*[position()=$HwObjindx]/CanMainFunctionRWPeriodRef)"!][!//
        [!VAR "RxMode"= "(node:value(./CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef))"!][!//
        [!IF "node:ref($RxMode)/CanRxProcessing = 'POLLING'"!][!//
            [!VAR "MainFuncNameConfig"= "(node:value(./CanHardwareObject/*[position()=$HwObjindx]/CanMainFunctionRWPeriodRef))"!][!//
            [!VAR "HrhRefNameCheckMax" = "num:i($HrhRefNameCheckMax+1)"!][!//
        [!IF "$HrhRefNameCheckMax = num:i(1)"!][!//
            [!VAR "MainFuncNameHrh" = "$MainFuncNameConfig"!][!//
        [!ENDIF!][!//
        [!IF "$MainFuncNameHrh != $MainFuncNameConfig"!][!//
            [!VAR "MultiCycleReadOperCfg" = "num:i(1)"!][!//
        [!ENDIF!][!//
        [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!ENDSELECT!][!//
/*******************************************************************************
              CAN Kernel configuration parameters
********************************************************************************
     { CAN Global Kernel Address, The activated nodes configuration index,
      The total number of active nodes with in the kernel }
********************************************************************************
           Note: If any of CAN controller is not activated then,this
                 will not be generated
                 The value of "CanUsedHwCfgIndx" is filled with 255 if the
                 associated node is not configured
*******************************************************************************/
[!SELECT "as:modconf('Can')[1]/CanConfigSet/./*[1]"!][!//
[!NOCODE!][!//
[!VAR "MaxKernel" = "num:i(ecu:get('Can.MaxKernels'))"!][!//
[!VAR "BaseAddress" = "num:i(0)"!][!//
[!VAR "ActNode0" = "num:i(0)"!][!//
[!VAR "ActNode1" = "num:i(0)"!][!//
[!VAR "ActNode2" = "num:i(0)"!][!//
[!VAR "ActNodeIndx00" = "num:i(255)"!][!//
[!VAR "ActNodeIndx01" = "num:i(255)"!][!//
[!VAR "ActNodeIndx02" = "num:i(255)"!][!//
[!VAR "ActNodeIndx03" = "num:i(255)"!][!//
[!VAR "ActNodeIndx10" = "num:i(255)"!][!//
[!VAR "ActNodeIndx11" = "num:i(255)"!][!//
[!VAR "ActNodeIndx12" = "num:i(255)"!][!//
[!VAR "ActNodeIndx13" = "num:i(255)"!][!//
[!VAR "ActNodeIndx20" = "num:i(255)"!][!//
[!VAR "ActNodeIndx21" = "num:i(255)"!][!//
[!VAR "ActNodeIndx22" = "num:i(255)"!][!//
[!VAR "ActNodeIndx23" = "num:i(255)"!][!//
[!VAR "Node2Present" = "num:i(0)"!][!//
[!VAR "Node1Present" = "num:i(0)"!][!//
[!VAR "Node0Present" = "num:i(0)"!][!//
/* Set loop for read the configured controller and corresponding MCMCAN kernel information*/
[!LOOP "./CanController/*"!][!//
    [!VAR "ValidCntrlBaseAddress" = "num:i(0)"!][!//
    [!IF "CanControllerActivation = 'true'"!][!//
        [!VAR "BaseAddress" = "num:i(CanControllerBaseAddress)"!][!//
        /* Check the controller is support with 3 MCMCAN kernels or not */
        [!IF "$MaxKernel > 2"!][!//
            /* Check if the configured controller is associated with in Kernel 2 */
            [!IF "(($BaseAddress = num:hextoint(ecu:get('Can.Node20BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node21BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node22BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node23BaseAddress'))))"!][!//
                [!VAR "Node2Present" = "num:i(1)"!][!//
                [!VAR "ActNode2" = "num:i($ActNode2+1)"!][!//
                [!IF "$ActNodeIndx20 = num:i(255)"!][!//
                    [!VAR "ActNodeIndx20" = "num:i(CanControllerId)"!][!//
                [!ELSEIF "$ActNodeIndx21 = num:i(255)"!][!//
                    [!VAR "ActNodeIndx21" = "num:i(CanControllerId)"!][!//
                [!ELSEIF "$ActNodeIndx22 = num:i(255)"!][!//
                    [!VAR "ActNodeIndx22" = "num:i(CanControllerId)"!][!//
                [!ELSE!][!//
                    [!VAR "ActNodeIndx23" = "num:i(CanControllerId)"!][!//
                [!ENDIF!][!//
                [!VAR "ValidCntrlBaseAddress" = "num:i(1)"!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
        /* Check if the configured controller is associated with in Kernel 1 */
        [!IF "(($BaseAddress = num:hextoint(ecu:get('Can.Node10BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node11BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node12BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node13BaseAddress'))))"!][!//
            [!VAR "Node1Present" = "num:i(1)"!][!//
            [!VAR "ActNode1" = "num:i($ActNode1+1)"!][!//
            [!IF "$ActNodeIndx10 = num:i(255)"!][!//
                [!VAR "ActNodeIndx10" = "num:i(CanControllerId)"!][!//
            [!ELSEIF "$ActNodeIndx11 = num:i(255)"!][!//
                [!VAR "ActNodeIndx11" = "num:i(CanControllerId)"!][!//
            [!ELSEIF "$ActNodeIndx12 = num:i(255)"!][!//
                [!VAR "ActNodeIndx12" = "num:i(CanControllerId)"!][!//
            [!ELSE!][!//
                [!VAR "ActNodeIndx13" = "num:i(CanControllerId)"!][!//
            [!ENDIF!][!//
            [!VAR "ValidCntrlBaseAddress" = "num:i(1)"!][!//
        [!ENDIF!][!//
        /* Check if the configured controller is associated with in Kernel 0 */
        [!IF "(($BaseAddress = num:hextoint(ecu:get('Can.Node00BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node01BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node02BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node03BaseAddress'))))"!][!//
            [!VAR "Node0Present" = "num:i(1)"!][!//
            [!VAR "ActNode0" = "num:i($ActNode0+1)"!][!//
            [!IF "$ActNodeIndx00 = num:i(255)"!][!//
                [!VAR "ActNodeIndx00" = "num:i(CanControllerId)"!][!//
            [!ELSEIF "$ActNodeIndx01 = num:i(255)"!][!//
                [!VAR "ActNodeIndx01" = "num:i(CanControllerId)"!][!//
            [!ELSEIF "$ActNodeIndx02 = num:i(255)"!][!//
                [!VAR "ActNodeIndx02" = "num:i(CanControllerId)"!][!//
            [!ELSE!][!//
                [!VAR "ActNodeIndx03" = "num:i(CanControllerId)"!][!//
            [!ENDIF!][!//
            [!VAR "ValidCntrlBaseAddress" = "num:i(1)"!][!//
        [!ENDIF!][!//
        [!IF "$ValidCntrlBaseAddress = '0' "!][!//
          [!ERROR!][!//
           The Base addrees configured for CancontrollerId[!"CanControllerId"!] is wrong.
         [!ENDERROR!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//

[!ENDLOOP!][!//
[!ENDNOCODE!][!//
static const Can_McmModuleConfigType Can_kMcmModuleConfig[[!"'CAN_NOOF_KERNEL'"!]] =
{
[!AUTOSPACING!]
[!INDENT "2"!]
[!IF "$Node0Present = '1'"!][!//
    {
     /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
     cast the generated address with CAN Kernel structure type */
     /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
     integer type. Permitted for special function registers.*/
    (volatile Ifx_CAN*) [!"ecu:get('Can.MCMCAN0BASERAM')"!]U,
    {[!"num:i($ActNodeIndx00)"!]U, [!//
     [!"num:i($ActNodeIndx01)"!]U, [!//
     [!"num:i($ActNodeIndx02)"!]U, [!//
     [!"num:i($ActNodeIndx03)"!]U}, [!//
     [!"num:i($ActNode0)"!]U
    }[!//
    [!IF "($Node1Present = '1') or ($Node2Present = '1')"!][!//
        ,
    [!ENDIF!][!//
[!ENDIF!][!//
[!IF "$Node1Present = '1'"!][!//
    {
     /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
     cast the generated address with CAN Kernel structure type */
     /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
     integer type. Permitted for special function registers.*/
    (volatile Ifx_CAN*) [!"ecu:get('Can.MCMCAN1BASERAM')"!]U,
    {[!"num:i($ActNodeIndx10)"!]U, [!//
    [!"num:i($ActNodeIndx11)"!]U, [!//
    [!"num:i($ActNodeIndx12)"!]U, [!//
    [!"num:i($ActNodeIndx13)"!]U}, [!//
    [!"num:i($ActNode1)"!]U
    }[!//
    [!IF "$Node2Present = '1'"!][!//
        ,
    [!ENDIF!][!//
[!ENDIF!][!//
[!IF "$MaxKernel > 2"!][!//
    [!IF "$Node2Present = '1'"!][!//
    {
     /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
     cast the generated address with CAN Kernel structure type */
     /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
     integer type. Permitted for special function registers.*/
    (volatile Ifx_CAN*) [!"ecu:get('Can.MCMCAN2BASERAM')"!]U,
    {[!"num:i($ActNodeIndx20)"!]U, [!//
    [!"num:i($ActNodeIndx21)"!]U, [!//
    [!"num:i($ActNodeIndx22)"!]U, [!//
    [!"num:i($ActNodeIndx23)"!]U}, [!//
    [!"num:i($ActNode2)"!]U
    }
    [!ENDIF!][!//
[!ENDIF!]
[!ENDINDENT!]

};
[!ENDSELECT!]
/*******************************************************************************
               Can Controller Configurations
********************************************************************************
    { Can node Base Address,[WakeupSrcId],Combination value of Rx pin select and
    Loopback mode Support,{First Tx Hardware Object, No.of Tx Hardware Objects,
    First Rx Standard Hardware Object, No.of Rx standard Hardware Objects},
    [First Rx Extended Hardware Object],Default baudrate Config index,
    First baudrate index,No.of baudrate configuration,Associated kernel Id,
    Controller Hw Id, [No.of Rx Extended Hardware Objects],[FD support status] }
********************************************************************************
       Note: [1] The configuration shall be generated only for the activated
                 controller
             [2] The Generation of Extended message information is depends on
                 the CanIdType of Rx message configuration
*******************************************************************************/
[!SELECT "as:modconf('Can')[1]/CanConfigSet/./*[1]"!][!//
[!VAR "BaudrateIndex" = "num:i(0)"!][!//
[!VAR "HwControllerCount" = "num:i(count(./CanController/*))"!][!//
static const Can_ControllerConfigType
                                Can_kControllerConfig[[!"'CAN_NOOF_CONTROLLER'"!]] =
{
[!NOCODE!][!//
[!VAR "FirstTxIndx" = "num:i(0)"!][!//
[!VAR "NoOfTx" = "num:i(0)"!][!//
[!VAR "FirstSIDIndx" = "num:i(0)"!][!//
[!VAR "NoOfSID" = "num:i(0)"!][!//
[!VAR "FirstXIDIndx" = "num:i(0)"!][!//
[!VAR "NoOfXID" = "num:i(0)"!][!//
[!VAR "NoOfTxTemp" = "num:i(0)"!][!//
[!VAR "NoOfSIDTemp" = "num:i(0)"!][!//
[!VAR "NoOfXIDTemp" = "num:i(0)"!][!//
[!VAR "FDNodes" = "num:i(0)"!][!//
[!VAR "IndexCnt" = "num:i(0)"!][!//
[!ENDNOCODE!][!//
[!AUTOSPACING!]
[!INDENT "2"!]
[!NOCODE!][!//
[!FOR "HwIndex" = "0" TO "$HwControllerCount - '1'"!][!//
/* Set loop for read all the configured controller informations */
[!LOOP "./CanController/*"!][!//
[!VAR "NPCRTemp" = "num:i(0)"!][!//
    [!VAR "TempControllerId" = "num:i(CanControllerId)"!][!//
    [!IF "$HwIndex = $TempControllerId"!][!//
    [!IF "CanControllerActivation = 'true'"!][!//
        [!IF "$IndexCnt > '0'"!][!//
        [!CODE!][!//
        ,
        [!ENDCODE!][!//
        [!ENDIF!][!//
        [!VAR "IndexCnt" = "num:i($IndexCnt+1)"!][!//
    [!VAR "BaseAddress" = "num:i(CanControllerBaseAddress)"!][!//
[!CODE!][!//
    {
     /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
     cast the generated address with CAN Node structure type */
     /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
     integer type. Permitted for special function registers.*/
    (volatile Ifx_CAN_N*)[!"num:inttohex($BaseAddress)"!]U,
[!ENDCODE!][!//
    [!IF "CanControllerLoopbackEnable = 'true'"!][!//
        [!VAR "NPCRTemp" = "bit:bitset($NPCRTemp,8)"!][!//
    [!ELSEIF "CanRxInputSelection = 'CANxx_RXDB'"!][!//
        [!VAR "NPCRTemp" = "bit:or($NPCRTemp,1)"!][!//
    [!ELSEIF "CanRxInputSelection = 'CANxx_RXDC'"!][!//
        [!VAR "NPCRTemp" = "bit:or($NPCRTemp,2)"!][!//
    [!ELSEIF "CanRxInputSelection = 'CANxx_RXDD'"!][!//
        [!VAR "NPCRTemp" = "bit:or($NPCRTemp,3)"!][!//
    [!ELSEIF "CanRxInputSelection = 'CANxx_RXDE'"!][!//
        [!VAR "NPCRTemp" = "bit:or($NPCRTemp,4)"!][!//
    [!ELSEIF "CanRxInputSelection = 'CANxx_RXDF'"!][!//
        [!VAR "NPCRTemp" = "bit:or($NPCRTemp,5)"!][!//
    [!ELSEIF "CanRxInputSelection = 'CANxx_RXDG'"!][!//
        [!VAR "NPCRTemp" = "bit:or($NPCRTemp,6)"!][!//
    [!ELSEIF "CanRxInputSelection = 'CANxx_RXDH'"!][!//
        [!VAR "NPCRTemp" = "bit:or($NPCRTemp,7)"!][!//
    [!ENDIF!][!//
    [!IF "$CanDrvWakeupSupport = '1'"!][!//
      [!IF "CanWakeupSupport = 'true'"!][!//
        [!IF "node:exists(CanWakeupSourceRef) = 'true'"!][!//
            [!IF "node:refexists(CanWakeupSourceRef) ='true'"!][!//
                [!CODE!][!//
                [!"num:inttohex(bit:shl(1,num:i(node:ref(CanWakeupSourceRef)/EcuMWakeupSourceId)))"!]U, [!//
                [!ENDCODE!][!//
            [!ELSE!][!//
                [!CODE!][!//
                [!"num:inttohex(0)"!]U, [!//
                [!ENDCODE!][!//
            [!ENDIF!][!//
        [!ELSE!][!//
            [!CODE!][!//
            [!"num:inttohex(0)"!]U, [!//
            [!ENDCODE!][!//
        [!ENDIF!][!//
      [!ELSE!][!//
            [!CODE!][!//
            [!"num:inttohex(0)"!]U, [!//
            [!ENDCODE!][!//
      [!ENDIF!][!//
    [!ENDIF!][!//
    [!CODE!][!//
    [!"num:inttohex($NPCRTemp)"!]U,
    [!ENDCODE!][!//
    [!LOOP "../../CanHardwareObject/*"!][!//
        [!IF "node:refexists(CanControllerRef) ='true'"!][!//
            [!VAR "HwControllerId" = "num:i(node:ref(CanControllerRef)/CanControllerId)"!][!//
            [!IF "$HwControllerId = $TempControllerId"!][!//
                [!IF "CanObjectType = 'TRANSMIT'"!][!//
                    [!VAR "NoOfTxTemp" = "num:i($NoOfTxTemp+1)"!][!//
                [!ENDIF!][!//
                [!IF "CanObjectType = 'RECEIVE'"!][!//
                    [!VAR "HwFilterCount" = "num:i(count(CanHwFilter/*))"!][!//
                    [!FOR "HwFilterindx" = "1" TO "$HwFilterCount"!][!//
                        [!VAR "HwFilterValue" = "num:i(CanHwFilter/*[position()=$HwFilterindx]/CanHwFilterCode)"!][!//
                        [!IF "CanIdType = 'STANDARD' or CanIdType = 'MIXED' "!][!//
                            [!VAR "NoOfSIDTemp" = "num:i($NoOfSIDTemp+1)"!][!//
                        [!ENDIF!][!//
                        [!IF "CanIdType = 'EXTENDED' or CanIdType = 'MIXED' "!][!//
                            [!VAR "NoOfXIDTemp" = "num:i($NoOfXIDTemp+1)"!][!//
                        [!ENDIF!][!//
                    [!ENDFOR!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    /* 1.Set first Index with Tx start Index*/
    /* 2.Set Second Index with total no of HTH configuration */
    /* 3.Set Third Index with SID filter mask start Index */
    /* 4.Set Fourth Index with total no of SID filter mask configuration */
    [!CODE!][!//
    {[!"num:inttohex($FirstTxIndx)"!]U, [!//
    [!ENDCODE!][!//
    [!VAR "FirstTxIndx" = "num:i($FirstTxIndx+$NoOfTxTemp)"!][!//
    [!CODE!][!//
    [!"num:inttohex($NoOfTxTemp)"!]U, [!//
    [!VAR "NoOfTxTemp" = "num:i(0)"!][!//
    [!"num:inttohex($FirstSIDIndx)"!]U, [!//
    [!VAR "FirstSIDIndx" = "num:i($FirstSIDIndx+$NoOfSIDTemp)"!][!//
    [!"num:inttohex($NoOfSIDTemp)"!]U}, [!//
    [!ENDCODE!][!//
    [!VAR "NoOfSIDTemp" = "num:i(0)"!][!//
    /* Check if CanIdType is support with extended or Mixed then set XIDFilterPos */
    [!IF "$RxObjectCountMax > 0"!][!//
        [!IF "$ExtendedOnly = '1' or $MixedOnly = '1'"!][!//
            [!CODE!][!//
            [!"num:inttohex($FirstXIDIndx)"!]U,[!//
            [!ENDCODE!][!//
            [!VAR "FirstXIDIndx" = "num:i($FirstXIDIndx+$NoOfXIDTemp)"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
    [!IF "node:refexists(CanControllerDefaultBaudrate) ='true'"!][!//
    [!VAR "CanDefaultBaudrateRef" = "node:path(node:ref(CanControllerDefaultBaudrate))"!][!//
    [!IF "contains($CanDefaultBaudrateRef, node:path(.)) = 'true'"!][!//
    [!ELSE!][!//
    [!ERROR!][!//
    [!VAR "CanConfigSetName" = "substring-after(node:path(.), "CanConfigSet/")"!][!//
    [!VAR "CanConfigSetName" = "substring-before($CanConfigSetName, "/")"!][!//
    The CanControllerId[!"CanControllerId"!] is referred to a default baudrate which does not belong to the same CanController.[!//
    [!ENDERROR!][!//
    [!ENDIF!][!//
    [!ENDIF!][!//
    [!VAR "DefaultBaudrateCfgIndx" = "num:i(node:ref(CanControllerDefaultBaudrate)/CanControllerBaudRateConfigID)"!][!//
    /* Set DefaultBaudrateCfgIndx value */
    [!CODE!][!//
    [!"num:inttohex($DefaultBaudrateCfgIndx+$BaudrateIndex)"!]U, [!//
    [!ENDCODE!][!//
    /* Set BaudrateCfgIndx value */
    [!CODE!][!//
    [!"num:inttohex($BaudrateIndex)"!]U, [!//
    [!ENDCODE!][!//
    [!VAR "NoOfBaudrateCfg" = "num:i(count(./CanControllerBaudrateConfig/*))"!][!//
    /* Set Total no of Baudrate configurations (NoOfBaudrateCfg) value */
    [!CODE!][!//
    [!"num:inttohex($NoOfBaudrateCfg)"!]U, [!//
    [!ENDCODE!][!//
    [!VAR "BaudrateIndex" = "num:i($BaudrateIndex + $NoOfBaudrateCfg)"!][!//
    /* Set CanKernelHwId parameter with Kernel Hw configuration index number */
    [!IF "(($BaseAddress = num:hextoint(ecu:get('Can.Node00BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node01BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node02BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node03BaseAddress'))))"!][!//
            [!CODE!][!//
            [!"num:inttohex('0')"!]U, [!//
            [!ENDCODE!][!//
            [!IF "($BaseAddress = num:hextoint(ecu:get('Can.Node00BaseAddress')))"!][!//
                [!CODE!][!//
                0x00U [!//
                [!ENDCODE!][!//
            [!ENDIF!][!//
            [!IF "($BaseAddress = num:hextoint(ecu:get('Can.Node01BaseAddress')))"!][!//
                [!CODE!][!//
                0x01U [!//
                [!ENDCODE!][!//
            [!ENDIF!][!//
            [!IF "($BaseAddress = num:hextoint(ecu:get('Can.Node02BaseAddress')))"!][!//
                [!CODE!][!//
                0x02U [!//
                [!ENDCODE!][!//
            [!ENDIF!][!//
            [!IF "($BaseAddress = num:hextoint(ecu:get('Can.Node03BaseAddress')))"!][!//
                [!CODE!][!//
                0x03U [!//
                [!ENDCODE!][!//
            [!ENDIF!][!//
    [!ENDIF!][!//
    [!IF "(($BaseAddress = num:hextoint(ecu:get('Can.Node10BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node11BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node12BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node13BaseAddress'))))"!][!//
            [!CODE!][!//
            [!"num:inttohex($Node0Present)"!]U, [!//
            [!ENDCODE!][!//
            [!IF "($BaseAddress = num:hextoint(ecu:get('Can.Node10BaseAddress')))"!][!//
                [!CODE!][!//
                0x00U [!//
                [!ENDCODE!][!//
            [!ENDIF!][!//
            [!IF "($BaseAddress = num:hextoint(ecu:get('Can.Node11BaseAddress')))"!][!//
                [!CODE!][!//
                0x01U [!//
                [!ENDCODE!][!//
            [!ENDIF!][!//
            [!IF "($BaseAddress = num:hextoint(ecu:get('Can.Node12BaseAddress')))"!][!//
                [!CODE!][!//
                0x02U [!//
                [!ENDCODE!][!//
            [!ENDIF!][!//
            [!IF "($BaseAddress = num:hextoint(ecu:get('Can.Node13BaseAddress')))"!][!//
                [!CODE!][!//
                0x03U [!//
                [!ENDCODE!][!//
            [!ENDIF!][!//
    [!ENDIF!][!//
    [!IF "(($BaseAddress = num:hextoint(ecu:get('Can.Node20BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node21BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node22BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node23BaseAddress'))))"!][!//
        [!CODE!][!//
        [!"num:inttohex($Node1Present+$Node0Present)"!]U, [!//
        [!ENDCODE!][!//
            [!IF "($BaseAddress = num:hextoint(ecu:get('Can.Node20BaseAddress')))"!][!//
                [!CODE!][!//
                0x00U [!//
                [!ENDCODE!][!//
            [!ENDIF!][!//
            [!IF "($BaseAddress = num:hextoint(ecu:get('Can.Node21BaseAddress')))"!][!//
                [!CODE!][!//
                0x01U [!//
                [!ENDCODE!][!//
            [!ENDIF!][!//
            [!IF "($BaseAddress = num:hextoint(ecu:get('Can.Node22BaseAddress')))"!][!//
                [!CODE!][!//
                0x02U [!//
                [!ENDCODE!][!//
            [!ENDIF!][!//
            [!IF "($BaseAddress = num:hextoint(ecu:get('Can.Node23BaseAddress')))"!][!//
                [!CODE!][!//
                0x03U [!//
                [!ENDCODE!][!//
            [!ENDIF!][!//
    [!ENDIF!][!//

    /* Extended filter configuration index number */
    [!IF "$RxObjectCountMax > 0"!][!//
        [!IF "$ExtendedOnly = '1' or $MixedOnly = '1'"!][!//
        [!CODE!][!//
        ,[!//
        [!"num:inttohex($NoOfXIDTemp)"!]U[!//
        [!ENDCODE!][!//
        [!VAR "NoOfXIDTemp" = "num:i(0)"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
    [!IF "$FDNodesPresent = '1'"!][!//
        [!VAR "FDNodes" = "num:i(0)"!][!//
        [!VAR "ControllerBRConfigTemp" = "num:i(count(./CanControllerBaudrateConfig/*))"!][!//
        [!FOR "BaudrateIndx" = "1" TO "$ControllerBRConfigTemp"!][!//
            [!IF "(node:exists(CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/*))"!][!//
            [!VAR "FDNodes" = "num:i(1)"!][!//
            [!ENDIF!][!//
        [!ENDFOR!][!//
        [!CODE!][!//
        ,
        [!IF "$FDNodes = '1'"!][!//
            CAN_TRUE
        [!ELSE!][!//
            CAN_FALSE
        [!ENDIF!][!//
        }[!//
        [!ENDCODE!][!//
    [!ELSE!][!//
    [!CODE!][!//

    }[!//
    [!ENDCODE!][!//
    [!ENDIF!][!//
    [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!]
[!ENDNOCODE!][!//
[!ENDINDENT!]

};
[!ENDSELECT!]
[!//
/*******************************************************************************
              Message RAM partition configuration
********************************************************************************
      {{start address of SID section,start address of XID section,
      start address of FIFO0 section,start address of FIFO1 section,start
      address of Rx dedicated buffer section,start address of Tx Event section,
      start address of Tx dedicated buffer section},Tx_ded_Buff size,
      Tx_Evnt size,[Rx_FIFO0 size],[Rx_FIFO0 Threshold],[Rx_FIFO1 size],
      [Rx_FIFO1 Threshold],[Tx_Queue size],[Tx_Queue Enable Status]}
********************************************************************************
           Note: This shall be generated only for the activated controller
*******************************************************************************/
[!SELECT "as:modconf('Can')[1]/CanConfigSet/./*[1]"!][!//
static const Can_ControllerMsgRAMConfigType
                    Can_kControllerMsgRAMMapConfig[[!"'CAN_NOOF_CONTROLLER'"!]] =
{
[!VAR "HwControllerCount" = "num:i(count(./CanController/*))"!][!//
[!VAR "MsgRAMAddress2" = "num:hextoint(ecu:get('Can.MCMCAN2BASERAM'))"!][!//
[!VAR "MsgRAMAddress1" = "num:hextoint(ecu:get('Can.MCMCAN1BASERAM'))"!][!//
[!VAR "MsgRAMAddress0" = "num:hextoint(ecu:get('Can.MCMCAN0BASERAM'))"!][!//
[!VAR "IndexCnt" = "num:i(0)"!][!//
[!FOR "HwIndex" = "0" TO "$HwControllerCount - '1'"!][!//
[!LOOP "./CanController/*"!][!//
[!VAR "Kernel0" = "num:i(0)"!][!//
[!VAR "Kernel1" = "num:i(0)"!][!//
[!VAR "Kernel2" = "num:i(0)"!][!//
[!VAR "TempControllerId" = "num:i(CanControllerId)"!][!//
[!IF "$HwIndex = $TempControllerId"!][!//
[!IF "CanControllerActivation = 'true'"!][!//
[!VAR "BaseAddress" = "num:i(CanControllerBaseAddress)"!][!//
[!IF "(($BaseAddress = num:hextoint(ecu:get('Can.Node20BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node21BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node22BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node23BaseAddress'))))"!][!//
[!VAR "FLSSA" = "$MsgRAMAddress2"!][!//
[!VAR "Kernel2" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "(($BaseAddress = num:hextoint(ecu:get('Can.Node10BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node11BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node12BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node13BaseAddress'))))"!][!//
[!VAR "FLSSA" = "$MsgRAMAddress1"!][!//
[!VAR "Kernel1" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "(($BaseAddress = num:hextoint(ecu:get('Can.Node00BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node01BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node02BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node03BaseAddress'))))"!][!//
[!VAR "FLSSA" = "$MsgRAMAddress0"!][!//
[!VAR "Kernel0" = "num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "NoOfTxDedBuff" = "num:i(0)"!][!//
[!VAR "NoOfRxDedBuff" = "num:i(0)"!][!//
[!VAR "SizeOfTxQue" = "num:i(0)"!][!//
[!VAR "RxFIFOCount" = "num:i(0)"!][!//
[!VAR "TxQueueCount" = "num:i(0)"!][!//
[!VAR "SizeOfRxFIFO1" = "num:i(0)"!][!//
[!VAR "SizeOfRxFIFO0" = "num:i(0)"!][!//
[!VAR "RxFIFO1Threshold" = "num:i(0)"!][!//
[!VAR "RxFIFO0Threshold" = "num:i(0)"!][!//
[!VAR "NoOfSIDTemp" = "num:i(0)"!][!//
[!VAR "NoOfXIDTemp" = "num:i(0)"!][!//
[!LOOP "../../CanHardwareObject/*"!][!//
    [!IF "node:refexists(CanControllerRef) ='true'"!][!//
    [!VAR "HwControllerId" = "num:i(node:ref(CanControllerRef)/CanControllerId)"!][!//
    [!IF "$HwControllerId = $TempControllerId"!][!//
    [!IF "CanObjectType = 'TRANSMIT' and CanHwObjectCount = '1' "!][!//
    [!VAR "NoOfTxDedBuff" = "num:i($NoOfTxDedBuff+1)"!][!//
    [!VAR "CanObjectIdTemp" = "num:i(CanObjectId)"!][!//
    [!ENDIF!][!//
    [!IF "CanObjectType = 'TRANSMIT' and CanHwObjectCount > '1' and CanHwObjectCount < '33' "!][!//
    [!VAR "SizeOfTxQue" = "num:i(CanHwObjectCount)"!][!//
    [!IF "$TxQueueCount > '0' "!][!//
    [!ERROR!][!//
    The Cancontroller [!"$HwControllerId"!] is configured with more than <1> HTH with the CanHwObjectCount is greater than value <1>.This type of configuration is allowed for
    a specific controller is limited with <1> since controller is supported with one TxQueue.
    [!ENDERROR!][!//
    [!ENDIF!][!//
    [!VAR "TxQueueCount" = "num:i($TxQueueCount+1)"!][!//
    [!ENDIF!][!//
    [!IF "CanObjectType = 'RECEIVE' and CanHwObjectCount = '1' "!][!//
    [!VAR "NoOfRxDedBuff" = "num:i($NoOfRxDedBuff+1)"!][!//
    [!ENDIF!][!//
    [!IF "CanObjectType = 'RECEIVE' and CanHwObjectCount > '1' "!][!//
    [!IF "$RxFIFOCount > '1' "!][!//
    [!ERROR!][!//
    The Cancontroller[!"$HwControllerId"!] is configured with more than <2> HRH which contains the CanHwObjectCount is greater than value <1>.This type of configuration is allowed for
    a specific controller is limited with <2> since controller is supported with 2 RXFIFO's only.
    [!ENDERROR!][!//
    [!ENDIF!][!//
    [!IF "$RxFIFOCount = '1' "!][!//
    [!VAR "SizeOfRxFIFO1" = "num:i(CanHwObjectCount)"!][!//
    [!VAR "RxFIFO1Threshold" = "num:i(CanHwFIFOThreshold)"!][!//
    [!VAR "RxFIFOCount" = "num:i($RxFIFOCount+1)"!][!//
    [!ENDIF!][!//
    [!IF "$RxFIFOCount = '0' "!][!//
    [!VAR "SizeOfRxFIFO0" = "num:i(CanHwObjectCount)"!][!//
    [!VAR "RxFIFO0Threshold" = "num:i(CanHwFIFOThreshold)"!][!//
    [!VAR "RxFIFOCount" = "num:i($RxFIFOCount+1)"!][!//
    [!ENDIF!][!//
    [!ENDIF!][!//
    [!IF "CanObjectType = 'RECEIVE'"!][!//
    [!VAR "HwFilterCount" = "num:i(count(CanHwFilter/*))"!][!//
    [!FOR "HwFilterindx" = "1" TO "$HwFilterCount"!][!//
    [!VAR "HwFilterValue" = "num:i(CanHwFilter/*[position()=$HwFilterindx]/CanHwFilterCode)"!][!//
    [!IF "CanIdType = 'STANDARD' or CanIdType = 'MIXED' "!][!//
    [!VAR "NoOfSIDTemp" = "num:i($NoOfSIDTemp+1)"!][!//
    [!ENDIF!][!//
    [!IF "CanIdType = 'EXTENDED' or CanIdType = 'MIXED' "!][!//
    [!VAR "NoOfXIDTemp" = "num:i($NoOfXIDTemp+1)"!][!//
    [!ENDIF!][!//
    [!ENDFOR!][!//
    [!ENDIF!][!//
    [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$SizeOfRxFIFO1 < $RxFIFO1Threshold "!][!//
   [!ERROR!][!//
   The configurtion value of CanHwFIFOThreshold of HRH refernced by Cancontroller [!"$TempControllerId"!] is wrong.The value of CanHwFIFOThreshold
   shall be less than or equal with CanHwObjectCount.
[!ENDERROR!][!//
[!ENDIF!][!//
[!IF "$SizeOfRxFIFO0 < $RxFIFO0Threshold "!][!//
  [!ERROR!][!//
  The configurtion value of CanHwFIFOThreshold of HRH refernced by Cancontroller [!"$TempControllerId"!] is wrong.The value of CanHwFIFOThreshold
  shall be less than or equal with CanHwObjectCount.
  [!ENDERROR!][!//
[!ENDIF!][!//
[!IF "$NoOfSIDTemp > 128 "!][!//
  [!ERROR!][!//
  The toatl number of standard message filter elements configuration for controller [!"$TempControllerId"!] is greater than limit value <128>
  [!ENDERROR!][!//
[!ENDIF!][!//
[!IF "$NoOfXIDTemp > 64 "!][!//
  [!ERROR!][!//
  The toatl number of Extended message filter elements configuration for controller [!"$TempControllerId"!] is greater than limit value <64>
  [!ENDERROR!][!//
[!ENDIF!][!//
[!IF "$NoOfRxDedBuff > 64 "!][!//
[!ERROR!][!//
The total number of HRH configuration for the controller [!"$TempControllerId"!] is greater than limit value <64>
[!ENDERROR!][!//
[!ENDIF!][!//
[!IF "$NoOfTxDedBuff > 32 "!][!//
[!ERROR!][!//
The total number of HTH is configured for the controller [!"$TempControllerId"!]is greater than limit value <32>
[!ENDERROR!][!//
[!ENDIF!][!//
[!IF "(($NoOfTxDedBuff+$SizeOfTxQue) > 32 )"!][!//
[!ERROR!][!//
The total number of Hardware object's (sum of all HTH CanHwObjectCount) used by the controller[!"$TempControllerId"!] is greater than limit value <32>
[!ENDERROR!][!//
[!ENDIF!][!//
[!VAR "MsgRAMElementSize" = "num:i(4)"!][!//
[!IF "$FDNodesPresent = '1'"!][!//
[!VAR "ControllerBRConfigTemp" = "num:i(count(./CanControllerBaudrateConfig/*))"!][!//
[!FOR "BaudrateIndx" = "1" TO "$ControllerBRConfigTemp"!][!//
[!IF "(node:exists(CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/*))"!][!//
[!VAR "MsgRAMElementSize" = "num:i(18)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!VAR "FLESA" = "$FLSSA  +($NoOfSIDTemp * 4) "!][!//
[!VAR "F0SA"  = "$FLESA  +($NoOfXIDTemp  * 2 * 4) "!][!//
[!VAR "F1SA"  = "$F0SA   +($SizeOfRxFIFO0 * $MsgRAMElementSize *4) "!][!//
[!VAR "RBSA"  = "$F1SA   +($SizeOfRxFIFO1 * $MsgRAMElementSize *4) "!][!//
[!VAR "EFSA"  = "$RBSA +($NoOfRxDedBuff * $MsgRAMElementSize *4) "!][!//
[!VAR "TBSA"  = "$EFSA +(($NoOfTxDedBuff+$TxQueueCount) * 2 * 4) "!][!//
[!VAR "NODEENDADDRESS" = "$TBSA +( ($NoOfTxDedBuff+$TxQueueCount)* $MsgRAMElementSize *4) "!][!//
[!IF "$Kernel2 = '1' "!][!//
[!VAR "MsgRAMAddress2" = "num:i($NODEENDADDRESS)"!][!//
[!IF "$NODEENDADDRESS > ecu:get('Can.MCMCAN2ENDRAM') "!][!//
  [!ERROR!][!//
    M_CAN is configured to use more MessageRAM than allowed by CAN Kernel
  [!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$Kernel1 = '1' "!][!//
[!VAR "MsgRAMAddress1" = "num:i($NODEENDADDRESS)"!][!//
[!IF "$NODEENDADDRESS > ecu:get('Can.MCMCAN1ENDRAM') "!][!//
   [!ERROR!][!//
     M_CAN is configured to use more MessageRAM than allowed by CAN Kernel
   [!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$Kernel0 = '1' "!][!//
[!VAR "MsgRAMAddress0" = "num:i($NODEENDADDRESS)"!][!//
[!IF "$NODEENDADDRESS > ecu:get('Can.MCMCAN2ENDRAM') "!][!//
  [!ERROR!][!//
     M_CAN is configured to use more MessageRAM than allowed by CAN Kernel
  [!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$IndexCnt > '0'"!][!//
,
[!ENDIF!][!//
[!AUTOSPACING!]
[!INDENT "2"!][!//
[!VAR "IndexCnt" = "num:i($IndexCnt+1)"!][!//
 {
   /* Start Address of each section within the Message RAM */
  {
[!IF "$NoOfSIDTemp > 0 "!][!//
 [!"num:inttohex($FLSSA)"!]UL,
[!ELSE!][!//
 0x00000000UL,
[!ENDIF!][!//
[!IF "$NoOfXIDTemp > 0 "!][!//
 [!"num:inttohex($FLESA)"!]UL,
[!ELSE!][!//
 0x00000000UL,
[!ENDIF!][!//
[!IF "$SizeOfRxFIFO0 > 0 "!][!//
 [!"num:inttohex($F0SA)"!]UL,
[!ELSE!][!//
 0x00000000UL,
[!ENDIF!][!//
[!IF "$SizeOfRxFIFO1 > 0 "!][!//
 [!"num:inttohex($F1SA)"!]UL,
[!ELSE!][!//
 0x00000000UL,
[!ENDIF!][!//
[!IF "$NoOfRxDedBuff > 0 "!][!//
 [!"num:inttohex($RBSA)"!]UL,
[!ELSE!][!//
 0x00000000UL,
[!ENDIF!][!//
[!IF "($NoOfTxDedBuff+$TxQueueCount) > 0"!][!//
 [!"num:inttohex($EFSA)"!]UL,
 [!"num:inttohex($TBSA)"!]UL
 },
[!ELSE!][!//
 0x00000000UL,
 0x00000000UL
},
[!ENDIF!][!//
 [!"num:inttohex($NoOfTxDedBuff)"!]U, [!//
[!"num:inttohex($NoOfTxDedBuff+$TxQueueCount)"!]U [!//
[!IF "$RXFIFO0UsedStatus = 1"!][!//
,[!//
[!"num:inttohex($SizeOfRxFIFO0)"!]U, [!//
[!"num:inttohex($RxFIFO0Threshold)"!]U [!//
[!ENDIF!][!//
[!IF "$RXFIFO1UsedStatus = '1'"!][!//
,[!//
[!"num:inttohex($SizeOfRxFIFO1)"!]U, [!//
[!"num:inttohex($RxFIFO1Threshold)"!]U [!//
[!ENDIF!][!//
[!IF "$TxQueueUsedStatus = '1'"!][!//
,[!//
[!"num:inttohex($SizeOfTxQue)"!]U, [!//
[!IF "$SizeOfTxQue = '0'"!][!//
[!"('CAN_FALSE')"!]
[!ELSE!][!//
[!"('CAN_TRUE')"!]
[!ENDIF!][!//
[!ENDIF!][!//
}[!//
[!ENDINDENT!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!]

};
[!ENDSELECT!][!//

/*******************************************************************************
                 CAN Controller Baudrate Configurations
********************************************************************************
           { CANx_NBTP value, Configured Baudrate ,FDBaudrate config Index ,
             FD Support Status  }
********************************************************************************
                           Baudrate Setting
    (uint32)((NSJW << 25)|(NBRP << 16)|(TSEG1 << 8)|(TSEG2))
    NSJW   -> CanControllerSyncJumpWidth - 1
    NTSEG1 -> CanControllerPropSeg + CanControllerSeg1 - 1
    NTSEG2 -> CanControllerSeg2 - 1
*******************************************************************************/
[!SELECT "as:modconf('Can')[1]/CanConfigSet/./*[1]"!][!//
[!VAR "CanMcuClockRef" = "''"!][!//
[!VAR "FDIndex" = "num:i(0)"!][!//
[!LOOP "./CanController/*"!][!//
[!IF "./CanControllerActivation = 'true'"!][!//
[!IF "node:refexists(./CanCpuClockRef) ='true'"!][!//
[!VAR "CanMcuClockRefNext" = "node:path(node:ref(./CanCpuClockRef))"!][!//
[!IF "$CanMcuClockRef = ''"!][!//
[!VAR "CanMcuClockRef" = "$CanMcuClockRefNext"!][!//
[!ENDIF!][!//
[!IF "$CanMcuClockRefNext != $CanMcuClockRef"!][!//
[!ERROR!][!//
CanCpuClockRef is wrong for the controller[!"num:i(CanControllerId)"!] should refer to the same MCU clock in all CanController Configurations of the CanConfigset.!
[!ENDERROR!][!//
 [!ENDIF!][!//
[!VAR "CanMcuClockRef" = "$CanMcuClockRefNext"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
static const Can_ControllerBaudrateConfigType
                             Can_kBaudrateConfig[[!"'CAN_NOOF_BAUDRATE_CONFIG'"!]] =
{
[!VAR "HwControllerCount" = "num:i(count(./CanController/*))"!][!//
[!VAR "IndexCnt" = "num:i(0)"!][!//
[!FOR "HwIndex" = "0" TO "$HwControllerCount - '1'"!][!//
[!LOOP "./CanController/*"!][!//
[!NOCODE!][!//
[!VAR "CANModuleRefClk" = "(node:ref(CanCpuClockRef)/McuPllDistributionSettingConfig/McuMCanClockSourceSelection  )"!][!//
[!IF "$CANModuleRefClk ='MCAN_CLOCK_SOURCE_DISABLED_SEL0'"!][!//
   [!ERROR!][!//
    [!CODE!][!//
    The CAN module clock source (McuMCanClockSourceSelection)shall be configured with MCAN_CLOCK_SOURCE_MCANI_SEL1 or MCAN_CLOCK_SOURCE_OSC_SEL2 with in the MCU configuration
    [!ENDCODE!][!//
   [!ENDERROR!][!//
[!ENDIF!][!//
[!SELECT "as:modconf('Mcu')/*"!][!//
    [!IF "$CANModuleRefClk ='MCAN_CLOCK_SOURCE_OSC_SEL2'"!][!//
        [!VAR "CANModuleClock" = "(num:i(1000000)) *(num:i(../McuGeneralConfiguration/McuMainOscillatorFrequency))"!][!//
    [!ENDIF!][!//
[!ENDSELECT!][!//
[!IF "$CANModuleRefClk ='MCAN_CLOCK_SOURCE_MCANI_SEL1'"!][!//
    [!VAR "CANModuleClock" = "(node:ref(CanCpuClockRef)/McuPllDistributionSettingConfig/McuMCanFrequency)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "$HwIndex = num:i(CanControllerId)"!][!//
[!IF "CanControllerActivation ='true'"!][!//
[!IF "$IndexCnt > 0"!][!//
,
[!ENDIF!][!//
[!VAR "IndexCnt" = "num:i($IndexCnt+1)"!][!//
[!VAR "MaxConfigCount" = "num:i(count(./CanControllerBaudrateConfig/*))"!][!//
[!VAR "NBRP" = "num:i(0)"!][!//
[!FOR "i" = "1" TO "$MaxConfigCount"!][!//
[!VAR "TimeQuantaNanoSecond" = "num:i(1000000000) div ( ((num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg))+(num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1))+(num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2))+1) * (num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerBaudRate)*num:i(1000)))"!][!//
[!VAR "NBRP" = "num:i((((($TimeQuantaNanoSecond) * num:i($CANModuleClock)) div num:i(1000000000)) - 1)+ 0.5)"!][!//
[!//
[!VAR "GetMinReqBR" = "(($CANModuleClock) div (512 * (3+ (num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1 - 1))+(num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2 - 1)))))"!][!//

[!VAR "GetMaxReqBR" = "(($CANModuleClock) div (3+ (num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1 - 1))+(num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2 - 1))))"!][!//
[!IF "(( num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerBaudRate)*num:i(1000)) < $GetMinReqBR)"!][!//
[!ERROR!]
Configured Baud rate [!"num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerBaudRate)"!] kbps for controller Id [!"num:i(CanControllerId)"!] of CanConfigSet [!"node:name(../..)"!] is Less than the Minimum allowed Baud rate [!"num:i($GetMinReqBR + 1)"!].
Acceptable Baud rate range depends upon configured CAN Module clock, CanControllerPropSeg, CanControllerSeg1 and CanControllerSeg2.
Change baud rate or any of the above parameters to get configured baud rate with in allowed range.
[!ENDERROR!][!//
[!ENDIF!][!//
[!//
[!IF "(( num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerBaudRate)*num:i(1000)) > $GetMaxReqBR)"!][!//
[!ERROR!]
Configured Baud rate [!"num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerBaudRate)"!] kbps for controller Id [!"num:i(CanControllerId)"!] of CanConfigSet [!"node:name(../..)"!] is greater than the Maximum allowed Baud rate [!"num:i($GetMaxReqBR - 1)"!].
Acceptable Baud rate range depends upon configured CAN Module clock, CanControllerPropSeg, CanControllerSeg1 and CanControllerSeg2.
Change baud rate or any of the above parameters to get configured baud rate with in allowed range.
[!ENDERROR!][!//
[!ENDIF!][!//
[!IF "(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1) < (./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSyncJumpWidth)"!][!//
[!ERROR!]
 CanControllerSeg1 should be greater than or equal to CanControllerSyncJumpWidth in CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!]!
[!ENDERROR!]
[!ENDIF!][!//
[!IF "(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2) < (./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSyncJumpWidth)"!][!//
 [!ERROR!]
 CanControllerSeg2 should be greater than or equal to CanControllerSyncJumpWidth in CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!]!
 [!ENDERROR!]
[!ENDIF!][!//
[!IF "num:i(4)> num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1 + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2) > num:i(385)"!][!//
 [!ERROR!]
CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range: 4<=(CanControllerPropSeg + CanControllerSeg1 + CanControllerSeg2)<=385.
 [!ENDERROR!]
[!ENDIF!][!//
[!IF "num:i($NBRP) > num:i(511) "!][!//
  [!ERROR!]
The Calculated NBRP value by using the configured baudrate parameters and CAN module clock greater than the allowed range value.Change any of the above parameters to get NBRP value with in allowed range.
 [!ENDERROR!]
[!ENDIF!][!//
[!VAR "ActualBRP" = "num:i($NBRP)"!][!//
[!IF "(node:exists(CanControllerBaudrateConfig/*[position()=$i]/CanControllerFdBaudrateConfig/*))"!][!//
[!VAR "TimeQuantaNanoSecond" = "num:i(1000000000) div (((num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerFdBaudrateConfig/CanControllerPropSeg))+(num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerFdBaudrateConfig/CanControllerSeg1))+(num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerFdBaudrateConfig/CanControllerSeg2))+1) * (num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerFdBaudrateConfig/CanControllerFdBaudRate)*num:i(1000)))"!][!//
[!VAR "FBRP" = "num:i((((($TimeQuantaNanoSecond) * num:i($CANModuleClock)) div num:i(1000000000)) - 1)+ 0.5)"!][!//
[!IF "num:i($FBRP)< num:i($ActualBRP)"!][!//
 [!ERROR!]
The Calculated DBRP value by using the configured FD baudrate parameters in the container CanControllerFdBaudrateConfig belonging to CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] should be greater than or equal to the calculated NBRP value by using the configured baudrate parameters in CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!]!
 [!ENDERROR!]
[!ENDIF!][!//
[!ENDIF!][!//
[!VAR "NBRP" = "bit:shl((num:i($NBRP)),16)"!][!//
[!VAR "SJW" = "bit:shl((num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSyncJumpWidth - 1)),25)"!][!//
[!VAR "TSEG1" = "bit:shl((num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1 - 1)),8)"!][!//
[!VAR "TSEG2" = "num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2 - 1)"!][!//
[!VAR "tempNBTR" = "bit:or($NBRP,$SJW)"!][!//
[!VAR "tempNBTR" = "bit:or($tempNBTR,$TSEG1)"!][!//
[!VAR "tempNBTR" = "bit:or($tempNBTR,$TSEG2)"!][!//
  {
    /* Configured Baudrate -> [!"num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerBaudRate)"!] kbps */
    /* Actual Baudrate     -> [!"(num:i($CANModuleClock) div (((num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1))+(num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2))+1) * (num:i($ActualBRP)+1))) div 1000"!] kbps */
    /* NBRP   -> [!"num:i($ActualBRP)"!] */
    /* NSJW   -> [!"num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSyncJumpWidth - 1)"!]  */
    /* NTSEG1 -> [!"num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1 - 1)"!]  */
    /* NTSEG2 -> [!"num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2 - 1)"!]  */
    [!"num:inttohex($tempNBTR)"!]U,
    [!"num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerBaudRate)"!]U[!//
[!IF "$FDNodesPresent = '1'"!][!//
,
[!IF "(node:exists(CanControllerBaudrateConfig/*[position()=$i]/CanControllerFdBaudrateConfig/*))"!][!//
    [!"num:inttohex($FDIndex)"!]U,
[!VAR "FDIndex" = "num:i($FDIndex + 1)"!][!//
    CAN_TRUE
[!ELSE!][!//
    0x0U,
    CAN_FALSE
[!ENDIF!][!//
[!ENDIF!][!//
  }[!//
[!IF "$i < $MaxConfigCount"!][!//
,
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//

};
[!IF "$FDNodesPresent != 0"!][!//
/*******************************************************************************
                CAN Controller FD Config Parameters
********************************************************************************
           { CANx_DBTP value, TrcvDelayCompensationOffset, BRS Status }
********************************************************************************

        (uint32)((DBRP << 16)|(DTSEG1 << 8)|(DTSEG2 << 4)|(DSJW ))
        DSJW   -> CanControllerSyncJumpWidth - 1
        DTSEG1 -> CanControllerPropSeg + CanControllerSeg1 - 1
        DTSEG2 -> CanControllerSeg2 - 1
*******************************************************************************/

static const Can_ControllerFDBaudrateConfigType
                            Can_kFDBaudrateConfig[[!"'CAN_NOOF_FDBAUDRATE_CONFIG'"!]] =
{
[!VAR "HwControllerCount" = "num:i(count(./CanController/*))"!][!//
[!VAR "InstanceCnt" = "num:i(0)"!][!//
[!FOR "HwIndex" = "0" TO "$HwControllerCount - '1'"!][!//
[!LOOP "./CanController/*"!][!//
[!NOCODE!][!//
[!VAR "CANModuleRefClk" = "(node:ref(CanCpuClockRef)/McuPllDistributionSettingConfig/McuMCanClockSourceSelection  )"!][!//
[!IF "$CANModuleRefClk ='MCAN_CLOCK_SOURCE_DISABLED_SEL0'"!][!//
   [!ERROR!][!//
    [!CODE!][!//
    The CAN module clock source (McuMCanClockSourceSelection  )shall be configured with MCAN_CLOCK_SOURCE_MCANI_SEL1 or MCAN_CLOCK_SOURCE_OSC_SEL2 with in the MCU configuration
    [!ENDCODE!][!//
   [!ENDERROR!][!//
[!ENDIF!][!//
[!SELECT "as:modconf('Mcu')/*"!][!//
    [!IF "$CANModuleRefClk ='MCAN_CLOCK_SOURCE_OSC_SEL2'"!][!//
        [!VAR "CANModuleClock" = "(num:i(1000000)) *(num:i(../McuGeneralConfiguration/McuMainOscillatorFrequency))"!][!//
    [!ENDIF!][!//
[!ENDSELECT!][!//
[!IF "$CANModuleRefClk ='MCAN_CLOCK_SOURCE_MCANI_SEL1'"!][!//
    [!VAR "CANModuleClock" = "(node:ref(CanCpuClockRef)/McuPllDistributionSettingConfig/McuMCanFrequency)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "CanControllerActivation ='true'"!][!//
[!IF "$HwIndex = num:i(CanControllerId)"!][!//
[!VAR "ControllerBRConfigTemp" = "num:i(count(./CanControllerBaudrateConfig/*))"!][!//
[!FOR "BaudrateIndx" = "1" TO "$ControllerBRConfigTemp"!][!//
[!IF "(node:exists(CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/*))"!][!//
[!IF "$InstanceCnt > 0"!][!//
,
[!ENDIF!][!//
[!VAR "InstanceCnt" = "num:i($InstanceCnt + 1)"!][!//
[!VAR "i" = "num:i(1)"!][!//
[!VAR "TimeQuantaNanoSecond" = "num:i(1000000000) div (((num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/CanControllerPropSeg))+(num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/CanControllerSeg1))+(num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/CanControllerSeg2))+1) * (num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/CanControllerFdBaudRate)*num:i(1000)))"!][!//
[!VAR "FBRP" = "num:i((((($TimeQuantaNanoSecond) * num:i($CANModuleClock)) div num:i(1000000000)) - 1)+ 0.5)"!][!//
[!//
[!VAR "GetMinReqBR" = "(($CANModuleClock) div (512 * (3+ (num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerSeg1 - 1))+(num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerSeg2 - 1)))))"!][!//
[!VAR "GetMaxReqBR" = "(($CANModuleClock) div (3+ (num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerSeg1 - 1))+(num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerSeg2 - 1))))"!][!//
[!//
[!IF "( (num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/CanControllerFdBaudRate)*num:i(1000)) < $GetMinReqBR)"!][!//
[!ERROR!]
Configured Baud rate [!"num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerFdBaudRate)"!] kbps for controller Id [!"num:i(CanControllerId)"!] of CanConfigSet [!"node:name(../..)"!] is Less than the Minimum allowed Baud rate [!"num:i($GetMinReqBR + 1)"!].
Acceptable Baud rate range depends upon configured CAN Module clock, CanControllerPropSeg, CanControllerSeg1 and CanControllerSeg2.
Change baud rate or any of the above parameters to get configured baud rate with in allowed range.
[!ENDERROR!]
[!ENDIF!][!//
[!//
[!IF "(( num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerFdBaudRate)*num:i(1000)) > $GetMaxReqBR)"!][!//
[!ERROR!]
Configured Baud rate [!"num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerFdBaudRate)"!] kbps for controller Id [!"num:i(CanControllerId)"!] of CanConfigSet [!"node:name(../..)"!] is greater than the Maximum allowed Baud rate [!"num:i($GetMaxReqBR - 1)"!].
Acceptable Baud rate range depends upon configured CAN Module clock, CanControllerPropSeg, CanControllerSeg1 and CanControllerSeg2.
Change baud rate or any of the above parameters to get configured baud rate with in allowed range.
[!ENDERROR!]
[!ENDIF!]
[!//
[!IF "num:i(4) > num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerSeg1 + ./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerSeg2) > num:i(49)"!][!//
 [!ERROR!]
 CanControllerFdBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig)"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range: 4<=(CanControllerPropSeg + CanControllerSeg1 + CanControllerSeg2)<=49.
 [!ENDERROR!]
[!ENDIF!][!//
[!IF "num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/CanControllerSeg1) < num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/CanControllerSyncJumpWidth)"!][!//
 [!ERROR!]
  The CanControllerSeg1 should be greater than or equal to CanControllerSyncJumpWidth in CanControllerFDBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig)"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!]
 [!ENDERROR!]
 [!ENDIF!][!//
[!IF "num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/CanControllerSeg2) < num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/CanControllerSyncJumpWidth)"!][!//
 [!ERROR!]
  The CanControllerSeg2 should be greater than or equal to CanControllerSyncJumpWidth in CanControllerFDBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig)"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!]
 [!ENDERROR!]
[!ENDIF!][!//
[!IF "num:i($FBRP) > num:i(31)"!][!//
 [!ERROR!]
  The Calculated DBRP value by using the configured baudrate parameters and CAN module clock greater than the allowed range value.Change any of the above parameters to get NBRP value with in allowed range.
 [!ENDERROR!]
[!ENDIF!][!//
[!VAR "DSJW" = "num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerSyncJumpWidth - 1)"!][!//
[!VAR "DTSEG1" = "bit:shl((num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/CanControllerSeg1 - 1)),8)"!][!//
[!VAR "DTSEG2" = "bit:shl((num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerSeg2 - 1)),4)"!][!//
[!VAR "ActualFBRP" = "num:i($FBRP)"!][!//
[!VAR "FBRP" = "bit:shl((num:i($FBRP)),16)"!][!//
[!VAR "tempFNBTR" = "bit:or($FBRP,$DSJW)"!][!//
[!VAR "tempFNBTR" = "bit:or($tempFNBTR,$DTSEG1)"!][!//
[!VAR "tempFNBTR" = "bit:or($tempFNBTR,$DTSEG2)"!][!//
[!IF "(node:exists(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/CanControllerTrcvDelayCompensationOffset) = 'true')"!][!//
[!VAR "TDCO" = "num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/CanControllerTrcvDelayCompensationOffset)"!][!//
[!ELSE!][!//
[!VAR "TDCO" = "0"!][!//
[!ENDIF!][!//
[!VAR "TDCEnable" = "0"!][!//
[!VAR "TDC" = "0"!][!//
[!IF "$TDCO > (num:i(0))"!][!//
[!VAR "TDCEnable" = "1"!][!//
[!ENDIF!][!//
[!VAR "TDC" = "bit:shl((num:i($TDCEnable)),23)"!][!//
[!VAR "tempNTDCR" = "$TDCO"!][!//
[!VAR "tempFNBTR" = "bit:or($tempFNBTR,$TDC)"!][!//
  {
  /* Configured FD Baudrate -> [!"num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerFdBaudRate)"!] kbps */
  /* Actual Baudrate     -> [!"(num:i($CANModuleClock) div (((num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/CanControllerSeg1))+(num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/CanControllerSeg2))+1) * (num:i($ActualFBRP)+1))) div 1000"!] kbps */
  /* DBRP   -> [!"num:i($ActualFBRP)"!] */
  /* DSJW   -> [!"num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerSyncJumpWidth - 1)"!]  */
  /* DTSEG1 -> [!"num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/CanControllerSeg1 - 1)"!]  */
  /* DTSEG2 -> [!"num:i(./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerSeg2 - 1)"!]  */
  [!"num:inttohex($tempFNBTR)"!]U,
  [!"num:inttohex($tempNTDCR)"!]U,
[!IF "./CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig//CanControllerTxBitRateSwitch = 'true'"!][!//
  CAN_TRUE
[!ELSE!][!//
  CAN_FALSE
[!ENDIF!][!//
  }[!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!]

};
[!ENDIF!][!//
[!ENDSELECT!][!//

/*******************************************************************************
              CAN Controller Handling of Events : Interrupt/Polling
********************************************************************************
        { CanTxProcessing Mode, CanRxProcessing Mode,
          CanBusoffProcessing Mode, CanWakeupProcessing Mode }
********************************************************************************
           Note: If the CAN controller is not activated then,
                 { 0U, 0U, 0U, 0U } will be generated
*******************************************************************************/
[!SELECT "as:modconf('Can')[1]/CanConfigSet/./*[1]"!][!//
[!VAR "NumControllers" = "num:i(count(./CanController/*))"!][!//
[!VAR "IndexCnt" = "num:i(0)"!][!//
/* [!"./@name"!] -> CAN Controller - Handling of Events */
static const Can_EventHandlingType
                              Can_kEventHandlingConfig[[!"'CAN_NOOF_CONTROLLER'"!]] =
{
[!FOR "TempIndex" = "0" TO "$NumControllers - 1"!][!//
[!LOOP "./CanController/*"!][!//
[!IF "CanControllerId = $TempIndex"!][!//
[!IF "CanControllerActivation = 'true'"!][!//
[!NOCODE!][!//
    [!IF "CanRxProcessing != CanWakeupProcessing"!][!//
    [!CODE!][!//
        [!ERROR!][!//
The CanWakeupProcessing and RxProcessing for the Can controller[!"CanControllerId"!] shall be configured as same (ie both are Polling or Interrupt)
        [!ENDERROR!][!//
    [!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "$IndexCnt > 0"!][!//
,
[!ENDIF!][!//
[!VAR "IndexCnt" = "num:i($IndexCnt+1)"!]
 { { [!//
[!CALL "CG_IsEventPolled", "event" = "CanTxProcessing "!],[!//
[!CALL "CG_IsEventPolled", "event" = "CanRxProcessing"!],[!//
[!CALL "CG_IsEventPolled", "event" = "CanBusoffProcessing"!],[!//
[!CALL "CG_IsEventPolled", "event" = "CanWakeupProcessing"!][!//
} }[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!]

};
[!ENDSELECT!][!//

[!IF "$RxObjectCountMax > 0"!][!//
[!IF "$StandardIdOnly = '1' or $MixedOnly = '1' "!][!//
[!/*******************************************************************************/!][!//
[!/*Receive Hardware Object Configurations validation check*/!][!//
[!/********************************************************************************/!][!//
/*******************************************************************************
               Receive Hardware Object Configurations
********************************************************************************
        This is the combination of SID filter elements
        Rx Object -> { Combination of Mask and filter value S0, HRH HwObject Id,
        Hw Controller Id, Rx BufferType, [Pretended Support Status] }
********************************************************************************
       Note: [1] If the associated CAN Controller is not activated then,
                   Hw Controller Id -> 255
             [2] If CanFilterMaskRef is not configured then,
                   Mask -> 0x7ff - for STANDARD Msg Id Type
*******************************************************************************/
[!SELECT "as:modconf('Can')[1]/CanConfigSet/./*[1]"!][!//
[!VAR "HwObjctMaxTemp" = "num:i(count(./CanHardwareObject/*))"!][!//
static const Can_SIDFilterConfigType
                      Can_kSIDFilterConfig[[!"'CAN_NOOF_SID_FILTER_CONFIG'"!]] =
{
[!VAR "NoOfInstance" = "num:i(0)"!][!//
[!VAR "RxFIFOCount" = "num:i(0)"!][!//
[!VAR "LastCfgCntrlId" = "num:i(0)"!][!//
[!VAR "RxDedicatedbuffIndex" = "num:i(0)"!][!//
[!FOR "Cntrlindx" = "0" TO "$HwObjctMaxTemp"!][!//
[!FOR "HwObjindx" = "1" TO "$HwObjctMaxTemp"!][!//
[!VAR "RxBufferType" = "','"!][!//
[!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanObjectType = 'RECEIVE'"!][!//
[!IF "node:refexists(./CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef) ='true'"!][!//
[!IF "(node:ref(./CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef)/CanControllerActivation = 'true')"!][!//
[!VAR "TempObjId" = "./CanHardwareObject/*[position()=$HwObjindx]/CanObjectId"!][!//
[!IF "$TempObjId = $Cntrlindx"!][!//
[!VAR "HwControllerId" = "num:i(node:ref(./CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef)/CanControllerId)"!][!//
[!IF "(node:ref(./CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef)/CanRxProcessing = 'POLLING')"!][!//
[!IF "(node:exists(./CanHardwareObject/*[position()=$HwObjindx]/CanMainFunctionRWPeriodRef))"!][!//
[!ELSE!]
[!ERROR!][!//
The HRH Hardare object[!"$TempObjId"!] shall be referenced or enabled (CanMainFunctionRWPeriodRef) with cyclic period,since the referenced controller is configured with Rx processing mode as POLLING
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$LastCfgCntrlId > $HwControllerId"!][!//
[!ERROR!][!//
The HRH Hardare object shall be configured in the increasing order of refrenced CanControllerId
Eg.: HRH object in order: HRHs of CanControllerId 0, HRHs of CanControllerId 1, etc..
[!ENDERROR!][!//
[!ENDIF!][!//
[!IF "$LastCfgCntrlId != $HwControllerId"!][!//
[!VAR "RxFIFOCount" = "num:i(0)"!][!//
[!VAR "RxDedicatedbuffIndex" = "num:i(0)"!][!//
[!ENDIF!][!//
[!VAR "LastCfgCntrlId" = "num:i($HwControllerId)"!][!//
[!VAR "HwFilterCount" = "num:i(count(./CanHardwareObject/*[position()=$HwObjindx]/CanHwFilter/*))"!][!//
[!IF "$HwFilterCount = '0'"!][!//
[!ERROR!][!//
The CanHwFilter  contianer shall be configured for the CanHwObjectId[!"$TempObjId"!] since CanHwObjectType is configured as "RECEIVE"
[!ENDERROR!][!//
[!ENDIF!][!//
[!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanHwObjectCount = '1'"!][!//
[!VAR "RxBufferType" = "concat(RxBufferType,'CAN_RX_DED_BUFFER')"!][!//
[!VAR "SFEC" = "bit:shl(num:i(7),27)"!][!//
[!ELSE!][!//
[!IF "$RxFIFOCount = '1'"!][!//
[!VAR "RxBufferType" = "concat(RxBufferType,'CAN_RX_FIFO1')"!][!//
[!VAR "SFEC" = "bit:shl(num:i(2),27)"!][!//
[!VAR "RxFIFOCount" = "num:i($RxFIFOCount+1)"!][!//
[!ELSEIF "$RxFIFOCount = '0'"!][!//
[!VAR "RxBufferType" = "concat(RxBufferType,'CAN_RX_FIFO0')"!][!//
[!VAR "SFEC" = "bit:shl(num:i(1),27)"!][!//
[!VAR "RxFIFOCount" = "num:i($RxFIFOCount+1)"!][!//
[!ELSE!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!FOR "HwFilterindx" = "1" TO "$HwFilterCount"!][!//
[!IF "((./CanHardwareObject/*[position()=$HwObjindx]/CanIdType = 'STANDARD') or(./CanHardwareObject/*[position()=$HwObjindx]/CanIdType = 'MIXED'))"!][!//
[!VAR "HwFilterValue" = "num:i(./CanHardwareObject/*[position()=$HwObjindx]/CanHwFilter/*[position()=$HwFilterindx]/CanHwFilterCode)"!][!//
[!VAR "HwFilterMaskValue" = "num:i(./CanHardwareObject/*[position()=$HwObjindx]/CanHwFilter/*[position()=$HwFilterindx]/CanHwFilterMask)"!][!//
[!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanIdType = 'STANDARD'"!][!//
[!IF "$HwFilterValue > 2047 or $HwFilterMaskValue > 2047"!][!//
[!ERROR!][!//
Error in the configurtion of "CanHwFilterCode" or "CanHwFilterMask" value for the CanHwObjectId[!"$TempObjId"!]: Allowed range for STANDARD CanIdType is: 0 to 0x7FF.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanIdType = 'MIXED'"!][!//
[!IF "$HwFilterValue != 0"!][!//
[!IF "$HwFilterValue < 262144 or $HwFilterValue > 536608768"!][!//
[!ERROR!][!//
Error in the configurtion of "CanHwFilterCode" value for the CanHwObjectId[!"$TempObjId"!]: The value
of CanHwFilterMask and CanHwFilterCode shall be within range 0x0 and 0x40000 to 0x1FFC0000 value If the CanIdType is MIXED.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!VAR "HwFilterValue" = "bit:and($HwFilterValue,536608768)"!][!//
[!VAR "HwFilterValue" = "bit:shr($HwFilterValue,18)"!][!//
[!VAR "HwFilterMaskValue" = "bit:and($HwFilterMaskValue,536608768)"!][!//
[!VAR "HwFilterMaskValue" = "bit:shr($HwFilterMaskValue,18)"!][!//
[!ENDIF!][!//
[!IF "$NoOfInstance > 0 "!][!//
,
[!ENDIF!][!//
[!VAR "PretendedSupportMsg" = "num:i(0)"!][!//
[!IF "$PublicIcomSupport > num:i(0)"!][!//
[!SELECT "as:modconf('Can')[1]/CanConfigSet/./*[1]"!][!//
[!LOOP "CanIcom/CanIcomConfig/*"!][!//
[!VAR "IcomRxMsgCount" = "num:i(count(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*))"!][!//
[!FOR "Rxindx" = "1" TO "num:i($IcomRxMsgCount)"!][!//
[!IF " $HwFilterValue = num:i(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomMessageId)"!][!//
[!VAR "PretendedSupportMsg" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!VAR "NoOfInstance" = "$NoOfInstance + num:i(1)"!][!//
[!VAR "SFT" = "bit:shl(num:i(2),30)"!][!//
[!VAR "SFID1" = "bit:shl(num:i($HwFilterValue),16)"!][!//
[!IF "$RxBufferType = 'CAN_RX_DED_BUFFER'"!][!//
[!VAR "SFID2" = "(num:i($RxDedicatedbuffIndex))"!][!//
[!ELSE!][!//
[!VAR "SFID2" = "num:i($HwFilterMaskValue)"!][!//
[!ENDIF!][!//
[!VAR "SIDFilterElementS0" = "bit:or($SFT,$SFEC)"!][!//
[!VAR "SIDFilterElementS0" = "bit:or($SIDFilterElementS0,$SFID1)"!][!//
[!VAR "SIDFilterElementS0" = "bit:or($SIDFilterElementS0,$SFID2)"!][!//
 {[!"num:inttohex($SIDFilterElementS0)"!]U,[!//
 [!"num:i(./CanHardwareObject/*[position()=$HwObjindx]/CanObjectId)"!]U,[!//
 [!"num:i($HwControllerId)"!]U,[!//
 [!"$RxBufferType"!][!//
[!IF "$PublicIcomSupport > num:i(0)"!][!//
,[!//
[!IF "$PretendedSupportMsg = 1 "!][!//
CAN_TRUE[!//
[!ELSE!][!//
CAN_FALSE[!//
[!ENDIF!][!//
[!ENDIF!][!//
 }[!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!VAR "RxDedicatedbuffIndex" = "num:i($RxDedicatedbuffIndex+1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!]

};
[!ENDSELECT!]
[!ENDIF!][!//

[!IF "$ExtendedOnly = '1' or $MixedOnly = '1'"!][!//
[!SELECT "as:modconf('Can')[1]/CanConfigSet/./*[1]"!][!//
[!VAR "HwObjctMaxTemp" = "num:i(count(./CanHardwareObject/*))"!][!//
/*******************************************************************************
      This is the combination of XID filer elements
      Rx Object -> { Combination of Mask and filter valueF0,Combination of
      Mask and filter valueF1, HRH HwObject Id, Hw Controller Id, Rx BufferType,
            [Pretended Support Status]  }
********************************************************************************
       Note: [1] If the associated CAN Controller is not activated then,
                   this shall not be generated
             [2] If CanFilterMaskRef is not configured then,
                   Mask -> 0x1fffffff - for EXTENDED/MIXED Msg Id Type
*******************************************************************************/
static const Can_XIDFilterConfigType
                      Can_kXIDFilterConfig[[!"'CAN_NOOF_XID_FILTER_CONFIG'"!]] =
{
[!VAR "NoOfInstance" = "num:i(0)"!][!//
[!VAR "ControllerConfigMaxTemp" = "num:i(count(./CanController/*))"!][!//
[!FOR "Cntrlindx" = "0" TO "$ControllerConfigMaxTemp - 1"!][!//
[!VAR "RxDedicatedbuffIndex" = "num:i(0)"!][!//
[!VAR "RxFIFOCount" = "num:i(0)"!][!//
[!FOR "HwObjindx" = "1" TO "$HwObjctMaxTemp"!][!//
[!VAR "RxBufferType" = "','"!][!//
[!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanObjectType = 'RECEIVE'"!][!//
[!IF "node:refexists(./CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef) ='true'"!][!//
[!IF "(node:ref(./CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef)/CanControllerActivation = 'true')"!][!//
[!VAR "HwControllerId" = "num:i(node:ref(./CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef)/CanControllerId)"!][!//
[!IF "(node:ref(./CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef)/CanRxProcessing = 'POLLING')"!][!//
[!IF "(node:exists(./CanHardwareObject/*[position()=$HwObjindx]/CanMainFunctionRWPeriodRef))"!][!//
[!ELSE!]
[!ERROR!][!//
The HRH Hardware object[!"num:i(./CanHardwareObject/*[position()=$HwObjindx]/CanObjectId)"!] shall be referenced or enabled (CanMainFunctionRWPeriodRef) with cyclic period,since the referenced controller is configured with Rx processing mode as POLLING
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$Cntrlindx = $HwControllerId"!][!//
[!VAR "HwFilterCount" = "num:i(count(./CanHardwareObject/*[position()=$HwObjindx]/CanHwFilter/*))"!][!//
[!VAR "ValidIndx" = "num:i(0)"!][!//
[!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanHwObjectCount = '1'"!][!//
[!VAR "RxBufferType" = "concat(RxBufferType,'CAN_RX_DED_BUFFER')"!][!//
[!VAR "EFEC" = "bit:shl(num:i(7),29)"!][!//
[!ELSE!][!//
[!IF "$RxFIFOCount = '1'"!][!//
[!VAR "RxBufferType" = "concat(RxBufferType,'CAN_RX_FIFO1')"!][!//
[!VAR "EFEC" = "bit:shl(num:i(2),29)"!][!//
[!VAR "RxFIFOCount" = "num:i($RxFIFOCount+1)"!][!//
[!ENDIF!][!//
[!IF "$RxFIFOCount = '0'"!][!//
[!VAR "RxBufferType" = "concat(RxBufferType,'CAN_RX_FIFO0')"!][!//
[!VAR "EFEC" = "bit:shl(num:i(1),29)"!][!//
[!VAR "RxFIFOCount" = "num:i($RxFIFOCount+1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!FOR "HwFilterindx" = "1" TO "$HwFilterCount"!][!//
[!VAR "HwFilterValue" = "num:i(./CanHardwareObject/*[position()=$HwObjindx]/CanHwFilter/*[position()=$HwFilterindx]/CanHwFilterCode)"!][!//
[!VAR "CanHwFilterMaskValue" = "num:i(./CanHardwareObject/*[position()=$HwObjindx]/CanHwFilter/*[position()=$HwFilterindx]/CanHwFilterMask)"!][!//
[!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanIdType = 'EXTENDED'"!][!//
[!IF "$HwFilterValue > 536870911"!][!//
[!ERROR!][!//
Error in the configurtion of "CanHwFilterCode" value for the CanHwObjectId
[!"num:i(./CanHardwareObject/*[position()=$HwObjindx]/CanObjectId)"!]: Allowed range for EXTENDED CanIdType is: 0 to 0x1FFFFFFF.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanIdType = 'MIXED'"!][!//
[!IF "$HwFilterValue != 0"!][!//
[!IF "$HwFilterValue < 262144 or $HwFilterValue > 536608768"!][!//
[!ERROR!][!//
Error in the configurtion of "CanHwFilterCode" value for the CanHwObjectId [!"num:i(./CanHardwareObject/*[position()=$HwObjindx]/CanObjectId)"!]: The value
of CanHwFilterCode shall be within range 0x0 and 0x40000 to 0x1FFC0000 value If the CanIdType is MIXED
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanIdType = 'MIXED' or ./CanHardwareObject/*[position()=$HwObjindx]/CanIdType = 'EXTENDED'"!][!//
[!IF "$ValidIndx > 0 or $NoOfInstance > 0 "!][!//
,
[!ENDIF!][!//
[!VAR "NoOfInstance" = "$NoOfInstance + num:i(1)"!][!//
[!VAR "ValidIndx" = "$ValidIndx + num:i(1)"!][!//
[!VAR "EFT" = "bit:shl(num:i(2),30)"!][!//
[!VAR "XIDFilterElemntF0" = "num:i($HwFilterValue)"!][!//
[!IF "$RxBufferType = 'CAN_RX_DED_BUFFER'"!][!//
[!VAR "EFID2" = "(num:i($RxDedicatedbuffIndex))"!][!//
[!ELSE!][!//
[!VAR "EFID2" = "num:i(./CanHardwareObject/*[position()=$HwObjindx]/CanHwFilter/*[position()=$HwFilterindx]/CanHwFilterMask)"!][!//
[!VAR "EFID2" = "bit:and($EFID2,536870911)"!][!//
[!ENDIF!][!//
[!VAR "PretendedSupportMsg" = "num:i(0)"!][!//
[!IF "$PublicIcomSupport > num:i(0)"!][!//
[!SELECT "as:modconf('Can')[1]/CanConfigSet/./*[1]"!][!//
[!LOOP "CanIcom/CanIcomConfig/*"!][!//
[!VAR "IcomRxMsgCount" = "num:i(count(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*))"!][!//
[!FOR "Rxindx" = "1" TO "num:i($IcomRxMsgCount)"!][!//
[!IF " $HwFilterValue = num:i(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomMessageId)"!][!//
[!VAR "PretendedSupportMsg" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!VAR "XIDFilterElemntF0" = "bit:or($XIDFilterElemntF0,$EFEC)"!][!//
[!VAR "XIDFilterElemntF1" = "bit:or($EFID2,$EFT)"!][!//
 {[!"num:inttohex($XIDFilterElemntF0)"!]U,[!//
 [!"num:inttohex($XIDFilterElemntF1)"!]U,[!//
 [!"num:i(./CanHardwareObject/*[position()=$HwObjindx]/CanObjectId)"!]U,[!//
 [!"num:i($HwControllerId)"!]U,[!//
 [!"$RxBufferType"!][!//
[!IF "$PublicIcomSupport > num:i(0)"!][!//
,[!//
 [!IF "$PretendedSupportMsg = 1 "!][!//
 CAN_TRUE[!//
[!ELSE!][!//
 CAN_FALSE[!//
[!ENDIF!][!//
[!ENDIF!][!//
}[!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!VAR "RxDedicatedbuffIndex" = "num:i($RxDedicatedbuffIndex+1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!]

};
[!ENDSELECT!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$TxObjectCountMax > 0"!][!//
/*******************************************************************************
               Transmit Hardware Object Configurations
********************************************************************************
 Tx Object -> { HTH HwObject Id, BufferIndex, HwControllerId, [FdPaddValue],
               Hardware ObjectType , Tx BufferType, TriggerTransmitStatus}
********************************************************************************
       Note: [1] If the associated CAN Controller is not activated then,
                   this shall not be generated.
*******************************************************************************/
[!SELECT "as:modconf('Can')[1]/CanConfigSet/./*[1]"!][!//
[!VAR "HwObjctMaxTemp" = "num:i(count(CanHardwareObject/*))"!][!//
static const Can_TxHwObjectConfigType
                        Can_kTxHwObjectConfig[[!"'CAN_NOOF_TX_HARDWARE_OBJECTS'"!]] =
{
[!VAR "NoOfInstance" = "num:i(0)"!][!//
[!VAR "TxHwObjCount" = "num:i(0)"!][!//
[!VAR "TxDedicatedBuffIndex" = "num:i(0)"!][!//
[!VAR "LastCfgCntrlId" = "num:i(0)"!][!//
[!VAR "LastCfgHrhId" = "num:i(0)"!][!//
[!FOR "HwObjindx" = "0" TO "$HwObjctMaxTemp - 1"!][!//
[!IF "CanHardwareObject/*[CanObjectId= $HwObjindx]/CanObjectType = 'RECEIVE'"!][!//
[!VAR "LastCfgHrhId" = "num:i($HwObjindx)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!FOR "Cntrlindx" = "$LastCfgHrhId+1" TO "$HwObjctMaxTemp - '1'"!][!//
[!FOR "HwObjindx" = "0" TO "$HwObjctMaxTemp"!][!//
[!IF "CanHardwareObject/*[position()=$HwObjindx]/CanObjectType = 'TRANSMIT'"!][!//
[!IF "node:refexists(CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef) ='true'"!][!//
[!IF "(node:ref(CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef)/CanControllerActivation = 'true')"!][!//
[!VAR "TempObjId" = "./CanHardwareObject/*[position()=$HwObjindx]/CanObjectId"!][!//
[!IF "$LastCfgHrhId > $TempObjId"!][!//
[!ERROR!][!//
  ERROR: All HTHs should have greater CanObjectId than all HRHs.
    Eg.: CanObjectId in increasing order: HRHs of CanControllerId 0, HRHs of CanControllerId
    1, HTHs of CanControllerId 0, HTHs of CanControllerId 1, etc..
[!ENDERROR!][!//
[!ENDIF!][!//
[!IF "$Cntrlindx = $TempObjId"!][!//
[!IF "(node:ref(./CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef)/CanTxProcessing = 'POLLING')"!][!//
[!IF "(node:exists(./CanHardwareObject/*[position()=$HwObjindx]/CanMainFunctionRWPeriodRef))"!][!//
[!ELSE!]
[!ERROR!][!//
The HTH Hardare object[!"$TempObjId"!] shall be referenced or enabled (CanMainFunctionRWPeriodRef) with cyclic period,since the referenced controller is configured with Tx processing mode as POLLING
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!VAR "HwControllerId" = "num:i(node:ref(CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef)/CanControllerId)"!][!//
[!IF "$LastCfgCntrlId != $HwControllerId"!][!//
[!VAR "TxDedicatedBuffIndex" = "num:i(0)"!][!//
[!ENDIF!][!//
[!IF "$LastCfgCntrlId > $HwControllerId"!][!//
[!ERROR!][!//
The HTH shall be configured in the increasing order of refrenced CanControllerId
Eg.: HTH object in order: HTHs of CanControllerId 0, HTHs of CanControllerId 1, etc..
[!ENDERROR!][!//
[!ENDIF!][!//
[!IF "$TxDedicatedBuffIndex > 0 or $NoOfInstance > 0"!][!//
,
[!ENDIF!][!//
[!VAR "LastCfgCntrlId" = "num:i($HwControllerId)"!][!//
[!VAR "TxHwObjCount" = "num:i(CanHardwareObject/*[position()=$HwObjindx]/CanHwObjectCount)"!][!//
[!IF "$TxHwObjCount > 32"!][!//
[!ERROR!][!//
The value of CanHwobjectCount of HTH with CanHwObjectId [!"num:i(CanHardwareObject/*[position()=$HwObjindx]/CanObjectId)"!] is gretaer than value 32
[!ENDERROR!][!//
[!ENDIF!][!//
[!VAR "NoOfInstance" = "$NoOfInstance + num:i(1)"!][!//
[!IF "CanHardwareObject/*[position()=$HwObjindx]/CanHwObjectCount = '1'"!][!//
 {[!"num:i(CanHardwareObject/*[position()=$HwObjindx]/CanObjectId)"!]U,[!//
 [!"num:i($TxDedicatedBuffIndex)"!]U,[!//
 [!"num:i($HwControllerId)"!]U,[!//
[!VAR "TxDedicatedBuffIndex" = "$TxDedicatedBuffIndex + num:i(1)"!][!//
[!ELSE!][!//
 {[!//
[!"num:i(CanHardwareObject/*[position()=$HwObjindx]/CanObjectId)"!]U,[!//
 [!"num:i(255)"!]U,[!//
 [!"num:i($HwControllerId)"!]U,[!//
[!ENDIF!][!//
[!IF "$FDNodesPresent = 1"!][!//
[!IF "(node:exists(CanHardwareObject/*[position()=$HwObjindx]/CanFdPaddingValue) = 'true' )"!][!//
 [!"num:i(CanHardwareObject/*[position()=$HwObjindx]/CanFdPaddingValue)"!]U,[!//
[!ELSE!][!//
 0U,[!//
[!ENDIF!][!//
[!ENDIF!][!//
 CAN_ID_[!"./CanHardwareObject/*[position()=$HwObjindx]/CanIdType"!],[!//
[!IF "CanHardwareObject/*[position()=$HwObjindx]/CanHwObjectCount = '1'"!][!//
 [!"('CAN_TX_DED_BUFFER')"!],[!//
[!ELSE!][!//
 [!"('CAN_TX_QUEUE')"!],[!//
[!ENDIF!][!//
[!IF "CanHardwareObject/*[position()=$HwObjindx]/CanTriggerTransmitEnable ='true'"!][!//
 [!"('CAN_TRUE')"!]}[!//
[!ELSE!][!//
 [!"('CAN_FALSE')"!]}[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!ERROR!][!//
CanControllerRef is not Configured for CanHardwareObject [!"num:i(CanHardwareObject/*[position()=$HwObjindx]/CanObjectId)"!]
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!]

};
[!ENDSELECT!][!//
[!ENDIF!][!//

[!IF "$MultiCycleWriteOperCfg > 0"!][!//
[!SELECT "as:modconf('Can')[1]/CanConfigSet/./*[1]"!][!//
[!VAR "Count" = "num:i(0)"!][!//
/*******************************************************************************
        Transmit Hardware Object Configurations for multiple period selected
********************************************************************************
 Tx Object -> { TxbufferMaskvalue,HW MO Id,HwControllerId}
********************************************************************************
           Note:
*******************************************************************************/
static const Can_HthMaskObjectConfigType
                       Can_kHthMaskObjectConfig[CAN_NOOF_HWOBJECT_TX_PERIODS] =
{
[!AUTOSPACING!]
[!NOCODE!]
[!INDENT "2"!]
[!VAR "ControllerConfigMaxTemp" = "num:i(count(./CanController/*))"!][!//
[!LOOP "../../CanGeneral/*[1]/CanMainFunctionRWPeriods/*"!][!//
    [!VAR "MainFuncName" = "node:name(.)"!][!//
    [!LOOP "../../../../CanConfigSet/./*[1]/CanController/*"!][!//
        [!VAR "BUFFR" = "num:i('00000000')"!][!//
        [!VAR "Maskval" = "num:i('00000000')"!][!//
        [!VAR "BuffIndex" = "num:i(0)"!][!//
        [!VAR "FifoCnt" = "num:i(0)"!][!//
        [!IF "CanControllerActivation = 'true'"!][!//
        [!IF "CanTxProcessing   = 'POLLING'"!][!//
            [!VAR "CntrlId" = "num:i(CanControllerId)"!][!//
            [!LOOP "../../../../CanConfigSet/./*[1]/CanHardwareObject/*"!][!//
                [!IF "CanObjectType = 'TRANSMIT'"!][!//
                    [!IF "node:refexists(CanMainFunctionRWPeriodRef)='true'"!][!//
                        [!IF "$CntrlId = num:i(node:ref(CanControllerRef)/CanControllerId)"!][!//
                            [!IF "num:i(CanHwObjectCount) > 1 "!][!//
                                [!VAR "FifoCnt" = "num:i($FifoCnt + 1)"!][!//
                                [!ELSE!]
                                [!VAR "BuffIndex" = "num:i($BuffIndex + 1)"!][!//
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                        [!VAR "MainFuncNameConfig"= "substring-after(CanMainFunctionRWPeriodRef,'Can/Can/')"!][!//
                        [!VAR "MainFuncNameConfig"= "substring-after($MainFuncNameConfig,'/')"!][!//
                        [!IF "$MainFuncNameConfig = $MainFuncName and $CntrlId = num:i(node:ref(CanControllerRef)/CanControllerId)"!][!//
                            [!IF "num:i(CanHwObjectCount) = 1 "!][!//
                                [!VAR "BUFFR" = "bit:bitset($BUFFR,($BuffIndex - 1))"!][!//
                                [!VAR "Maskval" = "bit:or($BUFFR,'00000000')"!][!//
                            [!ENDIF!][!//
                            [!CODE!]
[!IF "$Count > '0'"!][!//
,
[!ENDIF!][!//
[!VAR "Count" = "num:i($Count+'1')"!][!//
{[!"num:inttohex($Maskval)"!]U, [!//
 [!"num:i(CanObjectId)"!]U, [!//
 [!"num:i($CntrlId)"!]U[!//
}[!//
[!ENDCODE!][!//
                            [!VAR "BUFFR" = "num:i(0)"!][!//
                            [!VAR "Maskval" = "num:i(00000000)"!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDLOOP!]
        [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDLOOP!]
[!ENDLOOP!]
[!ENDINDENT!]
[!ENDNOCODE!]

};

/*******************************************************************************
              Tx HwObject handling for Multiple index is selected
********************************************************************************
     Each Period informations -> { Startindex , Endindex}
********************************************************************************

*******************************************************************************/
static const Can_PeriodHthMaskConfigType
                       Can_kPeriodHthMaskConfig[CAN_NOOF_TX_PERIODS_CONFIG] =
{
[!VAR "StartIndx" = "num:i(0)"!][!//
[!VAR "Instance" = "num:i(0)"!][!//
[!VAR "PeriodTempName" = "''"!][!//
[!LOOP "../../CanGeneral/*[1]/CanMainFunctionRWPeriods/*"!][!//
[!VAR "Count" = "num:i(0)"!][!//
[!VAR "EndIndex" = "num:i(0)"!][!//
[!VAR "MainFuncName" = "node:name(.)"!][!//
[!LOOP "../../../../CanConfigSet/./*[1]/CanHardwareObject/*"!][!//
[!IF "CanObjectType = 'TRANSMIT'"!][!//
[!IF "(node:ref(CanControllerRef)/CanTxProcessing) = 'POLLING'"!][!//
[!IF "node:refexists(CanMainFunctionRWPeriodRef)='true'"!][!//
[!VAR "MainFuncNameConfig"= "substring-after(CanMainFunctionRWPeriodRef,'Can/Can/')"!][!//
[!VAR "MainFuncNameConfig"= "substring-after($MainFuncNameConfig,'/')"!][!//
[!IF "$MainFuncNameConfig = $MainFuncName"!][!//
[!VAR "Count" = "num:i(1)"!][!//
[!VAR "EndIndex" = "num:i($EndIndex+ '1')"!][!//
[!IF "$MainFuncNameConfig != $PeriodTempName"!][!//
[!VAR "Instance" = "num:i($Instance+ '1')"!][!//
[!ENDIF!][!//
[!VAR "PeriodTempName" = "$MainFuncNameConfig"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$Count > '0'"!][!//
{[!"num:i($StartIndx)"!]U, [!//
[!"num:i($EndIndex)"!]U},[!//
[!VAR "StartIndx" = "num:i($StartIndx + $EndIndex)"!][!//
[!ENDIF!][!//
[!ENDLOOP!]

};
[!ENDSELECT!][!//

/*******************************************************************************
        Can_MainFunction_Write() API supported with multiple cycle
*******************************************************************************/
[!FOR "HwObjindx" = "0" TO "$Instance - 1"!][!//
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
void Can_17_McmCan_MainFunction_Write_[!"$HwObjindx"!]( void )
{

 Can_lTxPeriodHandler([!"$HwObjindx"!]);

}

[!ENDFOR!][!//
[!ENDIF!][!//
[!IF "$MultiCycleReadOperCfg > 0"!][!//
/*******************************************************************************
        Receive Hardware Object Configurations for multiple period selected
********************************************************************************
Rx Object -> { RxbufferMaskvalue,HwObjId,HwControllerId,BufferType}
********************************************************************************

*******************************************************************************/
[!SELECT "as:modconf('Can')[1]/CanConfigSet/./*[1]"!][!//
[!VAR "Count" = "num:i(0)"!][!//
static const Can_HrhMaskObjectConfigType
                       Can_kHrhMaskObjectConfig[CAN_NOOF_HWOBJECT_RX_PERIODS] =
{
[!AUTOSPACING!]
[!NOCODE!]
[!INDENT "2"!]
[!VAR "ControllerConfigMaxTemp" = "num:i(count(./CanController/*))"!][!//
[!LOOP "../../CanGeneral/*[1]/CanMainFunctionRWPeriods/*"!][!//
    [!VAR "MainFuncName" = "node:name(.)"!][!//
    [!LOOP "../../../../CanConfigSet/./*[1]/CanController/*"!][!//
        [!VAR "BUFFR" = "num:i('00000000')"!][!//
        [!VAR "Maskval" = "num:i('00000000')"!][!//
        [!VAR "BuffIndex" = "num:i(0)"!][!//
        [!VAR "FifoCnt" = "num:i(0)"!][!//
        [!IF "CanControllerActivation = 'true'"!][!//
        [!IF "CanRxProcessing   = 'POLLING'"!][!//
            [!VAR "CntrlId" = "num:i(CanControllerId)"!][!//
            [!LOOP "../../../../CanConfigSet/./*[1]/CanHardwareObject/*"!][!//
                [!IF "CanObjectType = 'RECEIVE'"!][!//
                    [!IF "node:refexists(CanMainFunctionRWPeriodRef)='true'"!][!//
                        [!IF "$CntrlId = num:i(node:ref(CanControllerRef)/CanControllerId)"!][!//
                            [!IF "num:i(CanHwObjectCount) > 1 "!][!//
                                [!VAR "FifoCnt" = "num:i($FifoCnt + 1)"!][!//
                                [!ELSE!]
                                [!VAR "BuffIndex" = "num:i($BuffIndex + 1)"!][!//
                                [!IF "num:i($BuffIndex) > 32 "!][!//
                                [!VAR "BuffIndex" = "num:i(0)"!][!//
                                [!VAR "BuffIndex" = "num:i($BuffIndex + 1)"!][!//
                                [!ENDIF!][!//
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                        [!VAR "MainFuncNameConfig"= "substring-after(CanMainFunctionRWPeriodRef,'Can/Can/')"!][!//
                        [!VAR "MainFuncNameConfig"= "substring-after($MainFuncNameConfig,'/')"!][!//
                        [!IF "$MainFuncNameConfig = $MainFuncName and $CntrlId = num:i(node:ref(CanControllerRef)/CanControllerId)"!][!//
                            [!IF "num:i(CanHwObjectCount) = 1 "!][!//
                                [!VAR "BUFFR" = "bit:bitset($BUFFR,($BuffIndex - 1))"!][!//
                                [!VAR "Maskval" = "bit:or($BUFFR,'00000000')"!][!//
                            [!ENDIF!][!//
[!CODE!]
[!IF "$Count > '0'"!][!//
,
[!ENDIF!][!//
[!VAR "Count" = "num:i($Count+'1')"!][!//
{[!"num:inttohex($Maskval)"!]U, [!//
 [!"num:i(CanObjectId)"!]U, [!//
 [!"num:i($CntrlId)"!]U, [!//
[!IF "num:i(CanHwObjectCount) = 1 "!][!//
 CAN_RX_DED_BUFFER[!//
[!ELSE!][!//
[!IF "$FifoCnt = 1 "!][!//
 CAN_RX_FIFO0[!//
[!ELSE!][!//
 CAN_RX_FIFO1[!//
[!ENDIF!][!//
[!ENDIF!][!//
}[!//
[!ENDCODE!][!//
                            [!VAR "BUFFR" = "num:i(0)"!][!//
                            [!VAR "Maskval" = "num:i(00000000)"!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDLOOP!]
        [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDLOOP!]
[!ENDLOOP!]
[!ENDINDENT!]
[!ENDNOCODE!]

};

/*******************************************************************************
        Rx HwObject handling for Multiple index is selected
********************************************************************************
  Each Rx Period informations -> { Startindex , Endindex }
********************************************************************************
           Note:
*******************************************************************************/
static const Can_PeriodHrhMaskConfigType
                          Can_kPeriodHrhMaskConfig[CAN_NOOF_RX_PERIODS_CONFIG]=
{
[!VAR "StartIndx" = "num:i(0)"!][!//
[!VAR "Instance" = "num:i(0)"!][!//
[!VAR "PeriodTempName" = "''"!][!//
[!LOOP "../../CanGeneral/*[1]/CanMainFunctionRWPeriods/*"!][!//
[!VAR "Count" = "num:i(0)"!][!//
[!VAR "EndIndex" = "num:i(0)"!][!//
[!VAR "MainFuncName" = "node:name(.)"!][!//
[!LOOP "../../../../CanConfigSet/./*[1]/CanHardwareObject/*"!][!//
[!IF "CanObjectType = 'RECEIVE'"!][!//
[!IF "(node:ref(CanControllerRef)/CanRxProcessing) = 'POLLING'"!][!//
[!IF "node:refexists(CanMainFunctionRWPeriodRef)='true'"!][!//
[!VAR "MainFuncNameConfig" = "substring-after(CanMainFunctionRWPeriodRef,'Can/Can/')"!][!//
[!VAR "MainFuncNameConfig" = "substring-after($MainFuncNameConfig,'/')"!][!//
[!IF "$MainFuncNameConfig = $MainFuncName"!][!//
[!VAR "EndIndex" = "num:i($EndIndex+ '1')"!][!//
[!VAR "Count" = "num:i(1)"!][!//
[!IF "$MainFuncNameConfig != $PeriodTempName"!][!//
[!VAR "Instance" = "num:i($Instance+ '1')"!][!//
[!ENDIF!][!//
[!VAR "PeriodTempName" = "$MainFuncNameConfig"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$Count > '0'"!][!//
{[!"num:i($StartIndx)"!]U, [!//
[!"num:i($EndIndex)"!]U},[!//
[!VAR "StartIndx" = "num:i($StartIndx + $EndIndex)"!][!//
[!ENDIF!][!//
[!ENDLOOP!]

};
[!ENDSELECT!][!//

/*******************************************************************************
        Can_MainFunction_Read() API supported with multiple cycle
*******************************************************************************/
[!FOR "HwObjindx" = "0" TO "$Instance - 1"!][!//
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
void Can_17_McmCan_MainFunction_Read_[!"$HwObjindx"!]( void )
{

 Can_lRxPeriodHandler([!"$HwObjindx"!]);

}

[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "$PublicIcomSupport > num:i(0)"!][!//
/*******************************************************************************
              CAN ICOM Configuration Parameters
********************************************************************************
         {IcomRxMsgFirstIndex, Number of RxMessages, IcomWakeOnBusOff}
********************************************************************************
           Note:
 1. IcomRxMsgFirstIndex : First Receive message configuration index value
 2. IcomRxMsgCount: Total no of RxMsg configured  for the ICOM configuration
 3. IcomWakeOnBusOff:  ICOM Wake On Bus off status
*******************************************************************************/
[!SELECT "as:modconf('Can')[1]/CanConfigSet/./*[1]"!][!//
[!VAR "IcomConfigCount" = "num:i(count(./CanIcom/CanIcomConfig/*))"!][!//
[!VAR "StartIndx1" = "num:i(0)"!][!//
[!VAR "EndIndx1" = "num:i(0)"!][!//
static const Can_IcomConfigType  Can_kIcomConfig[CAN_NOOF_ICOM_CONFIGURATIONS] =
{
[!LOOP "CanIcom/CanIcomConfig/*"!][!//
[!FOR "Index" = "1" TO "num:i($IcomConfigCount)"!][!//
[!IF "$Index = num:i(./CanIcomConfigId)"!][!//
[!IF "$Index > 1 "!][!//
,
[!ENDIF!][!//
[!VAR "EndIndx1" = "num:i(count(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*))"!][!//
 {
 [!"num:i($StartIndx1)"!]U, [!//
[!"num:i($EndIndx1)"!]U, [!//
[!IF "(./CanIcomWakeOnBusOff  ) = 'true' "!][!//
CAN_TRUE
[!ELSE!][!//
CAN_FALSE
[!ENDIF!][!//
 }[!//
[!VAR "StartIndx1" = "num:i($StartIndx1+$EndIndx1)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDLOOP!]

};
[!ENDSELECT!][!//

/*******************************************************************************
            CAN ICOM Rx Message Configuration
********************************************************************************
        {IcomMsgId,IcomMaskRef,IcomCntrVal,[IcomFirstSignalIndex,
        IcomNoOfSignalIndex,]IcomPayloadLength, IcomLengthErrr}
********************************************************************************
1. IcomMsgId            : ICOM receive Message Id value.
2. IcomMaskRef          : ICOM receive Message filter mask value.
3. IcomCntrVal          : Counter value for receive no of times of a
                          specified ID Message.
4. IcomPayloadLength    : ICOM receive message payload length.
5. IcomFirstSignalIndex : First RxSignal index value of the message signal
                          configuration.
6. IcomNoOfSignalIndex  : Total no of message signal configurations.
7. IcomLengthErr        : Defines that the MCU shall wake if a payload error
                          occur.
                          TRUE  :MCU shall wake if a payload error
                          occur.
                          FALSE :MCU shall not wake if a payload error
                          occur.
*******************************************************************************/
[!SELECT "as:modconf('Can')[1]/CanConfigSet/./*[1]"!][!//
[!VAR "IcomConfigCount" = "num:i(count(./CanIcom/CanIcomConfig/*))"!][!//
[!VAR "StartIndx" = "num:i(0)"!][!//
[!VAR "EndIndx" = "num:i(0)"!][!//
[!VAR "PosIndx" = "num:i(0)"!][!//
static const Can_IcomRxMsgConfigType
                        Can_kIcomRxMsgConfig[CAN_NOOF_ICOM_MSGCONFIGURATIONS] =
{
[!LOOP "CanIcom/CanIcomConfig/*"!][!//
[!FOR "Index" = "1" TO "num:i($IcomConfigCount)"!][!//
[!IF "$Index = num:i(./CanIcomConfigId)"!][!//
[!VAR "IcomRxMsgCount" = "num:i(count(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*))"!][!//
[!FOR "Rxindx" = "1" TO "num:i($IcomRxMsgCount)"!][!//
[!IF "$PosIndx > 0 "!][!//
,
[!ENDIF!][!//
[!VAR "PosIndx" = "num:i($PosIndx+ 1)"!][!//
[!VAR "NormalMsgSupport" = "num:i(0)"!][!//
[!VAR "IcomMsgId" = "num:i(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomMessageId)"!][!//
[!SELECT "as:modconf('Can')[1]/CanConfigSet/*[1]"!][!//
[!LOOP "./CanHardwareObject/*"!][!//
[!IF "CanObjectType = 'RECEIVE' "!][!//
[!VAR "HwFilterCount" = "num:i(count(CanHwFilter/*))"!][!//
[!FOR "HwFilterindx" = "1" TO "$HwFilterCount"!][!//
[!VAR "MsgId" = "num:i(CanHwFilter/*[position()=$HwFilterindx]/CanHwFilterCode)"!][!//
[!IF "$MsgId = $IcomMsgId"!][!//
[!VAR "NormalMsgSupport" = "1"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!IF "$NormalMsgSupport = 0"!][!//
[!ERROR!][!//
 All the Icom Message shall be configured as a Normal Message
[!ENDERROR!][!//
[!ENDIF!][!//
{[!"num:i(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomMessageId)"!]U, [!//
[!IF "(node:exists(CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomMessageIdMask))"!][!//
[!"num:i(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomMessageIdMask)"!]U, [!//
[!ELSE!][!//
0U, [!//
[!ENDIF!][!//
[!IF "(node:exists(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomCounterValue))"!][!//
[!"num:i(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomCounterValue)"!]U, [!//
[!ELSE!][!//
0U, [!//
[!ENDIF!][!//
[!"num:i(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomPayloadLength)"!]U,[!//
[!IF "node:exists(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomRxMessageSignalConfig/*[1]) = 'true'"!][!//
[!VAR "EndIndx" = "num:i(count(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomRxMessageSignalConfig/*))"!][!//
 [!"num:i($StartIndx)"!]U, [!//
 [!"num:i($EndIndx)"!]U, [!//
[!VAR "StartIndx" = "num:i($StartIndx+$EndIndx)"!][!//
[!ELSE!][!//
 0U, [!//
 0U, [!//
[!ENDIF!][!//
[!IF "(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomPayloadLengthError) = 'true'"!][!//
CAN_TRUE[!//
[!ELSE!][!//
CAN_FALSE[!//
[!ENDIF!][!//
}[!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDLOOP!]

};
[!ENDSELECT!][!//

[!SELECT "as:modconf('Can')[1]/CanConfigSet/./*[1]"!][!//
[!VAR "ICOMMsgSignalSupport" = " 0 "!][!//
[!VAR "IcomRxMsgSignalCount" = " 0 "!][!//
[!LOOP "CanIcom/CanIcomConfig/*"!][!//
[!FOR "Index" = "1" TO "num:i($IcomConfigCount)"!][!//
[!IF "$Index = num:i(./CanIcomConfigId)"!][!//
[!VAR "IcomRxMsgCount" = "num:i(count(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*))"!][!//
[!FOR "Rxindx" = "1" TO "num:i($IcomRxMsgCount)"!][!//
[!IF "node:exists(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomRxMessageSignalConfig/*[1]) = 'true'"!][!//
[!VAR "ICOMMsgSignalSupport" = "1"!][!//
[!VAR "IcomRxMsgSignalCount" = "num:i(count(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomRxMessageSignalConfig/*))"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDLOOP!]
[!ENDSELECT!][!//

[!IF "$IcomRxMsgSignalCount > 0 "!][!//
/*******************************************************************************
          CAN ICOM Rx Signal Configuration
********************************************************************************
        { IcomSignalMask, IcomSignalValue, IcomSignalOper }
********************************************************************************
           Note:
1. IcomSignalMask  :ICOM receive signal filter mask value.
2. IcomSignalValue :ICOM receive signal value for the comparison with
                    IcomSignalMask value
3. IcomSignalOper  :Defines the operation, which shall be used to verify the
                    signal value creates a wakeup condition
*******************************************************************************/
[!SELECT "as:modconf('Can')[1]/CanConfigSet/./*[1]"!][!//
[!VAR "IcomConfigCount" = "num:i(count(./CanIcom/CanIcomConfig/*))"!][!//
[!VAR "StartIndx" = "num:i(0)"!][!//
[!VAR "SignalMaskByte1" = "num:i(255)"!][!//
[!VAR "SignalMaskByte2" = "num:i(65280)"!][!//
[!VAR "SignalMaskByte3" = "num:i(16711680)"!][!//
[!VAR "SignalMaskByte4" = "num:i(4278190080)"!][!//
[!VAR "SignalMaskByte5" = "num:i(255)"!][!//
[!VAR "SignalMaskByte6" = "num:i(65280)"!][!//
[!VAR "SignalMaskByte7" = "num:i(16711680)"!][!//
[!VAR "SignalMaskByte8" = "num:i(4278190080)"!][!//
static const Can_IcomRxMsgSignalConfigType
               Can_kIcomRxMsgSignalConfig[CAN_NOOF_ICOM_SIGNALCONFIGURATIONS] =
{
[!LOOP "CanIcom/CanIcomConfig/*"!][!//
[!FOR "Index" = "1" TO "num:i($IcomConfigCount)"!][!//
[!IF "$Index = num:i(./CanIcomConfigId)"!][!//
[!VAR "IcomRxMsgCount" = "num:i(count(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*))"!][!//
[!FOR "Rxindx" = "0" TO "num:i($IcomRxMsgCount)"!][!//
[!IF "node:exists(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomRxMessageSignalConfig/*[1]) = 'true'"!][!//
[!VAR "IcomRxMsgSignalCount" = "num:i(count(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomRxMessageSignalConfig/*))"!][!//
[!FOR "RxSignalindx" = "1" TO "num:i($IcomRxMsgSignalCount)"!][!//
[!IF "$StartIndx > 0 "!][!//
,
[!ENDIF!][!//
{
[!VAR "StartIndx" = "num:i($StartIndx+ 1)"!][!//
[!VAR "IcomSignalMaskUpper32" = "num:i(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomRxMessageSignalConfig/*[position()=$RxSignalindx]/CanIcomSignalMaskUpper32bits)"!][!//
[!VAR "IcomSignalMaskLower32" = "num:i(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomRxMessageSignalConfig/*[position()=$RxSignalindx]/CanIcomSignalMaskLower32bits)"!][!//
[!VAR "IcomSignalValueUpper32" = "num:i(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomRxMessageSignalConfig/*[position()=$RxSignalindx]/CanIcomSignalValueUpper32bits)"!][!//
[!VAR "IcomSignalValueLower32" = "num:i(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomRxMessageSignalConfig/*[position()=$RxSignalindx]/CanIcomSignalValueLower32bits)"!][!//
[!VAR "TempByte1" = "bit:and($IcomSignalMaskLower32,$SignalMaskByte1)"!][!//
[!VAR "TempByte2" = "bit:and($IcomSignalMaskLower32,$SignalMaskByte2)"!][!//
[!VAR "TempByte3" = "bit:and($IcomSignalMaskLower32,$SignalMaskByte3)"!][!//
[!VAR "TempByte4" = "bit:and($IcomSignalMaskLower32,$SignalMaskByte4)"!][!//
[!VAR "TempByte5" = "bit:and($IcomSignalMaskUpper32,$SignalMaskByte5)"!][!//
[!VAR "TempByte6" = "bit:and($IcomSignalMaskUpper32,$SignalMaskByte6)"!][!//
[!VAR "TempByte7" = "bit:and($IcomSignalMaskUpper32,$SignalMaskByte7)"!][!//
[!VAR "TempByte8" = "bit:and($IcomSignalMaskUpper32,$SignalMaskByte8)"!][!//
[!VAR "Byte2" = "bit:shr($TempByte2,8)"!][!//
[!VAR "Byte3" = "bit:shr($TempByte3,16)"!][!//
[!VAR "Byte4" = "bit:shr($TempByte4,24)"!][!//
[!VAR "Byte5" = "bit:shr($TempByte5,32)"!][!//
[!VAR "Byte6" = "bit:shr($TempByte6,8)"!][!//
[!VAR "Byte7" = "bit:shr($TempByte7,16)"!][!//
[!VAR "Byte8" = "bit:shr($TempByte8,24)"!][!//
  {[!"num:inttohex($TempByte1)"!]U, [!"num:inttohex($Byte2)"!]U, [!"num:inttohex($Byte3)"!]U, [!"num:inttohex($Byte4)"!]U, [!"num:inttohex($TempByte5)"!]U, [!"num:inttohex($Byte6)"!]U, [!"num:inttohex($Byte7)"!]U, [!"num:inttohex($Byte8)"!]U },
[!VAR "TempByte1" = "bit:and($IcomSignalValueLower32,$SignalMaskByte1)"!][!//
[!VAR "TempByte2" = "bit:and($IcomSignalValueLower32,$SignalMaskByte2)"!][!//
[!VAR "TempByte3" = "bit:and($IcomSignalValueLower32,$SignalMaskByte3)"!][!//
[!VAR "TempByte4" = "bit:and($IcomSignalValueLower32,$SignalMaskByte4)"!][!//
[!VAR "TempByte5" = "bit:and($IcomSignalValueUpper32,$SignalMaskByte5)"!][!//
[!VAR "TempByte6" = "bit:and($IcomSignalValueUpper32,$SignalMaskByte6)"!][!//
[!VAR "TempByte7" = "bit:and($IcomSignalValueUpper32,$SignalMaskByte7)"!][!//
[!VAR "TempByte8" = "bit:and($IcomSignalValueUpper32,$SignalMaskByte8)"!][!//
[!VAR "Byte2" = "bit:shr($TempByte2,8)"!][!//
[!VAR "Byte3" = "bit:shr($TempByte3,16)"!][!//
[!VAR "Byte4" = "bit:shr($TempByte4,24)"!][!//
[!VAR "Byte5" = "bit:shr($TempByte5,32)"!][!//
[!VAR "Byte6" = "bit:shr($TempByte6,8)"!][!//
[!VAR "Byte7" = "bit:shr($TempByte7,16)"!][!//
[!VAR "Byte8" = "bit:shr($TempByte8,24)"!][!//
  {[!"num:inttohex($TempByte1)"!]U, [!"num:inttohex($Byte2)"!]U, [!"num:inttohex($Byte3)"!]U, [!"num:inttohex($Byte4)"!]U, [!"num:inttohex($TempByte5)"!]U, [!"num:inttohex($Byte6)"!]U, [!"num:inttohex($Byte7)"!]U, [!"num:inttohex($Byte8)"!]U },
  CAN_ICOM_OPER_[!"./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomRxMessageSignalConfig/*[position()=$RxSignalindx]/CanIcomSignalOperation "!]
}[!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDLOOP!]

};
[!ENDSELECT!]
[!ENDIF!][!//
[!ENDIF!][!//
/******************************************************************************/
                      /* CAN Configuration Pointer */
/******************************************************************************/
      /* Over all CAN configurations in the array, pointer to one of the
           configuration is passed as parameter to Can_Init API */
/******************************************************************************/

/* MISRA2012_RULE_8_7_JUSTIFICATION: Module configuration data structure
   declaration as per Autosar guidelines. This data structure may be needed
   by SW units using CAN Driver APIs */
/* MISRA2012_RULE_8_4_JUSTIFICATION: Definition is as per Autosar guidelines */
const Can_17_McmCan_ConfigType Can_17_McmCan_Config =
{
    /* Pointer to MCMCAN Kernel configuration */
    &Can_kMcmModuleConfig[0],
    /* Pointer to CAN controller configuration settings */
    &Can_kControllerConfig[0],
    /* Pointer to Message RAM configuration settings */
    &Can_kControllerMsgRAMMapConfig[0],
    /* Pointer to CAN Controller Handling of Events : Interrupt/Polling */
    &Can_kEventHandlingConfig[0],
    /* Pointer to Baudrate configuration settings */
    &Can_kBaudrateConfig[0][!//
[!IF "$FDNodesPresent != 0"!][!//
,
    /* Pointer to FDBaudrate configuration settings */
    &Can_kFDBaudrateConfig[0][!//
[!ENDIF!][!//
[!IF "$CanRxCalloutFnExists = num:i(1)"!][!//
,
    /* CAN L-PDU Receive Callout Function */
    &[!"$RxLPduCallout"!][!//
[!ENDIF!][!//
[!IF "$TxObjectCountMax != 0"!][!//
,
    /* Pointer to CAN Controller <-> Tx Hardware Objects Mapping */
    &Can_kTxHwObjectConfig[0][!//
[!ENDIF!][!//
[!IF "$RxObjectCountMax != 0"!][!//
[!IF "$StandardIdOnly = '1' or $MixedOnly = '1' "!][!//
,
    /* Pointer to CAN Controller <-> Rx Hardware Objects Mapping for Standard
       messages */
    &Can_kSIDFilterConfig[0][!//
[!ENDIF!][!//
[!IF "$ExtendedOnly = '1' or $MixedOnly = '1'"!][!//
,
    /* Pointer to CAN Controller <-> Rx Hardware Objects Mapping for Extended
       messages */
    &Can_kXIDFilterConfig[0][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$MultiCycleWriteOperCfg > 0"!][!//
,
    /* Pointer to CAN Controller <-> Tx Hardware Objects Mapping for Multiple
    period */
    &Can_kHthMaskObjectConfig[0],

    /* Pointer to CAN Controller <-> Tx Hardware Index Mapping for Multiple
    period */
    &Can_kPeriodHthMaskConfig[0][!//
[!ENDIF!][!//
[!IF "$MultiCycleReadOperCfg > 0"!][!//
,
    /* Pointer to CAN Controller <-> Rx Hardware Objects Mapping for Multiple
    period */
    &Can_kHrhMaskObjectConfig[0],

    /* Pointer to CAN Controller <-> Rx Hardware Index Mapping for Multiple
    period */
    &Can_kPeriodHrhMaskConfig[0][!//
[!ENDIF!][!//
[!IF "$PublicIcomSupport > num:i(0)"!][!//
,
    /* Pointer to ICOM configuration settings */
    &Can_kIcomConfig[0],
    /* Pointer to ICOM Message configuration settings */
    &Can_kIcomRxMsgConfig[0],
[!IF "$ICOMMsgSignalSupport > 0"!][!//
    /* Pointer to ICOM Message signal configuration settings */
    &Can_kIcomRxMsgSignalConfig[0]
[!ELSE!][!//
    /* Not used ICOM Message signal configuration settings */
    NULL_PTR
[!ENDIF!][!//
[!ENDIF!]
};
#define CAN_17_MCMCAN_STOP_SEC_CONFIG_DATA_QM_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
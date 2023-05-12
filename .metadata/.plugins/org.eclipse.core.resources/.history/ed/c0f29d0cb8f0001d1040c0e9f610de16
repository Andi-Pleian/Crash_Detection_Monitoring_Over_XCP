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
**  FILENAME  : Can_17_McmCan_Cfg.h                                           **
**                                                                            **
**  VERSION   : 3.0.0                                                         **
**                                                                            **
**  DATE      : 2017-03-03                                                    **
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
**  DESCRIPTION  : Code template header file for Can Driver                   **
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
**  FILENAME  : Can_17_McmCan_Cfg.h                                           **
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

#ifndef CAN_17_MCMCAN_CFG_H
#define CAN_17_MCMCAN_CFG_H
[!/* Include Code Generator Macros */!][!//
[!INCLUDE "Can_17_McmCan.m"!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Can')[1]/CanConfigSet/./*[1]"!][!//
[!//
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
[!NOCODE!][!//
  /* Autosar specification version */
  [!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
  [!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
  [!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//
[!ENDNOCODE!][!//
#define CAN_17_MCMCAN_AR_RELEASE_MAJOR_VERSION          ([!"$MajorVersion"!]U)
#define CAN_17_MCMCAN_AR_RELEASE_MINOR_VERSION          ([!"$MinorVersion"!]U)
#define CAN_17_MCMCAN_AR_RELEASE_REVISION_VERSION       ([!"$RevisionVersion"!]U)
[!NOCODE!][!//
  /* Vendor specific implementation version information */
  [!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
  [!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
  [!VAR "SwPatchVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
[!ENDNOCODE!]
#define CAN_17_MCMCAN_SW_MAJOR_VERSION                  ([!"$SwMajorVersion"!]U)
#define CAN_17_MCMCAN_SW_MINOR_VERSION                  ([!"$SwMinorVersion"!]U)
#define CAN_17_MCMCAN_SW_PATCH_VERSION                  ([!"$SwPatchVersion"!]U)
[!NOCODE!][!//
[!VAR "ControllerConfigMax" = "num:i(0)"!][!//
[!VAR "HwObjindx" = "num:i(0)"!][!//
[!VAR "BusOffInterruptEnable" = "num:i(0)"!][!//
[!VAR "RxInterruptEnable" = "num:i(0)"!][!//
[!VAR "RxEnabled" = "num:i(0)"!][!//
[!VAR "TxInterruptEnable" = "num:i(0)"!][!//
[!VAR "TxEnabled" = "num:i(0)"!][!//
[!VAR "BusOffPollingEnable" = "num:i(0)"!][!//
[!VAR "RxPollingEnable" = "num:i(0)"!][!//
[!VAR "TxPollingEnable" = "num:i(0)"!][!//
[!VAR "WUPollingEnable" = "num:i(0)"!][!//
[!VAR "CanWakeupApiSupport" = "num:i(0)"!][!//
[!VAR "CanWakeupEnable" = "num:i(0)"!][!//
[!VAR "StandardIdOnly" = "num:i(0)"!][!//
[!VAR "MixedOnly" = "num:i(0)"!][!//
[!VAR "ExtendedOnly" = "num:i(0)"!][!//
[!VAR "StandardIdNoConfig" = "num:i(0)"!][!//
[!VAR "ExtendedIdNoConfig" = "num:i(0)"!][!//
[!VAR "TxObjectCountMax" = "num:i(0)"!][!//
[!VAR "RxObjectCountMax" = "num:i(0)"!][!//
[!VAR "FDNodesPresent" = "num:i(0)"!][!//
[!VAR "Node0Present" = "num:i(0)"!][!//
[!VAR "Node1Present" = "num:i(0)"!][!//
[!VAR "Node2Present" = "num:i(0)"!][!//
[!VAR "Node0ID" = "num:i(255)"!][!//
[!VAR "Node1ID" = "num:i(255)"!][!//
[!VAR "Node2ID" = "num:i(255)"!][!//
[!VAR "ControllerBRConfigTemp" = "num:i(0)"!][!//
[!VAR "ControllerFDBRConfigTemp" = "num:i(0)"!][!//
[!VAR "BaudrateIndx" = "num:i(0)"!][!//
[!VAR "ControllerConfigMax" = "num:i('0')"!][!//
[!VAR "TxQueueEnable" = "num:i('0')"!][!//
[!VAR "TxMultiplePeriodSupport" = "num:i('0')"!][!//
[!VAR "RxMultiplePeriodSupport" = "num:i('0')"!][!//
[!VAR "CanTimeoutDuration" = "../../CanGeneral/*[1]/CanTimeoutDuration"!][!//
[!VAR "TxStartIndx" = "num:i('0')"!][!//
[!VAR "TxObjIndx" = "num:i('0')"!][!//
[!VAR "MainFuncName" = "''"!][!//
[!VAR "TxTriggerTransmit" = "''"!][!//
[!VAR "HwObjctMaxTemp" = "num:i(count(./CanHardwareObject/*))"!][!//
[!LOOP "../../CanGeneral/*[1]/CanMainFunctionRWPeriods/*"!][!//
[!VAR "MainFuncName" = "node:name(.)"!][!//
[!VAR "MainFuncNameTemp" = "node:name(.)"!][!//
[!FOR "HwObjindx" = "0" TO "$HwObjctMaxTemp - 1"!][!//
/* Loop for calculate number of Write MainFunction Periods */
[!LOOP "../../../../CanConfigSet/*[1]/CanHardwareObject/*"!][!//
 [!IF "CanObjectId  = $HwObjindx"!][!//
   [!IF "CanObjectType = 'TRANSMIT'"!][!//
     [!IF "node:refexists(CanMainFunctionRWPeriodRef)='true'"!][!//
       [!VAR "TxMode"= "(node:value(CanControllerRef))"!][!//
       [!IF "node:ref($TxMode)/CanTxProcessing = 'POLLING'"!][!//
       [!VAR "MainFuncNameConfig" = "(node:value(./CanMainFunctionRWPeriodRef))"!][!//
       [!VAR "MainFuncNameConfig" = "text:split($MainFuncNameConfig, '/')[last()]"!][!//
       [!IF "$MainFuncNameConfig = $MainFuncName"!][!//
         /* Set value for no of different Tx cyclic periods */
         [!VAR "TxStartIndx" = "num:i($TxStartIndx+ '1')"!][!//
         [!VAR "MainFuncName" = "''"!][!//
       [!ENDIF!][!//
       [!IF "$MainFuncNameConfig = $MainFuncNameTemp"!][!//
       [!VAR "TxObjIndx" = "num:i($TxObjIndx+ '1')"!][!//
       [!ENDIF!][!//
       [!ENDIF!][!//
     [!ENDIF!][!//
   [!ENDIF!][!//
  [!ENDIF!][!//
 [!ENDLOOP!][!//
 [!ENDFOR!][!//
 [!ENDLOOP!][!//
[!VAR "RxStartIndx" = "num:i('0')"!][!//
[!VAR "RxObjIndx" = "num:i('0')"!][!//
[!VAR "MainFuncName" = "''"!][!//
 /* Loop for calculate number of Read MainFunction Periods */
[!LOOP "../../CanGeneral/*[1]/CanMainFunctionRWPeriods/*"!][!//
[!VAR "MainFuncName" = "node:name(.)"!][!//
[!VAR "MainFuncNameTemp" = "node:name(.)"!][!//
[!FOR "HwObjindx" = "0" TO "$HwObjctMaxTemp - 1"!][!//
/* Loop for calculate number of Read MainFunction Periods */
[!LOOP "../../../../CanConfigSet/*[1]/CanHardwareObject/*"!][!//
 [!IF "CanObjectId  = $HwObjindx"!][!//
   [!IF "CanObjectType = 'RECEIVE'"!][!//
     [!IF "node:refexists(CanMainFunctionRWPeriodRef)='true'"!][!//
     [!VAR "RxMode"= "(node:value(CanControllerRef))"!][!//
       [!IF "node:ref($RxMode)/CanRxProcessing = 'POLLING'"!][!//
       [!VAR "MainFuncNameConfig" = "(node:value(./CanMainFunctionRWPeriodRef))"!][!//
       [!VAR "MainFuncNameConfig" = "text:split($MainFuncNameConfig, '/')[last()]"!][!//
       [!IF "$MainFuncNameConfig = $MainFuncName"!][!//
         /* Set value for no of different Tx cyclic periods */
         [!VAR "RxStartIndx" = "num:i($RxStartIndx+ '1')"!][!//
         [!VAR "MainFuncName" = "''"!][!//
       [!ENDIF!][!//
       [!IF "$MainFuncNameConfig = $MainFuncNameTemp"!][!//
       [!VAR "RxObjIndx" = "num:i($RxObjIndx+ '1')"!][!//
       [!ENDIF!][!//
       [!ENDIF!][!//
     [!ENDIF!][!//
   [!ENDIF!][!//
  [!ENDIF!][!//
 [!ENDLOOP!][!//
 [!ENDFOR!][!//
 [!ENDLOOP!][!//

[!VAR "IcomRxMsgCount" = "num:i(0)"!][!//
[!VAR "IcomRxMsgSignalCount" = "num:i(0)"!][!//
[!VAR "IcomConfigCount" = "num:i(count(./CanIcom/CanIcomConfig/*))"!][!//
 /* Loop for calculate Total number of Icom-Message and Icom-signal with in the configuration  */
 [!LOOP "./CanIcom/CanIcomConfig/*"!][!//
   [!VAR "IcomRxMsgCount" = "num:i(count(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*) + $IcomRxMsgCount )"!][!//
   [!FOR "Rxindx" = "1" TO "num:i($IcomRxMsgCount)"!][!//
     [!IF "node:exists(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomRxMessageSignalConfig) = 'true'"!][!//
     [!VAR "IcomRxMsgSignalCount" = "num:i(count(./CanIcomWakeupCauses/./*[1]/CanIcomRxMessage/*[position()=$Rxindx]/CanIcomRxMessageSignalConfig/*) + $IcomRxMsgSignalCount)"!][!//
     [!ENDIF!][!//
   [!ENDFOR!][!//
 [!ENDLOOP!][!//
[!VAR "RxFiofo0Support" = "num:i('0')"!][!//
[!VAR "RxFiofo1Support" = "num:i('0')"!][!//
[!VAR "HwCntrlId" = "num:i('0')"!][!//
/* Loop set for controller specific information read */
[!LOOP "./CanController/*"!][!//
 [!IF "CanControllerActivation = 'true'"!][!//
    [!VAR "BaseAddress" = "num:i(CanControllerBaseAddress)"!][!//
    [!IF "(($BaseAddress = num:hextoint(ecu:get('Can.Node00BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node01BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node02BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node03BaseAddress'))))"!][!//
      /* Activate Kernel0 module */
      [!VAR "Node0Present" = "num:i(1)"!][!//
    [!ENDIF!][!//
    [!IF "(($BaseAddress = num:hextoint(ecu:get('Can.Node10BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node11BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node12BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node13BaseAddress'))))"!][!//
      /* Activate Kernel1 module */
      [!VAR "Node1Present" = "num:i(1)"!][!//
    [!ENDIF!][!//
    [!IF "(($BaseAddress = num:hextoint(ecu:get('Can.Node20BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node21BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node22BaseAddress'))) or ($BaseAddress = num:hextoint(ecu:get('Can.Node23BaseAddress'))))"!][!//
      /* Activate Kernel2 module */
      [!VAR "Node2Present" = "num:i(1)"!][!//
    [!ENDIF!][!//
 [!VAR "ControllerConfigMax" = "num:i($ControllerConfigMax + 1)"!][!//
 [!IF "CanBusoffProcessing = 'INTERRUPT'"!][!//
  [!VAR "BusOffInterruptEnable" = "num:i(1)"!][!//
 [!ELSE!][!//
  [!VAR "BusOffPollingEnable" = "num:i(1)"!][!//
 [!ENDIF!][!//
 [!IF "CanRxProcessing = 'INTERRUPT'"!][!//
  [!VAR "RxInterruptEnable" = "num:i(1)"!][!//
 [!ELSE!][!//
  [!VAR "RxPollingEnable" = "num:i(1)"!][!//
 [!ENDIF!][!//
 [!IF "CanTxProcessing = 'INTERRUPT'"!][!//
  [!VAR "TxInterruptEnable" = "num:i(1)"!][!//
 [!ELSE!][!//
  [!VAR "TxPollingEnable" = "num:i(1)"!][!//
 [!ENDIF!][!//
  [!IF "CanWakeupProcessing   = 'POLLING'"!][!//
  [!VAR "WUPollingEnable" = "num:i(1)"!][!//
 [!ENDIF!][!//
  [!IF "CanWakeupSupport = 'true'"!][!//
  /* Set Global switch for CAN driver global Wakeup support */
  [!VAR "CanWakeupEnable" = "num:i(1)"!][!//
    [!IF "CanWakeupFunctionalityAPI = 'true'"!][!//
    /* Set Global switch for Wakeup API support */
    [!VAR "CanWakeupApiSupport" = "num:i(1)"!][!//
    [!ENDIF!][!//
 [!ENDIF!][!//
 [!VAR "NoOfBaudrateCfg" = "num:i(count(./CanControllerBaudrateConfig/*))"!][!//
 /* Set value with total number of Nominal baudrate configuration with in the configuration */
 [!VAR "ControllerBRConfigTemp" = "num:i($ControllerBRConfigTemp+$NoOfBaudrateCfg)"!][!//
 [!FOR "BaudrateIndx" = "1" TO "$NoOfBaudrateCfg"!][!//
     [!IF "(node:exists(CanControllerBaudrateConfig/*[position()=$BaudrateIndx]/CanControllerFdBaudrateConfig/*))"!][!//
        /* Set Global switch for FD support */
        [!VAR "FDNodesPresent" = "num:i(1)"!][!//
        /* Set value with total number of FD baudrate configuration with in the configuration */
        [!VAR "ControllerFDBRConfigTemp" = "num:i($ControllerFDBRConfigTemp+1)"!][!//
     [!ENDIF!][!//
 [!ENDFOR!][!//
 [!ENDIF!][!//
[!ENDLOOP!]
[!VAR "HwObjctMaxTemp" = "num:i(count(./CanHardwareObject/*))"!][!//
/* Read all the configured Hw object */
[!FOR "HwObjindx" = "1" TO "$HwObjctMaxTemp"!][!//
  [!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanObjectType = 'TRANSMIT'"!][!//
    [!IF "node:refexists(./CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef) ='true'"!][!//
      [!IF "(node:ref(./CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef)/CanControllerActivation = 'true')"!][!//
       /* Set value with total number of HTH configured with in the configuration */
       [!VAR "TxObjectCountMax" = "num:i($TxObjectCountMax+1)"!][!//
       /* Set Global switch for Tx Operation support status */
       [!VAR "TxEnabled" = "num:i(1)"!][!//
      [!ENDIF!][!//
      [!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanHwObjectCount > '1'"!][!//
       /* Set Global switch for Tx Queue support status */
       [!VAR "TxQueueEnable" = "num:i(1)"!][!//
      [!ENDIF!][!//
      [!IF "node:exists(./CanHardwareObject/*[position()=$HwObjindx]/CanTriggerTransmitEnable) ='true'"!][!//
        [!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanTriggerTransmitEnable = 'true'"!][!//
         /* Set Global switch for Tx Trigger Transmit support status */
         [!VAR "TxTriggerTransmit" = "num:i(1)"!][!//
        [!ENDIF!][!//
      [!ENDIF!][!//
    [!ENDIF!][!//
    [!IF "node:refexists(./CanHardwareObject/*[position()=$HwObjindx]/CanMainFunctionRWPeriodRef) ='true'"!][!//
    [!VAR "MainFuncNameConfig"= "substring-after(./CanHardwareObject/*[position()=$HwObjindx]/CanMainFunctionRWPeriodRef,'Can/Can/')"!][!//
    [!VAR "MainFuncNameConfig"= "substring-after($MainFuncNameConfig,'/')"!][!//
      [!IF "$TxObjectCountMax = '1'"!][!//
        [!VAR "MainFuncName" = "$MainFuncNameConfig"!][!//
      [!ENDIF!][!//
      [!IF "$MainFuncName != $MainFuncNameConfig"!][!//
        /* Set Global switch for Multiple write period support status */
        [!VAR "TxMultiplePeriodSupport" = "num:i(1)"!][!//
      [!ENDIF!][!//
    [!ENDIF!][!//
  [!ENDIF!][!//
  [!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanObjectType = 'RECEIVE'"!][!//
   [!IF "node:refexists(./CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef) ='true'"!][!//
      [!IF "(node:ref(./CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef)/CanControllerActivation = 'true')"!][!//
           /* Set Global switch for Rx Operation support status */
           [!VAR "RxEnabled" = "num:i(1)"!][!//
           /* Set value with total number of HRH configured with in the configuration */
           [!VAR "RxObjectCountMax" = "num:i($RxObjectCountMax+1)"!][!//
           [!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanIdType = 'STANDARD'"!][!//
             /* Set with used Id Type as Standard */
             [!VAR "StandardIdOnly" = "num:i(1)"!][!//
           [!ENDIF!][!//
           [!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanIdType = 'MIXED'"!][!//
             /* Set with used Id Type as Mixed */
             [!VAR "MixedOnly" = "num:i(1)"!][!//
           [!ENDIF!][!//
           [!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanIdType = 'EXTENDED'"!][!//
             /* Set with used Id Type as Extended */
             [!VAR "ExtendedOnly" = "num:i(1)"!][!//
           [!ENDIF!][!//
           [!VAR "HwFilterCount" = "num:i(count(./CanHardwareObject/*[position()=$HwObjindx]/CanHwFilter/*))"!][!//
           [!FOR "HwFilterindx" = "1" TO "$HwFilterCount"!][!//
             [!VAR "HwFilterValue" = "num:i(./CanHardwareObject/*[position()=$HwObjindx]/CanHwFilter/*[position()=$HwFilterindx]/CanHwFilterCode)"!][!//
             [!VAR "HwFilterMaskValue" = "num:i(./CanHardwareObject/*[position()=$HwObjindx]/CanHwFilter/*[position()=$HwFilterindx]/CanHwFilterMask)"!][!//
             [!IF "(./CanHardwareObject/*[position()=$HwObjindx]/CanIdType = 'STANDARD') or (./CanHardwareObject/*[position()=$HwObjindx]/CanIdType = 'MIXED')"!][!//
               /* Set value with total number of Standard Filter mask value configured with in the configuration */
               [!VAR "StandardIdNoConfig" = "num:i($StandardIdNoConfig + 1)"!][!//
             [!ENDIF!][!//
             [!IF "(./CanHardwareObject/*[position()=$HwObjindx]/CanIdType = 'EXTENDED') or (./CanHardwareObject/*[position()=$HwObjindx]/CanIdType = 'MIXED')"!][!//
               /* Set value with total number of Extended Filter mask value configured with in the configuration */
               [!VAR "ExtendedIdNoConfig" = "num:i($ExtendedIdNoConfig + 1)"!][!//
             [!ENDIF!][!//
           [!ENDFOR!][!//
           [!IF "./CanHardwareObject/*[position()=$HwObjindx]/CanHwObjectCount > '1'"!][!//
               [!IF "$RxFiofo0Support = 1"!][!//
                   [!IF "$HwCntrlId = (node:ref(./CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef)/CanControllerId)"!][!//
                       /* Set Global switch for RXFIFO1 used status */
                      [!VAR "RxFiofo1Support" = "num:i(1)"!][!//
                   [!ENDIF!][!//
               [!ENDIF!][!//
               /* Set Global switch for RXFIFO1 used status */
               [!VAR "RxFiofo0Support" = "num:i(1)"!][!//
               [!VAR "HwCntrlId" = "(node:ref(./CanHardwareObject/*[position()=$HwObjindx]/CanControllerRef)/CanControllerId)"!][!//
           [!ENDIF!][!//
      [!ENDIF!][!//
   [!ENDIF!][!//
   [!IF "node:refexists(./CanHardwareObject/*[position()=$HwObjindx]/CanMainFunctionRWPeriodRef) ='true'"!][!//
     [!VAR "MainFuncNameConfig"= "substring-after(./CanHardwareObject/*[position()=$HwObjindx]/CanMainFunctionRWPeriodRef,'Can/Can/')"!][!//
     [!VAR "MainFuncNameConfig"= "substring-after($MainFuncNameConfig,'/')"!][!//
         [!IF "$RxObjectCountMax = '1'"!][!//
             [!VAR "MainFuncName" = "$MainFuncNameConfig"!][!//
         [!ENDIF!][!//
         [!IF "$MainFuncName != $MainFuncNameConfig"!][!//
           /* Set Global switch for Multiple Read period support status */
           [!VAR "RxMultiplePeriodSupport" = "num:i(0)"!][!//
         [!ENDIF!][!//
   [!ENDIF!][!//
  [!ENDIF!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Maximum number of CAN Kernels configured in a ConfigSet */
#define CAN_NOOF_KERNEL                              (uint8)([!"num:i($Node0Present+$Node1Present+$Node2Present)"!]U)

/* Maximum number of CAN Controllers configured in a ConfigSet */
#define CAN_NOOF_CONTROLLER                          (uint8)([!"$ControllerConfigMax"!]U)

/* Number of baudrate Configuration sets */
#define CAN_NOOF_BAUDRATE_CONFIG                        ([!"$ControllerBRConfigTemp"!]U)
[!NOCODE!][!//
[!IF "$FDNodesPresent = 1"!]
[!CODE!][!//

/* Number of baudrate Configuration sets */
#define CAN_NOOF_FDBAUDRATE_CONFIG                      ([!"$ControllerFDBRConfigTemp"!]U)
[!ENDCODE!][!//
[!ENDIF!][!//

[!ENDNOCODE!]
/* Maximum number of transmit hardware objects configured in a ConfigSet */
#define CAN_NOOF_TX_HARDWARE_OBJECTS                   (Can_HwHandleType) ([!"$TxObjectCountMax"!]U)

/* Maximum number of transmit hardware objects configured in a ConfigSet */
#define CAN_NOOF_RX_HARDWARE_OBJECTS                   (Can_HwHandleType) ([!"$RxObjectCountMax"!]U)
[!IF "$TxStartIndx > 1"!][!//

/* Maximum number of multiple Write cycle period configured in a ConfigSet */
#define CAN_NOOF_TX_PERIODS_CONFIG                       ([!"$TxStartIndx"!]U)

/* Maximum number of HwObject supported with multiple Tx period in a ConfigSet */
#define CAN_NOOF_HWOBJECT_TX_PERIODS                     ([!"$TxObjIndx"!]U)
[!ENDIF!][!//
[!IF "$RxStartIndx > 1"!][!//

/* Maximum number of multiple Read cycle period configured in a ConfigSet */
#define CAN_NOOF_RX_PERIODS_CONFIG                       ([!"$RxStartIndx"!]U)

/* Maximum number of HwObject supported with multiple Rx period in a ConfigSet */
#define CAN_NOOF_HWOBJECT_RX_PERIODS                     ([!"$RxObjIndx"!]U)
[!ENDIF!][!//

/* Maximum number of Icom configurations with in the ConfigSet */
#define CAN_NOOF_ICOM_CONFIGURATIONS                   (IcomConfigIdType) ([!"$IcomConfigCount"!]U)

/* Maximum number of Icom Message configurations with in the ConfigSet */
#define CAN_NOOF_ICOM_MSGCONFIGURATIONS                 ([!"$IcomRxMsgCount"!]U)

/* Maximum number of Icom Message configurations with in the ConfigSet */
#define CAN_NOOF_ICOM_SIGNALCONFIGURATIONS              ([!"$IcomRxMsgSignalCount"!]U)

/* Configured Message Identifier Type */
/* CAN_ID_MIXED  : Standard and Extended Message Identifiers are configured */
/* CAN_ID_EXTENDED : Extended Message Identifier is only configured */
/* CAN_ID_STANDARD : Standard Message Identifier is only configured */
[!IF "($MixedOnly = 1) or (($ExtendedOnly = 1) and ($StandardIdOnly = 1))"!][!//
#define CAN_ID_CONFIG_TYPE                              (CAN_ID_MIXED)
[!ELSEIF "$ExtendedOnly = 1"!][!//
#define CAN_ID_CONFIG_TYPE                              (CAN_ID_EXTENDED)
[!ELSE!][!//
#define CAN_ID_CONFIG_TYPE                              (CAN_ID_STANDARD)
[!ENDIF!][!//

/* Maximum number of Standard Id filter elements configured in a ConfigSet */
#define CAN_NOOF_SID_FILTER_CONFIG                              ([!"$StandardIdNoConfig"!]U)

/* Maximum number of Extended Id filter elements configured in a ConfigSet */
#define CAN_NOOF_XID_FILTER_CONFIG                              ([!"$ExtendedIdNoConfig"!]U)

/* Configuration: CAN_WAKEUP_CONFIGURED
 - STD_ON  - At least one of the CAN controllers supports wakeup
 - STD_OFF - None of the CAN controllers supports wakeup
*/
[!IF "$CanWakeupEnable = 0"!][!//
#define CAN_WAKEUP_CONFIGURED                           (STD_OFF)
[!ELSE!][!//
#define CAN_WAKEUP_CONFIGURED                           (STD_ON)
[!ENDIF!][!//

/* Configuration: CAN_RX_PROCESS_ENABLED
 - STD_ON  - At least one of the HRH is configured
 - STD_OFF - None of the HRH is configured
*/
[!IF "$RxEnabled = 0"!][!//
#define CAN_RX_PROCESS_ENABLED                          (STD_OFF)
[!ELSE!][!//
#define CAN_RX_PROCESS_ENABLED                          (STD_ON)
[!ENDIF!][!//

/* Configuration: CAN_TX_PROCESS_ENABLED
 - STD_ON  - At least one of the HTH is configured
 - STD_OFF - None of the HRH is configured
*/
[!IF "$TxEnabled = 0"!][!//
#define CAN_TX_PROCESS_ENABLED                          (STD_OFF)
[!ELSE!][!//
#define CAN_TX_PROCESS_ENABLED                          (STD_ON)
[!ENDIF!][!//

/* Configuration: CAN_TRIGGER_TRANSMIT_SUPPORT
 - STD_ON  - Trigger Transmit support is enabled
 - STD_OFF - Trigger Transmit support is not enabled
*/
[!IF "$TxTriggerTransmit = 0"!][!//
#define CAN_TRIGGER_TRANSMIT_SUPPORT                    (STD_OFF)
[!ELSE!][!//
#define CAN_TRIGGER_TRANSMIT_SUPPORT                    (STD_ON)
[!ENDIF!][!//

/*******************************************************************************
**                      CAN General Information                               **
*******************************************************************************/
/* Configuration: CAN_17_MCMCAN_INSTANCE_ID
 - Specifies the InstanceId of this module instance
*/
#define CAN_17_MCMCAN_INSTANCE_ID                       ([!"../../CanGeneral/*[1]/CanIndex"!]U)

/* Configuration: CAN_DEV_ERROR_DETECT
 - STD_ON  - DET is enabled
 - STD_OFF - DET is disabled
*/
#define CAN_DEV_ERROR_DETECT                            [!//
[!CALL "CG_ConfigSwitch","nodeval" = "../../CanGeneral/*[1]/CanDevErrorDetection"!]

/* Configuration: DEM event configuration
 - CAN_ENABLE_DEM_REPORT  - Dem event support is enabled
 - CAN_DISABLE_DEM_REPORT - Dem event support is disabled
*/
[!IF "node:refexists(../../CanDemEventParameterRefs/*[1]/CAN_E_TIMEOUT) = 'true'"!][!//
#define CAN_E_TIMEOUT_DEM_REPORT                    (CAN_ENABLE_DEM_REPORT)
[!ELSE!][!//
#define CAN_E_TIMEOUT_DEM_REPORT                    (CAN_DISABLE_DEM_REPORT)
[!ENDIF!][!//

[!IF "node:refexists(../../CanDemEventParameterRefs/*[1]/CAN_E_TIMEOUT) = 'true'"!][!//
/*
- Configuration: DEM event configuration Id
*/
[!VAR "Text" = "text:split(../../CanDemEventParameterRefs/*[1]/CAN_E_TIMEOUT,'/')[last()]"!][!//
#define CAN_E_TIMEOUT                   \
                      (DemConf_DemEventParameter_[!"$Text"!])
[!ENDIF!][!//

/* Configuration: CAN_VERSION_INFO_API
 - STD_ON  - Can_17_McmCan_GetVersionInfo API is enabled
 - STD_OFF - Can_17_McmCan_GetVersionInfo API is disabled
*/
#define CAN_VERSION_INFO_API                            [!//
[!CALL "CG_ConfigSwitch","nodeval" = "../../CanGeneral/*[1]/CanVersionInfoApi"!]

/* Configuration: CAN_LPDU_RX_CALLOUT
 - STD_ON  - L-PDU receive callout support enabled
 - STD_OFF - L-PDU receive callout support disabled
*/
[!IF "node:exists(../../CanGeneral/*[1]/CanLPduReceiveCalloutFunction) = 'true'"!][!//
[!VAR "RxLPduCallout" = "../../CanGeneral/*[1]/CanLPduReceiveCalloutFunction"!][!//
[!IF "$RxLPduCallout = '""' or $RxLPduCallout = '' or $RxLPduCallout = 'NULL_PTR' or $RxLPduCallout = 'NULL' "!][!//
#define CAN_LPDU_RX_CALLOUT                             (STD_OFF)
[!ELSE!][!//
#define CAN_LPDU_RX_CALLOUT                             (STD_ON)
[!ENDIF!][!//
[!ELSE!][!//
#define CAN_LPDU_RX_CALLOUT                             (STD_OFF)
[!ENDIF!][!//

/* Configuration: CAN_MULTIPLEXED_TRANSMISSION
 - STD_ON  - Multiplexed transmission feature is enabled
 - STD_OFF - Multiplexed transmission feature is disabled
*/
#define CAN_MULTIPLEXED_TRANSMISSION                    [!//
[!CALL "CG_ConfigSwitch","nodeval" = "../../CanGeneral/*[1]/CanMultiplexedTransmission"!]

/* Configuration: CAN_TIMEOUT_DURATION
 - Specifies the maximum number of loops for blocking function until
   a time-out is raised in short term wait loops
*/
#define CAN_TIMEOUT_DURATION                            ([!"num:i($CanTimeoutDuration * 10000000)"!]U)

/* Configuration: CAN_SET_BAUDRATE_API
 - STD_ON  - Can_17_McmCan_SetBaudrate API is enabled
 - STD_OFF - Can_17_McmCan_SetBaudrate API is Disabled
*/
#define CAN_SET_BAUDRATE_API                            [!//
[!CALL "CG_ConfigSwitch","nodeval" = "../../CanGeneral/*[1]/CanSetBaudrateApi"!]

/* Configuration: CanWakeupFunctionalityAPI
 - STD_ON  - Can_17_McmCan_CheckWakeup API is enabled
 - STD_OFF - Can_17_McmCan_CheckWakeup API is Disabled
*/
[!IF "$CanWakeupApiSupport = 0"!][!//
#define CAN_WU_API_SUPPORT                              (STD_OFF)
[!ELSE!][!//
#define CAN_WU_API_SUPPORT                              (STD_ON)
[!ENDIF!][!//

/* Configuration: CanControllerFdBaudrateConfig
 - STD_ON  - FD Operation is Enabled
 - STD_OFF - FD Operation is Disabled
*/
[!IF "$FDNodesPresent = 0"!][!//
#define CAN_FD_ENABLE                                   (STD_OFF)
[!ELSE!][!//
#define CAN_FD_ENABLE                                   (STD_ON)
[!ENDIF!][!//

/* Configuration: CAN_DEINIT_API
 - STD_ON  - CAN De-initialization API is enabled
 - STD_OFF - CAN De-initialization API is not enabled
*/
#define CAN_DEINIT_API                                  [!//
[!CALL "CG_ConfigSwitch","nodeval" = "../../CanGeneral/*[1]/CanDeInitApi"!]

/* Configuration: CAN_PUBLIC_ICOM_SUPPORT
 - STD_ON  - CAN Pretended networking is enabled
 - STD_OFF - CAN Pretended networking is not enabled
*/
#define CAN_PUBLIC_ICOM_SUPPORT                         [!//
[!CALL "CG_ConfigSwitch","nodeval" = "../../CanGeneral/*[1]/CanPublicIcomSupport"!]

/******************************************************************************/
                    /* CAN Controller Configurations */
/******************************************************************************/
/* KERNEL0 Activation
 - STD_ON  - The controller associated with Kernel0 is used
 - STD_OFF - Not used any of the controller associated with Kernel0
*/
[!IF "$Node0Present = 0"!][!//
#define CAN_HWMCMKERNEL0_ACTIVATION                     (STD_OFF)
[!ELSE!][!//
[!VAR "Node0ID" = "num:i(0)"!][!//
#define CAN_HWMCMKERNEL0_ACTIVATION                     (STD_ON)
[!ENDIF!][!//

/* KERNEL1 Activation
 - STD_ON  - The controller associated with Kernel1 is used
 - STD_OFF - Not used any of the controller associated with Kernel1
*/
[!IF "$Node1Present = 0"!][!//
#define CAN_HWMCMKERNEL1_ACTIVATION                     (STD_OFF)
[!ELSE!][!//
[!VAR "Node1ID" = "num:i($Node0Present)"!][!//
#define CAN_HWMCMKERNEL1_ACTIVATION                     (STD_ON)
[!ENDIF!][!//

/* KERNEL2 Activation
 - STD_ON  - The controller associated with Kernel2 is used
 - STD_OFF - Not used any of the controller associated with Kernel2
*/
[!IF "$Node2Present = 0"!][!//
#define CAN_HWMCMKERNEL2_ACTIVATION                     (STD_OFF)
[!ELSE!][!//
[!VAR "Node2ID" = "num:i($Node0Present+$Node1Present)"!][!//
#define CAN_HWMCMKERNEL2_ACTIVATION                     (STD_ON)
[!ENDIF!][!//

/* KERNEL0 Configuration ID*/
#define CAN_HWMCMKERNEL0_ID                             ([!"$Node0ID"!]U)

/* KERNEL1 Configuration ID*/
#define CAN_HWMCMKERNEL1_ID                             ([!"$Node1ID"!]U)

/* KERNEL2 Configuration ID*/
#define CAN_HWMCMKERNEL2_ID                             ([!"$Node2ID"!]U)

/* RxFIFO0 is used for Reception
 - STD_ON  - RXFIFO0 buffer is supported for data reception
 - STD_OFF - RXFIFO0 buffer is not configured for data reception
*/
[!IF "$RxFiofo0Support = 0"!][!//
#define CAN_RXFIFO0_ENABLED                             (STD_OFF)
[!ELSE!][!//
#define CAN_RXFIFO0_ENABLED                             (STD_ON)
[!ENDIF!][!//

/* RxFIFO1 is used for Reception
 - STD_ON  - RXFIFO0 buffer is supported for data reception
 - STD_OFF - RXFIFO1 buffer is not configured for data reception
*/
[!IF "$RxFiofo1Support = 0"!][!//
#define CAN_RXFIFO1_ENABLED                             (STD_OFF)
[!ELSE!][!//
#define CAN_RXFIFO1_ENABLED                             (STD_ON)
[!ENDIF!][!//

/*BusOff Processing Event used as Interrupt
 - STD_ON - BusOff event is notified through Interrupt mechanism by the
            configured controller
 - STD_OFF - BusOff event is notified through Interrupt mechanism by the
            configured controller
*/
[!IF "$BusOffInterruptEnable = 0"!][!//
#define CAN_BO_INTERRUPT_PROCESSING                     (STD_OFF)
[!ELSE!][!//
#define CAN_BO_INTERRUPT_PROCESSING                     (STD_ON)
[!ENDIF!][!//

/* Transmission Processing Event used as Interrupt
 - STD_ON - Transmission event is notified through Interrupt mechanism by the
            configured controller
 - STD_OFF - Transmission event is notified through Interrupt mechanism by the
            configured controller
*/
[!IF "$TxInterruptEnable = 0"!][!//
#define CAN_TX_INTERRUPT_PROCESSING                     (STD_OFF)
[!ELSE!][!//
#define CAN_TX_INTERRUPT_PROCESSING                     (STD_ON)
[!ENDIF!][!//

/* Reception Processing Event used as Interrupt
 - STD_ON - Reception event is notified through Interrupt mechanism by the
            configured controller
 - STD_OFF - Reception event is notified through Interrupt mechanism by the
            configured controller
*/
[!IF "$RxInterruptEnable = 0"!][!//
#define CAN_RX_INTERRUPT_PROCESSING                     (STD_OFF)
[!ELSE!][!//
#define CAN_RX_INTERRUPT_PROCESSING                     (STD_ON)
[!ENDIF!][!//

/*BusOff Processing Event used as POLLING
 - STD_ON - BusOff event is notified through Polling mechanism by the
            configured controller
 - STD_OFF - BusOff event is notified through Polling mechanism by the
            configured controller
*/
[!IF "$BusOffPollingEnable = 0"!][!//
#define CAN_BO_POLLING_PROCESSING                       (STD_OFF)
[!ELSE!][!//
#define CAN_BO_POLLING_PROCESSING                       (STD_ON)
[!ENDIF!][!//

/* Transmission Processing Event used as POLLING
 - STD_ON - Transmission event is notified through Polling mechanism by the
            configured controller
 - STD_OFF - Transmission event is notified through Polling mechanism by the
            configured controller
*/
[!IF "$TxPollingEnable = 0"!][!//
#define CAN_TX_POLLING_PROCESSING                       (STD_OFF)
[!ELSE!][!//
#define CAN_TX_POLLING_PROCESSING                       (STD_ON)
[!ENDIF!][!//

/* Reception Processing Event used as POLLING
 - STD_ON - Reception event is notified through Polling mechanism by the
            configured controller
 - STD_OFF - Reception event is notified through Polling mechanism by the
            configured controller
*/
[!IF "$RxPollingEnable = 0"!][!//
#define CAN_RX_POLLING_PROCESSING                       (STD_OFF)
[!ELSE!][!//
#define CAN_RX_POLLING_PROCESSING                       (STD_ON)
[!ENDIF!][!//

/* WakeUp Processing Event used as POLLING
 - STD_ON - WakeUp event is notified through Polling mechanism by the
            configured controller
 - STD_OFF - WakeUp event is notified through Polling mechanism by the
            configured controller
*/
[!IF "$WUPollingEnable = 0"!][!//
#define CAN_WU_POLLING_PROCESSING                       (STD_OFF)
[!ELSE!][!//
#define CAN_WU_POLLING_PROCESSING                       (STD_ON)
[!ENDIF!][!//

/* Multiple cyclic periods for Can_MainFunction_Write
 - STD_ON - Multiple periods are configured
 - STD_OFF - Not supported with multiple period configuration
*/
[!IF "$TxStartIndx > 1"!][!//
#define CAN_MULTIPLE_TX_PERIODS                         (STD_ON)
[!ELSE!][!//
#define CAN_MULTIPLE_TX_PERIODS                         (STD_OFF)
[!ENDIF!][!//

/* Multiple cyclic periods for Can_MainFunction_Read
 - STD_ON - Multiple periods are configured
 - STD_OFF - Not supported with multiple period configuration
*/
[!IF "$RxStartIndx > 1"!][!//
#define CAN_MULTIPLE_RX_PERIODS                         (STD_ON)
[!ELSE!][!//
#define CAN_MULTIPLE_RX_PERIODS                         (STD_OFF)
[!ENDIF!][!//

/* Controller Handle Id */
[!NOCODE!][!//
[!VAR "ActualCntrlIndex" = "'0'"!][!//
[!VAR "ControllerConfigMaxTemp" = "num:i(count(./CanController/*))"!][!//
[!FOR "Cntrlindx" = "0" TO "$ControllerConfigMaxTemp - 1"!][!//
[!LOOP "./CanController/*"!][!//
[!IF "CanControllerId = $Cntrlindx"!][!//
[!IF "CanControllerActivation = 'true'"!][!//
[!VAR "Text" = "node:name(.)"!][!//
[!CODE!][!//
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanController_[!"$Text"!]             [!"$ActualCntrlIndex"!]
[!ENDCODE!][!//
[!VAR "ActualCntrlIndex" = "num:i($ActualCntrlIndex+1)"!][!//
[!ENDIF!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDFOR!]
[!ENDNOCODE!][!//

/* Hardware object Handle Id */
[!NOCODE!][!//
[!VAR "ActualHwIndex" = "'0'"!][!//
[!VAR "HwObjConfigMaxTemp" = "num:i(count(./CanHardwareObject/*))"!][!//
[!FOR "HwObjindx" = "0" TO "$HwObjConfigMaxTemp - 1"!][!//
[!LOOP "./CanHardwareObject/*"!][!//
[!IF "CanObjectId  = $HwObjindx"!][!//
[!IF "(node:ref(CanControllerRef)/CanControllerActivation = 'true')"!][!//
[!VAR "Text" = "node:name(.)"!][!//
[!CODE!][!//
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_[!"$Text"!]         [!"$ActualHwIndex"!]
[!ENDCODE!][!//
[!VAR "ActualHwIndex" = "num:i($ActualHwIndex+1)"!][!//
[!ENDIF!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDFOR!]
[!ENDNOCODE!][!//
/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

[!IF "$TxStartIndx > 1"!][!//
/*******************************************************************************
**  Can_MainFunction_Write Function Declarations with multipleperiod support  **
*******************************************************************************/
[!FOR "HwObjindx" = "0" TO "$TxStartIndx - 1"!][!//
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
extern void Can_17_McmCan_MainFunction_Write_[!"$HwObjindx"!](void);
[!ENDFOR!][!//
[!ENDIF!][!//

[!IF "$RxStartIndx > 1"!][!//
/*******************************************************************************
**  Can_MainFunction_Read Function Declarations with multipleperiod support  **
*******************************************************************************/
[!FOR "HwObjindx" = "0" TO "$RxStartIndx - 1"!][!//
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
extern void Can_17_McmCan_MainFunction_Read_[!"$HwObjindx"!](void);
[!ENDFOR!][!//
[!ENDIF!][!//
/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
[!ENDSELECT!]
#endif  /* CAN_17_MCMCAN_CFG_H */
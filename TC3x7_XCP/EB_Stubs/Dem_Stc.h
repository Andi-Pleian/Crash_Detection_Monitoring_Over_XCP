/**
 * \file
 *
 * \brief AUTOSAR Dem
 *
 * This file contains the implementation of the AUTOSAR
 * module Dem.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined DEM_STC_H)
#define DEM_STC_H

/* This file includes all external static API declarations and type
 * definitions. */

/*==================[inclusions]============================================*/
/* !LINKSTO dsn.Dem.IncludeStr,1 */

#include <TSAutosar.h>                        /* EB specific standard types */
#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <Dem_Version.h>                      /* Module version declaration */

/*==================[macros]================================================*/

/*------------------[AUTOSAR event ID declaration]--------------------------*/

#if (defined DEM_EVENT_ID_INVALID)
#error DEM_EVENT_ID_INVALID already defined
#endif
/** \brief Symbolic name of invalid event ID */
#define DEM_EVENT_ID_INVALID 0U

#if (defined DEM_EVENT_ID_IGNORE)
#error DEM_EVENT_ID_IGNORE already defined
#endif
/** \brief Symbolic name of event ID that must be ignored during processing
 ** of the queue since it got invalidated */
#define DEM_EVENT_ID_IGNORE  0x3FFFU

/*-----------------------[Development error IDs]----------------------------*/

/* API service called with wrong parameter */

#if (defined DEM_E_PARAM_CONFIG)
#error DEM_E_PARAM_CONFIG already defined
#endif
/** \brief DET error code for invalid configuration */
#define DEM_E_PARAM_CONFIG    0x10U

#if (defined DEM_E_PARAM_POINTER)
#error DEM_E_PARAM_POINTER already defined
#endif
/** \brief DET error code for invalid address */
#define DEM_E_PARAM_POINTER   0x11U

#if (defined DEM_E_PARAM_DATA)
#error DEM_E_PARAM_DATA already defined
#endif
/** \brief DET error code for invalid data */
#define DEM_E_PARAM_DATA      0x12U

#if (defined DEM_E_PARAM_LENGTH)
#error DEM_E_PARAM_LENGTH already defined
#endif
/** \brief DET error code for invalid length */
#define DEM_E_PARAM_LENGTH    0x13U

/* API service called before Dem initialized */

#if (defined DEM_E_UNINIT)
#error DEM_E_UNINIT already defined
#endif
/** \brief  DET error code for wrong initialization status */
#define DEM_E_UNINIT          0x20U

/* No valid data available by the SW-C */

/* - DEM_E_NODATAAVAILABLE (0x30): DET error code for non-availabilty of data
 *   This value is also used as regular return value, refer to Dem_Types.h */

#if (defined DEM_E_INTEGRATION)
#error DEM_E_INTEGRATION already defined
#endif
/** \brief DET error code for unfulfilled return values from an SW-C */
#define DEM_E_INTEGRATION     0x41U

/* Required pre-condition for API call was not fulfilled */

#if (defined DEM_E_WRONG_CONDITION)
#error DEM_E_WRONG_CONDITION already defined
#endif
/** \brief DET error code for unfulfilled pre-conditions for an API call */
#define DEM_E_WRONG_CONDITION 0x40U

/*==================[type definitions and related macros]===================*/

/*------------------[API function service IDs]------------------------------*/

#if (defined DEM_SID_GetVersionInfo)
#error DEM_SID_GetVersionInfo already defined
#endif
/** \brief Service Id for Dem_GetVersionInfo() */
#define DEM_SID_GetVersionInfo                                    0x00U

/* Interface ECU State Manager <--> Dem */

#if (defined DEM_SID_PreInit)
#error DEM_SID_PreInit already defined
#endif
/** \brief Service Id for Dem_PreInit() */
#define DEM_SID_PreInit                                           0x01U

#if (defined DEM_SID_Init)
#error DEM_SID_Init already defined
#endif
/** \brief Service Id for Dem_Init() */
#define DEM_SID_Init                                              0x02U

#if (defined DEM_SID_Shutdown)
#error DEM_SID_Shutdown already defined
#endif
/** \brief Service Id for Dem_Shutdown() */
#define DEM_SID_Shutdown                                          0x03U

/* Interface BSW modules / SW-Components <--> Dem */

#if (defined DEM_SID_ReportErrorStatus)
#error DEM_SID_ReportErrorStatus already defined
#endif
/** \brief Service Id for Dem_ReportErrorStatus() */
#define DEM_SID_ReportErrorStatus                                 0x0FU

#if (defined DEM_SID_SetEventStatus)
#error DEM_SID_SetEventStatus already defined
#endif
/** \brief Service Id for Dem_SetEventStatus() */
#define DEM_SID_SetEventStatus                                    0x04U

#if (defined DEM_SID_ResetEventStatus)
#error DEM_SID_ResetEventStatus already defined
#endif
/** \brief Service Id for Dem_ResetEventStatus() */
#define DEM_SID_ResetEventStatus                                  0x05U

#if (defined DEM_SID_PrestoreFreezeFrame)
#error DEM_SID_PrestoreFreezeFrame already defined
#endif
/** \brief Service Id for Dem_PrestoreFreezeFrame() */
#define DEM_SID_PrestoreFreezeFrame                               0x06U

#if (defined DEM_SID_ClearPrestoredFreezeFrame)
#error DEM_SID_ClearPrestoredFreezeFrame already defined
#endif
/** \brief Service Id for Dem_ClearPrestoredFreezeFrame() */
#define DEM_SID_ClearPrestoredFreezeFrame                         0x07U

#if (defined DEM_SID_SetOperationCycleState)
#error DEM_SID_SetOperationCycleState already defined
#endif
/** \brief Service Id for Dem_SetOperationCycleState() */
#define DEM_SID_SetOperationCycleState                            0x08U

#if (defined DEM_SID_SetOperationCycleCntValue)
#error DEM_SID_SetOperationCycleCntValue already defined
#endif
/** \brief Service Id for Dem_SetOperationCycleCntValue() */
#define DEM_SID_SetOperationCycleCntValue                         0x09U

#if (defined DEM_SID_SetAgingCycleState)
#error DEM_SID_SetAgingCycleState already defined
#endif
/** \brief Service Id for Dem_SetAgingCycleState() */
#define DEM_SID_SetAgingCycleState                                0x11U

#if (defined DEM_SID_SetAgingCycleCounterValue)
#error DEM_SID_SetAgingCycleCounterValue already defined
#endif
/** \brief Service Id for Dem_SetAgingCycleCounterValue() */
#define DEM_SID_SetAgingCycleCounterValue                         0x12U

#if (defined DEM_SID_GetEventStatus)
#error DEM_SID_GetEventStatus already defined
#endif
/** \brief Service Id for Dem_GetEventStatus() */
#define DEM_SID_GetEventStatus                                    0x0AU

#if (defined DEM_SID_GetEventFailed)
#error DEM_SID_GetEventFailed already defined
#endif
/** \brief Service Id for Dem_GetEventFailed() */
#define DEM_SID_GetEventFailed                                    0x0BU

#if (defined DEM_SID_GetEventTested)
#error DEM_SID_GetEventTested already defined
#endif
/** \brief Service Id for Dem_GetEventTested() */
#define DEM_SID_GetEventTested                                    0x0CU

#if (defined DEM_SID_GetDTCOfEvent)
#error DEM_SID_GetDTCOfEvent already defined
#endif
/** \brief Service Id for Dem_GetDTCOfEvent() */
#define DEM_SID_GetDTCOfEvent                                     0x0DU

#if (defined DEM_SID_SetEnableCondition)
#error DEM_SID_SetEnableCondition already defined
#endif
/** \brief Service Id for Dem_SetEnableCondition() */
#define DEM_SID_SetEnableCondition                                0x39U

#if (defined DEM_SID_SetStorageCondition)
#error DEM_SID_SetStorageCondition already defined
#endif
/** \brief Service Id for Dem_SetStorageCondition() */
#define DEM_SID_SetStorageCondition                               0x38U

#if (defined DEM_SID_GetFaultDetectionCounter)
#error DEM_SID_GetFaultDetectionCounter already defined
#endif
/** \brief Service Id for Dem_GetFaultDetectionCounter() */
#define DEM_SID_GetFaultDetectionCounter                          0x3EU

#if (defined DEM_SID_GetIndicatorStatus)
#error DEM_SID_GetIndicatorStatus already defined
#endif
/** \brief Service Id for Dem_GetIndicatorStatus() */
#define DEM_SID_GetIndicatorStatus                                0x29U

#if (defined DEM_SID_GetEventFreezeFrameData)
#error DEM_SID_GetEventFreezeFrameData already defined
#endif
/** \brief Service Id for Dem_GetEventFreezeFrameData() */
#define DEM_SID_GetEventFreezeFrameData                           0x31U

#if (defined DEM_SID_GetEventExtendedDataRecord)
#error DEM_SID_GetEventExtendedDataRecord already defined
#endif
/** \brief Service Id for Dem_GetEventExtendedDataRecord() */
#define DEM_SID_GetEventExtendedDataRecord                        0x30U

#if (defined DEM_SID_GetEventMemoryOverflow)
#error DEM_SID_GetEventMemoryOverflow already defined
#endif
/** \brief Service Id for Dem_GetEventMemoryOverflow() */
#define DEM_SID_GetEventMemoryOverflow                            0x32U

#if (defined DEM_SID_GetNumberOfEventMemoryEntries)
#error DEM_SID_GetNumberOfEventMemoryEntries already defined
#endif
/** \brief Service Id for Dem_GetNumberOfEventMemoryEntries() */
#define DEM_SID_GetNumberOfEventMemoryEntries                     0x35U

#if (defined DEM_SID_GetSI30Status)
#error DEM_SID_GetSI30Status already defined
#endif
/** \brief Service Id for Dem_GetSI30Status() */
#define DEM_SID_GetSI30Status                                     0x83U

#if (defined DEM_SID_SetSI30Symptom)
#error DEM_SID_SetSI30Symptom already defined
#endif
/** \brief Service Id for Dem_SetSI30Symptom() */
#define DEM_SID_SetSI30Symptom                                     0x84U

#if (defined DEM_SID_SetSI30Notification)
#error DEM_SID_SetSI30Notification already defined
#endif
/** \brief Service Id for Dem_SetSI30Notification() */
#define DEM_SID_SetSI30Notification                               0x85U

#if (defined DEM_SID_SetDTCSuppression)
#error DEM_SID_SetDTCSuppression already defined
#endif
/** \brief Service Id for Dem_SetDTCSuppression() */
#define DEM_SID_SetDTCSuppression                                 0x33U

/* Interface Dcm <--> Dem */

#if (defined DEM_SID_SetDTCFilter)
#error DEM_SID_SetDTCFilter already defined
#endif
/** \brief Service Id for Dem_SetDTCFilter() */
#define DEM_SID_SetDTCFilter                                      0x13U

#if (defined DEM_SID_SetFreezeFrameRecordFilter)
#error DEM_SID_SetFreezeFrameRecordFilter already defined
#endif
/** \brief Service Id for Dem_SetFreezeFrameRecordFilter() */
#define DEM_SID_SetFreezeFrameRecordFilter                        0x3FU

#if (defined DEM_SID_GetStatusOfDTC)
#error DEM_SID_GetStatusOfDTC already defined
#endif
/** \brief Service Id for Dem_GetStatusOfDTC() */
#define DEM_SID_GetStatusOfDTC                                    0x15U

#if (defined DEM_SID_GetDTCStatusAvailabilityMask)
#error DEM_SID_GetDTCStatusAvailabilityMask already defined
#endif
/** \brief Service Id for Dem_GetDTCStatusAvailabilityMask() */
#define DEM_SID_GetDTCStatusAvailabilityMask                      0x16U

#if (defined DEM_SID_GetNumberOfFilteredDTC)
#error DEM_SID_GetNumberOfFilteredDTC already defined
#endif
/** \brief Service Id for Dem_GetNumberOfFilteredDTC() */
#define DEM_SID_GetNumberOfFilteredDTC                            0x17U

#if (defined DEM_SID_GetNextFilteredDTC)
#error DEM_SID_GetNextFilteredDTC already defined
#endif
/** \brief Service Id for Dem_GetNextFilteredDTC() */
#define DEM_SID_GetNextFilteredDTC                                0x18U

#if (defined DEM_SID_GetDTCByOccurrenceTime)
#error DEM_SID_GetDTCByOccurrenceTime already defined
#endif
/** \brief Service Id for Dem_GetDTCByOccurrenceTime() */
#define DEM_SID_GetDTCByOccurrenceTime                            0x19U

#if (defined DEM_SID_GetNextFilteredRecord)
#error DEM_SID_GetNextFilteredRecord already defined
#endif
/** \brief Service Id for Dem_GetNextFilteredRecord() */
#define DEM_SID_GetNextFilteredRecord                             0x3AU

#if (defined DEM_SID_GetNextFilteredDTCAndFDC)
#error DEM_SID_GetNextFilteredDTCAndFDC already defined
#endif
/** \brief Service Id for Dem_GetNextFilteredDTCAndFDC() */
#define DEM_SID_GetNextFilteredDTCAndFDC                          0x3BU

#if (defined DEM_SID_GetNextFilteredDTCAndSeverity)
#error DEM_SID_GetNextFilteredDTCAndSeverity already defined
#endif
/** \brief Service Id for Dem_GetNextFilteredDTCAndSeverity() */
#define DEM_SID_GetNextFilteredDTCAndSeverity                     0x3DU

#if (defined DEM_SID_GetTranslationType)
#error DEM_SID_GetTranslationType already defined
#endif
/** \brief Service Id for Dem_GetTranslationType() */
#define DEM_SID_GetTranslationType                                0x3CU

#if (defined DEM_SID_GetSeverityOfDTC)
#error DEM_SID_GetSeverityOfDTC already defined
#endif
/** \brief Service Id for Dem_GetSeverityOfDTC() */
#define DEM_SID_GetSeverityOfDTC                                  0x0EU

#if (defined DEM_SID_GetFunctionalUnitOfDTC)
#error DEM_SID_GetFunctionalUnitOfDTC already defined
#endif
/** \brief Service Id for Dem_GetFunctionalUnitOfDTC() */
#define DEM_SID_GetFunctionalUnitOfDTC                            0x34U

#if (defined DEM_SID_DisableDTCRecordUpdate)
#error DEM_SID_DisableDTCRecordUpdate already defined
#endif
/** \brief Service Id for Dem_DisableDTCRecordUpdate() */
#define DEM_SID_DisableDTCRecordUpdate                            0x1AU

#if (defined DEM_SID_EnableDTCRecordUpdate)
#error DEM_SID_EnableDTCRecordUpdate already defined
#endif
/** \brief Service Id for Dem_EnableDTCRecordUpdate() */
#define DEM_SID_EnableDTCRecordUpdate                             0x1BU

#if (defined DEM_SID_GetFreezeFrameDataByRecord)
#error DEM_SID_GetFreezeFrameDataByRecord already defined
#endif
/** \brief Service Id for Dem_GetFreezeFrameDataByRecord() */
#define DEM_SID_GetFreezeFrameDataByRecord                        0x1CU

#if (defined DEM_SID_GetFreezeFrameDataByDTC)
#error DEM_SID_GetFreezeFrameDataByDTC already defined
#endif
/** \brief Service Id for Dem_GetFreezeFrameDataByDTC() */
#define DEM_SID_GetFreezeFrameDataByDTC                           0x1DU

#if (defined DEM_SID_GetSizeOfFreezeFrameByDTC)
#error DEM_SID_GetSizeOfFreezeFrameByDTC already defined
#endif
/** \brief Service Id for Dem_GetSizeOfFreezeFrameByDTC() */
#define DEM_SID_GetSizeOfFreezeFrameByDTC                         0x1FU

#if (defined DEM_SID_GetExtendedDataRecordByDTC)
#error DEM_SID_GetExtendedDataRecordByDTC already defined
#endif
/** \brief Service Id for Dem_GetExtendedDataRecordByDTC() */
#define DEM_SID_GetExtendedDataRecordByDTC                        0x20U

#if (defined DEM_SID_GetSizeOfExtendedDataRecordByDTC)
#error DEM_SID_GetSizeOfExtendedDataRecordByDTC already defined
#endif
/** \brief Service Id for Dem_GetSizeOfExtendedDataRecordByDTC() */
#define DEM_SID_GetSizeOfExtendedDataRecordByDTC                  0x21U

#if (DEM_DEFAULT_ASR_SERVICE_API == DEM_SERVICE_API_ASR42)
#if (defined DEM_SID_ASR42_ClearDTC)
#error DEM_SID_ASR42_ClearDTC already defined
#endif
/** \brief Service Id for Dem_ClearDTC() according with ASR42 */
#define DEM_SID_ASR42_ClearDTC                                    0x23U
#endif

#if (defined DEM_SID_DcmClearDTC)
#error DEM_SID_DcmClearDTC already defined
#endif
/** \brief Service Id for Dem_DcmClearDTC() according with ASR42 */
#define DEM_SID_DcmClearDTC                                       0x22U

#if (defined DEM_SID_DisableDTCSetting)
#error DEM_SID_DisableDTCSetting already defined
#endif
/** \brief Service Id for Dem_DisableDTCSetting() */
#define DEM_SID_DisableDTCSetting                                 0x24U

#if (defined DEM_SID_EnableDTCSetting)
#error DEM_SID_EnableDTCSetting already defined
#endif
/** \brief Service Id for Dem_EnableDTCSetting() */
#define DEM_SID_EnableDTCSetting                                  0x25U

#if (defined DEM_SID_DcmCancelOperation)
#error DEM_SID_DcmCancelOperation already defined
#endif
/** \brief Service Id for Dem_DcmCancelOperation() */
#define DEM_SID_DcmCancelOperation                                0x2AU

#if (defined DEM_SID_SetWIRStatus)
#error DEM_SID_SetWIRStatus already defined
#endif
/** \brief Service Id for Dem_SetWIRStatus() */
#define DEM_SID_SetWIRStatus                                      0x7AU

/* OBD-specific Interfaces */

#if (defined DEM_SID_SetEventDisabled)
#error DEM_SID_SetEventDisabled already defined
#endif
/** \brief Service Id for Dem_SetEventDisabled() */
#define DEM_SID_SetEventDisabled                                  0x51U

#if (defined DEM_SID_RepIUMPRFaultDetect)
#error DEM_SID_RepIUMPRFaultDetect already defined
#endif
/** \brief Service Id for Dem_RepIUMPRFaultDetect() */
#define DEM_SID_RepIUMPRFaultDetect                               0x73U

#if (defined DEM_SID_RepIUMPRDenLock)
#error DEM_SID_RepIUMPRDenLock already defined
#endif
/** \brief Service Id for Dem_RepIUMPRDenLock() */
#define DEM_SID_RepIUMPRDenLock                                   0x71U

#if (defined DEM_SID_RepIUMPRDenRelease)
#error DEM_SID_RepIUMPRDenRelease already defined
#endif
/** \brief Service Id for Dem_RepIUMPRDenRelease() */
#define DEM_SID_RepIUMPRDenRelease                                0x72U

#if (defined DEM_SID_GetInfoTypeValue08)
#error DEM_SID_GetInfoTypeValue08 already defined
#endif
/** \brief Service Id for Dem_GetInfoTypeValue08() */
#define DEM_SID_GetInfoTypeValue08                                0x6BU

#if (defined DEM_SID_GetInfoTypeValue0B)
#error DEM_SID_GetInfoTypeValue0B already defined
#endif
/** \brief Service Id for Dem_GetInfoTypeValue0B() */
#define DEM_SID_GetInfoTypeValue0B                                0x6CU

#if (defined DEM_SID_DcmReadDataOfPID01)
#error DEM_SID_DcmReadDataOfPID01 already defined
#endif
/** \brief Service Id for Dem_DcmReadDataOfPID01() */
#define DEM_SID_DcmReadDataOfPID01                                0x61U

#if (defined DEM_SID_DcmReadDataOfPID21)
#error DEM_SID_DcmReadDataOfPID21 already defined
#endif
/** \brief Service Id for Dem_DcmReadDataOfPID21() */
#define DEM_SID_DcmReadDataOfPID21                                0x64U

#if (defined DEM_SID_DcmReadDataOfPID30)
#error DEM_SID_DcmReadDataOfPID30 already defined
#endif
/** \brief Service Id for Dem_DcmReadDataOfPID30() */
#define DEM_SID_DcmReadDataOfPID30                                0x65U

#if (defined DEM_SID_DcmReadDataOfPID31)
#error DEM_SID_DcmReadDataOfPID31 already defined
#endif
/** \brief Service Id for Dem_DcmReadDataOfPID31() */
#define DEM_SID_DcmReadDataOfPID31                                0x66U

#if (defined DEM_SID_DcmReadDataOfPID41)
#error DEM_SID_DcmReadDataOfPID41 already defined
#endif
/** \brief Service Id for Dem_DcmReadDataOfPID41() */
#define DEM_SID_DcmReadDataOfPID41                                0x67U

#if (defined DEM_SID_DcmReadDataOfPID4D)
#error DEM_SID_DcmReadDataOfPID4D already defined
#endif
/** \brief Service Id for Dem_DcmReadDataOfPID4D() */
#define DEM_SID_DcmReadDataOfPID4D                                0x68U

#if (defined DEM_SID_DcmReadDataOfPID4E)
#error DEM_SID_DcmReadDataOfPID4E already defined
#endif
/** \brief Service Id for Dem_DcmReadDataOfPID4E() */
#define DEM_SID_DcmReadDataOfPID4E                                0x69U

#if (defined DEM_SID_DcmReadDataOfPID1C)
#error DEM_SID_DcmReadDataOfPID1C already defined
#endif
/** \brief Service Id for Dem_DcmReadDataOfPID1C() */
#define DEM_SID_DcmReadDataOfPID1C                                0x63U

#if (defined DEM_SID_ReadDataOfOBDFreezeFrame)
#error DEM_SID_ReadDataOfOBDFreezeFrame already defined
#endif
/** \brief Service Id for Dem_ReadDataOfOBDFreezeFrame() */
#define DEM_SID_ReadDataOfOBDFreezeFrame                          0x52U

#if (defined DEM_SID_GetDTCOfOBDFreezeFrame)
#error DEM_SID_GetDTCOfOBDFreezeFrame already defined
#endif
/** \brief Service Id for Dem_GetDTCOfOBDFreezeFrame() */
#define DEM_SID_GetDTCOfOBDFreezeFrame                            0x53U

#if (defined DEM_SID_SetPtoStatus)
#error DEM_SID_SetPtoStatus already defined
#endif
/** \brief Service Id for Dem_SetPtoStatus() */
#define DEM_SID_SetPtoStatus                                      0x79U

#if (defined DEM_SID_SetPfcCycleQualified)
#error DEM_SID_SetPfcCycleQualified already defined
#endif
/** \brief Service Id for Dem_SetPfcCycleQualifieds() */
#define DEM_SID_SetPfcCycleQualified                              0xAAU

#if (defined DEM_SID_GetPfcCycleQualified)
#error DEM_SID_GetPfcCycleQualified already defined
#endif
/** \brief Service Id for Dem_GetPfcCycleQualifieds() */
#define DEM_SID_GetPfcCycleQualified                              0xABU

#if (defined DEM_SID_ResetReadiness)
#error DEM_SID_ResetReadiness already defined
#endif
/** \brief Service Id for Dem_ResetReadiness() */
#define DEM_SID_ResetReadiness                                    0xACU

/* Vendor specific functions */

#if (defined DEM_SID_SetStoredDTCFilter)
#error DEM_SID_SetStoredDTCFilter already defined
#endif
/** \brief Service Id for Dem_DcmSetStoredDTCFilter() */
#define DEM_SID_SetStoredDTCFilter                                0x90U

#if (defined DEM_SID_GetNextFilteredStoredDTC)
#error DEM_SID_GetNextFilteredStoredDTC already defined
#endif
/** \brief Service Id for Dem_DcmGetNextFilteredStoredDTC() */
#define DEM_SID_GetNextFilteredStoredDTC                          0x91U

/* Scheduled functions */

#if (defined DEM_SID_MainFunction)
#error DEM_SID_MainFunction already defined
#endif
/** \brief Service Id for Dem_MainFunction() */
#define DEM_SID_MainFunction                                      0x55U

/* Callout functions */

#if (defined DEM_SID_CalloutDynamicDTCFnc)
#error DEM_SID_CalloutDynamicDTCFnc already defined
#endif
/** \brief Service Id for configured dynamic DTC callout function */
#define DEM_SID_CalloutDynamicDTCFnc                              0x80U

#if (defined DEM_SID_StoreImmediatelyNext)
#error DEM_SID_StoreImmediatelyNext already defined
#endif
/** \brief Service Id for Dem_StoreImmediatelyNext() */
#define DEM_SID_StoreImmediatelyNext                              0x81U

/* Debouncing functions */

#if (defined DEM_SID_ProcessUnconfirmedThreshold)
#error DEM_SID_ProcessUnconfirmedThreshold already defined
#endif
/** \brief Service Id for Dem_DebounceEventCounterBased() */
#define DEM_SID_ProcessUnconfirmedThreshold                       0x82U

/* Extended data assembly functions */

#if (defined DEM_SID_AssembleEDSegIntData)
#error DEM_SID_AssembleEDSegIntData already defined
#endif
/** \brief Service Id for Dem_AssembleEDSegIntData() */
#define DEM_SID_AssembleEDSegIntData                              0x86U

#if (defined DEM_SID_AssembleEDCounterIntData)
#error DEM_SID_AssembleEDCounterIntData already defined
#endif
/** \brief Service Id for Dem_AssembleEDCounterIntData() */
#define DEM_SID_AssembleEDCounterIntData                          0x87U

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* if !defined( DEM_STC_H ) */
/*==================[end of file]===========================================*/

/**
 * \file
 *
 * \brief AUTOSAR Xcp
 *
 * This file contains the implementation of the AUTOSAR
 * module Xcp.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 11.5 (advisory)
 * A conversion should not be performed from pointer to void into pointer to object
 *
 * Reason: The MTA address for write purposes is needed.
 *
 *
 */
/*==================[inclusions]============================================*/

#include <Xcp.h>               /* Module public API */
#if ( (XCP_DEFAULT_XCP_MODULE_STATE == STD_ON) || (XCP_ENABLE_XCP_CONTROL_API == STD_ON) )
#include <TSAutosar.h>         /* EB specific standard types */
#include <TSMem.h>             /* EB memory functions */
#include <SchM_Xcp.h>          /* Needed for exclusive area definition */
#include <Xcp_Trace.h>

#include <Xcp_Int.h>           /* Internal API */
#include <Xcp_UserCallouts.h>  /* XCP user callout functions */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

#if (XCP_RESOURCE_STIM == XCP_RESOURCE_STIM_MASK)

#define XCP_START_SEC_CODE
#include <MemMap.h>

/** \brief Function used to get the Stim package length information
 **
 ** This function calculates and retreives the DTO package information:
 ** - data header size
 ** - data size
 **
 ** \param[in] DaqId           The Id of the DAQ list related to the DTO
 ** \param[in] OdtId           The ODT Index related to the DTO
 ** \param[out] HeaderSizePtr  Pointer to the variable used to get data header size
 ** \param[out] DataSizePtr    Pointer to the variable used to get data size
 **/
STATIC FUNC(void, XCP_CODE) Xcp_GetStimDtoLength
(
  Xcp_DaqIdType DaqId,
  uint8 OdtId,
  CONSTP2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) HeaderSizePtr,
  CONSTP2VAR(PduLengthType, AUTOMATIC, XCP_APPL_DATA) DataSizePtr
);

/** \brief Function to insert a DTO into the STIM Buffer
 **
 ** This function is used to search for a DAQ List Id and ODT index in the
 ** STIM Buffer and insert the given DTO by replacing an existing entry
 ** or by adding a new entry.
 **
 ** \param[in] DaqID        The Id of the DAQ list related to the DTO
 ** \param[in] OdtIndex     The ODT Index related to the DTO
 ** \param[in] DataPtr      Pointer to the data within the DTO
 ** \param[in] DataCount    Number of data bytes within the DTO
 **/
STATIC FUNC(void, XCP_CODE) Xcp_InsertOdtToStimBuffer
(
  Xcp_DaqIdType DaqID,
  uint8 OdtIndex,
  P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) DataPtr,
  uint16 DataCount
);


/** \brief Function to stimulate the data of an ODT
 **
 ** This function is used to search an ODT in the STIM Buffer,
 ** stimulate the data assosiated with the ODT and remove the
 ** DTO entry from the STIM Buffer.
 **
 ** \param[in] DaqID     Index of the DAQ in the DAQ List
 ** \param[in] OdtIndex     The ODT Index
 **
 */
STATIC FUNC(void, XCP_CODE) Xcp_StimulateOdt
(
  Xcp_DaqIdType DaqID,
  uint8 OdtIndex
);


/** \brief Function to stimulate the data of an entire DAQ list
 **
 ** This function is used to search all ODTs for a DAQ in the STIM Buffer,
 ** stimulate the data assosiated with the ODTs and remove the
 ** DTO entries from the STIM Buffer.
 **
 ** \param[in] DaqID     Index of the DAQ in the DAQ List
 **
 */
STATIC FUNC(void, XCP_CODE) Xcp_StimulateDaq
(
  Xcp_DaqIdType DaqID
);


/** \brief Function to stimulate the data for an entire event
 **
 ** This function is used to search the STIM Buffer for each ODT of
 ** the DAQs associated with an event,
 ** stimulate the data assosiated with the ODTs and remove the
 ** DTO entries from the STIM Buffer.
 **
 ** \param[in] EventID      Event ID to process
 **
 */
STATIC FUNC(void, XCP_CODE) Xcp_StimulateEvent
(
  uint16 EventID
);

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*-----------------------------[Xcp_GetStimLength]------------------*/

FUNC(void, XCP_CODE) Xcp_GetStimLength
(
  P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) XcpRxSduPtr,
  P2VAR(PduLengthType, AUTOMATIC, XCP_APPL_DATA) DataLengthMin,
  P2VAR(PduLengthType, AUTOMATIC, XCP_APPL_DATA) DataLengthMax
)
{
  uint8 OdtId;
  Xcp_DaqIdType DaqID;
  uint8 HeaderSize = 0U;
  PduLengthType DataSize = 0U;


  DBG_XCP_GETSTIMLENGTH_ENTRY(XcpRxSduPtr);

  /* Get the DAQ Id and the ODT from the DTO packet */
  Xcp_GetDaqIDFromDto(XcpRxSduPtr, &DaqID, &OdtId);
  /* Get dto length information */
  Xcp_GetStimDtoLength(DaqID, OdtId, &HeaderSize, &DataSize);

  if(DataSize > 0U)
  {
    /* return Stim package length boundaries */
    *DataLengthMin = (PduLengthType)(HeaderSize + DataSize);
    *DataLengthMax = XCP_MAX_DTO;
  }
  else
  {
    /* reject the packages. this prevents invalid data access in case the
     * DaqList and/or OdtId is not configured */
    *DataLengthMin = 0U;
    *DataLengthMax = 0U;
  }

  DBG_XCP_GETSTIMLENGTH_EXIT(DataLengthMin,DataLengthMax);
}

/*-----------------------------[Xcp_InsertSTIM]------------------*/

FUNC(void, XCP_CODE) Xcp_InsertSTIM
(
  P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) SduDataPtr
)
{
  uint8 OdtId;
  Xcp_DaqIdType DaqId;
  uint8 HeaderSize = 0U;
  PduLengthType DataSize = 0U;

  DBG_XCP_INSERTSTIM_ENTRY(SduDataPtr);

  /* Get the DAQ Id and the ODT from the DTO packet */
  Xcp_GetDaqIDFromDto(SduDataPtr, &DaqId, &OdtId);
  /* get Stim package length information */
  Xcp_GetStimDtoLength(DaqId, OdtId, &HeaderSize, &DataSize);
  /* insert package to Odt mirror */
  Xcp_InsertOdtToStimBuffer(DaqId, OdtId, &SduDataPtr[HeaderSize], DataSize);

  DBG_XCP_INSERTSTIM_EXIT();
}

/*-----------------------------[Xcp_StimulateData]------------------*/

FUNC(void, XCP_CODE) Xcp_StimulateData
(
  uint16 EventID
)
{
  Xcp_DaqIdType DaqId = Xcp_Event[EventID].DaqIdListPtr[Xcp_Event[EventID].NextDaqIndex];
  P2VAR(Xcp_DaqType, AUTOMATIC, AUTOMATIC) DaqListPtr =
      XCP_GET_DAQ_LIST_PTR(DaqId);

  DBG_XCP_STIMULATEDATA_ENTRY(EventID);

  switch (XCP_GET_EVENT_CHANNEL_CONSISTENCY(EventID))
  {
    case XCP_EVENT_CHANNEL_CONSISTENCY_ODT:
    {
      /* For Odt consistency */
      if((DaqListPtr->Mode & XCP_MASK_DAQLIST_DIRECTION) == XCP_MASK_DAQLIST_DIRECTION_STIM)
      {
        Xcp_StimulateOdt(DaqId, Xcp_Event[EventID].NextOdtIndex);
      }
      break;
    }
    case XCP_EVENT_CHANNEL_CONSISTENCY_DAQ:
    {
      /* Stimulate the DAQ List */
      if ((DaqListPtr->Mode & XCP_MASK_DAQLIST_DIRECTION) == XCP_MASK_DAQLIST_DIRECTION_STIM)
      {
        Xcp_StimulateDaq(DaqId);
      }
      break;
    }
    default:
    {
      /* Stimulate the Event */
      Xcp_StimulateEvent(EventID);
      break;
    }
  }

  DBG_XCP_STIMULATEDATA_EXIT();
}

/*==================[internal function definitions]=========================*/

/*-----------------------------[Xcp_GetStimDtoLength]------------------*/

STATIC FUNC(void, XCP_CODE) Xcp_GetStimDtoLength
(
  Xcp_DaqIdType DaqId,
  uint8 OdtId,
  CONSTP2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) HeaderSizePtr,
  CONSTP2VAR(PduLengthType, AUTOMATIC, XCP_APPL_DATA) DataSizePtr
)
{
  /* local variable to hold the address of the requested DaqList */
  P2CONST(Xcp_DaqType,AUTOMATIC,AUTOMATIC) DaqListPtr;
  /* Local variable to hold address of the requested ODT */
  P2VAR(Xcp_OdtType, AUTOMATIC, XCP_VAR) OdtPtr;

  DBG_XCP_GETSTIMDTOLENGTH_ENTRY(DaqId, OdtId);

  /* initialize output parameters with 0 */
  *HeaderSizePtr = 0U;
  *DataSizePtr = 0U;

  if (DaqId < XCP_GET_NO_OF_CONFIGURED_DAQ_LISTS(Xcp_DaqIdType))
  {
    /* DAQ list corresponding to the received DTO */
    DaqListPtr = XCP_GET_DAQ_LIST_PTR(DaqId);

    if (OdtId < DaqListPtr->MaxOdt)
    {
      /* Iterator through ODT entries */
      uint8 i;
      /* Get the requested ODT */
      OdtPtr = &(DaqListPtr->OdtList[OdtId]);

      /* Prevent access if the ODTs were not assigned in the DAQ list (not just allocated, but an initial
       * ALLOC_ODT_ENTRY is needed for all allocated ODTs to be arranged in the dynamic area, if the DAQ
       * list is dynamically allocated) */
      if (OdtPtr != NULL_PTR)
      {
        /* Prevent access if the ODT does not have the address of its first ODT entry (i.e. there was no
         * SET_DAQ_PTR called at all)*/
        if (OdtPtr->OdtEntry != NULL_PTR)
        {
          /* add into account the Pid header size */
          *HeaderSizePtr += XCP_PID_LENGTH;

#if (XCP_TIMESTAMP_SUPPORTED == XCP_TIMESTAMP_MASK)
          /* Is time stamp supported and this is the first ODT of the DAQ list */
          if ((((DaqListPtr->Mode & XCP_MASK_DAQLIST_TIMESTAMPED_MODE) ==
                XCP_MASK_DAQLIST_TIMESTAMPED_MODE)) &&
              (0U == OdtId))
          {
            /* add into account the time stamp size */
            *HeaderSizePtr += XCP_TS_LENGTH;
          }
#endif /* (XCP_TIMESTAMP_SUPPORTED == XCP_TIMESTAMP_MASK) */

          /* calculate odt data size section */
          for (i = 0U; i < OdtPtr->NrOfOdtEntries; i++)
          {
            *DataSizePtr += (PduLengthType)OdtPtr->OdtEntry[i].Length *
                            XCP_GRANULARITY_ODT_ENTRY_SIZE_DAQ;
          }
        }
      }
    }
  }

  DBG_XCP_GETSTIMDTOLENGTH_EXIT(HeaderSizePtr, DataSizePtr);
}

/*-----------------------------[Xcp_InsertOdtToStimBuffer]------------------*/

STATIC FUNC(void, XCP_CODE) Xcp_InsertOdtToStimBuffer
(
  Xcp_DaqIdType DaqID,
  uint8 OdtIndex,
  P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) DataPtr,
  uint16 DataCount
)
{
  /* Position in the ODT Mirror buffer to insert the new entry */
  uint16 InsertPos;
  /* The DAQ list from Priority Queue */
  P2VAR(Xcp_DaqType, AUTOMATIC, XCP_VAR) DaqListPtr;

  /* Get the DAQ list */
  DaqListPtr = XCP_GET_DAQ_LIST_PTR(DaqID);
  /* Get the insert position from ODT mirror buffer */
  InsertPos = DaqListPtr->OdtList[OdtIndex].MirrorOffsetPos;

  DBG_XCP_INSERTODTTOSTIMBUFFER_ENTRY(DaqID,OdtIndex,DataPtr,DataCount);

  /* Protect Stim buffer from concurrent access */
  SchM_Enter_Xcp_SCHM_XCP_EXCLUSIVE_AREA_XCP_INTERNALS();

  /* Check if previous stimulation data was used for stimulation */
  if(XCP_IS_BYTE_FLAG_SET(OdtIndex, (Xcp_DaqRunTimeInfo[DaqID].IsNewOdtDataMask)) == FALSE)
  {
    /* Insert the new entry */
    TS_MemCpy(XCP_GET_MIRROR_PTR(DaqID, InsertPos), DataPtr, DataCount);
    /* Set bit mask in order to indicate that stimulation data is new */
    XCP_SET_BYTE_FLAG(OdtIndex, (Xcp_DaqRunTimeInfo[DaqID].IsNewOdtDataMask));
  }
#if(XCP_PROD_ERR_HANDLING_STIMULATION_DATA_LOST!= TS_PROD_ERR_DISABLE)
  else
  {
    /*Previous stimulation datat exists and therefore new entry cannot be added.
      Det notification is triggered.*/
      XCP_REPORT_STIMULATION_DATA_LOST(XCP_SID_INSERT_ODT_TO_STIM_BUFFER);
  }
#endif

  SchM_Exit_Xcp_SCHM_XCP_EXCLUSIVE_AREA_XCP_INTERNALS();

  DBG_XCP_INSERTODTTOSTIMBUFFER_EXIT();
}

/*-----------------------------[Xcp_StimulateOdt]------------------*/

STATIC FUNC(void, XCP_CODE) Xcp_StimulateOdt
(
  Xcp_DaqIdType DaqID,
  uint8 OdtIndex
)
{
  Xcp_OdtIdType OdtEntryId;
  uint8 OdtEntryLength;
  /* Get the DAQ list based on the DAQ list number */
  CONSTP2VAR(Xcp_DaqType,AUTOMATIC,AUTOMATIC) DaqListPtr =
      XCP_GET_DAQ_LIST_PTR(DaqID);

  /* Get the insert position from ODT mirror buffer */
  Xcp_MirrorSizeType DTOMirrorWritePos = DaqListPtr->OdtList[OdtIndex].MirrorOffsetPos;
  CONSTP2CONST(Xcp_OdtEntryType, AUTOMATIC, XCP_VAR) OdtEntryPtr =
      DaqListPtr->OdtList[OdtIndex].OdtEntry;
  const uint8 NrOfOdtEntries = DaqListPtr->OdtList[OdtIndex].NrOfOdtEntries;

  DBG_XCP_STIMULATEODT_ENTRY(DaqID,OdtIndex);

  /* for each ODT entry */
  for (OdtEntryId = 0U; OdtEntryId < NrOfOdtEntries; OdtEntryId++)
  {
    OdtEntryLength = (uint8)(OdtEntryPtr[OdtEntryId].Length *
                              XCP_GRANULARITY_ODT_ENTRY_SIZE_DAQ);

    if (OdtEntryLength != 0U)
    {
/* !LINKSTO Xcp.ProtectedMemoryLocations.General,1 */
#if (XCP_MEMORY_AREAS_ACCESS_SUPPORTED == STD_ON)
      if (Xcp_IsMemoryAreaAccessible
             (
                 OdtEntryPtr[OdtEntryId].Address,
                 OdtEntryLength,
                 XCP_MEMORY_AREA_TYPE_WRITE,
                 XCP_MEMORY_AREA_SCOPE_DAQ_STIM
             ) == FALSE
         )
      {
#if (XCP_PROD_ERR_HANDLING_ILLEGAL_MEMORY_ACCESS != TS_PROD_ERR_DISABLE)
        /* !LINKSTO Xcp.ProtectedMemoryLocations.NegativeResponse.DAQ,1 */
        /* report error */
        XCP_REPORT_ILLEGAL_MEMORY_ACCESS(XCP_SID_EVENT_MAIN_FUNCTION);
#endif
      }
      else
#endif
      {
        /* Protect data stimulation from concurrent access */
        SchM_Enter_Xcp_SCHM_XCP_EXCLUSIVE_AREA_XCP_INTERNALS();
        /* !LINKSTO Xcp.ASAM.BITWISE_STIMULATION.006,1 */
        if (OdtEntryPtr[OdtEntryId].BitOffset != XCP_BIT_OFFSET_IGNORE_VALUE)
        {
		 /* !LINKSTO Xcp.ASAM.BITWISE_STIMULATION.GENERAL001,1 */
          uint8 bitMask = 1U << OdtEntryPtr[OdtEntryId].BitOffset;

          /* Compare to 0 the value of the ODT elements*/
          if ((*XCP_GET_MIRROR_PTR(DaqID, DTOMirrorWritePos) & bitMask) > 0)
          {
            /* !LINKSTO Xcp.ASAM.BITWISE_STIMULATION.005,1 */
            /* Set the bit if the value is different from 0*/
            /* Deviation MISRAC2012-1 */
            *XCP_GET_MIRROR_PTR(DaqID, DTOMirrorWritePos) = *(uint8 *)XCP_APPL_GET_ADDRESS( 0U, OdtEntryPtr[OdtEntryId].Address)  | bitMask;
          }
          else
          {
            /* !LINKSTO Xcp.ASAM.BITWISE_STIMULATION.004,1 */
            /* Clear the bit if the value is 0*/
            /* Deviation MISRAC2012-1 */
            *XCP_GET_MIRROR_PTR(DaqID, DTOMirrorWritePos) = *(uint8 *)XCP_APPL_GET_ADDRESS( 0U, OdtEntryPtr[OdtEntryId].Address)  & (uint8)(~bitMask);
          }

        }
       /* Copy data from STIM DTO buffer to the ODT entry */
       TS_MemCpy(XCP_APPL_GET_ADDRESS( 0U, OdtEntryPtr[OdtEntryId].Address ),
                 XCP_GET_MIRROR_PTR(DaqID, DTOMirrorWritePos),
                 OdtEntryLength);
       SchM_Exit_Xcp_SCHM_XCP_EXCLUSIVE_AREA_XCP_INTERNALS();

       /* Increment the data count by length */
       DTOMirrorWritePos += OdtEntryLength;
      }
    }
    else
    {
      /* We need to stop as soon as we find an ODT entry with size 0 - ASAM requirement */
      break;
    }
  }

  /* reset semaphore to allow new STIM data to be received */
  XCP_CLEAR_BYTE_FLAG_ATOMIC(OdtIndex, (Xcp_DaqRunTimeInfo[DaqID].IsNewOdtDataMask));

  DBG_XCP_STIMULATEODT_EXIT();
}

/*-----------------------------[Xcp_StimulateDaq]------------------*/

STATIC FUNC(void, XCP_CODE) Xcp_StimulateDaq
(
  Xcp_DaqIdType DaqID
)
{
  uint8 OdtIndex; /* Variable to loop through each odt */
  /* Get the DAQ list based on the DAQ list number */
  CONSTP2VAR(Xcp_DaqType,AUTOMATIC,AUTOMATIC) DaqListPtr = XCP_GET_DAQ_LIST_PTR(DaqID);

  DBG_XCP_STIMULATEDAQ_ENTRY(DaqID);

  /* All the following ODTs are associated with the DAQ */
  for (OdtIndex = 0U; OdtIndex < DaqListPtr->MaxOdt; OdtIndex++)
  {
    /* stimulate Odt */
    Xcp_StimulateOdt(DaqID, OdtIndex);
  }

  DBG_XCP_STIMULATEDAQ_EXIT();
}

/*-----------------------------[Xcp_StimulateEvent]------------------*/

STATIC FUNC(void, XCP_CODE) Xcp_StimulateEvent
(
  uint16 EventID
)
{
  Xcp_DaqIdType DaqID;
  uint8 EvDaqIndex; /* Variable to loop through each Daq in the event */
  P2VAR(Xcp_DaqType,AUTOMATIC,AUTOMATIC) DaqListPtr;

  DBG_XCP_STIMULATEEVENT_ENTRY(EventID);

  for (EvDaqIndex = 0U; EvDaqIndex < Xcp_Event[EventID].DaqIdListCount; EvDaqIndex++)
  {
    /* Get the DAQ list number */
    DaqID = Xcp_Event[EventID].DaqIdListPtr[EvDaqIndex];
    /* Get each DAQ list for this event */
    DaqListPtr = XCP_GET_DAQ_LIST_PTR(DaqID);

    /* Check if DAQ List is running */
    if (((DaqListPtr->Mode & XCP_MASK_DAQLIST_DIRECTION) == XCP_MASK_DAQLIST_DIRECTION_STIM) &&
        ((DaqListPtr->Flags & XCP_MASK_DAQLIST_READY) == XCP_MASK_DAQLIST_READY))
    {
      /* Stimulate all the ODTs in the Daq */
      Xcp_StimulateDaq(DaqID);
    }
  }

  DBG_XCP_STIMULATEEVENT_EXIT();
}

#define XCP_STOP_SEC_CODE
#include <MemMap.h>

#endif

#endif /* ( (XCP_DEFAULT_XCP_MODULE_STATE == STD_ON) || (XCP_ENABLE_XCP_CONTROL_API == STD_ON) ) */

/*==================[end of file]===========================================*/

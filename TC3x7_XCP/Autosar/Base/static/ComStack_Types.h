#if (!defined COMSTACK_TYPES_H)
/* !LINKSTO COMTYPE016,1 */
#define COMSTACK_TYPES_H
/* !LINKSTO COMTYPE003,1, COMTYPE004,1 */

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

/* !LINKSTO STD016,1, COMTYPE001,1 */
#include <Std_Types.h>    /* AUTOSAR standard type declarations */
/* !LINKSTO COMTYPE001,1 */
#include <ComStack_Cfg.h> /* AUTOSAR ComStack type configurator dependent */

/*==================[macros]=================================================*/

/*------------------[AUTOSAR vendor identification]-------------------------*/

#if (defined COMSTYPE_VENDOR_ID)
#error COMTYPE_VENDOR_ID is already defined
#endif
/** \brief AUTOSAR vendor identification: EB Automotive */
#define COMTYPE_VENDOR_ID         1U

/*------------------[AUTOSAR module identification]-------------------------*/

#if (defined COMTYPE_MODULE_ID)
#error COMTYPE_MODULE_ID already defined
#endif
/** \brief AUTOSAR module identification
 *
 * Left empty as this header does not belong to any module
 */
#define COMTYPE_MODULE_ID      196U

/*------------------[AUTOSAR release version identification]----------------*/

#if (defined COMTYPE_AR_RELEASE_MAJOR_VERSION)
#error COMTYPE_AR_RELEASE_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR release major version */
#define COMTYPE_AR_RELEASE_MAJOR_VERSION     4U

#if (defined COMTYPE_AR_RELEASE_MINOR_VERSION)
#error COMTYPE_AR_RELEASE_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR release minor version */
#define COMTYPE_AR_RELEASE_MINOR_VERSION     0U

#if (defined COMTYPE_AR_RELEASE_REVISION_VERSION)
#error COMTYPE_AR_RELEASE_REVISION_VERSION already defined
#endif
/** \brief AUTOSAR release revision version */
#define COMTYPE_AR_RELEASE_REVISION_VERSION  3U

/*------------------[AUTOSAR module version identification]------------------*/

#if (defined COMTYPE_SW_MAJOR_VERSION)
#error COMTYPE_SW_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR module major version */
#define COMTYPE_SW_MAJOR_VERSION    3U

#if (defined COMTYPE_SW_MINOR_VERSION)
#error COMTYPE_SW_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR module minor version */
#define COMTYPE_SW_MINOR_VERSION    2U

#if (defined COMTYPE_SW_PATCH_VERSION)
#error COMTYPE_SW_PATCH_VERSION already defined
#endif
/** \brief AUTOSAR module patch version */
#define COMTYPE_SW_PATCH_VERSION    0U

/*------------------[AUTOSAR module vendor API infix]------------------------*/

#if (defined COMTYPE_VENDOR_API_INFIX)
#error COMTYPE_VENDOR_API_INFIX already defined
#endif
/** \brief Vendor API infix
 *
 * Left empty as this header does not belong to any module
 */
#define COMTYPE_VENDOR_API_INFIX

/*------------------[Notification: General Codes]----------------------------*/

/* !LINKSTO COMTYPE018,1 */

#if (defined NTFRSLT_OK)
#error NTFRSLT_OK already defined
#endif

/** \brief Notification code: Action has been successfully finished
 *
 * This is used when:
 * - message sent out (in case of confirmation)
 * - message received (in case if indication)
 */
#define NTFRSLT_OK 0x00U

#if (defined NTFRSLT_E_NOT_OK)
#error NTFRSLT_E_NOT_OK already defined
#endif

/** \brief Notification code: Error notification
 *
 * - message not successfully sent (in case of confirmation)
 * - message not successfully received (in case of indication)
 */
#define NTFRSLT_E_NOT_OK 0x01U

#if (defined NTFRSLT_E_TIMEOUT_A)
#error NTFRSLT_E_TIMEOUT_A already defined
#endif

/** \brief Notification code: Error notification
 *
 * - timer N_Ar/N_As (according to ISO specification [ISONM]) has
 *   passed its time-out value N_Asmax/N_Armax.
 *
 * This value can be issued to service user on both the sender and
 * receiver side.
 */
#define NTFRSLT_E_TIMEOUT_A 0x02U

#if (defined NTFRSLT_E_TIMEOUT_BS)
#error NTFRSLT_E_TIMEOUT_BS already defined
#endif

/** \brief Notification code: Error notification
 *
 * - timer N_Bs has passed its time-out value N_Bsmax
 *   (according to ISO specification [ISONM]).
 *
 * This value can be issued to the service user on the sender side only
 */
#define NTFRSLT_E_TIMEOUT_BS 0x03U

#if (defined NTFRSLT_E_TIMEOUT_CR)
#error NTFRSLT_E_TIMEOUT_CR already defined
#endif

/** \brief Notification code: Error notification
 *
 * - timer N_CR has passed its time-out value N_CRmax
 *
 * This value can be issued to the service user on the receiver side only
 */
#define NTFRSLT_E_TIMEOUT_CR 0x04U

#if (defined NTFRSLT_E_WRONG_SN)
#error NTFRSLT_E_WRONG_SN already defined
#endif

/** \brief Notification code: Error notification
 *
 * - unexpected sequence number (PCI.SN) value received
 *
 * This value can be issued to the service user on the receiver side only
 */
#define NTFRSLT_E_WRONG_SN 0x05U

#if (defined NTFRSLT_E_INVALID_FS)
#error NTFRSLT_E_INVALID_FS already defined
#endif

/** \brief Notification code: Error notification
 *
 * - invalid or unknown FlowStatus value has been received in a
 *   flow controll (FC) N_PDU
 *
 * This value can be issued to the service user on the sender side only.
 */
#define NTFRSLT_E_INVALID_FS 0x06U

#if (defined NTFRSLT_E_UNEXP_PDU)
#error NTFRSLT_E_UNEXP_PDU already defined
#endif

/** \brief Notification code: Error notification
 *
 * - unexpected protocol data unit received
 *
 * This value can be issued to the service user on both
 * the sender and receiver side.
 */
#define NTFRSLT_E_UNEXP_PDU 0x07U

#if (defined NTFRSLT_E_WFT_OVRN)
#error NTFRSLT_E_WFT_OVRN already defined
#endif

/** \brief Notification code: Error notification
 *
 * - flow control WAIT fram that exceeds the maximum counter
 *   N_WFTmax received.
 *
 * This value can be issued to the service user on the sender side.
 */
#define NTFRSLT_E_WFT_OVRN 0x08U

#if (defined NTFRSLT_E_ABORT)
#error NTFRSLT_E_ABORT is already defined
#endif
/** \brief Notification code: Error notification
 *
 * - Flow control (FC) N_PDU with FlowStatus = ABORT received. It indicates an abort of a
 *   transmission. A possible reason for this is that the receiver is currently busy and
 *   can not take the request at that point in time.
 *
 * This value can be issued to the service user on the sender side.
 */
#define NTFRSLT_E_ABORT 0x09U

/** \brief Notification code: Error notification
 *
 * - flow control (FC) N_PDU with FlowStatus = OVFLW received.
 *   It indicates that the buffer on the receiver side of a segmented
 *   message transmission cannot store the number of bytes specified by
 *   the FirstFrame DataLength (FF_DL) parameter in the FirstFFrame and
 *   therefore the transmission of the segmented message was aborted.
 * - no buffer within the TP available to transmit the segmented I-PDU.
 *
 * This value can be issued to the service user on both
 * the sender and receiver side.
 */
#define NTFRSLT_E_NO_BUFFER 0x0AU

#if (defined NTFRSLT_E_CANCELATION_OK)
#error NTFRSLT_E_CANCELATION_OK already defined
#endif

/** \brief Requested cancellation has been executed */
#define NTFRSLT_E_CANCELATION_OK 0x0BU

#if (defined NTFRSLT_E_CANCELATION_NOT_OK)
#error NTFRSLT_E_CANCELATION_NOT_OK already defined
#endif

/** \brief Request cancellation has not been executed
 *
 * Due to an internal error the requested cancelation has not been executed.
 * This will happen e.g., if the to be canceled transmission has been
 * executed already.
 */
#define NTFRSLT_E_CANCELATION_NOT_OK 0x0CU

#if (defined NTFRSLT_PARAMETER_OK) /* prevent double definition */
#error NTFRSLT_PARAMETER_OK already defined
#endif

/* see Autosar Bugzilla 33259 for the next value */
/** \brief Parameter value is not ok */
#define NTFRSLT_PARAMETER_OK 0x0DU

#if (defined NTFRSLT_E_PARAMETER_NOT_OK)
#error NTFRSLT_E_PARAMETER_NOT_OK already defined
#endif

/* see Autosar Bugzilla 33259 for the next value */
/** \brief Parameter value is not ok */
#define NTFRSLT_E_PARAMETER_NOT_OK 0x0EU

#if (defined NTFRSLT_E_RX_ON)
#error NTFRSLT_E_RX_ON already defined
#endif

/* see Autosar Bugzilla 33259 for the next value */
/** \brief Reception ongoing */
#define NTFRSLT_E_RX_ON 0x0FU

#if (defined NTFRSLT_E_VALUE_NOT_OK)
#error NTFRSLT_E_VALUE_NOT_OK already defined
#endif

/* see Autosar Bugzilla 33259 for the next value */
/** \brief Parameter value is in invalid range */
#define NTFRSLT_E_VALUE_NOT_OK 0x10U

/*------------------[Bus Error: General Codes]-------------------------------*/

/* !LINKSTO COMTYPE021,1 */

#if (defined BUSTRCV_OK)
#error BUSTRCV_OK already defined
#endif

/** \brief Code for: no bus error
 *
 * There is no bus transceiver error seen by the driver of transceiver
 * does not support the detection of bus errors.
 */
#define BUSTRCV_OK 0x00U

#if (defined BUSTRCV_E_ERROR)
#error BUSTRCV_E_ERROR already defined
#endif

/** \brief Bus transceiver detected an unclassified error. */
#define BUSTRCV_E_ERROR 0x01U

/*==================[type definitions]=======================================*/

/** \brief type for storage of basic information about a PDU
 *
 * This type shall be used to store the basic information about a PDU of
 * any type, namely a pointer variable pointing to it's SDU (payload) and
 * the corresponding length of the SDU in bytes.
 */
typedef struct
{
   /** \brief pointer to the SDU of the PDU  */
   P2VAR(uint8, AUTOMATIC, AUTOSAR_COMSTACKDATA) SduDataPtr;
   /** \brief length of SDU in bytes */
   PduLengthType SduLength;
} PduInfoType;


/** \brief Provide an alias for FrTp BandwithControl (BC) parameter, which is
  *        semantically identical to STMin
  */
#define TP_BC TP_STMIN

/** \brief Specifies which TP parameter has to be changed (BS or STMin).
 *
 * This type shall be used to specify which TP parameter shall be changed when invoking
 * xx_ChangeParameterRequest().
 */
typedef enum
{
    /** \brief This literal identifies TP parameter STMin (Minimum value of TP time-span ST) */
    TP_STMIN,
    /** \brief This literal identifies TP parameter BS (Blocksize) */
    TP_BS
} TPParameterType;


/** \brief TP parameter literal of ASR3.2 for the ST min parameter */
#define TPPARAMETER_STMIN TP_STMIN
/** \brief TP parameter literal of ASR3.2 for the Block size parameter */
#define TPPARAMTERE_BS    TP_BS
/** \brief TP parameter literal of ASR3.2 for the BandwidthControl parameter used in
 *         FlexRay transport protocol module.
 */
#define TPPARAMETER_BC    TP_BC
/** \brief TP parameter literal of ASR3.2 for the Block size parameter including RfC 58315 */
#define TPPARAMETER_BS    TP_BS


/** \brief type for storage of the result of a buffer request */
typedef enum
{
   /** \brief Buffer request accomplished successful */
   BUFREQ_OK,
   /** \brief Buffer request not successful, buffer cannot be accessed. */
   BUFREQ_E_NOT_OK,
   /** \brief Temporarily no buffer available. */
   BUFREQ_E_BUSY,
   /** \brief no buffer of the required length can be provided */
   BUFREQ_E_OVFL
} BufReq_ReturnType;

/** \brief type for storage of notification result status */
typedef uint8 NotifResultType;

/** \brief Bus status type definition
 *
 * Variables of this type are used to return the bus status
 * evaluated by a transceiver.
 */
typedef uint8 BusTrcvErrorType;

/** \brief Type to store the state of the TP buffer */
typedef enum
{
  /** \brief TP_DATACONF indicates that all data, that have been copied
   *         so far, are confirmed and can be removed from the TP buffer.
   *
   * Data copied by this API call are excluded and will be confirmed later.
   */
  TP_DATACONF,
  /** \brief TP_DATARETRY indicates that this API call shall copy already
   *         copied data in order to recover from an error.
   *
   * In this case TxTpDataCnt specifies the offset of the first byte
   * to be copied by the API call.
   */
  TP_DATARETRY,
  /** \brief TP_CONFPENDING indicates that the previously copies data must
   * remain in the TP.
   */
  TP_CONFPENDING
} TpDataStateType;

/** \brief Type to store TP buffer handling information */
typedef struct
{
  TpDataStateType TpDataState;
  PduLengthType TxTpDataCnt;
} RetryInfoType;

/** \brief Identifier of a communication channel
 *
 * Variables of the type NetworkHandleType shall be used to store
 * the identifier of a communication channel
 */
typedef uint8 NetworkHandleType;

/** \brief Identifier of a partial network cluster
 *
 * Variables of the type PNCHandleType shall be used to store
 * the identifier of a partial network cluster.
 *
 * This type is not specified in the Communication Stack Types SWS of AUTOSAR
 * R4.0.3 but it is required by the ComM SWS.
 */
typedef uint8 PNCHandleType;

/*==================[end of file]============================================*/
#endif /* if !defined( COMSTACK_TYPES_H ) */

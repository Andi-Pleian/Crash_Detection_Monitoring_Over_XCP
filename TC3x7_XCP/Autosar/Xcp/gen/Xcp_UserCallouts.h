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
 * MISRAC2012-1) Deviated Rule: 20.7 (required)
 * Expanded macro parameter 'rettype' shall be enclosed in parentheses
 *
 * Reason: AUTOSAR definition convention. Compiler abstraction macro.
 *
 */
#if (!defined XCP_USERCALLOUTS_H)
#define XCP_USERCALLOUTS_H


/*==================[includes]===============================================*/

#include <Xcp.h>

/*==================[macros]=================================================*/

#if (defined XCP_APPL_OK)
#error XCP_APPL_OK already defined
#endif
/** \brief return value of XCP application callout for successful execution. */
#define XCP_APPL_OK                     0x01U

#if (defined XCP_APPL_ERR_CMD_UNKNOWN)
#error XCP_APPL_ERR_CMD_UNKNOWN already defined
#endif
/** \brief return value of XCP application callout with XCP ERR_CMD_UNKNOWN error code. */
#define XCP_APPL_ERR_CMD_UNKNOWN        0x20U

#if (defined XCP_APPL_ERR_OUT_OF_RANGE)
#error XCP_APPL_ERR_OUT_OF_RANGE already defined
#endif
/** \brief return value of XCP application callout with XCP ERR_OUT_OF_RANGE error code. */
#define XCP_APPL_ERR_OUT_OF_RANGE       0x22U

#if (defined XCP_APPL_ERR_WRITE_PROTECTED)
#error XCP_APPL_ERR_WRITE_PROTECTED already defined
#endif
/** \brief return value of XCP application callout with XCP ERR_WRITE_PROTECTED error code. */
#define XCP_APPL_ERR_WRITE_PROTECTED    0x23U

#if (defined XCP_APPL_ERR_ACCESS_DENIED)
#error XCP_APPL_ERR_ACCESS_DENIED already defined
#endif
/** \brief return value of XCP application callout with XCP ERR_ACCESS_DENIED error code. */
#define XCP_APPL_ERR_ACCESS_DENIED      0x24U

#if (defined XCP_APPL_ERR_PAGE_NOT_VALID)
#error XCP_APPL_ERR_PAGE_NOT_VALID already defined
#endif
/** \brief return value of XCP application callout with XCP ERR_PAGE_NOT_VALID error code. */
#define XCP_APPL_ERR_PAGE_NOT_VALID     0x26U

#if (defined XCP_APPL_ERR_MODE_NOT_VALID)
#error XCP_APPL_ERR_MODE_NOT_VALID already defined
#endif
/** \brief return value of XCP application callout with XCP ERR_MODE_NOT_VALID error code. */
#define XCP_APPL_ERR_MODE_NOT_VALID     0x27U

#if (defined XCP_APPL_ERR_SEGMENT_NOT_VALID)
#error XCP_APPL_ERR_SEGMENT_NOT_VALID already defined
#endif
/** \brief return value of XCP application callout XCP ERR_SEGMENT_NOT_VALID error code. */
#define XCP_APPL_ERR_SEGMENT_NOT_VALID  0x28U

#if (defined XCP_APPL_ERR_MEMORY_OVERFLOW)
#error XCP_APPL_ERR_MEMORY_OVERFLOW already defined
#endif
/** \brief return value of XCP application callout with XCP ERR_MEMORY_OVERFLOW error code. */
#define XCP_APPL_ERR_MEMORY_OVERFLOW    0x30U

#if (defined XCP_APPL_ERR_GENERIC)
#error XCP_APPL_ERR_GENERIC already defined
#endif
/** \brief return value of XCP application callout with XCP ERR_GENERIC error code. */
#define XCP_APPL_ERR_GENERIC            0x31U

/** \brief Macro for address translation
 **
 ** Translates the given XCP address and address extension into the physical
 ** address to access.
 **
 ** \param[in] AddressExtension 8 bit XCP address extension
 ** \param[in] AddressPtr Pointer to the XCP address
 **
 ** \return Pointer to the physical address to access
 */
#if (defined XCP_APPL_GET_ADDRESS)
#error XCP_APPL_GET_ADDRESS already defined
#endif


#define XCP_APPL_GET_ADDRESS( AddressExtension, AddressPtr ) \
  (AddressPtr)

/*==================[type definitions]=======================================*/

/** \brief XCP application callout return type
 **
 ** This type provides the different return values to be used by the application
 ** callouts.
 */
typedef uint8 Xcp_ApplReturnType;


/*==================[external function declarations]=========================*/

#define XCP_START_SEC_APPL_CODE
#include <MemMap.h>






/** \brief Compare Key from the Master.
 **
 ** This function will be called by the XCP Slave when the key from master
 ** needs to be compared.
 ** Implementation of this function shall be provided by the user.
 ** The file Xcp_Callouts.c from the templates folder can be used as a reference.
 ** The function shall implement the algorithm being used by the master to generate the Key.
 **
 ** \param[in]  ResourceIdentifier  A Resource to be unlocked.
 ** \param[in]  KeyBufferPtr        Pointer to the key to be verified.
 ** \param[in]  KeyLength           Length of the key RAM.
 **
 ** \return Function result
 ** \retval E_OK Function successful
 ** \retval E_NOT_OK Function not successful
 **
 ** \Reentrancy{Reentrant for different ResourceIdentifier. Non-reentrant for the same ResourceIdentifier}
 ** \Synchronicity{Synchronous} */
extern FUNC(Std_ReturnType, XCP_APPL_CODE) Xcp_ApplCompareKey
(
  uint8 ResourceIdentifier,
  P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) KeyBufferPtr,
  uint8 KeyLength
);

/** \brief Generate Seed for a resource.
 **
 ** This function is called by the XCP slave to generate seed for a requested resource.
 ** Implementation of this function shall be provided by the user.
 ** The file Xcp_Callouts.c from the templates folder can be used as a reference.
 ** The function shall implement the algorithm being used by the master to generate the Seed.
 ** When requesting for a resource the user shall make sure that the resource is supported 
 ** and allowed.
 ** Any attempt to unlock a not supporter resource shall return E_NOT_OK.
 **
 ** \param[in]     ResourceIdentifier    A Resource to be unlocked.
 ** \param[in,out]  SeedBufferPtr        Pointer to the RAM area where the seed needs to be stored.
 ** \param[in,out]  SeedBufferLengthPtr  Pointer to the RAM area where the seed length needs to be stored.
 **
 ** \return Function result
 ** \retval E_OK Function successful
 ** \retval E_NOT_OK Function not successful
 **
 ** \Reentrancy{Reentrant for different ResourceIdentifier. Non-reentrant for the same ResourceIdentifier}
 ** \Synchronicity{Synchronous} */
extern FUNC(Std_ReturnType, XCP_APPL_CODE) Xcp_ApplGetSeed
(
  uint8 ResourceIdentifier,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) SeedBufferPtr,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) SeedBufferLengthPtr
);



#define XCP_STOP_SEC_APPL_CODE
#include <MemMap.h>

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* if !defined( XCP_USERCALLOUTS_H ) */
/*==================[end of file]============================================*/

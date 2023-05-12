/**
 * \file
 *
 * \brief AUTOSAR Det
 *
 * This file contains the implementation of the AUTOSAR
 * module Det.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if !defined(DET_H)
#define DET_H

/*  MISRA-C:2004 Deviation List
 *
 *  MISRA-1) Deviated Rule: 19.13 (advisory)
 *    The # and ## preprocessor operators shoud not be used
 *
 *    Reason: On windows console systems the defensive programming
 *    macros are used to print e.g. failed conditions.
 */

 /* MISRA-C:2012 Deviation List
  *
  *  MISRAC2012-1) Deviated Rule: 20.10 (required)
  *     "The # and ## preprocessor operators should not be used."
  *
  *     Reason:
  *     On WIN32X86 platform we use some macros to display infos
  *     related to the defensive programming on failing conditions.
  */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */
#include <TSAutosar.h>                        /* EB specific standard types */

#include <Det_BSW.h>                                      /* Det common API */
#include <Det_Version.h>               /* this module's version declaration */

/*==================[macros]================================================*/

/*------------------[API service IDs]---------------------------------------*/

#if (defined DET_SID_INIT)
#error DET_SID_INIT already defined
#endif
/** \brief AUTOSAR API service ID.
 **
 ** Definition of service ID for Det_Init(). */
#define DET_SID_INIT                               0U

#if (defined DET_SID_REPORT_ERROR)
#error DET_SID_REPORT_ERROR already defined
#endif
/** \brief AUTOSAR API service ID.
 **
 ** Definition of service ID for Det_ReportError(). */
#define DET_SID_REPORT_ERROR                       1U

#if (defined DET_SID_START)
#error DET_SID_START already defined
#endif
/** \brief AUTOSAR API service ID.
 **
 ** Definition of service ID for Det_Strat(). */
#define DET_SID_START                              2U

#if (defined DET_SID_GET_VERSION_INFO)
#error DET_SID_GET_VERSION_INFO already defined
#endif
/** \brief AUTOSAR API service ID.
 **
 ** Definition of service ID for Det_GetVersionInfo(). */
#define DET_SID_GET_VERSION_INFO                   3U

/*------------------[DET error codes]---------------------------------------*/

#if (defined DET_E_PARAM_POINTER)
#error DET_E_PARAM_POINTER already defined
#endif
/** \brief Development error code used if Det_GetVersionInfo() is called with
 * null parameter pointer */
#define DET_E_PARAM_POINTER                        1U

/*------------------[preconditions]-----------------------------------------*/
#if (defined DET_PRECONDITION_ASSERT)
#error DET_PRECONDITION_ASSERT is already defined
#endif

#if (defined DET_PRECONDITION_ASSERT_NO_EVAL)
#error DET_PRECONDITION_ASSERT_NO_EVAL is already defined
#endif

#if (DET_PRECONDITION_ASSERT_ENABLED == STD_ON)

#if (defined DET_E_PRECONDITION_ASSERT_FAILED)
#error DET_E_PRECONDITION_ASSERT_FAILED is already defined
#endif
/** \brief Reserved error value for precondition assertions */
#define DET_E_PRECONDITION_ASSERT_FAILED 230U

#if (defined DET_PRECONDITION_ASSERT_PRINT)
#error DET_PRECONDITION_ASSERT_PRINT is already defined
#endif

#if (TS_ARCH_FAMILY == TS_WINDOWS)


/** \brief Internal helper macro that in fact is a wrapper of ::Det_PreconditionAssertPrint
 ** that have as few arguments initialized with compiler macros to identify place of call
 */
/* Deviation MISRAC2012-1 <+5> */
/* Deviation MISRA-1 <+4> */
#define DET_PRECONDITION_ASSERT_PRINT(Condition, ModuleId, InstanceId, ApiId) \
  Det_PreconditionAssertPrint(                                          \
    (ModuleId), (InstanceId), (ApiId),                                  \
    __FILE__, __LINE__, __FUNCTION__, #Condition)

#else /* TS_ARCH_FAMILY != TS_WINDOWS */

/** \brief Internal helper macro */
#define DET_PRECONDITION_ASSERT_PRINT(Condition, ModuleId, InstanceId, ApiId)

#endif

/** \brief Report a precondition assertion
 **
 ** Use this macro in BSW modules to check a defensive programming
 ** precondition assertion with an evaluation of the condition.
 **
 ** \param[in] Condition The condition check
 ** \param[in] ModuleId The id of the reporting module
 ** \param[in] InstanceId The instance Id of the reporting module
 ** \param[in] ApiId The Api function where the check failed */

#define DET_PRECONDITION_ASSERT(Condition, ModuleId, InstanceId, ApiId) \
  do                                                                    \
  {                                                                     \
    if (!(Condition))                                                   \
    {                                                                   \
      DET_PRECONDITION_ASSERT_NO_EVAL(                                  \
        (Condition), (ModuleId), (InstanceId), (ApiId));                \
    }                                                                   \
  }                                                                     \
  while (0)

/** \brief Report a precondition assertion without condition evaluation
 **
 ** Use this macro in BSW modules to check a defensive programming
 ** precondition assertion without evaluating the condition.
 **
 ** \param[in] Condition The condition check, which will not be evaluated
 ** \param[in] ModuleId The id of the reporting module
 ** \param[in] InstanceId The instance Id of the reporting module
 ** \param[in] ApiId The Api function where the check failed */
#define DET_PRECONDITION_ASSERT_NO_EVAL(Condition, ModuleId, InstanceId, ApiId) \
  do                                                                            \
  {                                                                             \
    DET_PRECONDITION_ASSERT_PRINT(                                              \
      (Condition), (ModuleId), (InstanceId), (ApiId));                          \
    (void)Det_ReportError(                                                      \
      (ModuleId), (InstanceId), (ApiId),                                        \
      DET_E_PRECONDITION_ASSERT_FAILED);                                        \
  }                                                                             \
  while (0)

#else /* DET_PRECONDITION_ASSERT_ENABLED == STD_OFF */

/** \brief Internal helper macro */
#define DET_PRECONDITION_ASSERT(Condition, ModuleId, InstanceId, ApiId)

/** \brief Internal helper macro */
#define DET_PRECONDITION_ASSERT_NO_EVAL(Condition, ModuleId, InstanceId, ApiId)
#endif

/*------------------[postconditions]----------------------------------------*/
#if (defined DET_POSTCONDITION_ASSERT)
#error DET_POSTCONDITION_ASSERT is already defined
#endif

#if (DET_POSTCONDITION_ASSERT_ENABLED == STD_ON)

#if (defined DET_E_POSTCONDITION_ASSERT_FAILED)
#error DET_E_POSTCONDITION_ASSERT_FAILED is already defined
#endif
/** \brief Reserved error value for postcondition assertions */
#define DET_E_POSTCONDITION_ASSERT_FAILED 231U

#if (defined DET_POSTCONDITION_ASSERT_PRINT)
#error DET_POSTCONDITION_ASSERT_PRINT is already defined
#endif

#if (TS_ARCH_FAMILY == TS_WINDOWS)

/** \brief Internal helper macro that in fact is a wrapper of ::Det_PostconditionAssertPrint
 ** that have as few arguments initialized with compiler macros to identify place of call
 */
/* Deviation MISRAC2012-1 <+5> */
/* Deviation MISRA-1 <+4> */
#define DET_POSTCONDITION_ASSERT_PRINT(Condition, ModuleId, InstanceId, ApiId) \
  Det_PostconditionAssertPrint(                                         \
    (ModuleId), (InstanceId), (ApiId),                                  \
    __FILE__, __LINE__, __FUNCTION__, #Condition)

#else /* TS_ARCH_FAMILY != TS_WINDOWS */
/** \brief Internal helper macro */
#define DET_POSTCONDITION_ASSERT_PRINT(Condition, ModuleId, InstanceId, ApiId)
#endif

/** \brief Report a postcondition assertion
 **
 ** Use this macro in BSW modules to check a defensive programming
 ** postcondition assertion.
 **
 ** \param[in] Condition The condition check
 ** \param[in] ModuleId The id of the reporting module
 ** \param[in] InstanceId The instance Id of the reporting module
 ** \param[in] ApiId The Api function where the check failed */

#define DET_POSTCONDITION_ASSERT(Condition, ModuleId, InstanceId, ApiId) \
  do                                                                    \
  {                                                                     \
    if (!(Condition))                                                   \
    {                                                                   \
      DET_POSTCONDITION_ASSERT_PRINT(                                   \
        (Condition), (ModuleId), (InstanceId), (ApiId));                \
      (void)Det_ReportError(                                            \
        (ModuleId), (InstanceId), (ApiId),                              \
        DET_E_POSTCONDITION_ASSERT_FAILED);                             \
    }                                                                   \
  }                                                                     \
  while (0)

#else /* DET_POSTCONDITION_ASSERT_ENABLED == STD_OFF */

/** \brief Internal helper macro */
#define DET_POSTCONDITION_ASSERT(Condition, ModuleId, InstanceId, ApiId)

#endif

/*------------------[unreachable code assertions]---------------------------*/
#if (defined DET_UNREACHABLE_CODE_ASSERT)
#error DET_UNREACHABLE_CODE_ASSERT is already defined
#endif

#if (DET_UNREACHABLE_CODE_ASSERT_ENABLED == STD_ON)

#if (defined DET_E_UNREACHABLE_CODE_ASSERT_FAILED)
#error DET_E_UNREACHABLE_CODE_ASSERT_FAILED is already defined
#endif
/** \brief Reserved error value for unreachable code assertions */
#define DET_E_UNREACHABLE_CODE_ASSERT_FAILED 232U

#if (defined DET_UNREACHABLE_CODE_ASSERT_PRINT)
#error DET_UNREACHABLE_CODE_ASSERT_PRINT is already defined
#endif

#if (TS_ARCH_FAMILY == TS_WINDOWS)

/** \brief Internal helper macro that in fact is a wrapper of ::Det_UnreachableCodeAssertPrint
 ** that have as few arguments initialized with compiler macros to identify place of call
 */

#define DET_UNREACHABLE_CODE_ASSERT_PRINT(ModuleId, InstanceId, ApiId)  \
  Det_UnreachableCodeAssertPrint(                                       \
    (ModuleId), (InstanceId), (ApiId),                                  \
    __FILE__, __LINE__, __FUNCTION__)

#else /* TS_ARCH_FAMILY != TS_WINDOWS */
/** \brief Internal helper macro */
#define DET_UNREACHABLE_CODE_ASSERT_PRINT(ModuleId, InstanceId, ApiId)
#endif

/** \brief Report a unreachable code assertion
 **
 ** Use this macro in BSW modules to mark unreachable code as part of
 ** defensive programming.
 **
 ** \param[in] ModuleId The id of the reporting module
 ** \param[in] InstanceId The instance Id of the reporting module
 ** \param[in] ApiId The Api function where the check failed */

#define DET_UNREACHABLE_CODE_ASSERT(ModuleId, InstanceId, ApiId)        \
  do                                                                    \
  {                                                                     \
    DET_UNREACHABLE_CODE_ASSERT_PRINT(                                  \
      (ModuleId), (InstanceId), (ApiId));                               \
    (void)Det_ReportError(                                              \
      (ModuleId), (InstanceId), (ApiId),                                \
      DET_E_UNREACHABLE_CODE_ASSERT_FAILED);                            \
  }                                                                     \
  while (0)

#else /* DET_UNREACHABLE_CODE_ASSERT_ENABLED == STD_OFF */

/** \brief Internal helper macro */
#define DET_UNREACHABLE_CODE_ASSERT(ModuleId, InstanceId, ApiId)

#endif

/*------------------[invariant assertions]----------------------------------*/
#if (defined DET_INVARIANT_ASSERT)
#error DET_INVARIANT_ASSERT is already defined
#endif

#if (DET_INVARIANT_ASSERT_ENABLED == STD_ON)

#if (defined DET_E_INVARIANT_ASSERT_FAILED)
#error DET_E_INVARIANT_ASSERT_FAILED is already defined
#endif
/** \brief Reserved error value for invariant assertions */
#define DET_E_INVARIANT_ASSERT_FAILED 233U

#if (TS_ARCH_FAMILY == TS_WINDOWS)

/** \brief Internal helper macro that in fact is a wrapper of ::Det_InvariantAssertPrint
 ** that have as few arguments initialized with compiler macros to identify place of call
 */
/* Deviation MISRAC2012-1 <+5> */
 /* Deviation MISRA-1 <+4> */
#define DET_INVARIANT_ASSERT_PRINT(Condition, ModuleId, InstanceId, ApiId) \
  Det_InvariantAssertPrint(                                             \
    (ModuleId), (InstanceId), (ApiId),                                  \
    __FILE__, __LINE__, __FUNCTION__, #Condition)

#else /* TS_ARCH_FAMILY != TS_WINDOWS */
/** \brief Internal helper macro */
#define DET_INVARIANT_ASSERT_PRINT(Condition, ModuleId, InstanceId, ApiId)
#endif

/** \brief Report a invariant assertion
 **
 ** Use this macro in BSW modules to check a defensive programming invariant
 ** assertion.
 **
 ** \param[in] Condition The condition check
 ** \param[in] ModuleId The id of the reporting module
 ** \param[in] InstanceId The instance Id of the reporting module
 ** \param[in] ApiId The Api function where the check failed */

#define DET_INVARIANT_ASSERT(Condition, ModuleId, InstanceId, ApiId)    \
  do                                                                    \
  {                                                                     \
    if (!(Condition))                                                   \
    {                                                                   \
      DET_INVARIANT_ASSERT_PRINT(                                       \
        (Condition), (ModuleId), (InstanceId), (ApiId));                \
      (void)Det_ReportError(                                            \
        (ModuleId), (InstanceId), (ApiId),                              \
        DET_E_INVARIANT_ASSERT_FAILED);                                 \
    }                                                                   \
  }                                                                     \
  while (0)

#else /* DET_INVARIANT_ASSERT_ENABLED == STD_OFF */

/** \brief Internal helper macro */
#define DET_INVARIANT_ASSERT(Condition, ModuleId, InstanceId, ApiId)

#endif

/*------------------[static assertions]-------------------------------------*/
#if (defined DET_STATIC_ASSERT)
#error DET_STATIC_ASSERT is already defined
#endif

#if (DET_STATIC_ASSERT_ENABLED == STD_ON)

#if (defined DET_STATIC_ASSERT_JOIN)
#error DET_STATIC_ASSERT_JOIN is already defined
#endif
#if (defined DET_STATIC_ASSERT_JOIN_HLP)
#error DET_STATIC_ASSERT_JOIN_HLP is already defined
#endif
/** \brief Internal helper macro */
#define DET_STATIC_ASSERT_JOIN(X,Y) DET_STATIC_ASSERT_JOIN_HLP(X,Y)
/** \brief Internal helper macro */
/* Deviation MISRAC2012-1 */
/* Deviation MISRA-1 */
#define DET_STATIC_ASSERT_JOIN_HLP(X,Y) X##Y

/** \brief Report a static assertion
 **
 ** Use this macro in BSW modules to check a static compile time assertion as
 ** part of defensive programming.  With this macro you can check
 ** - size of types and size of global variables
 ** - alignment of global variables
 ** - padding in structures
 **
 ** The macro cannot be used for non-static check involving quantities which
 ** cannot be computed by the compiler at compile time.
 **
 ** This macro must only be used from global file scope, especially at places
 ** where global declarations can be done.  Do not use it inside of a function
 ** scope.  Do not use a trailing semicolon after DET_STATIC_ASSERT().  In the
 ** case of a disabled DET_STATIC_ASSERT() macro a trailing semicolon would
 ** lead to a single semicolon outside of a function body which is not allowed
 ** in C syntax.
 **
 ** Examples:
 **
 ** Ensure the correct size of a data type:
 ** - typedef uint8 Mod_IdHandleType;
 ** - DET_STATIC_ASSERT(sizeof(Mod_IdHandleType) == 1U)
 **
 ** Ensure correct alignment of the data type (32-bit in this case):
 ** - Mod_IdHandleType Mod_GlobalIdHandle;
 ** - DET_STATIC_ASSERT((&Mod_GlobalIdHandle & 3U) == 0U)
 **
 ** Technical background: If the \a expr is evaluated to be false the macro
 ** defines an array type with negative array size.  This is an invalid
 ** construct in ANSI C and leads to a compiler error.  The type name is
 ** typically included in the compiler's error message.  It includes the
 ** string "StaticAssertFailed" and also the line number on which the macro
 ** DET_STATIC_ASSERT() is placed.  From that the user can infer which static
 ** assert failed.
 **
 ** \param[in] expr The assertion expression */
#define DET_STATIC_ASSERT(expr)                                         \
  typedef uint8 DET_STATIC_ASSERT_JOIN(DetStaticAssertFailedInLine,__LINE__)[ \
    (expr) ? 1 : -1];
#else /* DET_STATIC_ASSERT_ENABLED == STD_OFF */
#define DET_STATIC_ASSERT(expr)
#endif

/*------------------[internal API id definition]----------------------------*/

#if (defined DET_INTERNAL_API_ID)
#error DET_INTERNAL_API_ID is already defined
#endif

/** \brief Service id for internal functions */
#define DET_INTERNAL_API_ID 0xFFU

/*==================[type definitions]======================================*/

/** \brief Internal helper macro
 **
 ** Wrapping macro to provide AUTOSAR 4.0 API as default to other BSW modules
 */
#define Det_ReportError Det_ASR40_ReportError

/*==================[external function declarations]========================*/

#define DET_START_SEC_CODE
#include <MemMap.h>

#if (DET_VERSION_INFO_API == STD_ON)
/** \brief Get version information of the Development Error Tracer.
 **
 ** This service returns the version information of this module. The version
 ** information includes:
 **  - Vendor Id
 **  - Module Id
 **  - Instance Id
 **  - Vendor specific version numbers
 **
 **  Precondition: Function is only available if parameter DetVersionInfoApi
 **  is set to true.
 **
 ** \param[out] VersionInfoPtr Pointer to where to store the version
 ** information of this module.
 **
 ** \ServiceID{::DET_SID_GET_VERSION_INFO}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC(void, DET_CODE) Det_GetVersionInfo(
  CONSTP2VAR(Std_VersionInfoType, AUTOMATIC, DET_APPL_DATA) VersionInfoPtr);
#endif

/** \brief Initialize the Development Error Tracer.
 **
 ** This function initializes the Development Error Tracer. The initialization
 ** function resets all error counters and error logging data.
 **
 ** If an initialization, or error information (e.g. after reset) is not
 ** desired, this function shall not be called. Det_Start() must be called
 ** after Det_Init() if external logging via PduR is enabled.
 **
 ** \ServiceID{::DET_SID_INIT}
 ** \Reentrancy{Non-Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC(void, DET_CODE) Det_Init(void);

/** \brief Start the Development Error Tracer.
 **
 ** This function starts the Development Error Tracer after
 ** Det_Init() has been called.
 **
 ** If external logging via PduR is enabled, this function must
 ** be called after the PduR_Init() function. This function must
 ** be called to enable Det to send error reports via PduR.
 **
 ** \ServiceID{::DET_SID_START}
 ** \Reentrancy{Non-Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC(void, DET_CODE) Det_Start(void);

/*------------------[defensive programming]---------------------------------*/

#if (TS_ARCH_FAMILY == TS_WINDOWS)

#if (DET_PRECONDITION_ASSERT_ENABLED == STD_ON)
/** \brief Print failed precondition assertion
 **
 ** Internal helper function to print a failed precondition.
 **
 ** \param[in] ModuleId     The ID of the reporting module
 ** \param[in] InstanceId   The instance ID of the reporting module
 ** \param[in] ApiId        The API function where the check failed
 ** \param[in] File         The file where the check failed
 ** \param[in] Line         The line of file where the check failed
 ** \param[in] Function     The function inside of the check failed
 ** \param[in] Condition    The condition check that enable print
 */
extern FUNC(void, DET_CODE) Det_PreconditionAssertPrint(
  uint8 ModuleId,
  uint8 InstanceId,
  uint8 ApiId,
  const char *File,
  uint32 Line,
  const char *Function,
  const char *Condition);
#endif /* if (DET_PRECONDITION_ASSERT_ENABLED == STD_ON) */

#if (DET_POSTCONDITION_ASSERT_ENABLED == STD_ON)
/** \brief Print failed postcondition assertion
 **
 ** Internal helper function to print a failed Postcondition.
 **
 ** \param[in] ModuleId     The ID of the reporting module
 ** \param[in] InstanceId   The instance ID of the reporting module
 ** \param[in] ApiId        The API function where the check failed
 ** \param[in] File         The file where the check failed
 ** \param[in] Line         The line of file where the check failed
 ** \param[in] Function     The function inside of the check failed
 ** \param[in] Condition    The condition check that enable print
 */
extern FUNC(void, DET_CODE) Det_PostconditionAssertPrint(
  uint8 ModuleId,
  uint8 InstanceId,
  uint8 ApiId,
  const char *File,
  uint32 Line,
  const char *Function,
  const char *Condition);
#endif /* if (DET_POSTCONDITION_ASSERT_ENABLED == STD_ON) */

#if (DET_UNREACHABLE_CODE_ASSERT_ENABLED == STD_ON)
/** \brief Print unreachable code assertion
 **
 ** Internal helper function to print if execution reaches unreachable
 ** code.
 **
 ** \param[in] ModuleId     The ID of the reporting module
 ** \param[in] InstanceId   The instance ID of the reporting module
 ** \param[in] ApiId        The API function where the check failed
 ** \param[in] File         The file where the check failed
 ** \param[in] Line         The line of file where the check failed
 ** \param[in] Function     The function inside of the check failed
 */
extern FUNC(void, DET_CODE) Det_UnreachableCodeAssertPrint(
  uint8 ModuleId,
  uint8 InstanceId,
  uint8 ApiId,
  const char *File,
  uint32 Line,
  const char *Function);
#endif /* if (DET_UNREACHABLE_CODE_ASSERT_ENABLED == STD_ON) */

#if (DET_INVARIANT_ASSERT_ENABLED == STD_ON)
/** \brief Print failed invariant assertion
 **
 ** Internal helper function to print a failed invariant assertion.
 **
 ** \param[in] ModuleId     The ID of the reporting module
 ** \param[in] InstanceId   The instance ID of the reporting module
 ** \param[in] ApiId        The API function where the check failed
 ** \param[in] File         The file where the check failed
 ** \param[in] Line         The line of file where the check failed
 ** \param[in] Function     The function inside of the check failed
 ** \param[in] Condition    The condition check that enable print
 */
extern FUNC(void, DET_CODE) Det_InvariantAssertPrint(
  uint8 ModuleId,
  uint8 InstanceId,
  uint8 ApiId,
  const char *File,
  uint32 Line,
  const char *Function,
  const char *Condition);
#endif /* if (DET_INVARIANT_ASSERT_ENABLED == STD_ON) */

#endif  /* TS_ARCH_FAMILY == TS_WINDOWS */

#define DET_STOP_SEC_CODE
#include <MemMap.h>

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/* Variables are only defined if the internal logging mode is used. */
#if (DET_LOGMODE == DET_LOGMODE_INTERNAL)

/* These are declarations of internal variables of the Det.  It may be
 * included and used by special debugging software to read out the internal
 * buffer content.  They shall _not_ be used by any other BSW software module
 * which only reports Det errors. */

#define DET_START_SEC_VAR_NO_INIT_16
#include <MemMap.h>

/** \brief Index for writing errors into buffer
 **
 ** Det_ErrorBuffer[Det_WriteIndex] is the next field to be overwritten.
 ** Variable definition is only available for internal or external logging
 ** mode.
 **
 ** Variable shall only be used for debugging. */
extern VAR(uint16, DET_VAR_NOINIT) Det_WriteIndex;

/** \brief Counter for lost errors because of buffer overflow
 **
 ** Variable definition is only available for internal or external logging
 ** mode.
 **
 ** Variable shall only be used for debugging. */
extern VAR(uint16, DET_VAR_NOINIT) Det_ErrorLost;

/** \brief Slot count of used Det_ErrorBuffer entries
 **
 ** Variable definition is only available for internal or external logging
 ** mode.
 **
 ** Variable shall only be used for debugging. */
extern VAR(uint16, DET_VAR_NOINIT) Det_UsedSlots;

#define DET_STOP_SEC_VAR_NO_INIT_16
#include <MemMap.h>

#endif  /* (DET_LOGMODE == DET_LOGMODE_INTERNAL) */

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
#endif /* if !defined(DET_H) */

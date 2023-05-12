#if (!defined PLATFORM_TYPES_H)
#define PLATFORM_TYPES_H
[!AUTOSPACING!][!//
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

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 20.10 (advisory)
 *   The # and ## preprocessor operators should not be used.
 *
 *   Reason:
 *   The operators are used to add the 'U' or 'UL' suffix to constants
 *   via macros which can only be performed using the '##' operator.
 */
/* !LINKSTO PLATFORM001,1, PLATFORM002,1, PLATFORM003,1 */
[!IF "ecu:has('Custom.Platform.Include') and ecu:get('Custom.Platform.Include') != '' "!]

/*==================[inclusions]=============================================*/

#include <[!"ecu:get('Custom.Platform.Include')"!]>
[!ENDIF!]

/*==================[macros]=================================================*/

/*------------------[AUTOSAR vendor identification]-------------------------*/

#if (defined PLATFORM_VENDOR_ID)
#error PLATFORM_VENDOR_ID is already defined
#endif
/** \brief AUTOSAR vendor identification: EB Automotive */
#define PLATFORM_VENDOR_ID         1U

/*------------------[AUTOSAR module identification]-------------------------*/

#if (defined PLATFORM_MODULE_ID)
#error PLATFORM_MODULE_ID already defined
#endif
/** \brief AUTOSAR module identification */
#define PLATFORM_MODULE_ID     199U

/*------------------[AUTOSAR release version identification]----------------*/

#if (defined PLATFORM_AR_RELEASE_MAJOR_VERSION)
#error PLATFORM_AR_RELEASE_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR release major version */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION     4U

#if (defined PLATFORM_AR_RELEASE_MINOR_VERSION)
#error PLATFORM_AR_RELEASE_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR release minor version */
#define PLATFORM_AR_RELEASE_MINOR_VERSION     0U

#if (defined PLATFORM_AR_RELEASE_REVISION_VERSION)
#error PLATFORM_AR_RELEASE_REVISION_VERSION already defined
#endif
/** \brief AUTOSAR release revision version */
#define PLATFORM_AR_RELEASE_REVISION_VERSION  3U

/*------------------[AUTOSAR module version identification]------------------*/

#if (defined PLATFORM_SW_MAJOR_VERSION)
#error PLATFORM_SW_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR module major version */
#define PLATFORM_SW_MAJOR_VERSION  2U

#if (defined PLATFORM_SW_MINOR_VERSION)
#error PLATFORM_SW_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR module minor version */
#define PLATFORM_SW_MINOR_VERSION  5U

#if (defined PLATFORM_SW_PATCH_VERSION)
#error PLATFORM_SW_PATCH_VERSION already defined
#endif
/** \brief AUTOSAR module patch version */
#define PLATFORM_SW_PATCH_VERSION  0U

/*------------------[AUTOSAR module vendor API infix]------------------------*/

#if (defined PLATFORM_VENDOR_API_INFIX)
#error PLATFORM_VENDOR_API_INFIX already defined
#endif
/** \brief Vendor API infix
 *
 * Left empty as this header does not belong to any module */
#define PLATFORM_VENDOR_API_INFIX

/*------------------[global identifiers]-------------------------------------*/

/* !LINKSTO PLATFORM054,1 */
#if (!defined TRUE)
/** \brief true value for boolean type */
/* !LINKSTO PLATFORM056,1 */
#define TRUE 1U
#endif

/* !LINKSTO PLATFORM054,1 */
#if (!defined FALSE)
/** \brief false value for boolean type */
/* !LINKSTO PLATFORM056,1 */
#define FALSE 0U
#endif

/* redefinition check may lead to an incorrect condition that
 * TRUE and FALSE are equal */
/* !LINKSTO PLATFORM054,1 */
#if (TRUE == FALSE)
#error TRUE == FALSE is incorrect
#endif

/*------------------[CPU properties]-----------------------------------------*/

#if (defined CPU_TYPE_8)
#error CPU_TYPE_8 already defined
#endif
/** \brief cpu identifier for 8-bit CPUs */
/* !LINKSTO PLATFORM057,1 */
#define CPU_TYPE_8 8U

#if (defined CPU_TYPE_16)
#error CPU_TYPE_16 already defined
#endif /* if (defined CPU_TYPE_16) */
/** \brief cpu identifier for 8-bit CPUs */
/* !LINKSTO PLATFORM057,1 */
#define CPU_TYPE_16 16U

#if (defined CPU_TYPE_32)
#error CPU_TYPE_32 already defined
#endif
/** \brief cpu identifier for 32-bit CPUs */
/* !LINKSTO PLATFORM057,1 */
#define CPU_TYPE_32 32U

/* !LINKSTO Base.CPU.64bit,1 */
#if (defined CPU_TYPE_64)
#error CPU_TYPE_64 already defined
#endif
/** \brief cpu identifier for 64-bit CPUs */
#define CPU_TYPE_64 64U

#if (defined MSB_FIRST)
#error MSB_FIRST already defined
#endif
/** \brief identifier for 'high byte first' */
#define MSB_FIRST 0U

#if (defined LSB_FIRST)
#error LSB_FIRST already defined
#endif /* if (defined LSB_FIRST) */
/** \brief identifier for 'little endian' */
#define LSB_FIRST 1U

#if (defined HIGH_BYTE_FIRST)
#error HIGH_BYTE_FIRST already defined
#endif
/** \brief identifier for 'high byte first' */
#define HIGH_BYTE_FIRST 0U

#if (defined LOW_BYTE_FIRST)
#error LOW_BYTE_FIRST already defined
#endif
/** \brief cpu identifier for  8-bit CPUs */
#define LOW_BYTE_FIRST 1U

#if (defined CPU_TYPE)
#error CPU_TYPE already defined
#endif

[!IF "ecu:has('Cpu.Type')"!]
  [!VAR "CpuTypeProperty" = "ecu:get('Cpu.Type')"!]
  [!IF "$CpuTypeProperty = '8' or $CpuTypeProperty = '16' or  $CpuTypeProperty = '32' or  $CpuTypeProperty = '64'"!]
    [!VAR "CpuType"="concat('CPU_TYPE_',$CpuTypeProperty)"!]
  [!ELSE!][!//
    [!ERROR!]
      Base: Invalid value for property 'Cpu.Type': '[!"$CpuTypeProperty"!]' (must be 8, 16, 32 or 64)
    [!ENDERROR!]
  [!ENDIF!]
[!ELSE!][!//
  [!ERROR!]
      Base: Property 'Cpu.Type' specifying the Cpu type not found
  [!ENDERROR!]
[!ENDIF!]
/** \brief Word size of this CPU (generated)
 *
 * Platforms Setting: 
 * The word size specifies the natural data unit size of a CPU. 
 * It is set in the Platforms plugin by
 * setting the parameter 'Cpu.Type'.
 *
 * Possible values:
 *  - CPU_TYPE_64 (if parameter 'Cpu.Type:64')
 *  - CPU_TYPE_32 (if parameter 'Cpu.Type:32')
 *  - CPU_TYPE_16 (if parameter 'Cpu.Type:16')
 *  - CPU_TYPE_8  (if parameter 'Cpu.Type:8')
 */
/* !LINKSTO PLATFORM044,1, PLATFORM045,1 */
#define CPU_TYPE [!WS!][!"concat('CPU_TYPE_',ecu:get('Cpu.Type'))"!]

/* !LINKSTO PLATFORM043,1, PLATFORM048,1, PLATFORM049,1, PLATFORM038,1 */
#if (defined CPU_BIT_ORDER)
#error CPU_BIT_ORDER already defined
#endif

[!IF "ecu:has('Cpu.Bitorder')"!]
  [!VAR "CpuBitorderProperty" = "ecu:get('Cpu.Bitorder')"!]
  [!IF "$CpuBitorderProperty = 'LE'"!]
    [!VAR "CpuBitorder" = "'LSB_FIRST'"!]
  [!ELSEIF "$CpuBitorderProperty = 'BE'"!][!//
    [!VAR "CpuBitorder" = "'MSB_FIRST'"!]
  [!ELSE!][!//
    [!ERROR!]
      Base: Invalid value for property 'Cpu.Bitorder': '[!"$CpuBitorderProperty"!]' (must be 'LE' or 'BE')
    [!ENDERROR!]
  [!ENDIF!]
[!ELSE!][!//
  [!ERROR!]
      Base: No property 'Cpu.Bitorder' specifying the bit order of bits for the CPU not found
  [!ENDERROR!]
[!ENDIF!]
/** \brief Bit order of this CPU (generated)
 *
 * Platforms Setting:
 * The bit order of the CPU is set in the Platforms plugin by 
 * setting the parameter 'Cpu.Bitorder'. 
 *
 * Range:
 *  - LE (LSB_FIRST if parameter 'Cpu.Bitorder:LE')
 *  - BE (MSB_FIRST if parameter 'Cpu.Bitorder:BE')
 */
#define CPU_BIT_ORDER [!WS!][!"$CpuBitorder"!]

/* !LINKSTO PLATFORM039,1, PLATFORM046,1, PLATFORM050,1, PLATFORM051,1 */
#if (defined CPU_BYTE_ORDER)
#error CPU_BYTE_ORDER already defined
#endif

[!IF "ecu:has('Cpu.Byteorder')"!]
  [!VAR "CpuByteorderProperty" = "ecu:get('Cpu.Byteorder')"!]
  [!IF "$CpuByteorderProperty = 'LE'"!]
    [!VAR "CpuByteorder" = "'LOW_BYTE_FIRST'"!]
  [!ELSEIF "$CpuByteorderProperty = 'BE'"!][!//
    [!VAR "CpuByteorder" = "'HIGH_BYTE_FIRST'"!]
  [!ELSE!][!//
    [!ERROR!]
      Base: Invalid value for property 'Cpu.Byteorder': '[!"$CpuByteorderProperty"!]' (must be 'LE' or 'BE')
    [!ENDERROR!]
  [!ENDIF!]
[!ELSE!][!//
  [!ERROR!]
      Base: Property 'Cpu.Byteorder' specifying the byte order of the CPU  order not found.
  [!ENDERROR!]
[!ENDIF!]
/** \brief Byte order of this CPU (generated)
 *
 * Platforms Setting:
 * The byte order of the CPU is set in the Platforms plugin by 
 * setting the parameter 'Cpu.Byteorder'. 
 *
 * Range:
 *  - BE (HIGH_BYTE_FIRST if parameter 'Cpu.Byteorder:BE')
 *  - LE (LOW_BYTE_FIRST if parameter 'Cpu.Byteorder:LE')
 */
#define CPU_BYTE_ORDER [!WS!][!"$CpuByteorder"!]

/* !LINKSTO Base.Dbg.ConfigMacro,1 */
#if (defined BASE_DBG_ENABLE)
#error BASE_DBG_ENABLE already defined
#endif

/** \brief Macro for enabling debug header file (generated)
 *
 * Range:
 *  - STD_ON (if configuration parameter 'Base/BaseDbg/BaseDbgHeaderFile' enabled)
 *  - STD_OFF (if configuration parameter 'Base/BaseDbg/BaseDbgHeaderFile' disabled)
 */
#define BASE_DBG_ENABLE [!WS!][!IF "node:exists(as:modconf('Base')[1]/BaseDbg/BaseDbgHeaderFile)='true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]


/*==================[type definitions]======================================*/
[!INCLUDE "TypeLists.m"!]
[!IF "text:contains(text:split($BitWidthList,','), '64')"!]

#if (!defined HAS_64BIT_TYPES)
#define HAS_64BIT_TYPES
#endif
[!ENDIF!]

/* !LINKSTO PLATFORM005,1, PLATFORM013,1, PLATFORM014,1, PLATFORM015,1, PLATFORM016,1, PLATFORM017,1, PLATFORM018,1, PLATFORM020,1, PLATFORM021,1, PLATFORM022,1, PLATFORM023,1, PLATFORM024,1, PLATFORM025,1, PLATFORM027,1, PLATFORM041,1, PLATFORM042,1, PLATFORM060,1, PLATFORM066,1, PLATFORM067,1 */
[!VAR "ListLength"="count(text:split($AutosarTypeList,','))"!]
[!FOR "i"="1" TO  "num:i($ListLength)"!]
  [!VAR "AutosarType"="text:split($AutosarTypeList,',')[num:i($i)]"!]
  [!IF "node:exists(as:modconf('Base')[1]/BaseTypes/*[node:name(.)=concat('BaseType_',$AutosarType)])"!]
/** \brief Type definition of AUTOSAR standard type [!"$AutosarType"!]
 *
 * Platforms Setting: 
 * Definition of platform specific AUTOSAR standard types
 * that are set in the Platforms plugin by parameter 'Basetypes.[!"$AutosarType"!].Mapping' 
 */
typedef[!WS!][!"as:modconf('Base')[1]/BaseTypes/*[node:name(.)=concat('BaseType_',$AutosarType)]"!][!WS!][!"$AutosarType"!];

  [!ENDIF!]
[!ENDFOR!]
[!IF "ecu:get('Cpu.Type') = '64' and text:contains(text:split($BitWidthList,','), '64')"!]
[!VAR "SizeType"="'uint64'"!]
[!VAR "SizeSuffix"="'ULL'"!]
[!ELSE!][!//
[!VAR "SizeType"="'uint32'"!]
[!VAR "SizeSuffix"="'UL'"!]
[!ENDIF!]
/* !LINKSTO Base.Types.SizeType,1 */
/** \brief Type definition of platform specific size type (generated, depending on parameter 'Cpu.Type') */
typedef[!WS!][!"$SizeType"!][!WS!]usize;

#if (!defined USIZE_C)
/** \brief Macro to define a constant of platform specific type usize (generated, depending on parameter 'Cpu.Type') */
/* Deviation MISRAC2012-1 <+2> */
#define USIZE_C(x) (x ## [!"$SizeSuffix"!])
#endif

/* !LINKSTO Base.Types.VoidPtr,1 */
/** \brief type definition for pointer to void */
typedef void * VoidPtr;
/** \brief type definition for pointer to const void */
typedef const void *  ConstVoidPtr;

/*==================[inclusions]=============================================*/

/* !LINKSTO Base.ConfigScheme.PlatformTypesGeneration,1 */
/** \brief Inclusions of custom standard files (generated)
 *
 * For each configuration parameter 'Base/CustomStdIncludeFiles/[file]',
 * an include statement is generated
 *
 * Platforms Setting: 
 * Custom standard file can be used for definition of
 * additional standard types that are customer specific.
 */
[!LOOP "as:modconf('Base')[1]/CustomStdIncludeFiles/*"!]
#include <[!"."!]>
[!ENDLOOP!]

#endif /* if (!defined PLATFORM_TYPES_H) */

#if (!defined AUTOSAR_CFG_H)
#define AUTOSAR_CFG_H
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

/*==================[macros]=================================================*/

/*------------------[Macros for Atomic Assignment]---------------------------*/
[!INCLUDE "TypeLists.m"!]
[!/* MACRO GetCTypeAUTOSAR:
     Get C type for a certain AUTOSAR type

     Parameter:
      - Type: the AUTOSAR type

     OUT Variables:
      - CType:  the C type corresponding to the AUTOSAR type
*/!][!//
[!MACRO "GetCTypeAUTOSAR","Type"!][!//
  [!VAR "property"="concat('BaseType_',$Type)"!]
  [!IF "node:exists(as:modconf('Base')[1]/BaseTypes/*[node:name(.)=$property])"!]
    [!VAR "BaseType"="as:modconf('Base')[1]/BaseTypes/*[node:name(.)=$property]"!]
    [!VAR "CType"="normalize-space(text:replace($BaseType,'(un)?signed',''))"!]
  [!ELSE!]
    [!ERROR!]
      Base: No mapping to C type found for AUTOSAR type [!"$Type"!]
    [!ENDERROR!]
  [!ENDIF!]
[!ENDMACRO!]
 [!/* MACRO GetCTypeDerived:
      Get C type for a certain derived type

      Parameter:
       - Type: the derived type

      OUT Variables:
       - CType:  the C type corresponding to the derived type
 */!]
[!MACRO "GetCTypeDerived","Type"!]
  [!VAR "property"="concat('Derivedtypes.',$Type,'.Mapping')"!]
  [!IF "ecu:has($property)"!]
    [!VAR "CType"="normalize-space(text:replace(ecu:get($property),'(un)?signed',''))"!]
  [!ELSE!]
    [!ERROR!]
      Base: No mapping to C type found for derived type [!"$Type"!]
    [!ENDERROR!]
  [!ENDIF!]
[!ENDMACRO!]
[!VAR "BitWidthListLength"="count(text:split($BitWidthList,','))"!]
[!FOR "i"="1" TO "num:i($BitWidthListLength)"!]
  [!VAR "BitWidth"="text:split($BitWidthList,',')[num:i($i)]"!]
  [!VAR "Type"="concat('uint',$BitWidth)"!]
  [!CALL "GetCTypeAUTOSAR","Type"="$Type"!]
  [!VAR "property"="concat('Basetypes.',$CType,'.AtomicAccess')"!]
  [!IF "ecu:has($property) and (ecu:get($property) = 'true')"!]
#if (defined TS_AtomicAssign[!"$BitWidth"!])
#error TS_AtomicAssign[!"$BitWidth"!] already defined
#endif
/** \brief Assigns the [!"$BitWidth"!] bit entity \p from to \p to in an atomic fashion
 *
 * This macro assigns the [!"$BitWidth"!] bit entity \p from to \p to in an atomic fashion
 *
 * The parameters \p from and \p to thus have to be of type \p uint8 or \p sint8.
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].[!"$CType"!].AtomicAccess'
 *
 * \param[out] to    [!"$BitWidth"!] bit entity which is the destination of the assignment
 * \param[in]  from  [!"$BitWidth"!] bit entity which is the source of the assignment
 *
 * \remarks The parameters of this macro may be used in any way, especially
 *   they can be used more than once. They shall not contain side effects.
 */
#define TS_AtomicAssign[!"$BitWidth"!](to, from) ((to) = (from))

  [!ENDIF!]
[!ENDFOR!]
/*------------------[Macros for Litte / Big Endian]--------------------------*/

[!/* import GuardedDefine macro
*/!][!INCLUDE "CommonMacros.m"!][!/*

*/!][!CALL "GuardedDefine", "Comment"="'Selector for Big Endian / Little Endian expression variants'",
 "Name"="'TS_IF_BE_LE'", "Params"="'(BE,LE)'"!][!//
[!IF "ecu:get('Cpu.Byteorder') = 'LE'"!]LE[!ELSE!]BE[!ENDIF!]


/*------------------[Size of Autosar Standard Types]-------------------------*/
[!/* MACRO CreateSizeMacros:
     Create marcos for accessing the size for all types passed.

     Parameter:
      - List: list of types to create the macros
      - IsDerivedType: flag (true|false) if derived type or base type is processed
*/!]
[!MACRO "CreateSizeMacros","List","IsDerivedType"!]
  [!VAR "ListLength"="count(text:split($List,','))"!]
  [!FOR "i"="1" TO "num:i($ListLength)"!]
    [!VAR "Type"="text:split($List,',')[num:i($i)]"!]
    [!IF "$IsDerivedType"!]
      [!CALL "GetCTypeDerived","Type"="$Type"!]
    [!ELSE!]
      [!CALL "GetCTypeAUTOSAR","Type"="$Type"!]
    [!ENDIF!]
    [!VAR "property"="concat('Basetypes.',$CType,'.Size')"!]
    [!IF "ecu:has($property)"!]
#if (defined TS_SIZE_[!"$Type"!])
#error TS_SIZE_[!"$Type"!] already defined
#endif
/** \brief Size of derived type [!"$Type"!]
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].[!"$CType"!].Size'
 */
#define TS_SIZE_[!"$Type"!] [!WS!][!"ecu:get($property)"!]U

    [!ENDIF!]
  [!ENDFOR!]
[!ENDMACRO!]
[!CALL "CreateSizeMacros", "List"="$AutosarTypeList", "IsDerivedType"="'false'"!]
[!CALL "CreateSizeMacros", "List"="$DerivedTypeList", "IsDerivedType"="'true'"!]
/*------------------[Alignment Autosar Standard Types]-----------------------*/
[!/* MACRO CreateAlignmentMacros:
     Create marcos for accessing the alignment for all types passed.

     Parameter:
      - List: list of types to create the macros
      - IsDerivedType: flag (true|false) if derived type or base type is processed
*/!][!//
[!MACRO "CreateAlignmentMacros","List","IsDerivedType"!][!//
  [!VAR "ListLength"="count(text:split($List,','))"!]
  [!FOR "i"="1" TO  "num:i($ListLength)"!]
    [!VAR "Type"="text:split($List,',')[num:i($i)]"!]
    [!IF "$IsDerivedType"!]
      [!CALL "GetCTypeDerived","Type"="$Type"!]
    [!ELSE!]
      [!CALL "GetCTypeAUTOSAR","Type"="$Type"!]
    [!ENDIF!]
    [!VAR "property"="concat('Basetypes.',$CType,'.Alignment')"!]
    [!IF "ecu:has($property)"!]
#if (defined TS_ALIGNMENT_[!"$Type"!])
#error TS_ALIGNMENT_[!"$Type"!] already defined
#endif
/** \brief Alignment constraints for derived type [!"$Type"!]
 *
 * Platforms Setting:
 * It is derived from the parameters in the Platforms plugin by
 * '[Basetypes|Derivedtypes].[!"$CType"!].Alignment'
 */
#define TS_ALIGNMENT_[!"$Type"!] [!WS!][!"ecu:get($property)"!]U

    [!ENDIF!]
  [!ENDFOR!]
[!ENDMACRO!]
[!/* MACRO CreateComplexAlignmentMacros:
      Create marcos for accessing the alignment of complex types.

      Parameter:
       - Type: type to create alignment macros for (either 'array' or 'struct')
       - ListThresholds: list of thresholds of alignments of complex type
       - ListAlignments: list of alignments of complex type
       - DefaultAlignment: default alignment of complex type
 */!]
[!MACRO "CreateComplexAlignmentMacros","Type","ListThresholds","ListAlignments","DefaultAlignment"!]
  [!VAR "Thresholds"="text:replaceAll(substring($ListThresholds,2,string-length($ListThresholds)-2),',','')"!]
  [!VAR "Alignments"="text:replaceAll(substring($ListAlignments,2,string-length($ListAlignments)-2),',','')"!]
  [!VAR "Length"="num:i(count(text:split($Alignments)))"!]
  [!IF "$Length > 1"!]
#if (defined TS_ALIGNMENT_[!"$Type"!]_NUM_THRESHOLDS)
#error TS_ALIGNMENT_[!"$Type"!]_NUM_THRESHOLDS already defined
#endif
/** \brief Number of alignment constraints for [!"$Type"!]s
 *
 * Platforms Setting:
 * It is set in the Platforms plugin by
 * setting the parameter 'Complextypes.[!"$Type"!].Alignment'.
 */
#define TS_ALIGNMENT_[!"$Type"!]_NUM_THRESHOLDS [!WS!][!"$Length"!]U
    [!FOR "i"="1" TO "$Length"!]
      [!VAR "Threshold"="text:split($Thresholds)[num:i($i)]"!]
      [!VAR "Alignment"="text:split($Alignments)[num:i($i)]"!]
      [!VAR "Index"="num:i($i - 1)"!]
      [!IF "string-length($Threshold) > 0"!]
#if (defined TS_ALIGNMENT_[!"$Type"!]_THRESHOLD_[!"$Index"!])
#error TS_ALIGNMENT_[!"$Type"!]_THRESHOLD_[!"$Index"!][!WS!]already defined
#endif
/** \brief Threshold of [!"$i"!]. alignment constraint for [!"$Type"!]s */
#define TS_ALIGNMENT_[!"$Type"!]_THRESHOLD_[!"$Index"!][!WS!][!"$Threshold"!]U

      [!ENDIF!]
#if (defined TS_ALIGNMENT_[!"$Type"!]_[!"$Index"!])
#error TS_ALIGNMENT_[!"$Type"!]_[!"$Index"!][!WS!]already defined
#endif
/** \brief [!"$i"!]. alignment constraint for [!"$Type"!]s */
#define TS_ALIGNMENT_[!"$Type"!]_[!"$Index"!] [!WS!][!"$Alignment"!]U

    [!ENDFOR!]
  [!ENDIF!]
#if (defined TS_ALIGNMENT_[!"$Type"!])
#error TS_ALIGNMENT_[!"$Type"!] already defined
#endif
/** \brief Default alignment constraint for [!"$Type"!]s */
#define TS_ALIGNMENT_[!"$Type"!] [!WS!][!"$DefaultAlignment"!]U

[!ENDMACRO!]
[!CALL "CreateAlignmentMacros", "List"="$AutosarTypeList", "IsDerivedType"="'false'"!]
[!CALL "CreateComplexAlignmentMacros", "Type"="'array'", "ListThresholds"="asc:getArrayAlignmentThresholds()", "ListAlignments"="asc:getArrayAlignments()", "DefaultAlignment"="asc:getArrayAlignment()"!]
[!CALL "CreateComplexAlignmentMacros", "Type"="'struct'", "ListThresholds"="asc:getStructAlignmentThresholds()", "ListAlignments"="asc:getStructAlignments()", "DefaultAlignment"="asc:getStructAlignment()"!]
[!CALL "CreateAlignmentMacros", "List"="$DerivedTypeList", "IsDerivedType"="'true'"!]
/*==================[type definitions]======================================*/

[!VAR "ListLength"="count(text:split($DerivedTypeList,','))"!]
[!FOR "i"="1" TO  "num:i($ListLength)"!]
  [!VAR "DerivedType"="text:split($DerivedTypeList,',')[num:i($i)]"!]
  [!VAR "property"="concat('Derivedtypes.',$DerivedType,'.Mapping')"!]
  [!IF "ecu:has($property)"!]
/** \brief Type definition of derived type [!"$DerivedType"!]
 *
 * Platforms Setting:
 * It is set in Platforms plugin by setting the parameter 'Derivedtypes.[!"$DerivedType"!].Mapping'.
 */
typedef[!WS!][!"ecu:get($property)"!][!WS!][!"$DerivedType"!];

  [!ENDIF!]
[!ENDFOR!]
#endif /*(!defined AUTOSAR_CFG_H)*/

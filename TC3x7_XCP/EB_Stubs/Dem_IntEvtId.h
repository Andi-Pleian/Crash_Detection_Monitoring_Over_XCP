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
#if (!defined DEM_INT_EVT_ID_H)
#define DEM_INT_EVT_ID_H

/* This file contains the configuration declarations of the
 * SW-C Event ID symbols for AUTOSAR module Dem. */








/*==================[inclusions]============================================*/

/*==================[macros]================================================*/

/*------------------[Events configuration]----------------------------------*/

/* !LINKSTO Dem115,2 */
/* Symbolic names of configured SW-C event IDs */

#if (defined DemConf_DemEventParameter_DmTestAppl)
#error DemConf_DemEventParameter_DmTestAppl already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_DmTestAppl                      1U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_DmTestAppl)
#error Dem_DmTestAppl already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_DmTestAppl                      1U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_DmTestCom)
#error DemConf_DemEventParameter_DmTestCom already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_DmTestCom                       2U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_DmTestCom)
#error Dem_DmTestCom already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_DmTestCom                       2U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_VsmEventOpmode)
#error DemConf_DemEventParameter_VsmEventOpmode already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_VsmEventOpmode                  3U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_VsmEventOpmode)
#error Dem_VsmEventOpmode already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_VsmEventOpmode                  3U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* if !defined( DEM_INT_EVT_ID_H ) */
/*==================[end of file]===========================================*/

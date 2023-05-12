
/**
 * \file
 *
 * \brief AUTOSAR CanIf
 *
 * This file contains the implementation of the AUTOSAR
 * module CanIf.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 1.3 (required)
 *    The macro `offsetof' shall not be used.
 *
 *    Reason:
 *    Relocatable postbuild macro requires the usage of `offsetof'.
 *
 * MISRAC2012-2) Deviated Rule: 11.4 (advisory)
 *    A cast should not be performed between a pointer type and an integral
 *    type.
 *
 *    Reason:
 *    Relocatable postbuild macro requires the cast between pointer and
 *    integral type.
 *
 * MISRAC2012-3) Deviated Rule: 11.9 (required)
 *    The macro NULL shall be the only permitted form of integer null pointer constant.
 *
 *    Reason:
 *    Macros are used in order to check the alignment for different data types.
 *
 */

/*==================[inclusions]=============================================*/

#include <CanIf_PBcfg.h>
#include <TSAutosar.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_NAME CanIf_ConfigLayout
#define TS_PB_CFG_LAYOUT_TYPE CanIf_ConstConfigLayoutType
#include <TSPBConfig_Init.h>

/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <START> */
CanIf_ConstConfigLayoutType CanIf_ConfigLayout = {
    { /* RootCfg */
        UINT32_C( 2147485970 ), /* PlatformSignature */
        UINT32_C( 2416897657 ), /* LcfgSignature */
        UINT32_C( 1323124628 ), /* CfgSignature */
        UINT32_C( 3410186675 ), /* PublicInfoSignature */
        TS_MAKEREF2CFG( txLPduConfig[0] ), /* txLPduConfigPtr */
        TS_MAKEREF2CFG( rxLPduConfig[0] ), /* rxLPduConfigPtr */
        TS_MAKEREF2CFG( sortedRxLPduConfig[0] ), /* sortedRxLPduConfigPtr */
        TS_MAKEREF2CFG( canDriverConfig[0] ), /* driverConfigPtr */
        UINT16_C( 2 ), /* nrOfStaticTxLPdus */
        UINT16_C( 2 ), /* nrOfTxLPdus */
        UINT16_C( 6 ), /* nrOfRxLPdus */
        UINT8_C( 0 ) /* maxCanControllerId */
    },
    { /* txLPduConfig */
        { /* txLPduConfig[0] */
            UINT32_C( 1792 ), /* canId */
            UINT8_C( 6 ), /* hth */
            UINT16_C( 0 ), /* sourcePduId_UL */
            UINT8_C( 0 ) /* userType */
        },
        { /* txLPduConfig[1] */
            UINT32_C( 1816 ), /* canId */
            UINT8_C( 7 ), /* hth */
            UINT16_C( 1 ), /* sourcePduId_UL */
            UINT8_C( 0 ) /* userType */
        }
    },
    { /* rxLPduConfig */
        { /* rxLPduConfig[0] */
            UINT16_C( 2 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 8 ) /* dlc */
        },
        { /* rxLPduConfig[1] */
            UINT16_C( 5 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 8 ) /* dlc */
        },
        { /* rxLPduConfig[2] */
            UINT16_C( 0 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 8 ) /* dlc */
        },
        { /* rxLPduConfig[3] */
            UINT16_C( 3 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 8 ) /* dlc */
        },
        { /* rxLPduConfig[4] */
            UINT16_C( 1 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 8 ) /* dlc */
        },
        { /* rxLPduConfig[5] */
            UINT16_C( 4 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 8 ) /* dlc */
        }
    },
    { /* driverHthConfig */
        { /* driverHthConfig[0] */
            UINT16_C( 0 ), /* firstIndex */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHthConfig[1] */
            UINT16_C( 0 ), /* firstIndex */
            UINT8_C( 0 ) /* intCtrlIdx */
        }
    },
    { /* driverHrhConfig */
        { /* driverHrhConfig[0] */
            UINT16_C( 0 ), /* firstIndex */
            UINT16_C( 0 ), /* lastIndex */
            UINT8_C( 0 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[1] */
            UINT16_C( 1 ), /* firstIndex */
            UINT16_C( 1 ), /* lastIndex */
            UINT8_C( 0 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[2] */
            UINT16_C( 2 ), /* firstIndex */
            UINT16_C( 2 ), /* lastIndex */
            UINT8_C( 0 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[3] */
            UINT16_C( 3 ), /* firstIndex */
            UINT16_C( 3 ), /* lastIndex */
            UINT8_C( 0 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[4] */
            UINT16_C( 4 ), /* firstIndex */
            UINT16_C( 4 ), /* lastIndex */
            UINT8_C( 0 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[5] */
            UINT16_C( 5 ), /* firstIndex */
            UINT16_C( 5 ), /* lastIndex */
            UINT8_C( 0 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        }
    },
    { /* hohIdToCanIfIdx */
        UINT16_C( 0 ), /* hohIdToCanIfIdx[0] */
        UINT16_C( 1 ), /* hohIdToCanIfIdx[1] */
        UINT16_C( 2 ), /* hohIdToCanIfIdx[2] */
        UINT16_C( 3 ), /* hohIdToCanIfIdx[3] */
        UINT16_C( 4 ), /* hohIdToCanIfIdx[4] */
        UINT16_C( 5 ), /* hohIdToCanIfIdx[5] */
        UINT16_C( 32768 ), /* hohIdToCanIfIdx[6] */
        UINT16_C( 32769 ) /* hohIdToCanIfIdx[7] */
    },
    { /* canControllerConfig */
        { /* canControllerConfig[0] */
            UINT8_C( 0 ) /* controllerId */
        }
    },
    { /* canDriverConfig */
        { /* canDriverConfig[0] */
            TS_MAKEREF2CFG( canControllerConfig[0] ), /* ctrlConfigPtr */
            TS_MAKEREF2CFG( hohIdToCanIfIdx[0] ), /* hohIdToCanIfIdxPtr */
            TS_MAKEREF2CFG( driverHthConfig[0] ), /* hthConfigPtr */
            TS_MAKEREF2CFG( driverHrhConfig[0] ), /* hrhConfigPtr */
            UINT8_C( 8 ), /* upperHohIdLimit */
            UINT8_C( 1 ) /* nrOfControllers */
        }
    },
    { /* sortedRxLPduConfig */
        { /* sortedRxLPduConfig[0] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1810 ), /* canId */
            UINT16_C( 0 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[1] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1815 ), /* canId */
            UINT16_C( 1 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[2] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1808 ), /* canId */
            UINT16_C( 2 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[3] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1813 ), /* canId */
            UINT16_C( 3 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[4] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1809 ), /* canId */
            UINT16_C( 4 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[5] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1814 ), /* canId */
            UINT16_C( 5 ) /* rxLPduIndex */
        }
    }
};

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <STOP> */

#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>

/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/


/*==================[end of file]============================================*/


/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : McalLib.h                                                  **
**                                                                            **
**  VERSION      : 2.1.0                                                      **
**                                                                            **
**  DATE         : 2017-03-14                                                 **
**                                                                            **
**  VARIANT      : Variant PC                                                 **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : MCAL Library header definition file                        **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
#ifndef MCAL_LIB_H
#define MCAL_LIB_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Mcal_Compiler.h"


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


#define MCAL_NO_OF_CORES                           (0x6U)

#if(MCAL_NO_OF_CORES == 6U)
#define MCAL_COREID_MAX_VALUE                      (0x6U)
#else
#define MCAL_COREID_MAX_VALUE                      (MCAL_NO_OF_CORES - 1U)
#endif


/* DSPR values for 39x chip*/
#define MCAL_DSPR0_END_ADDR                        (0x00018000U)
#define MCAL_DSPR1_END_ADDR                        (0x00018000U)
#define MCAL_DSPR2_END_ADDR                        (0x00018000U)
#define MCAL_DSPR3_END_ADDR                        (0x00018000U)
#define MCAL_DSPR4_END_ADDR                        (0x00018000U)
#define MCAL_DSPR5_END_ADDR                        (0x00018000U)

/* Global PSPR base address for 39x chip*/
#define MCAL_PSPR0_BASE_ADDR                       (0x00100000U)
#define MCAL_PSPR1_BASE_ADDR                       (0x00100000U)
#define MCAL_PSPR2_BASE_ADDR                       (0x00100000U)
#define MCAL_PSPR3_BASE_ADDR                       (0x00100000U)
#define MCAL_PSPR4_BASE_ADDR                       (0x00100000U)
#define MCAL_PSPR5_BASE_ADDR                       (0x00100000U)

/* Global PSPR End address for 39x chip*/
#define MCAL_PSPR0_END_ADDR                        (0x0010FFFFU)
#define MCAL_PSPR1_END_ADDR                        (0x0010FFFFU)
#define MCAL_PSPR2_END_ADDR                        (0x0010FFFFU)
#define MCAL_PSPR3_END_ADDR                        (0x0010FFFFU)
#define MCAL_PSPR4_END_ADDR                        (0x0010FFFFU)
#define MCAL_PSPR5_END_ADDR                        (0x0010FFFFU)

/* Local PSPR start address for 39x chip*/
#define MCAL_LOCAL_PSPR0_BASE_ADDR                (0xC0000000U)
#define MCAL_LOCAL_PSPR1_BASE_ADDR                (0xC0000000U)
#define MCAL_LOCAL_PSPR2_BASE_ADDR                (0xC0000000U)
#define MCAL_LOCAL_PSPR3_BASE_ADDR                (0xC0000000U)
#define MCAL_LOCAL_PSPR4_BASE_ADDR                (0xC0000000U)
#define MCAL_LOCAL_PSPR5_BASE_ADDR                (0xC0000000U)

/* Local PSPR stop address for 39x chip*/
#define MCAL_LOCAL_PSPR0_END_ADDR                 (0xC000FFFFU)
#define MCAL_LOCAL_PSPR1_END_ADDR                 (0xC000FFFFU)
#define MCAL_LOCAL_PSPR2_END_ADDR                 (0xC000FFFFU)
#define MCAL_LOCAL_PSPR3_END_ADDR                 (0xC000FFFFU)
#define MCAL_LOCAL_PSPR4_END_ADDR                 (0xC000FFFFU)
#define MCAL_LOCAL_PSPR5_END_ADDR                 (0xC000FFFFU)

/* Backup clock frequency in MHz */
#define MCAL_BACKUP_FREQUENCY                      (0x64U) /* 100MHz */

/* System clock frequency in MHz*/
#define MCAL_SYSCLK_FREQUENCY                      (0x14U) /* 20MHz */


#define MCAL_CORE0_MEM_SEGMENT                     (0x7U)
#define MCAL_CORE1_MEM_SEGMENT                     (0x6U)
#define MCAL_CORE2_MEM_SEGMENT                     (0x5U)
#define MCAL_CORE3_MEM_SEGMENT                     (0x4U)
#define MCAL_CORE4_MEM_SEGMENT                     (0x3U)
#define MCAL_CORE5_MEM_SEGMENT                     (0x1U)
#define MCAL_MEM_SEGMENT2_MSB                      (0x2U)

/* MISRA2012_RULE_4_9_JUSTIFICATION: Function like macro
 * 'UNUSED_PARAMETER' to suppress compiler warnings for unused variables.
 * No side effects foreseen by violating this MISRA rule. */

#define UNUSED_PARAMETER(VariableName)             (void)(VariableName)

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : Mcal_SetBitAtomic(DataPtr,BitPos,BitLen,Data)           **
**                                                                            **
** Description      : This API like macro receives a pointer to a 32bit word  **
**                    and places Data in specified Bit Positions specified by **
**                    starting bit position BitPos and data length BitLen     **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : NA                                                      **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters(in)   : BitPos - Starting bit position where Data needs         **
**                             to be placed                                   **
**                    BitLen - The length of the Data, starting the BitPos,   **
**                             which is replaced in *DataPtr                  **
**                    Data   - Value that is to be replaced in *DataPtr       **
**                                                                            **
** Parameters (out) : DataPtr - Address of the register/variable that is to be**
**                              modified                                      **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
*******************************************************************************/

/* MISRA2012_RULE_4_9_JUSTIFICATION: 'Mcal_SetBitAtomic' implemented to write
 * bitwise atomically. Since this is compiler dependent, for easy of use, it is
 * implemented as function like macro . No side effects foreseen by violating
 * this MISRA rule. */

#define Mcal_SetBitAtomic(DataPtr,BitPos,BitLen,Data) \
      IMASKLDMST((DataPtr),(Data),(BitPos),(BitLen))


/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : Mcal_GetBitAtomic(DataValue,BitPos,BitLen)              **
**                                                                            **
** Description      : This API like macro receives a 32bit word, extracts data**
**                    starting bit positions BitPos of length BitLen and      **
**                    returns a 32bit word.                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : NA                                                      **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters(in)   : BitPos - Starting bit position where Data needs         **
**                             to be placed                                   **
**                    BitLen - The length of the Data, starting the BitPos,   **
**                             which is extracted                             **
**                    DataValue - The variable/register from which data has to**
**                                be extracted                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Data that is extracted from DataVaue                    **
**                                                                            **
*******************************************************************************/
/* MISRA2012_RULE_4_9_JUSTIFICATION: 'Mcal_GetBitAtomic' implemented to read
 * bitwise atomically. Since this is compiler dependent, for easy of use, it is
 * implemented as function like macro . No side effects foreseen by violating
 * this MISRA rule. */

#define Mcal_GetBitAtomic(DataValue,BitPos,BitLen) \
            (EXTRACT((DataValue),(BitPos),(BitLen)))


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
#define MCALLIB_START_SEC_CODE_QM_GLOBAL
#include "McalLib_MemMap.h"

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : uint32 Mcal_GetCpuWdgPassword (void)                    **
**                                                                            **
** Description      : This interface is used by applications to retrieve the  **
**                    endinit password currently installed in the watchdog of **
**                    the CPU they are currently executing on.                **
**                                                                            **
** Service ID       : 0x01                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Not Reentrant on same CPU, Reentrant on other CPUs      **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Currently installed password                            **
**                                                                            **
*******************************************************************************/

extern uint32 Mcal_GetCpuWdgPassword(void);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : uint32 Mcal_SetCpuWdgPassword (uint32 Password)         **
**                                                                            **
** Description      : This interface is used by applications to install a     **
**                    specified endinit password in the endinit registers of  **
**                    the watchdog of the CPU they are executing on.          **
**                    Previously stored data in the PW bitfield of            **
**                    WDTCPUxCON0 register is returned back to the caller     **
**                                                                            **
** Service ID       : 0x02                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Not Reentrant on same CPU, Reentrant on other CPUs      **
**                                                                            **
** Parameters(in)   : Password - New password to be installed into            **
**                    WDTCPUxCON0 register                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Returns the last installed password                     **
**                                                                            **
*******************************************************************************/

extern uint32 Mcal_SetCpuWdgPassword(uint32 Password);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : void Mcal_ResetCpuEndInitProtection (void)              **
**                                                                            **
** Description      : This interface is used by applications to temporarily   **
**                    open up access to CPU endinit protected registers of the**
**                    CPU they are executing on.                              **
**                                                                            **
** Service ID       : 0x03                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Not Reentrant on same CPU, Reentrant on other CPUs      **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
*******************************************************************************/

extern void Mcal_ResetCpuEndInitProtection(void);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : void Mcal_SetCpuEndInitProtection (void)                **
**                                                                            **
** Description      : This interface is used by applications to resume        **
**                    protection of CPU endinit protected registers of the    **
**                    CPU they are executing on.                              **
**                                                                            **
** Service ID       : 0x04                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Not Reentrant on same CPU, Reentrant on other CPUs      **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
*******************************************************************************/

extern void Mcal_SetCpuEndInitProtection(void);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : uint32 Mcal_GetSafetyEndInitPassword (void)             **
**                                                                            **
** Description      : This interface is used by applications to retrieve the  **
**                    Safety endinit password currently installed in the      **
**                    Global ENDINIT control register (SEICON0 register).     **
**                    The password corresponds to EPW bitfield in register    **
**                    SEICON0.                                                **
**                                                                            **
** Service ID       : 0x05                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Not Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Currently installed password                            **
**                                                                            **
*******************************************************************************/

extern uint32 Mcal_GetSafetyEndInitPassword(void);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : uint32 Mcal_SetSafetyEndInitPassword (uint32 Password)  **
**                                                                            **
** Description      : This interface is used by applications to install a     **
**                    password for Safety endinit protection. The interface   **
**                    internally prepares the password (shifting, inversion   **
**                    etc.), installs the password and returns the previously **
**                    installed password (from the EPW bitfield).             **
**                                                                            **
** Service ID       : 0x06                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Not Reentrant                                           **
**                                                                            **
** Parameters(in)   : Password - New password to be installed into            **
**                    SEICON0 register                                        **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Returns the last installed password                     **
**                                                                            **
*******************************************************************************/

extern uint32 Mcal_SetSafetyEndInitPassword(uint32 Password);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : void Mcal_ResetSafetyEndInitProtection (void)           **
**                                                                            **
** Description      : This interface is used by applications to temporarily   **
**                    open up access to registers protected by Safety ENDINIT **
**                    signal.                                                 **
**                                                                            **
** Service ID       : 0x07                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Not Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
*******************************************************************************/

extern void Mcal_ResetSafetyEndInitProtection(void);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : void Mcal_SetSafetyEndInitProtection (void)             **
**                                                                            **
** Description      : This interface is used by applications to resume        **
**                    protection of registers protected by safety ENDINIT     **
**                    signal.                                                 **
**                                                                            **
** Service ID       : 0x08                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Not Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
*******************************************************************************/

extern void Mcal_SetSafetyEndInitProtection(void);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : uint32 Mcal_GetPeripheralEndInitPassword (void)         **
**                                                                            **
** Description      : This interface is used by applications to retrieve the  **
**                    peripheral endinit password currently installed in the  **
**                    Global ENDINIT control register (EICON0 register).      **
**                    The password corresponds to bits 15:2 in register EICON0**
**                                                                            **
** Service ID       : 0x09                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Not Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Currently installed password                            **
**                                                                            **
*******************************************************************************/

extern uint32 Mcal_GetPeripheralEndInitPassword(void);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : uint32 Mcal_SetPeripheralEndInitPassword                **
**                    (uint32 Password)                                       **
**                                                                            **
** Description      : This interface is used by applications to install a     **
**                    password for peripheral endinit protection. The         **
**                    interface internally prepares the password (shifting,   **
**                    inversion etc.), installs the password and returns the  **
**                    previously installed password.                          **
**                                                                            **
** Service ID       : 0x0A                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Not Reentrant                                           **
**                                                                            **
** Parameters(in)   : Password - New password to be installed into            **
**                    EICON0 register                                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Returns the last installed password                     **
**                                                                            **
*******************************************************************************/

extern uint32 Mcal_SetPeripheralEndInitPassword(uint32 Password);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : void Mcal_ResetPeripheralEndInitProtection (void)       **
**                                                                            **
** Description      : This interface is used by applications to temporarily   **
**                    open up access to registers protected by peripheral     **
**                    endinit signal.                                         **
**                                                                            **
** Service ID       : 0x0B                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Not Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
*******************************************************************************/

extern void Mcal_ResetPeripheralEndInitProtection(void);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : void Mcal_SetPeripheralEndInitProtection (void)         **
**                                                                            **
** Description      : This interface is used by applications to resume        **
**                    protection of registers protected by ENDINIT signal.    **
**                                                                            **
** Service ID       : 0x0C                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Not Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
*******************************************************************************/

extern void Mcal_SetPeripheralEndInitProtection(void);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : uint32 Mcal_GetCpuPhysicalId(void)                      **
**                                                                            **
** Description      : This interface is used by applications in a multicore   **
**                    environment to determine the CPU they are executing on. **
**                    The API returns the contents of CORE_ID register, for   **
**                    the core on which it is invoked.                        **
**                                                                            **
** Service ID       : 0x0D                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Physical Core ID for the CPU on which this API is called**
**                                                                            **
*******************************************************************************/

extern uint32 Mcal_GetCpuPhysicalId(void);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : uint32 Mcal_GetGlobalDsprAddress                        **
**                    (                                                       **
**                     uint32 CpuId,                                          **
**                     uint32 LocalDsprAddress                                **
**                    )                                                       **
**                                                                            **
** Description      : This interface is used by applications in a multicore   **
**                    environment to determine the global address of a local  **
**                    DSPR address of a specified CPU. A value 0 is returned  **
**                    in case an invalid input argument is passed             **
**                    (incorrect CpuId, local DSPR address)                   **
**                                                                            **
**                                                                            **
** Service ID       : 0x0E                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Concurrency Safe                                        **
**                                                                            **
** Parameters(in)   : CpuId - Physical Core ID                                **
**                    LocalDsprAddress - Local DSPR address for which global  **
**                    DSPR address is returned                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : 0: Invalid input parameter passed                       **
**                    Else, value returned the Global DSPR address            **
**                                                                            **
*******************************************************************************/

extern uint32 Mcal_GetGlobalDsprAddress(uint32 CpuId, uint32 LocalDsprAddress);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : uint32 Mcal_GetLocalDsprAddress                         **
**                    (                                                       **
**                      uint32 GlobalDsprAddress                              **
**                    )                                                       **
**                                                                            **
**                                                                            **
** Description      : This API is used by applications in a multicore         **
**                    environment to determine the local CPU address of a     **
**                    global DSPR address of the CPU, this interface is       **
**                    invoked on. A value 0 is returned in case an invalid    **
**                    input argument is passed(incorrect global DSPR address) **
**                                                                            **
**                                                                            **
** Service ID       : 0x0F                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Concurrency Safe                                        **
**                                                                            **
** Parameters(in)   : GlobalDsprAddress - Global DSPR address                 **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : 0: Invalid input parameter passed                       **
**                    Else, value returned the local DSPR address             **
**                                                                            **
*******************************************************************************/

extern uint32 Mcal_GetLocalDsprAddress(uint32 GlobalDsprAddress);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : uint32 Mcal_GetGlobalPsprAddress                        **
**                    (                                                       **
**                     uint32 CpuId,                                          **
**                     uint32 LocalPsprAddress                                **
**                    )                                                       **
**                                                                            **
** Description      : This interface is used by applications in a multicore   **
**                    environment to determine the global address of a local  **
**                    PSPR address of a specified CPU. A value 0 is returned  **
**                    in case an invalid input argument is passed             **
**                    (incorrect CpuId, local PSPR address)                   **
**                                                                            **
**                                                                            **
** Service ID       : 0x10                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Concurrency Safe                                        **
**                                                                            **
** Parameters(in)   : CpuId - Physical Core ID                                **
**                    LocalPsprAddress - Local PSPR address for which global  **
**                    PSPR address is returned                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : 0: Invalid input parameter passed                       **
**                    Else, value returned the Global PSPR address            **
**                                                                            **
*******************************************************************************/

extern uint32 Mcal_GetGlobalPsprAddress(uint32 CpuId, uint32 LocalPsprAddress);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : uint32 Mcal_GetLocalPsprAddress                         **
**                    (                                                       **
**                      uint32 GlobalPsprAddress                              **
**                    )                                                       **
**                                                                            **
** Description      : This API is used by applications in a multicore         **
**                    environment to determine the local CPU address of a     **
**                    global PSPR address of the CPU, this interface is       **
**                    invoked on. A value 0 is returned in case an invalid    **
**                    input argument is passed(incorrect global PSPR address) **
**                                                                            **
**                                                                            **
** Service ID       : 0x11                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Concurrency Safe                                        **
**                                                                            **
** Parameters(in)   : GlobalPsprAddress - Global PSPR address                 **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : 0: Invalid input parameter passed                       **
**                    Else, value returned the local PSPR address             **
**                                                                            **
**                                                                            **
*******************************************************************************/

extern uint32 Mcal_GetLocalPsprAddress(uint32 GlobalPsprAddress);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : uint32 Mcal_DelayTickResolution (void)                  **
**                                                                            **
** Description      : The interface is used by applications to retrieve in    **
**                    nanoseconds the resolution of the delay tick (STM timer)**
**                                                                            **
** Service ID       : 0x12                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Concurrency Safe                                        **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Resolution of delay tick in nanoseconds                 **
**                                                                            **
*******************************************************************************/

extern uint32 Mcal_DelayTickResolution(void);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : uint32 Mcal_DelayResetTickCalibration(void)             **
**                                                                            **
** Description      : The interface is used by applications to indicate to    **
**                    MCALLib that the clock tree has changed. The expectation**
**                    is that as a result of invocation of this service, any  **
**                    internally cached tick resolution data is discarded.    **
**                    This service is expected to query the clock tree and    **
**                    determine the resolution. The interface returns in      **
**                    nanoseconds the resolution of the delay tick (STM timer)**
**                                                                            **
** Service ID       : 0x13                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Not Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Resolution of delay tick in nanoseconds                 **
**                                                                            **
*******************************************************************************/

extern uint32 Mcal_DelayResetTickCalibration(void);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : uint32 Mcal_DelayGetTick (void)                         **
**                                                                            **
** Description      : This interface is used by applications to retrieve the  **
**                    latest tick count of the underlying STM timer. The      **
**                    latest tick count in STMx_TIM0 (‘x’ corresponds to CPU  **
**                    on which the API is invoked) is returned by this        **
**                    interface. There are two uses of this interface.        **
**                    Applications can retrieve a base tick count, add the    **
**                    desired delay to the base tick count and arrive at a    **
**                    terminal tick count. Applications can also then         **
**                    periodically invoke this interface to determine if the  **
**                    underlying timer has counted up to the terminal tick    **
**                    count.                                                  **
**                                                                            **
** Service ID       : 0x14                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Concurrency Safe                                        **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Latest timer counter value                              **
**                                                                            **
*******************************************************************************/

extern uint32 Mcal_DelayGetTick(void);

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : uint32 Mcal_GetCpuIndex (uint32 CpuId)                  **
**                                                                            **
** Description      : This interface is used by applications in a multicore   **
**                    environment to determine the CPU they are executing on. **
**                    The API returns the contents of CORE_ID register, for   **
**                    the core on which it is invoked.                        **
**                                                                            **
** Service ID       : 0x26                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Concurrency Safe                                        **
**                                                                            **
** Parameters(in)   : CpuId - Physical Core ID                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Returns the Core Index corresponding to the input       **
**                    physical Core Id. In case the input Core Id is an       **
**                    invalid value, then the API returns 0xFFFFFFFF          **
**                                                                            **
*******************************************************************************/

extern uint32 Mcal_GetCpuIndex(uint32 CpuId);


#define MCALLIB_STOP_SEC_CODE_QM_GLOBAL
/* MISRA2012_RULE_4_10_JUSTIFICATION: 'McalLib_MemMap.h' is header file which
 * contains the memory sections for McalLib. It should not be guarded by
 * standard include. No side effects foreseen by violating this MISRA rule. */
#include "McalLib_MemMap.h"


#endif

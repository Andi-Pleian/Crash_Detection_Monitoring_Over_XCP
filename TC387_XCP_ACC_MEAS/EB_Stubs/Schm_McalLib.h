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
**  FILENAME     : SchM_McalLib.h                                             **
**                                                                            **
**  VERSION      : 1.0.0                                                      **
**                                                                            **
**  DATE         : 2016-10-05                                                 **
**                                                                            **
**  VARIANT      : Variant PC                                                 **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : SchM file for McalLib                                      **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/

#ifndef MCAL_LIB_SCHM_H
#define MCAL_LIB_SCHM_H

#include "Std_Types.h"


extern void SchM_Enter_McalLib_PeripheralEndInit(void);
extern void SchM_Exit_McalLib_PeripheralEndInit(void);

extern void SchM_Enter_McalLib_SafetyEndInit(void);
extern void SchM_Exit_McalLib_SafetyEndInit(void);

extern void SchM_Enter_McalLib_CpuEndInit(void);
extern void SchM_Exit_McalLib_CpuEndInit(void);

extern void SchM_Enter_McalLib_StmTimerResolution(void);
extern void SchM_Exit_McalLib_StmTimerResolution(void);

extern void SchM_Enter_McalLib_TomTgcReg(void);

extern void SchM_Exit_McalLib_TomTgcReg(void);


extern void SchM_Enter_McalLib_AtomAgcReg(void);

extern void SchM_Exit_McalLib_AtomAgcReg(void);


#endif

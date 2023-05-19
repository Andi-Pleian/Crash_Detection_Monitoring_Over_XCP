/*
 * Mcal_Stubs.h
 *
 *  Created on: May 19, 2023
 *      Author: uif47623
 */

#ifndef AUTOSAR_MCAL_STUBS_H_
#define AUTOSAR_MCAL_STUBS_H_

#include "Platform_Types.h"

extern uint32 Mcal_DelayGetTick(void);
extern void Mcal_ResetPeripheralEndInitProtection(void);
extern void Mcal_SetPeripheralEndInitProtection(void);
extern uint32 Mcal_DelayTickResolution(void);

#endif /* AUTOSAR_MCAL_STUBS_H_ */
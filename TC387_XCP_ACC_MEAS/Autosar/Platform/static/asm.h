/*
 *	Copyright (c) 2008-2010 Wind River Systems, Inc.
 *	All Rights Reserved
 *	Implementation module : diab/asm.h
 *
 *	Description :
 *	This module provides access to the target assembly instructions
 *	through intrinsic function prototypes.
 */

#ifdef	__ppc		/* PowerPC */
#include "ppcasm.h"
#endif
#ifdef __arm		/* ARM */
#include "armasm.h"
#endif
#ifdef __mips		/* MIPS */
#include "mipsasm.h"
#endif
#ifdef __tc		/* Tricore */
#include "tcasm.h"
#endif
#ifdef __nec		/* RH-850 */
#include "necasm.h"
#endif

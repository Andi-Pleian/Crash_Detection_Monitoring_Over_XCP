#if (!defined NM_STACK_TYPES_H)
#define NM_STACK_TYPES_H

/**
 * \file
 *
 * \brief AUTOSAR Nm
 *
 * This file contains the implementation of the AUTOSAR
 * module Nm.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*===============================[includes]=================================*/

#include <ComStack_Types.h>
/* !LINKSTO Nm124_Std_Types,1 */

/*===========================[macro definitions]============================*/

/*============================[type definitions]============================*/

/** \brief Operational modes of the network management */
typedef enum
{
  /** \brief Bus-Sleep Mode */
  NM_MODE_BUS_SLEEP,
  /** \brief Prepare-Bus Sleep Mode */
  NM_MODE_PREPARE_BUS_SLEEP,
  /** \brief Synchronize Mode */
  NM_MODE_SYNCHRONIZE,
  /** \brief Network Mode */
  NM_MODE_NETWORK
} Nm_ModeType;

/** \brief States of the network management state machine */
typedef enum
{
  /** \brief Uninitialized State (0) */
  NM_STATE_UNINIT            = 0,
  /** \brief Bus-Sleep State (1) */
  NM_STATE_BUS_SLEEP         = 1,
  /** \brief Prepare-Bus State (2) */
  NM_STATE_PREPARE_BUS_SLEEP = 2,
  /** \brief Ready Sleep State (3) */
  NM_STATE_READY_SLEEP       = 3,
  /** \brief Normal Operation State (4) */
  NM_STATE_NORMAL_OPERATION  = 4,
  /** \brief Repeat Message State (5) */
  NM_STATE_REPEAT_MESSAGE    = 5,
  /** \brief Synchronize State (6) */
  NM_STATE_SYNCHRONIZE       = 6
} Nm_StateType;

/** \brief BusNm types */
typedef enum
{
  /** \brief CAN NM type */
  NM_BUSNM_CANNM     = 0,
  /** \brief FR NM type */
  NM_BUSNM_FRNM      = 1,
  /** \brief LIN NM type */
  NM_BUSNM_LINNM     = 2,
  /** \brief UDP NM type */
  NM_BUSNM_UDPNM     = 3,
  /** \brief Generic NM type */
  NM_BUSNM_GENERICNM = 4,
  /** \brief NM type undefined */
  NM_BUSNM_UNDEF     = 0xFF
} Nm_BusNmType;

/*=====================[external function declarations]=====================*/

/*=====================[internal function declarations]=====================*/

/*=====================[external constants declarations]====================*/

/*=====================[internal constants declarations]====================*/

/*=======================[external data declarations]=======================*/

#endif /* (!defined NM_STACK_TYPES_H) */

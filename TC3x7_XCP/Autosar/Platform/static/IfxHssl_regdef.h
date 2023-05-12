/**
 * \file IfxHssl_regdef.h
 * \brief
 * \copyright Copyright (c) 2015 Infineon Technologies AG. All rights reserved.
 *
 *
 * Date: 2015-12-17 16:14:54 GMT
 * Version: TBD
 * Specification: TBD
 * MAY BE CHANGED BY USER [yes/no]: No
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup IfxLld_Hssl_Registers HsslRegisters
 * \ingroup IfxLld
 * 
 * \defgroup IfxLld_Hssl_Registers_Bitfields Bitfields
 * \ingroup IfxLld_Hssl_Registers
 * 
 * \defgroup IfxLld_Hssl_Registers_union Register unions
 * \ingroup IfxLld_Hssl_Registers
 * 
 * \defgroup IfxLld_Hssl_Registers_struct Memory map
 * \ingroup IfxLld_Hssl_Registers
 */
#ifndef IFXHSSL_REGDEF_H
#define IFXHSSL_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/
/** \addtogroup IfxLld_Hssl_Bitfields
 * \{  */
/** \brief Access Enable Register 0 */
typedef struct _Ifx_HSSL_ACCEN0_Bits
{
    Ifx_UReg_32Bit EN0:1;             /**< \brief [0:0] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN1:1;             /**< \brief [1:1] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN2:1;             /**< \brief [2:2] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN3:1;             /**< \brief [3:3] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN4:1;             /**< \brief [4:4] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN5:1;             /**< \brief [5:5] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN6:1;             /**< \brief [6:6] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN7:1;             /**< \brief [7:7] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN8:1;             /**< \brief [8:8] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN9:1;             /**< \brief [9:9] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN10:1;            /**< \brief [10:10] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN11:1;            /**< \brief [11:11] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN12:1;            /**< \brief [12:12] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN13:1;            /**< \brief [13:13] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN14:1;            /**< \brief [14:14] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN15:1;            /**< \brief [15:15] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN16:1;            /**< \brief [16:16] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN17:1;            /**< \brief [17:17] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN18:1;            /**< \brief [18:18] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN19:1;            /**< \brief [19:19] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN20:1;            /**< \brief [20:20] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN21:1;            /**< \brief [21:21] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN22:1;            /**< \brief [22:22] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN23:1;            /**< \brief [23:23] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN24:1;            /**< \brief [24:24] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN25:1;            /**< \brief [25:25] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN26:1;            /**< \brief [26:26] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN27:1;            /**< \brief [27:27] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN28:1;            /**< \brief [28:28] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN29:1;            /**< \brief [29:29] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN30:1;            /**< \brief [30:30] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
    Ifx_UReg_32Bit EN31:1;            /**< \brief [31:31] Access Enable for Master TAG ID ${y} - EN${y} (rw) */
} Ifx_HSSL_ACCEN0_Bits;

/** \brief Access Enable Register 1 */
typedef struct _Ifx_HSSL_ACCEN1_Bits
{
    Ifx_UReg_32Bit reserved_0:32;     /**< \brief [31:0] \internal Reserved */
} Ifx_HSSL_ACCEN1_Bits;

/** \brief Access Rules Register */
typedef struct _Ifx_HSSL_AR_Bits
{
    Ifx_UReg_32Bit ARW0:2;            /**< \brief [1:0] Access Rule for Window ${x} - ARW${x} (rw) */
    Ifx_UReg_32Bit ARW1:2;            /**< \brief [3:2] Access Rule for Window ${x} - ARW${x} (rw) */
    Ifx_UReg_32Bit ARW2:2;            /**< \brief [5:4] Access Rule for Window ${x} - ARW${x} (rw) */
    Ifx_UReg_32Bit ARW3:2;            /**< \brief [7:6] Access Rule for Window ${x} - ARW${x} (rw) */
    Ifx_UReg_32Bit reserved_8:8;      /**< \brief [15:8] \internal Reserved */
    Ifx_UReg_32Bit MAVCH:2;           /**< \brief [17:16] Memory Access Violation Channel - MAVCH (rh) */
    Ifx_UReg_32Bit reserved_18:14;    /**< \brief [31:18] \internal Reserved */
} Ifx_HSSL_AR_Bits;

/** \brief Access Window End Register ${i} */
typedef struct _Ifx_HSSL_AW_AWEND_Bits
{
    Ifx_UReg_32Bit reserved_0:8;      /**< \brief [7:0] \internal Reserved */
    Ifx_UReg_32Bit AWE:24;            /**< \brief [31:8] Access Window End Address - AWE (rw) */
} Ifx_HSSL_AW_AWEND_Bits;

/** \brief Access Window Start Register ${i} */
typedef struct _Ifx_HSSL_AW_AWSTART_Bits
{
    Ifx_UReg_32Bit reserved_0:8;      /**< \brief [7:0] \internal Reserved */
    Ifx_UReg_32Bit AWS:24;            /**< \brief [31:8] Access Window Start Address - AWS (rw) */
} Ifx_HSSL_AW_AWSTART_Bits;

/** \brief Configuration Register */
typedef struct _Ifx_HSSL_CFG_Bits
{
    Ifx_UReg_32Bit PREDIV:14;         /**< \brief [13:0] Global Predivider - PREDIV (rw) */
    Ifx_UReg_32Bit reserved_14:2;     /**< \brief [15:14] \internal Reserved */
    Ifx_UReg_32Bit SMT:1;             /**< \brief [16:16] Streaming Mode Transmitter - SMT (rw) */
    Ifx_UReg_32Bit SMR:1;             /**< \brief [17:17] Streaming Mode Receiver - SMR (rw) */
    Ifx_UReg_32Bit SCM:1;             /**< \brief [18:18] Streaming Channel Mode - SCM (rw) */
    Ifx_UReg_32Bit CCC:1;             /**< \brief [19:19] Channel Code Control - CCC (rw) */
    Ifx_UReg_32Bit reserved_20:12;    /**< \brief [31:20] \internal Reserved */
} Ifx_HSSL_CFG_Bits;

/** \brief Clock Control Register */
typedef struct _Ifx_HSSL_CLC_Bits
{
    Ifx_UReg_32Bit DISR:1;            /**< \brief [0:0] Module Disable Request Bit - DISR (rw) */
    Ifx_UReg_32Bit DISS:1;            /**< \brief [1:1] Module Disable Status Bit - DISS (rh) */
    Ifx_UReg_32Bit reserved_2:1;      /**< \brief [2:2] \internal Reserved */
    Ifx_UReg_32Bit EDIS:1;            /**< \brief [3:3] Sleep Mode Enable Control - EDIS (rw) */
    Ifx_UReg_32Bit reserved_4:28;     /**< \brief [31:4] \internal Reserved */
} Ifx_HSSL_CLC_Bits;

/** \brief CRC Control Register */
typedef struct _Ifx_HSSL_CRC_Bits
{
    Ifx_UReg_32Bit XORMASK:16;        /**< \brief [15:0] Value to be XORed with the Calculated CRC - XORMASK (rw) */
    Ifx_UReg_32Bit XEN:1;             /**< \brief [16:16] Enable the Error Injection via XORMASK - XEN (rw) */
    Ifx_UReg_32Bit reserved_17:15;    /**< \brief [31:17] \internal Reserved */
} Ifx_HSSL_CRC_Bits;

/** \brief Module Identification Register */
typedef struct _Ifx_HSSL_ID_Bits
{
    Ifx_UReg_32Bit MODREV:8;          /**< \brief [7:0] Module Revision Number - MODREV (r) */
    Ifx_UReg_32Bit MODTYPE:8;         /**< \brief [15:8] Module Type - MODTYPE (r) */
    Ifx_UReg_32Bit MODNUMBER:16;      /**< \brief [31:16] Module Number Value - MODNUMBER (r) */
} Ifx_HSSL_ID_Bits;

/** \brief Initiator Stream Current Address Register */
typedef struct _Ifx_HSSL_IS_CA_Bits
{
    Ifx_UReg_32Bit reserved_0:5;      /**< \brief [4:0] \internal Reserved */
    Ifx_UReg_32Bit CURR:27;           /**< \brief [31:5] Address of the Memory Location for the Current Transfer - CURR (rh) */
} Ifx_HSSL_IS_CA_Bits;

/** \brief Initiator Stream Frame Count Register */
typedef struct _Ifx_HSSL_IS_FC_Bits
{
    Ifx_UReg_32Bit RELCOUNT:16;       /**< \brief [15:0] Reload Count Number - RELCOUNT (rw) */
    Ifx_UReg_32Bit CURCOUNT:16;       /**< \brief [31:16] Current Count Number - CURCOUNT (rh) */
} Ifx_HSSL_IS_FC_Bits;

/** \brief Initiator Stream Start Address Register */
typedef struct _Ifx_HSSL_IS_SA_Bits
{
    Ifx_UReg_32Bit reserved_0:5;      /**< \brief [4:0] \internal Reserved */
    Ifx_UReg_32Bit START:27;          /**< \brief [31:5] Start Address for the Memory Range - START (rw) */
} Ifx_HSSL_IS_SA_Bits;

/** \brief Initiator Control Data Register ${i} */
typedef struct _Ifx_HSSL_I_ICON_Bits
{
    Ifx_UReg_32Bit IDQ:1;             /**< \brief [0:0] Read ID Request - IDQ (w) */
    Ifx_UReg_32Bit TQ:1;              /**< \brief [1:1] Trigger Request - TQ (w) */
    Ifx_UReg_32Bit LETT:3;            /**< \brief [4:2] Last Error Transaction Tag - LETT (rh) */
    Ifx_UReg_32Bit CETT:3;            /**< \brief [7:5] Currently Expected Transaction Tag - CETT (rh) */
    Ifx_UReg_32Bit TOCV:8;            /**< \brief [15:8] Time Out Current Value - TOCV (rh) */
    Ifx_UReg_32Bit DATLEN:2;          /**< \brief [17:16] Data Length - DATLEN (rw) */
    Ifx_UReg_32Bit RWT:2;             /**< \brief [19:18] Read Write Trigger Command Type - RWT (rw) */
    Ifx_UReg_32Bit BSY:1;             /**< \brief [20:20] Channel Busy - BSY (rh) */
    Ifx_UReg_32Bit ITTAG:3;           /**< \brief [23:21] Initiator Transaction Tag - ITTAG (rh) */
    Ifx_UReg_32Bit TOREL:8;           /**< \brief [31:24] Time Out Reload Value - TOREL (rw) */
} Ifx_HSSL_I_ICON_Bits;

/** \brief Initiator Read Data Register */
typedef struct _Ifx_HSSL_I_IRD_Bits
{
    Ifx_UReg_32Bit DATA:32;           /**< \brief [31:0] Data Delivered by a Read Response Frame - DATA (rh) */
} Ifx_HSSL_I_IRD_Bits;

/** \brief Initiator Read Write Address Register */
typedef struct _Ifx_HSSL_I_IRWA_Bits
{
    Ifx_UReg_32Bit ADDRESS:32;        /**< \brief [31:0] Address Part of the Payload of a Write Frame - ADDRESS (rw) */
} Ifx_HSSL_I_IRWA_Bits;

/** \brief Initiator Write Data Register ${i} */
typedef struct _Ifx_HSSL_I_IWD_Bits
{
    Ifx_UReg_32Bit DATA:32;           /**< \brief [31:0] Data Part of the Payload of a Write Frame - DATA (rw) */
} Ifx_HSSL_I_IWD_Bits;

/** \brief Kernel Reset Register 0 */
typedef struct _Ifx_HSSL_KRST0_Bits
{
    Ifx_UReg_32Bit RST:1;             /**< \brief [0:0] Kernel Reset - RST (rwh) */
    Ifx_UReg_32Bit RSTSTAT:1;         /**< \brief [1:1] Kernel Reset Status - RSTSTAT (rh) */
    Ifx_UReg_32Bit reserved_2:30;     /**< \brief [31:2] \internal Reserved */
} Ifx_HSSL_KRST0_Bits;

/** \brief Kernel Reset Register 1 */
typedef struct _Ifx_HSSL_KRST1_Bits
{
    Ifx_UReg_32Bit RST:1;             /**< \brief [0:0] Kernel Reset - RST (rwh) */
    Ifx_UReg_32Bit reserved_1:31;     /**< \brief [31:1] \internal Reserved */
} Ifx_HSSL_KRST1_Bits;

/** \brief Kernel Reset Status Clear Register */
typedef struct _Ifx_HSSL_KRSTCLR_Bits
{
    Ifx_UReg_32Bit CLR:1;             /**< \brief [0:0] Kernel Reset Status Clear - CLR (w) */
    Ifx_UReg_32Bit reserved_1:31;     /**< \brief [31:1] \internal Reserved */
} Ifx_HSSL_KRSTCLR_Bits;

/** \brief Miscellaneous Flags Register */
typedef struct _Ifx_HSSL_MFLAGS_Bits
{
    Ifx_UReg_32Bit NACK:4;            /**< \brief [3:0] Not Acknowledge Error - Target Error - NACK (rh) */
    Ifx_UReg_32Bit TTE:4;             /**< \brief [7:4] Transaction Tag Error - TTE (rh) */
    Ifx_UReg_32Bit TIMEOUT:4;         /**< \brief [11:8] Timeout Error - TIMEOUT (rh) */
    Ifx_UReg_32Bit UNEXPECTED:4;      /**< \brief [15:12] Unexpected Type of Frame Error - UNEXPECTED (rh) */
    Ifx_UReg_32Bit reserved_16:2;     /**< \brief [17:16] \internal Reserved */
    Ifx_UReg_32Bit TMB:1;             /**< \brief [18:18] Target Memory Block - TMB (rh) */
    Ifx_UReg_32Bit IMB:1;             /**< \brief [19:19] Initiator Memory Block - IMB (rh) */
    Ifx_UReg_32Bit ISB:1;             /**< \brief [20:20] Initiator Stream Block Request - ISB (rh) */
    Ifx_UReg_32Bit MAV:1;             /**< \brief [21:21] Memory Access Violation - MAV (rh) */
    Ifx_UReg_32Bit SRIE:1;            /**< \brief [22:22] SRI/SPB Bus Access Error - SRIE (rh) */
    Ifx_UReg_32Bit PIE1:1;            /**< \brief [23:23] PHY Inconsistency Error 1(Channel Number Code Error) - PIE1 (rh) */
    Ifx_UReg_32Bit PIE2:1;            /**< \brief [24:24] PHY Inconsistency Error 2(Data Length Error) - PIE2 (rh) */
    Ifx_UReg_32Bit CRCE:1;            /**< \brief [25:25] CRC Error - CRCE (rh) */
    Ifx_UReg_32Bit reserved_26:2;     /**< \brief [27:26] \internal Reserved */
    Ifx_UReg_32Bit TSE:1;             /**< \brief [28:28] Target Stream Enable - TSE (rh) */
    Ifx_UReg_32Bit TEI:1;             /**< \brief [29:29] Transmit Enable Input - TEI (rh) */
    Ifx_UReg_32Bit TEO:1;             /**< \brief [30:30] Transmit Enable Output - TEO (rh) */
    Ifx_UReg_32Bit INI:1;             /**< \brief [31:31] Initialize Mode - INI (rh) */
} Ifx_HSSL_MFLAGS_Bits;

/** \brief Miscellaneous Flags Clear Register */
typedef struct _Ifx_HSSL_MFLAGSCL_Bits
{
    Ifx_UReg_32Bit NACKC:4;           /**< \brief [3:0] NACK Flags Clear - NACKC (w) */
    Ifx_UReg_32Bit TTEC:4;            /**< \brief [7:4] Transaction Tag Error Flags Clear - TTEC (w) */
    Ifx_UReg_32Bit TIMEOUTC:4;        /**< \brief [11:8] Timeout Error Flags Clear - TIMEOUTC (w) */
    Ifx_UReg_32Bit UNEXPECTEDC:4;     /**< \brief [15:12] Unexpected Error Flags Clear - UNEXPECTEDC (w) */
    Ifx_UReg_32Bit reserved_16:2;     /**< \brief [17:16] \internal Reserved */
    Ifx_UReg_32Bit TMBC:1;            /**< \brief [18:18] Target Memory Block Flag Clear - TMBC (w) */
    Ifx_UReg_32Bit IMBC:1;            /**< \brief [19:19] Initiator Memory Block Flag Clear - IMBC (w) */
    Ifx_UReg_32Bit ISBC:1;            /**< \brief [20:20] Initiator Stream Block Request Clear - ISBC (w) */
    Ifx_UReg_32Bit MAVC:1;            /**< \brief [21:21] MAV Flag Clear - MAVC (w) */
    Ifx_UReg_32Bit SRIEC:1;           /**< \brief [22:22] SRI/SPB Bus Access Error Flag Clear - SRIEC (w) */
    Ifx_UReg_32Bit PIE1C:1;           /**< \brief [23:23] PIE1 Error Flag Clear - PIE1C (w) */
    Ifx_UReg_32Bit PIE2C:1;           /**< \brief [24:24] PIE2 Error Flag Clear - PIE2C (w) */
    Ifx_UReg_32Bit CRCEC:1;           /**< \brief [25:25] CRC Error Flag Clear - CRCEC (w) */
    Ifx_UReg_32Bit reserved_26:2;     /**< \brief [27:26] \internal Reserved */
    Ifx_UReg_32Bit TSEC:1;            /**< \brief [28:28] Target Stream Enable Flag Clear - TSEC (w) */
    Ifx_UReg_32Bit reserved_29:1;     /**< \brief [29:29] \internal Reserved */
    Ifx_UReg_32Bit TEOC:1;            /**< \brief [30:30] Transmit Enable Flag Clear - TEOC (w) */
    Ifx_UReg_32Bit INIC:1;            /**< \brief [31:31] Initialize Mode Flag Clear - INIC (w) */
} Ifx_HSSL_MFLAGSCL_Bits;

/** \brief Flags Enable Register */
typedef struct _Ifx_HSSL_MFLAGSEN_Bits
{
    Ifx_UReg_32Bit NACKEN:4;          /**< \brief [3:0] Not Acknowledge Error Enable Bits - NACKEN (rw) */
    Ifx_UReg_32Bit TTEEN:4;           /**< \brief [7:4] Transaction Tag Error Enable Bits - TTEEN (rw) */
    Ifx_UReg_32Bit TIMEOUTEN:4;       /**< \brief [11:8] Timeout Error Enable Bits - TIMEOUTEN (rw) */
    Ifx_UReg_32Bit UNEXPECTEDEN:4;    /**< \brief [15:12] Unexpected Error Enable Bits - UNEXPECTEDEN (rw) */
    Ifx_UReg_32Bit reserved_16:5;     /**< \brief [20:16] \internal Reserved */
    Ifx_UReg_32Bit MAVEN:1;           /**< \brief [21:21] MAV Enable Bit - MAVEN (rw) */
    Ifx_UReg_32Bit SRIEEN:1;          /**< \brief [22:22] SRI/SPB Bus Access Error Enable Bit - SRIEEN (rw) */
    Ifx_UReg_32Bit PIE1EN:1;          /**< \brief [23:23] PIE1 Error Enable Bit - PIE1EN (rw) */
    Ifx_UReg_32Bit PIE2EN:1;          /**< \brief [24:24] PIE2 Error Enable Bit - PIE2EN (rw) */
    Ifx_UReg_32Bit CRCEEN:1;          /**< \brief [25:25] CRC Error Enable Bit - CRCEEN (rw) */
    Ifx_UReg_32Bit reserved_26:3;     /**< \brief [28:26] \internal Reserved */
    Ifx_UReg_32Bit TEIEN:1;           /**< \brief [29:29] TEI Enable Bit - TEIEN (rw) */
    Ifx_UReg_32Bit reserved_30:2;     /**< \brief [31:30] \internal Reserved */
} Ifx_HSSL_MFLAGSEN_Bits;

/** \brief Miscellaneous Flags Set Register */
typedef struct _Ifx_HSSL_MFLAGSSET_Bits
{
    Ifx_UReg_32Bit NACKS:4;           /**< \brief [3:0] NACK Flags Set - NACKS (w) */
    Ifx_UReg_32Bit TTES:4;            /**< \brief [7:4] Transaction Tag Error Flags Set - TTES (w) */
    Ifx_UReg_32Bit TIMEOUTS:4;        /**< \brief [11:8] Timeout Error Flags Set - TIMEOUTS (w) */
    Ifx_UReg_32Bit UNEXPECTEDS:4;     /**< \brief [15:12] Unexpected Error Flags Set - UNEXPECTEDS (w) */
    Ifx_UReg_32Bit reserved_16:2;     /**< \brief [17:16] \internal Reserved */
    Ifx_UReg_32Bit TMBS:1;            /**< \brief [18:18] Target Memory Block Flag Set - TMBS (w) */
    Ifx_UReg_32Bit IMBS:1;            /**< \brief [19:19] Initiator Memory Block Flag Set - IMBS (w) */
    Ifx_UReg_32Bit ISBS:1;            /**< \brief [20:20] Initiator Stream Block Request Set - ISBS (w) */
    Ifx_UReg_32Bit MAVS:1;            /**< \brief [21:21] MAV Flag Set - MAVS (w) */
    Ifx_UReg_32Bit SRIES:1;           /**< \brief [22:22] SRI/SPB Bus Access Error Flag Set - SRIES (w) */
    Ifx_UReg_32Bit PIE1S:1;           /**< \brief [23:23] PIE1 Error Flag Set - PIE1S (w) */
    Ifx_UReg_32Bit PIE2S:1;           /**< \brief [24:24] PIE2 Error Flag Set - PIE2S (w) */
    Ifx_UReg_32Bit CRCES:1;           /**< \brief [25:25] CRC Error Flag Set - CRCES (w) */
    Ifx_UReg_32Bit reserved_26:2;     /**< \brief [27:26] \internal Reserved */
    Ifx_UReg_32Bit TSES:1;            /**< \brief [28:28] Target Stream Enable Flag Set - TSES (w) */
    Ifx_UReg_32Bit reserved_29:1;     /**< \brief [29:29] \internal Reserved */
    Ifx_UReg_32Bit TEOS:1;            /**< \brief [30:30] Transmit Enable Flag Set - TEOS (w) */
    Ifx_UReg_32Bit INIS:1;            /**< \brief [31:31] Initialize Mode Flag Set - INIS (w) */
} Ifx_HSSL_MFLAGSSET_Bits;

/** \brief Multi Slave Control Register */
typedef struct _Ifx_HSSL_MSCR_Bits
{
    Ifx_UReg_32Bit EN:1;              /**< \brief [0:0] Multi Slave Mode Enable - EN (rw) */
    Ifx_UReg_32Bit SLAVETAG:2;        /**< \brief [2:1] Slave Tag - SLAVETAG (rw) */
    Ifx_UReg_32Bit reserved_3:13;     /**< \brief [15:3] \internal Reserved */
    Ifx_UReg_32Bit ITXSTOP:1;         /**< \brief [16:16] Initiator Transmission Stop - ITXSTOP (rw) */
    Ifx_UReg_32Bit reserved_17:15;    /**< \brief [31:17] \internal Reserved */
} Ifx_HSSL_MSCR_Bits;

/** \brief OCDS Control and Status */
typedef struct _Ifx_HSSL_OCS_Bits
{
    Ifx_UReg_32Bit TGS:2;             /**< \brief [1:0] Trigger Set for OTGB0/1 - TGS (rw) */
    Ifx_UReg_32Bit TGB:1;             /**< \brief [2:2] OTGB0/1 Bus Select - TGB (rw) */
    Ifx_UReg_32Bit TG_P:1;            /**< \brief [3:3] TGS, TGB Write Protection - TG_P (w) */
    Ifx_UReg_32Bit reserved_4:20;     /**< \brief [23:4] \internal Reserved */
    Ifx_UReg_32Bit SUS:4;             /**< \brief [27:24] OCDS Suspend Control - SUS (rw) */
    Ifx_UReg_32Bit SUS_P:1;           /**< \brief [28:28] SUS Write Protection - SUS_P (w) */
    Ifx_UReg_32Bit SUSSTA:1;          /**< \brief [29:29] Suspend State - SUSSTA (rh) */
    Ifx_UReg_32Bit reserved_30:2;     /**< \brief [31:30] \internal Reserved */
} Ifx_HSSL_OCS_Bits;

/** \brief Request Flags Register */
typedef struct _Ifx_HSSL_QFLAGS_Bits
{
    Ifx_UReg_32Bit I:4;               /**< \brief [3:0] Request Flags for Initiated Commands - I (rh) */
    Ifx_UReg_32Bit T:4;               /**< \brief [7:4] Request Flags for Commands Arrived at Target - T (rh) */
    Ifx_UReg_32Bit R:4;               /**< \brief [11:8] Request Flags for Response Frames at the Target - R (rh) */
    Ifx_UReg_32Bit reserved_12:4;     /**< \brief [15:12] \internal Reserved */
    Ifx_UReg_32Bit E0:2;              /**< \brief [17:16] Expect Flags for Activated Timeout Timer 0 - E0 (rh) */
    Ifx_UReg_32Bit E1:2;              /**< \brief [19:18] Expect Flags for Activated Timeout Timer 1 - E1 (rh) */
    Ifx_UReg_32Bit E2:2;              /**< \brief [21:20] Expect Flags for Activated Timeout Timer 2 - E2 (rh) */
    Ifx_UReg_32Bit E3:2;              /**< \brief [23:22] Expect Flags for Activated Timeout Timer 3 - E3 (rh) */
    Ifx_UReg_32Bit reserved_24:4;     /**< \brief [27:24] \internal Reserved */
    Ifx_UReg_32Bit IS:1;              /**< \brief [28:28] I Flag for Stream Frames - IS (rh) */
    Ifx_UReg_32Bit RS:1;              /**< \brief [29:29] R Flag for Stream Frames - RS (rh) */
    Ifx_UReg_32Bit TS:1;              /**< \brief [30:30] T Flag for Stream Frames - TS (rh) */
    Ifx_UReg_32Bit ES:1;              /**< \brief [31:31] E Flag for Stream Frames - ES (rh) */
} Ifx_HSSL_QFLAGS_Bits;

/** \brief Security Control Register */
typedef struct _Ifx_HSSL_SEC_Bits
{
    Ifx_UReg_32Bit LCK:1;             /**< \brief [0:0] Lock the HSSL Module - LCK (rw) */
    Ifx_UReg_32Bit LAW:1;             /**< \brief [1:1] Lock the Address Windows Registers - LAW (rw) */
    Ifx_UReg_32Bit reserved_2:30;     /**< \brief [31:2] \internal Reserved */
} Ifx_HSSL_SEC_Bits;

/** \brief Stream FIFOs Status Flags Register */
typedef struct _Ifx_HSSL_SFSFLAGS_Bits
{
    Ifx_UReg_32Bit RXFL:2;            /**< \brief [1:0] Stream RxFIFO Filling Level - RXFL (rh) */
    Ifx_UReg_32Bit TXFL:2;            /**< \brief [3:2] Stream TxFIFO Filling Level - TXFL (rh) */
    Ifx_UReg_32Bit EXFL:2;            /**< \brief [5:4] Stream Expect FIFO Filling Level - EXFL (rh) */
    Ifx_UReg_32Bit reserved_6:9;      /**< \brief [14:6] \internal Reserved */
    Ifx_UReg_32Bit ISF:1;             /**< \brief [15:15] Initiator Stream Frame Request - ISF (rh) */
    Ifx_UReg_32Bit reserved_16:16;    /**< \brief [31:16] \internal Reserved */
} Ifx_HSSL_SFSFLAGS_Bits;

/** \brief Target ID Address Register */
typedef struct _Ifx_HSSL_TIDADD_Bits
{
    Ifx_UReg_32Bit A:32;              /**< \brief [31:0] Address Pointer - A (rw) */
} Ifx_HSSL_TIDADD_Bits;

/** \brief Target Status Register */
typedef struct _Ifx_HSSL_TSTAT_Bits
{
    Ifx_UReg_32Bit LASTCC0:5;         /**< \brief [4:0] Last Command Code - LASTCC${x} (rh) */
    Ifx_UReg_32Bit LASTTT0:3;         /**< \brief [7:5] Last Transaction Tag - LASTTT${x} (rh) */
    Ifx_UReg_32Bit LASTCC1:5;         /**< \brief [12:8] Last Command Code - LASTCC${x} (rh) */
    Ifx_UReg_32Bit LASTTT1:3;         /**< \brief [15:13] Last Transaction Tag - LASTTT${x} (rh) */
    Ifx_UReg_32Bit LASTCC2:5;         /**< \brief [20:16] Last Command Code - LASTCC${x} (rh) */
    Ifx_UReg_32Bit LASTTT2:3;         /**< \brief [23:21] Last Transaction Tag - LASTTT${x} (rh) */
    Ifx_UReg_32Bit LASTCC3:5;         /**< \brief [28:24] Last Command Code - LASTCC${x} (rh) */
    Ifx_UReg_32Bit LASTTT3:3;         /**< \brief [31:29] Last Transaction Tag - LASTTT${x} (rh) */
} Ifx_HSSL_TSTAT_Bits;

/** \brief Target Stream Current Address Register */
typedef struct _Ifx_HSSL_TS_CA_Bits
{
    Ifx_UReg_32Bit reserved_0:5;      /**< \brief [4:0] \internal Reserved */
    Ifx_UReg_32Bit CURR:27;           /**< \brief [31:5] Address of the Memory Location for the Current Transfer - CURR (rh) */
} Ifx_HSSL_TS_CA_Bits;

/** \brief Target Stream Frame Count Register */
typedef struct _Ifx_HSSL_TS_FC_Bits
{
    Ifx_UReg_32Bit RELCOUNT:16;       /**< \brief [15:0] Reload Count Number - RELCOUNT (rw) */
    Ifx_UReg_32Bit CURCOUNT:16;       /**< \brief [31:16] Current Count Number - CURCOUNT (rh) */
} Ifx_HSSL_TS_FC_Bits;

/** \brief Target Stream Start Address Register ${x} */
typedef struct _Ifx_HSSL_TS_SA_Bits
{
    Ifx_UReg_32Bit reserved_0:5;      /**< \brief [4:0] \internal Reserved */
    Ifx_UReg_32Bit ADDR:27;           /**< \brief [31:5] Start Address for the Memory Range - ADDR (rw) */
} Ifx_HSSL_TS_SA_Bits;

/** \brief Target Current Address Register ${i} */
typedef struct _Ifx_HSSL_T_TCA_Bits
{
    Ifx_UReg_32Bit A:32;              /**< \brief [31:0] Address Part of the Payload of a Write Command Frame or a Read Command Frame or ID Frame - A (rh) */
} Ifx_HSSL_T_TCA_Bits;

/** \brief Target Current Data Register ${i} */
typedef struct _Ifx_HSSL_T_TCD_Bits
{
    Ifx_UReg_32Bit D:32;              /**< \brief [31:0] Data Part of the Payload of a Write Command Frame or Read Data of a Read Command Frame - D (rh) */
} Ifx_HSSL_T_TCD_Bits;

/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_hssl_union
 * \{   */
/** \brief Access Enable Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_ACCEN0_Bits B;           /**< \brief Bitfield access */
} Ifx_HSSL_ACCEN0;

/** \brief Access Enable Register 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_ACCEN1_Bits B;           /**< \brief Bitfield access */
} Ifx_HSSL_ACCEN1;

/** \brief Access Rules Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_AR_Bits B;               /**< \brief Bitfield access */
} Ifx_HSSL_AR;

/** \brief Access Window End Register ${i}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_AW_AWEND_Bits B;         /**< \brief Bitfield access */
} Ifx_HSSL_AW_AWEND;

/** \brief Access Window Start Register ${i}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_AW_AWSTART_Bits B;       /**< \brief Bitfield access */
} Ifx_HSSL_AW_AWSTART;

/** \brief Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_CFG_Bits B;              /**< \brief Bitfield access */
} Ifx_HSSL_CFG;

/** \brief Clock Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_CLC_Bits B;              /**< \brief Bitfield access */
} Ifx_HSSL_CLC;

/** \brief CRC Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_CRC_Bits B;              /**< \brief Bitfield access */
} Ifx_HSSL_CRC;

/** \brief Module Identification Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_ID_Bits B;               /**< \brief Bitfield access */
} Ifx_HSSL_ID;

/** \brief Initiator Stream Current Address Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_IS_CA_Bits B;            /**< \brief Bitfield access */
} Ifx_HSSL_IS_CA;

/** \brief Initiator Stream Frame Count Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_IS_FC_Bits B;            /**< \brief Bitfield access */
} Ifx_HSSL_IS_FC;

/** \brief Initiator Stream Start Address Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_IS_SA_Bits B;            /**< \brief Bitfield access */
} Ifx_HSSL_IS_SA;

/** \brief Initiator Control Data Register ${i}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_I_ICON_Bits B;           /**< \brief Bitfield access */
} Ifx_HSSL_I_ICON;

/** \brief Initiator Read Data Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_I_IRD_Bits B;            /**< \brief Bitfield access */
} Ifx_HSSL_I_IRD;

/** \brief Initiator Read Write Address Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_I_IRWA_Bits B;           /**< \brief Bitfield access */
} Ifx_HSSL_I_IRWA;

/** \brief Initiator Write Data Register ${i}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_I_IWD_Bits B;            /**< \brief Bitfield access */
} Ifx_HSSL_I_IWD;

/** \brief Kernel Reset Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_KRST0_Bits B;            /**< \brief Bitfield access */
} Ifx_HSSL_KRST0;

/** \brief Kernel Reset Register 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_KRST1_Bits B;            /**< \brief Bitfield access */
} Ifx_HSSL_KRST1;

/** \brief Kernel Reset Status Clear Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_KRSTCLR_Bits B;          /**< \brief Bitfield access */
} Ifx_HSSL_KRSTCLR;

/** \brief Miscellaneous Flags Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_MFLAGS_Bits B;           /**< \brief Bitfield access */
} Ifx_HSSL_MFLAGS;

/** \brief Miscellaneous Flags Clear Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_MFLAGSCL_Bits B;         /**< \brief Bitfield access */
} Ifx_HSSL_MFLAGSCL;

/** \brief Flags Enable Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_MFLAGSEN_Bits B;         /**< \brief Bitfield access */
} Ifx_HSSL_MFLAGSEN;

/** \brief Miscellaneous Flags Set Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_MFLAGSSET_Bits B;        /**< \brief Bitfield access */
} Ifx_HSSL_MFLAGSSET;

/** \brief Multi Slave Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_MSCR_Bits B;             /**< \brief Bitfield access */
} Ifx_HSSL_MSCR;

/** \brief OCDS Control and Status   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_OCS_Bits B;              /**< \brief Bitfield access */
} Ifx_HSSL_OCS;

/** \brief Request Flags Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_QFLAGS_Bits B;           /**< \brief Bitfield access */
} Ifx_HSSL_QFLAGS;

/** \brief Security Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_SEC_Bits B;              /**< \brief Bitfield access */
} Ifx_HSSL_SEC;

/** \brief Stream FIFOs Status Flags Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_SFSFLAGS_Bits B;         /**< \brief Bitfield access */
} Ifx_HSSL_SFSFLAGS;

/** \brief Target ID Address Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_TIDADD_Bits B;           /**< \brief Bitfield access */
} Ifx_HSSL_TIDADD;

/** \brief Target Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_TSTAT_Bits B;            /**< \brief Bitfield access */
} Ifx_HSSL_TSTAT;

/** \brief Target Stream Current Address Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_TS_CA_Bits B;            /**< \brief Bitfield access */
} Ifx_HSSL_TS_CA;

/** \brief Target Stream Frame Count Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_TS_FC_Bits B;            /**< \brief Bitfield access */
} Ifx_HSSL_TS_FC;

/** \brief Target Stream Start Address Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_TS_SA_Bits B;            /**< \brief Bitfield access */
} Ifx_HSSL_TS_SA;

/** \brief Target Current Address Register ${i}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_T_TCA_Bits B;            /**< \brief Bitfield access */
} Ifx_HSSL_T_TCA;

/** \brief Target Current Data Register ${i}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSSL_T_TCD_Bits B;            /**< \brief Bitfield access */
} Ifx_HSSL_T_TCD;

/** \}  */

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Hssl_I_struct
 * \{  */
/******************************************************************************/
/** \name Object L1
 * \{  */
/** \brief I object */
typedef volatile struct _Ifx_HSSL_I
{
       Ifx_HSSL_I_IWD                      IWD;                    /**< \brief 0, Initiator Write Data Register ${i}*/
       Ifx_HSSL_I_ICON                     ICON;                   /**< \brief 4, Initiator Control Data Register ${i}*/
       Ifx_HSSL_I_IRWA                     IRWA;                   /**< \brief 8, Initiator Read Write Address Register*/
       Ifx_HSSL_I_IRD                      IRD;                    /**< \brief C, Initiator Read Data Register*/
} Ifx_HSSL_I;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Hssl_T_struct
 * \{  */
/******************************************************************************/
/** \name Object L2
 * \{  */
/** \brief T object */
typedef volatile struct _Ifx_HSSL_T
{
       Ifx_HSSL_T_TCD                      TCD;                    /**< \brief 0, Target Current Data Register ${i}*/
       Ifx_HSSL_T_TCA                      TCA;                    /**< \brief 4, Target Current Address Register ${i}*/
} Ifx_HSSL_T;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Hssl_IS_struct
 * \{  */
/******************************************************************************/
/** \name Object L3
 * \{  */
/** \brief IS object */
typedef volatile struct _Ifx_HSSL_IS
{
       Ifx_HSSL_IS_SA                      SA[2];                  /**< \brief 0, Initiator Stream Start Address Register*/
       Ifx_HSSL_IS_CA                      CA;                     /**< \brief 8, Initiator Stream Current Address Register*/
       Ifx_HSSL_IS_FC                      FC;                     /**< \brief C, Initiator Stream Frame Count Register*/
} Ifx_HSSL_IS;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Hssl_TS_struct
 * \{  */
/******************************************************************************/
/** \name Object L4
 * \{  */
/** \brief TS object */
typedef volatile struct _Ifx_HSSL_TS
{
       Ifx_HSSL_TS_SA                      SA[2];                  /**< \brief 0, Target Stream Start Address Register ${x}*/
       Ifx_HSSL_TS_CA                      CA;                     /**< \brief 8, Target Stream Current Address Register*/
       Ifx_HSSL_TS_FC                      FC;                     /**< \brief C, Target Stream Frame Count Register*/
} Ifx_HSSL_TS;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Hssl_AW_struct
 * \{  */
/******************************************************************************/
/** \name Object L5
 * \{  */
/** \brief AW object */
typedef volatile struct _Ifx_HSSL_AW
{
       Ifx_HSSL_AW_AWSTART                 AWSTART;                /**< \brief 0, Access Window Start Register ${i}*/
       Ifx_HSSL_AW_AWEND                   AWEND;                  /**< \brief 4, Access Window End Register ${i}*/
} Ifx_HSSL_AW;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/** \addtogroup IfxLld_Hssl_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief HSSL object */
typedef volatile struct _Ifx_HSSL
{
       Ifx_HSSL_CLC                        CLC;                    /**< \brief 0, Clock Control Register*/
       Ifx_UReg_8Bit                       reserved_4[4];          /**< \brief 4, \internal Reserved */
       Ifx_HSSL_ID                         ID;                     /**< \brief 8, Module Identification Register*/
       Ifx_HSSL_CRC                        CRC;                    /**< \brief C, CRC Control Register*/
       Ifx_HSSL_CFG                        CFG;                    /**< \brief 10, Configuration Register*/
       Ifx_HSSL_QFLAGS                     QFLAGS;                 /**< \brief 14, Request Flags Register*/
       Ifx_HSSL_MFLAGS                     MFLAGS;                 /**< \brief 18, Miscellaneous Flags Register*/
       Ifx_HSSL_MFLAGSSET                  MFLAGSSET;              /**< \brief 1C, Miscellaneous Flags Set Register*/
       Ifx_HSSL_MFLAGSCL                   MFLAGSCL;               /**< \brief 20, Miscellaneous Flags Clear Register*/
       Ifx_HSSL_MFLAGSEN                   MFLAGSEN;               /**< \brief 24, Flags Enable Register*/
       Ifx_HSSL_SFSFLAGS                   SFSFLAGS;               /**< \brief 28, Stream FIFOs Status Flags Register*/
       Ifx_UReg_8Bit                       reserved_2C[4];         /**< \brief 2C, \internal Reserved */
       Ifx_HSSL_I                          I[4];                   /**< \brief 30, Initiator Read Data Register*/
       Ifx_HSSL_T                          T[4];                   /**< \brief 70, Target Current Address Register ${i}*/
       Ifx_HSSL_TSTAT                      TSTAT;                  /**< \brief 90, Target Status Register*/
       Ifx_HSSL_TIDADD                     TIDADD;                 /**< \brief 94, Target ID Address Register*/
       Ifx_HSSL_SEC                        SEC;                    /**< \brief 98, Security Control Register*/
       Ifx_HSSL_MSCR                       MSCR;                   /**< \brief 9C, Multi Slave Control Register*/
       Ifx_HSSL_IS                         IS;                     /**< \brief A0, Initiator Stream Frame Count Register*/
       Ifx_HSSL_TS                         TS;                     /**< \brief B0, Target Stream Frame Count Register*/
       Ifx_HSSL_AW                         AW[4];                  /**< \brief C0, Access Window End Register ${i}*/
       Ifx_HSSL_AR                         AR;                     /**< \brief E0, Access Rules Register*/
       Ifx_UReg_8Bit                       reserved_E4[4];         /**< \brief E4, \internal Reserved */
       Ifx_HSSL_OCS                        OCS;                    /**< \brief E8, OCDS Control and Status*/
       Ifx_HSSL_KRSTCLR                    KRSTCLR;                /**< \brief EC, Kernel Reset Status Clear Register*/
       Ifx_HSSL_KRST1                      KRST1;                  /**< \brief F0, Kernel Reset Register 1*/
       Ifx_HSSL_KRST0                      KRST0;                  /**< \brief F4, Kernel Reset Register 0*/
       Ifx_HSSL_ACCEN1                     ACCEN1;                 /**< \brief F8, Access Enable Register 1*/
       Ifx_HSSL_ACCEN0                     ACCEN0;                 /**< \brief FC, Access Enable Register 0*/
       Ifx_UReg_8Bit                       reserved_100[768];      /**< \brief 100, \internal Reserved */
} Ifx_HSSL;

/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXHSSL_REGDEF_H */
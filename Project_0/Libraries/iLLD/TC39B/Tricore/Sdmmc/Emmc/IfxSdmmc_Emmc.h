/**
 * \file IfxSdmmc_Emmc.h
 * \brief SDMMC EMMC details
 * \ingroup IfxLld_Sdmmc
 *
 * \version iLLD_1_0_1_15_0_1
 * \copyright Copyright (c) 2019 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * \defgroup IfxLld_Sdmmc_Emmc_Usage How to use the Sdmmc Driver Interface driver?
 * \ingroup IfxLld_Sdmmc_Emmc
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Sdmmc_Emmc_Preparation Preparation
 * \subsection IfxLld_Sdmmc_Emmc_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Sdmmc/Emmc/IfxSdmmc_Emmc.h>
 * \endcode
 *
 * \subsection IfxLld_Sdmmc_Emmc_Variables Variables
 *
 * Declare the Sdmmc handle and the Data buffers as global variables in your C code:
 *
 * \code
 * IfxSdmmc_Emmc handle;
 *
 * uint32 txData[8];
 * uint32 rxData[8];
 * uint32 sectorNumber;
 * \endcode
 *
 * \subsection IfxLld_Sdmmc_Emmc_Init Module Initialisation
 *
 * The module initialisation can be done as followed:
 * \code
 * // create config structure
 * IfxSdmmc_Emmc_Config config;
 * // fill the config structure with default values
 * IfxSdmmc_Emmc_initModuleConfig(&config, &MODULE_SDMMC0);
 *
 * {
 *     IfxSdmmc_Emmc_Pins pins;
 *     pins.clk = &IfxSdmmc0_CLK_P15_1_OUT;
 *     pins.cmd = &IfxSdmmc0_CMD_P15_3_INOUT;
 *     pins.dat0 = &IfxSdmmc0_DAT0_P20_7_INOUT;
 *     pins.dat1 = &IfxSdmmc0_DAT1_P20_8_INOUT;
 *     pins.dat2 = &IfxSdmmc0_DAT2_P20_10_INOUT;
 *     pins.dat3 = &IfxSdmmc0_DAT3_P20_11_INOUT;
 *     pins.dat4 = &IfxSdmmc0_DAT4_P20_12_INOUT;
 *     pins.dat5 = &IfxSdmmc0_DAT5_P20_13_INOUT;
 *     pins.dat6 = &IfxSdmmc0_DAT6_P20_14_INOUT;
 *     pins.dat7 = &IfxSdmmc0_DAT7_P15_0_INOUT;
 *     inputMode = IfxPort_InputMode_pullUp;
 *     pinDriver = IfxPort_PadDriver_cmosAutomotiveSpeed1;
 * }
 *
 * config.pins = &pins;
 *
 * // change bus width
 * config.cardConfig.dataWidth = IfxSdmmc_EmmcDataTransferWidth_1Bit;
 * // change speed mode
 * config.cardConfig.speedMode = IfxSdmmc_EmmcSpeedMode_legacy;
 *
 * config.useDma = FALSE;
 * // select DMA type if DMA is used
 * // config.dmaConfig.dmaType = IfxSdmmc_DmaType_sdma;
 *
 * // initialise the module
 * IfxSdmmc_Emmc_initModule(&handle, &config);
 * \endcode
 *
 * The SDMMC is ready for use now!
 *
 * \section IfxLld_Sdmmc_Emmc_DataTransfers Data Transfers
 * \subsection  IfxLld_Sdmmc_Emmc_DataTransfers_nonDma non DMA data transfers
 * \code
 * // prepare the data buffers
 * int i;
 * for (i = 0; i < 8; ++i)
 * {
 *     txData[i] = 0x1234000 + i;
 *     rxData[i] = 0;
 * }
 *
 * // specify the sector number of the card for data transfers
 * sectorNumber = 10;
 *
 * IfxSdmmc_Emmc_writeBlock(&handle, sectorNumber, txData);
 * IfxSdmmc_Emmc_readBlock(&handle, sectorNumber, rxData);
 * \endcode
 *
 * \subsection  IfxLld_Sdmmc_Sd_DataTransfers_sdma SDMA data transfers
 *
 * after selecting the DMA type in the module initialisation phase,
 * data transfers an be done as follows
 * \code
 * // prepare the data buffers
 * int i;
 * for (i = 0; i < 8; ++i)
 * {
 *     txData[i] = 0x1234000 + i;
 *     rxData[i] = 0;
 * }
 *
 * // specify the sector number of the card for data transfers
 * sectorNumber = 10;
 *
 * IfxSdmmc_Emmc_writeBlock(&handle, sectorNumber, txData);
 * IfxSdmmc_Emmc_readBlock(&handle, sectorNumber, rxData);
 * \endcode
 *
 * \subsection  IfxLld_Sdmmc_Sd_DataTransfers_adma2 ADMA2 data transfers
 *
 * after selecting the DMA type as ADMA2 in the module initialisation phase,
 * data transfers an be done as follows
 * \code
 * // the data buffers are assumed to be defined globally
 * // NUM_ADMA2_DESCRIPTORS and BUFF_LENGTH are also assumed to be defined globally
 * //uint32 txdata[NUM_ADMA2_DESCRIPTORS][BUFF_LENGTH];
 * //uint32 rxdata[NUM_ADMA2_DESCRIPTORS][BUFF_LENGTH];
 *
 * // prepare the data buffers
 * int i, j;
 * for (i = 0; i < NUM_ADMA2_DESCRIPTORS; ++i)
 * {
 *     for (j = 0; j < BUFF_LENGTH; ++i)
 *     {
 *         txData[i][j] = 0x1234000 + j;
 *         rxData[i][j] = 0;
 *     }
 * }
 *
 * // prepare ADMA2 descriptor table
 * // TX
 * IfxSdmmc_Adma2Descriptor adma2TxDescr[NUM_ADMA2_DESCRIPTORS];
 *
 * int i;
 * for (i=0; i<NUM_ADMA2_DESCRIPTORS; i++)
 * {
 *     adma2TxDescr[i].valid = 1;
 *     adma2TxDescr[i].act = IfxSdmmc_AdmaActionSymbol_tran;
 *     adma2TxDescr[i].length = IFXSDMMC_BLOCK_SIZE_DEFAULT;
 *     adma2TxDescr[i].address = (uint32)&txData[i][0];
 *
 *     // for the last descriptor line in table
 *     if (i == NUM_ADMA2_DESCRIPTORS - 1)
 *     {
 *         adma2TxDescr[i].end = 1; // set the END attribute
 *  adma2TxDescr[i].intEn = 1; // enable Interrupt after completion
 *     }
 * }
 *
 * // RX
 * IfxSdmmc_Adma2Descriptor adma2RxDescr[NUM_ADMA2_DESCRIPTORS];
 *
 * int i;
 * for (i=0; i<NUM_ADMA2_DESCRIPTORS; i++)
 * {
 *     adma2RxDescr[i].valid = 1;
 *     adma2RxDescr[i].act = IfxSdmmc_AdmaActionSymbol_tran;
 *     adma2RxDescr[i].length = IFXSDMMC_BLOCK_SIZE_DEFAULT;
 *     adma2RxDescr[i].address = (uint32)&rxData[i][0];
 *
 *     // for the last descriptor line in table
 *     if (i == NUM_ADMA2_DESCRIPTORS - 1)
 *     {
 *         adma2RxDescr[i].end = 1; // set the END attribute
 *  adma2RxDescr[i].intEn = 1; // enable Interrupt after completion
 *     }
 * }
 *
 * // specify the sector number of the card for data transfers
 * sectorNumber = 10;
 *
 * IfxSdmmc_Emmc_writeBlock(&handle, sectorNumber, adma2Descr);
 * IfxSdmmc_Emmc_readBlock(&handle, sectorNumber, adma2Descr);
 * \endcode
 *
 *
 * \defgroup IfxLld_Sdmmc_Emmc EMMC
 * \ingroup IfxLld_Sdmmc
 * \defgroup IfxLld_Sdmmc_Emmc_Data_Structures Data Structures
 * \ingroup IfxLld_Sdmmc_Emmc
 * \defgroup IfxLld_Sdmmc_Emmc_InitFunctions Initialisation Functions
 * \ingroup IfxLld_Sdmmc_Emmc
 * \defgroup IfxLld_Sdmmc_Emmc_CommandFunctions Command Functions
 * \ingroup IfxLld_Sdmmc_Emmc
 * \defgroup IfxLld_Sdmmc_Emmc_DataTransferFunctions Data Transfer Functions
 * \ingroup IfxLld_Sdmmc_Emmc
 * \defgroup IfxLld_Sdmmc_Emmc_supportFunctions Support Functions
 * \ingroup IfxLld_Sdmmc_Emmc
 */

#ifndef IFXSDMMC_EMMC_H
#define IFXSDMMC_EMMC_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Sdmmc/Std/IfxSdmmc.h"
#include "_PinMap/IfxSdmmc_PinMap.h"
#include "Scu/Std/IfxScuCcu.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Sdmmc_Emmc_Data_Structures
 * \{ */
/** \brief Configuration structure for SD Card
 */
typedef struct
{
    IfxSdmmc_EmmcDataTransferWidth dataWidth;       /**< \brief Data width for SD card transfers */
    IfxSdmmc_EmmcSpeedMode         speedMode;       /**< \brief Speed Mode for SD card transfers */
} IfxSdmmc_Emmc_CardConfig;

/** \brief Configuration structure for ADMA
 */
typedef struct
{
    IfxSdmmc_DmaType dmaType;       /**< \brief Type of DMA used for data transfers */
} IfxSdmmc_Emmc_DmaConfig;

/** \brief Configuration structure for Host
 */
typedef struct
{
    IfxSdmmc_DataLineTimeout timeoutValue;          /**< \brief The interval by which DAT line timeouts are detected */
    boolean                  usePresetValues;       /**< \brief Selection of whether to use automatic selection of SDCLK frequency and Driver strength Preset Value registers. */
    uint32                   frequency;             /**< \brief frequency select, clock divider will be calculated based on this */
} IfxSdmmc_Emmc_HostConfig;

/** \brief Configuration structure for SD card pins
 */
typedef struct
{
    IfxSdmmc_Clk_Out    *clk;             /**< \brief Clock out */
    IfxSdmmc_Cmd_InOut  *cmd;             /**< \brief Command */
    IfxSdmmc_Dat0_InOut *dat0;            /**< \brief Dat 0 */
    IfxSdmmc_Dat1_InOut *dat1;            /**< \brief Dat 1 */
    IfxSdmmc_Dat2_InOut *dat2;            /**< \brief Dat 2 */
    IfxSdmmc_Dat3_InOut *dat3;            /**< \brief Dat 3 */
    IfxSdmmc_Dat4_InOut *dat4;            /**< \brief Dat 4 */
    IfxSdmmc_Dat5_InOut *dat5;            /**< \brief Dat 5 */
    IfxSdmmc_Dat6_InOut *dat6;            /**< \brief Dat 6 */
    IfxSdmmc_Dat7_InOut *dat7;            /**< \brief Dat 7 */
    IfxPort_InputMode    inputMode;       /**< \brief Input Mod efor the IN pins */
    IfxPort_PadDriver    pinDriver;       /**< \brief Speed grade of the pins */
} IfxSdmmc_Emmc_Pins;

/** \} */

/** \addtogroup IfxLld_Sdmmc_Emmc_Data_Structures
 * \{ */
/** \brief handle of eMMC interface
 */
typedef struct
{
    Ifx_SDMMC        *sdmmcSFR;            /**< \brief pointer to register base address of SDMMC */
    boolean           flagF8;              /**< \brief f8 flag used during initialisation */
    IfxSdmmc_CardInfo cardInfo;            /**< \brief Card information */
    uint8             cardCapacity;        /**< \brief Card Capacity */
    uint8             cardState;           /**< \brief State of the card */
    boolean           dmaUsed;             /**< \brief Status of selection whether to use DMA for data transfers or not */
    IfxSdmmc_DmaType  dmaType;             /**< \brief Type of DMA used for data transfers */
    uint32            userFrequency;       /**< \brief Frequency of usage set by the user */
} IfxSdmmc_Emmc;

/** \brief Configuration Structure of SDMMC driver
 */
typedef struct
{
    Ifx_SDMMC               *sdmmcSFR;              /**< \brief pointer to register base address of SDMMC */
    IfxSdmmc_Emmc_HostConfig hostConfig;            /**< \brief Configuration structure for Host */
    IfxSdmmc_InterruptConfig interruptConfig;       /**< \brief Configuration structure for Normal and Error interrupts */
    IfxSdmmc_Emmc_Pins      *pins;                  /**< \brief Configuration structure for SD card pins */
    IfxSdmmc_Emmc_CardConfig cardConfig;            /**< \brief Configuration structure for SD card */
    boolean                  useDma;                /**< \brief selection of whether to use DMA for transfers or not */
    IfxSdmmc_Emmc_DmaConfig  dmaConfig;             /**< \brief Configuration structure for ADMA */
} IfxSdmmc_Emmc_Config;

/** \} */

/** \addtogroup IfxLld_Sdmmc_Emmc_InitFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initialises the eMMC card
 * \param emmc Handle for eMMC interface
 * \param cardConfig Configuration dtructure for eMMC card
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_initCard(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_CardConfig *cardConfig);

/** \brief Initialises the Host controller
 * \param emmc Handle for eMMC interface
 * \param hostConfig Configuration dtructure for Host Controller
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_initHostController(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_HostConfig *hostConfig);

/** \brief initialises the SDMMC module, both host interface and eMMC card
 * \param emmc Handle for eMMC interface
 * \param config Configuration structure of Emmc driver
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_initModule(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_Config *config);

/** \brief Filld the configuration structure with default values
 * \param config Configuration structure of Emmc driver
 * \param sdmmcSFR pointer to register base address of SDMMC
 * \return None
 */
IFX_EXTERN void IfxSdmmc_Emmc_initModuleConfig(IfxSdmmc_Emmc_Config *config, Ifx_SDMMC *sdmmcSFR);

/** \brief Sets up the eMMC card pins
 * \param emmc Handle for eMMC interface
 * \param pins Configuration dtructure for eMMC card Pins
 * \return None
 */
IFX_EXTERN void IfxSdmmc_Emmc_setupPins(IfxSdmmc_Emmc *emmc, IfxSdmmc_Emmc_Pins *pins);

/** \brief Switches the transfer bus width to 4bit wide
 * \param emmc Handle for eMMC interface
 * \param busWidth Data transfer width of eMMC card
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_switchBusWidth(IfxSdmmc_Emmc *emmc, IfxSdmmc_EmmcDataTransferWidth busWidth);

/** \brief Switches the Speed mode from Legacy to High speed Sdr
 * \param emmc Handle for eMMC interface
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_switchToHighSpeed(IfxSdmmc_Emmc *emmc);

/** \} */

/** \addtogroup IfxLld_Sdmmc_Emmc_DataTransferFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Reads data from Card
 * \param emmc Handle for eMMC interface
 * \param address Address where to read the data from
 * \param data Pointer of the buffer to read the data into
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_readBlock(IfxSdmmc_Emmc *emmc, uint32 address, uint32 *data);

/** \brief Transfers one block of data from Hostcontroller to Card or Vice versa using ADMA2
 * \param emmc Handle for eMMC interface
 * \param command Command to send
 * \param address Address where to send the data
 * \param blockSize Size of the block
 * \param descrAddress Pointer to the descriptor containing data to read/write
 * \param direction Transfer direction
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_singleBlockAdma2Transfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *descrAddress, IfxSdmmc_TransferDirection direction);

/** \brief Transfers one block of data from Hostcontroller to Card or Vice versa
 * \param emmc Handle for eMMC interface
 * \param command Command to send
 * \param address Address where to send the data
 * \param blockSize Size of the block
 * \param data Pointer of the buffer containing data to write
 * \param direction Transfer direction
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_singleBlockDmaTransfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *data, IfxSdmmc_TransferDirection direction);

/** \brief Transfers one block of data from Hostcontroller to Card or Vice versa
 * \param emmc Handle for eMMC interface
 * \param command Command to send
 * \param address Address where to send the data
 * \param blockSize Size of the block
 * \param data Pointer of the buffer containing data to write
 * \param direction Transfer direction
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_singleBlockTransfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint32 *data, IfxSdmmc_TransferDirection direction);

/** \brief Switches the card state to transferring state
 * \param emmc Handle for eMMC interface
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_switchToTransferState(IfxSdmmc_Emmc *emmc);

/** \brief Sends data from Hostcontroller to Card
 * \param emmc Handle for eMMC interface
 * \param address Address where to send the data
 * \param data Pointer of the buffer containing data to write
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_writeBlock(IfxSdmmc_Emmc *emmc, uint32 address, uint32 *data);

/** \brief API to read multiple blocks from EMMC card.
 * \param emmc Handle for emmc device
 * \param address Address to write to card
 * \param data pointer to data to be written
 * \param numBlocks number of blocks to bewritten
 * \return status of write
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_readMultiBlock(IfxSdmmc_Emmc *emmc, uint32 address, uint32 *data, uint32 numBlocks);

/** \brief API to write multiple blocks to EMMC card.
 * \param emmc Handle for emmc device
 * \param address Address to read from card
 * \param data pointer to data buffer in memory
 * \param numBlocks number of blocks to be read
 * \return status of read
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_writeMultiBlock(IfxSdmmc_Emmc *emmc, uint32 address, uint32 *data, uint32 numBlocks);

/** \brief API to transfer multiblocks between system memory and card. (polling method)
 * \param emmc Pointer to emmc device handle
 * \param command Command to be sent to card
 * \param address Address of card for data rx/tx
 * \param blockSize size of block to be transferred
 * \param numBlocks Number of blocks to be transferred
 * \param data Pointer to data
 * \param direction Direction (write/read)
 * \return Status of data transfer
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_multiBlockTransfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint16 numBlocks, uint32 *data, IfxSdmmc_TransferDirection direction);

/** \brief API to transfer multiblocks between system memory and card. (using ADMA2)
 * \param emmc Pointer to emmc device handle
 * \param command Command to be sent to card
 * \param address Address of card for data rx/tx
 * \param blockSize size of block to be transferred
 * \param numBlocks Number of blocks to be transferred
 * \param descrAddress Pointer to descriptor entry
 * \param direction Direction (write/read)
 * \return Status of data transfer
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_multiBlockAdma2Transfer(IfxSdmmc_Emmc *emmc, IfxSdmmc_Command command, uint32 address, uint16 blockSize, uint16 numBlocks, uint32 *descrAddress, IfxSdmmc_TransferDirection direction);

/** \} */

/** \addtogroup IfxLld_Sdmmc_Emmc_supportFunctions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Reads CID register of the card
 * \param emmc Handle for eMMC interface
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_readCid(IfxSdmmc_Emmc *emmc);

/** \brief Reads CID register of the card
 * \param emmc Handle for eMMC interface
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_readCsd(IfxSdmmc_Emmc *emmc);

/** \brief Sets RCA for the card
 * \param emmc Handle for eMMC interface
 * \param rca RCA for the card
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_setRca(IfxSdmmc_Emmc *emmc, uint16 rca);

/** \brief Reads CID register of the card
 * \param emmc Handle for eMMC interface
 * \return Status
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_validateAccessMode(IfxSdmmc_Emmc *emmc);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Erases blocks of data. Equivalent to a trim command.
 * Erases the data from start address to end address specified.
 * The addresses specify the block numbers and assume sector addressing.
 * If byte Addressing scheme is used for Card, specify the address after conversion to sector (512B) units.
 * Erase is not immediate by protocol - it happens at a later time.
 * \param emmc Pointer to base address of SDMMC SFR.
 * \param startAddress Start Address of the block to be erased.
 * \param endAddress End Address of the block to be erased
 * \return Status of execution
 */
IFX_EXTERN IfxSdmmc_Status IfxSdmmc_Emmc_eraseBlocks(IfxSdmmc_Emmc *emmc, uint32 startAddress, uint32 endAddress);

#endif /* IFXSDMMC_EMMC_H */

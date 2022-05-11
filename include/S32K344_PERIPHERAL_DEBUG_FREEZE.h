/*
** ###################################################################
**     Processor:           S32K344_M7
**     Reference manual:    S32K3xx RM Rev.1 Draft G
**     Version:             rev. 1.3, 2020-07-22
**     Build:               b200722
**
**     Abstract:
**         Peripheral Access Layer for S32K344_M7
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2020 NXP
**
**     NXP Confidential. This software is owned or controlled by NXP and may only be
**     used strictly in accordance with the applicable license terms. By expressly
**     accepting such terms or by downloading, installing, activating and/or otherwise
**     using the software, you are agreeing that you have read, and that you agree to
**     comply with and are bound by, such license terms. If you do not agree to be
**     bound by the applicable license terms, then you may not retain, install,
**     activate or otherwise use the software. The production use license in
**     Section 2.3 is expressly granted for this software.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
** ###################################################################
*/

/*!
 * @file S32K344_Peripheral_Debug_Freeze.h
 * @version 1.3
 * @date 2020-07-22
 * @brief Peripheral Access Layer for S32K344_Peripheral_Debug_Freeze
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32K344_Peripheral_Debug_Freeze_H_)  /* Check if memory map has not been already included */
#define S32K344_Peripheral_Debug_Freeze_H_

#include "S32K344_COMMON.h"

/* ----------------------------------------------------------------------------
   -- Peripheral_Debug_Freeze Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_Debug_Freeze_Peripheral_Access_Layer Peripheral_Debug_Freeze Peripheral Access Layer
 * @{
 */

/** Peripheral_Debug_Freeze - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[1300];
  __I  uint32_t CORE0_DBGFRZ_CTRL_GPR;             /**< Core 0 Debug Freeze Control, offset: 0x514 */
  uint8_t RESERVED_1[4];
  __I  uint32_t CORE1_DBGFRZ_CTRL_GPR;             /**< Core 1 Debug Freeze Control, offset: 0x51C */
} Peripheral_Debug_Freeze_Type, *Peripheral_Debug_Freeze_MemMapPtr;

/** Number of instances of the Peripheral_Debug_Freeze module. */
#define Peripheral_Debug_Freeze_INSTANCE_COUNT   (1u)

/* Peripheral_Debug_Freeze - Peripheral instance base addresses */
/** Peripheral PERIPHERAL_DEBUG_FREEZE base address */
#define PERIPHERAL_DEBUG_FREEZE_BASE             (0x402AC000u)
/** Peripheral PERIPHERAL_DEBUG_FREEZE base pointer */
#define PERIPHERAL_DEBUG_FREEZE                  ((Peripheral_Debug_Freeze_Type *)PERIPHERAL_DEBUG_FREEZE_BASE)
/** Array initializer of Peripheral_Debug_Freeze peripheral base addresses */
#define Peripheral_Debug_Freeze_BASE_ADDRS       { PERIPHERAL_DEBUG_FREEZE_BASE }
/** Array initializer of Peripheral_Debug_Freeze peripheral base pointers */
#define Peripheral_Debug_Freeze_BASE_PTRS        { PERIPHERAL_DEBUG_FREEZE }

/* ----------------------------------------------------------------------------
   -- Peripheral_Debug_Freeze Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_Debug_Freeze_Register_Masks Peripheral_Debug_Freeze Register Masks
 * @{
 */

/*! @name CORE0_DBGFRZ_CTRL_GPR - Core 0 Debug Freeze Control */
/*! @{ */
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EDMA_MASK (0x1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EDMA_SHIFT (0U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EDMA_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EDMA(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EDMA_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EDMA_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FCCU_MASK (0x2U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FCCU_SHIFT (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FCCU_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FCCU(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FCCU_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FCCU_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LCU0_MASK (0x4U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LCU0_SHIFT (2U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LCU0_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LCU0(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LCU0_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LCU0_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LCU1_MASK (0x8U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LCU1_SHIFT (3U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LCU1_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LCU1(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LCU1_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LCU1_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EMIOS0_MASK (0x10U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EMIOS0_SHIFT (4U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EMIOS0_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EMIOS0(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EMIOS0_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EMIOS0_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EMIOS1_MASK (0x20U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EMIOS1_SHIFT (5U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EMIOS1_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EMIOS1(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EMIOS1_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EMIOS1_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EMIOS2_MASK (0x40U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EMIOS2_SHIFT (6U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EMIOS2_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EMIOS2(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EMIOS2_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_EMIOS2_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_RTC_MASK (0x80U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_RTC_SHIFT (7U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_RTC_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_RTC(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_RTC_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_RTC_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SWT0_MASK (0x100U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SWT0_SHIFT (8U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SWT0_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SWT0(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SWT0_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SWT0_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SWT1_MASK (0x200U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SWT1_SHIFT (9U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SWT1_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SWT1(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SWT1_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SWT1_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_STM0_MASK (0x400U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_STM0_SHIFT (10U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_STM0_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_STM0(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_STM0_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_STM0_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_STM1_MASK (0x800U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_STM1_SHIFT (11U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_STM1_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_STM1(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_STM1_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_STM1_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_PIT0_MASK (0x1000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_PIT0_SHIFT (12U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_PIT0_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_PIT0(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_PIT0_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_PIT0_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_PIT1_MASK (0x2000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_PIT1_SHIFT (13U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_PIT1_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_PIT1(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_PIT1_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_PIT1_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_PIT2_MASK (0x4000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_PIT2_SHIFT (14U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_PIT2_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_PIT2(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_PIT2_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_PIT2_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI0_MASK (0x8000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI0_SHIFT (15U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI0_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI0(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI0_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI0_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI1_MASK (0x10000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI1_SHIFT (16U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI1_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI1_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI1_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI2_MASK (0x20000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI2_SHIFT (17U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI2_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI2(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI2_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI2_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI3_MASK (0x40000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI3_SHIFT (18U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI3_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI3(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI3_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI3_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI4_MASK (0x80000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI4_SHIFT (19U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI4_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI4(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI4_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI4_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI5_MASK (0x100000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI5_SHIFT (20U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI5_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI5(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI5_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPSPI5_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPI2C0_MASK (0x200000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPI2C0_SHIFT (21U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPI2C0_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPI2C0(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPI2C0_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPI2C0_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPI2C1_MASK (0x400000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPI2C1_SHIFT (22U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPI2C1_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPI2C1_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_LPI2C1_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXIO_MASK (0x800000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXIO_SHIFT (23U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXIO_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXIO(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXIO_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXIO_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN0_MASK (0x1000000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN0_SHIFT (24U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN0_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN0(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN0_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN0_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN1_MASK (0x2000000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN1_SHIFT (25U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN1_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN1(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN1_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN1_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN2_MASK (0x4000000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN2_SHIFT (26U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN2_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN2(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN2_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN2_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN3_MASK (0x8000000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN3_SHIFT (27U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN3_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN3(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN3_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN3_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN4_MASK (0x10000000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN4_SHIFT (28U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN4_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN4(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN4_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN4_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN5_MASK (0x20000000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN5_SHIFT (29U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN5_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN5(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN5_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_FLEXCAN5_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SAI0_MASK (0x40000000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SAI0_SHIFT (30U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SAI0_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SAI0(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SAI0_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SAI0_MASK)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SAI1_MASK (0x80000000U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SAI1_SHIFT (31U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SAI1_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SAI1(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SAI1_SHIFT)) & Peripheral_Debug_Freeze_CORE0_DBGFRZ_CTRL_GPR_SAI1_MASK)
/*! @} */

/*! @name CORE1_DBGFRZ_CTRL_GPR - Core 1 Debug Freeze Control */
/*! @{ */
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EDMA_MASK (0x1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EDMA_SHIFT (0U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EDMA_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EDMA(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EDMA_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EDMA_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FCCU_MASK (0x2U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FCCU_SHIFT (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FCCU_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FCCU(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FCCU_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FCCU_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LCU0_MASK (0x4U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LCU0_SHIFT (2U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LCU0_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LCU0(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LCU0_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LCU0_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LCU1_MASK (0x8U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LCU1_SHIFT (3U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LCU1_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LCU1(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LCU1_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LCU1_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EMIOS0_MASK (0x10U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EMIOS0_SHIFT (4U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EMIOS0_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EMIOS0(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EMIOS0_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EMIOS0_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EMIOS1_MASK (0x20U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EMIOS1_SHIFT (5U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EMIOS1_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EMIOS1(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EMIOS1_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EMIOS1_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EMIOS2_MASK (0x40U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EMIOS2_SHIFT (6U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EMIOS2_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EMIOS2(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EMIOS2_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_EMIOS2_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_RTC_MASK (0x80U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_RTC_SHIFT (7U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_RTC_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_RTC(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_RTC_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_RTC_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SWT0_MASK (0x100U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SWT0_SHIFT (8U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SWT0_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SWT0(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SWT0_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SWT0_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SWT1_MASK (0x200U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SWT1_SHIFT (9U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SWT1_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SWT1(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SWT1_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SWT1_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_STM0_MASK (0x400U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_STM0_SHIFT (10U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_STM0_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_STM0(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_STM0_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_STM0_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_STM1_MASK (0x800U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_STM1_SHIFT (11U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_STM1_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_STM1(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_STM1_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_STM1_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_PIT0_MASK (0x1000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_PIT0_SHIFT (12U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_PIT0_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_PIT0(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_PIT0_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_PIT0_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_PIT1_MASK (0x2000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_PIT1_SHIFT (13U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_PIT1_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_PIT1(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_PIT1_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_PIT1_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_PIT2_MASK (0x4000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_PIT2_SHIFT (14U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_PIT2_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_PIT2(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_PIT2_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_PIT2_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI0_MASK (0x8000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI0_SHIFT (15U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI0_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI0(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI0_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI0_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI1_MASK (0x10000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI1_SHIFT (16U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI1_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI1_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI1_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI2_MASK (0x20000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI2_SHIFT (17U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI2_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI2(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI2_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI2_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI3_MASK (0x40000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI3_SHIFT (18U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI3_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI3(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI3_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI3_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI4_MASK (0x80000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI4_SHIFT (19U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI4_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI4(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI4_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI4_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI5_MASK (0x100000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI5_SHIFT (20U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI5_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI5(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI5_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPSPI5_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPI2C0_MASK (0x200000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPI2C0_SHIFT (21U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPI2C0_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPI2C0(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPI2C0_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPI2C0_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPI2C1_MASK (0x400000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPI2C1_SHIFT (22U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPI2C1_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPI2C1_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_LPI2C1_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXIO_MASK (0x800000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXIO_SHIFT (23U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXIO_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXIO(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXIO_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXIO_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN0_MASK (0x1000000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN0_SHIFT (24U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN0_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN0(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN0_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN0_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN1_MASK (0x2000000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN1_SHIFT (25U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN1_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN1(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN1_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN1_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN2_MASK (0x4000000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN2_SHIFT (26U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN2_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN2(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN2_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN2_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN3_MASK (0x8000000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN3_SHIFT (27U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN3_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN3(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN3_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN3_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN4_MASK (0x10000000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN4_SHIFT (28U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN4_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN4(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN4_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN4_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN5_MASK (0x20000000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN5_SHIFT (29U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN5_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN5(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN5_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_FLEXCAN5_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SAI0_MASK (0x40000000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SAI0_SHIFT (30U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SAI0_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SAI0(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SAI0_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SAI0_MASK)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SAI1_MASK (0x80000000U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SAI1_SHIFT (31U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SAI1_WIDTH (1U)
#define Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SAI1(x) (((uint32_t)(((uint32_t)(x)) << Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SAI1_SHIFT)) & Peripheral_Debug_Freeze_CORE1_DBGFRZ_CTRL_GPR_SAI1_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group Peripheral_Debug_Freeze_Register_Masks */

/*!
 * @}
 */ /* end of group Peripheral_Debug_Freeze_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K344_Peripheral_Debug_Freeze_H_) */

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
 * @file S32K344_DCM.h
 * @version 1.3
 * @date 2020-07-22
 * @brief Peripheral Access Layer for S32K344_DCM
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
#if !defined(S32K344_DCM_H_)  /* Check if memory map has not been already included */
#define S32K344_DCM_H_

#include "S32K344_COMMON.h"

/* ----------------------------------------------------------------------------
   -- DCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCM_Peripheral_Access_Layer DCM Peripheral Access Layer
 * @{
 */

/** DCM - Size of Registers Arrays */
#define DCM_DCMSRR_COUNT                          1u

/** DCM - Register Layout Typedef */
typedef struct {
  __I  uint32_t DCMSTAT;                           /**< DCM Status, offset: 0x0 */
  __IO uint32_t DCMLCC;                            /**< LC and LC Control, offset: 0x4 */
  __IO uint32_t DCMLCS;                            /**< LC Scan Status, offset: 0x8 */
  uint8_t RESERVED_0[16];
  __IO uint32_t DCMMISC;                           /**< DCM Miscellaneous, offset: 0x1C */
  __I  uint32_t DCMDEB;                            /**< Debug Status and Configuration, offset: 0x20 */
  uint8_t RESERVED_1[8];
  __I  uint32_t DCMEC;                             /**< DCF Error Count, offset: 0x2C */
  __IO uint32_t DCMSRR[DCM_DCMSRR_COUNT];          /**< DCF Scan Report, array offset: 0x30, array step: 0x4 */
  uint8_t RESERVED_2[76];
  __IO uint32_t DCMLCS_2;                          /**< LC Scan Status 2, offset: 0x80 */
} DCM_Type, *DCM_MemMapPtr;

/** Number of instances of the DCM module. */
#define DCM_INSTANCE_COUNT                       (1u)

/* DCM - Peripheral instance base addresses */
/** Peripheral DCM base address */
#define DCM_BASE                                 (0x402AC000u)
/** Peripheral DCM base pointer */
#define DCM                                      ((DCM_Type *)DCM_BASE)
/** Array initializer of DCM peripheral base addresses */
#define DCM_BASE_ADDRS                           { DCM_BASE }
/** Array initializer of DCM peripheral base pointers */
#define DCM_BASE_PTRS                            { DCM }

/* ----------------------------------------------------------------------------
   -- DCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCM_Register_Masks DCM Register Masks
 * @{
 */

/*! @name DCMSTAT - DCM Status */
/*! @{ */
#define DCM_DCMSTAT_DCMDONE_MASK                 (0x1U)
#define DCM_DCMSTAT_DCMDONE_SHIFT                (0U)
#define DCM_DCMSTAT_DCMDONE_WIDTH                (1U)
#define DCM_DCMSTAT_DCMDONE(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSTAT_DCMDONE_SHIFT)) & DCM_DCMSTAT_DCMDONE_MASK)
#define DCM_DCMSTAT_DCMLCST_MASK                 (0x10U)
#define DCM_DCMSTAT_DCMLCST_SHIFT                (4U)
#define DCM_DCMSTAT_DCMLCST_WIDTH                (1U)
#define DCM_DCMSTAT_DCMLCST(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSTAT_DCMLCST_SHIFT)) & DCM_DCMSTAT_DCMLCST_MASK)
#define DCM_DCMSTAT_DCMOTAS_MASK                 (0x200U)
#define DCM_DCMSTAT_DCMOTAS_SHIFT                (9U)
#define DCM_DCMSTAT_DCMOTAS_WIDTH                (1U)
#define DCM_DCMSTAT_DCMOTAS(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSTAT_DCMOTAS_SHIFT)) & DCM_DCMSTAT_DCMOTAS_MASK)
#define DCM_DCMSTAT_DCMDBGPS_MASK                (0x400U)
#define DCM_DCMSTAT_DCMDBGPS_SHIFT               (10U)
#define DCM_DCMSTAT_DCMDBGPS_WIDTH               (1U)
#define DCM_DCMSTAT_DCMDBGPS(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSTAT_DCMDBGPS_SHIFT)) & DCM_DCMSTAT_DCMDBGPS_MASK)
#define DCM_DCMSTAT_DCMOTAA_MASK                 (0x10000U)
#define DCM_DCMSTAT_DCMOTAA_SHIFT                (16U)
#define DCM_DCMSTAT_DCMOTAA_WIDTH                (1U)
#define DCM_DCMSTAT_DCMOTAA(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSTAT_DCMOTAA_SHIFT)) & DCM_DCMSTAT_DCMOTAA_MASK)
#define DCM_DCMSTAT_DCMOTAR_MASK                 (0x20000U)
#define DCM_DCMSTAT_DCMOTAR_SHIFT                (17U)
#define DCM_DCMSTAT_DCMOTAR_WIDTH                (1U)
#define DCM_DCMSTAT_DCMOTAR(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSTAT_DCMOTAR_SHIFT)) & DCM_DCMSTAT_DCMOTAR_MASK)
/*! @} */

/*! @name DCMLCC - LC and LC Control */
/*! @{ */
#define DCM_DCMLCC_DCMCLC_MASK                   (0x7U)
#define DCM_DCMLCC_DCMCLC_SHIFT                  (0U)
#define DCM_DCMLCC_DCMCLC_WIDTH                  (3U)
#define DCM_DCMLCC_DCMCLC(x)                     (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCC_DCMCLC_SHIFT)) & DCM_DCMLCC_DCMCLC_MASK)
#define DCM_DCMLCC_DCMLCFN_MASK                  (0x8U)
#define DCM_DCMLCC_DCMLCFN_SHIFT                 (3U)
#define DCM_DCMLCC_DCMLCFN_WIDTH                 (1U)
#define DCM_DCMLCC_DCMLCFN(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCC_DCMLCFN_SHIFT)) & DCM_DCMLCC_DCMLCFN_MASK)
#define DCM_DCMLCC_DCMRLC_MASK                   (0x70U)
#define DCM_DCMLCC_DCMRLC_SHIFT                  (4U)
#define DCM_DCMLCC_DCMRLC_WIDTH                  (3U)
#define DCM_DCMLCC_DCMRLC(x)                     (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCC_DCMRLC_SHIFT)) & DCM_DCMLCC_DCMRLC_MASK)
#define DCM_DCMLCC_DCMFLC_MASK                   (0x300U)
#define DCM_DCMLCC_DCMFLC_SHIFT                  (8U)
#define DCM_DCMLCC_DCMFLC_WIDTH                  (2U)
#define DCM_DCMLCC_DCMFLC(x)                     (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCC_DCMFLC_SHIFT)) & DCM_DCMLCC_DCMFLC_MASK)
/*! @} */

/*! @name DCMLCS - LC Scan Status */
/*! @{ */
#define DCM_DCMLCS_DCMLCSS1_MASK                 (0x1U)
#define DCM_DCMLCS_DCMLCSS1_SHIFT                (0U)
#define DCM_DCMLCS_DCMLCSS1_WIDTH                (1U)
#define DCM_DCMLCS_DCMLCSS1(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCSS1_SHIFT)) & DCM_DCMLCS_DCMLCSS1_MASK)
#define DCM_DCMLCS_DCMLCC1_MASK                  (0xEU)
#define DCM_DCMLCS_DCMLCC1_SHIFT                 (1U)
#define DCM_DCMLCS_DCMLCC1_WIDTH                 (3U)
#define DCM_DCMLCS_DCMLCC1(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCC1_SHIFT)) & DCM_DCMLCS_DCMLCC1_MASK)
#define DCM_DCMLCS_DCMLCE1_MASK                  (0x10U)
#define DCM_DCMLCS_DCMLCE1_SHIFT                 (4U)
#define DCM_DCMLCS_DCMLCE1_WIDTH                 (1U)
#define DCM_DCMLCS_DCMLCE1(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCE1_SHIFT)) & DCM_DCMLCS_DCMLCE1_MASK)
#define DCM_DCMLCS_DCMLCFE1_MASK                 (0x20U)
#define DCM_DCMLCS_DCMLCFE1_SHIFT                (5U)
#define DCM_DCMLCS_DCMLCFE1_WIDTH                (1U)
#define DCM_DCMLCS_DCMLCFE1(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCFE1_SHIFT)) & DCM_DCMLCS_DCMLCFE1_MASK)
#define DCM_DCMLCS_DCMLCSS2_MASK                 (0x40U)
#define DCM_DCMLCS_DCMLCSS2_SHIFT                (6U)
#define DCM_DCMLCS_DCMLCSS2_WIDTH                (1U)
#define DCM_DCMLCS_DCMLCSS2(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCSS2_SHIFT)) & DCM_DCMLCS_DCMLCSS2_MASK)
#define DCM_DCMLCS_DCMLCC2_MASK                  (0x380U)
#define DCM_DCMLCS_DCMLCC2_SHIFT                 (7U)
#define DCM_DCMLCS_DCMLCC2_WIDTH                 (3U)
#define DCM_DCMLCS_DCMLCC2(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCC2_SHIFT)) & DCM_DCMLCS_DCMLCC2_MASK)
#define DCM_DCMLCS_DCMLCE2_MASK                  (0x400U)
#define DCM_DCMLCS_DCMLCE2_SHIFT                 (10U)
#define DCM_DCMLCS_DCMLCE2_WIDTH                 (1U)
#define DCM_DCMLCS_DCMLCE2(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCE2_SHIFT)) & DCM_DCMLCS_DCMLCE2_MASK)
#define DCM_DCMLCS_DCMLCFE2_MASK                 (0x800U)
#define DCM_DCMLCS_DCMLCFE2_SHIFT                (11U)
#define DCM_DCMLCS_DCMLCFE2_WIDTH                (1U)
#define DCM_DCMLCS_DCMLCFE2(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCFE2_SHIFT)) & DCM_DCMLCS_DCMLCFE2_MASK)
#define DCM_DCMLCS_DCMLCSS3_MASK                 (0x1000U)
#define DCM_DCMLCS_DCMLCSS3_SHIFT                (12U)
#define DCM_DCMLCS_DCMLCSS3_WIDTH                (1U)
#define DCM_DCMLCS_DCMLCSS3(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCSS3_SHIFT)) & DCM_DCMLCS_DCMLCSS3_MASK)
#define DCM_DCMLCS_DCMLCC3_MASK                  (0xE000U)
#define DCM_DCMLCS_DCMLCC3_SHIFT                 (13U)
#define DCM_DCMLCS_DCMLCC3_WIDTH                 (3U)
#define DCM_DCMLCS_DCMLCC3(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCC3_SHIFT)) & DCM_DCMLCS_DCMLCC3_MASK)
#define DCM_DCMLCS_DCMLCE3_MASK                  (0x10000U)
#define DCM_DCMLCS_DCMLCE3_SHIFT                 (16U)
#define DCM_DCMLCS_DCMLCE3_WIDTH                 (1U)
#define DCM_DCMLCS_DCMLCE3(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCE3_SHIFT)) & DCM_DCMLCS_DCMLCE3_MASK)
#define DCM_DCMLCS_DCMLCFE3_MASK                 (0x20000U)
#define DCM_DCMLCS_DCMLCFE3_SHIFT                (17U)
#define DCM_DCMLCS_DCMLCFE3_WIDTH                (1U)
#define DCM_DCMLCS_DCMLCFE3(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCFE3_SHIFT)) & DCM_DCMLCS_DCMLCFE3_MASK)
#define DCM_DCMLCS_DCMLCSS4_MASK                 (0x40000U)
#define DCM_DCMLCS_DCMLCSS4_SHIFT                (18U)
#define DCM_DCMLCS_DCMLCSS4_WIDTH                (1U)
#define DCM_DCMLCS_DCMLCSS4(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCSS4_SHIFT)) & DCM_DCMLCS_DCMLCSS4_MASK)
#define DCM_DCMLCS_DCMLCC4_MASK                  (0x380000U)
#define DCM_DCMLCS_DCMLCC4_SHIFT                 (19U)
#define DCM_DCMLCS_DCMLCC4_WIDTH                 (3U)
#define DCM_DCMLCS_DCMLCC4(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCC4_SHIFT)) & DCM_DCMLCS_DCMLCC4_MASK)
#define DCM_DCMLCS_DCMLCE4_MASK                  (0x400000U)
#define DCM_DCMLCS_DCMLCE4_SHIFT                 (22U)
#define DCM_DCMLCS_DCMLCE4_WIDTH                 (1U)
#define DCM_DCMLCS_DCMLCE4(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCE4_SHIFT)) & DCM_DCMLCS_DCMLCE4_MASK)
#define DCM_DCMLCS_DCMLCFE4_MASK                 (0x800000U)
#define DCM_DCMLCS_DCMLCFE4_SHIFT                (23U)
#define DCM_DCMLCS_DCMLCFE4_WIDTH                (1U)
#define DCM_DCMLCS_DCMLCFE4(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCFE4_SHIFT)) & DCM_DCMLCS_DCMLCFE4_MASK)
#define DCM_DCMLCS_DCMLCSS5_MASK                 (0x1000000U)
#define DCM_DCMLCS_DCMLCSS5_SHIFT                (24U)
#define DCM_DCMLCS_DCMLCSS5_WIDTH                (1U)
#define DCM_DCMLCS_DCMLCSS5(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCSS5_SHIFT)) & DCM_DCMLCS_DCMLCSS5_MASK)
#define DCM_DCMLCS_DCMLCC5_MASK                  (0xE000000U)
#define DCM_DCMLCS_DCMLCC5_SHIFT                 (25U)
#define DCM_DCMLCS_DCMLCC5_WIDTH                 (3U)
#define DCM_DCMLCS_DCMLCC5(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCC5_SHIFT)) & DCM_DCMLCS_DCMLCC5_MASK)
#define DCM_DCMLCS_DCMLCE5_MASK                  (0x10000000U)
#define DCM_DCMLCS_DCMLCE5_SHIFT                 (28U)
#define DCM_DCMLCS_DCMLCE5_WIDTH                 (1U)
#define DCM_DCMLCS_DCMLCE5(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCE5_SHIFT)) & DCM_DCMLCS_DCMLCE5_MASK)
#define DCM_DCMLCS_DCMLCFE5_MASK                 (0x20000000U)
#define DCM_DCMLCS_DCMLCFE5_SHIFT                (29U)
#define DCM_DCMLCS_DCMLCFE5_WIDTH                (1U)
#define DCM_DCMLCS_DCMLCFE5(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCFE5_SHIFT)) & DCM_DCMLCS_DCMLCFE5_MASK)
/*! @} */

/*! @name DCMMISC - DCM Miscellaneous */
/*! @{ */
#define DCM_DCMMISC_DCMDBGT_MASK                 (0x400U)
#define DCM_DCMMISC_DCMDBGT_SHIFT                (10U)
#define DCM_DCMMISC_DCMDBGT_WIDTH                (1U)
#define DCM_DCMMISC_DCMDBGT(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMMISC_DCMDBGT_SHIFT)) & DCM_DCMMISC_DCMDBGT_MASK)
#define DCM_DCMMISC_DCMCERS_MASK                 (0x10000000U)
#define DCM_DCMMISC_DCMCERS_SHIFT                (28U)
#define DCM_DCMMISC_DCMCERS_WIDTH                (1U)
#define DCM_DCMMISC_DCMCERS(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMMISC_DCMCERS_SHIFT)) & DCM_DCMMISC_DCMCERS_MASK)
#define DCM_DCMMISC_MRKLSTRCHK_MASK              (0x40000000U)
#define DCM_DCMMISC_MRKLSTRCHK_SHIFT             (30U)
#define DCM_DCMMISC_MRKLSTRCHK_WIDTH             (1U)
#define DCM_DCMMISC_MRKLSTRCHK(x)                (((uint32_t)(((uint32_t)(x)) << DCM_DCMMISC_MRKLSTRCHK_SHIFT)) & DCM_DCMMISC_MRKLSTRCHK_MASK)
/*! @} */

/*! @name DCMDEB - Debug Status and Configuration */
/*! @{ */
#define DCM_DCMDEB_DCM_APPDBG_STAT_MASK          (0x2U)
#define DCM_DCMDEB_DCM_APPDBG_STAT_SHIFT         (1U)
#define DCM_DCMDEB_DCM_APPDBG_STAT_WIDTH         (1U)
#define DCM_DCMDEB_DCM_APPDBG_STAT(x)            (((uint32_t)(((uint32_t)(x)) << DCM_DCMDEB_DCM_APPDBG_STAT_SHIFT)) & DCM_DCMDEB_DCM_APPDBG_STAT_MASK)
#define DCM_DCMDEB_APPDBG_STAT_SOC_MASK          (0x10000U)
#define DCM_DCMDEB_APPDBG_STAT_SOC_SHIFT         (16U)
#define DCM_DCMDEB_APPDBG_STAT_SOC_WIDTH         (1U)
#define DCM_DCMDEB_APPDBG_STAT_SOC(x)            (((uint32_t)(((uint32_t)(x)) << DCM_DCMDEB_APPDBG_STAT_SOC_SHIFT)) & DCM_DCMDEB_APPDBG_STAT_SOC_MASK)
/*! @} */

/*! @name DCMEC - DCF Error Count */
/*! @{ */
#define DCM_DCMEC_DCMECT_MASK                    (0xFFFFU)
#define DCM_DCMEC_DCMECT_SHIFT                   (0U)
#define DCM_DCMEC_DCMECT_WIDTH                   (16U)
#define DCM_DCMEC_DCMECT(x)                      (((uint32_t)(((uint32_t)(x)) << DCM_DCMEC_DCMECT_SHIFT)) & DCM_DCMEC_DCMECT_MASK)
/*! @} */

/*! @name DCMSRR - DCF Scan Report */
/*! @{ */
#define DCM_DCMSRR_DCMDCFE1_MASK                 (0x1FFFFFU)
#define DCM_DCMSRR_DCMDCFE1_SHIFT                (0U)
#define DCM_DCMSRR_DCMDCFE1_WIDTH                (21U)
#define DCM_DCMSRR_DCMDCFE1(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFE1_SHIFT)) & DCM_DCMSRR_DCMDCFE1_MASK)
#define DCM_DCMSRR_DCMDCFF1_MASK                 (0x7000000U)
#define DCM_DCMSRR_DCMDCFF1_SHIFT                (24U)
#define DCM_DCMSRR_DCMDCFF1_WIDTH                (3U)
#define DCM_DCMSRR_DCMDCFF1(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFF1_SHIFT)) & DCM_DCMSRR_DCMDCFF1_MASK)
#define DCM_DCMSRR_DCMESF1_MASK                  (0x8000000U)
#define DCM_DCMSRR_DCMESF1_SHIFT                 (27U)
#define DCM_DCMSRR_DCMESF1_WIDTH                 (1U)
#define DCM_DCMSRR_DCMESF1(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESF1_SHIFT)) & DCM_DCMSRR_DCMESF1_MASK)
#define DCM_DCMSRR_DCMESD1_MASK                  (0x10000000U)
#define DCM_DCMSRR_DCMESD1_SHIFT                 (28U)
#define DCM_DCMSRR_DCMESD1_WIDTH                 (1U)
#define DCM_DCMSRR_DCMESD1(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESD1_SHIFT)) & DCM_DCMSRR_DCMESD1_MASK)
#define DCM_DCMSRR_DCMDCFT1_MASK                 (0x20000000U)
#define DCM_DCMSRR_DCMDCFT1_SHIFT                (29U)
#define DCM_DCMSRR_DCMDCFT1_WIDTH                (1U)
#define DCM_DCMSRR_DCMDCFT1(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFT1_SHIFT)) & DCM_DCMSRR_DCMDCFT1_MASK)
/*! @} */

/*! @name DCMLCS_2 - LC Scan Status 2 */
/*! @{ */
#define DCM_DCMLCS_2_DCMLCSS6_MASK               (0x1U)
#define DCM_DCMLCS_2_DCMLCSS6_SHIFT              (0U)
#define DCM_DCMLCS_2_DCMLCSS6_WIDTH              (1U)
#define DCM_DCMLCS_2_DCMLCSS6(x)                 (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_2_DCMLCSS6_SHIFT)) & DCM_DCMLCS_2_DCMLCSS6_MASK)
#define DCM_DCMLCS_2_DCMLCC6_MASK                (0xEU)
#define DCM_DCMLCS_2_DCMLCC6_SHIFT               (1U)
#define DCM_DCMLCS_2_DCMLCC6_WIDTH               (3U)
#define DCM_DCMLCS_2_DCMLCC6(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_2_DCMLCC6_SHIFT)) & DCM_DCMLCS_2_DCMLCC6_MASK)
#define DCM_DCMLCS_2_DCMLCE6_MASK                (0x10U)
#define DCM_DCMLCS_2_DCMLCE6_SHIFT               (4U)
#define DCM_DCMLCS_2_DCMLCE6_WIDTH               (1U)
#define DCM_DCMLCS_2_DCMLCE6(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_2_DCMLCE6_SHIFT)) & DCM_DCMLCS_2_DCMLCE6_MASK)
#define DCM_DCMLCS_2_DCMLCFE6_MASK               (0x20U)
#define DCM_DCMLCS_2_DCMLCFE6_SHIFT              (5U)
#define DCM_DCMLCS_2_DCMLCFE6_WIDTH              (1U)
#define DCM_DCMLCS_2_DCMLCFE6(x)                 (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_2_DCMLCFE6_SHIFT)) & DCM_DCMLCS_2_DCMLCFE6_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group DCM_Register_Masks */

/*!
 * @}
 */ /* end of group DCM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K344_DCM_H_) */

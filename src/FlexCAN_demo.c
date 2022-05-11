#include "FlexCAN_demo.h"
#include "S32K344.h"

#define __IO volatile

/**
 * Message buffer bit field definition for CANFD frames of 64-byte payload
 */
typedef struct{
	struct {
	  __IO uint32_t TIMESTAMP  : 16;
	  __IO uint32_t DLC        : 4;
	  __IO uint32_t RTR        : 1;
	  __IO uint32_t IDE        : 1;
	  __IO uint32_t SRR        : 1;
			uint32_t            : 1;
	  __IO uint32_t CODE       : 4;
			uint32_t            : 1;
	  __IO uint32_t ESI        : 1;
	  __IO uint32_t BRS        : 1;
	  __IO uint32_t EDL        : 1;
	  __IO uint32_t EXT_ID     : 29;
	  __IO uint32_t PRIO       : 3;
	  __IO uint32_t PAYLOAD[16];
	} FD_MessageBuffer[7];
} CAN_MB_t;

/* Macros for accessing the previous bit field definitions for FlexCAN1 and FlexCAN4*/
#define CAN0_MB ((CAN_MB_t*) (CAN_0_BASE + 0x80) )
#define CAN4_MB ((CAN_MB_t*) (CAN_4_BASE + 0x80) )


void FlexCAN_Init(void)
{
    /* FIRC @48Mhz divider enable for FlexCAN0 */
    MC_CGM->MUX_3_DC_0 |= MC_CGM_MUX_3_DC_0_DE(1);

    /* FIRC @48Mhz divider enable for FlexCAN4 */
    MC_CGM->MUX_4_DC_0 |= MC_CGM_MUX_4_DC_0_DE(1);

    /* Peripheral clock gating to FleCAN0 and FlexCAN4 */
    MC_ME->PRTN1_COFB2_CLKEN |= MC_ME_PRTN1_COFB2_CLKEN_REQ65(1) | MC_ME_PRTN1_COFB2_CLKEN_REQ69(1);
    MC_ME->PRTN1_PCONF |= MC_ME_PRTN1_PCONF_PCE(1);
    MC_ME->PRTN1_PUPD |= MC_ME_PRTN1_PUPD_PCUD(1);
    MC_ME->CTL_KEY = 0x5AF0;
    MC_ME->CTL_KEY = 0xA50F;

    /* Poll for valid clock gatings */
    while(!(MC_ME->PRTN1_COFB2_STAT & MC_ME_PRTN1_COFB2_STAT_BLOCK65_MASK)){}
    while(!(MC_ME->PRTN1_COFB2_STAT & MC_ME_PRTN1_COFB2_STAT_BLOCK69_MASK)){}

    /* FlexCAN1 initialization, enable module and automatic transition to freeze mode */
    CAN_0->MCR &= ~FLEXCAN_MCR_MDIS_MASK;

    /* Poll for freeze mode entry */
    while(!(CAN_0->MCR & FLEXCAN_MCR_FRZACK_MASK));

    /*======= Initialization of FlexCAN memory for the error detection engine, refer to section 68.4.14 ============*/
    /* Unlock FlexCAN memory for writing */
    CAN_0->CTRL2 |= FLEXCAN_CTRL2_WRMFRZ(1);

    /* Initialize memory address 0x80 to 0xADF */
    for(uint32_t i = 0x80; i < 0xADF+1; i+=4)
    {
        *(uint32_t*)(CAN_0_BASE + i) = 0;
    }

    /* Initialize memory address 0xC20 to 0x31FF */
    for(uint32_t i = 0xC20; i < 0x31FF + 1; i+=4)
    {
        *(uint32_t*)(CAN_0_BASE + i) = 0;
    }

    /* Initialize other required registers */
    CAN_0->RXMGMASK = 0;
    CAN_0->RX14MASK = 0;
    CAN_0->RX15MASK = 0;
    CAN_0->RXFGMASK = 0;

    /* Clear any pending memory error flags */
    CAN_0->ERRSR = 0xFFFFFFFF;
    /*==============================================================================================================*/

    /* Enable CAN-FD operation mode */
    CAN_0->MCR |= FLEXCAN_MCR_FDEN(1);

    /* Enable ISO-11898-1 CAN-FD operation */
    CAN_0->CTRL2 |= FLEXCAN_CTRL2_ISOCANFDEN(1);

    /* Setup bit rate switch in data phase for transmission */
    /* Configure 64-bytes of payload per message buffer */
    CAN_0->FDCTRL |= FLEXCAN_FDCTRL_FDRATE(1) | FLEXCAN_FDCTRL_MBDSR0(3);

    /* Setup CAN bit timings for 500Kbit/s and 2Mbit/s in nominal and data phases, respectively */
    CAN_0->CBT |= FLEXCAN_CBT_BTF(1)      |
                      FLEXCAN_CBT_EPRESDIV(2) |
                      FLEXCAN_CBT_EPROPSEG(12)|
                      FLEXCAN_CBT_EPSEG1(11)  |
                      FLEXCAN_CBT_EPSEG2(5)   |
                      FLEXCAN_CBT_ERJW(5);

    CAN_0->FDCBT |= FLEXCAN_FDCBT_FPRESDIV(0) |
                        FLEXCAN_FDCBT_FPROPSEG(10)| /* Doesn't add 1 */
                        FLEXCAN_FDCBT_FPSEG1(8)   |
                        FLEXCAN_FDCBT_FPSEG2(3)   |
                        FLEXCAN_FDCBT_FRJW(6);

    /* Request exit from freeze mode */
    CAN_0->MCR &= ~FLEXCAN_MCR_FRZ_MASK;

    /* Poll for freeze mode exit */
    while(CAN_0->MCR & FLEXCAN_MCR_FRZACK_MASK);


    /* FlexCAN4 initialization, enable module and automatic transition to freeze mode */
    CAN_4->MCR &= ~FLEXCAN_MCR_MDIS_MASK;

    /* Poll for freeze mode entry */
    while(!(CAN_4->MCR & FLEXCAN_MCR_FRZACK_MASK));

    /*======= Initialization of FlexCAN memory for the error detection engine, refer to section 68.4.14 ============*/
    /* Unlock FlexCAN memory for writing */
    CAN_4->CTRL2 |= FLEXCAN_CTRL2_WRMFRZ(1);

    /* Initialize memory address 0x80 to 0xADF */
    for(uint32_t i = 0x80; i < 0xADF+1; i+=4)
    {
        *(uint32_t*)(CAN_4_BASE + i) = 0;
    }

    /* Initialize memory address 0xC20 to 0x31FF */
    for(uint32_t i = 0xC20; i < 0x31FF + 1; i+=4)
    {
        *(uint32_t*)(CAN_4_BASE + i) = 0;
    }

    /* Initialize other required registers */
    CAN_4->RXMGMASK = 0;
    CAN_4->RX14MASK = 0;
    CAN_4->RX15MASK = 0;
    CAN_4->RXFGMASK = 0;

    /* Clear any pending memory error flags */
    CAN_4->ERRSR = 0xFFFFFFFF;
    /*==============================================================================================================*/

    /* Enable CAN-FD operation mode */
    /* Enable Individual message buffer masking */
    CAN_4->MCR |= FLEXCAN_MCR_FDEN(1) | FLEXCAN_MCR_IRMQ(1);

    /* Enable the 32-bit High Resolution Time Stamp and configure it to capture in the EOF point */
    /* Enable ISO-11898-1 CAN-FD operation */
    CAN_4->CTRL2 |= FLEXCAN_CTRL2_TSTAMPCAP(1) | FLEXCAN_CTRL2_ISOCANFDEN(1);

    /* Configure 64-bytes of payload per message buffer */
    CAN_4->FDCTRL |= FLEXCAN_FDCTRL_MBDSR0(3);

    /* Setup CAN bit timings for 500Kbit/s and 2Mbit/s in nominal and data phases, respectively */
    CAN_4->CBT |= FLEXCAN_CBT_BTF(1)      |
                      FLEXCAN_CBT_EPRESDIV(2) |
                      FLEXCAN_CBT_EPROPSEG(12)|
                      FLEXCAN_CBT_EPSEG1(11)  |
                      FLEXCAN_CBT_EPSEG2(5)   |
                      FLEXCAN_CBT_ERJW(5);

    CAN_4->FDCBT |= FLEXCAN_FDCBT_FPRESDIV(0) |
                        FLEXCAN_FDCBT_FPROPSEG(10)| /* Doesn't add 1 */
                        FLEXCAN_FDCBT_FPSEG1(8)   |
                        FLEXCAN_FDCBT_FPSEG2(3)   |
                        FLEXCAN_FDCBT_FRJW(6);

    /* Request exit from freeze mode */
    CAN_4->MCR &= ~FLEXCAN_MCR_FRZ_MASK;

    /* Poll for freeze mode exit */
    while(CAN_4->MCR & FLEXCAN_MCR_FRZACK_MASK);

    return;

}

void SIUL2_PIN_MUX(void)
{
	/* FlexCAN0 RX, PTA6, SSS = 0b0010 */
	SIUL2->MSCR[6] |= SIUL2_MSCR_IBE(1);
	SIUL2->IMCR[0]  |= SIUL2_IMCR_SSS(2);

	/* FlexCAN0 TX, PTA7, SSS = 0b100 */
	SIUL2->MSCR[7] |= SIUL2_MSCR_OBE(1) | SIUL2_MSCR_SSS_2(1) | SIUL2_MSCR_SSS_1(0) | SIUL2_MSCR_SSS_0(0);

    /* FlexCAN4 RX, PTE14, SSS = 0b1 */
    SIUL2->MSCR[142] |= SIUL2_MSCR_IBE(1);
    SIUL2->IMCR[4]   |= SIUL2_IMCR_SSS(1);

    /* FlexCAN4 TX, PTE3, SSS = 0b1 */
    SIUL2->MSCR[131] |= SIUL2_MSCR_OBE(1) | SIUL2_MSCR_SSS_0(1);

    /* CAN0_EN PTC21 */
    SIUL2->MSCR[85] |= SIUL2_MSCR_OBE(1);
    SIUL2->GPDO85   |= SIUL2_GPDO85_PDO_n(1);

    /* CAN0_STB PTC20 */
    SIUL2->MSCR[84] |= SIUL2_MSCR_OBE(1);

    /* CAN1_EN PTD15 */
    SIUL2->MSCR[111] |= SIUL2_MSCR_OBE(1);
    SIUL2->GPDO111   |= SIUL2_GPDO111_PDO_n(1);

    /* CAN1_STB PTD13 */
    SIUL2->MSCR[109] |= SIUL2_MSCR_OBE(1);

    return;
}

void Stinger_TJA1153_Init(void)
{
   /**
    * The TJA1153 transceiver does not come ready to use as most CAN transceivers
    * It enters configuration mode initially if it has not been configured before,
    * in this initial state, it is ready for receiving additional security
    * setups such as an ID blacklist for example.
    *
    * In this example, the ID being transmitted is added to the CAN0 transceiver's
    * whitelist, other configurations are left as default.
    *
    * Refer to the NXP's TJA1153 data sheet for further detail.
    *
    */

    /* Allow configuration from local host via TXD pin for CAN0 transceiver, STB = 0 (Negated pin) */
	SIUL2->GPDO84 &= ~SIUL2_GPDO84_PDO_n_MASK;

    /* Auto bit rate detection initial CAN Classic frame with ID 0x555 for CAN0 */
    /* Filling of the frame's payload for transmission */
    CAN0_MB->FD_MessageBuffer[0].PAYLOAD[0] = 0;
    CAN0_MB->FD_MessageBuffer[0].PAYLOAD[1] = 0;

    /* Filling of the ID field and other setup bits, the FD structure is reused for a CAN Classic frame,
     * the only difference is that the Standard ID has to be left shifted by 18 */
    CAN0_MB->FD_MessageBuffer[0].EXT_ID = 0x555 << 18;;
    CAN0_MB->FD_MessageBuffer[0].EDL =  0;
    CAN0_MB->FD_MessageBuffer[0].BRS =  0;
    CAN0_MB->FD_MessageBuffer[0].ESI =  0;
    CAN0_MB->FD_MessageBuffer[0].SRR =  0;
    CAN0_MB->FD_MessageBuffer[0].IDE =  0;
    CAN0_MB->FD_MessageBuffer[0].RTR =  0;
    CAN0_MB->FD_MessageBuffer[0].DLC = 0x8;
    CAN0_MB->FD_MessageBuffer[0].CODE = 0xC; /* Frame is sent when this field is written */

    /* After a successful transmission the interrupt flag of the corresponding message buffer is set */
    while(!(CAN_0->IFLAG1 & FLEXCAN_IFLAG1_BUF0I_MASK)){}

    /* Write 1 to clear the previously set bit flag */
    CAN_0->IFLAG1 = FLEXCAN_IFLAG1_BUF0I(1);

    /* Filter Element Configuration (FEC) frame for setting up the transmission whitelist */
    uint32_t ID_Stinger = 0x18DA00F1;
    uint32_t PAYLOAD_FEC[2];
    uint8_t COMMAND_BYTE_FEC = 0x10;
    uint8_t DLC_FEC = 6;
    uint8_t Filter_Element_Index_0 = 0;
    uint8_t Filter_Element_Type = 1;
    uint8_t Extended_Filter_Config = 3; /* Both TWL and BBL */
    uint32_t ID_TX = 0xC0FFEE;

    /* Formation of the payload */
    uint32_t Filter_Element_Contents =  (Extended_Filter_Config << 29) | ID_TX ;

    PAYLOAD_FEC[0] = (COMMAND_BYTE_FEC << 24) | (Filter_Element_Index_0 << 16) |
                     (Filter_Element_Type << 15) | (Filter_Element_Contents >> 16);

    PAYLOAD_FEC[1] = (Filter_Element_Contents & 0xFFFF) << 16;

    /* Filling of the frame's payload for transmission */
    CAN0_MB->FD_MessageBuffer[0].PAYLOAD[0] = PAYLOAD_FEC[0];
    CAN0_MB->FD_MessageBuffer[0].PAYLOAD[1] = PAYLOAD_FEC[1];

    /* Filling of the ID field and other setup bits */
    CAN0_MB->FD_MessageBuffer[0].EXT_ID = ID_Stinger;
    CAN0_MB->FD_MessageBuffer[0].EDL =  0;
    CAN0_MB->FD_MessageBuffer[0].BRS =  0;
    CAN0_MB->FD_MessageBuffer[0].ESI =  0;
    CAN0_MB->FD_MessageBuffer[0].SRR =  0;
    CAN0_MB->FD_MessageBuffer[0].IDE =  1;
    CAN0_MB->FD_MessageBuffer[0].RTR =  0;
    CAN0_MB->FD_MessageBuffer[0].DLC = DLC_FEC;
    CAN0_MB->FD_MessageBuffer[0].CODE = 0xC; /* Frame is sent when this field is written */

    /* After a successful transmission the interrupt flag of the corresponding message buffer is set */
    while(!(CAN_0->IFLAG1 & FLEXCAN_IFLAG1_BUF0I_MASK)){}

    /* Write 1 to clear the previously set bit flag */
    CAN_0->IFLAG1 = FLEXCAN_IFLAG1_BUF0I(1);


    /* Last command frame for exiting configuration mode without writing to non-volatile memory nor
     * locking the transceiver, i.e. Development mode  */
    /* Filling of the frame's payload for transmission */
    CAN0_MB->FD_MessageBuffer[0].PAYLOAD[0] = 0x71020304;
    CAN0_MB->FD_MessageBuffer[0].PAYLOAD[1] = 0x05060708;

    /* Filling of the ID field and other setup bits */
    CAN0_MB->FD_MessageBuffer[0].EXT_ID = ID_Stinger;
    CAN0_MB->FD_MessageBuffer[0].EDL =  0;
    CAN0_MB->FD_MessageBuffer[0].BRS =  0;
    CAN0_MB->FD_MessageBuffer[0].ESI =  0;
    CAN0_MB->FD_MessageBuffer[0].SRR =  0;
    CAN0_MB->FD_MessageBuffer[0].IDE =  1;
    CAN0_MB->FD_MessageBuffer[0].RTR =  0;
    CAN0_MB->FD_MessageBuffer[0].DLC = 0x8;
    CAN0_MB->FD_MessageBuffer[0].CODE = 0xC; /* Frame is sent when this field is written */

    /* After a successful transmission the interrupt flag of the corresponding message buffer is set */
    while(!(CAN_0->IFLAG1 & FLEXCAN_IFLAG1_BUF0I_MASK)){}

    /* Write 1 to clear the previously set bit flag */
    CAN_0->IFLAG1 = FLEXCAN_IFLAG1_BUF0I(1);

    /* After the last frame, the transceiver exits configuration mode and goes to standby mode, exit
     * to normal operation mode is done by setting the STB pin of CAN0 transceiver to HIGH (pin is negated) */
    SIUL2->GPDO84 |= SIUL2_GPDO84_PDO_n(1);

    /* Allow configuration from local host via TXD pin for CAN1 transceiver, STB = 0 (Negated pin) */
    SIUL2->GPDO109 &= ~SIUL2_GPDO109_PDO_n_MASK;

    /* Auto bit rate detection initial CAN Classic frame with ID 0x555 for CAN1 */
    /* Filling of the frame's payload for transmission */
    CAN4_MB->FD_MessageBuffer[1].PAYLOAD[0] = 0;
    CAN4_MB->FD_MessageBuffer[1].PAYLOAD[1] = 0;

    /* Filling of the ID field and other setup bits, the FD structure is reused for a CAN Classic frame,
     * the only difference is that the Standard ID has to be left shifted by 18 */
    CAN4_MB->FD_MessageBuffer[1].EXT_ID = 0x555 << 18;;
    CAN4_MB->FD_MessageBuffer[1].EDL =  0;
    CAN4_MB->FD_MessageBuffer[1].BRS =  0;
    CAN4_MB->FD_MessageBuffer[1].ESI =  0;
    CAN4_MB->FD_MessageBuffer[1].SRR =  0;
    CAN4_MB->FD_MessageBuffer[1].IDE =  0;
    CAN4_MB->FD_MessageBuffer[1].RTR =  0;
    CAN4_MB->FD_MessageBuffer[1].DLC = 0x8;
    CAN4_MB->FD_MessageBuffer[1].CODE = 0xC; /* Frame is sent when this field is written */

    /* After a successful transmission the interrupt flag of the corresponding message buffer is set */
    while(!(CAN_4->IFLAG1 & FLEXCAN_IFLAG1_BUF4TO1I_MASK)){}

    /* Write 1 to clear the previously set bit flag */
    CAN_4->IFLAG1 = FLEXCAN_IFLAG1_BUF4TO1I(1);


    /* Last command frame for exiting configuration mode without writing to non-volatile memory nor
     * locking the transceiver, i.e. Development mode  */
    /* Filling of the frame's payload for transmission */
    CAN4_MB->FD_MessageBuffer[1].PAYLOAD[0] = 0x71020304;
    CAN4_MB->FD_MessageBuffer[1].PAYLOAD[1] = 0x05060708;

    /* Fill the ID field and other setup bits */
    CAN4_MB->FD_MessageBuffer[1].EXT_ID = ID_Stinger;
    CAN4_MB->FD_MessageBuffer[1].EDL =  0;
    CAN4_MB->FD_MessageBuffer[1].BRS =  0;
    CAN4_MB->FD_MessageBuffer[1].ESI =  0;
    CAN4_MB->FD_MessageBuffer[1].SRR =  0;
    CAN4_MB->FD_MessageBuffer[1].IDE =  1;
    CAN4_MB->FD_MessageBuffer[1].RTR =  0;
    CAN4_MB->FD_MessageBuffer[1].DLC = 0x8;
    CAN4_MB->FD_MessageBuffer[1].CODE = 0xC; /* Frame is sent when this field is written */

    /* After a successful transmission the interrupt flag of the corresponding message buffer is set */
    while(!(CAN_4->IFLAG1 & FLEXCAN_IFLAG1_BUF4TO1I_MASK)){}

    /* Write 1 to clear the previously set bit flag */
    CAN_4->IFLAG1 = FLEXCAN_IFLAG1_BUF4TO1I(1);

    /* After the last frame, the transceiver exits configuration mode and goes to standby mode, exit
     * to normal operation mode is done by setting the STB pin of CAN1 transceiver to HIGH (pin is negated) */
    SIUL2->GPDO109 |= SIUL2_GPDO109_PDO_n_MASK;

    return;

}

void FlexCAN4_Install_RX_ID(uint32_t ID)
{
    /* Request freeze mode entry for FlexCAN0 */
    CAN_4->MCR |= FLEXCAN_MCR_HALT(1) | FLEXCAN_MCR_FRZ(1);

    /* Poll for freeze mode entry */
    while(!(CAN_4->MCR & FLEXCAN_MCR_FRZACK_MASK));

    /* Setup reception mask to all-care bits of 29-bit extended ID */
    CAN_4->RXIMR[0] = 0x1FFFFFFF;

    /* Setup Message Buffer 0 for reception of frames with the parameter extended ID */
    CAN4_MB->FD_MessageBuffer[0].EDL = 1;
    CAN4_MB->FD_MessageBuffer[0].BRS = 1;
    CAN4_MB->FD_MessageBuffer[0].ESI = 0;
    CAN4_MB->FD_MessageBuffer[0].CODE = 4;
    CAN4_MB->FD_MessageBuffer[0].SRR = 0;
    CAN4_MB->FD_MessageBuffer[0].IDE = 1;
    CAN4_MB->FD_MessageBuffer[0].RTR = 0;

    CAN4_MB->FD_MessageBuffer[0].EXT_ID = ID;

    /* Request exit from freeze mode */
    CAN_4->MCR &= ~FLEXCAN_MCR_FRZ_MASK;

    /* Poll for freeze mode exit */
    while(CAN_4->MCR & FLEXCAN_MCR_FRZACK_MASK);

    return;
}


status_t FlexCAN4_Read_Frame(frame_t* out_frame)
{
    /* Poll Message Buffer 0 reception flag */
    while(!(CAN_4->IFLAG1 & FLEXCAN_IFLAG1_BUF0I_MASK)){};

    /* Harvest the ID field of the received frame */
    out_frame->ID = CAN4_MB->FD_MessageBuffer[0].EXT_ID;

    /* Harvest the 32-bit high resolution time-stamp */
    out_frame->HIGH_RES_TIMESTAMP = CAN_4->HR_TIME_STAMP[0];

    /* Harvest the payload of the received frame */
    for(uint8_t i = 0; i<16; i++)
    {
        out_frame->PAYLOAD[i] = CAN4_MB->FD_MessageBuffer[0].PAYLOAD[i];
    }

    /* Clear IFLAG1 flag for message buffer 0 (W1C) */
    CAN_4->IFLAG1 = FLEXCAN_IFLAG1_BUF0I(1);

	return SUCCESS;
}

status_t FlexCAN0_Transmit_Frame(frame_t* in_frame)
{
    /* Fill the frame's payload for transmission */
    for(uint8_t i = 0; i<16; i++)
    {
        CAN0_MB->FD_MessageBuffer[0].PAYLOAD[i] = in_frame->PAYLOAD[i];
    }

    /* Fill the ID field and other setup bits */
    CAN0_MB->FD_MessageBuffer[0].EXT_ID = in_frame->ID;
    CAN0_MB->FD_MessageBuffer[0].EDL =  1;
    CAN0_MB->FD_MessageBuffer[0].BRS =  1;
    CAN0_MB->FD_MessageBuffer[0].ESI =  0;
    CAN0_MB->FD_MessageBuffer[0].SRR =  0;
    CAN0_MB->FD_MessageBuffer[0].IDE =  1;
    CAN0_MB->FD_MessageBuffer[0].RTR =  0;
    CAN0_MB->FD_MessageBuffer[0].DLC = 0xF;
    CAN0_MB->FD_MessageBuffer[0].CODE = 0xC; /* Frame is sent when this field is written */

    /* After a successful transmission the interrupt flag of the corresponding message buffer is set */
    while(!(CAN_0->IFLAG1 & FLEXCAN_IFLAG1_BUF0I_MASK)){}

    /* Write 1 to clear the previously set bit flag */
    CAN_0->IFLAG1 = FLEXCAN_IFLAG1_BUF0I(1);

	return SUCCESS;
}

void Green_LED_Init(void)
{
    /* Enable output buffer for RGBLED0_GREEN @ PTA30 */
    SIUL2->MSCR[30] |= SIUL2_MSCR_OBE(1);

    return;
}

void Green_LED_Toggle(void)
{

    SIUL2->GPDO30 ^= SIUL2_GPDO30_PDO_n_MASK;
    return;
}

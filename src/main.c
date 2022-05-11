/**
 * FlexCAN demo for the usage of CAN-FD in the S32K434 Customer EVB with TJA1153 Stinger transceivers
 *
 * This demo uses FlexCAN instance 5 to continuously transmit a CANFD frame at 500Kbit/s and 2Mbit/s, then
 * receives it with FlexCAN instance 4 by polling, finally it toggles a LED each TOGGLE_COUNT number
 * of frames received.
 *
 * The board needs to be reconnected from the power supply in each reset/debug session for the TJA1153
 * transceivers to be properly reset for this demo.
 *
 * Pin-out is set as next:
 *     FLEXCAN0_TX @ PTC7 for CAN0_TX signal in board
 *     FLEXCAN0_RX @ PTC6 for CAN0_RX signal in board
 *
 *     FLEXCAN4_TX @ PTE3  for CAN1_TX signal in board
 *     FLEXCAN4_RX @ PTE14 for CAN1_RX signal in board
 *
 *     RGBLED0_GREEN @ PTA30
 *
 *     CAN0_EN  PTC21
 *     CAN0_STB PTC20
 *     CAN1_EN  PTD15
 *     CAN1_STB PTD13
 *
 * @author abraham.rodriguez@nxp.com
 * @date 15/Sept/20
 *
 */
#include "FlexCAN_demo.h"
#include "stdint.h"

/* Macros for the ID to install as RX in FLEXCAN4 and to use for transmission by FlexCAN5 */
#define DEMO_ID	     (0xC0FFEE)
/* Macro for the received frame's count for toggling an indication LED */
#define TOGGLE_COUNT (1000U)

/* Variables for the reception and transmission mechanism */
frame_t bounce_frame;
uint32_t reception_count = 0;
status_t status;

int main(void)
{

/* Initialization of the frame's ID, and a dummy payload at the last payload word */
bounce_frame.ID = DEMO_ID;
bounce_frame.PAYLOAD[15] = 0x11223344;

/* Initialization of FlexCAN1 and FlexCAN4 */
FlexCAN_Init();

/* Pin multiplexing for the required pins for FleCAN and transceivers */
SIUL2_PIN_MUX();

/* CAN Transceiver Initialization */
Stinger_TJA1153_Init();

/* Install of ID in a message buffer for reception in FlexCAN4 */
FlexCAN4_Install_RX_ID( DEMO_ID );

Green_LED_Init();

/* Initial transmission */
status = FlexCAN0_Transmit_Frame(&bounce_frame);

/* Super-loop for continuous frame reception and retransmission */
for(;;)
{
	status = FlexCAN4_Read_Frame(&bounce_frame);

	if(status)
	{
		reception_count++;

		if(TOGGLE_COUNT == reception_count)
		{
			Green_LED_Toggle();
			reception_count = 0;
		}

		status = FlexCAN0_Transmit_Frame(&bounce_frame);
	}
}

}

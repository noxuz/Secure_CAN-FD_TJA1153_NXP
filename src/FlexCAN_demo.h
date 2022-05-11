#ifndef FLEXCAN_DEMO_H_
#define FLEXCAN_DEMO_H_

#include "stdint.h"

/**
 * CAN-FD frame type definition for a 64-byte payload and a 32-bit high resolution time-stamp
 */
typedef struct{
	uint32_t ID;
	uint32_t HIGH_RES_TIMESTAMP;
    uint32_t PAYLOAD[16];
} frame_t;

/*  */
typedef enum{
	SUCCESS = 1,
} status_t;

/**
 * Function for initializing FlexCAN4 for the reception of CAN-FD frames and FlexCAN1 for transmission
 */
void FlexCAN_Init(void);

/**
 * Function for setting up the multiplexing required for FlexCAN1, FlexCAN4 and the TJA1153 transceiver's
 * ENABLE and STANDBY pins.
 */
void SIUL2_PIN_MUX(void);

/**
 * Function for initializing both TJA1153 Stinger Secure CAN transceivers found in the board, since they don't
 * come ready to use (Vanilla)
 */
void Stinger_TJA1153_Init(void);

/**
 * Function for configuring a reception Message Buffer ID in FlexCAN4, mask is set to all 1's, i.e. all-care.
 */
void FlexCAN4_Install_RX_ID(uint32_t ID);

/**
 * Function for reading a received CANFD frame from the Message Buffer 0 of FlexCAN4.
 * @return SUCCESS If a frame was read without errors
 */
status_t FlexCAN4_Read_Frame(frame_t* out_frame);

/**
 * Function for transmitting a CANFD frame throughout FlexCAN0 Message Buffer 0.
 * @return SUCCESS If the frame was sent successfully
 */
status_t FlexCAN0_Transmit_Frame(frame_t* in_frame);

/**
 * Function for initializing a frame reception indicative green LED, RGBLED0_GREEN @ PTA30.
 */
void Green_LED_Init(void);

/**
 * Function for toggling a green LED.
 */
void Green_LED_Toggle(void);

#endif /* FLEXCAN_DEMO_H_ */

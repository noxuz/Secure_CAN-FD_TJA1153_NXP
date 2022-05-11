# Secure-CAN-FD-TJA1153-NXP-demo
Demo for last generation CAN-FD transceiver with security features such as flooding and spoofing protection, running on NXP S32K344 mcu

FlexCAN demo for the usage of CAN-FD in the S32K434 Customer EVB with TJA1153 Stinger transceivers

This demo uses FlexCAN instance 5 to continuously transmit a CANFD frame at 500Kbit/s and 2Mbit/s, then
receives it with FlexCAN instance 4 by polling, finally it toggles a LED each TOGGLE_COUNT number
of frames received.

The board needs to be reconnected from the power supply in each reset/debug session for the TJA1153
transceivers to be properly reset for this demo.

More info at https://www.nxp.com/products/interfaces/can-transceivers/secure-can-transceivers/secure-hs-can-transceiver-with-standby-mode:TJA1152

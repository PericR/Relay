/**
 **************************************************
 *
 * @file        RelayControl4CH.ino
 * @brief       Relay control example to show how to control 4 channel relay using easyC comunication
 *
 *              Product: solde.red/333216
 *
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/

// Include our CH_Relay library
#include "Relays-SOLDERED.h"

#define RELAY_ADDRESS 0x30

CH_Relay Relay;

void setup()
{
    Relay.begin(RELAY_ADDRESS); // Set address on relay hardware switch using provided addresses and here (0x30 - 0x37)
                                // If there are more sensors/breakout boards are connected with same address,
                                // it is needed to change address in order to have normal I2C communication.
                                // Every end device should have unique address on same bus
}

void loop()
{
    // Turn on relay 1
    Relay.relayControl(CHANNEL1, HIGH);
    delay(1500);

    // Turn off relay 1
    Relay.relayControl(CHANNEL1, LOW);
    delay(1500);

    // Turn on relay 2
    Relay.relayControl(CHANNEL2, HIGH);
    delay(1500);

    // Turn off relay 2
    Relay.relayControl(CHANNEL2, LOW);
    delay(1500);

    // Turn on relay 3
    Relay.relayControl(CHANNEL3, HIGH);
    delay(1500);

    // Turn off relay 3
    Relay.relayControl(CHANNEL3, LOW);
    delay(1500);

    // Turn on relay 4
    Relay.relayControl(CHANNEL4, HIGH);
    delay(1500);

    // Turn off relay 4
    Relay.relayControl(CHANNEL4, LOW);
    delay(1500);
}

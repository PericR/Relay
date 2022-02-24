/**
 **************************************************
 *
 * @file        RelayControl1CH.ino
 * @brief       Relay control example to show how to control 1 channel relay using easyC comunication
 *  
 *              Product:  solde.red/333021
 *
 * @authors     Robert Peric @ soldered.com
 ***************************************************/

//Include our CH_Relay library
#include "Relay-SOLDERED.h"

#define RELAY_ADDRESS  0x32

CH_Relay Relay;

void setup()
{    
    Relay.begin(RELAY_ADDRESS); //Set address on relay hardware switch using provided addresses and here (0x30 - 0x37)
                                //If there are more sensors/breakout boards are connected with same address,
                                // it is needed to change address in order to have normal I2C communication.
                                // Every end device should have unique address on same bus
}

void loop()
{
    //Turn on relay
    Relay.relayControl(CHANNEL1, HIGH);
    delay(1500);

    //Turn off relay
    Relay.relayControl(CHANNEL1, LOW);
    delay(1500);
}

/**
 **************************************************
 *
 * @file        RelayControl.ino
 * @brief       Relay control example to show how to control 1 channel relay using easyC comunication
 *
 *
 *
 * @authors     Robert Peric @ soldered.com
 ***************************************************/

//Include our CH_Reley library
#include "Relay-SOLDERED.h"

CH_Relay Relay;

void setup()
{
    Serial.begin(9600);
    
    //Set address on relay hardware switch using provided addresses and here (0x30 - 0x37)
    Relay.begin(0x32);
}

void loop()
{
    //For 2 channeled relays use CHANNEL1_PIN CHANNEL2_PIN

    //Turn on channel1
    Relay.relayControl(CHANNEL1_PIN, HIGH);
    delay(1500);

    //Turn off channel 1    
    Relay.relayControl(CHANNEL1_PIN, LOW);
    delay(1500);
}

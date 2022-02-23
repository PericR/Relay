/**
 **************************************************
 *
 * @file        RelayControl2CHNative.ino
 * @brief       Relay control example to show how to control 2 channel relay board
 *
 *
 *
 * @authors     Robert Peric @ soldered.com
 ***************************************************/

//Connecting diagram
//Breakout      Arduino
//|-------------|
//IN1-----------9
//IN2-----------10
//GND-----------GND
//VCC-----------5V

//Include our CH_Reley library
#include "Relay-SOLDERED.h"

#define RELAY1_PIN 9
#define RELAY2_PIN 10

CH_Relay Relay(RELAY1_PIN, RELAY2_PIN); //Here is needed to specify the pins on which relays are connected 

void setup()
{
    Relay.begin(); //Initialize relay
}

void loop()
{
    //Turn on relay 1
    Relay.relayControl(CHANNEL1, HIGH);
    delay(1500);

    //Turn off relay 1
    Relay.relayControl(CHANNEL1, LOW);
    delay(1500);

    //Turn on relay 2
    Relay.relayControl(CHANNEL2, HIGH);
    delay(1500);

    //Turn off relay 2
    Relay.relayControl(CHANNEL2, LOW);
    delay(1500);
}

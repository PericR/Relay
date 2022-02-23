/**
 **************************************************
 *
 * @file        RelayControl1CHNative.ino
 * @brief       Relay control example to show how to control 1 channel relay board
 *
 *
 *
 * @authors     Robert Peric @ soldered.com
 ***************************************************/

 //Connecting diagram
//Breakout      Arduino
//|-------------|
//IN------------9
//GND-----------GND
//VCC-----------5V

//Include our CH_Relay library
#include "Relay-SOLDERED.h"

#define RELAY_PIN  9

CH_Relay Relay(RELAY_PIN); //Here is needed to specify the pin on which relay is connected 

void setup()
{    
    Relay.begin(); //Initialize relay
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

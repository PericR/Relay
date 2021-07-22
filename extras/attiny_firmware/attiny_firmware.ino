/**
 **************************************************
 *
 * @file        Template for attiny_firmware
 * @brief       This is firmwire for controling relay board with easyC comunication.
 *
 * @authors     @ soldered.com
 ***************************************************/

#include "easyC.h"
#include <Wire.h>
#include "Relay_Firmwire.h"

int addr = DEFAULT_ADDRESS;

Relay_Firmwire chRelay;

void setup()
{
    //Initialises address pins and sets i2c address
    initDefault();
    addr = getI2CAddress();

    Wire.begin(addr);
    Wire.onReceive(receiveEvent);

    chRelay.begin();
}

void loop()
{
}


void receiveEvent(int howMany)
{
    uint8_t data[2];
    while (1 < Wire.available())
    {
        char c = Wire.read();
        data[0] = c;
    }

    char c = Wire.read();
    data[1] = c;
    
    //data[0] == channel, data[1] == mode
    chRelay.controlRelay(data[0], data[1]);
}
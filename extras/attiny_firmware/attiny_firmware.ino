/**
 **************************************************
 *
 * @file        attiny_firmware.ino
 * @brief       This is firmwire for controling relay board with easyC comunication.
 *
 * @authors     @ soldered.com
 ***************************************************/

#include "easyC.h"
#include <Wire.h>
#include "attiny_firmware.h"

// Default address is 0x30
int addr = DEFAULT_ADDRESS; 

// Create object for relay firmware
Relay_Firmwire chRelay;

void setup()
{
    //Initialises address pins and sets i2c address
    initDefault();
    addr = getI2CAddress();

    // Init I2C communication
    Wire.begin(addr);
    Wire.onReceive(receiveEvent);

    // Begin function sets channel pins as outputs
    chRelay.begin();
}

void loop()
{
    // Nothing...
}

// The function that runs when Dasduino sends an I2C command
void receiveEvent(int howMany)
{
    uint8_t data[2];

    // Read data and store it in data array
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

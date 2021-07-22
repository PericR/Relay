/**
 **************************************************
 *
 * @file        Relay.cpp
 * @brief       Library for controling simple relay board with easyC connection.
 *
 *
 *
 * @authors     @ soldered.com @Robert Peric
 ***************************************************/


#include "Relay-SOLDERED.h"

/**
 * @brief                   Sensor specific native constructor.
 *
 * @param int _pin          Example parameter.
 */
CH_Relay::CH_Relay(int _pin)
{
    pin = _pin;
}

/**
 * @brief       Constructor for relay control
 */
CH_Relay::CH_Relay()
{

}

/**
 * @brief       Overloaded function for virtual in base class to initialize sensor specific.
 */
void CH_Relay::initializeNative()
{
    pinMode(pin, INPUT);
}


/**
 * @brief       relayControl send two bytes of data to relay to turn it on or off
 * 
 * @param       int channel sends channel pin to relay
 * 
 * @param       int mode sends HIGH or LOW to relay 
 */
void CH_Relay::relayControl(int channel, int mode)
{
    char data[2];
    data[0] = channel;
    data[1] = mode;
    sendData(data, 2);
}

/**
 * @brief       relayControlNative send two bytes of data to relay to turn it on or off
 * 
 * @param       int pin thats connected to relay
 * 
 * @param       int mode sends HIGH or LOW to relay 
 */
void CH_Relay::relayControlNative(int pin, int mode)
{
    digitalWrite(pin, mode);
}
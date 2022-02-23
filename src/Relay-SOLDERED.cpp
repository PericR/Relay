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
 * @brief                   Sensor specific native constructor for 2 channel board
 *
 * @param int _pin          Example parameter.
 */
CH_Relay::CH_Relay(int _pin1, int _pin2)
{
    native = 1;
    pin1 = _pin1;
    pin2 = _pin2;
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
    pinMode(pin1, INPUT);
    if (pin2)
    {
        pinMode(pin2, INPUT);
    }
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
    if (native)
    {
        digitalWrite(channel ? pin2 : pin1, mode);
    }
    else
    {
        char data[2];
        data[0] = channel;
        data[1] = mode;
        sendData((const uint8_t *)data, 2);
    }
}


#include "Relay_Firmwire.h"

/**
 * @brief       default constructor with nothing in it
 */
Relay_Firmwire::Relay_Firmwire()
{

}

/**
 * @brief       begin function sets channel pins as outputs
 */
void Relay_Firmwire::begin()
{
    pinMode(CHANNEL1_PIN, OUTPUT);
    pinMode(CHANNEL2_PIN, OUTPUT);
    pinMode(CHANNEL3_PIN, OUTPUT);
    pinMode(CHANNEL4_PIN, OUTPUT);
}

/**
 * @brief       controlRelay turns channel on or off
 */
void Relay_Firmwire::controlRelay(uint8_t channel, uint8_t mode)
{
    digitalWrite(channel, mode);
}





#ifndef _RELAY_FIRMWIRE_H
#define _RELAY_FIRMWIRE_H

#include "Arduino.h"

#define CHANNEL1_PIN 0
#define CHANNEL2_PIN 1
#define CHANNEL3_PIN 2
#define CHANNEL4_PIN 8

class Relay_Firmwire
{
  private:
    /* data */
  public:
    Relay_Firmwire();

    void begin();
    void controlRelay(uint8_t channel, uint8_t mode);
};

#endif
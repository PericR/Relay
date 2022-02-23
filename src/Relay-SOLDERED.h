/**
 **************************************************
 *
 * @file        Relay.h
 * @brief       Header file for simple relay board with easyC comunication
 *
 *
 *
 * @authors     @ soldered.com @Robert Peric
 ***************************************************/

#ifndef __RELAY_SOLDERED__
#define __RELAY_SOLDERED__

#include "Arduino.h"
#include "libs/Generic-easyC/easyC.hpp"

/**
 * RElay chanels
 */
#define CHANNEL1 0
#define CHANNEL2 1

/* To be added later for 4 channel relay (Maybe)
#define CHANNEL3        0
#define CHANNEL4        0
*/

class CH_Relay : public EasyC
{
  public:
    CH_Relay(int _pin1, int _pin2);
    CH_Relay();
    void relayControl(int channel, int mode);

  protected:
    void initializeNative();

  private:
    int pin1, pin2;
};

#endif

#ifndef lm35library_h
#define lm35library_h

#include "Arduino.h"

class LM35Temperature {

  public:
    LM35Temperature(int pin);
    float readTemperature(char unidade);

  private:
    int _pin;

};

#endif

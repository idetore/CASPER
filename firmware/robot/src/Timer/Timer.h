/*  Copyright (C) 2012  Albert van Dalen http://www.avdweb.nl
 *  This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 *  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 *  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License at http://www.gnu.org/licenses .
 */

//Original repo: https://github.com/avandalen/avdweb_SAMDtimer
//Forked by Barna Keresztes https://github.com/kbarni/avdweb_SAMDtimer
//Modified by Jeremy Paradie for Hampshire College

#ifndef Timer_H
#define Timer_H

#include "Adafruit_ZeroTimer.h"

class Timer : public Adafruit_ZeroTimer {
  public:
    Timer(byte timerNr, tc_counter_size countersize, byte pin, unsigned period_us, int pulseWidth_us=-1, bool timerEnable=1); // For timer with output
    Timer(byte timerNr, void (*_ISR)(), unsigned period_us, bool ISRenable=1); // For timer interrupt, without output 
    
    void attachInterrupt(void (*_ISR)(), bool interruptEnable=1); // attach ISR to a timer with output, or exchange the ISR
    void enableTimer(bool timerEnable);
    void enableInterrupt(bool interruptEnable);
    void setPulseWidth(unsigned pulseWidth_us);
    
  protected:  
    void init(bool enabled); 
    void calc(unsigned period_us, unsigned pulseWidth_us);  

    byte pin;
    void (*ISR)();
    unsigned period_us, periodCounter, PWcounter;
    tc_clock_prescaler prescale;
    tc_counter_size countersize;  
};
#endif

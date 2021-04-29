#ifndef __AVR_ATmega328__
#define __AVR_ATmega328__
#endif

#include "activity3.h"
#include<util/delay.h>

void InitPWM(void)
{
    TIMER_COUNTER_CONTROL_REGISTER1A |= (1 << NONINVERTING_MODE) | (1 << WAVEGENERATION_MODE0) | (1 << WAVEGENERATION_MODE1);// non inverting Fast PWM mode
    TIMER_COUNTER_CONTROL_REGISTER1B |= (1 << CS00) | (1 << CS01); //PRESCALING OF 64
    DDRD |= (1 << CRO_DISPLAYPIN);
}

uint16_t OutPWM (uint16_t value)
{
    
    uint16_t temperature;

    if((value>=0) && (value<=209)){

        OUTPUT_COMPAIR_REGISTERA = 205; //20% duty cycle
        temperature = 20;
        _delay_ms(20);
    }
    else if((value>=210) && (value<=509)){

        OUTPUT_COMPAIR_REGISTERA = 410; //40% duty cycle
        temperature = 25;
       _delay_ms(20);
    }
    else if((value>=510) && (value<=709)){

        OUTPUT_COMPAIR_REGISTERA = 717;//70% duty cycle
        temperature = 29;
        _delay_ms(20);
    }
    else if((value>=710) && (value<=1024)){

        OUTPUT_COMPAIR_REGISTERA = 973; //95% duty cycle
        temperature = 33;
        _delay_ms(20);
    }
    else{
        OUTPUT_COMPAIR_REGISTERA = 0; //0% output
        temperature = 0;
    }
    return temperature;
}
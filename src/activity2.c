#ifndef __AVR_ATmega328__
#define __AVR_ATmega328__
#endif

#include "activity2.h"

void InitADC()
{
    ADC_MUX_REGISTER|=(1<<ADC_REF_VOLTAGE);//SET REF VOLTAGE 5VOLT
    ADC_CONTROL_STATUSREGISTER|=(1<<ADC_ENABLE)|(7<<ADC_PRESCALER);//ENABLE ADC AND SET PRESCALER TO /128
}

uint16_t ReadADC(uint8_t ch)
{
    //channel must be within 0-7
    ADC_MUX_REGISTER&=0xf8;
    ch=ch&0b00000111;
    ADC_MUX_REGISTER|=ch;

    //start conversion
    ADC_CONTROL_STATUSREGISTER|=(1<<ADC_START_CONVERSION);

    //WAIT FOR CONVERSION TO COMPLETE
    while(!(ADC_CONTROL_STATUSREGISTER & (1<<ADC_INTERRUPTFLAG)));

    //CLEAR ADIF BY WRITING 1  TO IT
    ADC_CONTROL_STATUSREGISTER|=(1<<ADC_INTERRUPTFLAG);

    return(ADC);
}
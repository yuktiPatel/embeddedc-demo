#ifndef __AVR_ATmega328__
#define __AVR_ATmega328__
#endif

#include "inc/activity1.h"
#include "inc/activity2.h"
#include "inc/activity3.h"
#include "inc/activity4.h"

int main(){

    peripherals_init();

    while(1){
        if(seatOccupiedAndHeaterOn()){
            uint16_t temperature,data;
            LED_ON;
            temperature = ReadADC(0);
            data = OutPWM(temperature);
            UARTwrite(data);
        }
        else{
            LED_OFF;
            OUTPUT_COMPAIR_REGISTERA = 0;
        }
    }
}
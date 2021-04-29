#ifndef __AVR_ATmega328__
#define __AVR_ATmega328__
#endif

#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"

void peripherals_init(void){
    DDRB |= (1 << LED_PIN);
    DDRD &=~ (1 << SEAT);
    DDRD &=~ (1 << HEATER_BUTTON);
    SEAT_HEATER_PORT |= (1 << SEAT);
    SEAT_HEATER_PORT |= (1 << HEATER_BUTTON);
    InitADC();
    InitPWM();
    InitUART(103);

}

uint8_t seatOccupiedAndHeaterOn(void){
    if((!((PIND) & (1 << SEAT))) == 1 && (!((PIND) & (1 << HEATER_BUTTON))) == 1){
        return 1;
    }
    return 0;
}


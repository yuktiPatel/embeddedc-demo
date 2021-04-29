#ifndef __ACTIVITY4_H__
#define __ACTIVITY4_H__

#include <avr/io.h>

void InitUART(uint16_t ubrr_value);
void UARTwrite(char data);

#endif
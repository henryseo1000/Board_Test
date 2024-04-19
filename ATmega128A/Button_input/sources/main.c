#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "UART_support.h"
#define BINARY_PATTERN "0b%d%d%d%d%d%d%d%d"
#define BYTE2BINARY(byte) \
    (byte & 0x80 ? 1 : 0), \
    (byte & 0x40 ? 1 : 0), \
    (byte & 0x20 ? 1 : 0), \
    (byte & 0x10 ? 1 : 0), \
    (byte & 0x08 ? 1 : 0), \
    (byte & 0x04 ? 1 : 0), \
    (byte & 0x02 ? 1 : 0), \
    (byte & 0x01 ? 1 : 0)

FILE OUTPUT \
    = FDEV_SETUP_STREAM(UART0_transmit, NULL, _FDEV_SETUP_WRITE);

int main(void){
    UART0_init();
    stdout = &OUTPUT;

    DDRA &= ~0x00;

    char mask = 0x10; //0001 0000

    while(1){
        if(PINA & mask){
            printf("PORTA4 is 1!!\n");
        }
        else{
            printf("PORTA4 is 0!!\n");
        }
        printf(""BINARY_PATTERN"\n", BYTE2BINARY(PINA));
        _delay_ms(500);
    }
    

    return 0;
}
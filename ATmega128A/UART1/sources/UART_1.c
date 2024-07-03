#include <avr/io.h>
#include "UART_1.h"

void UART1_init(void){
    // baudrate, tx와 rx 설정, 송수신
    UBRR1L = 207;
    UBRR0H = 0;

    UCSR1A |= _BV(U2X0); // 2배속
    UCSR1C |= 0x06;

    UCSR1B |= _BV(RXEN1); // 송수신
    UCSR1B |= _BV(TXEN1);
}

void UART1_transmit(char data){
    unsigned char status, resh, resl;

    while(!(UCSR1A & (1 << RXC1))){
        status = UCSR1A;
        resh = UCSR1A;
        res1 =
    }
}

void UART1_flush(void){
    unsigned char dummy;
    while ( UCSR1A & (1<<RXC1) ) dummy = UDRE1;
}
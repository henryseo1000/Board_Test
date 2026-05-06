#include <avr/io.h>
#include "UART_1.h"

void UART1_init(void){
    // baudrate, tx와 rx 설정, 송수신
    UBRR1H = 0x00;
    UBRR1L = 207; // 9600 baud rate

    UCSR1A |= _BV(U2X1); // 2배속
    UCSR1C |= 0x06;

    UCSR1B |= _BV(RXEN1); // 송수신
    UCSR1B |= _BV(TXEN1);
}

void UART1_transmit(char data){
    while(!(UCSR1A & (1 << UDRE1)));
    UDR1 = data;
}

void UART1_flush(void){
    unsigned char dummy;
    while ( UCSR1A & (1 << RXC1) ) {
        dummy = UDRE1;
    }
}
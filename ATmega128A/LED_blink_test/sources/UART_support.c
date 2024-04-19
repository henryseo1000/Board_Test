#include <avr/io.h>
#include "UART_support.h"

void UART0_init(void){
    UBRR0H = 0x00; // 9600 baudrate
    UBRR0L = 207;

    UCSR0A |= _BV(U2X0); // 2배속
    UCSR0C |= 0x06;

    UCSR0B |= _BV(RXEN0); // 송수신
    UCSR0B |= _BV(TXEN0);
}

void UART0_transmit(char data){
    while(!(UCSR0A & (1 << UDRE0))); // 송신 가능 대기
    UDR0 = data; // 데이터 전송
}
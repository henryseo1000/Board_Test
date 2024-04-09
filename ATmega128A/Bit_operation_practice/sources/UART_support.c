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

int with_while(int sum){
    int total = 0;
    int n = 0;
    while(total < sum){
        n++;
        total += n;
    }

    return n;
}

int with_do_while(int sum){
    int total = 0;
    int n = 0;

    do{
        n++;
        total += n;
    }while(total < sum);

    return n;
}

int with_for(int sum){
    int total = 0;
    int n = 0;

    for( ; total < sum; ){
        n++;
        total += n;
    }

    return n;
}

void print_bits(uint8_t no){
    int n = 0;
    int mask = 0x80;

    while(n < 8){
        printf("%d th bit is %d.\n", n, no & mask ? 1 : 0);
        mask = mask /2;
        n++;
    }
}
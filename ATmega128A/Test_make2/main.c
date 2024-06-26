#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

void UART0_init(void);
void UART0_transmit(char data);
FILE OUTPUT \
    = FDEV_SETUP_STREAM(UART0_transmit, NULL, _FDEV_SETUP_WRITE);

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

int main(void){
    UART0_init();
    stdout = &OUTPUT;

    unsigned int count = 0;
    while (1){
        printf("%d\n\r", count++);
        _delay_ms(1000);
    }
    return 0;
}
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "UART_support.h"

#define set_bit(value, bit) (_SFR_BYTE(value) |= _BV(bit))
#define clear_bit(value, bit) (_SFR_BYTE(value) &= ~_BV(bit))
#define invert_bit(value, bit) (_SFR_BYTE(value) ^= _BV(bit))
#define read_bit(value, bit) ((_SFR_BYTE(value) & _BV(bit)) >> bit)

#define LED_3_ON 2
#define BINARY_PATTERN "0b%d%d%d%d%d%d%d%d" //이진 출력 양식의 지정
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

    //레지스터의 특정 비트를 검사할 수 있다.
    if((SREG & 0x20) == 0x20){
        printf("Bit is 1!\n");
    }
    else{
        printf("Bit is 0!\n");
    }

    //_BV() 메크로를 이용해 특정 비트가 0또는 1인지 검사하는 매크로 정의됨
    unsigned char value = 0b00001111;
    printf("Original    : "BINARY_PATTERN"\n\r", BYTE2BINARY(value)); // value의 비트를 읽는다.

    //비트를 set한다.
    set_bit(value, 6);
    printf("Set 7th bit : "BINARY_PATTERN"\n\r", BYTE2BINARY(value));

    //비트를 clear한다.
    clear_bit(value, 2);
    printf("Set 3rd bit : "BINARY_PATTERN"\n\r", BYTE2BINARY(value));

    //비트를 반전한다.
    invert_bit(value, 0);
    printf("Set 1st bit : "BINARY_PATTERN"\n\r", BYTE2BINARY(value));

    //비트를 검사하고 읽는다.
    int read = read_bit(value, 5);
    printf("6th bit is  : %d\n\r", read);

    return 0;
}
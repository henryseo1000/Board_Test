#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

int main(void){
    DDRA |= 0xFF;

    while(1){
        PORTA = 0xFF;
        _delay_ms(500); // 지정해준 시간만큼 지연
        PORTA = 0x00;
        _delay_ms(500); // 지정해준 시간만큼 지연
    }

    return 0;
}
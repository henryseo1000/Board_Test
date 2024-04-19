#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

int main(void){
    DDRA |= 0xFF;

    while(1){
        for(int i = 0x01; i <= 0x80; i <<= 1){
            PORTA = i;
            _delay_ms(1000);
        }
    }
    
    // 아래는 교재에 나와있던 코드
    /*char mask = 0x01;

    while(1){
        PORTA = mask; // 포트A를 mask로 설정

        // 다음 패턴 값을 생성
        mask <<= 1;
        if(mask == 0x00) mask = 0x01;

        _delay_ms(1000); // 1초 기다림
    }*/

    return 0;
}
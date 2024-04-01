#include <avr/io.h>
#include <util/delay.h>

int main(){
    DDRA |= 0x01;
    while(1){
        PORTA |= 0x01;
        _delay_ms(1000);
        PORTA &= ~0x01;
        _delay_ms(1000);
    }
    return 0;
}
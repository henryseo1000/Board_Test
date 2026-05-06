#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "UART_1.h"

FILE OUTPUT \
    = FDEV_SETUP_STREAM(UART1_transmit, NULL, _FDEV_SETUP_WRITE);

int main(void){
    UART1_init();
    stdout = &OUTPUT;

    char str[100] = "Test String";

    printf("*** Data Types... ***\n\r");
    printf("Integer : %d\n\r", 128);
    printf("Float : %f\n\r", 3.14); // 실수의 경우 정상적으로 출력되지 않음. 라이브러리 추가가 필요. Makefile 8번째 줄을 보자.
    printf("String : %s\n\r", str);
    printf("Character : %c\n\r", 'A');

    // unsigned int count = 0;

    // while (1) {
    //     printf("%d\n\r", count++);
    //     _delay_ms(1000);
    // }

    return 0;
}
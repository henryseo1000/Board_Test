#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "UART_support.h"

FILE OUTPUT \
    = FDEV_SETUP_STREAM(UART0_transmit, NULL, _FDEV_SETUP_WRITE);

int main(void){
    UART0_init();
    stdout = &OUTPUT;

    printf("with    while : %d\n", with_while(22));
    printf("with do-while : %d\n", with_do_while(22));
    printf("with      for : %d\n", with_for(22));

    print_bits(115);

    return 0;
}
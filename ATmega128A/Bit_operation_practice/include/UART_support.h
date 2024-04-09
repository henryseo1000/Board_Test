#ifndef UART_SUPPORT_H_
#define UART_SUPPORT_H_

void UART0_init(void);
void UART0_transmit(char data);

// 1~n까지의 자연수를 더해 합이 sum보다 커지는 가장 작은 자연수 n을 구하는 함수
// 각각 위에서부터 while, do-while, for을 이용해 구해본다.
int with_while(int sum);
int with_do_while(int sum);
int with_for(int sum);

// 인자로 받은 수의 각 비트를 순서대로 출력한다.
void print_bits(uint8_t no);

#endif
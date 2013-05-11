#include <twi.h>
#include <stdio.h>
#include <inttypes.h>
#include <avr/io.h>
#include <util/delay.h>

//Define functions
//======================
void ioinit(void);      // initializes IO
static int uart_putchar(char c, FILE *stream);
uint8_t uart_getchar(void);
static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
uint8_t uart_rxready(void);

int main(void)
{
	//int j;
	/******************************************/
	#define FOSC 16000000
	#define BAUD 9600
	#define MYUBRR (FOSC/16/BAUD-1)


	//======================
	//USART Baud rate: 9600
	UBRR0H = MYUBRR >> 8;
	UBRR0L = MYUBRR;
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	stdout = &mystdout; //Required for printf init
	printf("\nboot\n");
	
	twi_setfreq(89200);
	printf("\nread:%08lu, psc:%02d, twbr:%03d calc:%08lu", 
		twi_getfreq(), 
		twi_getprescaler(), 
		TWBR,
		twi_calcfreq(TWBR, twi_getprescaler())
		);

	return 0;
}

static int uart_putchar(char c, FILE *stream)
{
    if (c == '\n') uart_putchar('\r', stream);
  
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = c;
    
    return 0;
}

uint8_t uart_rxready(void)
{
	return (UCSR0A & (1<<RXC0));
}

uint8_t uart_getchar(void)
{
    while( !(UCSR0A & (1<<RXC0)) );
    return(UDR0);
};
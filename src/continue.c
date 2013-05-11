#include <twi.h>
#include <stdlib.h>

uint8_t twi_continue(void)
{
	uint8_t val;
	val = TWCR;
	val |= ((1<<TWINT) | (1<<TWEN));
	val &= ~( (1<<TWSTA) | (1<<TWSTO) );
	TWCR = val;
	while(!twi_checkint()){};
	return twi_getstat();

}
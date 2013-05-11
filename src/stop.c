#include <twi.h>
#include <stdlib.h>

void twi_stop(void)
{
	uint8_t val;
	val = TWCR;
	val |= ( (1<<TWINT) | (1<<TWSTO) | (1<<TWEN) );
	val &= ~(1<<TWSTA);
	TWCR = val;
}

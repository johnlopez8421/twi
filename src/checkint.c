#include <twi.h>
#include <stdlib.h>

uint8_t twi_checkint(void)
{
	return TWCR & (1<<TWINT);
}

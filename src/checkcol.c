#include <twi.h>
#include <stdlib.h>

uint8_t twi_checkcol(void)
{
	return (TWCR & (1<<TWWC));
}

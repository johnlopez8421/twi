#include <twi.h>
#include <stdlib.h>

void twi_clearstart(void)
{
	TWCR = (TWCR | (~(1<<TWSTA)));
}

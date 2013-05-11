#include <twi.h>
#include <stdlib.h>

uint8_t twi_getstat(void)
{
	return (TWSR & ~TWIPRESCALE_MASK);
}

#include <twi.h>
#include <stdlib.h>

uint32_t twi_getfreq(void)
{
	return (F_CPU/(16 + ((2 * TWBR) * (twi_getprescaler())) ));
}

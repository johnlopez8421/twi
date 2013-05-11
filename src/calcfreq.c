#include <twi.h>
#include <stdlib.h>

uint32_t twi_calcfreq(uint8_t twbr, uint8_t prescale)
{
	return ( F_CPU/(16 + ((2 * twbr) * (prescale))) );
}

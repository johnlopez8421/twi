#include <twi.h>
#include <stdint.h>

uint8_t twi_getprescaler(void)
{
	uint8_t val = 0;
	
	switch(TWSR & TWIPRESCALE_MASK)
	{
		case TWIPRESCALE_1:  val = 1;  break;
		case TWIPRESCALE_4:  val = 4;  break;
		case TWIPRESCALE_16: val = 16; break;
		case TWIPRESCALE_64: val = 64; break;
		default: break;
	}
	return val;
}

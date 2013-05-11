#include <twi.h>
#include <stdlib.h>


void twi_setprescaler(uint8_t val)
{

	uint8_t reg;
	
	reg = TWSR;
	reg &= ~TWIPRESCALE_MASK;
	
	switch(val)
	{
		case 1:  reg |= TWIPRESCALE_1;  TWSR = reg; break;
		case 4:  reg |= TWIPRESCALE_4;  TWSR = reg; break;
		case 16: reg |= TWIPRESCALE_16; TWSR = reg; break;
		case 64: reg |= TWIPRESCALE_64; TWSR = reg; break;
		default: break;
	}
}

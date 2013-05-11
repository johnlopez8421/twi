#include <twi.h>
#include <stdlib.h>

uint8_t twi_valmakeaddr(uint8_t addr, uint8_t rdwr)
{
	addr <<=1;
	return (addr | rdwr);

}
#include <twi.h>
#include <stdlib.h>

uint8_t twi_rd(uint8_t *pstat)
{
	twi_continue();
	if(pstat != NULL) *pstat = twi_getstat();
	return TWDR;
}
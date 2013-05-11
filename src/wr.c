#include <twi.h>
#include <stdlib.h>

void twi_wr(uint8_t data, uint8_t *pstat)
{
	TWDR = data;
	twi_continue();
	if(pstat != NULL) *pstat = twi_getstat();
}

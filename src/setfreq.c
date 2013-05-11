#include <twi.h>
#include <stdlib.h>

void twi_setfreq(uint32_t freq)
{
	uint8_t prescales[4] = {1, 4, 16, 64};
	uint8_t twbr_best = 0x00;
	uint8_t prescale_best = 0x00;
	uint32_t freq_best = 0xFFFFFFFF;
	uint32_t freq_curr = 0xFFFFFFFF;
	uint32_t diff = 0x00000000;
	uint32_t diff_curr = 0x00000000;
	uint16_t j, jj;
	
	for(j=0; j<256; j++)
	{
		for(jj=0; jj<5; jj++)
		{
			(freq_best>freq) ? (diff=freq_best-freq) : (diff=freq-freq_best);	// find the difference between the current "best" and the goal
			
			freq_curr = twi_calcfreq(j, prescales[jj]);	// get the next iteration of the prescaler and TWBR
			
			(freq_curr>freq) ? (diff_curr=freq_curr-freq) : (diff_curr=freq-freq_curr);	// find the difference between the result and the goal
			
			if(diff_curr<diff) // if the new value is closer to the goal...
			{
				freq_best = freq_curr;
				prescale_best = prescales[jj];
				twbr_best = j;
			}
		}
	}
	twi_setprescaler(prescale_best);
	TWBR = twbr_best;
}

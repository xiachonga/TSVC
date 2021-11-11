#include "common.h"

int s315()
{

//	reductions
//	if to max with index reductio 1 dimension

	uint64_t start_t, end_t, clock_dif;


	init( "s315 ");
	for (int i = 0; i < LEN; i++)
		a[i] = (i * 7) % LEN;
	start_t = rdtsc();

	float x, chksum;
	int index;

		x = a[0];
		index = 0;
		for (int i = 0; i < LEN; ++i) {
			if (a[i] > x) {
				x = a[i];
				index = i;
			}
		}
		chksum = x + (float) index;
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S315\t %8ld   ", clock_dif);
	temp = index+x+1;
	check(-1);
	return 0;
}
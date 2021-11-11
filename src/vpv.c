#include "common.h"

int vpv()
{

//	control loops
//	vector plus vector

	uint64_t start_t, end_t, clock_dif;


	init( "vpv  ");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			a[i] += b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("vpv\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
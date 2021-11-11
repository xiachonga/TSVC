#include "common.h"

int vpvts( float s)
{

//	control loops
//	vector plus vector times scalar

	uint64_t start_t, end_t, clock_dif;


	init( "vpvts");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			a[i] += b[i] * s;
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("vpvts\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
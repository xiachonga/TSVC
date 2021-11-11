#include "common.h"

int vas( int* __restrict__ ip)
{

//	control loops
//	vector assignment, scatter
//	scatter is required

	uint64_t start_t, end_t, clock_dif;


	init( "vas  ");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			a[ip[i]] = b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("vas\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
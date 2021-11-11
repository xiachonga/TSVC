#include "common.h"

int s4112(int* __restrict__ ip, float s)
{

//	indirect addressing
//	sparse saxpy
//	gather is required

	uint64_t start_t, end_t, clock_dif;


	init( "s4112");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			a[i] += b[ip[i]] * s;
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S4112\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
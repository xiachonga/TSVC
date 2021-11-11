#include "common.h"

int vag( int* __restrict__ ip)
{

//	control loops
//	vector assignment, gather
//	gather is required

	uint64_t start_t, end_t, clock_dif;


	init( "vag  ");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			a[i] = b[ip[i]];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("vag\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
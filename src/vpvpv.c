#include "common.h"

int vpvpv()
{

//	control loops
//	vector plus vector plus vector

	uint64_t start_t, end_t, clock_dif;


	init( "vpvpv");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			a[i] += b[i] + c[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("vpvpv\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
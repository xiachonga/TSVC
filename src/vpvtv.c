#include "common.h"

int vpvtv()
{

//	control loops
//	vector plus vector times vector

	uint64_t start_t, end_t, clock_dif;


	init( "vpvtv");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			a[i] += b[i] * c[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("vpvtv\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
#include "common.h"

int vtv()
{

//	control loops
//	vector times vector

	uint64_t start_t, end_t, clock_dif;


	init( "vtv  ");
	start_t = rdtsc();

	// Function Body

		for (int i = 0; i < LEN; i++) {
			a[i] *= b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("vtv\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
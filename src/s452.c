#include "common.h"

int s452()
{

//	intrinsic functions
//	seq function

	uint64_t start_t, end_t, clock_dif;


	init( "s452 ");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			a[i] = b[i] + c[i] * (float) (i+1);
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S452\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
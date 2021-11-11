#include "common.h"

int s451()
{

//	intrinsic functions
//	intrinsics

	uint64_t start_t, end_t, clock_dif;


	init( "s451 ");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			a[i] = sinf(b[i]) + cosf(c[i]);
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S451\t %8ld   ", clock_dif);
	check(1);
	return 0;
} 
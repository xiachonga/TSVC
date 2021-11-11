#include "common.h"

int s000()
{

//	linear dependence testing
//	no dependence - vectorizable

	uint64_t start_t, end_t, clock_dif;


	init( "s000 ");
	start_t = rdtsc();

		for (int i = 0; i < lll; i++) {
			a[i] = b[i] + c[i];
			X[i] = Y[i] + 1;
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S000\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
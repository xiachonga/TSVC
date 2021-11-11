#include "common.h"

int s1113()
{

//	linear dependence testing
//	one iteration dependency on a(LEN/2) but still vectorizable

	uint64_t start_t, end_t, clock_dif;


	init( "s113 ");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			a[i] = a[LEN/2] + b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S1113\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
#include "common.h"

int s481()
{

//	non-local goto's
//	stop statement

	uint64_t start_t, end_t, clock_dif;


	init( "s481 ");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			if (d[i] < (float)0.) {
				exit (0);
			}
			a[i] += b[i] * c[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S481\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
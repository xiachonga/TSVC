#include "common.h"

int s2244()
{

//	node splitting
//	cycle with ture and anti dependency

	uint64_t start_t, end_t, clock_dif;


	init( "s244 ");
	start_t = rdtsc();

		for (int i = 0; i < LEN-1; i++) {
			a[i+1] = b[i] + e[i];
			a[i] = b[i] + c[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S2244\t %8ld   ", clock_dif);
	check(12);
	return 0;
}
#include "common.h"

int s131()
{
//	global data flow analysis
//	forward substitution

	uint64_t start_t, end_t, clock_dif;


	init( "s131 ");
	start_t = rdtsc();

	int m  = 1;

		for (int i = 0; i < LEN - 1; i++) {
			a[i] = a[i + m] + b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S131\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
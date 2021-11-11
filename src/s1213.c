#include "common.h"

int s1213()
{

//	statement reordering
//	dependency needing temporary

	uint64_t start_t, end_t, clock_dif;

	init( "s212 ");
	start_t = rdtsc();

		for (int i = 1; i < LEN-1; i++) {
			a[i] = b[i-1]+c[i];
			b[i] = a[i+1]*d[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S1213\t %8ld   ", clock_dif);
	check(12);
	return 0;
}
#include "common.h"

int s222()
{

//	loop distribution
//	partial loop vectorizatio recurrence in middle

	uint64_t start_t, end_t, clock_dif;


	init( "s222 ");
	start_t = rdtsc();


		for (int i = 1; i < LEN; i++) {
			a[i] += b[i] * c[i];
			e[i] = e[i - 1] * e[i - 1];
			a[i] -= b[i] * c[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S222\t %8ld   ", clock_dif);
	check(12);
	return 0;
}
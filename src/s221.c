#include "common.h"

int s221()
{

//	loop distribution
//	loop that is partially recursive

	uint64_t start_t, end_t, clock_dif;


	init( "s221 ");
	start_t = rdtsc();


		for (int i = 1; i < LEN; i++) {
			a[i] += c[i] * d[i];
			b[i] = b[i - 1] + a[i] + d[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S221\t %8ld   ", clock_dif);
	check(12);
	return 0;
}
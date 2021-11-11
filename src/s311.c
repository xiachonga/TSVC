#include "common.h"

int s311()
{

//	reductions
//	sum reduction

	uint64_t start_t, end_t, clock_dif;


	init( "s311 ");
	start_t = rdtsc();

	float sum;

		sum = (float)0.;
		for (int i = 0; i < LEN; i++) {
			sum += a[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S311\t %8ld   ", clock_dif);
	check(1);
	return 0;
}

#include "common.h"

int s254()
{

//	scalar and array expansion
//	carry around variable

	uint64_t start_t, end_t, clock_dif;


	init( "s254 ");
	start_t = rdtsc();

	float x;

		x = b[LEN-1];
		for (int i = 0; i < LEN; i++) {
			a[i] = (b[i] + x) * (float).5;
			x = b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S254\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
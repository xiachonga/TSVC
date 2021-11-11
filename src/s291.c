#include "common.h"

int s291()
{

//	loop peeling
//	wrap around variable, 1 level

	uint64_t start_t, end_t, clock_dif;


	init( "s291 ");
	start_t = rdtsc();

	int im1;

		im1 = LEN-1;
		for (int i = 0; i < LEN; i++) {
			a[i] = (b[i] + b[im1]) * (float).5;
			im1 = i;
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S291\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
#include "common.h"

int s292()
{

//	loop peeling
//	wrap around variable, 2 levels
//	similar to S291

	uint64_t start_t, end_t, clock_dif;


	init( "s292 ");
	start_t = rdtsc();

	int im1, im2;

		im1 = LEN-1;
		im2 = LEN-2;
		for (int i = 0; i < LEN; i++) {
			a[i] = (b[i] + b[im1] + b[im2]) * (float).333;
			im2 = im1;
			im1 = i;
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S292\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
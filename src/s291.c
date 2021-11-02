#include "common.h"

int s291()
{

//	loop peeling
//	wrap around variable, 1 level

	clock_t start_t, end_t, clock_dif;


	init( "s291 ");
	start_t = clock();

	int im1;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		im1 = LEN-1;
		for (int i = 0; i < LEN; i++) {
			a[i] = (b[i] + b[im1]) * (float).5;
			im1 = i;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S291\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
#include "common.h"

int s254()
{

//	scalar and array expansion
//	carry around variable

	clock_t start_t, end_t, clock_dif;


	init( "s254 ");
	start_t = clock();

	float x;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		x = b[LEN-1];
		for (int i = 0; i < LEN; i++) {
			a[i] = (b[i] + x) * (float).5;
			x = b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S254\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
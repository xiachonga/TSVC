#include "common.h"

int s112()
{

//	linear dependence testing
//	loop reversal

	clock_t start_t, end_t, clock_dif;


	init( "s112 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
//		#pragma vector always
		for (int i = LEN - 2; i >= 0; i--) {
			a[i+1] = a[i] + b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S112\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
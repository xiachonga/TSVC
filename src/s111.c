#include "common.h"

int s111()
{

//	linear dependence testing
//	no dependence - vectorizable

	clock_t start_t, end_t, clock_dif;


	init( "s111 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
//		#pragma vector always
		for (int i = 1; i < LEN; i += 2) {
			a[i] = a[i - 1] + b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S111\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
#include "common.h"

int s451()
{

//	intrinsic functions
//	intrinsics

	clock_t start_t, end_t, clock_dif;


	init( "s451 ");
	start_t = clock();
	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[i] = sinf(b[i]) + cosf(c[i]);
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S451\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
} 
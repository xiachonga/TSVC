#include "common.h"

int s1113()
{

//	linear dependence testing
//	one iteration dependency on a(LEN/2) but still vectorizable

	clock_t start_t, end_t, clock_dif;


	init( "s113 ");
	start_t = clock();
	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[i] = a[LEN/2] + b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S1113\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
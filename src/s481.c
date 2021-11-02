#include "common.h"

int s481()
{

//	non-local goto's
//	stop statement

	clock_t start_t, end_t, clock_dif;


	init( "s481 ");
	start_t = clock();
	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN; i++) {
			if (d[i] < (float)0.) {
				exit (0);
			}
			a[i] += b[i] * c[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S481\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
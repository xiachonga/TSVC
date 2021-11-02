#include "common.h"

int s212()
{

//	statement reordering
//	dependency needing temporary

	clock_t start_t, end_t, clock_dif;

	init( "s212 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN-1; i++) {
			a[i] *= c[i];
			b[i] += a[i + 1] * d[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S212\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(12);
	return 0;
}
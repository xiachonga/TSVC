#include "common.h"

int s2711()
{

//	control flow
//	semantic if removal

	clock_t start_t, end_t, clock_dif;

	init( "s2711");
	start_t = clock();
	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN; i++) {
			if (b[i] != (float)0.0) {
				a[i] += b[i] * c[i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S2711\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
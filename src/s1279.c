#include "common.h"

int s1279()
{

//	control flow
//	vector if/gotos

	clock_t start_t, end_t, clock_dif;


	init( "s279 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN; i++) {
			if (a[i] < (float)0.) {
				if (b[i] > a[i]) {
					c[i] += d[i] * e[i];
				}
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S1279\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(123);
	return 0;
}
#include "common.h"

int s242(float s1, float s2)
{

//	node splitting

	clock_t start_t, end_t, clock_dif;


	init( "s242 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 1; i < LEN; ++i) {
			a[i] = a[i - 1] + s1 + s2 + b[i] + c[i] + d[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S242\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
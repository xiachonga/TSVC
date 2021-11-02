#include "common.h"

int s273()
{

//	control flow
//	simple loop with dependent conditional

	clock_t start_t, end_t, clock_dif;


	init( "s273 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[i] += d[i] * e[i];
			if (a[i] < (float)0.)
				b[i] += d[i] * e[i];
			c[i] += a[i] * d[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S273\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(123);
	return 0;
}
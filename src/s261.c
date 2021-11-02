#include "common.h"

int s261()
{

//	scalar and array expansion
//	wrap-around scalar under an if

	clock_t start_t, end_t, clock_dif;


	init( "s261 ");
	start_t = clock();

	float t;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 1; i < LEN; ++i) {
			t = a[i] + b[i];
			a[i] = t + c[i-1];
			t = c[i] * d[i];
			c[i] = t;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S261\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(13);
	return 0;
}
#include "common.h"

int s351()
{

//	loop rerolling
//	unrolled saxpy

	clock_t start_t, end_t, clock_dif;
	start_t = clock();

	init( "s351 ");
	start_t = clock();

	float alpha = c[0];
	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN; i += 5) {
			a[i] += alpha * b[i];
			a[i + 1] += alpha * b[i + 1];
			a[i + 2] += alpha * b[i + 2];
			a[i + 3] += alpha * b[i + 3];
			a[i + 4] += alpha * b[i + 4];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S351\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
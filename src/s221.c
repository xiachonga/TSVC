#include "common.h"

int s221()
{

//	loop distribution
//	loop that is partially recursive

	clock_t start_t, end_t, clock_dif;


	init( "s221 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 1; i < LEN; i++) {
			a[i] += c[i] * d[i];
			b[i] = b[i - 1] + a[i] + d[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S221\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(12);
	return 0;
}
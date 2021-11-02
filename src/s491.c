#include "common.h"

int s491(int* __restrict__ ip)
{

//	vector semantics
//	indirect addressing on lhs, store in sequence
//	scatter is required

	clock_t start_t, end_t, clock_dif;


	init( "s491 ");
	start_t = clock();
	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[ip[i]] = b[i] + c[i] * d[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S491\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
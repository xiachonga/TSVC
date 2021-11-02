#include "common.h"

int vas( int* __restrict__ ip)
{

//	control loops
//	vector assignment, scatter
//	scatter is required

	clock_t start_t, end_t, clock_dif;


	init( "vas  ");
	start_t = clock();
	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[ip[i]] = b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("vas\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
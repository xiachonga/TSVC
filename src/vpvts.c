#include "common.h"

int vpvts( float s)
{

//	control loops
//	vector plus vector times scalar

	clock_t start_t, end_t, clock_dif;


	init( "vpvts");
	start_t = clock();
	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[i] += b[i] * s;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("vpvts\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
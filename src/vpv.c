#include "common.h"

int vpv()
{

//	control loops
//	vector plus vector

	clock_t start_t, end_t, clock_dif;


	init( "vpv  ");
	start_t = clock();
	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[i] += b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("vpv\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
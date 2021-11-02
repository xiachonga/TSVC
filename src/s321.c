#include "common.h"

int s321()
{

//	recurrences
//	first order linear recurrence

	clock_t start_t, end_t, clock_dif;


	init( "s321 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 1; i < LEN; i++) {
			a[i] += a[i-1] * b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S321\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
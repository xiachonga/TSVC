#include "common.h"

int s322()
{

//	recurrences
//	second order linear recurrence

	clock_t start_t, end_t, clock_dif;


	init( "s322 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 2; i < LEN; i++) {
			a[i] = a[i] + a[i - 1] * b[i] + a[i - 2] * c[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S322\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
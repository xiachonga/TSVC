#include "common.h"

int s173()
{
//	symbolics
//	expression in loop bounds and subscripts

	clock_t start_t, end_t, clock_dif;


	init( "s173 ");
	start_t = clock();

	int k = LEN/2;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN/2; i++) {
			a[i+k] = a[i] + b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S173\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
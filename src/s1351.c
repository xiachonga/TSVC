#include "common.h"

int s1351()
{

//	induction pointer recognition

	clock_t start_t, end_t, clock_dif;
	start_t = clock();

	init( "s351 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
		float* __restrict__ A = a;
		float* __restrict__ B = b;
		float* __restrict__ C = c;
		for (int i = 0; i < LEN; i++) {
			*A = *B+*C;
			A++;
			B++;
			C++;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S1351\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
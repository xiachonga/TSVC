#include "common.h"

int s453()
{

//	induction varibale recognition

	float s;
	clock_t start_t, end_t, clock_dif;


	init( "s453 ");
	start_t = clock();
	for (int nl = 0; nl < REPETITIONS; nl++) {
		s = 0.;
		for (int i = 0; i < LEN; i++) {
			s += (float)2.;
			a[i] = s * b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S453\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
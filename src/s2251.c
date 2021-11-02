#include "common.h"

int s2251()
{

//	scalar and array expansion
//	scalar expansion

	clock_t start_t, end_t, clock_dif;


	init( "s251 ");
	start_t = clock();
	for (int nl = 0; nl < REPETITIONS; nl++) {
		float s = (float)0.0;
		for (int i = 0; i < LEN; i++) {
			a[i] = s*e[i];
			s = b[i]+c[i];
			b[i] = a[i]+d[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S2251\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
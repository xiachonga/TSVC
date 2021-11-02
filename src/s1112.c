#include "common.h"

int s1112()
{

//	linear dependence testing
//	loop reversal

	clock_t start_t, end_t, clock_dif;
	

	init("s112 ");
	start_t = clock();
	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = LEN - 1; i >= 0; i--) {
			a[i] = b[i] + (float) 1.;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	
	printf("S1112\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
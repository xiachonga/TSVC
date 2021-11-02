#include "common.h"

int s252()
{

//	scalar and array expansion
//	loop with ambiguous scalar temporary

	clock_t start_t, end_t, clock_dif;

	init( "s252 ");
	start_t = clock();

	float t, s;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		t = (float) 0.;
		for (int i = 0; i < LEN; i++) {
			s = b[i] * c[i];
			a[i] = s + t;
			t = s;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S252\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
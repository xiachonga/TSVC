#include "common.h"

int s313()
{

//	reductions
//	dot product

	clock_t start_t, end_t, clock_dif;


	init( "s313 ");
	start_t = clock();

	float dot;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		dot = (float)0.;
		for (int i = 0; i < LEN; i++) {
			dot += a[i] * b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, dot);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S313\t %6d   %8ld   ", REPETITIONS, clock_dif);
	temp = dot;
	check(-1);
	return 0;
}
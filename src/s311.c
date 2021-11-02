#include "common.h"

int s311()
{

//	reductions
//	sum reduction

	clock_t start_t, end_t, clock_dif;


	init( "s311 ");
	start_t = clock();

	float sum;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		sum = (float)0.;
		for (int i = 0; i < LEN; i++) {
			sum += a[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, sum);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S311\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}

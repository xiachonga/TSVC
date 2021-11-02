#include "common.h"

int s316()
{

//	reductions
//	if to min reduction

	clock_t start_t, end_t, clock_dif;


	init( "s316 ");
	start_t = clock();

	float x;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		x = a[0];
		for (int i = 1; i < LEN; ++i) {
			if (a[i] < x) {
				x = a[i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, x);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S316\t %8d   %8ld   ", REPETITIONS, clock_dif);
	temp = x;
	check(-1);
	return 0;
}
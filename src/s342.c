#include "common.h"

int s342()
{

//	packing
//	unpacking
//	not vectorizable, value of j in unknown at each iteration

	clock_t start_t, end_t, clock_dif;
	start_t = clock();

	init( "s342 ");
	start_t = clock();

	int j = 0;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		j = -1;
		for (int i = 0; i < LEN; i++) {
			if (a[i] > (float)0.) {
				j++;
				a[i] = b[j];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S342\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
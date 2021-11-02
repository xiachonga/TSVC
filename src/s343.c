#include "common.h"

int s343()
{

//	packing
//	pack 2-d array into one dimension
//	not vectorizable, value of k in unknown at each iteration

	clock_t start_t, end_t, clock_dif;
	start_t = clock();

	init( "s343 ");
	start_t = clock();

	int k;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		k = -1;
		for (int i = 0; i < LEN2; i++) {
			for (int j = 0; j < LEN2; j++) {
				if (bb[j][i] > (float)0.) {
					k++;
					array[k] = aa[j][i];
				}
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S343\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(0);
	return 0;
}
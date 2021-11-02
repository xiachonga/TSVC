#include "common.h"

int s162(int k)
{
//	control flow
//	deriving assertions

	clock_t start_t, end_t, clock_dif;


	init( "s162 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
		if (k > 0) {
			for (int i = 0; i < LEN-1; i++) {
				a[i] = a[i + k] + b[i] * c[i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S162\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
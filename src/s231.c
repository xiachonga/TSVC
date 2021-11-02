#include "common.h"

int s231()
{
//	loop interchange
//	loop with data dependency

	clock_t start_t, end_t, clock_dif;


	init( "s231 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN2; ++i) {
			for (int j = 1; j < LEN2; j++) {
				aa[j][i] = aa[j - 1][i] + bb[j][i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S231\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(11);
	return 0;
}
#include "common.h"

int s114()
{

//	linear dependence testing
//	transpose vectorization
//	Jump in data access - not vectorizable

	clock_t start_t, end_t, clock_dif;


	init( "s114 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN2; i++) {
			for (int j = 0; j < i; j++) {
				aa[i][j] = aa[j][i] + bb[i][j];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}

	end_t = clock(); clock_dif = end_t - start_t;
	printf("S114\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(11);
	return 0;
}
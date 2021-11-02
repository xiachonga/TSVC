#include "common.h"

int s1119()
{

//	linear dependence testing
//	no dependence - vectorizable

	clock_t start_t, end_t, clock_dif;
	

	init("s119 ");
	start_t = clock();
	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 1; i < LEN2; i++) {
			for (int j = 0; j < LEN2; j++) {
				aa[i][j] = aa[i-1][j] + bb[i][j];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	
	
	printf("S1119\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(11);
	return 0;
}
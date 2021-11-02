#include "common.h"

int s232()
{

//	loop interchange
//	interchanging of triangular loops

	clock_t start_t, end_t, clock_dif;


	init( "s232 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int j = 1; j < LEN2; j++) {
			for (int i = 1; i <= j; i++) {
				aa[j][i] = aa[j][i-1]*aa[j][i-1]+bb[j][i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 1.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S232\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(11);
	return 0;
}
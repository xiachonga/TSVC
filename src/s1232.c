#include "common.h"

int s1232()
{

//	loop interchange
//	interchanging of triangular loops

	clock_t start_t, end_t, clock_dif;


	init( "s232 ");
	start_t = clock();
	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int j = 0; j < LEN2; j++) {
			for (int i = j; i < LEN2; i++) {
				aa[i][j] = bb[i][j] + cc[i][j];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 1.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S1232\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(11);
	return 0;
}
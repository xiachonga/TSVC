#include "common.h"

int s257()
{

//	scalar and array expansion
//	array expansion

	clock_t start_t, end_t, clock_dif;


	init( "s257 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 1; i < LEN2; i++) {
			for (int j = 0; j < LEN2; j++) {
				a[i] = aa[j][i] - a[i-1];
				aa[j][i] = a[i] + bb[j][i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S257\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(111);
	return 0;
}
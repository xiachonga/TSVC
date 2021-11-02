#include "common.h"

int s256()
{

//	scalar and array expansion
//	array expansion

	clock_t start_t, end_t, clock_dif;


	init( "s256 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN2; i++) {
			for (int j = 1; j < LEN2; j++) {
				a[j] = (float)1.0 - a[j - 1];
				cc[j][i] = a[j] + bb[j][i]*d[j];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S256\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(111);
	return 0;
}
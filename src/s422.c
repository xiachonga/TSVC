#include "common.h"

int s422()
{

//	storage classes and equivalencing
//	common and equivalence statement
//	anti-dependence, threshold of 4

	xx = array + 4;
	set1d(xx, 0., 1);
	clock_t start_t, end_t, clock_dif;
	init( "s422 ");
	start_t = clock();


	for (int nl = 0; nl < 8*ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			xx[i] = array[i + 8] + a[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S422\t %8ld \t ", clock_dif);
	temp = 0;
	for (int i = 0; i < LEN; i++){
		temp += xx[i];
	}
	check(-1);
	return 0;
}
#include "common.h"

int s175(int inc)
{

//	symbolics
//	symbolic dependence tests

	clock_t start_t, end_t, clock_dif;


	init( "s175 ");
	start_t = clock();

	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 0; i < LEN-1; i += inc) {
			a[i] = a[i + inc] + b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S175\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
#include "common.h"

int s131()
{
//	global data flow analysis
//	forward substitution

	clock_t start_t, end_t, clock_dif;


	init( "s131 ");
	start_t = clock();

	int m  = 1;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 5*ntimes; nl++) {
		for (int i = 0; i < LEN - 1; i++) {
			a[i] = a[i + m] + b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S131\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
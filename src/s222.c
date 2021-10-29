#include "common.h"

int s222()
{

//	loop distribution
//	partial loop vectorizatio recurrence in middle

	clock_t start_t, end_t, clock_dif;


	init( "s222 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes/2; nl++) {
		for (int i = 1; i < LEN; i++) {
			a[i] += b[i] * c[i];
			e[i] = e[i - 1] * e[i - 1];
			a[i] -= b[i] * c[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S222\t %8ld \t ", clock_dif);
	check(12);
	return 0;
}
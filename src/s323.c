#include "common.h"

int s323()
{

//	recurrences
//	coupled recurrence

	clock_t start_t, end_t, clock_dif;


	init( "s323 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes/2; nl++) {
		for (int i = 1; i < LEN; i++) {
			a[i] = b[i-1] + c[i] * d[i];
			b[i] = a[i] + c[i] * e[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S323\t %8ld \t ", clock_dif);
	check(12);
	return 0;
}
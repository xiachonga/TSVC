#include "common.h"

int s1113()
{

//	linear dependence testing
//	one iteration dependency on a(LEN/2) but still vectorizable

	clock_t start_t, end_t, clock_dif;


	init( "s113 ");
	start_t = clock();
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 2*ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[i] = a[LEN/2] + b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S1113\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
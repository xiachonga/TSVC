#include "common.h"

int s111()
{

//	linear dependence testing
//	no dependence - vectorizable

	clock_t start_t, end_t, clock_dif;


	init( "s111 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 2*ntimes; nl++) {
//		#pragma vector always
		for (int i = 1; i < LEN; i += 2) {
			a[i] = a[i - 1] + b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S111\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
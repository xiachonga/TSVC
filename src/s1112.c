#include "common.h"

int s1112()
{

//	linear dependence testing
//	loop reversal

	clock_t start_t, end_t, clock_dif;
	

	init("s112 ");
	start_t = clock();
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes*3; nl++) {
		for (int i = LEN - 1; i >= 0; i--) {
			a[i] = b[i] + (float) 1.;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	
	printf("S1112\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
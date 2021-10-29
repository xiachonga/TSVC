#include "common.h"

int s316()
{

//	reductions
//	if to min reduction

	clock_t start_t, end_t, clock_dif;


	init( "s316 ");
	start_t = clock();

	float x;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes*5; nl++) {
		x = a[0];
		for (int i = 1; i < LEN; ++i) {
			if (a[i] < x) {
				x = a[i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, x);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S316\t %8ld \t ", clock_dif);
	temp = x;
	check(-1);
	return 0;
}
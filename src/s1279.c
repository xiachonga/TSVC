#include "common.h"

int s1279()
{

//	control flow
//	vector if/gotos

	clock_t start_t, end_t, clock_dif;


	init( "s279 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			if (a[i] < (float)0.) {
				if (b[i] > a[i]) {
					c[i] += d[i] * e[i];
				}
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S1279\t %8ld \t ", clock_dif);
	check(123);
	return 0;
}
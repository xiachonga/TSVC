#include "common.h"

int s2710( float x)
{

//	control flow
//	scalar and vector ifs

	clock_t start_t, end_t, clock_dif;


	init( "s2710");
	start_t = clock();
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes/2; nl++) {
		for (int i = 0; i < LEN; i++) {
			if (a[i] > b[i]) {
				a[i] += b[i] * d[i];
				if (LEN > 10) {
					c[i] += d[i] * d[i];
				} else {
					c[i] = d[i] * e[i] + (float)1.;
				}
			} else {
				b[i] = a[i] + e[i] * e[i];
				if (x > (float)0.) {
					c[i] = a[i] + d[i] * d[i];
				} else {
					c[i] += e[i] * e[i];
				}
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S2710\t %8ld \t ", clock_dif);
	check(123);
	return 0;
}
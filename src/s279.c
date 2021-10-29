#include "common.h"

int s279()
{

//	control flow
//	vector if/gotos

	clock_t start_t, end_t, clock_dif;


	init( "s279 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes/2; nl++) {
		for (int i = 0; i < LEN; i++) {
			if (a[i] > (float)0.) {
				goto L20;
			}
			b[i] = -b[i] + d[i] * d[i];
			if (b[i] <= a[i]) {
				goto L30;
			}
			c[i] += d[i] * e[i];
			goto L30;
L20:
			c[i] = -c[i] + e[i] * e[i];
L30:
			a[i] = b[i] + c[i] * d[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S279\t %8ld \t ", clock_dif);
	check(123);
	return 0;
}
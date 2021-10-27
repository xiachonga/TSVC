#include "common.h"

int s277()
{

//	control flow
//	test for dependences arising from guard variable computation.

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s277 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 0; i < LEN-1; i++) {
				if (a[i] >= (float)0.) {
					goto L20;
				}
				if (b[i] >= (float)0.) {
					goto L30;
				}
				a[i] += c[i] * d[i];
L30:
				b[i+1] = c[i] + d[i] * e[i];
L20:
;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S277\t %.2f \t\t", clock_dif_sec);;
	check(12);
	return 0;
}
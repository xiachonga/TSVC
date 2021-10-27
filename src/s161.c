#include "common.h"

int s161()
{

//	control flow
//	tests for recognition of loop independent dependences
//	between statements in mutually exclusive regions.

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s161 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes/2; nl++) {
		for (int i = 0; i < LEN-1; ++i) {
			if (b[i] < (float)0.) {
				goto L20;
			}
			a[i] = c[i] + d[i] * e[i];
			goto L10;
L20:
			c[i+1] = a[i] + d[i] * d[i];
L10:
			;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S161\t %.2f \t\t", clock_dif_sec);;
	check(13);
	return 0;
}
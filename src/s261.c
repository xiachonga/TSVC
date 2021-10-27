#include "common.h"

int s261()
{

//	scalar and array expansion
//	wrap-around scalar under an if

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s261 ");
	start_t = clock();

	float t;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 1; i < LEN; ++i) {
			t = a[i] + b[i];
			a[i] = t + c[i-1];
			t = c[i] * d[i];
			c[i] = t;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S261\t %.2f \t\t", clock_dif_sec);;
	check(13);
	return 0;
}
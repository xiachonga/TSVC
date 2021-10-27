#include "common.h"

int s273()
{

//	control flow
//	simple loop with dependent conditional

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s273 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[i] += d[i] * e[i];
			if (a[i] < (float)0.)
				b[i] += d[i] * e[i];
			c[i] += a[i] * d[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S273\t %.2f \t\t", clock_dif_sec);;
	check(123);
	return 0;
}
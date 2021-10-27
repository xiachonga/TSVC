#include "common.h"

int s242(float s1, float s2)
{

//	node splitting

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s242 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes/5; nl++) {
		for (int i = 1; i < LEN; ++i) {
			a[i] = a[i - 1] + s1 + s2 + b[i] + c[i] + d[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S242\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
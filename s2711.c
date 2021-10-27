#include "common.h"

int s2711()
{

//	control flow
//	semantic if removal

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;

	init( "s2711");
	start_t = clock();
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 4*ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			if (b[i] != (float)0.0) {
				a[i] += b[i] * c[i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S2711\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
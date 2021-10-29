#include "common.h"

int s1281()
{

//	crossing thresholds
//	index set splitting
//	reverse data access

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s281 ");
	start_t = clock();

	float x;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 4*ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			x = b[i]*c[i]+a[i]*d[i]+e[i];
			a[i] = x-(float)1.0;
			b[i] = x;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S1281\t %.2f \t\t", clock_dif_sec);;
	check(12);
	return 0;
}
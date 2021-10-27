#include "common.h"

int s2251()
{

//	scalar and array expansion
//	scalar expansion

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s251 ");
	start_t = clock();
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		float s = (float)0.0;
		for (int i = 0; i < LEN; i++) {
			a[i] = s*e[i];
			s = b[i]+c[i];
			b[i] = a[i]+d[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S2251\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
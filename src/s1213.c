#include "common.h"

int s1213()
{

//	statement reordering
//	dependency needing temporary

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;

	init( "s212 ");
	start_t = clock();
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 1; i < LEN-1; i++) {
			a[i] = b[i-1]+c[i];
			b[i] = a[i+1]*d[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S1213\t %.2f \t\t", clock_dif_sec);;
	check(12);
	return 0;
}
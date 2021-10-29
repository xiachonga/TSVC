#include "common.h"

int s1213()
{

//	statement reordering
//	dependency needing temporary

	clock_t start_t, end_t, clock_dif;

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
	printf("S1213\t %8ld \t ", clock_dif);
	check(12);
	return 0;
}
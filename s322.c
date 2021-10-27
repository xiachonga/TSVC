#include "common.h"

int s322()
{

//	recurrences
//	second order linear recurrence

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s322 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes/2; nl++) {
		for (int i = 2; i < LEN; i++) {
			a[i] = a[i] + a[i - 1] * b[i] + a[i - 2] * c[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S322\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
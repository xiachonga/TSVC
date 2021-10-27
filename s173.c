#include "common.h"

int s173()
{
//	symbolics
//	expression in loop bounds and subscripts

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s173 ");
	start_t = clock();

	int k = LEN/2;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 10*ntimes; nl++) {
		for (int i = 0; i < LEN/2; i++) {
			a[i+k] = a[i] + b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S173\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
#include "common.h"

int s291()
{

//	loop peeling
//	wrap around variable, 1 level

	clock_t start_t, end_t, clock_dif;


	init( "s291 ");
	start_t = clock();

	int im1;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 2*ntimes; nl++) {
		im1 = LEN-1;
		for (int i = 0; i < LEN; i++) {
			a[i] = (b[i] + b[im1]) * (float).5;
			im1 = i;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S291\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
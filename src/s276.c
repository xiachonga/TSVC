
#include "common.h"

int s276()
{

//	control flow
//	if test using loop index

	clock_t start_t, end_t, clock_dif;


	init( "s276 ");
	start_t = clock();

	int mid = (LEN/2);
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 4*ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			if (i+1 < mid) {
				a[i] += b[i] * c[i];
			} else {
				a[i] += b[i] * d[i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S276\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
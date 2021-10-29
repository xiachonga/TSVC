#include "common.h"

int s271()
{

//	control flow
//	loop with singularity handling

	clock_t start_t, end_t, clock_dif;


	init( "s271 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 4*ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			if (b[i] > (float)0.) {
				a[i] += b[i] * c[i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S271\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
#include "common.h"

int s172( int n1, int n3)
{
//	symbolics
//	vectorizable if n3 .ne. 0

	clock_t start_t, end_t, clock_dif;


	init( "s172 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = n1-1; i < LEN; i += n3) {
			a[i] += b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S172\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
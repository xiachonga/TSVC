#include "common.h"

int s174(int M)
{

//	symbolics
//	loop with subscript that may seem ambiguous

	clock_t start_t, end_t, clock_dif;


	init( "s174 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 10*ntimes; nl++) {
		for (int i = 0; i < M; i++) {
			a[i+M] = a[i] + b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S174\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
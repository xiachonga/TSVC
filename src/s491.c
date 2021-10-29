#include "common.h"

int s491(int* __restrict__ ip)
{

//	vector semantics
//	indirect addressing on lhs, store in sequence
//	scatter is required

	clock_t start_t, end_t, clock_dif;


	init( "s491 ");
	start_t = clock();
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[ip[i]] = b[i] + c[i] * d[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S491\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
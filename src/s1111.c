#include "common.h"

int s1111()
{

//	no dependence - vectorizable
//	jump in data access

	clock_t start_t, end_t, clock_dif;

	init("s111 ");
	start_t = clock();
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 2*ntimes; nl++) {
		for (int i = 0; i < LEN/2; i++) {
			a[2*i] = c[i] * b[i] + d[i] * b[i] + c[i] * c[i] + d[i] * b[i] + d[i] * c[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	
	printf("S1111\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
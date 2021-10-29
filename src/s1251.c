#include "common.h"

int s1251()
{

//	scalar and array expansion
//	scalar expansion

	clock_t start_t, end_t, clock_dif;


	init( "s251 ");
	start_t = clock();

	float s;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 4*ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			s = b[i]+c[i];
			b[i] = a[i]+d[i];
			a[i] = s*e[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S1251\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
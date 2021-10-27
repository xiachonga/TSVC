#include "common.h"

int s1351()
{

//	induction pointer recognition

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;
	start_t = clock();

	init( "s351 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 8*ntimes; nl++) {
		float* __restrict__ A = a;
		float* __restrict__ B = b;
		float* __restrict__ C = c;
		for (int i = 0; i < LEN; i++) {
			*A = *B+*C;
			A++;
			B++;
			C++;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S1351\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
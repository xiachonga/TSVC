#include "common.h"

int s151s(float a[LEN], float b[LEN],  int m)
{
	for (int i = 0; i < LEN-1; i++) {
		a[i] = a[i + m] + b[i];
	}
	return 0;
}
int s151()
{

//	interprocedural data flow analysis
//	passing parameter information into a subroutine

	clock_t start_t, end_t, clock_dif;
	init( "s151 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 5*ntimes; nl++) {
		s151s(a, b,  1);
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S151\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
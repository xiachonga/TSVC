#include "common.h"

int s152s(float a[LEN], float b[LEN], float c[LEN], int i)
{
	a[i] += b[i] * c[i];
	return 0;
}

int s152()
{

//	interprocedural data flow analysis
//	collecting information from a subroutine
	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s152 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			b[i] = d[i] * e[i];
			s152s(a, b, c, i);
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S152\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
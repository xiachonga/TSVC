#include "common.h"

int s4113(int* __restrict__ ip)
{

//	indirect addressing
//	indirect addressing on rhs and lhs
//	gather and scatter is required

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s4113");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[ip[i]] = b[ip[i]] + c[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S4113\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
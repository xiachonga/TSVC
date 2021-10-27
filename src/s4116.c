#include "common.h"

int s4116(int* __restrict__ ip, int j, int inc)
{

//	indirect addressing
//	more complicated sparse sdot
//	gather is required

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s4116");
	start_t = clock();

	float sum;
	int off;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable) 
	for (int nl = 0; nl < 100*ntimes; nl++) {
		sum = 0.;
		for (int i = 0; i < LEN2-1; i++) {
			off = inc + i;
			sum += a[off] * aa[j-1][ip[i]];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S4116\t %.2f \t\t", clock_dif_sec);;
	temp = sum;
	check(-1);
	return 0;
}
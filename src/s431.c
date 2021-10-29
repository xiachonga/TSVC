#include "common.h"

int s431()
{

//	parameters
//	parameter statement

	int k1=1;
	int k2=2;
	int k=2*k1-k2;
	clock_t start_t, end_t, clock_dif;


	init( "s431 ");
	start_t = clock();
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes*10; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[i] = a[i+k] + b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S431\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
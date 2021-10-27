#include "common.h"

int s4114(int* ip, int n1)
{

//	indirect addressing
//	mix indirect addressing with variable lower and upper bounds
//	gather is required

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s4114");
	start_t = clock();

	int k;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = n1-1; i < LEN; i++) {
			k = ip[i];
			a[i] = b[i] + c[LEN-k+1-2] * d[i];
			k += 5;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S4114\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
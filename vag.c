#include "common.h"

int vag( int* __restrict__ ip)
{

//	control loops
//	vector assignment, gather
//	gather is required

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "vag  ");
	start_t = clock();
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 2*ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[i] = b[ip[i]];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("vag\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
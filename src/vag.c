#include "common.h"

int vag( int* __restrict__ ip)
{

//	control loops
//	vector assignment, gather
//	gather is required

	clock_t start_t, end_t, clock_dif;


	init( "vag  ");
	start_t = clock();
	for (int nl = 0; nl < 2*ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[i] = b[ip[i]];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("vag\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
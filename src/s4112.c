#include "common.h"

int s4112(int* __restrict__ ip, float s)
{

//	indirect addressing
//	sparse saxpy
//	gather is required

	clock_t start_t, end_t, clock_dif;


	init( "s4112");
	start_t = clock();
	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[i] += b[ip[i]] * s;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S4112\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
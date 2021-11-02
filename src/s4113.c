#include "common.h"

int s4113(int* __restrict__ ip)
{

//	indirect addressing
//	indirect addressing on rhs and lhs
//	gather and scatter is required

	clock_t start_t, end_t, clock_dif;


	init( "s4113");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[ip[i]] = b[ip[i]] + c[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S4113\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
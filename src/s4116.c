#include "common.h"

int s4116(int* __restrict__ ip, int j, int inc)
{

//	indirect addressing
//	more complicated sparse sdot
//	gather is required

	clock_t start_t, end_t, clock_dif;


	init( "s4116");
	start_t = clock();

	float sum;
	int off;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		sum = 0.;
		for (int i = 0; i < LEN2-1; i++) {
			off = inc + i;
			sum += a[off] * aa[j-1][ip[i]];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S4116\t %6d   %8ld   ", REPETITIONS, clock_dif);
	temp = sum;
	check(-1);
	return 0;
}
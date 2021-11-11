#include "common.h"

int s4116(int* __restrict__ ip, int j, int inc)
{

//	indirect addressing
//	more complicated sparse sdot
//	gather is required

	uint64_t start_t, end_t, clock_dif;


	init( "s4116");
	start_t = rdtsc();

	float sum;
	int off;

		sum = 0.;
		for (int i = 0; i < LEN2-1; i++) {
			off = inc + i;
			sum += a[off] * aa[j-1][ip[i]];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S4116\t %8ld   ", clock_dif);
	temp = sum;
	check(-1);
	return 0;
}
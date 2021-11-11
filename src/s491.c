#include "common.h"

int s491(int* __restrict__ ip)
{

//	vector semantics
//	indirect addressing on lhs, store in sequence
//	scatter is required

	uint64_t start_t, end_t, clock_dif;


	init( "s491 ");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			a[ip[i]] = b[i] + c[i] * d[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S491\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
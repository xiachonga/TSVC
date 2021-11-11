#include "common.h"

int s4113(int* __restrict__ ip)
{

//	indirect addressing
//	indirect addressing on rhs and lhs
//	gather and scatter is required

	uint64_t start_t, end_t, clock_dif;


	init( "s4113");
	start_t = rdtsc();


		for (int i = 0; i < LEN; i++) {
			a[ip[i]] = b[ip[i]] + c[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S4113\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
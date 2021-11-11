#include "common.h"

int s4114(int* ip, int n1)
{

//	indirect addressing
//	mix indirect addressing with variable lower and upper bounds
//	gather is required

	uint64_t start_t, end_t, clock_dif;


	init( "s4114");
	start_t = rdtsc();

	int k;

		for (int i = n1-1; i < LEN; i++) {
			k = ip[i];
			a[i] = b[i] + c[LEN-k+1-2] * d[i];
			k += 5;
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S4114\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
#include "common.h"

int s431()
{

//	parameters
//	parameter statement

	int k1=1;
	int k2=2;
	int k=2*k1-k2;
	uint64_t start_t, end_t, clock_dif;


	init( "s431 ");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			a[i] = a[i+k] + b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S431\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
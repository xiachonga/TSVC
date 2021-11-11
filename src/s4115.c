#include "common.h"

int s4115(int* __restrict__ ip)
{

//	indirect addressing
//	sparse dot product
//	gather is required

	uint64_t start_t, end_t, clock_dif;


	init( "s4115");
	start_t = rdtsc();

	float sum;

		sum = 0.;
		for (int i = 0; i < LEN; i++) {
			sum += a[i] * b[ip[i]];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S4115\t %8ld   ", clock_dif);
	temp = sum;
	check(-1);
	return 0;
}
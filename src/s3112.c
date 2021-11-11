#include "common.h"

int s3112()
{

//	reductions
//	sum reduction saving running sums

	uint64_t start_t, end_t, clock_dif;


	init( "s3112");
	start_t = rdtsc();

	float sum;

		sum = (float)0.0;
		for (int i = 0; i < LEN; i++) {
			sum += a[i];
			b[i] = sum;
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S3112\t %8ld   ", clock_dif);
	temp = sum;
	check(-12);
	return 0;
}
#include "common.h"

int s3111()
{

//	reductions
//	conditional sum reduction

	uint64_t start_t, end_t, clock_dif;


	init( "s3111");
	start_t = rdtsc();

	float sum;

		sum = 0.;
		for (int i = 0; i < LEN; i++) {
			if (a[i] > (float)0.) {
				sum += a[i];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S3111\t %8ld   ", clock_dif);
	temp = sum;
	check(-1);
	return 0;
}
#include "common.h"

int s3113()
{

//	reductions
//	maximum of absolute value

	uint64_t start_t, end_t, clock_dif;


	init( "s3113");
	start_t = rdtsc();

	float max;

		max = abs(a[0]);
		for (int i = 0; i < LEN; i++) {
			if ((abs(a[i])) > max) {
				max = abs(a[i]);
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S3113\t %8ld   ", clock_dif);
	temp = max;
	check(-1);
	return 0;
}
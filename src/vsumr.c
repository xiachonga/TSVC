#include "common.h"

int vsumr()
{

//	control loops
//	vector sum reduction

	uint64_t start_t, end_t, clock_dif;


	init( "vsumr");
	start_t = rdtsc();

	float sum;

		sum = 0.;
		for (int i = 0; i < LEN; i++) {
			sum += a[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("vsumr\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
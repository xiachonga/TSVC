#include "common.h"

int s281()
{

//	crossing thresholds
//	index set splitting
//	reverse data access

	uint64_t start_t, end_t, clock_dif;


	init( "s281 ");
	start_t = rdtsc();

	float x;

		for (int i = 0; i < LEN; i++) {
			x = a[LEN-i-1] + b[i] * c[i];
			a[i] = x-(float)1.0;
			b[i] = x;
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S281\t %8ld   ", clock_dif);
	check(12);
	return 0;
}
#include "common.h"

int s352()
{

//	loop rerolling
//	unrolled dot product

	uint64_t start_t, end_t, clock_dif;

	init( "s352 ");
	start_t = rdtsc();

	float dot;

		dot = (float)0.;
		for (int i = 0; i < LEN; i += 5) {
			dot = dot + a[i] * b[i] + a[i + 1] * b[i + 1] + a[i + 2]
				* b[i + 2] + a[i + 3] * b[i + 3] + a[i + 4] * b[i + 4];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S352\t %8ld   ", clock_dif);
	temp = dot;
	check(-1);
	return 0;
}
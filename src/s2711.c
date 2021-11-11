#include "common.h"

int s2711()
{

//	control flow
//	semantic if removal

	uint64_t start_t, end_t, clock_dif;

	init( "s2711");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			if (b[i] != (float)0.0) {
				a[i] += b[i] * c[i];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S2711\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
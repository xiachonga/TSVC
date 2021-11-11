#include "common.h"

int s441()
{

//	non-logical if's
//	arithmetic if

	uint64_t start_t, end_t, clock_dif;


	init( "s441 ");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			if (d[i] < (float)0.) {
				a[i] += b[i] * c[i];
			} else if (d[i] == (float)0.) {
				a[i] += b[i] * b[i];
			} else {
				a[i] += c[i] * c[i];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S441\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
#include "common.h"

int s1221()
{

//	run-time symbolic resolution

	uint64_t start_t, end_t, clock_dif;


	init( "s221 ");
	start_t = rdtsc();

		for (int i = 4; i < LEN; i++) {
			b[i] = b[i - 4] + a[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S1221\t %8ld   ", clock_dif);
	check(12);
	return 0;
}
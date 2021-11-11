#include "common.h"

int s351()
{

//	loop rerolling
//	unrolled saxpy

	uint64_t start_t, end_t, clock_dif;

	init( "s351 ");
	start_t = rdtsc();

	float alpha = c[0];

		for (int i = 0; i < LEN; i += 5) {
			a[i] += alpha * b[i];
			a[i + 1] += alpha * b[i + 1];
			a[i + 2] += alpha * b[i + 2];
			a[i + 3] += alpha * b[i + 3];
			a[i + 4] += alpha * b[i + 4];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S351\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
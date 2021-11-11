#include "common.h"

int s353(int* __restrict__ ip)
{

//	loop rerolling
//	unrolled sparse saxpy
//	gather is required

	uint64_t start_t, end_t, clock_dif;

	init( "s353 ");
	start_t = rdtsc();

	float alpha = c[0];

		for (int i = 0; i < LEN; i += 5) {
			a[i] += alpha * b[ip[i]];
			a[i + 1] += alpha * b[ip[i + 1]];
			a[i + 2] += alpha * b[ip[i + 2]];
			a[i + 3] += alpha * b[ip[i + 3]];
			a[i + 4] += alpha * b[ip[i + 4]];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S353\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
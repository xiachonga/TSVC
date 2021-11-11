#include "common.h"

int s242(float s1, float s2)
{

//	node splitting

	uint64_t start_t, end_t, clock_dif;


	init( "s242 ");
	start_t = rdtsc();


		for (int i = 1; i < LEN; ++i) {
			a[i] = a[i - 1] + s1 + s2 + b[i] + c[i] + d[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S242\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
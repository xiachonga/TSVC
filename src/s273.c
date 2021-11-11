#include "common.h"

int s273()
{

//	control flow
//	simple loop with dependent conditional

	uint64_t start_t, end_t, clock_dif;


	init( "s273 ");
	start_t = rdtsc();


		for (int i = 0; i < LEN; i++) {
			a[i] += d[i] * e[i];
			if (a[i] < (float)0.)
				b[i] += d[i] * e[i];
			c[i] += a[i] * d[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S273\t %8ld   ", clock_dif);
	check(123);
	return 0;
}
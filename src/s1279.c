#include "common.h"

int s1279()
{

//	control flow
//	vector if/gotos

	uint64_t start_t, end_t, clock_dif;


	init( "s279 ");
	start_t = rdtsc();


		for (int i = 0; i < LEN; i++) {
			if (a[i] < (float)0.) {
				if (b[i] > a[i]) {
					c[i] += d[i] * e[i];
				}
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S1279\t %8ld   ", clock_dif);
	check(123);
	return 0;
}
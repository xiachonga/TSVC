#include "common.h"

int s274()
{

//	control flow
//	complex loop with dependent conditional

	uint64_t start_t, end_t, clock_dif;


	init( "s274 ");
	start_t = rdtsc();


		for (int i = 0; i < LEN; i++) {
			a[i] = c[i] + e[i] * d[i];
			if (a[i] > (float)0.) {
				b[i] = a[i] + b[i];
			} else {
				a[i] = d[i] * e[i];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S274\t %8ld   ", clock_dif);
	check(12);
	return 0;
}
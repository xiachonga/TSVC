#include "common.h"

int s272(float t)
{

//	control flow
//	loop with independent conditional

	uint64_t start_t, end_t, clock_dif;


	init( "s272 ");
	start_t = rdtsc();


		for (int i = 0; i < LEN; i++) {
			if (e[i] >= t) {
				a[i] += c[i] * d[i];
				b[i] += c[i] * c[i];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S272\t %8ld   ", clock_dif);
	check(12);
	return 0;
}
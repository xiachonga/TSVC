#include "common.h"

int s2710( float x)
{

//	control flow
//	scalar and vector ifs

	uint64_t start_t, end_t, clock_dif;


	init( "s2710");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			if (a[i] > b[i]) {
				a[i] += b[i] * d[i];
				if (LEN > 10) {
					c[i] += d[i] * d[i];
				} else {
					c[i] = d[i] * e[i] + (float)1.;
				}
			} else {
				b[i] = a[i] + e[i] * e[i];
				if (x > (float)0.) {
					c[i] = a[i] + d[i] * d[i];
				} else {
					c[i] += e[i] * e[i];
				}
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S2710\t %8ld   ", clock_dif);
	check(123);
	return 0;
}
#include "common.h"

int s277()
{

//	control flow
//	test for dependences arising from guard variable computation.

	uint64_t start_t, end_t, clock_dif;


	init( "s277 ");
	start_t = rdtsc();


		for (int i = 0; i < LEN-1; i++) {
				if (a[i] >= (float)0.) {
					goto L20;
				}
				if (b[i] >= (float)0.) {
					goto L30;
				}
				a[i] += c[i] * d[i];
L30:
				b[i+1] = c[i] + d[i] * e[i];
L20:
;
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S277\t %8ld   ", clock_dif);
	check(12);
	return 0;
}
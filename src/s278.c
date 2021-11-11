#include "common.h"

int s278()
{

//	control flow
//	if/goto to block if-then-else

	uint64_t start_t, end_t, clock_dif;


	init( "s278 ");
	start_t = rdtsc();


		for (int i = 0; i < LEN; i++) {
			if (a[i] > (float)0.) {
				goto L20;
			}
			b[i] = -b[i] + d[i] * e[i];
			goto L30;
L20:
			c[i] = -c[i] + d[i] * e[i];
L30:
			a[i] = b[i] + c[i] * d[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S278\t %8ld   ", clock_dif);
	check(123);
	return 0;
}
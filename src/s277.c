#include "common.h"

int s277()
{

//	control flow
//	test for dependences arising from guard variable computation.

	clock_t start_t, end_t, clock_dif;


	init( "s277 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
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
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S277\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(12);
	return 0;
}
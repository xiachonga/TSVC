#include "common.h"

int s443()
{

//	non-logical if's
//	arithmetic if

	clock_t start_t, end_t, clock_dif;


	init( "s443 ");
	start_t = clock();
	for (int nl = 0; nl < 2*ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			if (d[i] <= (float)0.) {
				goto L20;
			} else {
				goto L30;
			}
L20:
			a[i] += b[i] * c[i];
			goto L50;
L30:
			a[i] += b[i] * b[i];
L50:
			;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S443\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
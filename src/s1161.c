#include "common.h"

int s1161()
{

//	control flow
//	tests for recognition of loop independent dependences
//	between statements in mutually exclusive regions.

	clock_t start_t, end_t, clock_dif;


	init( "s161 ");
	start_t = clock();
	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 0; i < LEN-1; ++i) {
			if (c[i] < (float)0.) {
				goto L20;
			}
			a[i] = c[i] + d[i] * e[i];
			goto L10;
L20:
			b[i] = a[i] + d[i] * d[i];
L10:
			;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S1161\t %8ld \t ", clock_dif);
	check(13);
	return 0;
}
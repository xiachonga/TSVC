#include "common.h"

int s274()
{

//	control flow
//	complex loop with dependent conditional

	clock_t start_t, end_t, clock_dif;


	init( "s274 ");
	start_t = clock();

	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[i] = c[i] + e[i] * d[i];
			if (a[i] > (float)0.) {
				b[i] = a[i] + b[i];
			} else {
				a[i] = d[i] * e[i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S274\t %8ld \t ", clock_dif);
	check(12);
	return 0;
}
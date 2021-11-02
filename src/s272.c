#include "common.h"

int s272(float t)
{

//	control flow
//	loop with independent conditional

	clock_t start_t, end_t, clock_dif;


	init( "s272 ");
	start_t = clock();

	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			if (e[i] >= t) {
				a[i] += c[i] * d[i];
				b[i] += c[i] * c[i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S272\t %8ld \t ", clock_dif);
	check(12);
	return 0;
}
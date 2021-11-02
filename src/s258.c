#include "common.h"

int s258()
{

//	scalar and array expansion
//	wrap-around scalar under an if

	clock_t start_t, end_t, clock_dif;


	init( "s258 ");
	start_t = clock();

	float s;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		s = 0.;
		for (int i = 0; i < LEN2; ++i) {
			if (a[i] > 0.) {
				s = d[i] * d[i];
			}
			b[i] = s * c[i] + d[i];
			e[i] = (s + (float)1.) * aa[0][i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S258\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(25);
	return 0;
}
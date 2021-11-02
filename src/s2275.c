#include "common.h"

int s2275()
{

//	loop distribution is needed to be able to interchange

	clock_t start_t, end_t, clock_dif;


	init( "s275 ");
	start_t = clock();
	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN2; i++) {
			for (int j = 0; j < LEN2; j++) {
				aa[j][i] = aa[j][i] + bb[j][i] * cc[j][i];
			}
			a[i] = b[i] + c[i] * d[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S2275\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(11);
	return 0;
}
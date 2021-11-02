#include "common.h"

int s235()
{

//	loop interchanging
//	imperfectly nested loops

	clock_t start_t, end_t, clock_dif;


	init( "s235 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN2; i++) {
			a[i] += b[i] * c[i];
			for (int j = 1; j < LEN2; j++) {
				aa[j][i] = aa[j-1][i] + bb[j][i] * a[i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S235\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(111);
	return 0;
}
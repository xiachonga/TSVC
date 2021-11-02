#include "common.h"

int s125()
{

//	induction variable recognition
//	induction variable in two loops; collapsing possible

	clock_t start_t, end_t, clock_dif;


	init( "s125 ");
	start_t = clock();

	int k;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		k = -1;
		for (int i = 0; i < LEN2; i++) {
			for (int j = 0; j < LEN2; j++) {
				k++;
				array[k] = aa[i][j] + bb[i][j] * cc[i][j];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S125\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(0);
	return 0;
}
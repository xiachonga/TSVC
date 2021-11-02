#include "common.h"

int s127()
{

//	induction variable recognition
//	induction variable with multiple increments

	clock_t start_t, end_t, clock_dif;


	init( "s127 ");
	start_t = clock();

	int j;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		j = -1;
		for (int i = 0; i < LEN/2; i++) {
			j++;
			a[j] = b[i] + c[i] * d[i];
			j++;
			a[j] = b[i] + d[i] * e[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S127\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
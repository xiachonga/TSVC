#include "common.h"

int s128()
{

//	induction variables
//	coupled induction variables
//	jump in data access

	clock_t start_t, end_t, clock_dif;


	init( "s128 ");
	start_t = clock();

	int j, k;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		j = -1;
		for (int i = 0; i < LEN/2; i++) {
			k = j + 1;
			a[i] = b[k] - d[i];
			j = k + 1;
			b[k] = a[i] + c[k];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 1.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S128\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(12);
	return 0;
}
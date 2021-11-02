#include "common.h"

int s121()
{

//	induction variable recognition
//	loop with possible ambiguity because of scalar store

	clock_t start_t, end_t, clock_dif;


	init( "s121 ");
	start_t = clock();

	int j;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN-1; i++) {
			j = i + 1;
			a[i] = a[j] + b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S121\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}

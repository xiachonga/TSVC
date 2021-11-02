#include "common.h"

int s172( int n1, int n3)
{
//	symbolics
//	vectorizable if n3 .ne. 0

	clock_t start_t, end_t, clock_dif;


	init( "s172 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = n1-1; i < LEN; i += n3) {
			a[i] += b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S172\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
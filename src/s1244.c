#include "common.h"

int s1244()
{

//	node splitting
//	cycle with ture and anti dependency

	clock_t start_t, end_t, clock_dif;


	init( "s244 ");
	start_t = clock();
	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN-1; i++) {
			a[i] = b[i] + c[i] * c[i] + b[i]*b[i] + c[i];
			d[i] = a[i] + a[i+1];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S1244\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(12);
	return 0;
}
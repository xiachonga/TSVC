#include "common.h"

int s319()
{

//	reductions
//	coupled reductions

	clock_t start_t, end_t, clock_dif;


	init( "s319 ");
	start_t = clock();

	float sum;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		sum = 0.;
		for (int i = 0; i < LEN; i++) {
			a[i] = c[i] + d[i];
			sum += a[i];
			b[i] = c[i] + e[i];
			sum += b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, sum);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S319\t %6d   %8ld   ", REPETITIONS, clock_dif);
	temp = sum;
	check(-1);
	return 0;
}
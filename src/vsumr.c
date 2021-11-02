#include "common.h"

int vsumr()
{

//	control loops
//	vector sum reduction

	clock_t start_t, end_t, clock_dif;


	init( "vsumr");
	start_t = clock();

	float sum;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		sum = 0.;
		for (int i = 0; i < LEN; i++) {
			sum += a[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, sum);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("vsumr\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
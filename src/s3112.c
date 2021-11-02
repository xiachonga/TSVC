#include "common.h"

int s3112()
{

//	reductions
//	sum reduction saving running sums

	clock_t start_t, end_t, clock_dif;


	init( "s3112");
	start_t = clock();

	float sum;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		sum = (float)0.0;
		for (int i = 0; i < LEN; i++) {
			sum += a[i];
			b[i] = sum;
		}
		dummy(a, b, c, d, e, aa, bb, cc, sum);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S3112\t %6d   %8ld   ", REPETITIONS, clock_dif);
	temp = sum;
	check(-12);
	return 0;
}
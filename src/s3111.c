#include "common.h"

int s3111()
{

//	reductions
//	conditional sum reduction

	clock_t start_t, end_t, clock_dif;


	init( "s3111");
	start_t = clock();

	float sum;
	for (int nl = 0; nl < ntimes/2; nl++) {
		sum = 0.;
		for (int i = 0; i < LEN; i++) {
			if (a[i] > (float)0.) {
				sum += a[i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, sum);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S3111\t %8ld \t ", clock_dif);
	temp = sum;
	check(-1);
	return 0;
}
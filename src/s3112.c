#include "common.h"

int s3112()
{

//	reductions
//	sum reduction saving running sums

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s3112");
	start_t = clock();

	float sum;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		sum = (float)0.0;
		for (int i = 0; i < LEN; i++) {
			sum += a[i];
			b[i] = sum;
		}
		dummy(a, b, c, d, e, aa, bb, cc, sum);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S3112\t %.2f \t\t", clock_dif_sec);;
	temp = sum;
	check(-12);
	return 0;
}
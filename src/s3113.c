#include "common.h"

int s3113()
{

//	reductions
//	maximum of absolute value

	clock_t start_t, end_t, clock_dif;


	init( "s3113");
	start_t = clock();

	float max;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes*4; nl++) {
		max = abs(a[0]);
		for (int i = 0; i < LEN; i++) {
			if ((abs(a[i])) > max) {
				max = abs(a[i]);
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, max);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S3113\t %8ld \t ", clock_dif);
	temp = max;
	check(-1);
	return 0;
}
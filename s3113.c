#include "common.h"
.
int s3113()
{

//	reductions
//	maximum of absolute value

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


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
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S3113\t %.2f \t\t", clock_dif_sec);;
	temp = max;
	check(-1);
	return 0;
}
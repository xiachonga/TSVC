#include "common.h"

int s311()
{

//	reductions
//	sum reduction

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s311 ");
	start_t = clock();

	float sum;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes*10; nl++) {
		sum = (float)0.;
		for (int i = 0; i < LEN; i++) {
			sum += a[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, sum);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S311\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}

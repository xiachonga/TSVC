#include "common.h"

int s314()
{

//	reductions
//	if to max reduction

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s314 ");
	start_t = clock();

	float x;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes*5; nl++) {
		x = a[0];
		for (int i = 0; i < LEN; i++) {
			if (a[i] > x) {
				x = a[i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, x);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S314\t %.2f \t\t", clock_dif_sec);;
	temp = x;
	check(-1);
	return 0;
}
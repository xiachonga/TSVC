#include "common.h"

int s292()
{

//	loop peeling
//	wrap around variable, 2 levels
//	similar to S291

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s292 ");
	start_t = clock();

	int im1, im2;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		im1 = LEN-1;
		im2 = LEN-2;
		for (int i = 0; i < LEN; i++) {
			a[i] = (b[i] + b[im1] + b[im2]) * (float).333;
			im2 = im1;
			im1 = i;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S292\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
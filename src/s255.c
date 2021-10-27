#include "common.h"

int s255()
{

//	scalar and array expansion
//	carry around variables, 2 levels

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s255 ");
	start_t = clock();

	float x, y;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		x = b[LEN-1];
		y = b[LEN-2];
		for (int i = 0; i < LEN; i++) {
			a[i] = (b[i] + x + y) * (float).333;
			y = x;
			x = b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S255\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
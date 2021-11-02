#include "common.h"

int s292()
{

//	loop peeling
//	wrap around variable, 2 levels
//	similar to S291

	clock_t start_t, end_t, clock_dif;


	init( "s292 ");
	start_t = clock();

	int im1, im2;
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
	printf("S292\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
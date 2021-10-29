#include "common.h"

int s118()
{

//	linear dependence testing
//	potential dot product recursion

	clock_t start_t, end_t, clock_dif;


	init( "s118 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 200*(ntimes/LEN2); nl++) {
		for (int i = 1; i < LEN2; i++) {
			for (int j = 0; j <= i - 1; j++) {
				a[i] += bb[j][i] * a[i-j-1];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S118\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
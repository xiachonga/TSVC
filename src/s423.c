#include "common.h"

int s423()
{

//	storage classes and equivalencing
//	common and equivalenced variables - with anti-dependence

	int vl = 64;
	xx = array+vl;
	set1d(xx, 1., 1);
	clock_t start_t, end_t, clock_dif;
	init( "s423 ");
	start_t = clock();
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 4*ntimes; nl++) {
		for (int i = 0; i < LEN - 1; i++) {
			array[i+1] = xx[i] + a[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 1.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S423\t %8ld \t ", clock_dif);

	temp = 0.;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int i = 0; i < LEN; i++){
		temp += array[i];
	}
	check(-1);
	return 0;
}
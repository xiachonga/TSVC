#include "common.h"

int s421()
{

//	storage classes and equivalencing
//	equivalence- no overlap

	set1d(xx, 1., 1);
	clock_t start_t, end_t, clock_dif; double clock_dif_sec;
	init( "s421 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 4*ntimes; nl++) {
		yy = xx;
		for (int i = 0; i < LEN - 1; i++) {
			xx[i] = yy[i+1] + a[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 1.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S421\t %.2f \t\t", clock_dif_sec);;
	temp = 0;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int i = 0; i < LEN; i++){
		temp += xx[i];
	}
	check(-1);
	return 0;
}
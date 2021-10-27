#include "common.h"

int s1421()
{

//	storage classes and equivalencing
//	equivalence- no overlap

	set1d(xx, 1., 1);
	clock_t start_t, end_t, clock_dif; double clock_dif_sec;
	init( "s421 ");
	start_t = clock();

	xx = &b[LEN/2];
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 8*ntimes; nl++) {
		for (int i = 0; i < LEN/2; i++) {
			b[i] = xx[i] + a[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 1.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S1421\t %.2f \t\t", clock_dif_sec);;
	temp = 0;
	for (int i = 0; i < LEN/2; i++){
		temp += xx[i];
	}
	check(-1);
	return 0;
}
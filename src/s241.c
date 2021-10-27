#include "common.h"

int s241()
{

//	node splitting
//	preloading necessary to allow vectorization

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s241 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 2*ntimes; nl++) {
		for (int i = 0; i < LEN-1; i++) {
			a[i] = b[i] * c[i  ] * d[i];
			b[i] = a[i] * a[i+1] * d[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S241\t %.2f \t\t", clock_dif_sec);;
	check(12);
	return 0;
}
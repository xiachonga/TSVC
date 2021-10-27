#include "common.h"

int s317()
{

//	reductions
//	product reductio vectorize with
//	1. scalar expansion of factor, and product reduction
//	2. closed form solution: q = factor**n

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s317 ");
	start_t = clock();

	float q;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 5*ntimes; nl++) {
		q = (float)1.;
		for (int i = 0; i < LEN/2; i++) {
			q *= (float).99;
		}
		dummy(a, b, c, d, e, aa, bb, cc, q);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S317\t %.2f \t\t", clock_dif_sec);;
	temp = q;
	check(-1);
	return 0;
}
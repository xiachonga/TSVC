#include "common.h"

int s312()
{

//	reductions
//	product reduction

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s312 ");
	start_t = clock();

	float prod;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 10*ntimes; nl++) {
		prod = (float)1.;
		for (int i = 0; i < LEN; i++) {
			prod *= a[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, prod);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S312\t %.2f \t\t", clock_dif_sec);;
	temp = prod;
	check(-1);
	return 0;
}
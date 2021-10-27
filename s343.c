#include "common.h"

int s343()
{

//	packing
//	pack 2-d array into one dimension
//	not vectorizable, value of k in unknown at each iteration

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;
	start_t = clock();

	init( "s343 ");
	start_t = clock();

	int k;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 10*(ntimes/LEN2); nl++) {
		k = -1;
		for (int i = 0; i < LEN2; i++) {
			for (int j = 0; j < LEN2; j++) {
				if (bb[j][i] > (float)0.) {
					k++;
					array[k] = aa[j][i];
				}
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S343\t %.2f \t\t", clock_dif_sec);;
	check(0);
	return 0;
}
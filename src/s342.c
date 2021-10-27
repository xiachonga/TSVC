#include "common.h"

int s342()
{

//	packing
//	unpacking
//	not vectorizable, value of j in unknown at each iteration

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;
	start_t = clock();

	init( "s342 ");
	start_t = clock();

	int j = 0;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		j = -1;
		for (int i = 0; i < LEN; i++) {
			if (a[i] > (float)0.) {
				j++;
				a[i] = b[j];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S342\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
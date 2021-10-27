#include "common.h"

int s176()
{

//	symbolics
//	convolution

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s176 ");
	start_t = clock();

	int m = LEN/2;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 4*(ntimes/LEN); nl++) {
		for (int j = 0; j < (LEN/2); j++) {
			for (int i = 0; i < m; i++) {
				a[i] += b[i+m-j-1] * c[j];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S176\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
#include "common.h"

int s275()
{

//	control flow
//	if around inner loop, interchanging needed

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s275 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 10*(ntimes/LEN2); nl++) {
		for (int i = 0; i < LEN2; i++) {
			if (aa[0][i] > (float)0.) {
				for (int j = 1; j < LEN2; j++) {
					aa[j][i] = aa[j-1][i] + bb[j][i] * cc[j][i];
				}
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S275\t %.2f \t\t", clock_dif_sec);;
	check(11);
	return 0;
}
#include "common.h"

int s257()
{

//	scalar and array expansion
//	array expansion

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s257 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 10*(ntimes/LEN2); nl++) {
		for (int i = 1; i < LEN2; i++) {
			for (int j = 0; j < LEN2; j++) {
				a[i] = aa[j][i] - a[i-1];
				aa[j][i] = a[i] + bb[j][i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S257\t %.2f \t\t", clock_dif_sec);;
	check(111);
	return 0;
}
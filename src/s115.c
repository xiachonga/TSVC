#include "common.h"

int s115()
{

//	linear dependence testing
//	triangular saxpy loop

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s115 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 1000*(ntimes/LEN2); nl++) {
		for (int j = 0; j < LEN2; j++) {
			for (int i = j+1; i < LEN2; i++) {
				a[i] -= aa[j][i] * a[j];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S115\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
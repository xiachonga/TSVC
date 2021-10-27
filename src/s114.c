#include "common.h"

int s114()
{

//	linear dependence testing
//	transpose vectorization
//	Jump in data access - not vectorizable

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s114 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 200*(ntimes/(LEN2)); nl++) {
		for (int i = 0; i < LEN2; i++) {
			for (int j = 0; j < i; j++) {
				aa[i][j] = aa[j][i] + bb[i][j];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}

	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S114\t %.2f \t\t", clock_dif_sec);;
	check(11);
	return 0;
}
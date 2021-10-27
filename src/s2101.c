#include "common.h"

int s2101()
{

//	diagonals
//	main diagonal calculation
//	jump in data access

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s2101");
	start_t = clock();
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 10*ntimes; nl++) {
		for (int i = 0; i < LEN2; i++) {
			aa[i][i] += bb[i][i] * cc[i][i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S2101\t %.2f \t\t", clock_dif_sec);;
	check(11);
	return 0;
}
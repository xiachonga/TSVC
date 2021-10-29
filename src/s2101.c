#include "common.h"

int s2101()
{

//	diagonals
//	main diagonal calculation
//	jump in data access

	clock_t start_t, end_t, clock_dif;


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
	printf("S2101\t %8ld \t ", clock_dif);
	check(11);
	return 0;
}
#include "common.h"

int s1221()
{

//	run-time symbolic resolution

	clock_t start_t, end_t, clock_dif;


	init( "s221 ");
	start_t = clock();
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 4; i < LEN; i++) {
			b[i] = b[i - 4] + a[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S1221\t %8ld \t ", clock_dif);
	check(12);
	return 0;
}
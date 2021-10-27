#include "common.h"

int s221()
{

//	loop distribution
//	loop that is partially recursive

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s221 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes/2; nl++) {
		for (int i = 1; i < LEN; i++) {
			a[i] += c[i] * d[i];
			b[i] = b[i - 1] + a[i] + d[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S221\t %.2f \t\t", clock_dif_sec);;
	check(12);
	return 0;
}
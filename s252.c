#include "common.h"

int s252()
{

//	scalar and array expansion
//	loop with ambiguous scalar temporary

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;

	init( "s252 ");
	start_t = clock();

	float t, s;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		t = (float) 0.;
		for (int i = 0; i < LEN; i++) {
			s = b[i] * c[i];
			a[i] = s + t;
			t = s;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S252\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
#include "common.h"

int s258()
{

//	scalar and array expansion
//	wrap-around scalar under an if

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s258 ");
	start_t = clock();

	float s;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		s = 0.;
		for (int i = 0; i < LEN2; ++i) {
			if (a[i] > 0.) {
				s = d[i] * d[i];
			}
			b[i] = s * c[i] + d[i];
			e[i] = (s + (float)1.) * aa[0][i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S258\t %.2f \t\t", clock_dif_sec);;
	check(25);
	return 0;
}
#include "common.h"

int s471(){

//	call statements

	int m = LEN;
	set1d(x, 0., 1);
	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s471 ");
	start_t = clock();
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes/2; nl++) {
		for (int i = 0; i < m; i++) {
			x[i] = b[i] + d[i] * d[i];
			s471s();
			b[i] = c[i] + d[i] * e[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S471\t %.2f \t\t", clock_dif_sec);;
	temp = 0.;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int i = 0; i < LEN; i++){
		temp += x[i];
	}
	check(-12);
	return 0;
}
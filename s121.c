#include "common.h"

int s121()
{

//	induction variable recognition
//	loop with possible ambiguity because of scalar store

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s121 ");
	start_t = clock();

	int j;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 3*ntimes; nl++) {
		for (int i = 0; i < LEN-1; i++) {
			j = i + 1;
			a[i] = a[j] + b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S121\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
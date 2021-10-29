#include "common.h"

int s253()
{

//	scalar and array expansion
//	scalar expansio assigned under if

	clock_t start_t, end_t, clock_dif;


	init( "s253 ");
	start_t = clock();

	float s;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			if (a[i] > b[i]) {
				s = a[i] - b[i] * d[i];
				c[i] += s;
				a[i] = s;
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S253\t %8ld \t ", clock_dif);
	check(13);
	return 0;
}
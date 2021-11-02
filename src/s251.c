#include "common.h"

int s251()
{

//	scalar and array expansion
//	scalar expansion

	clock_t start_t, end_t, clock_dif;


	init( "s251 ");
	start_t = clock();

	float s;
	for (int nl = 0; nl < 4*ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			s = b[i] + c[i] * d[i];
			a[i] = s * s;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S251\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
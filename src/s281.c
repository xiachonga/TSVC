#include "common.h"

int s281()
{

//	crossing thresholds
//	index set splitting
//	reverse data access

	clock_t start_t, end_t, clock_dif;


	init( "s281 ");
	start_t = clock();

	float x;
	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			x = a[LEN-i-1] + b[i] * c[i];
			a[i] = x-(float)1.0;
			b[i] = x;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S281\t %8ld \t ", clock_dif);
	check(12);
	return 0;
}
#include "common.h"

int s241()
{

//	node splitting
//	preloading necessary to allow vectorization

	clock_t start_t, end_t, clock_dif;


	init( "s241 ");
	start_t = clock();

	for (int nl = 0; nl < 2*ntimes; nl++) {
		for (int i = 0; i < LEN-1; i++) {
			a[i] = b[i] * c[i  ] * d[i];
			b[i] = a[i] * a[i+1] * d[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S241\t %8ld \t ", clock_dif);
	check(12);
	return 0;
}
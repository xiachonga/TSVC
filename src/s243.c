#include "common.h"

int s243()
{

//	node splitting
//	false dependence cycle breaking

	clock_t start_t, end_t, clock_dif;


	init( "s243 ");
	start_t = clock();

	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 0; i < LEN-1; i++) {
			a[i] = b[i] + c[i  ] * d[i];
			b[i] = a[i] + d[i  ] * e[i];
			a[i] = b[i] + a[i+1] * d[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S243\t %8ld \t ", clock_dif);
	check(12);
	return 0;
}
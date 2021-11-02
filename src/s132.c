#include "common.h"

int s132()
{
//	global data flow analysis
//	loop with multiple dimension ambiguous subscripts

	clock_t start_t, end_t, clock_dif;

	init( "s132 ");
	start_t = clock();

	int m = 0;
	int j = m;
	int k = m+1;
	for (int nl = 0; nl < 400*ntimes; nl++) {
		for (int i= 1; i < LEN2; i++) {
			aa[j][i] = aa[k][i-1] + b[i] * c[1];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S132\t %8ld \t ", clock_dif);
	check(11);
	return 0;
}
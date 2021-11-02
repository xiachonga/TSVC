#include "common.h"

int s4117()
{

//	indirect addressing
//	seq function

	clock_t start_t, end_t, clock_dif;


	init( "s4117");
	start_t = clock();

	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[i] = b[i] + c[i/2] * d[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S4117\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
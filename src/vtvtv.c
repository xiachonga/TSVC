#include "common.h"

int vtvtv()
{

//	control loops
//	vector times vector times vector

	clock_t start_t, end_t, clock_dif;


	init( "vtvtv");
	start_t = clock();

	for (int nl = 0; nl < 4*ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[i] = a[i] * b[i] * c[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("vtvtv\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
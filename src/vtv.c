#include "common.h"

int vtv()
{

//	control loops
//	vector times vector

	clock_t start_t, end_t, clock_dif;


	init( "vtv  ");
	start_t = clock();

	// Function Body
	for (int nl = 0; nl < ntimes*10; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[i] *= b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("vtv\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
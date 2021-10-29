#include "common.h"

int va()
{

//	control loops
//	vector assignment

	clock_t start_t, end_t, clock_dif;

	init( "va	");
	start_t = clock();
	for (int nl = 0; nl < ntimes*10; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[i] = b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("va\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
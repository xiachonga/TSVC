#include "common.h"

int s116()
{

//	linear dependence testing

	clock_t start_t, end_t, clock_dif;


	init( "s116 ");
	start_t = clock();

	for (int nl = 0; nl < ntimes*10; nl++) {
		for (int i = 0; i < LEN - 5; i += 5) {
			a[i] = a[i + 1] * a[i];
			a[i + 1] = a[i + 2] * a[i + 1];
			a[i + 2] = a[i + 3] * a[i + 2];
			a[i + 3] = a[i + 4] * a[i + 3];
			a[i + 4] = a[i + 5] * a[i + 4];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S116\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
#include "common.h"

int s176()
{

//	symbolics
//	convolution

	clock_t start_t, end_t, clock_dif;


	init( "s176 ");
	start_t = clock();

	int m = LEN/2;
	for (int nl = 0; nl < 4*(ntimes/LEN); nl++) {
		for (int j = 0; j < (LEN/2); j++) {
			for (int i = 0; i < m; i++) {
				a[i] += b[i+m-j-1] * c[j];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S176\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
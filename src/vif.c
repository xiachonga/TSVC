#include "common.h"

int vif()
{

//	control loops
//	vector if

	clock_t start_t, end_t, clock_dif;


	init( "vif  ");
	start_t = clock();
	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			if (b[i] > (float)0.) {
				a[i] = b[i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("vif\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
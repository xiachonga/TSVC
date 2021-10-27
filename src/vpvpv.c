#include "common.h"

int vpvpv()
{

//	control loops
//	vector plus vector plus vector

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "vpvpv");
	start_t = clock();
	for (int nl = 0; nl < 4*ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[i] += b[i] + c[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("vpvpv\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
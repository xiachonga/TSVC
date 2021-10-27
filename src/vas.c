#include "common.h"

int vas( int* __restrict__ ip)
{

//	control loops
//	vector assignment, scatter
//	scatter is required

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "vas  ");
	start_t = clock();
	for (int nl = 0; nl < 2*ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[ip[i]] = b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("vas\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
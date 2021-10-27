#include "common.h"

int s128()
{

//	induction variables
//	coupled induction variables
//	jump in data access

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s128 ");
	start_t = clock();

	int j, k;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 2*ntimes; nl++) {
		j = -1;
		for (int i = 0; i < LEN/2; i++) {
			k = j + 1;
			a[i] = b[k] - d[i];
			j = k + 1;
			b[k] = a[i] + c[k];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 1.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S128\t %.2f \t\t", clock_dif_sec);;
	check(12);
	return 0;
}
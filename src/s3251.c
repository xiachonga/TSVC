#include "common.h"

int s3251()
{

//	scalar and array expansion
//	scalar expansion

	clock_t start_t, end_t, clock_dif;

	init( "s251 ");
	start_t = clock();

	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 0; i < LEN-1; i++){
			a[i+1] = b[i]+c[i];
			b[i]   = c[i]*e[i];
			d[i]   = a[i]*e[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S3251\t %8d   %8ld   ", REPETITIONS, clock_dif);
	check(1);
	return 0;
}
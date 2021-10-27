#include "common.h"

int s3251()
{

//	scalar and array expansion
//	scalar expansion

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;

	init( "s251 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 0; i < LEN-1; i++){
			a[i+1] = b[i]+c[i];
			b[i]   = c[i]*e[i];
			d[i]   = a[i]*e[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S3251\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
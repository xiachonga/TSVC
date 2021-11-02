#include "common.h"

int s4115(int* __restrict__ ip)
{

//	indirect addressing
//	sparse dot product
//	gather is required

	clock_t start_t, end_t, clock_dif;


	init( "s4115");
	start_t = clock();

	float sum;
	for (int nl = 0; nl < ntimes; nl++) {
		sum = 0.;
		for (int i = 0; i < LEN; i++) {
			sum += a[i] * b[ip[i]];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S4115\t %8ld \t ", clock_dif);
	temp = sum;
	check(-1);
	return 0;
}
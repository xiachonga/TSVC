#include "common.h"

int s3251()
{

//	scalar and array expansion
//	scalar expansion

	uint64_t start_t, end_t, clock_dif;

	init( "s251 ");
	start_t = rdtsc();


		for (int i = 0; i < LEN-1; i++){
			a[i+1] = b[i]+c[i];
			b[i]   = c[i]*e[i];
			d[i]   = a[i]*e[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S3251\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
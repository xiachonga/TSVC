#include "common.h"

int s251()
{

//	scalar and array expansion
//	scalar expansion

	uint64_t start_t, end_t, clock_dif;


	init( "s251 ");
	start_t = rdtsc();

	float s;

		for (int i = 0; i < LEN; i++) {
			s = b[i] + c[i] * d[i];
			a[i] = s * s;
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S251\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
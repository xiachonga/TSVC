#include "common.h"

int s1251()
{

//	scalar and array expansion
//	scalar expansion

	uint64_t start_t, end_t, clock_dif;


	init( "s251 ");
	start_t = rdtsc();

	float s;

		for (int i = 0; i < LEN; i++) {
			s = b[i]+c[i];
			b[i] = a[i]+d[i];
			a[i] = s*e[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S1251\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
#include "common.h"

int s261()
{

//	scalar and array expansion
//	wrap-around scalar under an if

	uint64_t start_t, end_t, clock_dif;


	init( "s261 ");
	start_t = rdtsc();

	float t;

		for (int i = 1; i < LEN; ++i) {
			t = a[i] + b[i];
			a[i] = t + c[i-1];
			t = c[i] * d[i];
			c[i] = t;
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S261\t %8ld   ", clock_dif);
	check(13);
	return 0;
}
#include "common.h"

int s252()
{

//	scalar and array expansion
//	loop with ambiguous scalar temporary

	uint64_t start_t, end_t, clock_dif;

	init( "s252 ");
	start_t = rdtsc();

	float t, s;

		t = (float) 0.;
		for (int i = 0; i < LEN; i++) {
			s = b[i] * c[i];
			a[i] = s + t;
			t = s;
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S252\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
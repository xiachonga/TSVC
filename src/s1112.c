#include "common.h"

int s1112()
{

//	linear dependence testing
//	loop reversal

	uint64_t start_t, end_t, clock_dif;
	

	init("s112 ");
	start_t = rdtsc();

		for (int i = LEN - 1; i >= 0; i--) {
			a[i] = b[i] + (float) 1.;
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	
	printf("S1112\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
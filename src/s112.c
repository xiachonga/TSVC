#include "common.h"

int s112()
{

//	linear dependence testing
//	loop reversal

	uint64_t start_t, end_t, clock_dif;


	init( "s112 ");
	start_t = rdtsc();


//		#pragma vector always
		for (int i = LEN - 2; i >= 0; i--) {
			a[i+1] = a[i] + b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S112\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
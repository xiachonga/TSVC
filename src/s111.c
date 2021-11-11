#include "common.h"

int s111()
{

//	linear dependence testing
//	no dependence - vectorizable

	uint64_t start_t, end_t, clock_dif;


	init( "s111 ");
	start_t = rdtsc();


//		#pragma vector always
		for (int i = 1; i < LEN; i += 2) {
			a[i] = a[i - 1] + b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S111\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
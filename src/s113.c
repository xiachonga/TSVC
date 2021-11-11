#include "common.h"

int s113()
{

//	linear dependence testing
//	a(i)=a(1) but no actual dependence cycle

	uint64_t start_t, end_t, clock_dif;


	init( "s113 ");
	start_t = rdtsc();


		for (int i = 1; i < LEN; i++) {
			a[i] = a[0] + b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S113\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
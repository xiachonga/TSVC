#include "common.h"

int s293()
{

//	loop peeling
//	a(i)=a(0) with actual dependence cycle, loop is vectorizable

	uint64_t start_t, end_t, clock_dif;

	init( "s293 ");
	start_t = rdtsc();


		for (int i = 0; i < LEN; i++) {
			a[i] = a[0];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S293\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
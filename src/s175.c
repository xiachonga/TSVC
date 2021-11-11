#include "common.h"

int s175(int inc)
{

//	symbolics
//	symbolic dependence tests

	uint64_t start_t, end_t, clock_dif;


	init( "s175 ");
	start_t = rdtsc();


		for (int i = 0; i < LEN-1; i += inc) {
			a[i] = a[i + inc] + b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S175\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
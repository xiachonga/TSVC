#include "common.h"

int s321()
{

//	recurrences
//	first order linear recurrence

	uint64_t start_t, end_t, clock_dif;


	init( "s321 ");
	start_t = rdtsc();


		for (int i = 1; i < LEN; i++) {
			a[i] += a[i-1] * b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S321\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
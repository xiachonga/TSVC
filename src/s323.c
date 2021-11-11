#include "common.h"

int s323()
{

//	recurrences
//	coupled recurrence

	uint64_t start_t, end_t, clock_dif;


	init( "s323 ");
	start_t = rdtsc();


		for (int i = 1; i < LEN; i++) {
			a[i] = b[i-1] + c[i] * d[i];
			b[i] = a[i] + c[i] * e[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S323\t %8ld   ", clock_dif);
	check(12);
	return 0;
}
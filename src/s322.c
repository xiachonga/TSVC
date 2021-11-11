#include "common.h"

int s322()
{

//	recurrences
//	second order linear recurrence

	uint64_t start_t, end_t, clock_dif;


	init( "s322 ");
	start_t = rdtsc();


		for (int i = 2; i < LEN; i++) {
			a[i] = a[i] + a[i - 1] * b[i] + a[i - 2] * c[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S322\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
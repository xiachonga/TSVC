#include "common.h"

int s173()
{
//	symbolics
//	expression in loop bounds and subscripts

	uint64_t start_t, end_t, clock_dif;


	init( "s173 ");
	start_t = rdtsc();

	int k = LEN/2;

		for (int i = 0; i < LEN/2; i++) {
			a[i+k] = a[i] + b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S173\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
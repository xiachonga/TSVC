#include "common.h"

int s121()
{

//	induction variable recognition
//	loop with possible ambiguity because of scalar store

	uint64_t start_t, end_t, clock_dif;


	init( "s121 ");
	start_t = rdtsc();

	int j;

		for (int i = 0; i < LEN-1; i++) {
			j = i + 1;
			a[i] = a[j] + b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S121\t %8ld   ", clock_dif);
	check(1);
	return 0;
}

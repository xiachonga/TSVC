#include "common.h"

int s174(int M)
{

//	symbolics
//	loop with subscript that may seem ambiguous

	uint64_t start_t, end_t, clock_dif;


	init( "s174 ");
	start_t = rdtsc();


		for (int i = 0; i < M; i++) {
			a[i+M] = a[i] + b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S174\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
#include "common.h"

int s1351()
{

//	induction pointer recognition

	uint64_t start_t, end_t, clock_dif;

	init( "s351 ");
	start_t = rdtsc();


		float* __restrict__ A = a;
		float* __restrict__ B = b;
		float* __restrict__ C = c;
		for (int i = 0; i < LEN; i++) {
			*A = *B+*C;
			A++;
			B++;
			C++;
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S1351\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
#include "common.h"

int s453()
{

//	induction varibale recognition

	float s;
	uint64_t start_t, end_t, clock_dif;


	init( "s453 ");
	start_t = rdtsc();

		s = 0.;
		for (int i = 0; i < LEN; i++) {
			s += (float)2.;
			a[i] = s * b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S453\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
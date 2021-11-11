#include "common.h"

int s1111()
{

//	no dependence - vectorizable
//	jump in data access

	uint64_t start_t, end_t, clock_dif;

	init("s111 ");
	start_t = rdtsc();

		for (int i = 0; i < LEN/2; i++) {
			a[2*i] = c[i] * b[i] + d[i] * b[i] + c[i] * c[i] + d[i] * b[i] + d[i] * c[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	
	printf("S1111\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
#include "common.h"

int s152s(float a[LEN], float b[LEN], float c[LEN], int i)
{
	a[i] += b[i] * c[i];
	return 0;
}

int s152()
{

//	interprocedural data flow analysis
//	collecting information from a subroutine
	uint64_t start_t, end_t, clock_dif;


	init( "s152 ");
	start_t = rdtsc();


		for (int i = 0; i < LEN; i++) {
			b[i] = d[i] * e[i];
			s152s(a, b, c, i);
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S152\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
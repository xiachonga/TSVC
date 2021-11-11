#include "common.h"

int s151s(float a[LEN], float b[LEN],  int m)
{
	for (int i = 0; i < LEN-1; i++) {
		a[i] = a[i + m] + b[i];
	}
	return 0;
}
int s151()
{

//	interprocedural data flow analysis
//	passing parameter information into a subroutine

	uint64_t start_t, end_t, clock_dif;
	init( "s151 ");
	start_t = rdtsc();


		s151s(a, b,  1);
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S151\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
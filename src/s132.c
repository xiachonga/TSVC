#include "common.h"

int s132()
{
//	global data flow analysis
//	loop with multiple dimension ambiguous subscripts

	uint64_t start_t, end_t, clock_dif;

	init( "s132 ");
	start_t = rdtsc();

	int m = 0;
	int j = m;
	int k = m+1;

		for (int i= 1; i < LEN2; i++) {
			aa[j][i] = aa[k][i-1] + b[i] * c[1];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S132\t %8ld   ", clock_dif);
	check(11);
	return 0;
}
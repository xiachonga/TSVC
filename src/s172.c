#include "common.h"

int s172( int n1, int n3)
{
//	symbolics
//	vectorizable if n3 .ne. 0

	uint64_t start_t, end_t, clock_dif;


	init( "s172 ");
	start_t = rdtsc();


		for (int i = n1-1; i < LEN; i += n3) {
			a[i] += b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S172\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
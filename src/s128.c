#include "common.h"

int s128()
{

//	induction variables
//	coupled induction variables
//	jump in data access

	uint64_t start_t, end_t, clock_dif;


	init( "s128 ");
	start_t = rdtsc();

	int j, k;

		j = -1;
		for (int i = 0; i < LEN/2; i++) {
			k = j + 1;
			a[i] = b[k] - d[i];
			j = k + 1;
			b[k] = a[i] + c[k];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S128\t %8ld   ", clock_dif);
	check(12);
	return 0;
}
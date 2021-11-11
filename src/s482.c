#include "common.h"

int s482()
{

//	non-local goto's
//	other loop exit with code before exit

	uint64_t start_t, end_t, clock_dif;


	init( "s482 ");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			a[i] += b[i] * c[i];
			if (c[i] > b[i]) break;
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S482\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
#include "common.h"

int s341()
{

//	packing
//	pack positive values
//	not vectorizable, value of j in unknown at each iteration

	uint64_t start_t, end_t, clock_dif;

	init( "s341 ");
	start_t = rdtsc();

	int j;

		j = -1;
		for (int i = 0; i < LEN; i++) {
			if (b[i] > (float)0.) {
				j++;
				a[j] = b[i];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S341\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
#include "common.h"

int s342()
{

//	packing
//	unpacking
//	not vectorizable, value of j in unknown at each iteration

	uint64_t start_t, end_t, clock_dif;

	init( "s342 ");
	start_t = rdtsc();

	int j = 0;

		j = -1;
		for (int i = 0; i < LEN; i++) {
			if (a[i] > (float)0.) {
				j++;
				a[i] = b[j];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S342\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
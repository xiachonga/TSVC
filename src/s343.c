#include "common.h"

int s343()
{

//	packing
//	pack 2-d array into one dimension
//	not vectorizable, value of k in unknown at each iteration

	uint64_t start_t, end_t, clock_dif;

	init( "s343 ");
	start_t = rdtsc();

	int k;

		k = -1;
		for (int i = 0; i < LEN2; i++) {
			for (int j = 0; j < LEN2; j++) {
				if (bb[j][i] > (float)0.) {
					k++;
					array[k] = aa[j][i];
				}
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S343\t %8ld   ", clock_dif);
	check(0);
	return 0;
}
#include "common.h"

int s2712()
{

//	control flow
//	if to elemental min

	uint64_t start_t, end_t, clock_dif;


	init( "s2712");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			if (a[i] > b[i]) {
				a[i] += b[i] * c[i];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S2712\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
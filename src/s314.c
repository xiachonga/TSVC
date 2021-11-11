#include "common.h"

int s314()
{

//	reductions
//	if to max reduction

	uint64_t start_t, end_t, clock_dif;


	init( "s314 ");
	start_t = rdtsc();

	float x;

		x = a[0];
		for (int i = 0; i < LEN; i++) {
			if (a[i] > x) {
				x = a[i];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S314\t %8ld   ", clock_dif);
	temp = x;
	check(-1);
	return 0;
}
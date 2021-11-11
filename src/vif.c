#include "common.h"

int vif()
{

//	control loops
//	vector if

	uint64_t start_t, end_t, clock_dif;


	init( "vif  ");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			if (b[i] > (float)0.) {
				a[i] = b[i];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("vif\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
#include "common.h"

int s331()
{

//	search loops
//	if to last-1

	uint64_t start_t, end_t, clock_dif;


	init( "s331 ");
	start_t = rdtsc();

	int j;
	float chksum;

		j = -1;
		for (int i = 0; i < LEN; i++) {
			if (a[i] < (float)0.) {
				j = i;
			}
		}
		chksum = (float) j;
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S331\t %8ld   ", clock_dif);
	temp = j+1;
	check(-1);
	return 0;
}
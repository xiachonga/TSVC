#include "common.h"

int s4117()
{

//	indirect addressing
//	seq function

	uint64_t start_t, end_t, clock_dif;


	init( "s4117");
	start_t = rdtsc();


		for (int i = 0; i < LEN; i++) {
			a[i] = b[i] + c[i/2] * d[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S4117\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
#include "common.h"

int va()
{

//	control loops
//	vector assignment

	uint64_t start_t, end_t, clock_dif;

	init( "va	");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			a[i] = b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("va\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
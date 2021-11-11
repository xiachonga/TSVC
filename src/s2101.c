#include "common.h"

int s2101()
{

//	diagonals
//	main diagonal calculation
//	jump in data access

	uint64_t start_t, end_t, clock_dif;


	init( "s2101");
	start_t = rdtsc();

		for (int i = 0; i < LEN2; i++) {
			aa[i][i] += bb[i][i] * cc[i][i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S2101\t %8ld   ", clock_dif);
	check(11);
	return 0;
}
#include "common.h"

int s114()
{

//	linear dependence testing
//	transpose vectorization
//	Jump in data access - not vectorizable

	uint64_t start_t, end_t, clock_dif;


	init( "s114 ");
	start_t = rdtsc();


		for (int i = 0; i < LEN2; i++) {
			for (int j = 0; j < i; j++) {
				aa[i][j] = aa[j][i] + bb[i][j];
			}
		}
		

	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S114\t %8ld   ", clock_dif);
	check(11);
	return 0;
}
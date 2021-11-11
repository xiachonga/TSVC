#include "common.h"

int s1119()
{

//	linear dependence testing
//	no dependence - vectorizable

	uint64_t start_t, end_t, clock_dif;
	

	init("s119 ");
	start_t = rdtsc();

		for (int i = 1; i < LEN2; i++) {
			for (int j = 0; j < LEN2; j++) {
				aa[i][j] = aa[i-1][j] + bb[i][j];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	
	
	printf("S1119\t %8ld   ", clock_dif);
	check(11);
	return 0;
}
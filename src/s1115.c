#include "common.h"

int s1115()
{

//	linear dependence testing
//	triangular saxpy loop

	uint64_t start_t, end_t, clock_dif;


	init( "s115 ");
	start_t = rdtsc();

		for (int i = 0; i < LEN2; i++) {
			for (int j = 0; j < LEN2; j++) {
				aa[i][j] = aa[i][j]*cc[j][i] + bb[i][j];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S1115\t %8ld   ", clock_dif);
	check(11);
	return 0;
}
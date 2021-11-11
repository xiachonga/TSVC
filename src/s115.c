#include "common.h"

int s115()
{

//	linear dependence testing
//	triangular saxpy loop

	uint64_t start_t, end_t, clock_dif;


	init( "s115 ");
	start_t = rdtsc();


		for (int j = 0; j < LEN2; j++) {
			for (int i = j+1; i < LEN2; i++) {
				a[i] -= aa[j][i] * a[j];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S115\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
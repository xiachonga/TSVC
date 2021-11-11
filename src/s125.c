#include "common.h"

int s125()
{

//	induction variable recognition
//	induction variable in two loops; collapsing possible

	uint64_t start_t, end_t, clock_dif;


	init( "s125 ");
	start_t = rdtsc();

	int k;

		k = -1;
		for (int i = 0; i < LEN2; i++) {
			for (int j = 0; j < LEN2; j++) {
				k++;
				array[k] = aa[i][j] + bb[i][j] * cc[i][j];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S125\t %8ld   ", clock_dif);
	check(0);
	return 0;
}
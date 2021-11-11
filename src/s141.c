#include "common.h"

int s141()
{

//	nonlinear dependence testing
//	walk a row in a symmetric packed array
//	element a(i,j) for (int j>i) stored in location j*(j-1)/2+i

	uint64_t start_t, end_t, clock_dif;


	init( "s141 ");
	start_t = rdtsc();

	int k;

		for (int i = 0; i < LEN2; i++) {
			k = (i+1) * ((i+1) - 1) / 2 + (i+1)-1;
			for (int j = i; j < LEN2; j++) {
				array[k] += bb[j][i];
				k += j+1;
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S141\t %8ld   ", clock_dif);
	check(0);
	return 0;
}
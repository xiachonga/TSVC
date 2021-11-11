#include "common.h"

int s232()
{

//	loop interchange
//	interchanging of triangular loops

	uint64_t start_t, end_t, clock_dif;


	init( "s232 ");
	start_t = rdtsc();


		for (int j = 1; j < LEN2; j++) {
			for (int i = 1; i <= j; i++) {
				aa[j][i] = aa[j][i-1]*aa[j][i-1]+bb[j][i];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S232\t %8ld   ", clock_dif);
	check(11);
	return 0;
}
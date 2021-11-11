#include "common.h"

int s1232()
{

//	loop interchange
//	interchanging of triangular loops

	uint64_t start_t, end_t, clock_dif;


	init( "s232 ");
	start_t = rdtsc();

		for (int j = 0; j < LEN2; j++) {
			for (int i = j; i < LEN2; i++) {
				aa[i][j] = bb[i][j] + cc[i][j];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S1232\t %8ld   ", clock_dif);
	check(11);
	return 0;
}
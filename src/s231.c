#include "common.h"

int s231()
{
//	loop interchange
//	loop with data dependency

	uint64_t start_t, end_t, clock_dif;


	init( "s231 ");
	start_t = rdtsc();


		for (int i = 0; i < LEN2; ++i) {
			for (int j = 1; j < LEN2; j++) {
				aa[j][i] = aa[j - 1][i] + bb[j][i];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S231\t %8ld   ", clock_dif);
	check(11);
	return 0;
}
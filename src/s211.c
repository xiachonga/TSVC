#include "common.h"

int s211()
{

//	statement reordering
//	statement reordering allows vectorization

	uint64_t start_t, end_t, clock_dif;


	init( "s211 ");
	start_t = rdtsc();


		for (int i = 1; i < LEN-1; i++) {
			a[i] = b[i - 1] + c[i] * d[i];
			b[i] = b[i + 1] - e[i] * d[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S211\t %8ld   ", clock_dif);
	check(12);
	return 0;
}
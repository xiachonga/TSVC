#include "common.h"

int s176()
{

//	symbolics
//	convolution

	uint64_t start_t, end_t, clock_dif;


	init( "s176 ");
	start_t = rdtsc();

	int m = LEN/2;

		for (int j = 0; j < (LEN/2); j++) {
			for (int i = 0; i < m; i++) {
				a[i] += b[i+m-j-1] * c[j];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S176\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
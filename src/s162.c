#include "common.h"

int s162(int k)
{
//	control flow
//	deriving assertions

	uint64_t start_t, end_t, clock_dif;


	init( "s162 ");
	start_t = rdtsc();


		if (k > 0) {
			for (int i = 0; i < LEN-1; i++) {
				a[i] = a[i + k] + b[i] * c[i];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S162\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
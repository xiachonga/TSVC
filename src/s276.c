
#include "common.h"

int s276()
{

//	control flow
//	if test using loop index

	uint64_t start_t, end_t, clock_dif;


	init( "s276 ");
	start_t = rdtsc();

	int mid = (LEN/2);

		for (int i = 0; i < LEN; i++) {
			if (i+1 < mid) {
				a[i] += b[i] * c[i];
			} else {
				a[i] += b[i] * d[i];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S276\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
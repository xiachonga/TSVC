#include "common.h"

int s124()
{

//	induction variable recognition
//	induction variable under both sides of if (same value)

	uint64_t start_t, end_t, clock_dif;


	init( "s124 ");
	start_t = rdtsc();

	int j;

		j = -1;
		for (int i = 0; i < LEN; i++) {
			if (b[i] > (float)0.) {
				j++;
				a[j] = b[i] + d[i] * e[i];
			} else {
				j++;
				a[j] = c[i] + d[i] * e[i];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S124\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
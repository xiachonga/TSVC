#include "common.h"

int s2275()
{

//	loop distribution is needed to be able to interchange

	uint64_t start_t, end_t, clock_dif;


	init( "s275 ");
	start_t = rdtsc();

		for (int i = 0; i < LEN2; i++) {
			for (int j = 0; j < LEN2; j++) {
				aa[j][i] = aa[j][i] + bb[j][i] * cc[j][i];
			}
			a[i] = b[i] + c[i] * d[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S2275\t %8ld   ", clock_dif);
	check(11);
	return 0;
}
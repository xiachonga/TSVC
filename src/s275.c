#include "common.h"

int s275()
{

//	control flow
//	if around inner loop, interchanging needed

	uint64_t start_t, end_t, clock_dif;


	init( "s275 ");
	start_t = rdtsc();


		for (int i = 0; i < LEN2; i++) {
			if (aa[0][i] > (float)0.) {
				for (int j = 1; j < LEN2; j++) {
					aa[j][i] = aa[j-1][i] + bb[j][i] * cc[j][i];
				}
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S275\t %8ld   ", clock_dif);
	check(11);
	return 0;
}
#include "common.h"

int s331()
{

//	search loops
//	if to last-1

	clock_t start_t, end_t, clock_dif;


	init( "s331 ");
	start_t = clock();

	int j;
	float chksum;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		j = -1;
		for (int i = 0; i < LEN; i++) {
			if (a[i] < (float)0.) {
				j = i;
			}
		}
		chksum = (float) j;
		dummy(a, b, c, d, e, aa, bb, cc, chksum);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S331\t %8ld \t ", clock_dif);
	temp = j+1;
	check(-1);
	return 0;
}
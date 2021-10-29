#include "common.h"

int s318( int inc)
{

//	reductions
//	isamax, max absolute value, increments not equal to 1


	clock_t start_t, end_t, clock_dif;


	init( "s318 ");
	start_t = clock();

	int k, index;
	float max, chksum;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes/2; nl++) {
		k = 0;
		index = 0;
		max = abs(a[0]);
		k += inc;
		for (int i = 1; i < LEN; i++) {
			if (abs(a[k]) <= max) {
				goto L5;
			}
			index = i;
			max = abs(a[k]);
L5:
			k += inc;
		}
		chksum = max + (float) index;
		dummy(a, b, c, d, e, aa, bb, cc, chksum);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S318\t %8ld \t ", clock_dif);
	temp = max + index+1;
	check(-1);
	return 0;
}
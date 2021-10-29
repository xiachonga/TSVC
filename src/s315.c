#include "common.h"

int s315()
{

//	reductions
//	if to max with index reductio 1 dimension

	clock_t start_t, end_t, clock_dif;


	init( "s315 ");
	for (int i = 0; i < LEN; i++)
		a[i] = (i * 7) % LEN;
	start_t = clock();

	float x, chksum;
	int index;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		x = a[0];
		index = 0;
		for (int i = 0; i < LEN; ++i) {
			if (a[i] > x) {
				x = a[i];
				index = i;
			}
		}
		chksum = x + (float) index;
		dummy(a, b, c, d, e, aa, bb, cc, chksum);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S315\t %8ld \t ", clock_dif);
	temp = index+x+1;
	check(-1);
	return 0;
}
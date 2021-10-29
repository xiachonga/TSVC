#include "common.h"

int s122(int n1, int n3)
{

//	induction variable recognition
//	variable lower and upper bound, and stride
//	reverse data access and jump in data access

	clock_t start_t, end_t, clock_dif;


	init( "s122 ");
	start_t = clock();

	int j, k;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		j = 1;
		k = 0;
		for (int i = n1-1; i < LEN; i += n3) {
			k += j;
			a[i] += b[LEN - k];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S122\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
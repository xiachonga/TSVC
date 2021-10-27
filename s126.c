#include "common.h"

int s126()
{

//	induction variable recognition
//	induction variable in two loops; recurrence in inner loop

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s126 ");
	start_t = clock();

	int k;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 10*(ntimes/LEN2); nl++) {
		k = 1;
		for (int i = 0; i < LEN2; i++) {
			for (int j = 1; j < LEN2; j++) {
				bb[j][i] = bb[j-1][i] + array[k-1] * cc[j][i];
				++k;
			}
			++k;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S126\t %.2f \t\t", clock_dif_sec);;
	check(22);
	return 0;
}
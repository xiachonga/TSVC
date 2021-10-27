#include "common.h"

int s125()
{

//	induction variable recognition
//	induction variable in two loops; collapsing possible

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s125 ");
	start_t = clock();

	int k;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 100*(ntimes/(LEN2)); nl++) {
		k = -1;
		for (int i = 0; i < LEN2; i++) {
			for (int j = 0; j < LEN2; j++) {
				k++;
				array[k] = aa[i][j] + bb[i][j] * cc[i][j];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S125\t %.2f \t\t", clock_dif_sec);;
	check(0);
	return 0;
}
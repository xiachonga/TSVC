#include "common.h"

int s235()
{

//	loop interchanging
//	imperfectly nested loops

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s235 ");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 200*(ntimes/LEN2); nl++) {
		for (int i = 0; i < LEN2; i++) {
			a[i] += b[i] * c[i];
			for (int j = 1; j < LEN2; j++) {
				aa[j][i] = aa[j-1][i] + bb[j][i] * a[i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S235\t %.2f \t\t", clock_dif_sec);;
	check(111);
	return 0;
}
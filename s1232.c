#include "common.h"

int s1232()
{

//	loop interchange
//	interchanging of triangular loops

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s232 ");
	start_t = clock();
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 100*(ntimes/LEN2); nl++) {
		for (int j = 0; j < LEN2; j++) {
			for (int i = j; i < LEN2; i++) {
				aa[i][j] = bb[i][j] + cc[i][j];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 1.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S1232\t %.2f \t\t", clock_dif_sec);;
	check(11);
	return 0;
}
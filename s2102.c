#include "common.h"

int s2102()
{

//	diagonals
//	identity matrix, best results vectorize both inner and outer loops

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s2102");
	start_t = clock();
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 100*(ntimes/LEN2); nl++) {
		for (int i = 0; i < LEN2; i++) {
			for (int j = 0; j < LEN2; j++) {
				aa[j][i] = (float)0.;
			}
			aa[i][i] = (float)1.;
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S2102\t %.2f \t\t", clock_dif_sec);;
	check(11);
	return 0;
}
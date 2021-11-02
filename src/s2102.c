#include "common.h"

int s2102()
{

//	diagonals
//	identity matrix, best results vectorize both inner and outer loops

	clock_t start_t, end_t, clock_dif;


	init( "s2102");
	start_t = clock();
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
	printf("S2102\t %8ld \t ", clock_dif);
	check(11);
	return 0;
}
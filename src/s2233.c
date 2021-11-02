#include "common.h"

int s2233()
{

//	loop interchange
//	interchanging with one of two inner loops

	clock_t start_t, end_t, clock_dif;


	init( "s233 ");
	start_t = clock();
	for (int nl = 0; nl < REPETITIONS; nl++) {
		for (int i = 1; i < LEN2; i++) {
			for (int j = 1; j < LEN2; j++) {
				aa[j][i] = aa[j-1][i] + cc[j][i];
			}
			for (int j = 1; j < LEN2; j++) {
				bb[i][j] = bb[i-1][j] + cc[i][j];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S2233\t %6d   %8ld   ", REPETITIONS, clock_dif);
	check(1122);
	return 0;
}
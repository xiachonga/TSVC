#include "common.h"

int s123()
{

//	induction variable recognition
//	induction variable under an if
//	not vectorizable, the condition cannot be speculated

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s123 ");
	start_t = clock();

	int j;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		j = -1;
		for (int i = 0; i < (LEN/2); i++) {
			j++;
			a[j] = b[i] + d[i] * e[i];
			if (c[i] > (float)0.) {
				j++;
				a[j] = c[i] + d[i] * e[i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S123\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
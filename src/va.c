#include "common.h"

int va()
{

//	control loops
//	vector assignment

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;

	init( "va	");
	start_t = clock();
	for (int nl = 0; nl < ntimes*10; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[i] = b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("va\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
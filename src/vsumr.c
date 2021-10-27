#include "common.h"

int vsumr()
{

//	control loops
//	vector sum reduction

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "vsumr");
	start_t = clock();

	float sum;
	for (int nl = 0; nl < ntimes*10; nl++) {
		sum = 0.;
		for (int i = 0; i < LEN; i++) {
			sum += a[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, sum);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("vsumr\t %.2f \t\t", clock_dif_sec);;
	check(1);
	return 0;
}
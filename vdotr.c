#include "common.h"

int vdotr()
{

//	control loops
//	vector dot product reduction

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "vdotr");
	start_t = clock();

	float dot;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes*10; nl++) {
		dot = 0.;
		for (int i = 0; i < LEN; i++) {
			dot += a[i] * b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, dot);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("vdotr\t %.2f \t\t", clock_dif_sec);;
	temp = dot;
	check(-1);
	return 0;
}
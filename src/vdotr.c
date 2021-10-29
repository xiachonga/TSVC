#include "common.h"

int vdotr()
{

//	control loops
//	vector dot product reduction

	clock_t start_t, end_t, clock_dif;


	init( "vdotr");
	start_t = clock();

	float dot;
	for (int nl = 0; nl < ntimes*10; nl++) {
		dot = 0.;
		for (int i = 0; i < LEN; i++) {
			dot += a[i] * b[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, dot);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("vdotr\t %8ld \t ", clock_dif);
	temp = dot;
	check(-1);
	return 0;
}
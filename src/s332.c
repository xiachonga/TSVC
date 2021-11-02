#include "common.h"

int s332( float t)
{

//	search loops
//	first value greater than threshoLEN

	clock_t start_t, end_t, clock_dif;


	init( "s332 ");
	start_t = clock();

	int index;
	float value;
	float chksum;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		index = -2;
		value = -1.;
		for (int i = 0; i < LEN; i++) {
			if (a[i] > t) {
				index = i;
				value = a[i];
				goto L20;
			}
		}
L20:
		chksum = value + (float) index;
		dummy(a, b, c, d, e, aa, bb, cc, chksum);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S332\t %8d   %8ld   ", REPETITIONS, clock_dif);
	temp = value;
	check(-1);
	return 0;
}
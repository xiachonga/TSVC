#include "common.h"

int s332( float t)
{

//	search loops
//	first value greater than threshoLEN

	uint64_t start_t, end_t, clock_dif;


	init( "s332 ");
	start_t = rdtsc();

	int index;
	float value;
	float chksum;

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
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S332\t %8ld   ", clock_dif);
	temp = value;
	check(-1);
	return 0;
}
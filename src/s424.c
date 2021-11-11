#include "common.h"

int s424()
{

//	storage classes and equivalencing
//	common and equivalenced variables - overlap
//	vectorizeable in strips of 64 or less

	int vl = 63;
	xx = array + vl;
	set1d(xx, 0., 1);
	uint64_t start_t, end_t, clock_dif;
	init( "s424 ");
	start_t = rdtsc();

		for (int i = 0; i < LEN - 1; i++) {
			xx[i+1] = array[i] + a[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S424\t %8ld   ", clock_dif);
	temp = 0.;
	for (int i = 0; i < LEN; i++){
		temp += xx[i];
	}
	check(-1);
	return 0;
}
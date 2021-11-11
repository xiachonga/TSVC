#include "common.h"

int s421()
{

//	storage classes and equivalencing
//	equivalence- no overlap

	set1d(xx, 1., 1);
	uint64_t start_t, end_t, clock_dif;
	init( "s421 ");
	start_t = rdtsc();


		yy = xx;
		for (int i = 0; i < LEN - 1; i++) {
			xx[i] = yy[i+1] + a[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S421\t %8ld   ", clock_dif);
	temp = 0;
	for (int i = 0; i < LEN; i++){
		temp += xx[i];
	}
	check(-1);
	return 0;
}
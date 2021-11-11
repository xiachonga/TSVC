#include "common.h"

int vtvtv()
{

//	control loops
//	vector times vector times vector

	uint64_t start_t, end_t, clock_dif;


	init( "vtvtv");
	start_t = rdtsc();


		for (int i = 0; i < LEN; i++) {
			a[i] = a[i] * b[i] * c[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("vtvtv\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
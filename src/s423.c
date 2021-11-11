#include "common.h"

int s423()
{

//	storage classes and equivalencing
//	common and equivalenced variables - with anti-dependence

	int vl = 64;
	xx = array+vl;
	set1d(xx, 1., 1);
	uint64_t start_t, end_t, clock_dif;
	init( "s423 ");
	start_t = rdtsc();

		for (int i = 0; i < LEN - 1; i++) {
			array[i+1] = xx[i] + a[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S423\t %8ld   ", clock_dif);

	temp = 0.;
	for (int i = 0; i < LEN; i++){
		temp += array[i];
	}
	check(-1);
	return 0;
}
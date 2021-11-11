#include "common.h"

int s118()
{

//	linear dependence testing
//	potential dot product recursion

	uint64_t start_t, end_t, clock_dif;


	init( "s118 ");
	start_t = rdtsc();


		for (int i = 1; i < LEN2; i++) {
			for (int j = 0; j <= i - 1; j++) {
				a[i] += bb[j][i] * a[i-j-1];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S118\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
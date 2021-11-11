#include "common.h"

int s257()
{

//	scalar and array expansion
//	array expansion

	uint64_t start_t, end_t, clock_dif;


	init( "s257 ");
	start_t = rdtsc();


		for (int i = 1; i < LEN2; i++) {
			for (int j = 0; j < LEN2; j++) {
				a[i] = aa[j][i] - a[i-1];
				aa[j][i] = a[i] + bb[j][i];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S257\t %8ld   ", clock_dif);
	check(111);
	return 0;
}
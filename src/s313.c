#include "common.h"

int s313()
{

//	reductions
//	dot product

	uint64_t start_t, end_t, clock_dif;


	init( "s313 ");
	start_t = rdtsc();

	float dot;

		dot = (float)0.;
		for (int i = 0; i < LEN; i++) {
			dot += a[i] * b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S313\t %8ld   ", clock_dif);
	temp = dot;
	check(-1);
	return 0;
}
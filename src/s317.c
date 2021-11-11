#include "common.h"

int s317()
{

//	reductions
//	product reductio vectorize with
//	1. scalar expansion of factor, and product reduction
//	2. closed form solution: q = factor**n

	uint64_t start_t, end_t, clock_dif;


	init( "s317 ");
	start_t = rdtsc();

	float q;

		q = (float)1.;
		for (int i = 0; i < LEN/2; i++) {
			q *= (float).99;
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S317\t %8ld   ", clock_dif);
	temp = q;
	check(-1);
	return 0;
}
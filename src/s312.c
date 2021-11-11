#include "common.h"

int s312()
{

//	reductions
//	product reduction

	uint64_t start_t, end_t, clock_dif;


	init( "s312 ");
	start_t = rdtsc();

	float prod;

		prod = (float)1.;
		for (int i = 0; i < LEN; i++) {
			prod *= a[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S312\t %8ld   ", clock_dif);
	temp = prod;
	check(-1);
	return 0;
}
#include "common.h"

int s312()
{

//	reductions
//	product reduction

	clock_t start_t, end_t, clock_dif;


	init( "s312 ");
	start_t = clock();

	float prod;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		prod = (float)1.;
		for (int i = 0; i < LEN; i++) {
			prod *= a[i];
		}
		dummy(a, b, c, d, e, aa, bb, cc, prod);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S312\t %8d   %8ld   ", REPETITIONS, clock_dif);
	temp = prod;
	check(-1);
	return 0;
}
#include "common.h"

int s317()
{

//	reductions
//	product reductio vectorize with
//	1. scalar expansion of factor, and product reduction
//	2. closed form solution: q = factor**n

	clock_t start_t, end_t, clock_dif;


	init( "s317 ");
	start_t = clock();

	float q;
	for (int nl = 0; nl < REPETITIONS; nl++) {
		q = (float)1.;
		for (int i = 0; i < LEN/2; i++) {
			q *= (float).99;
		}
		dummy(a, b, c, d, e, aa, bb, cc, q);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S317\t %8d   %8ld   ", REPETITIONS, clock_dif);
	temp = q;
	check(-1);
	return 0;
}
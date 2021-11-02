#include "common.h"

int s000()
{

//	linear dependence testing
//	no dependence - vectorizable

	clock_t start_t, end_t, clock_dif;


	init( "s000 ");
	start_t = clock();

	for (int nl = 0; nl < 2*ntimes; nl++) {
		for (int i = 0; i < lll; i++) {
			a[i] = b[i] + c[i];
			X[i] = (Y[i] * Z[i])+(U[i]*V[i]);
			X[i] = Y[i] + 1;
		}
		dummy((float*)X, (float*)Y, (float*)Z, (float*)U, (float*)V, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S000\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
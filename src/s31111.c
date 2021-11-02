#include "common.h"

float test(float* A){
  float s = (float)0.0;
//  #pragma nosimd
  for (int i = 0; i < 4; i++)
    s += A[i];
  return s;
}

int s31111()
{

//	reductions
//	sum reduction

	clock_t start_t, end_t, clock_dif;


	init( "s311 ");
	start_t = clock();

	float sum;
	for (int nl = 0; nl < 2000*ntimes; nl++) {
		sum = (float)0.;
		sum += test(a);
		sum += test(&a[4]);
		sum += test(&a[8]);
		sum += test(&a[12]);
		sum += test(&a[16]);
		sum += test(&a[20]);
		sum += test(&a[24]);
		sum += test(&a[28]);
		dummy(a, b, c, d, e, aa, bb, cc, sum);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S31111\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
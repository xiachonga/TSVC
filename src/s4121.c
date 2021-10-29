#include "common.h"

inline float f(float a, float b){
	return a*b;
}

int s4121()
{

//	statement functions
//	elementwise multiplication

	clock_t start_t, end_t, clock_dif;


	init( "s4121");
	start_t = clock();

	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < ntimes; nl++) {
		for (int i = 0; i < LEN; i++) {
			a[i] += f(b[i],c[i]);
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S4121\t %8ld \t ", clock_dif);
	check(1);
	return 0;
}
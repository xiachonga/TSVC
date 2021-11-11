#include "common.h"

inline float f(float a, float b){
	return a*b;
}

int s4121()
{

//	statement functions
//	elementwise multiplication

	uint64_t start_t, end_t, clock_dif;


	init( "s4121");
	start_t = rdtsc();


		for (int i = 0; i < LEN; i++) {
			a[i] += f(b[i],c[i]);
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S4121\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
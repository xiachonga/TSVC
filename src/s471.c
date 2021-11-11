#include "common.h"

inline int s471s(void)
{
// --  dummy subroutine call made in s471
	return 0;
}

int s471(){

//	call statements

	int m = LEN;
	set1d(x, 0., 1);
	uint64_t start_t, end_t, clock_dif;


	init( "s471 ");
	start_t = rdtsc();

		for (int i = 0; i < m; i++) {
			x[i] = b[i] + d[i] * d[i];
			s471s();
			b[i] = c[i] + d[i] * e[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S471\t %8ld   ", clock_dif);
	temp = 0.;
	for (int i = 0; i < LEN; i++){
		temp += x[i];
	}
	check(-12);
	return 0;
}
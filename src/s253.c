#include "common.h"

int s253()
{

//	scalar and array expansion
//	scalar expansio assigned under if

	uint64_t start_t, end_t, clock_dif;


	init( "s253 ");
	start_t = rdtsc();

	float s;

		for (int i = 0; i < LEN; i++) {
			if (a[i] > b[i]) {
				s = a[i] - b[i] * d[i];
				c[i] += s;
				a[i] = s;
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S253\t %8ld   ", clock_dif);
	check(13);
	return 0;
}
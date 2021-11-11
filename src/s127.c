#include "common.h"

int s127()
{

//	induction variable recognition
//	induction variable with multiple increments

	uint64_t start_t, end_t, clock_dif;


	init( "s127 ");
	start_t = rdtsc();

	int j;

		j = -1;
		for (int i = 0; i < LEN/2; i++) {
			j++;
			a[j] = b[i] + c[i] * d[i];
			j++;
			a[j] = b[i] + d[i] * e[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S127\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
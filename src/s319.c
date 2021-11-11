#include "common.h"

int s319()
{

//	reductions
//	coupled reductions

	uint64_t start_t, end_t, clock_dif;


	init( "s319 ");
	start_t = rdtsc();

	float sum;

		sum = 0.;
		for (int i = 0; i < LEN; i++) {
			a[i] = c[i] + d[i];
			sum += a[i];
			b[i] = c[i] + e[i];
			sum += b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S319\t %8ld   ", clock_dif);
	temp = sum;
	check(-1);
	return 0;
}
#include "common.h"

int s122(int n1, int n3)
{

//	induction variable recognition
//	variable lower and upper bound, and stride
//	reverse data access and jump in data access

	uint64_t start_t, end_t, clock_dif;


	init( "s122 ");
	start_t = rdtsc();

	int j, k;

		j = 1;
		k = 0;
		for (int i = n1-1; i < LEN; i += n3) {
			k += j;
			a[i] += b[LEN - k];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S122\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
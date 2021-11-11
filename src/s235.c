#include "common.h"

int s235()
{

//	loop interchanging
//	imperfectly nested loops

	uint64_t start_t, end_t, clock_dif;


	init( "s235 ");
	start_t = rdtsc();


		for (int i = 0; i < LEN2; i++) {
			a[i] += b[i] * c[i];
			for (int j = 1; j < LEN2; j++) {
				aa[j][i] = aa[j-1][i] + bb[j][i] * a[i];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S235\t %8ld   ", clock_dif);
	check(111);
	return 0;
}
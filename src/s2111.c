#include "common.h"

int s2111()
{

//	wavefronts, it will make jump in data access

	uint64_t start_t, end_t, clock_dif;


	init( "s2111");
	start_t = rdtsc();

		for (int j = 1; j < LEN2; j++) {
			for (int i = 1; i < LEN2; i++) {
				aa[j][i] = aa[j][i-1] + aa[j-1][i];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S2111\t %8ld   ", clock_dif);
	temp = 0.;
	for (int i = 0; i < LEN2; i++)
		for (int j = 0; j < LEN2; j++)
			temp += aa[i][j];
	if (temp == 0) temp = 3.;	
	check(-1);
	return 0;
}
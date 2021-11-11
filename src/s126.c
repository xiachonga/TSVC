#include "common.h"

int s126()
{

//	induction variable recognition
//	induction variable in two loops; recurrence in inner loop

	uint64_t start_t, end_t, clock_dif;


	init( "s126 ");
	start_t = rdtsc();

	int k;

		k = 1;
		for (int i = 0; i < LEN2; i++) {
			for (int j = 1; j < LEN2; j++) {
				bb[j][i] = bb[j-1][i] + array[k-1] * cc[j][i];
				++k;
			}
			++k;
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S126\t %8ld   ", clock_dif);
	check(22);
	return 0;
}
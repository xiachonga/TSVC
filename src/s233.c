#include "common.h"

int s233()
{

//	loop interchange
//	interchanging with one of two inner loops

	uint64_t start_t, end_t, clock_dif;


	init( "s233 ");
	start_t = rdtsc();


		for (int i = 1; i < LEN2; i++) {
			for (int j = 1; j < LEN2; j++) {
				aa[j][i] = aa[j-1][i] + cc[j][i];
			}
			for (int j = 1; j < LEN2; j++) {
				bb[j][i] = bb[j][i-1] + cc[j][i];
			}
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S233\t %8ld   ", clock_dif);
	check(1122);
	return 0;
}
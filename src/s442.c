#include "common.h"

int s442()
{

//	non-logical if's
//	computed goto

	uint64_t start_t, end_t, clock_dif;


	init( "s442 ");
	start_t = rdtsc();

		for (int i = 0; i < LEN; i++) {
			switch (indx[i]) {
				case 1:  goto L15;
				case 2:  goto L20;
				case 3:  goto L30;
				case 4:  goto L40;
			}
L15:
			a[i] += b[i] * b[i];
			goto L50;
L20:
			a[i] += c[i] * c[i];
			goto L50;
L30:
			a[i] += d[i] * d[i];
			goto L50;
L40:
			a[i] += e[i] * e[i];
L50:
			;
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S442\t %8ld   ", clock_dif);
	check(1);
	return 0;
}
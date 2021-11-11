#include "common.h"

int vdotr()
{

//	control loops
//	vector dot product reduction

	uint64_t start_t, end_t, clock_dif;


	init( "vdotr");
	start_t = rdtsc();

	float dot;

		dot = 0.;
		for (int i = 0; i < LEN; i++) {
			dot += a[i] * b[i];
		}
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("vdotr\t %8ld   ", clock_dif);
	temp = dot;
	check(-1);
	return 0;
}
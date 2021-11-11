#include "common.h"

int s3110()
{

//	reductions
//	if to max with index reductio 2 dimensions
//	similar to S315

	uint64_t start_t, end_t, clock_dif;


	init( "s3110");
	start_t = rdtsc();

	int xindex, yindex;
	float max, chksum;

		max = aa[(0)][0];
		xindex = 0;
		yindex = 0;
		for (int i = 0; i < LEN2; i++) {
			for (int j = 0; j < LEN2; j++) {
				if (aa[i][j] > max) {
					max = aa[i][j];
					xindex = i;
					yindex = j;
				}
			}
		}
		chksum = max + (float) xindex + (float) yindex;
		
	end_t = rdtsc(); clock_dif = end_t - start_t;
	printf("S3110\t %8ld   ", clock_dif);
	temp = max + xindex+1 + yindex+1;
	check(-1);
	return 0;
}
#include "common.h"

int s3110()
{

//	reductions
//	if to max with index reductio 2 dimensions
//	similar to S315

	clock_t start_t, end_t, clock_dif;


	init( "s3110");
	start_t = clock();

	int xindex, yindex;
	float max, chksum;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 100*(ntimes/(LEN2)); nl++) {
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
		dummy(a, b, c, d, e, aa, bb, cc, chksum);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	printf("S3110\t %8ld \t ", clock_dif);
	temp = max + xindex+1 + yindex+1;
	check(-1);
	return 0;
}
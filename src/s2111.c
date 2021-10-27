#include "common.h"

int s2111()
{

//	wavefronts, it will make jump in data access

	clock_t start_t, end_t, clock_dif; double clock_dif_sec;


	init( "s2111");
	start_t = clock();
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int nl = 0; nl < 100*(ntimes/(LEN2)); nl++) {
		for (int j = 1; j < LEN2; j++) {
			for (int i = 1; i < LEN2; i++) {
				aa[j][i] = aa[j][i-1] + aa[j-1][i];
			}
		}
		dummy(a, b, c, d, e, aa, bb, cc, 0.);
	}
	end_t = clock(); clock_dif = end_t - start_t;
	clock_dif_sec = (double) (clock_dif/1000000.0);
	printf("S2111\t %.2f \t\t", clock_dif_sec);;
	temp = 0.;
	#pragma clang loop unroll(disable)
	#pragma clang loop interleave(disable)
	#pragma clang loop vectorize_width(4, scalable)
	for (int i = 0; i < LEN2; i++)
		for (int j = 0; j < LEN2; j++)
			temp += aa[i][j];
	if (temp == 0) temp = 3.;	
	check(-1);
	return 0;
}
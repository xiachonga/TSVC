
/*
 * This is an executable test containing a number of loops to measure
 * the performance of a compiler. Arrays' length is LEN by default
 * and if you want a different array length, you should replace every 
 * LEN by your desired number which must be a multiple of 40. If you 
 * want to increase the number of loop calls to have a longer run time
 * you have to manipulate the constant value ntimes. There is a dummy
 * function called in each loop to make all computations appear required.
 * The time to execute this function is included in the time measurement 
 * for the output but it is neglectable.
 *
 *  The output includes three columns:
 *	Loop:		The name of the loop
 *	Time(Sec): 	The time in seconds to run the loop
 *	Checksum:	The checksum calculated when the test has run
 *
 * In this version of the codelets arrays are static type.
 *
 * All functions/loops are taken from "TEST SUITE FOR VECTORIZING COMPILERS"
 * by David Callahan, Jack Dongarra and David Levine except those whose 
 * functions' name have 4 digits.
 */

#include "common.h"
#include "string.h"

__attribute__ ((aligned(16))) TYPE X[lll],Y[lll],Z[lll],U[lll],V[lll];

//float* __restrict__ array;
float array[LEN2*LEN2] __attribute__((aligned(16)));

float x[LEN] __attribute__((aligned(16)));
float temp;
int temp_int;

__attribute__((aligned(16))) float a[LEN],b[LEN],c[LEN],d[LEN],e[LEN],
								   aa[LEN2][LEN2],bb[LEN2][LEN2],cc[LEN2][LEN2],tt[LEN2][LEN2];

int indx[LEN] __attribute__((aligned(16)));

float* __restrict__ xx;
float* yy;

__attribute__((aligned(16))) float set1d_m1[LEN], set1d_m2[LEN], set2d_m1[LEN2][LEN2], set2d_m2[LEN2][LEN2];

int set1d(float arr[LEN], float value, int stride)
{
	if (stride == -1) {
		memcpy(arr, set1d_m1, LEN * sizeof(float));
	} else if (stride == -2) {
		memcpy(arr, set1d_m2, LEN * sizeof(float));
	} else if (stride == 1) {
		for (int i = 0; i < LEN; i++) {
			arr[i] = value;
		}
	} else {
		for (int i = 0; i < LEN; i += stride) {
			arr[i] = value;
		}
	}
	return 0;
}

int set1ds(int _n, float* arr, float value, int stride)
{
	if (stride == -1) {
		memcpy(arr, set1d_m1, _n * sizeof(float));
	} else if (stride == -2) {
		memcpy(arr, set1d_m2, _n * sizeof(float));
	} else if (stride == 1)  {
		for (int i = 0; i < _n; i++) {
			arr[i] = value;
		}
	} else {
		for (int i = 0; i < _n; i += stride) {
			arr[i] = value;
		}
	}
	return 0;
}

int set2d(float arr[LEN2][LEN2], float value, int stride)
{
//  -- initialize two-dimensional arraysft
	if (stride == -1) {
		memcpy(arr, set2d_m1, LEN2 * LEN2 * sizeof(float));
	} else if (stride == -2) {
		memcpy(arr, set2d_m2, LEN2 * LEN2 * sizeof(float));
	} else {
		for (int i = 0; i < LEN2; i++) {
			for (int j = 0; j < LEN2; j += stride) {
				arr[i][j] = value;
			}
		}
	}
	return 0;
}

float sum1d(float arr[LEN])
{
	float ret = 0.;
	for (int i = 0; i < LEN; i++)
		ret += arr[i];
	return ret;
}

void check(int name){
	float suma = 0;
	float sumb = 0;
	float sumc = 0;
	float sumd = 0;
	float sume = 0;
	float sumaa = 0;
	float sumbb = 0;
	float sumcc = 0;
	float sumarray = 0;
	if (name == 1)
	{
		for (int i = 0; i < LEN; i++)
			suma += a[i];
		printf("%f \n",suma);
	}
	else if (name == 2)
	{
		for (int i = 0; i < LEN; i++)
			sumb += b[i];
		printf("%f \n",sumb);
	}
	else if (name == 3)
	{
		for (int i = 0; i < LEN; i++)
			sumc += c[i];
		printf("%f \n",sumc);
	}
	else if (name == 4)
	{
		for (int i = 0; i < LEN; i++)
			sumd += d[i];
		printf("%f \n",sumd);
	}
	else if (name == 5)
	{
		for (int i = 0; i < LEN; i++)
			sume += e[i];
		printf("%f \n",sume);
	}
	else if (name == 11)
	{
		for (int i = 0; i < LEN2; i++)
			for (int j = 0; j < LEN2; j++)
				sumaa += aa[i][j];
		printf("%f \n",sumaa);
	}
	else if (name == 22)
	{
		for (int i = 0; i < LEN2; i++)
			for (int j = 0; j < LEN2; j++)
				sumbb += bb[i][j];
		printf("%f \n",sumbb);
	}
	else if (name == 33)
	{
		for (int i = 0; i < LEN2; i++)
			for (int j = 0; j < LEN2; j++)
				sumcc += cc[i][j];
		printf("%f \n",sumcc);
	}
	else if (name == 0)
	{
		for (int i = 0; i < LEN2*LEN2; i++)
			sumarray += array[i];
		printf("%f \n",sumarray);
	}
	else if (name == 12)
	{
		for (int i = 0; i < LEN; i++)
			suma += (a[i] + b[i]);
		printf("%f \n",suma);
	}
	else if (name == 25)
	{
		for (int i = 0; i < LEN; i++)
			suma += (b[i] + e[i]);
		printf("%f \n",suma);
	}
	else if (name == 13)
	{
		for (int i = 0; i < LEN; i++)
			suma += (a[i] + c[i]);
		printf("%f \n",suma);
	}
	else if (name == 123)
	{
		for (int i = 0; i < LEN; i++)
			suma += (a[i] + b[i] + c[i]);
		printf("%f \n",suma);
	}
	else if (name == 1122)
	{
		for (int i = 0; i < LEN2; i++)
			for (int j = 0; j < LEN2; j++)
				sumaa += (aa[i][j] + bb[i][j]);
		printf("%f \n",sumaa);
	}
	else if (name == 112233)
	{
		for (int i = 0; i < LEN2; i++)
			for (int j = 0; j < LEN2; j++)
				sumaa += (aa[i][j] + bb[i][j] + cc[i][j]);
		printf("%f \n",sumaa);
	}
	else if (name == 111)
	{
		for (int i = 0; i < LEN; i++)
			suma += a[i];
		for (int i = 0; i < LEN2; i++)
			for (int j = 0; j < LEN2; j++)
				sumaa += aa[i][j];
		printf("%f \n",sumaa+suma);
	}
	else if (name == -1) printf("%f \n",temp);
	else if (name == -12)
	{
		for (int i = 0; i < LEN; i++)
			sumb += b[i];
		printf("%f \n",temp+sumb);
	}
	else
		printf("checksum not exist!\n");
}

int init(char* name)
{
	float any=0.;
	float zero=0.;
	float half=.5;
	float one=1.;
	float two=2.;
	float small = .000001;
	int unit =1;
	int frac=-1;
	int frac2=-2;

	if	(!strcmp(name, "s000 ")) {
	  for (int i = 0; i < lll; i++) {
			X[i] = 1+i;
			Y[i] = 2+i;
			Z[i] = 3+i;
			U[i] = 4+i;
			V[i] = 5+i;
		  }
	} else if (!strcmp(name, "s111 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac2);
		set1d(c, any,frac2);
		set1d(d, any,frac2);
		set1d(e, any,frac2);
	} else if (!strcmp(name, "s112 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "s113 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "s114 ")) {
		set2d(aa, any,frac);
		set2d(bb, any,frac2);
	} else if (!strcmp(name, "s115 ")) {
		set1d(a, one,unit);
		set2d(aa,small,unit);
		set2d(bb,small,unit);
		set2d(cc,small,unit);
	} else if (!strcmp(name, "s116 ")) {
		set1d(a, one,unit);
	} else if (!strcmp(name, "s118 ")) {
		set1d(a, one,unit);
		set2d(bb,small,unit);
	} else if (!strcmp(name, "s119 ")) {
		set2d(aa, one,unit);
		set2d(bb, any,frac2);
	} else if (!strcmp(name, "s121 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "s122 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "s123 ")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
		set1d(c, one,unit);
		set1d(d, any,frac);
		set1d(e, any,frac);
	} else if (!strcmp(name, "s124 ")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
		set1d(c, one,unit);
		set1d(d, any,frac);
		set1d(e, any,frac);
	} else if (!strcmp(name, "s125 ")) {
		set1ds(LEN2*LEN2, array,zero,unit);
		set2d(aa, one,unit);
		set2d(bb,half,unit);
		set2d(cc, two,unit);
	} else if (!strcmp(name, "s126 ")) {
		set2d(bb, one,unit);
		set1ds(LEN2*LEN2,array,any,frac);
		set2d(cc, any,frac);
	} else if (!strcmp(name, "s127 ")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
		set1d(c, any,frac);
		set1d(d, any,frac);
		set1d(e, any,frac);
	} else if (!strcmp(name, "s128 ")) {
		set1d(a,zero,unit);
		set1d(b, two,unit);
		set1d(c, one,unit);
		set1d(d, one,unit);
	} else if (!strcmp(name, "s131 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "s132 ")) {
		set2d(aa, one,unit);
		set1d(b, any,frac);
		set1d(c, any,frac);
	} else if (!strcmp(name, "s141 ")) {
		set1ds(LEN2*LEN2,array, one,unit);
		set2d(bb, any,frac2);
	} else if (!strcmp(name, "s151 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "s152 ")) {
		set1d(a, one,unit);
		set1d(b,zero,unit);
		set1d(c, any,frac);
		set1d(d, any,frac);
		set1d(e, any,frac);
	} else if (!strcmp(name, "s161 ")) {
		set1d(a, one,unit);
		set1ds(LEN/2,&b[0], one,2);
		set1ds(LEN/2,&b[1],-one,2);
		set1d(c, one,unit);
		set1d(d, any,frac);
		set1d(e, any,frac);
	} else if (!strcmp(name, "s162 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac);
		set1d(c, any,frac);
	} else if (!strcmp(name, "s171 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "s172 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "s173 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "s174 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "s175 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "s176 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac);
		set1d(c, any,frac);
	} else if (!strcmp(name, "s211 ")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
		set1d(c, any,frac);
		set1d(d, any,frac);
		set1d(e, any,frac);
	} else if (!strcmp(name, "s212 ")) {
		set1d(a, any,frac);
		set1d(b, one,unit);
		set1d(c, one,unit);
		set1d(d, any,frac);
	} else if (!strcmp(name, "s221 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac);
		set1d(c, any,frac);
		set1d(d, any,frac);
	} else if (!strcmp(name, "s222 ")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
		set1d(c, one,unit);
	} else if (!strcmp(name, "s231 ")) {
		set2d(aa, one,unit);
		set2d(bb, any,frac2);
	} else if (!strcmp(name, "s232 ")) {
		set2d(aa, one,unit);
		set2d(bb,zero,unit);
	} else if (!strcmp(name, "s233 ")) {
		set2d(aa, any,frac);
		set2d(bb, any,frac);
		set2d(cc, any,frac);
	} else if (!strcmp(name, "s234 ")) {
		set2d(aa, one,unit);
		set2d(bb, any,frac);
		set2d(cc, any,frac);
	} else if (!strcmp(name, "s235 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac);
		set1d(c, any,frac);
		set2d(aa, one,unit);
		set2d(bb, any, frac2);
	} else if (!strcmp(name, "s241 ")) {
		set1d(a, one,unit);
		set1d(b, one,unit);
		set1d(c, one,unit);
		set1d(d, one,unit);
	} else if (!strcmp(name, "s242 ")) {
		set1d(a,small,unit);
		set1d(b,small,unit);
		set1d(c,small,unit);
		set1d(d,small,unit);
	} else if (!strcmp(name, "s243 ")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
		set1d(c, any,frac);
		set1d(d, any,frac);
		set1d(e, any,frac);
	} else if (!strcmp(name, "s244 ")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
		set1d(c,small,unit);
		set1d(d,small,unit);
	} else if (!strcmp(name, "s251 ")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
		set1d(c, any,frac);
		set1d(d, any,frac);
		set1d(e, any,frac);
	} else if (!strcmp(name, "s252 ")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
		set1d(c, one,unit);
	} else if (!strcmp(name, "s253 ")) {
		set1d(a, one,unit);
		set1d(b,small,unit);
		set1d(c, one,unit);
		set1d(d, any,frac);
	} else if (!strcmp(name, "s254 ")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
	} else if (!strcmp(name, "s255 ")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
	} else if (!strcmp(name, "s256 ")) {
		set1d(a, one,unit);
		set2d(aa, two,unit);
		set2d(bb, one,unit);
	} else if (!strcmp(name, "s257 ")) {
		set1d(a, one,unit);
		set2d(aa, two,unit);
		set2d(bb, one,unit);
	} else if (!strcmp(name, "s258 ")) {
		set1d(a, any,frac);
		set1d(b,zero,unit);
		set1d(c, any,frac);
		set1d(d, any,frac);
		set1d(e,zero,unit);
		set2d(aa, any,frac);
	} else if (!strcmp(name, "s261 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac2);
		set1d(c, any,frac2);
		set1d(d, one,unit);
	} else if (!strcmp(name, "s271 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac);
		set1d(c, any,frac);
	} else if (!strcmp(name, "s272 ")) {
		set1d(a, one,unit);
		set1d(b, one,unit);
		set1d(c, any,frac);
		set1d(d, any,frac);
		set1d(e, two,unit);
	} else if (!strcmp(name, "s273 ")) {
		set1d(a, one,unit);
		set1d(b, one,unit);
		set1d(c, one,unit);
		set1d(d,small,unit);
		set1d(e, any,frac);
	} else if (!strcmp(name, "s274 ")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
		set1d(c, one,unit);
		set1d(d, any,frac);
		set1d(e, any,frac);
	} else if (!strcmp(name, "s275 ")) {
		set2d(aa, one,unit);
		set2d(bb,small,unit);
		set2d(cc,small,unit);
	} else if (!strcmp(name, "s276 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac);
		set1d(c, any,frac);
		set1d(d, any,frac);
	} else if (!strcmp(name, "s277 ")) {
		set1d(a, one,unit);
		set1ds(LEN/2,b, one,unit);
		set1ds(LEN/2,&b[LEN/2],-one,unit);
		set1d(c, any,frac);
		set1d(d, any,frac);
		set1d(e, any,frac);
	} else if (!strcmp(name, "s278 ")) {
		set1ds(LEN/2,a,-one,unit);
		set1ds(LEN/2,&a[LEN/2],one,unit);
		set1d(b, one,unit);
		set1d(c, any,frac);
		set1d(d, any,frac);
		set1d(e, any,frac);
	} else if (!strcmp(name, "s279 ")) {
		set1ds(LEN/2,a,-one,unit);
		set1ds(LEN/2,&a[LEN/2],one,unit);
//		set1d(a, -one,unit);
		set1d(b, one,unit);
		set1d(c, any,frac);
		set1d(d, any,frac);
		set1d(e, any,frac);
	} else if (!strcmp(name, "s2710")) {
		set1d(a, one,unit);
		set1d(b, one,unit);
		set1d(c, any,frac);
		set1d(d, any,frac);
		set1d(e, any,frac);
	} else if (!strcmp(name, "s2711")) {
		set1d(a, one,unit);
		set1d(b, any,frac);
		set1d(c, any,frac);
	} else if (!strcmp(name, "s2712")) {
		set1d(a, one,unit);
		set1d(b, any,frac);
		set1d(c, any,frac);
	} else if (!strcmp(name, "s281 ")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
		set1d(c, one,unit);
	} else if (!strcmp(name, "s291 ")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
	} else if (!strcmp(name, "s292 ")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
	} else if (!strcmp(name, "s293 ")) {
		set1d(a, any,frac);
	} else if (!strcmp(name, "s2101")) {
		set2d(aa, one,unit);
		set2d(bb, any,frac);
		set2d(cc, any,frac);
	} else if (!strcmp(name, "s2102")) {
		set2d(aa,zero,unit);
	} else if (!strcmp(name, "s2111")) {
//		set2d(aa, one,unit);
		set2d(aa,zero,unit);
	} else if (!strcmp(name, "s311 ")) {
		set1d(a, any,frac);
	} else if (!strcmp(name, "s312 ")) {
		set1d(a,1.000001,unit);
	} else if (!strcmp(name, "s313 ")) {
		set1d(a, any,frac);
		set1d(b, any,frac);
	} else if (!strcmp(name, "s314 ")) {
		set1d(a, any,frac);
	} else if (!strcmp(name, "s315 ")) {
		set1d(a, any,frac);
	} else if (!strcmp(name, "s316 ")) {
		set1d(a, any,frac);
	} else if (!strcmp(name, "s317 ")) {
	} else if (!strcmp(name, "s318 ")) {
		set1d(a, any,frac);
		a[LEN-1] = -two;
	} else if (!strcmp(name, "s319 ")) {
		set1d(a,zero,unit);
		set1d(b,zero,unit);
		set1d(c, any,frac);
		set1d(d, any,frac);
		set1d(e, any,frac);
	} else if (!strcmp(name, "s3110")) {
		set2d(aa, any,frac);
		aa[LEN2-1][LEN2-1] = two;
	} else if (!strcmp(name, "s3111")) {
		set1d(a, any,frac);
	} else if (!strcmp(name, "s3112")) {
		set1d(a, any,frac2);
		set1d(b,zero,unit);
	} else if (!strcmp(name, "s3113")) {
		set1d(a, any,frac);
		a[LEN-1] = -two;
	} else if (!strcmp(name, "s321 ")) {
		set1d(a, one,unit);
		set1d(b,zero,unit);
	} else if (!strcmp(name, "s322 ")) {
		set1d(a, one,unit);
		set1d(b,zero,unit);
		set1d(c,zero,unit);
	} else if (!strcmp(name, "s323 ")) {
		set1d(a, one,unit);
		set1d(b, one,unit);
		set1d(c, any,frac);
		set1d(d, any,frac);
		set1d(e, any,frac);
	} else if (!strcmp(name, "s331 ")) {
		set1d(a, any,frac);
		a[LEN-1] = -one;
	} else if (!strcmp(name, "s332 ")) {
		set1d(a, any,frac2);
		a[LEN-1] = two;
	} else if (!strcmp(name, "s341 ")) {
		set1d(a,zero,unit);
		set1d(b, any,frac);
	} else if (!strcmp(name, "s342 ")) {
		set1d(a, any,frac);
		set1d(b, any,frac);
	} else if (!strcmp(name, "s343 ")) {
		set2d(aa, any,frac);
		set2d(bb, one,unit);
	} else if (!strcmp(name, "s351 ")) {
		set1d(a, one,unit);
		set1d(b, one,unit);
		c[0] = 1.;
	} else if (!strcmp(name, "s352 ")) {
		set1d(a, any,frac);
		set1d(b, any,frac);
	} else if (!strcmp(name, "s353 ")) {
		set1d(a, one,unit);
		set1d(b, one,unit);
		c[0] = 1.;
	} else if (!strcmp(name, "s411 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac);
		set1d(c, any,frac);
	} else if (!strcmp(name, "s412 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac);
		set1d(c, any,frac);
	} else if (!strcmp(name, "s413 ")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
		set1d(c, one,unit);
		set1d(d, any,frac);
		set1d(e, any,frac);
	} else if (!strcmp(name, "s414 ")) {
		set2d(aa, one,unit);
		set2d(bb, any,frac);
		set2d(cc, any,frac);
	} else if (!strcmp(name, "s415 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac);
		set1d(c, any,frac);
		a[LEN-1] = -one;
	} else if (!strcmp(name, "s421 ")) {
		set1d(a, any,frac2);
	} else if (!strcmp(name, "s422 ")) {
		set1d(array,one,unit);
		set1d(a, any,frac2);
	} else if (!strcmp(name, "s423 ")) {
		set1d(array,zero,unit);
		set1d(a, any,frac2);
	} else if (!strcmp(name, "s424 ")) {
		set1d(array,one,unit);
		set1d(a, any,frac2);
	} else if (!strcmp(name, "s431 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "s432 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "s441 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac);
		set1d(c, any,frac);
		set1ds(LEN/3,	&d[0],		-one,unit);
		set1ds(LEN/3,	&d[LEN/3],	zero,unit);
		set1ds(LEN/3+1, &d[(2*LEN/3)], one,unit);
	} else if (!strcmp(name, "s442 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac);
		set1d(c, any,frac);
		set1d(d, any,frac);
		set1d(e, any,frac);
	} else if (!strcmp(name, "s443 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac);
		set1d(c, any,frac);
	} else if (!strcmp(name, "s451 ")) {
		set1d(b, any,frac);
		set1d(c, any,frac);
	} else if (!strcmp(name, "s452 ")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
		set1d(c,small,unit);
	} else if (!strcmp(name, "s453 ")) {
		set1d(a,zero,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "s471 ")) {
		set1d(a, one,unit);
		set1d(b, one,unit);
		set1d(c, one,unit);
		set1d(d, any,frac);
		set1d(e, any,frac);
	} else if (!strcmp(name, "s481 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac);
		set1d(c, any,frac);
		set1d(d, any,frac);
	} else if (!strcmp(name, "s482 ")) {
		set1d(a, one,unit);
		set1d(b, any,frac);
		set1d(c, any,frac);
	} else if (!strcmp(name, "s491 ")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
		set1d(c, any,frac);
		set1d(d, any,frac);
	} else if (!strcmp(name, "s4112")) {
		set1d(a, one,unit);
		set1d(b, any,frac);
	} else if (!strcmp(name, "s4113")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
		set1d(c, any,frac2);
	} else if (!strcmp(name, "s4114")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
		set1d(c, any,frac);
		set1d(d, any,frac);
	} else if (!strcmp(name, "s4115")) {
		set1d(a, any,frac);
		set1d(b, any,frac);
	} else if (!strcmp(name, "s4116")) {
		set1d(a, any,frac);
		set2d(aa, any,frac);
	} else if (!strcmp(name, "s4117")) {
		set1d(a,zero,unit);
		set1d(b, one,unit);
		set1d(c, any,frac);
		set1d(d, any,frac);
	} else if (!strcmp(name, "s4121")) {
		set1d(a, one,unit);
		set1d(b, any,frac);
		set1d(c, any,frac);
	} else if (!strcmp(name, "va	")) {
		set1d(a,zero,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "vag  ")) {
		set1d(a,zero,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "vas  ")) {
		set1d(a,zero,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "vif  ")) {
		set1d(a,zero,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "vpv  ")) {
		set1d(a,zero,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "vtv  ")) {
		set1d(a, one,unit);
		set1d(b, one,unit);
	} else if (!strcmp(name, "vpvtv")) {
		set1d(a, one,unit);
		set1d(b, any,frac);
		set1d(c, any,frac);
	} else if (!strcmp(name, "vpvts")) {
		set1d(a, one,unit);
		set1d(b, any,frac2);
	} else if (!strcmp(name, "vpvpv")) {
		set1d(a, any,frac2);
		set1d(b, one,unit);
		set1d(c,-one,unit);
	} else if (!strcmp(name, "vtvtv")) {
		set1d(a, one,unit);
		set1d(b, two,unit);
		set1d(c,half,unit);
	} else if (!strcmp(name, "vsumr")) {
		set1d(a, any,frac);
	} else if (!strcmp(name, "vdotr")) {
		set1d(a, any,frac);
		set1d(b, any,frac);
	} else if (!strcmp(name, "vbor ")) {
		set1d(a, any,frac);
		set1d(b, any,frac);
		set1d(c, one,frac);
		set1d(d, two,frac);
		set1d(e,half,frac);
		set2d(aa, any,frac);
	} else {
	}

	return 0;
}

void set(int* ip, float* s1, float* s2){
	xx = (float*) memalign(16, LEN*sizeof(float));
	for (int i = 0; i < LEN; i = i+5){
		ip[i]	= (i+4);
		ip[i+1] = (i+2);
		ip[i+2] = (i);
		ip[i+3] = (i+3);
		ip[i+4] = (i+1);

	}

	set1d(a, 1.,1);
	set1d(b, 1.,1);
	set1d(c, 1.,1);
	set1d(d, 1.,1);
	set1d(e, 1.,1);
	set2d(aa, 0.,-1);
	set2d(bb, 0.,-1);
	set2d(cc, 0.,-1);

	for (int i = 0; i < LEN; i++){
		indx[i] = (i+1) % 4+1;
	}
	*s1 = 1.0;
	*s2 = 2.0;

}

int main(){
	for (int i = 0; i < LEN; i++) {
		set1d_m1[i] = 1. / (float) (i+1);
		set1d_m2[i] = 1. / (float) ((i+1) * (i+1));
	}
	for (int i = 0; i < LEN2; i++) {
		for (int j = 0; j < LEN2; j++) {
			set2d_m1[i][j] = 1. / (float) (i+1);
			set2d_m2[i][j] = 1. / (float) ((i+1) * (i+1));
		}
	}

	int n1 = 1;
	int n3 = 1;
	int* ip = (int *) memalign(16, LEN*sizeof(float));
	float s1,s2;
	set(ip, &s1, &s2);
	printf("Loop \t Time(ns)   Time(ns)   Checksum\n");
	fflush(stdout);
	s000();		fflush(stdout);
	s111();		fflush(stdout);
	s1111();	fflush(stdout);
	s112();		fflush(stdout);
	s1112();	fflush(stdout);
	s113();		fflush(stdout);
	s1113();	fflush(stdout);
	s114();		fflush(stdout);
	s115();		fflush(stdout);
	s1115();	fflush(stdout);
	s116();		fflush(stdout);
	s118();		fflush(stdout);
	s119();		fflush(stdout);
	s1119();	fflush(stdout);
	s121();		fflush(stdout);
	s122(n1,n3);	fflush(stdout);
	s123();		fflush(stdout);
	s124();		fflush(stdout);
	s125();		fflush(stdout);
	s126();		fflush(stdout);
	s127();		fflush(stdout);
	s128();		fflush(stdout);
	s131();		fflush(stdout);
	s132();		fflush(stdout);
	s141();		fflush(stdout);
	s151();		fflush(stdout);
	s152();		fflush(stdout);
	s161();		fflush(stdout);
	s1161();	fflush(stdout);
	s162(n1);	fflush(stdout);
	s171(n1);	fflush(stdout);
	s172(n1,n3);	fflush(stdout);
	s173();		fflush(stdout);
	s174(LEN/2);	fflush(stdout);
	s175(n1);	fflush(stdout);
	s176();		fflush(stdout);
	s211();		fflush(stdout);
	s212();		fflush(stdout);
	s1213();	fflush(stdout);
	s221();		fflush(stdout);
	s1221();	fflush(stdout);
	s222();		fflush(stdout);
	s231();		fflush(stdout);
	s232();		fflush(stdout);
	s1232();	fflush(stdout);
	s233();		fflush(stdout);
	s2233();	fflush(stdout);
	s235();		fflush(stdout);
	s241();		fflush(stdout);
	s242(s1, s2);	fflush(stdout);
	s243();		fflush(stdout);
	s244();		fflush(stdout);
	s1244();	fflush(stdout);
	s2244();	fflush(stdout);
	s251();		fflush(stdout);
	s1251();	fflush(stdout);
	s2251();	fflush(stdout);
	s3251();	fflush(stdout);
	s252();		fflush(stdout);
	s253();		fflush(stdout);
	s254();		fflush(stdout);
	s255();		fflush(stdout);
	s256();		fflush(stdout);
	s257();		fflush(stdout);
	s258();		fflush(stdout);
	s261();		fflush(stdout);
	s271();		fflush(stdout);
	s272(s1);	fflush(stdout);
	s273();		fflush(stdout);
	s274();		fflush(stdout);
	s275();		fflush(stdout);
	s2275();	fflush(stdout);
	s276();		fflush(stdout);
	s277();		fflush(stdout);
	s278();		fflush(stdout);
	s279();		fflush(stdout);
	s1279();	fflush(stdout);
	s2710(s1);	fflush(stdout);
	s2711();	fflush(stdout);
	s2712();	fflush(stdout);
	s281();		fflush(stdout);
	s1281();	fflush(stdout);
	s291();		fflush(stdout);
	s292();		fflush(stdout);
	s293();		fflush(stdout);
	s2101();	fflush(stdout);
	s2102();	fflush(stdout);
	s2111();	fflush(stdout);
	s311();		fflush(stdout);
	s31111();	fflush(stdout);
	s312();		fflush(stdout);
	s313();		fflush(stdout);
	s314();		fflush(stdout);
	s315();		fflush(stdout);
	s316();		fflush(stdout);
	s317();		fflush(stdout);
	s318(n1);	fflush(stdout);
	s319();		fflush(stdout);
	s3110();	fflush(stdout);
	s13110();	fflush(stdout);
	s3111();	fflush(stdout);
	s3112();	fflush(stdout);
	s3113();	fflush(stdout);
	s321();		fflush(stdout);
	s322();		fflush(stdout);
	s323();		fflush(stdout);
	s331();		fflush(stdout);
	s332(s1);	fflush(stdout);
	s341();		fflush(stdout);
	s342();		fflush(stdout);
	s343();		fflush(stdout);
	s351();		fflush(stdout);
	s1351();	fflush(stdout);
	s352();		fflush(stdout);
	s353(ip);	fflush(stdout);
	s421();		fflush(stdout);
	s1421();	fflush(stdout);
	s422();		fflush(stdout);
	s423();		fflush(stdout);
	s424();		fflush(stdout);
	s431();		fflush(stdout);
	s441();		fflush(stdout);
	s442();		fflush(stdout);
	s443();		fflush(stdout);
	s451();		fflush(stdout);
	s452();		fflush(stdout);
	s453();		fflush(stdout);
	s471();		fflush(stdout);
	s481();		fflush(stdout);
	s482();		fflush(stdout);
	s491(ip);	fflush(stdout);
	s4112(ip, s1);	fflush(stdout);
	s4113(ip);	fflush(stdout);
	s4114(ip,n1);	fflush(stdout);
	s4115(ip);	fflush(stdout);
	s4116(ip, LEN2/2, n1);	fflush(stdout);
	s4117();	fflush(stdout);
	s4121();	fflush(stdout);
	va();		fflush(stdout);
	vag(ip);	fflush(stdout);
	vas(ip);	fflush(stdout);
	vif();		fflush(stdout);
	vpv();		fflush(stdout);
	vtv();		fflush(stdout);
	vpvtv();	fflush(stdout);
	vpvts(s1);	fflush(stdout);
	vpvpv();	fflush(stdout);
	vtvtv();	fflush(stdout);
	vsumr();	fflush(stdout);
	vdotr();	fflush(stdout);
	vbor();		fflush(stdout);
	return 0;
}


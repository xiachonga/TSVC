#if HAVE_ICC
#pragma auto_inline(off)
#endif

#define LEN 32000
#define LEN2 256

#define ntimes 4096

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <sys/param.h>
#include <sys/times.h>
#include <sys/types.h>
#include <time.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>
// #include <xmmintrin.h>

//#include <builtins.h>


#define TYPE float

#define lll LEN


extern __attribute__ ((aligned(16))) TYPE X[lll],Y[lll],Z[lll],U[lll],V[lll];


//float* __restrict__ array;
extern float array[LEN2*LEN2] __attribute__((aligned(16)));

extern float x[LEN] __attribute__((aligned(16)));
extern float temp;
extern int temp_int;


extern __attribute__((aligned(16))) float a[LEN],b[LEN],c[LEN],d[LEN],e[LEN],
                                   aa[LEN2][LEN2],bb[LEN2][LEN2],cc[LEN2][LEN2],tt[LEN2][LEN2];


extern int indx[LEN] __attribute__((aligned(16)));


extern float* __restrict__ xx;
extern float* yy;

int dummy(float[LEN], float[LEN], float[LEN], float[LEN], float[LEN], float[LEN2][LEN2], float[LEN2][LEN2], float[LEN2][LEN2], float);

int dummy_media(short[], char[], int);



int set1d(float arr[LEN], float value, int stride);

int set1ds(int _n, float arr[LEN], float value, int stride);

int set2d(float arr[LEN2][LEN2], float value, int stride);

float sum1d(float arr[LEN]);

void check(int name);

int init(char* name);

int s000();

// %1.1
int s111();

int s1111();

// %1.1

int s112();

int s1112();

// %1.1

int s113();

int s1113();

// %1.1

int s114();

// %1.1

int s115();

int s1115();

// %1.1

int s116();

// %1.1

int s118();

// %1.1

int s119();

int s1119();

// %1.2

int s121();

// %1.2

int s122(int n1, int n3);

// %1.2

int s123();

// %1.2

int s124();
// %1.2
int s125();

// %1.2
int s126();

// %1.2

int s127();

// %1.2

int s128();

// %1.3

int s131();

// %1.3

int s132();

// %1.4

int s141();

// %1.5

int s151s(float a[LEN], float b[LEN],  int m);

int s151();

// %1.5

int s152s(float a[LEN], float b[LEN], float c[LEN], int i);

int s152();

// %1.6

int s161();

int s1161();

// %1.6

int s162(int k);

// %1.7

int s171(int inc);

// %1.7

int s172( int n1, int n3);

// %1.7

int s173();
// %1.7

int s174(int M);

// %1.7

int s175(int inc);

// %1.7

int s176();

// **********************************************************
// *							    *
// *			VECTORIZATION			    *
// *							    *
// **********************************************************

// %2.1

int s211();

// %2.1

int s212();

int s1213();

// %2.2

int s221();

int s1221();

// %2.2

int s222();

// %2.3

int s231();

// %2.3

int s232();

int s1232();

// %2.3

int s233();

int s2233();

// %2.3
int s235();

// %2.4

int s241();

// %2.4

int s242(float s1, float s2);

// %2.4

int s243();

// %2.4

int s244();

int s1244();

int s2244();

// %2.5

int s251();

int s1251();

int s2251();

int s3251();

// %2.5

int s252();

// %2.5


int s253();

// %2.5

int s254();

// %2.5

int s255();

// %2.5

int s256();

// %2.5

int s257();

int s258();

// %2.7

int s261();

int s271();

// %2.7

int s272(float t);

// %2.7

int s273();

// %2.7

int s274();

// %2.7

int s275();

int s2275();

// %2.7

int s276();

// %2.7
int s277();

// %2.7

int s278();

// %2.7

int s279();

int s1279();

// %2.7

int s2710( float x);

// %2.7

int s2711();

// %2.7

int s2712();

// %2.8

int s281();

int s1281();

// %2.9

int s291();

// %2.9

int s292();

// %2.9

int s293();

// %2.10

int s2101();

// %2.12

int s2102();

// %2.11

int s2111();


// **********************************************************
//							    *
//			IDIOM RECOGNITION		    *
//							    *
// **********************************************************

// %3.1

int s311();

int s31111();

// %3.1

int s312();

// %3.1
int s313();

// %3.1

int s314();

// %3.1

int s315();

// %3.1

int s316();
// %3.1

int s317();

// %3.1

int s318( int inc);

// %3.1

int s319();

// %3.1

int s3110();

int s13110();

// %3.1

int s3111();

// %3.1

int s3112();

// %3.1

int s3113();

// %3.2

int s321();

// %3.2

int s322();

// %3.2

int s323();

// %3.3

int s331();

// %3.3
int s332( float t);

// %3.4

int s341();

// %3.4

int s342();

// %3.4

int s343();

// %3.5

int s351();

int s1351();

// %3.5

int s352();
// %3.5

int s353(int* __restrict__ ip);

// **********************************************************
//							    *
//			 LANGUAGE COMPLETENESS		    *
//							    *
// **********************************************************

// %4.1
// %4.2

int s421();

int s1421();

// %4.2

int s422();

// %4.2

int s423();

// %4.2

int s424();

// %4.3

int s431();

// %4.4

int s441();

// %4.4

int s442();

// %4.4

int s443();

// %4.5

int s451();

// %4.5

int s452();

// %4.5

int s453();

// %4.7

int s471();

// %4.8

int s481();

// %4.8

// %4.8
int s482();


// static int min(int a, int b){
//   return (a < b) ? a : b;
// }

// %4.9

int s491(int* __restrict__ ip);

// %4.11

int s4112(int* __restrict__ ip, float s);

// %4.11

int s4113(int* __restrict__ ip);

// %4.11

int s4114(int* ip, int n1);

// %4.11

int s4115(int* __restrict__ ip);

// %4.11

int s4116(int* __restrict__ ip, int j, int inc);

// %4.11

int s4117();

// %4.12

int s4121();

// %5.1

int va();

// %5.1

int vag( int* __restrict__ ip);

// %5.1

int vas( int* __restrict__ ip);

// %5.1

int vif();

// %5.1

int vpv();

// %5.1

int vtv();

// %5.1

int vpvtv();

// %5.1

int vpvts( float s);

// %5.1

int vpvpv();

// %5.1

int vtvtv();

// %5.1

int vsumr();

// %5.1

int vdotr();

// %5.1

int vbor();

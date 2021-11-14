#define LEN 32000
#define LEN2 256

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

#include <gem5/m5ops.h>

#define TYPE float

#define lll LEN


extern __attribute__ ((aligned(16))) TYPE X[lll],Y[lll],Z[lll],U[lll],V[lll];

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

// Loops:
int s000();
int s111();
int s1111();
int s112();
int s1112();
int s113();
int s1113();
int s114();
int s115();
int s1115();
int s116();
int s118();
int s119();
int s1119();
int s121();
int s122(int n1, int n3);
int s123();
int s124();
int s125();
int s126();
int s127();
int s128();
int s131();
int s132();
int s141();
int s151();
int s152();
int s161();
int s1161();
int s162(int k);
int s171(int inc);
int s172( int n1, int n3);
int s173();
int s174(int M);
int s175(int inc);
int s176();
int s211();
int s212();
int s1213();
int s221();
int s1221();
int s222();
int s231();
int s232();
int s1232();
int s233();
int s2233();
int s235();
int s241();
int s242(float s1, float s2);
int s243();
int s244();
int s1244();
int s2244();
int s251();
int s1251();
int s2251();
int s3251();
int s252();
int s253();
int s254();
int s255();
int s256();
int s257();
int s258();
int s261();
int s271();
int s272(float t);
int s273();
int s274();
int s275();
int s2275();
int s276();
int s277();
int s278();
int s279();
int s1279();
int s2710( float x);
int s2711();
int s2712();
int s281();
int s1281();
int s291();
int s292();
int s293();
int s2101();
int s2102();
int s2111();
int s311();
int s31111();
int s312();
int s313();
int s314();
int s315();
int s316();
int s317();
int s318( int inc);
int s319();
int s3110();
int s13110();
int s3111();
int s3112();
int s3113();
int s321();
int s322();
int s323();
int s331();
int s332( float t);
int s341();
int s342();
int s343();
int s351();
int s1351();
int s352();
int s353(int* __restrict__ ip);
int s421();
int s1421();
int s422();
int s423();
int s424();
int s431();
int s441();
int s442();
int s443();
int s451();
int s452();
int s453();
int s471();
int s481();
int s482();
int s491(int* __restrict__ ip);
int s4112(int* __restrict__ ip, float s);
int s4113(int* __restrict__ ip);
int s4114(int* ip, int n1);
int s4115(int* __restrict__ ip);
int s4116(int* __restrict__ ip, int j, int inc);
int s4117();
int s4121();
int va();
int vag( int* __restrict__ ip);
int vas( int* __restrict__ ip);
int vif();
int vpv();
int vtv();
int vpvtv();
int vpvts( float s);
int vpvpv();
int vtvtv();
int vsumr();
int vdotr();
int vbor();

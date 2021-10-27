
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


void set(int* ip, float* s1, float* s2){
	xx = (float*) memalign(16, LEN*sizeof(float));
	printf("\n");
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
	int n1 = 1;
	int n3 = 1;
	int* ip = (int *) memalign(16, LEN*sizeof(float));
	float s1,s2;
	set(ip, &s1, &s2);
	printf("Loop \t Time(Sec) \t Checksum \n");

	s000();
	s111();
	s1111();
	s112();
	s1112();
	s113();
	s1113();
	s114();
	s115();
	s1115();
	s116();
	s118();
	s119();
	s1119();
	s121();
	s122(n1,n3);
	s123();
  s124();
	s125();
	s126();
	s127();
	s128();
	s131();
	s132();
	s141();
	s151();
	s152();
	s161();
	s1161();
	s162(n1);
	s171(n1);
	s172(n1,n3);
	s173();
	s174(LEN/2);
	s175(n1);
	s176();
	s211();
	s212();
	s1213();
	s221();
	s1221();
	s222();
	s231();
	s232();
	s1232();
	s233();
	s2233();
	s235();
	s241();
	s242(s1, s2);
	s243();
	s244();
	s1244();
	s2244();
	s251();
	s1251();
	s2251();
	s3251();
	s252();
	s253();
	s254();
	s255();
	s256();
	s257();
	s258();
	s261();
	s271();
	s272(s1);
	s273();
	s274();
	s275();
	s2275();
	s276();
	s277();
	s278();
	s279();
	s1279();
	s2710(s1);
	s2711();
	s2712();
	s281();
	s1281();
	s291();
	s292();
	s293();
	s2101();
	s2102();
	s2111();
	s311();
	s31111();
	s312();
	s313();
	s314();
	s315();
	s316();
	s317();
	s318(n1);
	s319();
	s3110();
	s13110();
	s3111();
	s3112();
	s3113();
	s321();
	s322();
	s323();
	s331();
	s332(s1);
	s341();
	s342();
	s343();
	s351();
	s1351();
	s352();
	s353(ip);
	s421();
	s1421();
	s422();
	s423();
	s424();
	s431();
	s441();
	s442();
	s443();
	s451();
	s452();
	s453();
	s471();
	s481();
	s482();
	s491(ip);
	s4112(ip, s1);
	s4113(ip);
	s4114(ip,n1);
	s4115(ip);
	s4116(ip, LEN2/2, n1);
	s4117();
	s4121();
	va();
	vag(ip);
	vas(ip);
	vif();
	vpv();
	vtv();
	vpvtv();
	vpvts(s1);
	vpvpv();
	vtvtv();
	vsumr();
	vdotr();
	vbor();
	return 0;
}


#ifndef WIN32
typedef unsigned int dimen;
#else
typedef unsigned long dimen;
#define strdup _strdup
#endif
typedef double* vector;
typedef double real;
#ifdef __cplusplus
extern "C" 
{
#endif

	char* expire_date(char*asetup);
	char* version(char*asetup);
	char* cversion(char*asetup);
	void dmx_transpose(dimen n,dimen m,vector A,vector B);
	double dsumvec(dimen n,vector a);
	void dcopyvec(dimen n,vector a,vector b);
	void dscalvec(dimen n,double a,vector b);
	double ddotvec(dimen n,vector a,vector b);
	void dmxtmulv(dimen n,dimen m,vector A,vector b,vector Ab);
	void dmxmulv(dimen n,dimen m,vector A,vector b,vector bA);
	short eigendecomp(dimen n, vector S, vector d, dimen itmax);
	void SDPsvec(size_t n,vector S,vector v);
	void SDPsMat(size_t n,vector v,vector S);
	short Conic_General(size_t ncone,int*cone,int*typecone,size_t m,vector x,vector s,vector y,vector A,vector b,
										 vector c,vector tau,vector kappa,double comptoll=1e-8,double gaptoll=1e-8,double stepmax=2e-2,int straight=0,
										 int fastbreak=1,int log=0,char*outfile=0);
	short Conic_VeryGeneral(size_t ncone,int*cone,int*typecone,size_t m,vector x,vector s,vector y,vector A,vector b,
										 vector c,vector tau,vector kappa,double comptoll=1e-8,double gaptoll=1e-8,double stepmax=2e-2,int straight=0,
										 int fastbreak=1,int log=0,char*outfile=0,int method=0,int homog=1,long nf=0,vector SV=0,vector FL=0,vector FC=0,size_t fcone=0);

#ifdef __cplusplus
}
#endif

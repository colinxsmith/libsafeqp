//Copyright 2005 COR Financial Solutions

#ifndef WIN32
typedef unsigned long dimen;
#else
typedef unsigned int dimen;
#endif
typedef double* vector;
typedef double real;
#ifdef __cplusplus
extern "C" 
{
#endif
void factor_model_process(dimen n,dimen nfac,vector FLOAD,vector FFC,vector SSV,vector QMATRIX);

short Optimise_internalCVP(dimen n,long nfac,char** names,vector w_opt,dimen m,
        vector AAA,vector L,vector U,vector alpha,
        vector benchmark,vector QMATRIX,double gamma,vector initial,
        double delta,vector buy,vector sell,double kappa,long basket,
        long trades,int revise,int costs,double min_holding,double min_trade,
        int m_LS,int Fully_Invested,double Rmin,double Rmax,
        int m_Round,vector min_lot,vector size_lot,int* shake,dimen ncomp,vector Composite,
        double LSValue,dimen npiece,vector hpiece,vector pgrad);


short  Optimise_internalCVPA(dimen n,long nfac,char** stocknames,vector w_opt,dimen m,
         vector AAA,vector L,vector U,vector alpha,
         vector benchmark,vector QMATRIX,real gamma,vector Initial,
         real delta,vector buy,vector sell,real kappa,long basket,
         long trades,int revise,int costs,real min_holding,
         real min_trade,
         int m_LS,int Fully_Invested,real Rmin,real Rmax,
         int m_Round,vector min_lot,vector size_lot,int* shake,
         dimen ncomp,vector Composite,real LSValue,
         dimen npiece,vector hpiece,vector pgrad,
         dimen nabs,vector Abs_A,dimen mabs,dimen* I_A,vector Abs_U,
         vector mask,int log,char* logfile);
short  Optimise_internalCVPAF(dimen n,long nfac,char** stocknames,vector w_opt,dimen m,
         vector AAA,vector L,vector U,vector alpha,
         vector benchmark,vector QMATRIX,real gamma,vector Initial,
         real delta,vector buy,vector sell,real kappa,long basket,
         long trades,int revise,int costs,real min_holding,
         real min_trade,
         int m_LS,int Fully_Invested,real Rmin,real Rmax,
         int m_Round,vector min_lot,vector size_lot,int* shake,
         dimen ncomp,vector Composite,real LSValue,
         dimen npiece,vector hpiece,vector pgrad,
         dimen nabs,vector Abs_A,dimen mabs,dimen* I_A,vector Abs_U,
         vector FFC,vector FLOAD,vector SSV,
         double minRisk,double maxRisk,double* ogamma,
         vector mask,int log,char* logfile,
         int downrisk,double downfactor);
short  Optimise_internalCVPAFb(dimen n,long nfac,char** stocknames,vector w_opt,dimen m,
         vector AAA,vector L,vector U,vector alpha,
         vector benchmark,vector QMATRIX,real gamma,vector Initial,
         real delta,vector buy,vector sell,real kappa,long basket,
         long trades,int revise,int costs,real min_holding,
         real min_trade,
         int m_LS,int Fully_Invested,real Rmin,real Rmax,
         int m_Round,vector min_lot,vector size_lot,int* shake,
         dimen ncomp,vector Composite,real LSValue,
         dimen npiece,vector hpiece,vector pgrad,
         dimen nabs,vector Abs_A,dimen mabs,dimen* I_A,vector Abs_U,
         vector FFC,vector FLOAD,vector SSV,
         double minRisk,double maxRisk,double* ogamma,
         vector mask,int log,char* logfile,
         int downrisk,double downfactor,
         long longbasket1,long shortbasket,
         long tradebuy,long tradesell,
         double zetaS,double zetaF,double ShortCostScale);
short  Optimise_internalCVPAFbl(dimen n,long nfac,char** names,vector w,dimen m,
									vector A,vector L,vector U,vector alpha,
									vector benchmark,vector Q,real gamma,vector initial,
									real delta,vector buy,vector sell,real kappa,long basket,
									long trades,int revise,int costs,real min_holding,
									real min_trade,
									int m_LS,int Fully_Invested,real Rmin,real Rmax,
									int m_Round,vector min_lot,vector size_lot,int* shake,
									dimen ncomp,vector Composite,real LSValue,
									dimen npiece,vector hpiece,vector pgrad,
									dimen nabs,vector Abs_A,dimen mabs,dimen* I_A,vector Abs_U,
									vector FC,vector FL,vector SV,double minRisk=-1,
									double maxRisk=-1,double* ogamma=0,vector mask=0,
									int log=0,char* logfile=0,
									int downrisk=0,double downfactor=3.0,
									long longbasket=-1,long shortbasket=-1,
									long tradebuy=-1,long tradesell=-1,
									double zetaS=1,double zetaF=1,double ShortCostScale=1,
									double LSValuel=0,vector Abs_L=0);
short FrontierCVPA(dimen npoints,vector frontrisk,
         vector frontarisk,vector frontrreturn,vector frontareturn,
         dimen n,long nfac,char** names,vector frontw,dimen m,
         vector AAA,vector L,vector U,vector alpha,
         vector benchmark,vector QMATRIXF,vector Initial,
         real delta,vector buy,vector sell,real kappa,long basket,
         long trades,dimen revise,int costs,real min_holding,real min_trade,
         int m_LS,int Fully_Invested,real Rmin,real Rmax,
         int m_Round,vector min_lot,vector size_lot,int* frontshake,
         dimen ncomp,vector Comp,real LSValue,
         dimen npiece,vector hpiece,vector pgrad,
         dimen nabs,vector Abs_A,dimen mabs,dimen* I_A,vector Abs_U,
         vector mask);
short FrontierCVPAF(dimen npoints,vector frontrisk,
         vector frontarisk,vector frontrreturn,vector frontareturn,
         dimen n,long nfac,char** names,vector frontw,dimen m,
         vector AAA,vector L,vector U,vector alpha,
         vector benchmark,vector QMATRIXF,vector Initial,
         real delta,vector buy,vector sell,real kappa,long basket,
         long trades,dimen revise,int costs,real min_holding,real min_trade,
         int m_LS,int Fully_Invested,real Rmin,real Rmax,
         int m_Round,vector min_lot,vector size_lot,int* frontshake,
         dimen ncomp,vector Comp,real LSValue,
         dimen npiece,vector hpiece,vector pgrad,
         dimen nabs,vector Abs_A,dimen mabs,dimen* I_A,vector Abs_U,
         vector FFC,vector FLOAD,vector SSV,vector mask,
         int DoByRisks);
short FrontierCVPAFb(dimen npoints,vector frontrisk,
         vector frontarisk,vector frontrreturn,vector frontareturn,
         dimen n,long nfac,char** names,vector frontw,dimen m,
         vector AAA,vector L,vector U,vector alpha,
         vector benchmark,vector QMATRIXF,vector Initial,
         real delta,vector buy,vector sell,real kappa,long basket,
         long trades,dimen revise,int costs,real min_holding,real min_trade,
         int m_LS,int Fully_Invested,real Rmin,real Rmax,
         int m_Round,vector min_lot,vector size_lot,int* frontshake,
         dimen ncomp,vector Comp,real LSValue,
         dimen npiece,vector hpiece,vector pgrad,
         dimen nabs,vector Abs_A,dimen mabs,dimen* I_A,vector Abs_U,
         vector FFC,vector FLOAD,vector SSV,vector mask,
         int DoByRisks,
         long longbasket,long shortbasket,
         long tradebuy,long tradesell,
         double ShortCostScale);
short FrontierCVPAFbl(dimen npoints,vector risk,
									vector arisk,vector rreturn,vector areturn,
									dimen n,long nfac,char** names,vector w,dimen m,
									vector A,vector L,vector U,vector alpha,
									vector benchmark,vector Q,vector initial,
									real delta,vector buy,vector sell,real kappa,long basket,
									long trades,dimen revise,int costs,real min_holding,real min_trade,
									int m_LS,int Fully_Invested,real Rmin,real Rmax,
									int m_Round,vector min_lot,vector size_lot,int* shake,
									dimen ncomp,vector Comp,real LSValue,
									dimen npiece,vector hpiece,vector pgrad,
									dimen nabs,vector Abs_A,dimen mabs,dimen* I_A,vector Abs_U,
									vector FC,vector FL,vector SV,vector mask=0,int DoByRisks=0,
									long longbasket=-1,long shortbasket=-1,
									long tradebuy=-1,long tradesell=-1,double ShortCostScale=1,
									double LSValuel=0,vector Abs_L=0);
short FrontierCVPF(dimen npoints,vector frontrisk,
         vector frontarisk,vector frontrreturn,vector frontareturn,
         dimen n,long nfac,char** names,vector frontw,dimen m,
         vector AAA,vector L,vector U,vector alpha,
         vector benchmark,vector QMATRIXF,vector Initial,
         real delta,vector buy,vector sell,real kappa,long basket,
         long trades,dimen revise,int costs,real min_holding,real min_trade,
         int m_LS,int Fully_Invested,real Rmin,real Rmax,
         int m_Round,vector min_lot,vector size_lot,int* frontshake,
         dimen ncomp,vector Comp,real LSValue,
         dimen npiece,vector hpiece,vector pgrad,
         vector FFC,vector FLOAD,vector SSV,vector mask,
         int DoByRisks);
void PropertiesC(dimen n,long nfac,char** names,vector w,vector alpha,
         vector benchmark,
         vector QMATRIX,double* risk,double* arisk,double* Rrisk,
         double* rreturn,
         double* areturn,double* Rreturn,
         vector MCAR,vector MCTR,vector MCRR,vector FMCRR,
         vector FMCTR,vector   bbeta,vector FX,vector RFX,
         vector  FLOAD,vector FFC,vector SSV,dimen ncomp,
         vector Composite);
void  PropertiesCA(dimen n,long nfac,char** names,vector w,
           vector benchmark,
           vector alpha,real *rreturn,real *areturn,real *Rreturn,
           real *breturn,
           vector QMATRIX,real *risk,real *arisk,real *Rrisk,real *brisk,
           real *srisk,
           real *pbeta,
           vector MCAR,vector MCTR,vector MCRR,vector MCBR,
           vector FMCRR,
           vector FMCTR,vector FMCAR,vector FMCBR,vector FMCSR,
           vector beta,
           vector FX,vector RFX,vector AFX,vector BFX,vector SFX,
           vector  FLOAD,vector FFC,vector SSV,dimen ncomp,
           vector Composite);
void GetBeta(dimen n,long nfac,vector benchmark,vector Q,vector beta,
      dimen ncomp,vector Composite);
void Get_RisksC(dimen n,long nfac,vector Q,vector w,vector benchmark,double* arisk,
          double* risk,double* Rrisk,double* brisk,
          double *pbeta,dimen ncomp,vector Composite);
void  MarginalUtility(dimen n,long nfac,char** names,vector w,
           vector benchmark,vector Initial,
           vector Q,real gamma,real kappa,
           dimen npiece,vector hpiece,vector pgrad,
           vector buy,vector sell,
           vector alpha,real *tcost,real *utility,
           vector gradutility,
           vector utility_per_stock,
           vector cost_per_stock,
           dimen ncomp,
           vector Composite);
void  MarginalUtilityb(dimen n,long nfac,char** names,vector w,
           vector benchmark,vector Initial,
           vector Q,real gamma,real kappa,
           dimen npiece,vector hpiece,vector pgrad,
           vector buy,vector sell,
           vector alpha,real *tcost,real *utility,
           vector gradutility,
           vector utility_per_stock,
           vector cost_per_stock,
           dimen ncomp,
           vector Composite,double ShortCostScale);
short SOCPlsRobust(size_t n,size_t m,vector w,vector A,
										long nf,vector SV,vector FL,vector FC,
										vector alpha,int full,double rmin,double rmax,
										vector L,vector U,double val,double TopRisk,
										vector dalpha,double MaxDalpha,vector covalpha,double MaxValpha,
										size_t nabs,vector Aabs,
										vector Uabs,vector bench,vector initialm,vector initials,int signtest,int fast=0);
short SOCPlsRobustl(size_t n,size_t m,vector w,vector A,
										long nf,vector SV,vector FL,vector FC,
										vector alpha,int full,double rmin,double rmax,
										vector L,vector U,double val,double TopRisk,
										vector dalpha,double MaxDalpha,vector covalpha,double MaxValpha,
										size_t nabs,vector Aabs,vector Labs,
										vector Uabs,vector bench,vector initialm,vector initials,
										int signtest,int fast=0,int maxrobust=0,char*SOCPdump=0);
short SOCPinfeasHomogt(size_t n,size_t m,size_t *ncone,vector c,vector A,
										 vector b,vector x,vector y,vector s,double *tau,
										 double *kappa,size_t maxit,double beta,double delta,double ccomp=1e-6,
										 double cgap=1e-6,int signtest=0,double changeratio=4,
										 double rhoconv=1e-8,int log=0,char*outfile=0,char*SOCPdump=0);
short SOCPlsRobustlC(size_t n,size_t m,vector w,vector A,
										long nf,vector SV,vector FL,vector FC,
										vector alpha,int full,double rmin,double rmax,
										vector L,vector U,double val,double TopRisk,
										vector dalpha,double MaxDalpha,
										size_t nabs,vector Aabs,vector Labs,
										vector Uabs,
										vector bench,vector initial,
										int signtest,int fast=0,int maxrobust=0,char*SOCPdump=0,
										size_t ncomp=0,vector Composites=0,double mintrade=-1);
char*	SOCPlstestMessage(int ifail);
int fix_covariancem(dimen n,vector QFIX);
char* Return_Message(int ifail);
char* expire_date(char*asetup);
char* version(char*asetup);
char* cversion(char*asetup);
void Extract_Factor_Information(dimen nstocks,dimen numfac,dimen Mnstocks,
        vector FLOAD,vector SSV,char** stocklist,
        vector MFLOAD,vector MSV,char** Mstocklist);
void dmx_transpose(dimen n,dimen m,vector A,vector B);
double dsumvec(dimen n,vector a);
void dcopyvec(dimen n,vector a,vector b);
double ddotvec(dimen n,vector a,vector b);
int UnlockBita(char* filename,char*password);

#ifdef __cplusplus
}
#endif

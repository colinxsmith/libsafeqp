template <class T> inline const T max(T a,T b){return (a<b)?b:a;}
template <class T> inline const T min(T a,T b){return (a>b)?b:a;}
template <class T> inline const T square(T a){return a*a;}
#ifdef WIN32
#pragma warning(disable:4786)
#endif
#include<map>
#include<fstream>
#include<vector>
#include<valarray>
#include<iostream>
#include<list>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include"ooptimise.h"
//#include <omp.h>

typedef std::vector<std::string> vstring;
typedef std::vector<double> vdouble;

#define line_len 3000
#define DBAD 1e66
#define IBAD ((size_t) -1)

template <class T> inline T* SetUp(std::vector<T>& a)
{//E.g. get a double* pointer to std::vector<double>
	if(a.size())
		return &(a.front());
	else
		return 0;
}
inline void linefeedcheck(std::string& t)
{
	/*	This lets us use a dos format file on unix	*/
	size_t i;
	if((i=t.find('\r'))!=t.npos)
		t.erase(i);
}
inline bool getlongline(std::ifstream& from,char* line,std::string& temp)
{
/*	This will handle lines longer than 3000 characters.
If the file cannot be opened or is empty we just return false,
if this line is blank, we return true
and if something has been read we return true
	*/
	if(from.fail())
		return false;
	temp.erase();
	from.getline(line,line_len);
	temp+=line;
	linefeedcheck(temp);
	while(from.fail() && from.is_open() && !from.eof())
	{
		from.clear();
		from.getline(line,line_len);
		temp+=line;
		linefeedcheck(temp);
	}
	if(!temp.empty()) 
		return true;
	else 
		return !from.eof() && from.is_open();
}
inline std::string firstspaceout(std::string a)
{
	std::string tt=a;
	if(tt.length())
	{
		while(tt[0]==' ')
			tt=std::string(tt,1,tt.length());
	}
	return tt;
}
inline std::string lastspaceout(std::string a)
{
	std::string tt=a;
	if(tt.length())
	{
		size_t l=tt.length()-1;
		while(tt[l]==' ')
		{
			tt=std::string(tt,0,l);l=tt.length()-1;
		}
	}
	return tt;
}

char* getvar(const char* name,char* def)
{
	char* ff=getenv(name);
	if(!ff)
		return def;
	else
		return ff;
}
void printx(size_t n,double* a)
{
    size_t i=0;
    while(n--)
	{
		printf("%21.13e ",*a++);
		if(i++%5==4)printf("\n");
    }
	printf("\n");
}
inline double aatof(const char*in)
{
	if(strlen(in)) return atof(in);
	else return DBAD;
}
inline int aatoi(const char*in)
{
	if(strlen(in)) return atoi(in);
	else return IBAD;
}
void split(std::string &temp,std::vector<double> &data,std::string splitter)
{
	size_t pos;
	for(pos=temp.find(splitter);pos!=std::string::npos;pos=temp.find(splitter))
	{
		data.push_back(aatof(std::string(temp,0,pos).c_str()));
		temp=std::string(temp,pos+splitter.length(),temp.length());
	}
	data.push_back(aatof(temp.c_str()));
	std::vector<double>::iterator iter;
	std::vector<double>::reverse_iterator riter;
	for(riter=data.rbegin();riter!=data.rend();riter++)
	{
		iter=data.end()-1;
		if(*riter == DBAD) data.erase(iter);
		else break;
	}
}
void split(std::string &temp,std::vector<std::string> &data,std::string splitter)
{
	size_t pos;
	for(pos=temp.find(splitter);pos!=std::string::npos;pos=temp.find(splitter))
	{
		data.push_back(lastspaceout(firstspaceout(std::string(temp,0,pos))));
		temp=std::string(temp,pos+splitter.length(),temp.length());
	}
	data.push_back(lastspaceout(firstspaceout(temp)));
	std::vector<std::string>::iterator iter;
	std::vector<std::string>::reverse_iterator riter;
	for(riter=data.rbegin();riter!=data.rend();riter++)
	{
		iter=data.end()-1;
		if(!riter->length()) data.erase(iter);
		else break;
	}
}
void split(std::string &temp,std::vector<char*> &data,std::string splitter)
{
	size_t pos;
	for(pos=temp.find(splitter);pos!=std::string::npos;pos=temp.find(splitter))
	{
		data.push_back(strdup(lastspaceout(firstspaceout(std::string(temp,0,pos))).c_str()));
		temp=std::string(temp,pos+splitter.length(),temp.length());
	}
	data.push_back(strdup(lastspaceout(firstspaceout(temp)).c_str()));
	std::vector<char*>::iterator iter;
	std::vector<char*>::reverse_iterator riter;
	for(riter=data.rbegin();riter!=data.rend();riter++)
	{
		iter=data.end()-1;
		if(!strlen(*riter)) 
		{
			free(*riter);
			data.erase(iter);
		}
		else break;
	}
}
void deletechar(std::vector<char*> &data)//because we used strdup
{
	std::vector<char*>::iterator iter;
	for(iter=data.begin();iter!=data.end();++iter)
	{
		free(*iter);
	}
}

void split(std::string &temp,std::vector<int> &data,std::string splitter)
{
	size_t pos;
	for(pos=temp.find(splitter);pos!=std::string::npos;pos=temp.find(splitter))
	{
		data.push_back(atoi(std::string(temp,0,pos).c_str()));
		temp=std::string(temp,pos+splitter.length(),temp.length());
	}
	data.push_back(atoi(temp.c_str()));
	std::vector<int>::iterator iter;
	std::vector<int>::reverse_iterator riter;
	for(riter=data.rbegin();riter!=data.rend();riter++)
	{
		iter=data.end()-1;
		if(*riter == (int)IBAD) data.erase(iter);
		else break;
	}
}
void split(std::string &temp,std::vector<long> &data,std::string splitter)
{
	size_t pos;
	for(pos=temp.find(splitter);pos!=std::string::npos;pos=temp.find(splitter))
	{
		data.push_back(atoi(std::string(temp,0,pos).c_str()));
		temp=std::string(temp,pos+splitter.length(),temp.length());
	}
	data.push_back(atoi(temp.c_str()));
	std::vector<long>::iterator iter;
	std::vector<long>::reverse_iterator riter;
	for(riter=data.rbegin();riter!=data.rend();riter++)
	{
		iter=data.end()-1;
		if(*riter == (int)IBAD) data.erase(iter);
		else break;
	}
}
bool testfile(const char* costfile)
{
	if(!costfile)
		return false;
	std::ifstream costFile;
	costFile.open(costfile);
	if(!costFile.is_open())
	{
		std::cout<<"Cannot open file " << costfile <<std::endl;
		return false;
	}
	costFile.close();
	costFile.clear();
	return true;
}
int main(int argc,char** argv)
{
	time_t ltime;
	time(&ltime);
	printf( "Started; %s",(const char*)ctime(&ltime));
	double vv=1.0;//Default long value.
	char*vvv;
	if(argv[argc-1][0]=='-')//Hack to allow us to change long value
	{
		argc--;
		vvv=argv[argc];
		vv=atof(vvv+1);
		printf("%s Value %f\n",vvv+1,vv);
	}
	auto tracefile=getvar("TRACE",(char *)"c:\\users\\colin\\safeqp\\newMirror2@omamquant_mikes_OptimserTrace.log");
	auto costfile=getvar("COSTS",(char *)"c:\\users\\colin\\safeqp\\newcosts1.log");

	if(argc==2)
	{
		tracefile=argv[1];
		costfile=0;
	}
	else if(argc==3)
	{
		tracefile=argv[1];
		costfile=argv[2];
	}

	if(!tracefile)
	{
		std::cout<<"Error; no tracefile"<<std::endl;
		std::cerr<<"Error; no tracefile"<<std::endl;
		return 0;
	}
	
	std::cout<<"Trace file "<< tracefile << std::endl;
	if(costfile)std::cout<<"Cost file "<< costfile << std::endl;
	else std::cout<<"No Cost file"<<std::endl;

	std::ifstream traceFile;
	std::ifstream costFile;

	if(!testfile(tracefile))
		return 34;

	char line[line_len];
	vstring linedata,scalers,vectors;
	std::string temp;
	size_t nscaler=0,nvector=0;
	std::map<std::string,std::string> scalmap;
	std::map<std::string,vdouble> vecmap;
	vstring StockNames;
	vstring FactorNames;
	vstring ConstraintNames;
	std::map<std::string,vdouble> constraintmap;
	vdouble COV;
	size_t i,nlen=0,ncov=0;
	traceFile.open(tracefile);
	while(getlongline(traceFile,line,temp))
//	while(traceFile.getline(line,line_len))
	{
//		temp=line;
//		linefeedcheck(temp);
		if(temp.length())
		{
			if(temp.find("numAssets")!=std::string::npos)
			{
				scalers.erase(scalers.begin(),scalers.end());
				split(temp,scalers,",");
				nscaler=scalers.size();
//				for(i=0;i<nscaler;++i)
//					printf("scalers %s\n",scalers[i].c_str());
			}
			else if(temp.find("alphas")!=std::string::npos)
			{
				vectors.erase(vectors.begin(),vectors.end());
				split(temp,vectors,",");
				nvector=vectors.size();
				for(i=0;i<nvector;++i)
				{
					if(vectors[i].find("actor")!=std::string::npos)
						FactorNames.push_back(vectors[i]);
				}
			}
			else if(nscaler&&!nvector)
			{
				linedata.erase(linedata.begin(),linedata.end());
				split(temp,linedata,",");
				for(i=0;i<linedata.size();++i)
				{
					scalmap[scalers[i]]=linedata[i];
				}
			}
			else if(!nlen&&temp.find("lower")==std::string::npos)
			{
				linedata.erase(linedata.begin(),linedata.end());
				split(temp,linedata,",");
				for(i=0;i<linedata.size();++i)
				{
					if(vectors[i].find("assetNames")!=std::string::npos)
						StockNames.push_back(linedata[i]);
					else
						vecmap[vectors[i]].push_back(atof(linedata[i].c_str()));
				}
			}
			else if(!nlen&&temp.find("lower")!=std::string::npos)
			{
				linedata.erase(linedata.begin(),linedata.end());
				split(temp,linedata,",");
				nlen=linedata.size();
			}
			else if(!ncov&&temp.find("rMFactor")==std::string::npos&&temp.find("Asset")==std::string::npos)
			{
				linedata.erase(linedata.begin(),linedata.end());
				split(temp,linedata,",");
				ConstraintNames.push_back(linedata[0]);
				for(i=1;i<linedata.size();++i)
				{
					(constraintmap[linedata[0]]).push_back(atof(linedata[i].c_str()));
				}
			}
			else if(!ncov&&temp.find("Asset")!=std::string::npos)
			{
				ncov=1;
			}
			else if(!ncov&&temp.find("rmFactor")!=std::string::npos)
			{
				ncov=1;
			}
			else
			{
				linedata.erase(linedata.begin(),linedata.end());
				split(temp,linedata,",");
				for(i=0;i<linedata.size();++i)
					COV.push_back(atof(linedata[i].c_str()));
			}
		}
	}
	printf("len COV %d\n",COV.size());
	traceFile.close();
	traceFile.clear();
	vdouble Hpiece,Pgrad;
	short gethpiece=0,getpgrad=0;
	dimen ncosts=0;
	if(testfile(costfile))
	{
		costFile.open(costfile);
		while(getlongline(costFile,line,temp))
//		while(costFile.getline(line,line_len))
		{
//			temp=line;
//			linefeedcheck(temp);
			if(temp.length())
			{
				if(temp.find("hpiece")!=std::string::npos)
				{
					gethpiece=1;getpgrad=0;
				}
				else if(temp.find("pgrad")!=std::string::npos)
				{
					gethpiece=0;getpgrad=1;
				}
				else if(gethpiece)
				{
					linedata.erase(linedata.begin(),linedata.end());
					split(temp,linedata,",");
					Hpiece.push_back(atof(linedata[0].c_str()));
				}
				else if(getpgrad)
				{
					linedata.erase(linedata.begin(),linedata.end());
					split(temp,linedata,",");
					Pgrad.push_back(atof(linedata[0].c_str()));
				}
			}
		}
		ncosts=(dimen)Pgrad.size();
	}
	costFile.close();
	costFile.clear();
	char CURVEnames[]="numAssets,numFactors,riskModelType,costParameter,costsOnOff,fullyInvested,longShortOnOff,maxNumAssetsInOptimisedPortfolio,maxNumTradesInOptimisedPortfolio,maxShortLongRatio,minAssetTrade,minAssetWeight,minShortLongRatio,numLinearConstraints,numGrossWeightConstraints,numFrontierIncrements,optimisationTechnique,returnParameter,reviseOnOff,roundLotsOnOff,turnoverConstraint,isRiskConstrained,minRisk,maxRisk,numCompositeAssets";
	char QPnames[]="n,nf,riskModelType,kappa,costs,full,ls,basket,trades,rmax,mintrade,minhold,rmin,m,nabs,nfront,optimisationTechnique,gamma,revise,round,delta,isRiskConstrained,minRisk,maxRisk,ncomp";
	vstring qpnames;
	std::map<std::string,std::string> snamemap;
	temp=QPnames;
	qpnames.erase(qpnames.begin(),qpnames.end());
	split(temp,qpnames,",");
	temp=CURVEnames;
	linedata.erase(linedata.begin(),linedata.end());
	split(temp,linedata,",");
	for(i=0;i<qpnames.size();++i)
		snamemap[qpnames[i]]=linedata[i];
	for(i=0;i<qpnames.size();++i)
	{
		printf("%20s\t%20s\t%20s\n",qpnames[i].c_str(),
			snamemap[qpnames[i]].c_str(),
			scalmap[snamemap[qpnames[i]]].c_str());
	}
	std::map<std::string,std::string>::iterator iused;
	for(iused=snamemap.begin();iused!=snamemap.end();iused++)
		printf("%s %s\n",iused->first.c_str(),iused->second.c_str());
	std::string IRC=scalmap[snamemap["isRiskConstrained"]];
	dimen n=atoi(scalmap[snamemap["n"]].c_str());printf("%s\n",snamemap["n"].c_str());
	dimen ncomp=atoi(scalmap[snamemap["ncomp"]].c_str());printf("%s\n",snamemap["ncomp"].c_str());
	dimen m=atoi(scalmap[snamemap["m"]].c_str());printf("%s\n",snamemap["m"].c_str());
	dimen nabs=atoi(scalmap[snamemap["nabs"]].c_str());printf("%s\n",snamemap["nabs"].c_str());
	dimen nfront=atoi(scalmap[snamemap["nfront"]].c_str());printf("%s\n",snamemap["nfront"].c_str());
	long nf=atoi(scalmap[snamemap["nf"]].c_str());printf("%s\n",snamemap["nf"].c_str());
	dimen costs=atoi(scalmap[snamemap["costs"]].c_str());printf("%s\n",snamemap["costs"].c_str());
	dimen full=atoi(scalmap[snamemap["full"]].c_str());printf("%s\n",snamemap["full"].c_str());
	dimen ls=atoi(scalmap[snamemap["ls"]].c_str());printf("%s\n",snamemap["ls"].c_str());
	dimen revise=atoi(scalmap[snamemap["revise"]].c_str());printf("%s\n",snamemap["revise"].c_str());
	dimen round=atoi(scalmap[snamemap["round"]].c_str());printf("%s\n",snamemap["round"].c_str());
	long basket=atoi(scalmap[snamemap["basket"]].c_str());printf("%s\n",snamemap["basket"].c_str());
	long trades=atoi(scalmap[snamemap["trades"]].c_str());printf("%s\n",snamemap["trades"].c_str());
	double minRisk=atof(scalmap[snamemap["minRisk"]].c_str());printf("%s\n",snamemap["minRisk"].c_str());
	double maxRisk=atof(scalmap[snamemap["maxRisk"]].c_str());printf("%s\n",snamemap["maxRisk"].c_str());
	double gamma=atof(scalmap[snamemap["gamma"]].c_str());printf("%s\n",snamemap["gamma"].c_str());
	double delta=atof(scalmap[snamemap["delta"]].c_str());printf("%s\n",snamemap["delta"].c_str());
	double kappa=atof(scalmap[snamemap["kappa"]].c_str());printf("%s\n",snamemap["kappa"].c_str());
	double rmax=atof(scalmap[snamemap["rmax"]].c_str());printf("%s\n",snamemap["rmax"].c_str());
	double rmin=atof(scalmap[snamemap["rmin"]].c_str());printf("%s\n",snamemap["rmin"].c_str());
	double mintrade=atof(scalmap[snamemap["mintrade"]].c_str());printf("%s\n",snamemap["mintrade"].c_str());
	double minhold=atof(scalmap[snamemap["minhold"]].c_str());printf("%s\n",snamemap["minhold"].c_str());
	char CURVEvec[]="alphas,assetNames,benchmarkPortfolio,specificVariance,initialPortfolio,buyCost,minLot,sellCost,sizeLot,lowerBoundAssetWeight,upperBoundAssetWeight";
	char QPvec[]="alpha,stocks,bench,SV,initial,buy,minlot,sell,sizelot,L,U";
	dimen npiece=ncosts/n;
	double* hpiece=0,*pgrad=0;
	if(npiece)
	{
		hpiece=SetUp(Hpiece);
		pgrad=SetUp(Pgrad);
	}
	vstring qpvec;
	std::map<std::string,std::string> vnamemap;
	temp=QPvec;
	qpvec.erase(qpvec.begin(),qpvec.end());
	split(temp,qpvec,",");
	temp=CURVEvec;
	linedata.erase(linedata.begin(),linedata.end());
	split(temp,linedata,",");
	for(i=0;i<qpvec.size();++i)
		vnamemap[qpvec[i]]=linedata[i];
	for(i=0;i<qpvec.size();++i)
	{
		printf("%20s\t%20s\n",qpvec[i].c_str(),
			vnamemap[qpvec[i]].c_str());
	}

	double*alpha=SetUp(vecmap[vnamemap["alpha"]]);
	double*bench=SetUp(vecmap[vnamemap["bench"]]);
	double*SV=SetUp(vecmap[vnamemap["SV"]]);
	double*initial=SetUp(vecmap[vnamemap["initial"]]);
	double*buy=SetUp(vecmap[vnamemap["buy"]]);
	double*sell=SetUp(vecmap[vnamemap["sell"]]);
	double*minlot=SetUp(vecmap[vnamemap["minlot"]]);
	double*sizelot=SetUp(vecmap[vnamemap["sizelot"]]);

	if((buy==0&&sell==0)||(buy&&sell&&dsumvec(n,buy)==0&&dsumvec(n,sell)==0))
	{
		costs=0;std::cout<<"Costs turned off"<<std::endl;
	}

	vdouble AA,UU_abs,AA_abs,FFL,LL_abs;
	long j;
	for(j=0;j<ConstraintNames.size();j++)
	{
		if(ConstraintNames[j].find("linear")!=std::string::npos)
		{
			vecmap[vnamemap["L"]].push_back((constraintmap[ConstraintNames[j]])[0]);
			vecmap[vnamemap["U"]].push_back((constraintmap[ConstraintNames[j]])[1]);
			double*a =SetUp(vecmap[ConstraintNames[j]]);
			if(a)
			{
				for(i=0;i<n;++i)
				{
					AA.push_back(*a++);
				}
			}
//			printf("linear \n");
		}
		else if(ConstraintNames[j].find("gros")!=std::string::npos)
		{
			UU_abs.push_back((constraintmap[ConstraintNames[j]])[1]);
			LL_abs.push_back((constraintmap[ConstraintNames[j]])[0]);
			double*a =SetUp(vecmap[ConstraintNames[j]]);
			if(a)
			{
				for(i=0;i<n;++i)
				{
					AA_abs.push_back(*a++);
				}
			}
			//			printf("gross \n");
		}
	}
	for(j=0;j<nf;++j)
	{
		double*a =SetUp(vecmap[FactorNames[j]]);
		if(a)
		{
			for(i=0;i<n;++i)
			{
				FFL.push_back(*a++);
			}
		}
	}

	double* L=SetUp(vecmap[vnamemap["L"]]);
	double* U=SetUp(vecmap[vnamemap["U"]]);
	double* A=SetUp(AA);
	dmx_transpose(n,m,A,A);
	double* U_abs=SetUp(UU_abs);
	double* L_abs=SetUp(LL_abs);
	double* A_abs=SetUp(AA_abs);
	dmx_transpose(n,nabs,A_abs,A_abs);
	double* FL=SetUp(FFL);
	char** stocks=new char*[n];
	for(i=0;i<n;++i)
		stocks[i]=(char*)StockNames[i].c_str();

	double* w=new double[n],*Comp=0,value=vv,ogamma;
	int* shake=new int[n];
	double*Q=0,*FC=0;
	std::valarray<double>QQ;
	if(nf>-1)
	{
		FC=SetUp(COV);
		if(!Q)
		{
			QQ.resize((nf+1)*n);
			Q=&QQ[0];
		}
	}
	else
	{
		Q=SetUp(COV);
		SV=0;
		FL=0;
	}
	
	/*Optimise_internalCVPAFb(dimen n,long nfac,char** stocknames,vector w_opt,dimen m,
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
	double zetaS,double zetaF,double ShortCostScale);*/
	
	if(IRC=="false")
	{
		minRisk=maxRisk=-1;printf("No Risk Constraint\n");
	}
	if(ncomp)
	{
		Comp=new double[ncomp*(n-ncomp)];
		double *gg;
		for(i=0;i<ncomp;++i)
		{
			gg =SetUp(vecmap[StockNames[n-ncomp+i]]);
			dcopyvec(n-ncomp,gg,Comp+(n-ncomp)*i);
		}
	}
	printf("Q=%lx\n",Q);
	printf("SV=%lx\n",SV);
	printf("FL=%lx\n",FL);
	printf("FC=%lx\n",FC);
	clock_t t1=clock();
//UnlockBita("s:/paskey/BITA_PAS_key","colincolin12");
	short back=Optimise_internalCVPAFbl(n,nf,stocks,w,m,A,L,U,alpha,bench,Q,gamma,initial,delta,buy,sell,
		kappa,basket,trades,revise,costs,minhold,mintrade,ls,full,rmin,rmax,
		round,minlot,sizelot,shake,ncomp,Comp,value,npiece,hpiece,pgrad,
		nabs,A_abs,0,0,U_abs,FC,FL,SV,minRisk,maxRisk,&ogamma,0,1,0,
		0,0,-1,-1,-1,-1,1,1,1,0,L_abs);
	clock_t t2=(clock()-t1)/CLOCKS_PER_SEC;
	double arisk,risk,Rrisk,brisk,pbeta,areturn,rreturn;
	rreturn=ddotvec(n,bench,alpha);
	areturn=ddotvec(n,w,alpha);
	rreturn=areturn-rreturn;

	Get_RisksC(n,nf,Q,w,bench,&arisk,&risk,&Rrisk,&brisk,&pbeta,ncomp,Comp);
	printf("Absolute return %20.8e, Absolute risk %20.8e\n",areturn,arisk);
	printf("Relative return %20.8e, Relative risk %20.8e\n",rreturn,risk);
	std::string results=tracefile;
	vstring backer;
	if(results.find("\\")<std::string::npos)
	{
		size_t pos;
		if((pos=results.find(".\\"))<std::string::npos)
			results=std::string(results,pos+strlen(".\\"),results.length());
		split(results,backer,"\\");
		results=backer[backer.size()-1];
	}
	else if(results.find("/")<std::string::npos)
	{
		size_t pos;
		if((pos=results.find("./"))<std::string::npos)
			results=std::string(results,pos+strlen("./"),results.length());
		split(results,backer,"/");
		results=backer[backer.size()-1];
	}
	results="OUTPUT"+results;
	FILE*RES=fopen(results.c_str(),"w");
	fprintf(RES,"%5d\n",back);
	for(i=0;i<n;i++)
		fprintf(RES,"%20.10e ",w[i]);
	fprintf(RES,"\n");
	for(i=0;i<n;i++)
		fprintf(RES,"%d ",shake[i]);
	fprintf(RES,"\n");
	fclose(RES);
	if(Comp)delete[]Comp;
	delete[]w;
	delete[]shake;
	delete[]stocks;
	printf("%s\n",Return_Message(back));
	printf("Time taken for optimisation; %d seconds\n",t2);
	time(&ltime);
	printf( "Finished; %s",ctime(&ltime));
	return back;
}


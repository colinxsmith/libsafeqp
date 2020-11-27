template <typename T> inline const T max(T a,T b){return (a<b)?b:a;}
template <typename T> inline const T min(T a,T b){return (a>b)?b:a;}
template <typename T> inline const T square(T a){return a*a;}

#pragma warning(disable:4786)
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
#include<cmath>
#include<PASopt.h>
//
typedef std::vector<std::string> vstring;
typedef std::vector<double> vdouble;

#define line_len 100000 
#define DBAD 1e66
#define IBAD ((dimen) -1)

inline void linefeedcheck(std::string& t)
{
	/*	This lets us use a dos format file on unix	*/
	std::string::size_type i;
	if((i=t.find('\r'))!=t.npos)
		t.erase(i);
}
inline bool getlongline(std::ifstream& from,char* line,std::string& temp)
{
/*	This will handle lines longer than line_len characters.
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
inline std::string firstspaceout(std::string a,const char space=' ')
{
	std::string tt=a;
	if(tt.length())
	{
		while(tt[0]==space)
			tt=std::string(tt,1,tt.length());
	}
	return tt;
}
inline std::string lastspaceout(std::string a,const char space=' ')
{
	std::string tt=a;
	if(tt.length())
	{
		size_t l=tt.length()-1;
		while(tt[l]==space)
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
void printx(dimen n,double* a)
{
    dimen i=0;
    while(n--)
	{
		printf("%21.13e ",*a++);
		if(i++%5==4)printf("\n");
    }
	printf("\n");
}
inline double aatof(const char*in,const char* splitter=(char*)" ")
{
	std::string temp;
	temp=in;
	if(strlen(in)&&(temp.find(splitter,0)!=0)) return atof(in);
	else return DBAD;
}
inline int aatoi(const char*in)
{
	if(strlen(in)) return atoi(in);
	else return (int) IBAD;
}
void split(std::string &temp,std::vector<double> &data,std::string splitter)
{
	/*
	This now works properly for ignoring extra splitter characters at the beginning and end of each line
	and also for multiple line input.
	*/
	std::string::size_type pos,ppos,maxline=1000;
	double back;
	for(ppos=0,pos=temp.find(splitter,ppos);pos<std::string::npos;)
	{
		if((back=aatof((std::string(temp,ppos,pos-ppos)).c_str(),splitter.c_str()))!=DBAD)
		{
			data.push_back(back);
		}
		ppos=pos+1;
		pos=temp.find(splitter,ppos);
//		std::cout<<pos-ppos<<std::endl;
		if(pos>=maxline&&pos<std::string::npos)
		{
			data.push_back(aatof(std::string(temp,ppos,pos-ppos).c_str(),splitter.c_str()));
//			std::cout<<temp.length()<<std::endl;
			temp=std::string(temp,pos+splitter.length(),temp.length());
			ppos=0;
			pos=temp.find(splitter,ppos);
		}
	}
//	std::cout<<"End"<<std::endl;
	data.push_back(aatof(std::string(temp,ppos,pos-ppos).c_str(),splitter.c_str()));
	std::vector<double>::iterator iter;
	for(iter=data.end()-1;iter>=data.begin();iter--)
	{
		if(*iter == DBAD) iter=data.erase(iter);
		else break;
	}
}
void split(std::string &temp,std::vector<std::string> &data,std::string splitter)
{
	std::string::size_type pos;
	for(pos=temp.find(splitter);pos!=std::string::npos;pos=temp.find(splitter))
	{
		data.push_back(lastspaceout(firstspaceout(std::string(temp,0,pos))));
		temp=std::string(temp,pos+splitter.length(),temp.length());
	}
	data.push_back(lastspaceout(firstspaceout(temp)));
	std::vector<std::string>::iterator iter;
	for(iter=data.end()-1;iter>=data.begin();iter--)
	{
		if(!iter->length()) iter=data.erase(iter);
		else break;
	}
}
void split(std::string &temp,std::vector<char*> &data,std::string splitter)
{
	std::string::size_type pos;
	for(pos=temp.find(splitter);pos!=std::string::npos;pos=temp.find(splitter))
	{
		data.push_back(strdup(lastspaceout(firstspaceout(std::string(temp,0,pos))).c_str()));
		temp=std::string(temp,pos+splitter.length(),temp.length());
	}
	data.push_back(strdup(lastspaceout(firstspaceout(temp)).c_str()));
	std::vector<char*>::iterator iter;
	for(iter=data.end()-1;iter>=data.begin();iter--)
	{
		if(!strlen(*iter)) 
		{
			free(*iter);
			iter=data.erase(iter);
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
	std::string::size_type pos;
	for(pos=temp.find(splitter);pos!=std::string::npos;pos=temp.find(splitter))
	{
		data.push_back(atoi(std::string(temp,0,pos).c_str()));
		temp=std::string(temp,pos+splitter.length(),temp.length());
	}
	data.push_back(atoi(temp.c_str()));
	std::vector<int>::iterator iter;
	for(iter=data.end()-1;iter>=data.begin();iter--)
	{
		if(*iter == (int)IBAD) iter=data.erase(iter);
		else break;
	}
}
void split(std::string &temp,std::vector<long> &data,std::string splitter)
{
	std::string::size_type pos;
	for(pos=temp.find(splitter);pos!=std::string::npos;pos=temp.find(splitter))
	{
		data.push_back(atoi(std::string(temp,0,pos).c_str()));
		temp=std::string(temp,pos+splitter.length(),temp.length());
	}
	data.push_back(atoi(temp.c_str()));
	std::vector<long>::iterator iter;
	for(iter=data.end()-1;iter>=data.begin();iter--)
	{
		if(*iter == (long)IBAD) iter=data.erase(iter);
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
bool matchnumber_sp(char a)
{
	int tt=(int)(a-'0');
	return (a=='e'||a=='E'||a==' '||a=='-'||a=='+'||(tt<=9&&tt>=0))?true:false;
}
vector getvector(std::map<std::string,vdouble>& vecmap,char*name)
{
	vector back;
	if(vecmap.find(name)!=vecmap.end())
	{
		back= &vecmap[name].front();
		return back;
	}
	else
		return 0;
}
int main(int argc,char** argv)
{

	time_t ltime;
	time(&ltime);
	printf( "Started; %s",(const char*)ctime(&ltime));


	clock_t t1=clock();
#ifdef PAS
	if(!UnlockBita((char*) "BITA_PAS_key",(char*) "colincolin1"))
	{
		std::cout<<"Error; bad PAS key"<<std::endl;
		std::cerr<<"Error; bad PAS key"<<std::endl;
		return 45;
	}

#endif
	char* tracefile=0;
	char* logfile=0;
	if(argc==2)
	{
		tracefile=argv[1];
	}

	if(!tracefile)
	{
		std::cout<<"No tracefile"<<std::endl;
		std::cerr<<"No tracefile"<<std::endl;
		time(&ltime);
		printf( "Finished; %s",ctime(&ltime));
		char mess[500];
		printf("%s\n",version(mess));
		return 0;
	}
	
	std::cout<<"Trace file "<< tracefile << std::endl;

	std::ifstream traceFile;

	if(!testfile(tracefile))
	{
		time(&ltime);
		printf( "Finished; %s",ctime(&ltime));
		return 34;
	}

	char line[line_len];
	std::string attribs=(char*)"NumStocks NumFactors NumLinConstraints AAA lower upper alpha BenchmarkOrZero Q gamma Initial delta buy sell kappa basket trades revise costs min_holding min_trade m_LS Fully_Invested Rmin Rmax m_Round min_lot size_lot ncomp Composite LSValue npiece hpiece pgrad nabs Abs_A mabs I_A Abs_U FCnil FLnil SVnil minRisk maxRisk ogamma1 mask log logfile downrisk downfactor longbasket shortbasket tradebuy tradesell zetaS zetaF ShortCostScale LSValueL Abs_L";
	vstring vattribs;
	vdouble linedata;
	vattribs.erase(vattribs.begin(),vattribs.end());
	split(attribs,vattribs," ");
	std::string temp;
	size_t nvector=vattribs.size(),i,il;
	std::map<std::string,vdouble> vecmap;
	traceFile.open(tracefile);
	std::string SOCPdump=(char*)"";
	std::string outfile=(char*)"";
	int prevkey=-1,nkeys=0;
	getlongline(traceFile,line,temp);
	while(temp.length())
	{
		for(i=0;i<nvector&&(nkeys<nvector);++i)
		{
			if(vattribs[i].size()==temp.size()&&temp.find(vattribs[i])==0/*std::string::npos*/)
			{
				prevkey=i;nkeys++;
				std::cout<<"������������������������  "<<line<<"  ������������������������"<<std::endl;
					if(getlongline(traceFile,line,temp))
					{
						if((il=temp.length())>0)
						{
							std::cout<<"Line length "<<il<<std::endl;
							linedata.erase(linedata.begin(),linedata.end());//New data item to be set up so erase what's there before starting
							split(temp,linedata," ");
							std::cout<<"Number of items "<<linedata.size()<<std::endl;
							if(linedata.size())std::cout<<"First item "<<linedata[0]<<std::endl;
						}
					}
					else break;
			}
			else if(temp.find("outfile")==0)
			{
				if(getlongline(traceFile,line,temp))
				{
					if(temp.length())
					{
						outfile=temp;
					}
				}
				else break;
			}
			while(prevkey>=0)
			{
				if(getlongline(traceFile,line,temp))
				{
					if(matchnumber_sp(line[0]))
					{
						if(il=temp.length())
						{
							std::cout<<"Line length "<<il<<std::endl;
							split(temp,linedata," ");//split has been written to work across more than one line
							std::cout<<"Number of items "<<linedata.size()<<std::endl;
							if(linedata.size())std::cout<<"First item "<<linedata[0]<<std::endl;
						}
					}
					else 
					{
						if(linedata[0]!=DBAD)//Do the data storing here so that it is not repeated
						{
							if(il>0)vecmap[vattribs[prevkey]]=linedata;
						}
						prevkey=-2;
						i=-1;//Need the loop to continue from 0
					}
				}
				else break;
			}
		}
		getlongline(traceFile,line,temp);
	}
	traceFile.close();
	size_t m=(size_t)vecmap["NumLinConstraints"][0],ii;
	size_t n=(size_t)vecmap["NumStocks"][0];
	size_t nf=(size_t)vecmap["NumFactors"][0];
	vector A=getvector(vecmap,(char*)"AAA");
	vector L=getvector(vecmap,(char*)"lower");
	vector U=getvector(vecmap,(char*)"upper");
	vector alpha=&vecmap["alpha"].front();
	vector bench=getvector(vecmap,(char*)"BenchmarkOrZero");
	vector Q=&vecmap["Q"].front();
	double gamma=(double)vecmap["gamma"][0];
	vector initial=(vector)getvector(vecmap,(char*)"Initial");
	double delta=(double)vecmap["delta"][0];
	vector buy=getvector(vecmap,(char*)"buy");
	vector sell=getvector(vecmap,(char*)"sell");
	double kappa=(double)vecmap["kappa"][0];
	long basket=(long)vecmap["basket"][0];
	long trades=(long)vecmap["trades"][0];
	int revise=(int)vecmap["revise"][0];
	int costs=(int)vecmap["costs"][0];
	double minhold=(double)vecmap["min_holding"][0];
	double mintrade=(double)vecmap["min_trade"][0];
	int ls=(int)vecmap["m_LS"][0];
	int full=(int)vecmap["Fully_Invested"][0];
	double rmin=(double)vecmap["Rmin"][0];
	double rmax=(double)vecmap["Rmax"][0];
	int round=(int)vecmap["m_Round"][0];
	vector minlot=getvector(vecmap,(char*)"min_lot");
	vector sizelot=getvector(vecmap,(char*)"size_lot");
	size_t ncomp=(size_t)vecmap["ncomp"][0];
	vector Comp=getvector(vecmap,(char*)"Composite");
	if(vecmap.find("Composite")!=vecmap.end())
		Comp=&vecmap["Composite"].front();
	double value=(double)vecmap["LSValue"][0];
	double valueL=(double)vecmap["LSValueL"][0];
	dimen npiece=(dimen)vecmap["npiece"][0];
	vector hpiece=getvector(vecmap,(char*)"hpiece");
	vector pgrad=getvector(vecmap,(char*)"pgrad");
	dimen nabs=(dimen)vecmap["nabs"][0];
	vector A_abs=getvector(vecmap,(char*)"Abs_A");
	dimen mabs=(dimen)vecmap["mabs"][0];
	vector I_Af=getvector(vecmap,(char*)"I_A");

	std::valarray<dimen> I_A(mabs);
	for(ii=0;ii<mabs;++ii)
		I_A[ii]=(size_t)I_Af[ii];

	vector U_abs=getvector(vecmap,(char*)"Abs_U");
	vector L_abs=getvector(vecmap,(char*)"Abs_L");
	vector FC=getvector(vecmap,(char*)"FCnil");
	vector FL=getvector(vecmap,(char*)"FLnil");
	vector SV=getvector(vecmap,(char*)"SVnil");
	double minRisk=(double)vecmap["minRisk"][0];
	double maxRisk=(double)vecmap["maxRisk"][0];
	double ogamma=(double)vecmap["ogamma1"][0];
	double ShortCostScale=(double)vecmap["ShortCostScale"][0];
	int tradebuy=(int)vecmap["tradebuy"][0];
	int tradesell=(int)vecmap["tradesell"][0];
	int longbasket=(int)vecmap["longbasket"][0];
	int shortbasket=(int)vecmap["shortbasket"][0];
	vector mask=(vector)getvector(vecmap,(char*)"mask");



	std::valarray<double>w(n);
	std::valarray<int>shake(n);


	short back=Optimise_internalCVPAFbl(n,nf,0,&w[0],m,A,L,U,alpha,bench,Q,gamma,initial,delta,buy,sell,
		kappa,basket,trades,revise,costs,minhold,mintrade,ls,full,rmin,rmax,
		round,minlot,sizelot,&shake[0],ncomp,Comp,value,npiece,hpiece,pgrad,
		nabs,A_abs,mabs,&I_A[0],U_abs,FC,FL,SV,minRisk,maxRisk,&ogamma,mask,1,0,
		0,3,longbasket,shortbasket,tradebuy,tradesell,1,1,ShortCostScale,valueL,L_abs);

	clock_t t2=(clock()-t1)/CLOCKS_PER_SEC;
	double arisk,risk,Rrisk,brisk,pbeta,areturn,rreturn;
	rreturn=ddotvec(n,bench,alpha);
	areturn=ddotvec(n,&w[0],alpha);
	rreturn=areturn-rreturn;

	Get_RisksC(n,nf,Q,&w[0],bench,&arisk,&risk,&Rrisk,&brisk,&pbeta,ncomp,Comp);
	printf("Absolute return %20.8e, Absolute risk %20.8e\n",areturn,arisk);
	printf("Relative return %20.8e, Relative risk %20.8e\n",rreturn,risk);
	std::string results=tracefile;
	vstring backer;
	if(results.find("\\")<std::string::npos)
	{
		std::string::size_type pos;
		if((pos=results.find(".\\"))<std::string::npos)
			results=std::string(results,pos+strlen(".\\"),results.length());
		split(results,backer,"\\");
		results=backer[backer.size()-1];
	}
	else if(results.find("/")<std::string::npos)
	{
		std::string::size_type pos;
		if((pos=results.find("./"))<std::string::npos)
			results=std::string(results,pos+strlen("./"),results.length());
		split(results,backer,"/");
		results=backer[backer.size()-1];
	}
	results=(char*)"OUTPUT"+results;
	FILE*RES=fopen(results.c_str(),"w");
	fprintf(RES,"%5d\n",back);
	for(i=0;i<n;i++)
		fprintf(RES,"%20.10e ",w[i]);
	fprintf(RES,"\n");
	for(i=0;i<n;i++)
		fprintf(RES,"%d ",shake[i]);
	fprintf(RES,"\n");
	fclose(RES);
	printf("%s\n",Return_Message(back));
	printf("Time taken for optimisation; %ld seconds\n",t2);
	time(&ltime);
	printf( "Finished; %s",ctime(&ltime));
	char mess[500];
	printf("%s\n",version(mess));
	return 0;
}


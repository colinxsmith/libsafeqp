template <class T> inline const T max(T a,T b){return (a<b)?b:a;}
template <class T> inline const T min(T a,T b){return (a>b)?b:a;}
template <class T> inline const T square(T a){return a*a;}

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
#include<conic.h>
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
inline double aatof(const char*in,const char* splitter=" ")
{
	std::string temp;
	temp=in;
	if(strlen(in)&&(temp.find(splitter,0)!=0)) return atof(in);
	else return DBAD;
}
inline int aatoi(const char*in)
{
	if(strlen(in)) return atoi(in);
	else return IBAD;
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
template <class T> T* getvector(std::map<std::string,std::vector<T> >&vecmap,const char*name)
{
	T* back=0;
	if(vecmap.find(name)!=vecmap.end())
		back=&vecmap[name].front();
	return back;
}
template <class T> T getscalar(std::map<std::string,std::vector<double> >&vecmap,const char*name,T init=0)
{
	T back=init;
	if(vecmap.find(name)!=vecmap.end())
		back=(T)vecmap[name][0];
	return back;
}
int main(int argc,char**argv,char**env)
{
	bool do_first=true;//Only read in the first job's data in the input file if do_first is true otherwise do the last job's data
	char*pargv;
	char**ppargv=argv;
	while((pargv=*ppargv++))
	{
		if(pargv[0]=='-')//Must have the - flags before the others
		{
			if(pargv[1]=='l')
			{
				do_first=false;
			}
			else if(pargv[1]=='f')
			{
				do_first=true;
			}
			argc--;argv++;
		}
	}
	char*penv;
	std::string k;
	std::vector<char*>kk;
	std::vector<char*>::iterator kkk;
	while((penv=*env))
	{
		k=penv;
		split(k,kk,"=");
		for(kkk=kk.begin();kkk!=kk.end();)
			kkk=kk.erase(kkk);
		env++;
	}
	time_t ltime;
	time(&ltime);
	printf("Started; %s",ctime(&ltime));
	char* tracefile=getvar((const char*)"SOCP",(char*)"conic.log");
	char* logfile=getvar((const char*)"LOGSOCP",(char*)"checklog");

	if(argc==2)
	{
		tracefile=argv[1];
	}

	if(!tracefile)
	{
		std::cout<<"Error; no tracefile"<<std::endl;
		std::cerr<<"Error; no tracefile"<<std::endl;
		time(&ltime);
		printf("Finished; %s",ctime(&ltime));
		return 0;
	}
	
	std::cout<<"Trace file "<< tracefile << std::endl;

	std::ifstream traceFile;

	if(!testfile(tracefile))
	{
		time(&ltime);
		printf("Finished; %s",ctime(&ltime));
		return 34;
	}

	char line[line_len];
	std::string attribs="ncone,cone,typecone,m,A,b,c,comptoll,gaptoll,stepmax,straight,fastbreak,method,homog,nf,SV,FL,FC,fcone";
	vstring vattribs;
	vdouble linedata;
	vattribs.erase(vattribs.begin(),vattribs.end());
	split(attribs,vattribs,",");
	std::string temp;
	std::string::size_type nvector=vattribs.size(),il;
	std::string::size_type i;
	std::map<std::string,vdouble> vecmap;
	traceFile.open(tracefile);
	std::string outfile="";
	int prevkey=-1,nkeys=0;
	getlongline(traceFile,line,temp);
	while(temp.length())
	{
		for(i=0;i<nvector&&((!do_first)||(nkeys<nvector));++i)
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
//#ifdef AWAY
	dimen ncone=(dimen)vecmap["ncone"][0];
	dimen m=(dimen)vecmap["m"][0];
	int straight=(int)getscalar(vecmap,"straight",1);
	int fastbreak=(int)getscalar(vecmap,"fastbreak",0);
	int log=2;
	double comptoll=(double)getscalar(vecmap,"comptoll",1e-9);
	double gaptoll=(double)getscalar(vecmap,"gaptoll",1e-9);
	double stepmax=(double)getscalar(vecmap,"stepmax",1e-5);
	vector A=(vector)getvector(vecmap,"A");
	vector b=(vector)getvector(vecmap,"b");
	vector c=(vector)getvector(vecmap,"c");
	int method=(int)getscalar(vecmap,"method",0);
	int homog=(int)getscalar(vecmap,"homog",1);
	long nf=(long) getscalar(vecmap,"nf",0);
	size_t fcone=(size_t) getscalar(vecmap,"fcone",0);
	vector SV=(vector)getvector(vecmap,"SV");
	vector FL=(vector)getvector(vecmap,"FL");
	vector FC=(vector)getvector(vecmap,"FC");

	std::valarray<int>vcone(ncone),vtypecone(ncone);
	dimen nn;
	for(i=0,nn=0;i<ncone;i++)
	{
		nn+=vcone[i]=(int)vecmap["cone"][i];
		vtypecone[i]=(int)vecmap["typecone"][i];
	}
	std::valarray<double>x(nn),y(m),s(nn);
	double tau=1,kappa=1;
	x=0;
	y=0;
	s=0;
	double norm=sqrt(ddotvec(nn*m,A,A)+ddotvec(nn,c,c)+ddotvec(m,b,b));
	printf("Normalisation factor %20.8e\n",norm);
	clock_t t1=clock();
	short back=Conic_VeryGeneral(ncone,&vcone[0],&vtypecone[0],m,&x[0],&s[0],&y[0],A,b,c,&tau,&kappa,comptoll,gaptoll,stepmax,straight,fastbreak,log,logfile,method,
	homog,nf,SV,FL,FC,fcone);
	clock_t t2=(clock()-t1)/CLOCKS_PER_SEC;
	printf("Return code; %d\nTime taken for Conic optimisation; %ld seconds\n",back,t2);

	if(back)
		printf("Conic optimisation failed\n");
	else
	{
		if(tau/kappa > 100)
		{
			dimen i,ic,tot;
			dscalvec(nn,1./tau,&x[0]);
			dscalvec(nn,1./tau,&s[0]);
			dscalvec(m,1./tau,&y[0]);
			std::valarray<double> Ax(m),yA(nn);
			dmxtmulv(nn,m,A,&x[0],&Ax[0]);
			dmxmulv(nn,m,A,&y[0],&yA[0]);
			printf("%20s %20s %20s\n","b","Ax","b-Ax");
			double pRes=0,dRes=0;
			for(i = 0;i<m;++i)
			{
				printf("%20.13e %20.13e %20.13e\n",b[i],Ax[i],b[i]-Ax[i]);pRes+=square(b[i]-Ax[i]);
			}
			printf("%20s %20s %20s\n","s","c-yA","s-c+yA");
			for(i = 0,ic=0,tot=0;i<nn;++i)
			{
				if(vcone[ic]==(int)(i - tot))
				{
					tot=i;
					ic++;
				}
				printf("(%d %d) %20.13e %20.13e %20.13e\n",ic,i,s[i],c[i]-yA[i],s[i]-c[i]+yA[i]);dRes+=square(s[i]-c[i]+yA[i]);
			}
			double primal=ddotvec(nn,&x[0],c);
			double dual=ddotvec(m,&y[0],b);
			vector px,ps;
			int rank,j;
			for(i = 0,px=&x[0],ps=&s[0];i<ncone;px+=vcone[i],ps+=vcone[i],i++)
			{
				if(vtypecone[i]==2)//Check rank for positive semi-definite cones
				{
					size_t n=(size_t)(-0.25+.5*sqrt(1.0+8.0*vcone[i]));
					std::valarray<double>X(n*n),eigv(n);
					SDPsMat(n,px,&X[0]);
					back=eigendecomp(n,&X[0],&eigv[0],200);
					if(back)printf("Eigenvalues for x failed\n");
					for(j=0,rank=0;j<n;++j)
					{
						if(eigv[j]>1e-4*eigv[0])//rough way to get an idea of the rank
						{
							printf("x psd cone %d; eigenvalue[%d]=%e\n",i,j,eigv[j]);
							rank++;
						}
					}
					printf("cone %d in x has rank %d\n",i,rank);
					SDPsMat(n,ps,&X[0]);
					back=eigendecomp(n,&X[0],&eigv[0],200);
					if(back)printf("Eigenvalues for s failed\n");
					for(j=0,rank=0;j<n;++j)
					{
						if(eigv[j]>1e-4*eigv[0])//rough way to get an idea of the rank
						{
							printf("s psd cone %d; eigenvalue[%d]=%e\n",i,j,eigv[j]);
							rank++;
						}
					}
					printf("cone %d in s has rank %d\n",i,rank);
				}
			}
			printf("tau               %20.8e\n",tau);
			printf("kappa             %20.8e\n",kappa);
			printf("Primal            %20.8e\n",primal);
			printf("Dual              %20.8e\n",dual);
			printf("Complementarity   %20.8e\n",ddotvec(nn,&x[0],&s[0]));
			printf("Gap               %20.8e\n",primal-dual);
			printf("Total pRes = %20.8e, Total dRes = %20.8e\n",pRes,dRes);
		}
		else
			printf("Conic optimisation was infeasible\n");
	}
	time(&ltime);
	printf("Finished; %s dimen size %d",ctime(&ltime),sizeof(dimen));
//#endif
	return 0;
}


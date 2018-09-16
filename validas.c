#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <sys/file.h>
#define	_NO_KRYPTON_VARS_
#define _GNU_SOURCE

#include "krypton.h"
char	Hdr[] = "Analytic server from BITA Plus, ver ";
char	Cdr[] = "Optimiser from BITA Plus. ";
char	Tdr[] = "DLL made ";
#define SEARCH 0
#define MATCH 1
#define SKIP 2
#define DONE 3
static	int	buf_i=BUFSIZ;
static	int	buf_l=BUFSIZ;
static	char	buf[BUFSIZ];
static	int	readchar(
			int	exe,
			char	*pc
			)
{
	if(buf_i>=buf_l){
		buf_l = read(exe,buf,BUFSIZ);
		buf_i = 0;
		if(buf_l<=0) return -1;
		}
	*pc = buf[buf_i++];
	return 1;
}

typedef union
{
	unsigned char conv[16];
	long	key;
}	compkeyn;
int main	(
		int	argc,
		char	**argv
		)
{
	int	exe,err;
	long	key[4];
	long long pos=0;
	compkeyn	compkeynumber={(long)0};
	int	i;
	int	state = SEARCH;
	char	c, *ptr;
	validator_t v;
	time_t	t;
	time(&t);

	printf("TODAY=%ld=",t);
	printf("%s",(char *)ctime(&t));
	printf("Sizeof validator_t=%d\n", sizeof(validator_t));
	
	if(argc==2 && argv[1][0]=='-' && argv[1][1]=='i'){
			extern long guniqid(void);
		fprintf(stderr,"validas unique id = %lX\n", guniqid());
		exit(0);
		}
	else if(argc<6){
		fprintf(stderr,"validas: usage error\n");
		fprintf(stderr,"use validas file key1 key2 key3 key4 compkeynumber\n");
		fprintf(stderr,"or  validas -i\n");
		exit(1);
		}

	for(i=0;i<4;i++){
		if(!sscanf(argv[2+i],"%lx", key+i)){
			fprintf(stderr,"validas: can't convert key %s\n",
				argv[2+i]);
			exit(1);
			}
		}
	if(argc == 7)
	{
		if(!sscanf(argv[6],"%ld", &(compkeynumber.key)))
		{
			fprintf(stderr,"validas: can't convert compkeynumber %s\n",
				argv[6]);
			exit(1);
		}
	}
#ifdef	__SYSNT__
	exe = open(argv[1],O_RDWR | O_BINARY);
#else
	exe = open(argv[1],O_RDWR);
#endif

	if(exe<0){
		fprintf(stderr,"validas: cannot open file %s\n", argv[1] );
		exit(1);
		}

	while( state!=DONE && (err = readchar(exe,&c)) != 0){
		if(err == -1)
		{
			pos = lseek(exe,pos,SEEK_SET);
			err =  readchar(exe,&c);
		}
		pos++;
		switch(state){
			case SEARCH:
				if(c==Hdr[0]){
					ptr = Hdr;
					state = MATCH;
					}
				else	if(c==Cdr[0]){
					ptr = Cdr;
					state = MATCH;
					}
				else	if(c==Tdr[0]){
					ptr = Tdr;
					state = MATCH;
					}
				break;
			case MATCH:
				if(c== *++ptr){
					if(!ptr[1])
						 state = SKIP;
					}
				else	state = SEARCH;
				break;
			case SKIP:
				printf("%c",c);
				if( !c ){
					v.t.start = key[0];
					v.t.stop = key[1];
					v.t.pad = key[2];
					v.t.hid = key[3];
					printf("\n%lx %lx %lx %lx\n",v.t.start,v.t.stop,v.t.pad,v.t.hid);
					pos = lseek(exe,pos,SEEK_SET);
					if(pos<0){
						fprintf(stderr,"validas: seek failed\n");
						exit(1);
						}
					if((i = write(exe,v.b,16))<16){
						fprintf(stderr,"validas: write failed\n");
						exit(1);
						}
					if(compkeynumber.key&&(i = write(exe,compkeynumber.conv,16))<16){
						fprintf(stderr,"validas: write failed\n");
						exit(1);
						}
					printf("validas: o.k. pos=%ld, %d\n",pos,i);
					state = DONE;
					if((i = close(exe)))
						printf("%s close error %d\n",argv[1],i);
				//	exit(0);
					}
			}
		}

	if(state!=DONE){
		fprintf(stderr,"validas: failed to install the validus\n");
		exit(1);
		}
	return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

#define children 2

int value;
int pid,stat_loc;
int n;
int *pidArr;

void USRhandler(int signum);


void main(int argc,char**argv){
	if(argc>2){
		value=atoi(argv[1]);
		//printf("%d\n",value);
		int flag=1;
		int flag1=0;
		int flag2=0;
		n=argc-2;
		int*arr=malloc(sizeof(int)*n);
		for(int j=0;j<n;j++)
  		arr[j]=atoi(argv[j+2]);
		//printf("%d	%d	%d",arr[0],arr[2],arr[7]);
		pidArr=malloc(sizeof(int)*3);
		for(int z=0;z<children+1;z++)
			pidArr[z]=0;
		signal(SIGUSR1,USRhandler);	  		
			  	  	
		printf("\nI am the parent,PID = %d\n",getpid());
		pidArr[children+1]=getpid();  	  
		
		
			(pidArr[1]=fork())&&(pidArr[0]=fork());
			if (pid== -1)
	  				perror("error in fork");
	  		else if(pidArr[1] == 0) //child 2
			 		{
			 		flag=0;
			 			pidArr[1]=getpid();
			 			printf("\nI am the second child,PID = %d, PPID = %d \n",getpid(),getppid());
			 			for(int k=n/2;k<n;k++)
			 			{
			 				if(arr[k]==value)
			 				{
			 					sleep(1);
			 					kill(getppid(),SIGUSR1);
			 					exit(k);
			 					flag2=1;
			 					}	
			 			}
			 			sleep(3);
			 			printf("\nChild 2 terminates\n");
			 			exit(0);
			 		
			 		}
	  		else if (pidArr[0] == 0) //child 1
			 	{ 
			 	flag=1;
			 	pidArr[0]=getpid();
			 	
	 			printf("\nI am the first child,PID = %d, PPID = %d \n",getpid(),getppid());
			 		for(int k=0;k<n/2;k++)
			 			{
			 				if(arr[k]==value)
			 					{
			 					sleep(1);
			 					kill(getppid(),SIGUSR1);
			 					
			 					exit(k);
			 					flag1=1;
			 					}	
			 			}
			 			sleep(3);
			 			printf("\nChild 1 terminates\n");
			 			exit(0);
			 		}
			 		
			 		else
			 			{
			 			sleep(5);
	pid= wait(&stat_loc);
	if(!(stat_loc & 0x00FF))
	{
			printf("\nA child with pid %d terminated with exit code %d\n", pidArr[0], stat_loc>>8);
		printf("\nA child with pid %d terminated with exit code %d\n", pidArr[1], stat_loc>>8);	
		printf("Value not found\n");
		exit(0);
	}
			 			}
		
		/*if (pidArr[0] == getpid()) //child 1
			 	{ 
			 	
			 		for(int k=0;k<n/2;k++)
			 			{
			 				if(arr[k]==value)
			 					{
			 					kill(getppid(),SIGUSR1);
			 					exit(k);
			 					
			 					}	
			 			}
			 			sleep(3);
			 			printf("\nChild 1 terminates\n");
			 			exit(0);
			 		}
			 		else if(pidArr[1] == getpid()) //child 2
			 		{
			 			
			 			for(int k=n/2;k<n;k++)
			 			{
			 				if(arr[k]==value)
			 				{
			 					kill(getppid(),SIGUSR1);
			 					exit(k);
			 					flag2=1;
			 					}	
			 			}
			 			sleep(3);
			 			printf("\nChild 2 terminates\n");
			 			exit(0);
			 		
			 		}
			*/
	
}
}

void USRhandler(int signum)//the parent as child process send SIGUSR1 to its PID
{
	pid= wait(&stat_loc);
	if(!(stat_loc & 0x00FF))
	{
		if(stat_loc>>8 <n/2)
			printf("child 1: Value found at position %d\n", stat_loc>>8);	
		else
			printf("child 2: Value found at position %d\n", stat_loc>>8);
		for(int i=0;i<=children;i++)
		kill(pidArr[i],SIGKILL);
	}
  	    
	signal(SIGUSR1,USRhandler);
}

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

#define children 2

int value;
int pid;
int n;
int *pidArr,*stat_loc;
int flag1;
void USRhandler(int signum);


void main(int argc,char**argv){
	if(argc>2){
		value=atoi(argv[1]);
		//printf("%d\n",value);
		n=argc-2;
		int*arr=malloc(sizeof(int)*n);
		for(int j=0;j<n;j++)
  		arr[j]=atoi(argv[j+2]);
		//printf("%d	%d	%d",arr[0],arr[2],arr[7]);
		pidArr=malloc(sizeof(int)*3);
		stat_loc=malloc(sizeof(int)*children);
		for(int z=0;z<children+1;z++)
			pidArr[z]=0;
		signal(SIGUSR1,USRhandler);	  		
			  	  	
		printf("\nI am the parent,PID = %d\n",getpid());
		pidArr[children+1]=getpid();  	  
		
		for(int i=0;i<children;i++)
		{
	  		 if (fork() == 0) //children
			 	{ 
			 	
			 	if (i==0) //child 1
			 	{ 
				pidArr[0]=getpid();
	 			printf("\nI am the first child,PID = %d, PPID = %d \n",getpid(),getppid());
			 		for(int k=0;k<n/2;k++)
			 			{
			 				if(arr[k]==value)
			 					{
			 					sleep(0.000000001);
			 					kill(getppid(),SIGUSR1);
			 					
			 					exit(k);
			 					
			 					}	
			 			}
			 			sleep(3);
			 			printf("\nChild 1 terminates\n");
			 			exit(0);
			 		}
			 		
	  		
			  if(i==1){
			 			pidArr[1]=getpid();
			 			
			 			//printf("%d",pidArr[1]);
			 			sleep(0.000000001);
			 			printf("\nI am the second child,PID = %d, PPID = %d \n",getpid(),getppid());
			 			for(int k=n/2;k<n;k++)
			 			{
			 				if(arr[k]==value)
			 				{
			 					sleep(0.001);
			 					kill(getppid(),SIGUSR1);
			 					exit(k);
			 					
			 					}	
			 			}
			 			sleep(3);
			 			printf("\nChild 2 terminates\n");
			 			exit(0);
			 		
			 		}
			 		} 
			 }
			 sleep(5);
			 for(int i=0;i<children;i++)
			 {
			pid= wait(&stat_loc[i]);
			if(!(stat_loc[i] & 0x00FF))
			{
				printf("\nA child with pid %d terminated with exit code %d\n", pid, stat_loc[i]>>8);
				
				if(i==1)
				exit(0);
			}
		}	
			} 
			 
			 		
			 //else 
	  		 
			 		
		
}

void USRhandler(int signum)//the parent as child process send SIGUSR1 to its PID
{
	pid= wait(&flag1);
	if(!(flag1 & 0x00FF))
	{
		if(flag1>>8 <n/2)
			printf("child 1: Value found at position %d\n", flag1>>8);	
		else
			printf("child 2: Value found at position %d\n", flag1>>8);
		for(int i=0;i<=children;i++)
		kill(pidArr[i],SIGKILL);
	}
  	    
	signal(SIGUSR1,USRhandler);
}

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
		n=argc-2;
		int*arr=malloc(sizeof(int)*n);
		for(int j=0;j<n;j++)
  		arr[j]=atoi(argv[j+2]);
		//printf("%d	%d	%d",arr[0],arr[2],arr[7]);
		pidArr=malloc(sizeof(int)*3);
		signal(SIGUSR1,USRhandler);	  		
			  	  	
			  	  
		
		for(int i=0;i<children;i++)
		{
			pid=fork();
			
		
			if (pid== -1)
	  				perror("error in fork");
	  	
	  		else if (pid == 0) //child
			 	{ 
			 	pidArr[i]=getpid();
			 		if(i==0)
			 		{
			 			printf("I am the first child,PID = %d, PPID = %d \n",getpid(),getppid());
			 			for(int k=0;k<n/2;k++)
			 			{
			 				if(arr[k]==value)
			 					{
			 					kill(getppid(),SIGUSR1);
			 					exit(k);
			 					}	
			 			}
			 		}
			 		else
			 		{
			 			printf("I am the second child,PID = %d, PPID = %d \n",getpid(),getppid());
			 			for(int k=n/2;k<n;k++)
			 			{
			 				if(arr[k]==value)
			 				{
			 					kill(getppid(),SIGUSR1);
			 					exit(k);
			 					}	
			 			}
			 		
			 		}
			  	   
			  	} 
			 
			 else 	//parent
			  	{
			  		pidArr[children+1]=getpid();
			  		if(i==0)
			  		printf("I am the parent,PID = %d\n",getpid());
			  		
		}
	
	}

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
		for(int i=0;i<children;i++)
		kill(pidArr[i],SIGKILL);
	}
  	    
	signal(SIGUSR1,USRhandler);
}

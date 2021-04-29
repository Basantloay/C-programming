#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc,char **argv)
{
	int n;
	FILE *fileRead;
	if(argc==4)
	{
		/////READ FILE AND ARGUEMENTS/////
		char *fileName=argv[1];
		char *temp;
		int TANum=atoi(argv[2]);
		int *TA=malloc(n*sizeof(int));
		for(int i=0;i<TANum;i++)
			TA[i]=0;
		double pass=strtod(argv[3],&temp);
		//printf("%i\n",TANum);
		fileRead=fopen(fileName,"r");
		fscanf(fileRead,"%i",&n);
		double *mid=malloc(sizeof(double)*n);
		double *final=malloc(sizeof(double)*n);
		//printf("%d \n",n);
		for(int i=0;i<n;i++)
		{
			fscanf(fileRead,"%lf%lf",&mid[i],&final[i]);
		}
		
		fclose(fileRead);
		//printf("%lf	%lf",mid[5],final[5]);
		
		///////FORKING////////
		
		int *pid=malloc(sizeof(int)*n);
		int*stat_loc=malloc(sizeof(int)*n);
		int quotient=n/TANum;
		for(int j=0;j<n;j++)
		{
				pid[j]=fork();
				if (pid[j] == -1)
	  				perror("error in fork");
	  	
	  			else if (pid[j] == 0)
			 	{ 
			  	   exit(j);
			  	}   
			  else 	
			  	{
			  		
			  	  	pid[j] = wait(&stat_loc[j]);
	  	  			if(mid[j]+final[j]>=pass&&j/quotient<TANum)
	  	  			{
	  	  				TA[j/quotient]++;
	  	  				
	  	  			}
	  	  			else if(mid[j]+final[j]>=pass)
	  	  				TA[TANum-1]++;
				}
				
  		}
  		
  		for(int i=0;i<TANum;i++)
  					printf("%d ",TA[i]);
  		
	}
	return 0;
}
	

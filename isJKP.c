#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isJKP(char *shorter,char *longer)
{
	//char *shorter;
	for(int ii=0;ii<strlen(shorter);ii++)
	{
		shorter[ii]=tolower(shorter[ii]);
	}
	//char *longer;
	for(int ij=0;ij<strlen(longer);ij++)
	{
		longer[ij]=tolower(longer[ij]);
	}

	int count=0;
	int j=0;
	if (strlen(shorter)==strlen(longer))	
	 {
	 	/*for(int i=0;i<strlen(longer);i++)
		{
			if(longer[i]==shorter[j])
			{
				j++;
			}
			}
		if (i==j-1)
		*/
			return 0;
	}
		
	for(int i=0;i<strlen(longer);i++)
	{
		if(longer[i]==shorter[count])
		{
			count++;
		}
	
	}
	if(count==strlen(shorter))
		return 1;
	else 
		return 0;
}

int main(int argc, char **argv) {

	int ans;
	//printf("jjjjj");
	if (argc<3) {	 
		//printf("Too few arguments. Exiting!\n");
		ans=0;
	}
	
	else if(strlen(argv[1])<strlen(argv[2]))
		ans=isJKP(argv[1],argv[2]);
	else
		ans=isJKP(argv[2],argv[1]);
 	
	printf("%d\n",ans);
	return 0; 
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main(int argc, char **argv)
{

	if(argc==2)
	{
		char *wholeString;
		wholeString=argv[1];
		int sum=0;
		int j=0;	//counter of segmentedarray
		int i=0;
		int x=0;
		while(wholeString[i]!='\0')
		{
		
			if(wholeString[i]!='+')
			{
				char ch=wholeString[i];
				x=x*10+ch-'0';
				//printf("%c\n",ch); 
				i++;
			}
			else
			{
				
				sum=sum+x;
				x=0;
				i++;
				
			}
			
		}
		sum=sum+x;
		printf("%d\n",sum);
	}
	//else
		//printf("Invalid output");


	return 0;
}

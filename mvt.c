#include<stdio.h>
void main()
{
	int memory,process,choice;
	printf("Enter the memory size");
	scanf("%d",&memory);
	do{
	printf("Enter the process size");
	scanf("%d",&process);
	if(process<=memory)
	{
	memory = memory - process;
	printf("process is allocated remaining memory = %d\n",memory);
	
	}else
	printf("Process is not allocated due to insufficient memory");
	printf("Do you want to continue?(0 for yes | 1for no )\n");
	scanf("%d",&choice);
	}while(choice!=1);

}


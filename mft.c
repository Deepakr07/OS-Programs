#include<stdio.h>
#include<string.h>
struct process
{
	int size;
	char a[2];
	int internalfrag;

};
struct block
{
	int size;
	
};

void main()
{
	int memory,blocksize,bcount = 0,n,i,j;
	printf("Enter the total memory available\n");
	scanf("%d",&memory); 
	printf("Enter the block size \n");
	scanf("%d",&blocksize);
	bcount = memory/blocksize;
	int externalfrag=0;
	externalfrag = memory%blocksize;
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	struct block b1[bcount];
	struct process p1[n];
	for(i = 0; i<bcount ; i++)
	{
	b1[i].size = blocksize;
	}
	printf("Enter the size of %d processes\n",n);
	for(i = 0; i<n ; i++)
	{
	scanf("%d",&p1[i].size);
	}
	for(i = 0; i<n ; i++)
	{
	p1[i].internalfrag = 0;
	strcpy(p1[i].a,"NO");
	}
	for(i = 0,j = 0;i<n,j<bcount;j++)
	{
	if(p1[i].size <= b1[j].size)
	{
	strcpy(p1[i].a,"Yes");
	p1[i].internalfrag = b1[j].size - p1[i].size;
	b1[j].size = b1[j].size-p1[i].size;
	i++;
	}
	else continue;
	}
	printf("PROCESS\t\t\t\tSIZE\t\t\t\tALLOCATED?\t\t\t\tINTERNAL_FRAG\n\n");
	for( i = 0 ;i<n ; i++)
	{
	printf("%d\t\t\t\t%d\t\t\t\t%s\t\t\t\t%d\n",i+1,p1[i].size,p1[i].a,p1[i].internalfrag);
	
	}
	

}

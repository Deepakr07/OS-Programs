#include<stdio.h>
void main()
{
	int bt[10],finish[10],start[10],n,at[10],tat[10],wt[10],totaltat =0,totalwt = 0;
	int temp1,temp2;
	char temp3, p[100];
	printf("Enter the process number \n");
	scanf("%d",&n);
	for(int i = 0 ; i<n ; i++)
	{
	printf("enter the process name process arrival time and burst time\n");
	scanf("%s%d%d",&p[i],&at[i],&bt[i]);
	}
	
	for(int i = 0 ; i<n;i++)
	{
	for(int j = 0 ;j <n ; j++)
	{
	if(at[j]>at[j+1])
	{
	
	temp1 = at[j];
	temp2 = bt[j];
	temp3 = p[j];
	at[j] = at[j+1];
	bt[j] = bt[j+1];
	p[j]  = p[j+1];
	at[j+1] = temp1;
	bt[j+1] = temp2;
	p[j+1] = temp3;
	}
	}
	}
	for(int i = 0; i<n; i++)
	{
	if(i ==0)
	{
	start[i] = at[i];
	finish[i] = start[i]+bt[i];
	tat[i] = finish[i] - at[i];
	wt[i] = start[i] - at[i];
	}
	
	else{
	
	start[i] = finish[i-1];
	finish[i] = start[i]+bt[i];
	tat[i] = finish[i] - at[i];
	wt[i] = start[i]-at[i];
	}
	
	}

	for(int i = 0; i<n; i++)
	{
	totaltat = tat[i]+totaltat;
	totalwt = wt[i]+totalwt;
	}

	printf("Total turn around time = %f\n",totaltat/n);
	printf("Total waiting time = %f\n",totalwt/n);




}


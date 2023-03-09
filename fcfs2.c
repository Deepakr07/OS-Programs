
#include<stdio.h> 
int main() 
{
char pn[100],temp1;
int arr[100],temp2,temp3,j,bur[100],star[100],finish[100],tat[100],wt[100],i,n; 
int totwt=0,tottat=0; 
printf("Enter the number of processes:");
scanf("%d",&n); 
for(i=0;i<n;i++) 
{ 
printf("Enter the Process Name, Arrival Time, Burst time \n");
	
scanf("%s%d%d",&pn[i],&arr[i],&bur[i]);
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++){
if(arr[j]>arr[j+1])
 { 
        temp1=pn[j];
	temp2=arr[j];
	temp3=bur[j];
	pn[j]=pn[j+1];
	bur[j]=bur[j+1];
	arr[j]=arr[j+1];
	pn[j+1]=temp1;
	bur[j+1]=temp3;
	arr[j+1]=temp2;
    		        }}}
for(i=0;i<n;i++) 
{ 
	if(i==0) 
	{ 
	star[i]=arr[i];
	wt[i]=star[i]-arr[i]; 
	finish[i]=star[i]+bur[i]; 
	tat[i]=finish[i]-arr[i];
 	} 
	else 
	{
	star[i]=finish[i-1]; 
	wt[i]=star[i]-arr[i]; 
	finish[i]=star[i]+bur[i];
	tat[i]=finish[i]-arr[i];
	}
}
printf("\n ProcessName\tArrivalTime\tBurstTime\tStartTime\tFinish\tTAT \n");
for(i=0;i<n;i++)
{
totwt+=wt[i];
tottat+=tat[i];
printf("\n%c\t\t%d\t\t%d\t\t%d\t%d\t%d ",pn[i],arr[i],bur[i],star[i],finish[i],tat[i]);  
}
printf("\n Avreage Turn around Time : %f",(float)tottat/n);
printf("\n Avreage Waiting Time     : %f",(float)totwt/n);
return 0;
}

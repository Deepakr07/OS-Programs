#include<stdio.h>
#include<unistd.h>
#include<sys/types.h> 
void main()
{
int x = fork();
if(x == 0)
{printf("child process\n");
printf("The process id is %d",getpid());}
else if(x>0)
{
printf("Parent process\n");
printf("The process id is %d",getpid());
}



}

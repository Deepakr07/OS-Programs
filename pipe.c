#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void main()
{
	char message1[20] = {"hello"};
	char message2[20] = {"helloworld"},readmessage[20];
	int returnvalue,pid = 0;
	int pipefds[2];
	returnvalue = pipe(pipefds);
	if(returnvalue == -1)
	printf("Unable to create pipe");
	else
	{
	int pid;
	pid = fork();
	if(pid == 0)
	{
		close(pipefds[1]);
		read(pipefds[0],readmessage,sizeof(readmessage));
		printf("Child process reading message1 from pipe message 1 - %s\n",readmessage);
		read(pipefds[0],readmessage,sizeof(readmessage));
		printf("Child process reading message2 from pipe message 2 - %s\n",readmessage);
	}
	else
	{
	close(pipefds[0]);
	write(pipefds[1],message1,sizeof(message1));
	printf("Parent process written message1 to pipe \n");
	write(pipefds[1],message2,sizeof(message2));
	printf("Parent process written message2 to pipe \n");
	
	}
	
	
	}

}

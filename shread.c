#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>
void main()
{
	void *sharedmemory;
	int shmid;
	char read[20];
	char buffer[200];
	shmid = shmget((key_t)2345,1024,0666|IPC_CREAT);
	sharedmemory = shmat(shmid,NULL,0);
	printf("Process attached at %p\n",sharedmemory);
	printf("Enter the data to be written on to the shared memory ");
	gets(buffer);
	strcpy(sharedmemory,buffer);
	printf("\nData written to the shared memory %s\n",(char*)sharedmemory);


}

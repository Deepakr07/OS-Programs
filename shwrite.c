#include<stdio.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
void main()
{
	void *sharedmemory;
	int shmid;
	//creating shared memory
	shmid = shmget((key_t)2345,1024,0666|IPC_CREAT);//shared memory is created
	sharedmemory = shmat(shmid,NULL,0);//process is attached to shared memory
	char buffer[200];
	strcpy(buffer,sharedmemory);
	printf("Data read from shared memory = %s\n",buffer);
	
}

#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct messageq
{
	long type;
	char message[100]; 
}m1;

void main()

{
	key_t key;
	int msgid;
	key = ftok("progfile",65);
	msgid = msgget(key,0666|IPC_CREAT);
	msgrcv(msgid,&m1,sizeof(m1),1,0);
	printf("Message read is %s\n",m1.message);

}

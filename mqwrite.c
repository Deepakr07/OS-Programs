#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>
struct messagebuffer
{
long mesg_type;
char message[100];
}mes;

void main()
{
	char buffer[20];
	key_t key;
	int msgid;
	key = ftok("progfile",65);
	msgid = msgget(key,0666|IPC_CREAT);
	mes.mesg_type = 1;
	printf("Write the data\n");
	gets(buffer);
	strcpy(mes.message,buffer);
	//fgets((mes.message),10,stdin);
	msgsnd(msgid,&mes,sizeof(mes),0);
	printf("Data send is %s\n",mes.message);
}                                                                       
                           

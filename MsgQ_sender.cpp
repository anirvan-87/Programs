#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

using namespace std;

struct msg_buf{
	long msg_type;
	char msg[100];
}message;

int main()
{
	key_t key;
	int msg_id;
	
	//ftok to generate unique key
	key=ftok("prog",65);

	//msgget creates message queue and
	//returns identifier
	msg_id=msgget(key,0666|IPC_CREAT);
	message.msg_type=1;

	cout<<"\n Write data: \n";
	gets(message.msg);

	//msgsnd to send message
	msgsnd(msg_id, &message, sizeof(message), 0);

	//Display the message
	cout<<"\n Data sent is \n"<<message.msg<<endl;

	return 0;
}

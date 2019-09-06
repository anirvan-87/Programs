#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

using namespace std;

struct msg_buf{
	long mesg_type;
	char msg[100];
}message;

int main()
{
	key_t key;
	int msg_id;

	//ftok to generate unique key
	key=ftok("prog",65);

	//msgget creates a message queue
	//and returns an identifier.
	msg_id=msgget(key, 0666 | IPC_CREAT);
	message.mesg_type=1;

	cout<<"\n Read data : \n";
	
	//msgrcv to receive the data
	msgrcv(msg_id, &message, sizeof(message), 1, 0);
	puts(message.msg);

	// to destroy the message queue 
	msgctl(msg_id, IPC_RMID, NULL); 
	return 0; 
} 


#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct msgbuff
{
    long mtype;
    char mtext[256];
    
};
void reverse(char* msg,char* reversed)
{
	int i=0;
	for(i=0;i<strlen(msg);i++)
	{
		
		reversed[i]=msg[strlen(msg)-i-1];
	}
}

void Ehandler(int signum);

key_t key_id_up,key_id_down;
int msgq_id_up,msgq_id_down, send_val_down,rec_val_up;
    
int main()
{
	signal(SIGINT,Ehandler);	
    
    
    key_id_up = ftok("keyfile", 65);
    key_id_down = ftok("keyfile", 67);
    
    
    msgq_id_up = msgget(key_id_up, 0666 | IPC_CREAT);
    msgq_id_down = msgget(key_id_down, 0666 | IPC_CREAT);

    if (msgq_id_up == -1 || msgq_id_down==-1)
    {
        perror("Error in create");
        exit(-1);
    }
    //printf("Message Queue ID UP = %d\n %d \n", msgq_id_up,key_id_up);
    //printf("Message Queue ID down = %d\n %d\n", msgq_id_down,key_id_down);
    char revers[256];
    struct msgbuff messageUp,messageDown;
while(1)
{
   
	rec_val_up = msgrcv(msgq_id_up, &messageUp, sizeof(messageUp.mtext), 0, !IPC_NOWAIT);
	if (rec_val_up == -1)
            perror("Error in receive");
        else
            {
            	messageDown.mtype = 7; 
            	
            	
            	//printf("\n message:%s \n",messageDown.mtext);
            	for(int i=0;i<sizeof(messageDown.mtext);i++)
            		revers[i]='\0';
            	reverse(messageUp.mtext,revers);
            	//printf("\n message:%s \n",(messageUp.mtext));
            	strcpy(messageDown.mtext, revers);
            	//printf("\n message after reverse:%s \n",messageDown.mtext);
            	send_val_down = msgsnd(msgq_id_down, &messageDown, sizeof(messageDown.mtext), !IPC_NOWAIT);
				

   			 	if (send_val_down == -1)
        			perror("Errror in send");
            }
  }          
    
    
   

	//msgctl(msgq_id_up,IPC_RMID,(struct msqid_ds *)0);
	//msgctl(msgq_id_down,IPC_RMID,(struct msqid_ds *)0);
    return 0;
}


void Ehandler(int signum)
{
	
  	msgctl(msgq_id_up,IPC_RMID,(struct msqid_ds *)0);
	msgctl(msgq_id_down,IPC_RMID,(struct msqid_ds *)0);
	exit(0);
	signal(SIGINT,Ehandler);	
}

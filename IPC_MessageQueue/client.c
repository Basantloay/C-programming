#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

struct msgbuff
{
    long mtype;
    char mtext[256];
    int count;
};

int main()
{
    key_t key_id_up,key_id_down;
    int msgq_id_up,msgq_id_down, send_val_up,rec_val_down;
    
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
    while(1){
    char input[256];
    printf("Enter The Message :");
    gets(input);
    //printf("m:%s",input);
    struct msgbuff messageUp,messageDown;

    messageUp.mtype = 7; // arbitrary value 
    strcpy(messageUp.mtext, input);

    send_val_up = msgsnd(msgq_id_up, &messageUp, sizeof(messageUp.mtext), !IPC_NOWAIT);
	//printf("m:%s",messageUp.mtext);
    if (send_val_up == -1)
        perror("Errror in send");
   /* receive all types of messages */
   rec_val_down = msgrcv(msgq_id_down, &messageDown, sizeof(messageDown.mtext), 0, !IPC_NOWAIT);

        if (rec_val_down == -1)
            perror("Error in receive");
        else
            printf("\nMessage received:%s\n", messageDown.mtext);
   }
	//msgctl(msgq_id_up,IPC_RMID,(struct msqid_ds *)0);
	//msgctl(msgq_id_down,IPC_RMID,(struct msqid_ds *)0);
    return 0;
}

/*
 * Messagerie.cpp
 *
 *  Created on: Feb 1, 2019
 *      Author: nicolas
 */

#include "Messagerie.h"
#include "stdio.h"
//#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
//#include <mqueue.h>
#include <errno.h>
#include <string.h>


#include <sys/ipc.h>
#include <sys/msg.h>

//https://stackoverflow.com/questions/55437521/send-and-receive-a-struct-in-posix-message-queue
//https://fabrice-boissier.developpez.com/articles/introduction-posix-mq/
//http://perso.ens-lyon.fr/daniel.hirschkoff/C_Caml/docs/doc_gdb.pdf

# define MQ_NAME "/queuetest"
# define BUF_LEN 512




Messager::Messager(char* nom, int taille)
{
    ssize_t 		len_recv;
    //mqd_t 		My_MQ;
     // ftok to generate unique key
    key = ftok(nom, taille);
    // msgget creates a message queue
    // and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);
    snprintf(nomqueue,sizeof(nomqueue),"%s",nom);
    printf("Creation messagerie ->%s<-, key : %d  msgid : %d\r\n",nomqueue,key,msgid);
    AMessage  txMessage;
    txMessage.priorie = 12;

}

Messager::~Messager()
{
}

int Messager::envoieMessage(AMessage * txMessage)
{
    //laqueue__ = xQueueCreate(1, sizeof( AMessage )); //creation d'une queue contenant 10 messages
    printf(">   envoieMessage : debut \r\n");
    ssize_t 		len_recv;
    //  mqd_t 		My_MQ;
    char 			recv[BUF_LEN];
    // msgsnd to send message
    mesg_buffer message;

    message.mesg_type = 1;
    snprintf(message.mesg_text,sizeof(message.mesg_text),"mess %s",txMessage->message);
    msgsnd(msgid, &message, sizeof(message), 0);
    timespec taillemahout;
    taillemahout.tv_sec = 4;
    printf("    %s   envoieMessage (id %d): %s\r\n",nomqueue,msgid,txMessage->message);
    //mq_timedsend(laqueue__, txMessage->message, strlen(txMessage->message), txMessage->priorie,&taillemahout);
    //free(text);
#if 0
    text = strdup("tournicoton 21 !");
    mq_send(laqueue__, text, strlen(text), 21);
    free(text);
#endif
    return 1;
}

int Messager::recoitMessage()
{
    printf("recoitMessage (id : %d) %s\n\r ",msgid,nomqueue);
    char recoitt[200];
    ssize_t 		len_recv;
    char 			*text;
    char 			recv[BUF_LEN];
    memset(recv, 0, BUF_LEN);
    // len_recv = mq_receive(laqueue__, recv, BUF_LEN, NULL);
    // msgrcv to receive message
    printf("    attend message  id:%x\n\r ",msgid);
     mesg_buffer message;
    msgrcv(msgid, &message, sizeof(message), 1, 0);
    // if( EAGAIN ==len_recv )printf("   mq vide %d",len_recv);
    printf("    recu message :%s\n\r ",message.mesg_text);
    AMessage messagea ;

    snprintf(messagea.message,sizeof(messagea.message),"%s",message.mesg_text);
    vecteurMessages.push_back(messagea);
    //   printf("Premier msg recu (len : %u) : %s\n", (unsigned int) len_recv, recv);
    //  memset(recv, 0, BUF_LEN);
    //  len_recv = mq_receive(laqueue__, recv, BUF_LEN, NULL);
    //  printf("Deuxieme msg recu (len : %u) : %s\n", (unsigned int) len_recv, recv);
    // printf(" %s  recoit :%s, taille %d\n\r ",nomqueue,message.consigne,vecteurMessages.size());
    return 1;
}
int Messager::effaceQueue()
{
    //xQueueReset(laqueue__);
    //	vQueueDelete(laqueue__);
    //delete laqueue__;
}
int Messager::creeQueue()
{
}

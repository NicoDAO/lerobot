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
    char 			*text;
    char 			recv[BUF_LEN];


  // ftok to generate unique key
    key = ftok("progfile", 65);
   // msgget creates a message queue
    // and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);



     snprintf(nomqueue,sizeof(nomqueue),"%s",nom);
    printf("Creation messagerie ->%s<-\r\n",nomqueue);

    AMessage  txMessage;
    txMessage.priorie = 12;
    //  snprintf(txMessage.message,sizeof(txMessage.consigne  ),"bonjour la queue");
    //  envoieMessage( &txMessage);
    //  txMessage.priorie = 13;
    snprintf(txMessage.message,sizeof(txMessage.consigne  ),"supergenial");
    //   envoieMessage( &txMessage);


}

Messager::~Messager()
{
}

int Messager::envoieMessage(AMessage * txMessage)
{
    //laqueue__ = xQueueCreate(1, sizeof( AMessage )); //creation d'une queue contenant 10 messages
    // printf(">   envoieMessage \r\n");
     ssize_t 		len_recv;
    //  mqd_t 		My_MQ;
    char 			*text;
    char 			recv[BUF_LEN];
    text = strdup("tournicoti : 42 !");



    // msgsnd to send message
    msgsnd(msgid, txMessage->message, sizeof(txMessage->message), 0);



     timespec taillemahout;
    taillemahout.tv_sec = 4;
    printf("    %s   envoieMessage : %s\r\n",nomqueue,txMessage->message);
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

    //printf("recoitMessage de %s\n\r ",nomqueue);
    char recoitt[200];
    ssize_t 		len_recv;
    char 			*text;
    char 			recv[BUF_LEN];
    memset(recv, 0, BUF_LEN);
    // len_recv = mq_receive(laqueue__, recv, BUF_LEN, NULL);
      // msgrcv to receive message
    msgrcv(msgid, &recv, sizeof(recv), 1, 0);

       // if( EAGAIN ==len_recv )printf("   mq vide %d",len_recv);
        printf("    recu message :%s\n\r ",recv);
        AMessage message ;
        snprintf(message.consigne,sizeof(message.consigne),"%s",recv);
        vecteurMessages.push_back(message);

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

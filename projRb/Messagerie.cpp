/*
 * Messagerie.cpp
 *
 *  Created on: Feb 1, 2019
 *      Author: nicolas
 */

#include "Messagerie.h"
#include "stdio.h"
#include "config_du_system.h"
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
    snprintf(nomqueue,sizeof(nomqueue),"%s",nom);
    msgid = msgget(key, 0666 | IPC_CREAT);
    //log_message(nomqueue,sizeof(nomqueue),"%s",nom);
    log_message("Creation messagerie ->%s<-, key : %d  msgid : %d\r\n",nomqueue,key,msgid);
}

Messager::~Messager()
{
}

int Messager::envoieMessage(AMessage * txMessage)
{
    //laqueue__ = xQueueCreate(1, sizeof( AMessage )); //creation d'une queue contenant 10 messages
   // log_message(">   envoieMessage : debut \r\n");
  //  ssize_t 		len_recv;
    //  mqd_t 		My_MQ;
 //   char 			recv[BUF_LEN];
    // msgsnd to send message
//   mesg_buffer message;
//    message.mesg_type = 1;
//    log_info(txMessage->mesg_text,sizeof(message.mesg_text),"mess %s",txMessage->message);
    txMessage->mesg_type = 1;
    msgsnd(msgid, txMessage, BUF_LEN /*sizeof(txMessage)*/, 0);
    timespec taillemahout;
    taillemahout.tv_sec = 4;
    log_message("%s envoieMessage : fin (id %d): %s\r\n",nomqueue,msgid,txMessage->message);
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
  //  log_info("recoitMessage (id : %d) %s\n\r ",msgid,nomqueue);
   // log_message("recoitMessage (id : %d) %s\n\r ",msgid,nomqueue);
    char recoitt[200];
    ssize_t 		len_recv;
    char 			*text;
    char 			recv[BUF_LEN];
    memset(recv, 0, BUF_LEN);
    log_message("    attend message  id:%x\n\r ",msgid);
    AMessage messagea ;
    msgrcv(msgid, &messagea, BUF_LEN /*sizeof(messagea)*/, 1, 0);
    log_message("%s    recu message :%s\n\r ",nomqueue,messagea.message );
    vecteurMessages.push_back(messagea);
    return 1;
}
int Messager::effaceQueue()
{
    //xQueueReset(laqueue__);
    //	vQueueDelete(laqueue__);
    //delete laqueue__;
    vecteurMessages.clear();
}
int Messager::creeQueue()
{
}

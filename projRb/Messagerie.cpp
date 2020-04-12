/*
 * Messagerie.cpp
 *
 *  Created on: Feb 1, 2019
 *      Author: nicolas
 */

#include "Messagerie.h"
#include "stdio.h"
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <errno.h>
#include <string.h>
//https://stackoverflow.com/questions/55437521/send-and-receive-a-struct-in-posix-message-queue
//https://fabrice-boissier.developpez.com/articles/introduction-posix-mq/
//http://perso.ens-lyon.fr/daniel.hirschkoff/C_Caml/docs/doc_gdb.pdf
struct mq_attr	attr;
# define MQ_NAME "/queuetest"
# define BUF_LEN 512

Messager::Messager(char* nom, int taille)
{
    struct mq_attr	attr;
    ssize_t 		len_recv;
    mqd_t 		My_MQ;
    char 			*text;
    char 			recv[BUF_LEN];
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = BUF_LEN;
    attr.mq_curmsgs = 0;
    laqueue__ = mq_open(MQ_NAME, O_RDWR | O_CREAT, 0644, &attr);
    if ((int) My_MQ == -1)
    {
        perror("Error : mq_open failed !\n");
        exit(   1);
    }
    AMessage  txMessage;
    txMessage.priorie = 12;
    snprintf(txMessage.message,sizeof(txMessage.consigne  ),"bonjour la queue");
    envoieMessage( &txMessage);
    txMessage.priorie = 13;
    snprintf(txMessage.message,sizeof(txMessage.consigne  ),"super");
    envoieMessage( &txMessage);
#if 0
    printf("%s\n", "tournicoton priorite 42");
    text = strdup("tournicoti : 42 !");
    mq_send(laqueue__, text, strlen(text), 42);
    free(text);
    printf("%s\n", "tournicoti priorite 21");
    text = strdup("tournicoton 21 !");
    mq_send(laqueue__, text, strlen(text), 21);
    free(text);
#endif
#if 0
    memset(recv, 0, BUF_LEN);
    len_recv = mq_receive(My_MQ, recv, BUF_LEN, NULL);
    printf("Premier msg recu (len : %u) : %s\n", (unsigned int) len_recv, recv);
    memset(recv, 0, BUF_LEN);
    len_recv = mq_receive(My_MQ, recv, BUF_LEN, NULL);
    printf("Deuxieme msg recu (len : %u) : %s\n", (unsigned int) len_recv, recv);
#endif
    //mq_close(My_MQ);
// mq_unlink(MQ_NAME);
//    attr.mq_flags = 0;
//    attr.mq_maxmsg = 1      ;
//    attr.mq_msgsize = BUF_LEN;
//    attr.mq_curmsgs = 0;
//    memcpy(nomqueue,nom,sizeof(nomqueue));
//
//    laqueue__ = mq_open((const char *)nom, O_CREAT | O_RDWR, 0644, &attr); //creation d'une queue contenant 10 messages
//    printf("cree la queue %s\r\n",nom);
//    if(laqueue__!= -1)
//    {
//        perror("erreur creation queue");
//        exit(1);
//    }
//    char mess[30];
//    snprintf(mess, sizeof(mess),"coucou");
//    mq_send(laqueue__, mess, strlen(mess),21);
//    printf("   envoie message%s\r\n",mess);
//
//    char recoitt[200];
//     if (mq_receive(laqueue__,  recoitt, BUF_LEN, NULL) == -1)
//    {
//        perror("process request: mq_receive =");
//        exit(1);
//    }
//     printf("   mq_receive  %s\n\r ",recoitt);
}

Messager::~Messager()
{
}
mqd_t * Messager::testQueue()
{
    //QueueHandle_t * Messager::testQueue() {
    return &laqueue__;
}

int Messager::envoieMessage(AMessage * txMessage)
{
    //laqueue__ = xQueueCreate(1, sizeof( AMessage )); //creation d'une queue contenant 10 messages
    printf(">   envoieMessage \r\n");
    if (laqueue__ == 0)
        return -1;
    printf("envoieMessage\r\n");
    struct mq_attr	attr;
    ssize_t 		len_recv;
    mqd_t 		My_MQ;
    char 			*text;
    char 			recv[BUF_LEN];
    text = strdup("tournicoti : 42 !");
    mq_send(laqueue__, txMessage->message, strlen(txMessage->message), txMessage->priorie);
    free(text);
#if 0
    text = strdup("tournicoton 21 !");
    mq_send(laqueue__, text, strlen(text), 21);
    free(text);
#endif
    return 1;
}

int Messager::recoitMessage()
{
    if (laqueue__ == 0)
        return -1;
    printf("hh mq_receive %s\n\r ",nomqueue);
    char recoitt[200];
    ssize_t 		len_recv;
    char 			*text;
    char 			recv[BUF_LEN];
    memset(recv, 0, BUF_LEN);
    len_recv = mq_receive(laqueue__, recv, BUF_LEN, NULL);
    printf("Premier msg recu (len : %u) : %s\n", (unsigned int) len_recv, recv);
    memset(recv, 0, BUF_LEN);
    len_recv = mq_receive(laqueue__, recv, BUF_LEN, NULL);
    printf("Deuxieme msg recu (len : %u) : %s\n", (unsigned int) len_recv, recv);
    printf("   recoit  %s\n\r ",recoitt);
    return -2;
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

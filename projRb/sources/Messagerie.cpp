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

Messager::Messager(char *nom, int taille) {
	ssize_t len_recv;
	//mqd_t 		My_MQ;
	// ftok to generate unique key
	char cle[50];
	snprintf(cle,sizeof(cle),"/tmp%s",nom);//on crée la clé systemV dans le repertoitr /tmp"
	key = ftok(".",(char) taille);
	// msgget creates a message queue
	// and returns identifier
	snprintf(nomqueue, sizeof(nomqueue), "%s", nom);
	msgid = msgget(key, 0666 | IPC_CREAT);
	//log_message(nomqueue,sizeof(nomqueue),"%s",nom);
	calog.log_message("Creation messagerie nom : %s, key : %d  msgid : %d\r\n",
		       cle, key, msgid);
} 

Messager::~Messager() {
}

int Messager::envoieMessage(AMessage *txMessage) {
	txMessage->mesg_type = 1;
	if(-1 == msgsnd(msgid, txMessage, BUF_LEN /*sizeof(txMessage)*/, 0)){
            calog.log_error("probleme envoie message");
	  }
	timespec taillemahout;
	taillemahout.tv_sec = 4;
	calog.log_message("%s envoieMessage : fin (id %d): %s\r\n", nomqueue, msgid,
			txMessage->message);

	return 1;
}

int Messager::recoitMessage() {
	//  log_info("recoitMessage (id : %d) %s\n\r ",msgid,nomqueue);
	// log_message("recoitMessage (id : %d) %s\n\r ",msgid,nomqueue);
	char recoitt[200];
	ssize_t len_recv;
	char *text;
	char recv[BUF_LEN];
	memset(recv, 0, BUF_LEN);
	calog.log_message("    attend message  id:%x\n\r ", msgid);
	AMessage messagea;
	/*
        https://www.systutorials.com/docs/linux/man/2-msgrcv/
        IPC_NOWAIT
        Return immediately if no message of the requested type is in the queue. The system call fails with errno set to ENOMSG. */
	
 	if(-1 == msgrcv(msgid, &messagea, BUF_LEN /*sizeof(messagea)*/, 1,/* 0*/IPC_NOWAIT)){
	    if(errno != ENOMSG){
	      calog.log_error("problème réception message");
			       }
	    return -1;
	  }
	  
	calog.log_message("%s    recu message :%s\n\r ", nomqueue, messagea.message);
	vecteurMessages.push_back(messagea);
	return 1;
}
int Messager::effaceQueue() {
	vecteurMessages.clear();
	return 1;
}
int Messager::creeQueue() {
	return 0;
}



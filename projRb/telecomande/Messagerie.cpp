/*
 * Messagerie.cpp
 *
 *  Created on: Feb 1, 2019
 *      Author: nicolas
 */

#include "Messagerie.h"
#include "stdio.h"
#include "config_du_system.h"
#include <sys/stat.h>        /* For mode constants */
#include <errno.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

# define MQ_NAME "/queuetest"
# define BUF_LEN 512

Messager::Messager(char *nom, int taille) {
} 

Messager::~Messager() {
}
void Messager::setID(int id){
  	msgid = id;
}

int Messager::envoieMessage(AMessage *txMessage) {
	txMessage->mesg_type = 1;
	if(-1 == msgsnd(msgid, txMessage, BUF_LEN /*sizeof(txMessage)*/, 0)){
            calog.log_error("Pprobleme envoie message");
	  }
	timespec taillemahout;
	taillemahout.tv_sec = 4;
	calog.log_message("%s envoieMessage : fin (id %d): %s\r\n", nomqueue, msgid,
			txMessage->message);

	return 1;
}

int Messager::recoitMessage() {
	char recoitt[200];
	ssize_t len_recv;
	char *text;
	char recv[BUF_LEN];
	memset(recv, 0, BUF_LEN);
	calog.log_message("    attend message  id:%x\n\r ", msgid);
	AMessage messagea;
	
 	if(-1 == msgrcv(msgid, &messagea, BUF_LEN /*sizeof(messagea)*/, 1,/* 0*/IPC_NOWAIT)){
	    if(errno != ENOMSG){
	      calog.log_error("problème réception message");
			       }
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



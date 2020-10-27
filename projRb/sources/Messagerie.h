/*
 * Messagerie.h
 *
 *  Created on: Feb 1, 2019
 *      Author: nicolas
 */

#ifndef SRC_MESSAGE_H_
#define SRC_MESSAGE_H_
#include <iostream>
#include <vector>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "log.h"
#define MAX_CACHE_REQUEST_LEN 1000

struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} ;
struct AMessage
{
    long mesg_type;
     char message[100];
} ;
class Messager
{
public:
    Messager(char*,int);
    ~Messager(void);
    AMessage meee;
    int envoieMessage(AMessage *);
    int recoitMessage(void);
    std::vector<AMessage> vecteurMessages;
    int effaceQueue(void);
    int creeQueue(void);
    int getMsgId(void){return msgid;}
private:
    key_t key;
    int msgid;
    char nomqueue[100];
    GestionLog calog;
};

#endif /* SRC_MESSAGE_H_ */

/*
 * GereLed.h
 *
 *  Created on: Feb 1, 2019
 *      Author: nicolas
 */

#ifndef SRC_MESSAGE_H_
#define SRC_MESSAGE_H_
//#include <sys/queue.h>
//#include <mqueue.h>
//#include "queue.h"
#include <iostream>
#include <vector>


#include <sys/ipc.h>
#include <sys/msg.h>


#define MAX_CACHE_REQUEST_LEN 1000
/*
class AMessage {
public:
	char ucMessageID;
	char consigne[20];

	int puissance_moteur = 0;
	int sens_moteur = 0;
	int distanceCapteur = 0;

};*/

/*typedef*/ struct AMessage {

	char ucMessageID;
	char consigne[20];

	int puissance_moteur = 0;
	int sens_moteur = 0;
	int distanceCapteur = 0;
	char message[100];
	int priorie=10;

} ;
class Messager {
public:
	Messager(char*,int);
	~Messager(void);
	AMessage meee;
	//QueueHandle  * testQueue(void);
	//mqd_t* testQueue(void);
	int envoieMessage(AMessage *);
	int recoitMessage(void);
	std::vector<AMessage> vecteurMessages;
	int effaceQueue(void);
	int creeQueue(void);
private:
	//QueueHandle_t laqueue__;
	//mqd_t laqueue__;
	 key_t key;
    int msgid;
	char nomqueue[100];

};

#endif /* SRC_MESSAGE_H_ */

/*
 * Messagerie.cpp
 *
 *  Created on: Feb 1, 2019
 *      Author: nicolas
 */

#include "Messagerie.h"
#include "stdio.h"
//https://stackoverflow.com/questions/55437521/send-and-receive-a-struct-in-posix-message-queue
Messager::Messager() {
	creeQueue();
}

Messager::~Messager() {

}
mqd_t * Messager::testQueue() {
//QueueHandle_t * Messager::testQueue() {
	return &laqueue__;
}

int Messager::envoieMessage(AMessage * txMessage) {
	//laqueue__ = xQueueCreate(1, sizeof( AMessage )); //creation d'une queue contenant 10 messages


	if (laqueue__ == 0)
		return -1;
	mq_send(laqueue__,(const char *) &meee, sizeof( AMessage ), 0);
//	xQueueSend(laqueue__, txMessage, (TickType_t ) 0);
	return 1;
}

int Messager::recoitMessage() {
	if (laqueue__ == 0)
		return -1;
	AMessage rxMessage;

    if (mq_receive(laqueue__, (char *) &meee, MAX_CACHE_REQUEST_LEN, NULL) == -1)
    {
        perror("process request: mq_receive");
        exit(1);
    }
	return -2;
}
int Messager::effaceQueue(){
	//xQueueReset(laqueue__);
//	vQueueDelete(laqueue__);
	//delete laqueue__;
}
int Messager::creeQueue(){

	laqueue__ = mq_open((const char *)"eee", O_RDWR); //creation d'une queue contenant 10 messages

}

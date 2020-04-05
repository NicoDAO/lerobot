/*
 * Messagerie.cpp
 *
 *  Created on: Feb 1, 2019
 *      Author: nicolas
 */

#include "Messagerie.h"
#include "stdio.h"

Messager::Messager() {
	creeQueue();
}

Messager::~Messager() {

}

QueueHandle_t * Messager::testQueue() {
	return &laqueue__;
}

int Messager::envoieMessage(AMessage * txMessage) {
	//laqueue__ = xQueueCreate(1, sizeof( AMessage )); //creation d'une queue contenant 10 messages

	if (laqueue__ == 0)
		return -1;
	xQueueSend(laqueue__, txMessage, (TickType_t ) 0);
	return 1;
}

int Messager::recoitMessage() {
	if (laqueue__ == 0)
		return -1;
	AMessage rxMessage;

	if (xQueueReceive(laqueue__, &(rxMessage), (TickType_t) 0) == pdTRUE) {
		vecteurMessages.push_back(rxMessage);//si on a recu un nouveau message on l'ajoute dans la liste
		return 1;
	}
	return -2;
}
int Messager::effaceQueue(){
	//xQueueReset(laqueue__);
//	vQueueDelete(laqueue__);
	//delete laqueue__;
}
int Messager::creeQueue(){

	laqueue__ = xQueueCreate(1, sizeof( AMessage )); //creation d'une queue contenant 10 messages

}

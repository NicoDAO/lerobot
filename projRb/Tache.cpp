/*
 * Tache.cpp
 *
 *  Created on: 26 août 2018
 *      Author: nicolas
 */

#include "Tache.h"

Tache::Tache() {
	// TODO Auto-generated constructor stub

}

Tache::~Tache() {
	// TODO Auto-generated destructor stub
}
void Tache::calc_handler(void)
{
	// xLastWakeTime = xTaskGetTickCount();

}

void Tache::setPeriod( uint16_t wpt)
{
	this->xWakePeriod = wpt;
}

void Tache::SetGereLed(GereLed* cf){
	//this->GestionLed = cf;
}

void Tache::lapause(u32 lp){

	//vTaskDelayUntil(&xLastWakeTime, xWakePeriod);
	cpt_tache++;
	usleep(lp);

}
void Tache::SetMessage1(Messager* lm){
	this->leMessage1 = lm;
}
void Tache::SetMessage2(Messager* lm){
	this->leMessage2 = lm;
}
void Tache::SetMessage3(Messager* lm){
	this->leMessage3 = lm;
}

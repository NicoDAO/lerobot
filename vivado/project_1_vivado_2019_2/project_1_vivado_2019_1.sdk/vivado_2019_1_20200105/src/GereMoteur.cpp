/*
 * GereMoteur.cpp
 *
 *  Created on: 6 janv. 2020
 *      Author: nicolas
 */

#include "GereMoteur.h"

#include "MonPWM.h"

GereMoteur::GereMoteur() {

}

GereMoteur::~GereMoteur() {

}

void GereMoteur::handler() {
	static u32 rp = 0;
	rp +=5;

	if (rp > 1024) rp = 0;
	reglePuissanceMoteur(rp);


	lapause(0);
}

void GereMoteur::SetAdresseMoteur(u32 add) {
	lpwm.setBaseAddr(add); // on regle l'adresse du PWM
}

void GereMoteur::reglePuissanceMoteur(u32 p){
	xil_printf("->PuissanceMoteur \r",p);
	lpwm.RegleRapportCyclique(p );//test
	xil_printf("	Puissance moteur = %d /1000 \r",p);
}

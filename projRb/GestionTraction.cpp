/*
 * MonPWM.cpp
 *
 *  Created on: 10 janv. 2020
 *      Author: nicolas
 */

#include "GestionTraction.h"
#include <stdio.h>
GestionTraction::GestionTraction() {
	// TODO Auto-generated constructor stub

}

GestionTraction::~GestionTraction() {
	// TODO Auto-generated destructor stub
}

void GestionTraction::setBaseAddr(u32 aa) {
	this->baseAddr = aa;
}
void GestionTraction::handler() {
	static u8 automate = 0;
	AMessage mot1mess, mot2mess;
	int mesureDistance = 0;

	u32 vitesse_g = 0;
	char bargraf[256];

	if (leMessage3->recoitMessage() == 1) {
		//int taille = leMessage3->vecteurMessages.size();
		while (!leMessage3->vecteurMessages.empty()) {
			AMessage tt = leMessage3->vecteurMessages.back();
			//AMessage tt = leMessage3->vecteurMessages.begin();
			leMessage3->vecteurMessages.pop_back();
			//leMessage3->vecteurMessages.erase(leMessage3->vecteurMessages.begin());
			//leMessage3->vecteurMessages.erase();
			mesureDistance = tt.distanceCapteur;
#ifdef LOG_CAPTEUR
			printf(
					"\r\n[%04d]Cerveau : recoit message distance capteur : distance = %d , taille %d \r\n",
					cpt_tache, mesureDistance,
					leMessage3->vecteurMessages.size());
#endif
		}
		leMessage3->vecteurMessages.clear();
		leMessage3->effaceQueue();	//on efface la queue

		//test logique


		if((mesureDistance <(mesureDistance_avant-2000)) || (mesureDistance >(mesureDistance_avant+2000)))
		{
			mesureDistance_avant = mesureDistance;
			if ((mesureDistance >= 2000) && (mesureDistance <= 55000)) {
				automate = Robot_avant_lent;
			}
			if (mesureDistance < 2000) {
					automate = Robot_arret;
				}

		}else{
			automate = Robot_arret;
		}

		if ((mesureDistance > 1000) && (mesureDistance <= 15000)) {
			//	automate = 2;
		}
		if ((mesureDistance > 15000) && (mesureDistance <= 20000)) {
			//	automate = 3;
		}
		if ((mesureDistance > 20000)) {
			//	automate = 0;
		}
		switch (automate) {
		case Robot_arret:
			mot1mess.puissance_moteur = 0;
			//mot1mess.sens_moteur = 1;
			mot2mess.puissance_moteur = 0;
			printf("[%04d]Traction : arret\r\n");

			break;
		case Robot_avant_lent:

			vitesse_g = mesureDistance / 1000;
#ifdef LOG_BARGRAF
			memset(bargraf, 0, sizeof(bargraf));
			if (vitesse_g >= sizeof(bargraf))
				vitesse_g = sizeof(bargraf) - 1;
			for (u8 u = 0; u < vitesse_g; u++) {
				bargraf[u] = 'O';
			}
			printf("  %s\r\n", bargraf);
#endif
			mot1mess.puissance_moteur = vitesse_g + 500;
			//mot1mess.sens_moteur = 1;
			mot2mess.puissance_moteur = vitesse_g + 500;
#ifdef LOG_MOTEUR
			printf("[%04d]Traction : marche avant\r\n");
#endif
			//mot1mess.sens_moteur = 0;
			//	automate++;

			break;
		case Robot_arriere_lent:
			mot1mess.puissance_moteur = 100;
			//mot1mess.sens_moteur = 0;
			mot2mess.puissance_moteur = 300;
			//mot1mess.sens_moteur = 1;
			//	automate++;
			break;
		case Robot_tourne_droite_arriere:
			mot1mess.puissance_moteur = 10;
			mot1mess.sens_moteur = 0;
			mot2mess.puissance_moteur = 10;
			mot1mess.sens_moteur = 1;
			//	automate++;
			break;
		default:
			automate = 0;
			break;

		}
		if (leMessage1->vecteurMessages.empty()) {
			leMessage1->envoieMessage(&mot1mess);
		}
		if (leMessage2->vecteurMessages.empty()) {
			leMessage2->envoieMessage(&mot2mess);
		}

	}
	lapause(0);
}
void GestionTraction::RegleSens(u32 rc) {
	//printf("	RegleSens = %d /1000, this->baseAddr = %x \r",rc,this->baseAddr);

	//u32 rcloc = rc & 0x03FFFF;//on utilise que les 10 bits de poids faible
	//rcloc |= 20000000;//dans l'IP, le bit 29 sert à router le PWM depuis le bus AXI
	//rcloc |= 0x20000000;
	Xil_Out32(this->baseAddr, rc); //allume l'ampli
	//printf("	ok \r");

}

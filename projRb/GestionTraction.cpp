/*
 * MonPWM.cpp
 *
 *  Created on: 10 janv. 2020
 *      Author: nicolas
 */

#include "GestionTraction.h"
#include <stdio.h>
#include <iostream>
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
	int puissance_moteur1 = 0;
	int puissance_moteur2 = 0;
//test
//fin test
#if 1
	leMessage3->recoitMessage();
	//  {
	log_traction("GestionTraction : recoit %d message",
			leMessage3->vecteurMessages.size());
	for (unsigned i = 0; i < leMessage3->vecteurMessages.size(); i++) {
		mesureDistance = atoi(leMessage3->vecteurMessages[i].message);
		char mmmm[MSGLEN];
		snprintf(mmmm, sizeof(mmmm), "%s ->%d",
				leMessage3->vecteurMessages[i].message, mesureDistance);
		log_traction("[%d]GestionTraction : Recoit mesure distance : %s", i,
				mmmm);
		//int taille = leMessage3->vecteurMessages.size();
		//test logique
		if (mesureDistance < 1000) {

			automate = Robot_arriere_lent;
		}
		if ((mesureDistance > 1000) && (mesureDistance <= 10000)) {
			automate = Robot_avant_lent;
		}

		if ((mesureDistance > 10000) && (mesureDistance <= 20000)) {
			automate = Robot_avant_tranquilou;
		}
		if ((mesureDistance > 20000)) {
			automate = Robot_avant_rapide;
		}
		switch (automate) {
		case Robot_arret:
			log_traction("robot arret");
			puissance_moteur1 = 0;
			puissance_moteur2 = 0;
			break;
		case Robot_avant_rapide:
			log_traction("Robot_avant_rapide ");

			puissance_moteur1 = 900;
			puissance_moteur2 = 900;
			break;
		case Robot_avant_lent:
			log_traction("robot avance lentement");

			vitesse_g = mesureDistance / 1000;
			puissance_moteur1 = 100;
			puissance_moteur2 = 100;
			//mot1mess.sens_moteur = 0;
			//	automate++;
			break;
		case Robot_avant_tranquilou:
			log_traction("robot avance tranquilou");

			vitesse_g = mesureDistance / 1000;
			puissance_moteur1 = 300;
			puissance_moteur2 = 300;
			//mot1mess.sens_moteur = 0;
			//	automate++;
			break;
		case Robot_arriere_lent:
			log_traction("robot recule lentement");

			puissance_moteur1 = -100;
			puissance_moteur2 = -100;
			break;
		case Robot_tourne_droite_arriere:
			log_traction("robot tourne arriere droite");

			log_traction(mot1mess.message, sizeof(mot1mess.message),
					"avance vitesse %d", 10);
			log_traction(mot2mess.message, sizeof(mot2mess.message),
					"recule vitesse %d", 10);
			puissance_moteur1 = 500;
			puissance_moteur2 = -500;

			//	automate++;
			break;
		default:
			log_traction("robot etat indeterminé");


			automate = 0;
			break;
		}
	}
#endif
	leMessage3->effaceQueue();
	snprintf(mot1mess.message, sizeof(mot1mess.message), "%d",puissance_moteur1);
	snprintf(mot2mess.message, sizeof(mot1mess.message), "%d",puissance_moteur2);
	//   log_traction("GestionTraction 1 : envoie %s\r\n",mot1mess.message);
//    log_traction("GestionTraction 2 : envoie %s\r\n",mot2mess.message);
	leMessage1->envoieMessage(&mot1mess);
	leMessage2->envoieMessage(&mot2mess);
	//TODO faire pareil pour le moteur 2
	//lapause(0);

	//	sleep(this->xWakePeriod);
	usleep(this->xWakePeriod);

}
void GestionTraction::RegleSens(u32 rc) {
}

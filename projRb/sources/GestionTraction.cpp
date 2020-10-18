/*
 * GestionTraction.cpp
 *
 *  Created on: 10 janv. 2020
 *      Author: nicolas
 */

#include "GestionTraction.h"
#include <stdio.h>
#include <iostream>
using namespace std;
GestionTraction::GestionTraction() {
}

GestionTraction::~GestionTraction() {
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
        string mesures_gyro ="";
        string mesures_distance ="";
	string etat_traction = "";

#if 1
        leMessage4->recoitMessage();
	if( leMessage4->vecteurMessages.size()>0){
	    for (unsigned i = 0; i < leMessage4->vecteurMessages.size(); i++) {
	        char titi[MSGLEN];
	        memset(titi,0,MSGLEN);
	        snprintf(titi, sizeof(titi), "%s ->%d",
		leMessage4->vecteurMessages[i].message, mesureDistance);
		mesures_gyro = to_string(i) + "gyro : "+ string(titi);
	    }
            leMessage4->effaceQueue();
        }
 
	leMessage3->recoitMessage();
        if( leMessage3->vecteurMessages.size()>0){
	    for (unsigned i = 0; i < leMessage3->vecteurMessages.size(); i++) {
		mesureDistance = atoi(leMessage3->vecteurMessages[i].message);
		char mmmm[MSGLEN];
		memset(mmmm,0,MSGLEN);
		snprintf(mmmm, sizeof(mmmm), "%s ->%d",
				leMessage3->vecteurMessages[i].message, mesureDistance);
		mesures_distance = to_string(i) + "distance : "+ string(mmmm);

	    }
	    leMessage3->effaceQueue();
		if (mesureDistance <= 10) {  //on recoit les mesures en cm
			automate = Robot_arret;
		}
		if ((mesureDistance > 10)&&(mesureDistance <= 100)) {
			automate = Robot_arriere_lent;
		}
		if ((mesureDistance > 100) && (mesureDistance <= 500)) {
			automate = Robot_avant_lent;
		}
		if ((mesureDistance > 500) && (mesureDistance <= 1000)) {
			automate = Robot_arriere_tranquilou;
		}
		if ((mesureDistance > 1000) && (mesureDistance <= 2000)) {
			automate = Robot_avant_tranquilou;
		}
		if ((mesureDistance > 20000)) {
			automate = Robot_avant_rapide;
		}
		switch (automate) {
		case Robot_arret:
			etat_traction = "robot arret";
			puissance_moteur1 = 0;
			puissance_moteur2 = 0;
			break;
		case Robot_avant_rapide:
			etat_traction = "Robot_avant_rapide" ;
			puissance_moteur1 = 900;
			puissance_moteur2 = 900;
			break;
		case Robot_avant_lent:
			etat_traction = "robot avance lentement";
			vitesse_g = mesureDistance / 1000;
			puissance_moteur1 = 100;
			puissance_moteur2 = 100;
			//mot1mess.sens_moteur = 0;
			//	automate++;
			break;
		case Robot_avant_tranquilou:
			etat_traction = "robot avance tranquilou";
			vitesse_g = mesureDistance / 1000;
			puissance_moteur1 = 300;
			puissance_moteur2 = 300;
			break;
		case Robot_arriere_tranquilou:
			etat_traction = "robot arriere tranquilou";
			vitesse_g = mesureDistance / 1000;
			puissance_moteur1 = -300;
			puissance_moteur2 = -300;
			break;
		case Robot_arriere_lent:
			etat_traction = "robot recule lentement";
			puissance_moteur1 = -100;
			puissance_moteur2 = -100;
			break;
		case Robot_tourne_droite_arriere:
			etat_traction = "robot tourne arriere droite";
			puissance_moteur1 = 500;
			puissance_moteur2 = -500;
			//	automate++;
			break;
		default:
			etat_traction = "robot etat indeterminé";
			automate = 0;
			break;
		}
		string log = etat_traction + "  " + mesures_distance +  "  " +  mesures_gyro;
		log_traction (log.c_str(), strlen(log.c_str()));	    
	}

	
#endif
	snprintf(mot1mess.message, sizeof(mot1mess.message), "%d",
			puissance_moteur1);
	snprintf(mot2mess.message, sizeof(mot1mess.message), "%d",
			puissance_moteur2);
	leMessage1->envoieMessage(&mot1mess);
	leMessage2->envoieMessage(&mot2mess);
	usleep(this->xWakePeriod);
}
void GestionTraction::RegleSens(u32 rc) {
}

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
void GestionTraction::dirige(){
    string log;
  
    if( commande_telecommande.find("mode autonome")!= string::npos){
      	 calog.log_teleco("mode autonome");

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
    }
    
    if( commande_telecommande.find("AVANCE")!=string::npos){
         automate =    Robot_avant_rapide;
	 calog.log_teleco("commande , bon, on avance");
    }

    if( commande_telecommande.find("AVANCE_GAUCHE")!=string::npos){
         automate =    Robot_tourne_gauche_avant;
	 calog.log_teleco("commande , bon, on avance");
    }

    if( commande_telecommande.find("AVANCE_DROITE")!=string::npos){
         automate =    Robot_tourne_droite_avant;
	 calog.log_teleco("commande , bon, on avance");
    }
    

    calog.log_teleco(commande_telecommande.c_str());

    if( commande_telecommande.find ("arret")!=string::npos){
         automate =    Robot_arret;
	 calog.log_teleco("commande , bon, on arrete");
    }

   if( commande_telecommande.find ("RECULE")!=string::npos){
         automate =    Robot_arriere_lent;
	 calog.log_teleco("commande , bon, recule");
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
		puissance_moteur2 = 100;
		//	automate++;
	break;
        case Robot_tourne_gauche_avant:
                etat_traction = "robot tourne avant gauche";
		puissance_moteur1 = 100;
		puissance_moteur2 = 500;
        break;
        case Robot_tourne_droite_avant:
  	        etat_traction = "robot tourne avant droite";
		puissance_moteur1 = 500;
		puissance_moteur2 = 100;
        break;
	default:
		etat_traction = "robot etat indeterminé";
		automate = 0;
	break;
    }
    log = commande_telecommande + ":" +  etat_traction + "/ " + mesures_distance +  " !  " +  mesures_gyro;
    calog.log_teleco(log.c_str(), strlen(log.c_str()));	    

}
void GestionTraction::handler() {

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
    }


    if(leMessage5->recoitMessage()>=0){
        if( leMessage5->vecteurMessages.size()>0){
            for (unsigned i = 0; i < leMessage5->vecteurMessages.size(); i++) {
        	    char mmmmt[MSGLEN];
		    memset(mmmmt,0,MSGLEN);
		    snprintf(mmmmt, sizeof(mmmmt), "message 5, msgid = %d : %s",
			 leMessage5->getMsgId(),leMessage5->vecteurMessages[i].message);
		    
		    // commande_telecommande ="";//on sort du mode autonome car on a recu une commande de la telecommande
		    commande_telecommande= leMessage5->vecteurMessages[i].message;

                    calog.log_teleco(" recoit commande %s", commande_telecommande.c_str());
		    
		    log_teleco (mmmmt, strlen(mmmmt));	    
		
	          }
	      leMessage5->effaceQueue();
	      }
	  }

	
        dirige();
	snprintf(mot1mess.message, sizeof(mot1mess.message), "%d",puissance_moteur1);
	snprintf(mot2mess.message, sizeof(mot1mess.message), "%d",puissance_moteur2);
	leMessage1->envoieMessage(&mot1mess);
	leMessage2->envoieMessage(&mot2mess);
	usleep(this->xWakePeriod);
}


void GestionTraction::RegleSens(u32 rc) {
}

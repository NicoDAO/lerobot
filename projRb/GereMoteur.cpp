/*
 * GereMoteur.cpp
 *
 *  Created on: 6 janv. 2020
 *      Author: nicolas
 */

#include "GereMoteur.h"

#include "MonPWM.h"

GereMoteur::GereMoteur() {
	log_info(this->nom_moteur, sizeof(this->nom_moteur), "moteur????");
}

GereMoteur::~GereMoteur() {
}

void GereMoteur::handler() {
	u32 rapport_cyclique = 1024;
	//log_info("GereMoteur::handler taille  %d\r\n",leMessage1->vecteurMessages.size());
	if (leMessage1->recoitMessage() == 1) {
		while (!leMessage1->vecteurMessages.empty()) {
			//  log_info("     messages[%d]: %s\r\n",i,leMessage1->vecteurMessages[i].consigne);
			AMessage tt = leMessage1->vecteurMessages.back();
			consigne_puissance = atoi(tt.message);

			log_moteur("Recoit message :%s  messages: %s ->%d",nom_moteur, tt.message, consigne_puissance);
			leMessage1->vecteurMessages.pop_back();
		}
		leMessage1->effaceQueue(); //on efface la queue

		if (consigne_puissance < 0) {
			sens = 0;
			rapport_cyclique = 1000 + (u32) consigne_puissance;
		}
		if (consigne_puissance >= 0) {
			sens = 1;
			rapport_cyclique = 1000 - (u32) consigne_puissance;
		}
		{
			//il n'y a plus de probleme de sens
			float valeur_calibre = ((float)rapport_cyclique ) * calibre;

			puissanceMoteur.RegleMoteur((u32)valeur_calibre ,sens);
		}
	}
	usleep(this->xWakePeriod );

}

void GereMoteur::SetAdresseMoteur(uint32 add) {
	puissanceMoteur.setBaseAddr(add); // on regle l'adresse du PWM
	lsensMoteur.setBaseAddr(add );
}

void GereMoteur::reglePuissanceMoteur(u32 p) {

    log_moteur("  %s   puissance du moteur = %d /1000", this->nom_moteur, p);
    puissanceMoteur.RegleRapportCyclique(p); //test
}

void GereMoteur::met_marcheAvant() {
	lsensMoteur.RegleSens(Marche_avant);
}
void GereMoteur::met_marcheArriere() {
	lsensMoteur.RegleSens(Marche_arriere);
}

void GereMoteur::SetNomMoteur(char *nom, unsigned char taille) {
	snprintf(this->nom_moteur, sizeof(this->nom_moteur), "%s", nom);
}

void GereMoteur::metEnmodeSimu() {
	log_moteur("met moteur (%s) en mode simu", nom_moteur);
	puissanceMoteur.metEnmodeSimu();
	lsensMoteur.metEnmodeSimu();
}
void GereMoteur::Reglecalibre(float cal){
	calibre = cal;
}
void GereMoteur::SetfichierCalib(std::string tt){
	this->fichier_calibre = tt;
}


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
		// for (unsigned i=0; i<leMessage1->vecteurMessages.size() ; i++)
#if 1
		while (!leMessage1->vecteurMessages.empty()) {
			//  log_info("     messages[%d]: %s\r\n",i,leMessage1->vecteurMessages[i].consigne);
			AMessage tt = leMessage1->vecteurMessages.back();
			consigne_puissance = atoi(tt.message);

			log_moteur("%s  messages: %s ->%d\r\n",nom_moteur, tt.message, consigne_puissance);
			leMessage1->vecteurMessages.pop_back();
		}
		leMessage1->effaceQueue(); //on efface la queue
		/*if (puissance_m < consigne_puissance) {
		 puissance_m += rapport_entre_2_consignes;
		 }
		 if (puissance_m > consigne_puissance) {
		 puissance_m -= rapport_entre_2_consignes;
		 }*/

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
			lsensMoteur.RegleSens(sens);
			puissanceMoteur.RegleRapportCyclique(rapport_cyclique); //test
		}
#ifdef LOG_MOTEUR
        xil_log_info(
            "[%04d]moteur :  %s  sens : %d  p= %d, rapport cycl = %d ,  consigne %d\r\n",
            cpt_tache, this->nom_moteur, sens, puissance_m,
            rapport_cyclique, consigne_puissance);
#endif
#endif
	}
	usleep(this->xWakePeriod );
	//lapause(0);
}

void GereMoteur::SetAdresseMoteur(uint32 add) {
	puissanceMoteur.setBaseAddr(add); // on regle l'adresse du PWM
	lsensMoteur.setBaseAddr(add );
}

void GereMoteur::reglePuissanceMoteur(u32 p) {
	//xil_log_info("->PuissanceMoteur = \r", p);
	puissanceMoteur.RegleRapportCyclique(p); //test
#ifdef LOG_MOTEUR
    xil_log_info("  %s   puissance du moteur = %d /1000 \r\n", this->nom_moteur,
                 p);
#endif
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

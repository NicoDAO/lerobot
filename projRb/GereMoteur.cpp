/*
 * GereMoteur.cpp
 *
 *  Created on: 6 janv. 2020
 *      Author: nicolas
 */

#include "GereMoteur.h"

#include "MonPWM.h"

GereMoteur::GereMoteur() {
	snprintf(this->nom_moteur, sizeof(this->nom_moteur), "moteur????");
}

GereMoteur::~GereMoteur() {

}

void GereMoteur::handler() {
	u32 rapport_cyclique = 1024;

	if (leMessage1->recoitMessage() == 1) {
		while (!leMessage1->vecteurMessages.empty()) {
			AMessage tt = leMessage1->vecteurMessages.back();
			leMessage1->vecteurMessages.pop_back();

			sens = tt.sens_moteur;
			/*puissance_m*/consigne_puissance = tt.puissance_moteur; //la puissance vas de -1000 à +1000
			//rapport_entre_2_consignes = (consigne_puissance - puissance_m);
			//rapport_entre_2_consignes = (rapport_entre_2_consignes / 20) + 1;
			//if (rapport_entre_2_consignes < 0)
			//	rapport_entre_2_consignes = 0 - rapport_entre_2_consignes;
#ifdef LOG_MOTEUR
			xil_printf(
					"[%04d]Moteur  : %s consigne_puissance %d, pas = %d \r\n",
					cpt_tache, this->nom_moteur, consigne_puissance,
					rapport_entre_2_consignes);
#endif
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
		xil_printf(
				"[%04d]moteur :  %s  sens : %d  p= %d, rapport cycl = %d ,  consigne %d\r\n",
				cpt_tache, this->nom_moteur, sens, puissance_m,
				rapport_cyclique, consigne_puissance);
#endif
	}
	sleep(12);
	//lapause(0);
}

void GereMoteur::SetAdresseMoteur(uint32 add) {
	puissanceMoteur.setBaseAddr(add); // on regle l'adresse du PWM
	lsensMoteur.setBaseAddr(add + 4);
}

void GereMoteur::reglePuissanceMoteur(u32 p) {

	//xil_printf("->PuissanceMoteur = \r", p);
	puissanceMoteur.RegleRapportCyclique(p); //test
#ifdef LOG_MOTEUR
			xil_printf("  %s   puissance du moteur = %d /1000 \r\n", this->nom_moteur,
					p);
#endif

}

void GereMoteur::met_marcheAvant() {
	lsensMoteur.RegleSens(1);
}

void GereMoteur::SetNomMoteur(char * nom, unsigned char taille) {
	snprintf(this->nom_moteur, sizeof(this->nom_moteur), "%s", nom);
}


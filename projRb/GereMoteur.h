/*
 * GereMoteur.h
 *
 *  Created on: 6 janv. 2020
 *      Author: nicolas
 */

#ifndef SRC_GEREMOTEUR_H_
#define SRC_GEREMOTEUR_H_

#include "config_du_system.h"
#include "Tache.h"
#include "MonPWM.h"
#include "SensMoteur.h"
#include "Messagerie.h"
#include <cstring>
class GereMoteur: public Tache {
public:
	GereMoteur();
	virtual ~GereMoteur();

	void handler(void);
	void SetAdresseMoteur(u32);
	void reglePuissanceMoteur(u32);
	void met_marcheAvant(void);
	void SetNomMoteur(char*, unsigned char taille);
private:
	u32 AdresseMoteur;
	CommandePWM puissanceMoteur;
	SensMoteur lsensMoteur;
	u8 sens_moteur = 0;
	char nom_moteur[50];
	s32 puissance_m = 1023;
	u8 sens = 0; //test

	s32 vitesse_avant = 0;
	u8 sens_avant = 0; //test
	s32 consigne_puissance = 0;
	s32 consigne_puissance_avant = 0;
	s32 rapport_entre_2_consignes = 0;
};

#endif /* SRC_GEREMOTEUR_H_ */

/*
 * GereMoteur.cpp
 *
 *  Created on: 6 janv. 2020
 *      Author: nicolas
 */

#include "GereCapteurDistance.h"
#include "config_du_system.h"
GereCapteurDistance::GereCapteurDistance()  {
	//log_info(this->nom_moteur, sizeof(this->nom_moteur), "moteur????");
	memset(tabMesure, 0, sizeof(tabMesure));
}

GereCapteurDistance::~GereCapteurDistance() {
}

void GereCapteurDistance::handler() {
	static u32 add = 0;
	static int num = 0;
	u32 lit = 0, lit_moy = 0;
	u32 add1 = this->adresseAXI + add;
	lit = Xil_In32(add1);
	u32 distance_calibree = (int)appliqueCalibre((int) lit);

	calog.log_capteur("capteur distance brute %d = %d cm",lit, distance_calibree);
   	AMessage messCapteur;
	snprintf(messCapteur.message, sizeof(messCapteur.message), "%d", distance_calibree);
	int ret = leMessage1->envoieMessage(&messCapteur);

	usleep(this->xWakePeriod);
}

void GereCapteurDistance::ajoute_mesure(int mesure) {
	if (indexMesure < coef_moyenne/*sizeof(tabMesure)*/) {
		tabMesure[indexMesure] = mesure;
	}
	if (indexMesure++ >= coef_moyenne/*sizeof(tabMesure)*/) {
		indexMesure = 0;
	}
}

int GereCapteurDistance::calculeMesureMoyenne() {
	int val_moy = 0;
	for (int i = 0; i < coef_moyenne/*sizeof(tabMesure)*/; i++) {
		val_moy += tabMesure[i]; // on fait la somme
	}
	val_moy = val_moy / coef_moyenne /* sizeof(tabMesure)*/;
	return val_moy;
}

int GereCapteurDistance::appliqueCalibre(int val) {

	float cal = parametrage.at(0);
	int valeur_calibre = ((float) val) * cal;
	calog.log_calibre("on applique  le calibrage (%f) capteur %d ", cal,
			valeur_calibre);
	return valeur_calibre;
}

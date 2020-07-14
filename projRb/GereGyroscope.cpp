/*
 * GereGyroscope.cpp
 *
 *  Created on: 21 juin 2020
 *      Author: nicolas
 */

#include "GereGyroscope.h"

GereGyroscope::GereGyroscope() {
	// TODO Auto-generated constructor stub

}

GereGyroscope::~GereGyroscope() {
	// TODO Auto-generated destructor stub
}

int GereGyroscope::appliqueCalibre(int val) {

	float cal = parametrage.at(0);
	int valeur_calibre = ((float) val) * cal;
	log_calibre("on applique  le calibrage (%f) gyroscope %d ", cal,
			valeur_calibre);
	return valeur_calibre;
}

void GereGyroscope::handler() {
	static u32 add = 0;
	static int num = 0;
	u32 lit = 0, lit_moy = 0;
	u32 add1 = this->adresseAXI + add;
	lit = Xil_In32(add1);
	u32 distance_calibree = (int)appliqueCalibre((int) lit);

	switch (etat_gyro){

	case gyro_reset:
		log_gyro("gyroscope gyro_reset ");
		etat_gyro++;
		lit_config_gyro();
		num =  config_gyro.parametrage.size();
		break;
	case gyro_config:
		handler_gyro_config(0);
		log_gyro("gyroscope gyro_config  %d" ,num--);
		if(num ==0)etat_gyro = gyro_tourne;
		break;

	case gyro_tourne:
		log_gyro("gyroscope gyro_tourne ");

		break;


	}
	//	AMessage messCapteur;
	//	snprintf(messCapteur.message, sizeof(messCapteur.message), "%d", distance_calibree);
	//		int ret = leMessage1->envoieMessage(&messCapteur);

	usleep(this->xWakePeriod);
}

int GereGyroscope::handler_gyro_config(int ii){


	return 1;
}
int GereGyroscope::handler_gyro_reset(int ii){
	return 1;
}
int GereGyroscope::handler_gyro_tourne(int ii){
	return 1;
}
int GereGyroscope::lit_config_gyro()
{
	//config_gyro.
	config_gyro.setFichier("config_gyroscope");
	config_gyro.litFichierConfigMemoire();

	log_fichiersimu("lecture fichier  (%d)",config_gyro.memoire_periph->parametrage_memoire.size());
	int rr;
	for (rr=0;rr<config_gyro.memoire_periph->parametrage_memoire.size();rr++){
		case_memoire_ pp = config_gyro.memoire_periph->parametrage_memoire.at(rr);
		log_fichiersimu("reglage gyroscope  %d : %d ",pp.adresse,pp.valeur);
	}
//	config_gyro.memoire_periph->parametrage_memoire.get_allocator()
//	config_gyro.memoire_periph->parametrage_memoire.
	//element_config reg1;
	//reg1.nom_element = "registr1";
	//reg1.adresse = 1;
	//reg1.valeur = 22;

//	config_gyro.element.push_back(reg1);
	return 1;
}


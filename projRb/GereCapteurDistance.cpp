/*
 * GereMoteur.cpp
 *
 *  Created on: 6 janv. 2020
 *      Author: nicolas
 */

#include "GereCapteurDistance.h"
#include "config_du_system.h"
GereCapteurDistance::GereCapteurDistance() {
	//log_info(this->nom_moteur, sizeof(this->nom_moteur), "moteur????");
	memset(tabMesure, 0, sizeof(tabMesure));
}

GereCapteurDistance::~GereCapteurDistance() {
}

void GereCapteurDistance::handler() {
	//Xil_Out32(this->adresseAXI + AXI_SLV_REG2_OFFSET,lescoefs[cpt_coef]); //valeur
	//https://www.xilinx.com/support/documentation/ip_documentation/axi_dma/v7_1/pg021_axi_dma.pdf
	static u32 add = 0;
	static int num = 0;
	//  log_info("\r\nGereCapteurDistance::handler() entree\r\n");
	//   if (leMessage1->vecteurMessages.empty())
	//   {
	u32 lit = 0, lit_moy = 0;
	u32 add1 = this->adresseAXI + add;
	lit = Xil_In32(add1);
	appliqueCalibre((int) lit);
	//      ajoute_mesure(lit);
	//      lit_moy = calculeMesureMoyenne();
//	add++;
	log_capteur("capteur distance : %d ", lit);
	AMessage messCapteur;
	//   messCapteur.distanceCapteur = lit_moy;
	snprintf(messCapteur.message, sizeof(messCapteur.message), "%d", lit);
	int ret = leMessage1->envoieMessage(&messCapteur);

#ifdef LOG_BARGRAF		//dessin du bargraf
        u8 dist_g = lit_moy/1000;
        char bargraf [256];
        memset(bargraf,0,sizeof(bargraf));
        if(dist_g>=sizeof(bargraf))dist_g =sizeof(bargraf)-1;
        for(u8 u = 0; u < dist_g; u++)
        {
            bargraf[u] = '*';
        }
        log_info("  %s",bargraf);
        for(u8 u = 0; u < dist_g; u++)
        {
            bargraf[u] = '*';
        }
#endif
//    }
//    else
//    {
//        log_info("Capteur : la queue est pleine \r\n");
//    }
//    log_info("Capteur handler sleep %d sortie\r\n\r\n",this->xWakePeriod);
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
	log_calibre("on applique  le calibrage (%f) capteur %d ", cal,
			valeur_calibre);
	return valeur_calibre;
}

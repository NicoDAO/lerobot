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
	calog.log_calibre("on applique  le calibrage (%f) gyroscope %d ", cal,
			valeur_calibre);
	return valeur_calibre;
}

void GereGyroscope::handler() {
	static u32 add = 0;
	static int num = 0;
	u32 lit = 0, lit_moy = 0;
	u32 add1 = this->adresseAXI + add;
	//lit = Xil_In32(add1);
	//u32 distance_calibree = (int)appliqueCalibre((int) lit);

	switch (etat_gyro){

	case gyro_reset:
		calog.log_gyro("gyroscope gyro_reset ");
		etat_gyro++;
		lit_config_gyro();
		num =  config_gyro.parametrage.size();
		break;
	case gyro_config:
		if(1 == handler_gyro_config(0)){
			etat_gyro = gyro_tourne;//on a fini la config du gyroscope
		}
		break;

	case gyro_tourne:
		calog.log_gyro("gyroscope gyro_tourne ");

		break;


	}
	usleep(this->xWakePeriod);
}

int GereGyroscope::handler_gyro_config(int ii){
	static unsigned int rr = 0;
	if (rr == config_gyro.memoire_periph->parametrage_memoire.size())rr=0;//la config n'est pas finie
	config_gyro.memoire_periph->parametrage_memoire.size();
	static unsigned int axi_reg_loc = AXI_SLV_REG0_OFFSET;
	static unsigned int axi_adresse = 0;
	static unsigned int axi_valeur = 0;
	//regle le gyroscope avec les données trouvées dans le fichier de configuration
	
	case_memoire_ pp = config_gyro.memoire_periph->parametrage_memoire.at(rr);
	std::string toto =  pp.nom ;
	if(pp.nom == "AXI_REG"){
		axi_reg_loc = pp.valeur;//on regle le numero de registre de l'AXI
		calog.log_gyro("AXI_REG %d %d ",pp.adresse,pp.valeur);
	}
	if(pp.nom == "AXI_ADD"){
		axi_adresse = pp.valeur;//on regle l'adresse de l'AXI
		calog.log_gyro("AXI_ADD %x %x ",pp.adresse,pp.valeur);
	}
	if(pp.nom == "AXI_VAL"){
		axi_valeur = pp.valeur;//on regle l'adresse de l'AXI
		calog.log_gyro("AXI_VAL %x %x ",pp.adresse,pp.valeur);
	}
	if(pp.nom == "AXI_ECRIT"){
		calog.log_gyro("AXI_ECRIT %x : %x ",pp.adresse,pp.valeur);
		//Xil_Out32(this->adresseAXI + axi_reg_loc,
		//		axi_valeur);
		//Xil_Out32_tab(this->adresseAXI, commande,10   ); //allume l'ampli                   
 	
		u32 commande[10];                                                                                                                                           
		memset(commande,0,sizeof(commande));                                              
                                                                                          
		commande[0] =  axi_valeur;                                                              
		commande[1] = 0xAA;                                                               
		Xil_Out32(this->adresseAXI,axi_valeur,axi_reg_loc ); //envoie la valeur sur la sortie               
		//Xil_Out32(this->adresseAXI,axi_valeur,0 ); //arrete d'envoyer sur la sortie   

		}
	if(pp.nom == "LIT"){
			calog.log_gyro("LIT %d %d ",pp.adresse,pp.valeur);
		        u32 commande[10];                                                                 
		        memset(commande,0,sizeof(commande));                                              
		        commande[0] = 0;                                                              
		        commande[1] = 0xAA;                                                               
        		Xil_Out32_tab(this->adresseAXI, commande,10   ); //allume l'ampli                   
		}
	rr++;
	return 0;
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

	calog.log_fichiersimu("lecture fichier  (%d)",config_gyro.memoire_periph->parametrage_memoire.size());


	return 1;
}


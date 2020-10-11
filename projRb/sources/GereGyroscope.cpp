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
Donnees_gyroscope::Donnees_gyroscope(){
}
Donnees_gyroscope::~Donnees_gyroscope(){
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
        static u32 lecture1 = 0;
        static u32 lecture2 = 0;
        static u32 lecture3 = 0;
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
		static u16 etat = 0;
		switch(etat){
			case 0:
				Xil_Out32(this->adresseAXI, CDE_RESET, 0x1 ); //on lit la valeur X  
				Xil_Out32(this->adresseAXI, 0, 2 ); //on lit la valeur X 
				Xil_Out32(this->adresseAXI, CTRL_REG1,3 ); //on lit la valeur X
				Xil_Out32(this->adresseAXI, CDE_LIT,1 ); //on lit la valeur X
		                lecture1 = 0xff & Xil_In32(this->adresseAXI  ); //lit la valeur du registre
				//calog.log_gyro("1 LIT  STATUS_REG = %x ",lecture1);
				etat = 1;
			break;
			case 1:
				Xil_Out32(this->adresseAXI, CDE_RESET, 0x1 ); //on lit la valeur X  
				Xil_Out32(this->adresseAXI, 0, 2 ); //on lit la valeur X 
				Xil_Out32(this->adresseAXI, OUT_X_L,3 ); //on lit la valeur X
				Xil_Out32(this->adresseAXI, CDE_LIT,1 ); //on lit la valeur X
		                lecture2 = 0xff & Xil_In32(this->adresseAXI  ); //lit la valeur du registre
				//calog.log_gyro("2 LIT  OUT_X_L = %x ",lecture2);
				etat = 2;
			case 2:
                                
				donne_gyro.x_l = 0xff & litRegistreGyro(OUT_X_L);
				usleep(100);
                                donne_gyro.x_h = 0xff & litRegistreGyro(OUT_X_H);
         	                usleep(100);

				donne_gyro.y_l = 0xff & litRegistreGyro(OUT_Y_L);
				usleep(100);
                                donne_gyro.y_h = 0xff & litRegistreGyro(OUT_Y_H);
		                usleep(100);

				donne_gyro.z_l = 0xff & litRegistreGyro(OUT_Z_L);
				usleep(100);
                                donne_gyro.z_h = 0xff & litRegistreGyro(OUT_Z_H);
                                
                                s16 XX = (donne_gyro.x_l) << 9 | (donne_gyro.x_h);//bugounet les bit doivent être décalés dans le vhdl
                                s16 YY = (donne_gyro.y_l) << 9 | (donne_gyro.y_h);
                                s16 ZZ = (donne_gyro.z_l) << 9 | (donne_gyro.z_h);
			        float XX_f = static_cast<float>(~XX+1)/1000 ;	
			        float YY_f = static_cast<float>(~YY+1)/1000;	
			        float ZZ_f = static_cast<float>(~ZZ+1)/1000;	
				//	calog.log_gyro(".x = %02x%02x   y =  %02x%02x    z = %02x%02x",donne_gyro.x_l,donne_gyro.x_h,donne_gyro.y_l,donne_gyro.y_h \
				//		,donne_gyro.z_l,donne_gyro.z_h);
				calog.log_gyro("  %f   %f   %f  ",XX_f,YY_f,ZZ_f);
		

				break;
		}
	break;


	}
	usleep(this->xWakePeriod);
}

void Donnees_gyroscope::integre(){

	calc_x = ((float) x_h + calc_x); 



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
		Xil_Out32(this->adresseAXI, pp.valeur, pp.adresse ); //envoie la valeur sur la sortie
	}
	

	if(pp.nom == "LIT"){
		u32 lecture = Xil_In32(this->adresseAXI); //envoie la valeur sur la sortie
		calog.log_gyro("LIT %x: %x ",pp.adresse,lecture);
	}

	if(pp.nom == "FIN_CONFIG"){
		return 1;
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
u32 GereGyroscope::litRegistreGyro(u8 adresse){
	u32 lecture1= 0;
        Xil_Out32(this->adresseAXI, CDE_RESET, 0x1 ); //on lit la valeur X         
      	Xil_Out32(this->adresseAXI, 0, 2 ); //on lit la valeur X                   
        Xil_Out32(this->adresseAXI, adresse,3 ); //on lit la valeur X            
        Xil_Out32(this->adresseAXI, CDE_LIT,1 ); //on lit la valeur X              
        lecture1 = 0xff & Xil_In32(this->adresseAXI  ); //lit la valeur du registre
 
	return lecture1; 
}

/*
 * Calibrage.cpp
 *
 *  Created on: 9 mai 2020
 *      Author: nicolas
 */

#include "Calibrage.h"
#include "log.h"

Calibrage::Calibrage() { // @suppress("Member declaration not found")
	// TODO Auto-generated constructor stub
}

Calibrage::~Calibrage() {
	// TODO Auto-generated destructor stub
}

Calibrage::Calibrage(GestionLog *lelog ) {
  //this->lelog = lelog;

}

void Calibrage::SetfichierCalib(std::string tt){

	ouvrFichierSimu(tt);//on va lire le fichier de parametrage et on rempli le vecteur parametrage
        calog.log_calibre( "setFichierCalib = %s",tt);

	lit_parametrage();
	nom_fichier = tt;

}
int Calibrage::lit_parametrage(void){
	 for (unsigned i=0; i<parametrage.size(); i++)
	   calog.log_calibre( "%s  on lit %d", nom_fichier,parametrage.at(i));
	 return 1;
}



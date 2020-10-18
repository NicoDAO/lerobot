/*
 * Calibrage.cpp
 *
 *  Created on: 9 mai 2020
 *      Author: nicolas
 */

#include "Calibrage.h"
#include "log.h"

Calibrage::Calibrage() {
}

Calibrage::~Calibrage() {
}

Calibrage::Calibrage(GestionLog *lelog ) {
  //this->lelog = lelog;

}

void Calibrage::SetfichierCalib(std::string tt){
	nom_fichier = tt;  
        calog.log_calibre( "setFichierCalib = %s",tt.c_str());
        ouvrFichierSimu(tt);//on va lire le fichier de parametrage et on rempli le vecteur parametrage
        lit_parametrage();

}
int Calibrage::lit_parametrage(void){

        for (unsigned i=0; i<parametrage.size(); i++)
	  calog.log_calibre( "%s  on lit %f", nom_fichier.c_str(),parametrage.at(i));
	 return 1;
}


